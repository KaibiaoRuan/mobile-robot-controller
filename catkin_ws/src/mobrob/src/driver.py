#!/usr/bin/env python3
# license removed for brevity


import rospy
import traceback
# import the message type by name (here "ME439WheelSpeeds")
from mobrob_util.msg import ME439WheelSpeeds
from geometry_msgs.msg import Twist

#==============================================================================
# # Get parameters from rosparam
#==============================================================================

wheel_width = 0.151
#rospy.get_param('/wheel_width_actual') # 0.151 # meters
left_vel = 0
right_vel = 0

def driver():
    
    rospy.init_node('driver_node', anonymous=False)

    rospy.Subscriber("/cmd_vel", Twist, update_velocity)
    
    speed_publisher()

def update_velocity(msg_in):
    global wheel_width,left_vel,right_vel
    
    vel_x = msg_in.linear.x;
    vel_th = msg_in.angular.z;
    if(vel_x == 0):
        right_vel = vel_th * wheel_width / 2.0
        left_vel = (-1) * right_vel
    elif(vel_th == 0):
        left_vel = right_vel = vel_x
    else:
        left_vel = vel_x - vel_th / 2.0
        right_vel = vel_x + vel_th / 2.0
    
# Publish desired wheel speeds at the appropriate time. 
def speed_publisher(): 
    global left_vel,right_vel

    # Create the publisher. Name the topic "sensors_data", with message type "Sensors"
    pub_speeds = rospy.Publisher('/wheel_speeds_desired', ME439WheelSpeeds, queue_size=10)
    # Declare the message that will go on that topic. 
    # Here we use one of the message name types we Imported, and add parentheses to call it as a function. 
    # We could also put data in it right away using . 
    msg_out = ME439WheelSpeeds()
    msg_out.v_left = 0
    msg_out.v_right = 0
    
    # set up a rate basis to keep it on schedule.
    r = rospy.Rate(100) # N Hz
    try: 
        # start a loop 
        while not rospy.is_shutdown():
            msg_out.v_left = left_vel
            msg_out.v_right = right_vel
            # publish the message
            pub_speeds.publish(msg_out)
            # Log the info (optional)
#            rospy.loginfo(pub_speeds)    
            
            r.sleep()
            
    except Exception:
        traceback.print_exc()
        # When done or Errored, Zero the speeds
        msg_out.v_left = 0
        msg_out.v_right = 0
        pub_speeds.publish(msg_out)
        #rospy.loginfo(pub_speeds)    
        pass
        
        
    # When done or Errored, Zero the speeds
    msg_out.v_left = 0
    msg_out.v_right = 0
    pub_speeds.publish(msg_out)
    #rospy.loginfo(pub_speeds)   

if __name__ == '__main__':
    try:
        driver()
    except rospy.ROSInterruptException:
        pass