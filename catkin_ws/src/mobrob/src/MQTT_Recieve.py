#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Twist
import paho.mqtt.client as mqtt

x_vel = 0

#Connection success callback
def on_connect(client, userdata, flags, rc):
    print('Connected with result code '+str(rc))
    client.subscribe('esp8266/y_axis')
    client.subscribe('esp8266/x_axis')

# Message receiving callback
def on_message(client, userdata, msg):
    global x_vel
    print(msg.topic, " : ", int(msg.payload))
    print(str(msg.topic))
    # count = int.from_bytes(msg.payload, "big")  
    # print(count)   
    if(str(msg.topic) == "esp8266/x_axis"):
        if(int(msg.payload) > 500) and (int(msg.payload) < 600):
            x_vel = 0.0
        else:
            x_vel = float(int(msg.payload)-612)/612/4
    elif(str(msg.topic) == "esp8266/y_axis"):
        cmd_msg.linear.x = x_vel
        cmd_msg.linear.y = 0
        cmd_msg.linear.z = 0
        cmd_msg.angular.x = 0
        cmd_msg.angular.y = 0
        if(int(msg.payload) > 500) and (int(msg.payload) < 600):
            cmd_msg.angular.z = 0.0
        else:
            cmd_msg.angular.z = float(int(msg.payload)-612)/612/4
        pub_cmd.publish(cmd_msg)


if __name__ == "__main__":
    try:
        rospy.init_node('mqtt_bridge', anonymous=True)
	
        pub_cmd = rospy.Publisher('/cmd_vel', Twist, queue_size=1)
        cmd_msg = Twist()
        	
        client = mqtt.Client()
        	
        	# Specify callback function
        client.on_connect = on_connect
        client.on_message = on_message
        	
        	
        	# Establish a connection
        client.connect('broker.emqx.io', 1883, 60)
	# Publish a message
	# client.publish('emqtt',payload='Hello World',qos=0)
	
        client.loop_forever()
    except rospy.ROSInterruptException: 
        traceback.print_exc()
        pass

