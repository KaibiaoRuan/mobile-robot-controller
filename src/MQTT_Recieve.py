import paho.mqtt.client as mqtt

#Connection success callback
def on_connect(client, userdata, flags, rc):
    print('Connected with result code '+str(rc))
    client.subscribe('esp8266/y_axis')
    client.subscribe('esp8266/x_axis')

# Message receiving callback
def on_message(client, userdata, msg):
    print(msg.topic, " : ", int(msg.payload))
    # count = int.from_bytes(msg.payload, "big")  
    # print(count)     

client = mqtt.Client()

# Specify callback function
client.on_connect = on_connect
client.on_message = on_message


# Establish a connection
client.connect('broker.emqx.io', 1883, 60)
# Publish a message
# client.publish('emqtt',payload='Hello World',qos=0)

client.loop_forever()
