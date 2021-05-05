#!/usr/bin/env python3
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
        path.linear.x = 0.3
        path.linear.y = 0
        path.linear.z = 0
        path.angular.x = 0
        path.angular.y = 0
        path.angular.z = ii
        pub.publish(path)
        i += 0.1
        if(i>1):
            ii = 0
            i =0
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass