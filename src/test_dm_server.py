#!/usr/bin/env python

import roslib; roslib.load_manifest('srs_ui_pro')
import rospy
import actionlib
import smach
import smach_ros
import simplejson as json

from srs_ui_pro.msg import *

class ui_echo_server_test():
	
	########################################################################
	def __init__(self):

		self.client = actionlib.SimpleActionClient('/srs_ui_pro/echo_server', dm_serverAction)

		rospy.loginfo("Waiting for echo_server...")
		self.client.wait_for_server()
		rospy.loginfo("[srs_ui_pro/echo_server]: Test for DM calls is running.")
		self.execute()


	########################################################################
	def execute(self):

		goal = dm_serverGoal()

		goal.json_input = '{"exception_id":55, "tasks":[{"time_schedule":1263798000000,"task":"move","destination":{"pose2d_string":"[0 1 3.14]"}}, {"time_schedule":2222222222,"task":"move","destination":{"pose2d_string":"[0 1 3.14]"}}], "additional_information":"The robot needs the user to assist in completing the task of moving to [0 1 3.14]"}'

		self.client.send_goal(goal)

		rospy.loginfo('Sending goal')
		self.client.wait_for_result()

		result = self.client.get_result()	


################################################################################
if __name__ == '__main__':
	rospy.init_node('srs_ui_pro_echo_server_test')
	server = ui_echo_server_test()

		
