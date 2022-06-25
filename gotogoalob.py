#! /usr/bin/env python

import rospy

from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist, Point 
from nav_msgs.msg import Odometry
from tf.transformations import euler_from_quaternion
from math import atan2

pub = None

def callback(msg):
   global a
   global b 
   a=msg.pose.pose.position.x
   b=msg.pose.pose.position.y


def callback_laser(msg):
  # 120 degrees into 3 regions
  regions = {
    'right':  min(min(msg.ranges[0:2]), 10),
    'front':  min(min(msg.ranges[3:5]), 10),
    'left':   min(min(msg.ranges[6:9]), 10),
  }
  
  take_action(regions)
  
def take_action(regions):
  threshold_dist = 1.5
  linear_speed = 0.6
  angular_speed = 1                                                            

  msg = Twist()
  linear_x = 0
  angular_z = 0
  goal=Point ()
  goal.x=5
  goal.y=5
  goalx=goalx-a
  goaly=goal.y-b
  angle=atan2(goaly, goalx)
  state_description = ''
  
  if regions['front'] > threshold_dist and regions['left'] > threshold_dist and regions['right'] > threshold_dist:
    state_description = 'case 1 - no obstacle'
    if angle > 0.1 :
      linear_x = 0.0
      angular_z = 0.3
    else :
      linear_x=0.5
      angular_z=0.0
 
 # elif regions['front'] < threshold_dist and regions['left'] < threshold_dist and regions['right'] < threshold_dist:
  #  state_description = 'case 7 - front and left and right'
   # linear_x = -linear_speed
    #angular_z = angular_speed # Increase this angular speed for avoiding obstacle faster
  #elif regions['front'] < threshold_dist and regions['left'] > threshold_dist and regions['right'] > threshold_dist:
   # state_description = 'case 2 - front'
    #linear_x = 0
    #angular_z = angular_speed
  #elif regions['front'] > threshold_dist and regions['left'] > threshold_dist and regions['right'] < threshold_dist:
   # state_description = 'case 3 - right'
   # linear_x = 0
   # angular_z = -angular_speed
  #elif regions['front'] > threshold_dist and regions['left'] < threshold_dist and regions['right'] > threshold_dist:
   # state_description = 'case 4 - left'
    #linear_x = 0
    #angular_z = angular_speed
  #elif regions['front'] < threshold_dist and regions['left'] > threshold_dist and regions['right'] < threshold_dist:
   # state_description = 'case 5 - front and right'
    #linear_x = 0
    #angular_z = -angular_speed
  #elif regions['front'] < threshold_dist and regions['left'] < threshold_dist and regions['right'] > threshold_dist:
   # state_description = 'case 6 - front and left'
    #linear_x = 0
    #angular_z = angular_speed
  #elif regions['front'] > threshold_dist and regions['left'] < threshold_dist and regions['right'] < threshold_dist:
  #  state_description = 'case 8 - left and right'
   # linear_x = linear_speed
    #angular_z = 0
  #else:
  #  state_description = 'unknown case'
   # rospy.loginfo(regions)

  rospy.loginfo(state_description)
  msg.linear.x = linear_x
  msg.angular.z = angular_z
  pub.publish(msg)

def main():
  global pub
  
  rospy.init_node('reading_laser')
  
  pub = rospy.Publisher('/cmd_vel', Twist, queue_size=1)
  
  sub = rospy.Subscriber('/robot/laser/scan', LaserScan, callback_laser)

  subs=rospy.Subscriber('/odom', Odometry, callback)
  
  rospy.spin()

if __name__ == '__main__':
  main()
