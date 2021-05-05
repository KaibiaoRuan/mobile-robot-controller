#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define pingPin D7
#define echoPin D6

//const int pingPin = 7; // Trigger Pin of Ultrasonic Sensor
//const int echoPin = 6; // Echo Pin of Ultrasonic Sensor

const char *ssid = "MakerSpace"; // Enter your WiFi name
const char *password = "4%G9ZbYw2~6fazN";  // Enter WiFi password

// MQTT Broker
const char *mqtt_broker = "broker.emqx.io";
const char *dist_topic = "esp8266/dist";
const char *mqtt_username = "emqx";
const char *mqtt_password = "public";
const int mqtt_port = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
   Serial.begin(115200); // Starting Serial Terminal
   pinMode(pingPin, OUTPUT);
   pinMode(echoPin, INPUT);

   // connecting to a WiFi network
   WiFi.begin(ssid, password);
   while (WiFi.status() != WL_CONNECTED) {
       delay(500);
       Serial.println("Connecting to WiFi..");
   }
   Serial.println("Connected to the WiFi network");
   //connecting to a mqtt broker
   client.setServer(mqtt_broker, mqtt_port);
   //client.setCallback(callback);
   while (!client.connected()) {
       String client_id = "esp8266-client-";
       client_id += String(WiFi.macAddress());
       
       Serial.printf("The client %s connects to the public mqtt broker\n", client_id.c_str());
       if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
           Serial.println("Public emqx mqtt broker connected");
       } else {
           Serial.print("failed with state ");
           Serial.print(client.state());
           delay(2000);
       }
   }
 // publish and subscribe
  // client.publish(topic, "hello emqx");
  //client.subscribe(dist_topic);
}

void loop() {
   long duration, inches, cm;

   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);

   duration = pulseIn(echoPin, HIGH);
   Serial.println(duration);
   //inches = microsecondsToInches(duration);
   cm = microsecondsToCentimeters(duration);
//   Serial.print(inches);
//   Serial.print("in, ");
   Serial.print(cm);
   Serial.print("cm");
   Serial.println();
   client.publish(dist_topic, String(cm).c_str());
   delay(1000);
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
