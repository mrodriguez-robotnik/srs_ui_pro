#!/usr/bin/env python

import roslib; roslib.load_manifest('srs_ui_pro')
import rospy
import actionlib
import smach
import smach_ros
import simplejson as json

from srs_ui_pro.msg import *

class ui_echo_server():
	
	########################################################################
	def __init__(self):

		self._as = actionlib.SimpleActionServer('srs_ui_pro/echo_server', dm_serverAction, self.execute, False)
		self._as.start()

		self._ui_msg = srs_ui_proEcho();
		self._ui_msg.status = 0;
		self._ui_msg.feedback = "Unknown";

        	self._ui_sub = rospy.Subscriber("/srs_ui_pro/gui/status", srs_ui_proEcho, self._ui_echo)

		rospy.loginfo("[srs_ui_pro/echo_server]: Server for DM calls is running.")


	########################################################################
	def _ui_echo(self, data):
			self._ui_msg = data	

	def _create_fb(self, exception_id, content):
		return "{\"exception_id\":"+str(exception_id)+", \"feedback_type \":\"unstructured\", \"content\":\""+content+"\"}";

	def _publish_fb(self, fb):
		_feedback = dm_serverFeedback()
		_feedback.json_feedback = fb
		self._as.publish_feedback(_feedback)

	def _create_result(self, exception_id, result):
		return "{\"exception_id\":"+str(exception_id)+", \"result\":\""+result+"\")";

	def _publish_result(self, result):
		_result = dm_serverResult()
		_result.json_result = result
		self._as.set_succeeded(_result)

	def _end(self, fb, ret):
		self._publish_fb(fb)
		self._publish_result(ret)
		self._ui_msg = srs_ui_proEcho();

	########################################################################
	def execute(self, goal):
		rospy.loginfo("[srs_ui_pro/echo_server]: New goal received (%s)", goal)
		rospy.loginfo("------------------------------------------------")

		exception_id = -1

		try:
			json_decoded = json.loads(goal.json_input)
			exception_id = json_decoded['exception_id']
			tasks = json_decoded['tasks']
			#something = tasks[0]['something']
			#info = json_decoded['additional_information']
		except json.JSONDecodeError:
			print "Oops, error when decoding goal.json_input", goal.json_input
			self._end(self._create_fb(exception_id, "Error when decoding json_input"), self._create_result(exception_id, "failed"))
			return

		rospy.loginfo("[srs_ui_pro/echo_server]: Waiting the srs_ui_pro...")
		while self._ui_sub.get_num_connections() == 0:
			self._publish_fb(self._create_fb(exception_id, "Waiting srs_ui_pro"))
    			rospy.sleep(1)
    			continue

		#This feedback warns to the srs_ui_pro/gui about the necessity of user intervention.
		self._publish_fb(self._create_fb(exception_id, "new_event"))
		rospy.sleep(5); #Allows the srs_ui_pro catch the event.

		#self._publish_fb("Waiting user choice...")

		while self._ui_msg.status == 0:
			rospy.loginfo("[srs_ui_pro/echo_server]: Waiting user intervention...")
			rospy.sleep(5);


		#No intervention
		if self._ui_msg.status == -42:
			rospy.logerr("[srs_ui_pro/echo_server]: User can't help you now... :(")
			self._end(self._create_fb(exception_id, self._ui_msg.feedback), self._create_result(exception_id, "failed"))
			return

		#User intervention
		rospy.loginfo("[srs_ui_pro/echo_server]: User is trying to solve your problem...")
		last_feedback = "Unknown";
		while self._ui_msg.status == 42: #user operating
			if last_feedback != self._ui_msg.feedback:
				last_feedback = self._ui_msg.feedback
				self._publish_fb(self._create_fb(exception_id, last_feedback))


		rospy.loginfo("[srs_ui_pro/echo_server]: User has finished!")
		status = "succeeded" if (self._ui_msg.status == 1) else "failed"

		self._end(self._create_fb(exception_id, status), self._create_result(exception_id, status))
		return


################################################################################
if __name__ == '__main__':
	rospy.init_node('srs_ui_pro_echo_server')
	server = ui_echo_server()
	rospy.spin()

		
