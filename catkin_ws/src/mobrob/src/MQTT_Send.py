#!/usr/bin/env python2
# -*- coding: utf-8 -*-
"""
Created on Tue May  4 09:19:32 2021

@author: pi
"""

import rospy
import paho.mqtt.client as mqtt
import json
from std_msgs.msg import Float32
import time

from mobrob_util.msg import ME439SensorsRaw
from mobrob_util.msg import ME439SensorsProcessed

client = mqtt.Client()

client.connect("broker.emqx.io", 1883, 60)

def callback(data):
    dist = {
            "distance": str(data)
            }
   
    client.publish("esp8266/dist",json.dumps(dist))
    
    
def mqtt_bridge():
    rospy.init_node('mqtt_bridge1',anonymous=True)
    
    rospy.Subscriber('/sensors_A0_proc',Float32, callback)
    
    rospy.spin()
    
    
if __name__ == "__main__":
    mqtt_bridge()