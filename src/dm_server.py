#!/usr/bin/env python

import roslib; roslib.load_manifest('srs_ui_pro')
import rospy
import actionlib
import smach
import smach_ros

from srs_ui_pro.msg import *
from arm_manip_generic_states import *
from assisted_grasping_generic_states import *
from simulate_dm import *

class UI_PRO_Server_for_DM():

	########################################################################
	def __init__(self):

		self._as = actionlib.SimpleActionServer('ui_pro_server_for_dm', dm_serverAction, self.execute, False)
		self._as.start()
		rospy.loginfo("UI_PRO server for DM demands is running.")


	########################################################################
	def execute(self, goal):
		rospy.loginfo("UI_PRO server for DM: New goal received (%s)", goal)

		_result = dm_serverResult()
		_feedback = dm_serverFeedback()

		sm = smach.StateMachine(outcomes=['completed','not_completed','failed','pre-empted'])

		#This feedback warns to the srs_ui_pro about the necessity of user intervention.
		_feedback.current_status = "new_event"
		self._as.publish_feedback(_feedback)
		rospy.sleep(1); #Allows the srs_ui_pro catch the event.


		#[TODO]: Define the excepcional cases.
		if goal.excepcional_case_id == ExcepcionalCases.ASSISTED_BASE_NAVIGATION:
			_result.output = self.assisted_base_navigation(sm)

		elif goal.excepcional_case_id == ExcepcionalCases.ASSISTED_ARM_NAVIGATION:
			_result.output = self.assisted_arm_navigation(sm)

		elif goal.excepcional_case_id == ExcepcionalCases.ASSISTED_GRASPING:
			_result.output = self.assisted_grasping(sm)

		else: 
			_feedback.current_status = "unknown"
			self._as.publish_feedback(_feedback)

		self._as.set_succeeded(_result)
		return
		

	########################################################################
	def assisted_base_navigation(self, sm):
		rospy.loginfo("Executing assisted_base_navigation state machine...")
		
		_feedback = dm_serverFeedback()
		_feedback.current_status = "assisted_base_navigation: init"
		self._as.publish_feedback(_feedback)

		#[TODO]: Call move base state
		"""
		with sm:

			smach.StateMachine.add('move_base', move_base(),
						transitions={'completed':'completed',
						'not_completed':'not_completed',
						'pre-empted':'pre-empted',
						'failed':'failed'})
		"""
		output = "completed" #sm.execute();

		rospy.loginfo("...assisted_base_navigation state has finished.")
		return output


	########################################################################
	def assisted_arm_navigation(self, sm):
		rospy.loginfo("Executing assisted_arm_navigation state machine...")

		_feedback = dm_serverFeedback()
		_feedback.current_status = "assisted_arm_navigation: init"
		self._as.publish_feedback(_feedback)

		with sm:

			smach.StateMachine.add('simulate_dm', simulate_dm(),
						transitions={'completed':'move_arm_to_given_positions_assisted',
						'not_completed':'not_completed',
						'pre-empted':'pre-empted',
						'failed':'failed'})

			smach.StateMachine.add('move_arm_to_given_positions_assisted', move_arm_to_given_positions_assisted(),
						transitions={'completed':'move_arm_from_a_given_position_assisted',
						'not_completed':'move_arm_from_a_given_position_assisted',
						'pre-empted':'move_arm_from_a_given_position_assisted',
						'failed':'move_arm_from_a_given_position_assisted',
						'repeat': 'move_arm_to_given_positions_assisted'},
						remapping={'list_of_target_positions':'list_of_target_positions',
						'list_of_id_for_target_positions':'list_of_id_for_target_positions',
						'name_of_the_target_object':'name_of_the_target_object',
						'pose_of_the_target_object':'pose_of_the_target_object',
						'bb_of_the_target_object':'bb_of_the_target_object'}) 
			
			smach.StateMachine.add('move_arm_from_a_given_position_assisted', move_arm_from_a_given_position_assisted(),
						transitions={'completed':'completed',
						'not_completed':'not_completed',
						'pre-empted':'pre-empted',
						'failed':'failed'})

		output = sm.execute()

		rospy.loginfo("...assisted_arm_navigation state has finished.")
		return output


	########################################################################
	def assisted_grasping(self, sm):

		rospy.loginfo("Executing assisted_grasping state machine...")

		_feedback = dm_serverFeedback()
		_feedback.current_status = "assisted_grasp_navigation: init"
		self._as.publish_feedback(_feedback)

		with sm:

			smach.StateMachine.add('detect', detect_unknown_object_assisted(),
						transitions={'completed':'grasp_unknown_object_assisted',
						'not_completed':'not_completed',
						'pre-empted':'pre-empted',
						'failed':'failed'})

			smach.StateMachine.add('grasp_unknown_object_assisted', grasp_unknown_object_assisted(),
						transitions={'completed':'completed',
						'not_completed':'not_completed',
						'pre-empted':'pre-empted',
						'failed':'failed',
						'repeat_detection' : 'detect'})

		output = sm.execute()

		rospy.loginfo("...assisted_grasping state has finished.")
		return output



################################################################################
if __name__ == '__main__':

	rospy.init_node('ui_pro_server_for_dm')
	server = UI_PRO_Server_for_DM()
	rospy.spin()
