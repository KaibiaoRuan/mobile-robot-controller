# Mobile-Robot-Controller

### MQTT_Recieve.py
Located in /mobrob/src
Bridge between MQTT Broker and ROS node
____

### Ultrasonic_Sensor.ino
Located in /mqtt_esp8266_ultrasonic_sensor
Runs on NodeMCU to send distance from ultrasonic sensor to MQTT Broker
____

### mqtt_esp8266_x_axis.ino
Located in /mqtt_esp8266_x_axis
Runs on NodeMcu to send x axis values from joystick to MQTT Broker
____

### mqtt_esp8266_y_axis.ino
Located in /mqtt_esp8266_y_axis
Runs on NodeMcu to send y axis values from joystick to MQTT Broker
____

## How to run
`roslaunch mobrob mobile_sim.launch`
In a new tab

`rosrun mobrob MQTT_Recieve.py`
