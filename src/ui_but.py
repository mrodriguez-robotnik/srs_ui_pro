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


class UI_BUT_server():

	########################################################################
	def __init__(self):

		self._as = actionlib.SimpleActionServer('srs_ui_pro/ui_but_server', ui_butAction, self.execute, False)
		self._as.start()
		rospy.loginfo("[UI_BUT]: Server between srs_ui_pro and BUT states is running.")


	########################################################################
	def execute(self, goal):
		rospy.loginfo("[UI_BUT]: New goal received (%s)", goal)

		_result = ui_butResult()
		_feedback = ui_butFeedback()

		sm = smach.StateMachine(outcomes=['completed','not_completed','failed','pre-empted'])


		if goal.excepcional_case_id == ExcepcionalCases.ASSISTED_ARM_NAVIGATION:
			_result.output = self.assisted_arm_navigation(sm)

		elif goal.excepcional_case_id == ExcepcionalCases.ASSISTED_GRASPING:
			_result.output = self.assisted_grasping(sm)

		else: 
			_feedback.feedback = "unknown"
			_result.output =" unknown"
			self._as.publish_feedback(_feedback)


		self._as.set_succeeded(_result)
		return
		



	########################################################################
	def assisted_arm_navigation(self, sm):
		rospy.loginfo("[UI_BUT]: Executing assisted_arm_navigation state machine...")
		
		_feedback = ui_butFeedback()
		_feedback.feedback = "assisted_arm_navigation: init"
		self._as.publish_feedback(_feedback)
		
		with sm:
			rospy.logwarn("assisted_arm_navigation: Using simulated params...");
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
		

		rospy.loginfo("[UI_BUT]: ...assisted_arm_navigation state has finished.")
		return output



	########################################################################
	def assisted_grasping(self, sm):

		rospy.loginfo("[UI_BUT]: Executing assisted_grasping state machine...")

		_feedback = ui_butFeedback()
		_feedback.feedback = "assisted_grasp_navigation: init"
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

		rospy.loginfo("[UI_BUT]:  ...assisted_grasping state has finished.")
		return output



################################################################################
if __name__ == '__main__':

	rospy.init_node('ui_but_server')
	server = UI_BUT_server()
	rospy.spin()
