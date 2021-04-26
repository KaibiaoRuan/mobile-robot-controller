#!/usr/bin/env python
# license removed for brevity


import rospy
from geometry_msgs.msg import Twist

def talker():
    pub = rospy.Publisher('/cmd_vel', Twist, queue_size=10)
    rospy.init_node('mobile_talker_node', anonymous=True)
    rate = rospy.Rate(10) # 10hz
    i = 0
    ii = 0.0
    while not rospy.is_shutdown():
        path = Twist()
        path.linear.x = 8
        path.linear.y = 0
        path.linear.z = 0
        path.angular.x = 0
        path.angular.y = 0
        path.angular.z = ii
        pub.publish(path)
        i += 1
        if(i>5):
            ii = 18
        if(i>17):
            ii = 0
            i =0
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass