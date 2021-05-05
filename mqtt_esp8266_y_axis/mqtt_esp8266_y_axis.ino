#include <ESP8266WiFi.h>
#include <PubSubClient.h>

//LEDs
#define LED0  D0
#define LED1  D1
#define LED2  D2
#define LED3  D3
#define LED4  D4
#define LED5  D5

//Joystick PS2
#define X_axis A0

// WiFi
const char *ssid = "MakerSpace"; // Enter your WiFi name
const char *password = "4%G9ZbYw2~6fazN";  // Enter WiFi password


// MQTT Broker
const char *mqtt_broker = "broker.emqx.io";
const char *topic = "esp8266/y_axis";
const char *dist_topic = "esp8266/dist";
const char *mqtt_username = "emqx";
const char *mqtt_password = "public";
const int mqtt_port = 1883;
int count;
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  // Set up joystick
  pinMode(X_axis, INPUT);

  // Set up LEDs
  pinMode(LED0, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  
  count = 0;
 // Set software serial baud to 115200;
 Serial.begin(115200);
 // connecting to a WiFi network
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
     delay(500);
     Serial.println("Connecting to WiFi..");
 }
 Serial.println("Connected to the WiFi network");
 //connecting to a mqtt broker
 client.setServer(mqtt_broker, mqtt_port);
 client.setCallback(callback);
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
  client.subscribe(dist_topic);
}

void callback(char *topic, byte *payload, unsigned int length) {
 Serial.print("Message arrived in topic: ");
 Serial.println(topic);
 Serial.print("Message:");

  
  payload[length] = '\0'; // Add a NULL to the end of the char* to make it a string.
  int aNumber = atoi((char *)payload);
 Serial.print(aNumber);

  if(aNumber <= 30){
    digitalWrite(LED0, HIGH);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
  }
  else if(aNumber > 400){
    digitalWrite(LED0, LOW);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
  }
  else if(aNumber > 30 && aNumber < 100){
    digitalWrite(LED0, HIGH);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
  }
  else{
    digitalWrite(LED0, HIGH);
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
  }
  
}

void loop() {
 client.loop();

 delay(250);
 int x_val = analogRead(X_axis);
 Serial.println(String(x_val).c_str());
// char msg[101] = {char(x_val)};
// Serial.println(msg);
 client.publish(topic, String(x_val).c_str());
 count++;
}
