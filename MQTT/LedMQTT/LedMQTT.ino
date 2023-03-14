#include "env.h"
#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#define LED 5

const char *ssid = wifi_ssid;
const char *password = wifi_ssid;

const char *mqtt_broker = mqtt_broker_server;
const int mqtt_port = mqtt_port_server;
const char *mqtt_username = mqtt_username_server;
const char *mqtt_password = mqtt_password_server;
const char *topic = "/VARX/led";

WiFiClient espClient;
PubSubClient client(espClient);

/// Variabel Data Format Json
char data1[150];
char data2[150];
StaticJsonDocument<200> doc;

long lastMsg = 0;
char msg[50];
int value = 0;

char LedString[8];
int BUTTON = 16;
// int LED   = 18;
int ledState = LOW;
int previousButtonState;
int presentButtonState;

void setup()
{
  Serial.begin(115200);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  presentButtonState = digitalRead(BUTTON);

  // connecting to a WiFi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Connecting to WiFi..");
    delay(500);
  }
  Serial.println("Connected to the WiFi network");

  // connecting to a mqtt broker
  client.setServer(mqtt_broker, mqtt_port);
  client.setCallback(callback);
  while (!client.connected())
  {
    String client_id = "mqtt-ledtoggle";
    // client_id += String(WiFi.macAddress());
    Serial.printf("The client %s connects to the public mqtt broker\n", client_id.c_str());
    if (client.connect(client_id.c_str(), mqtt_username, mqtt_password))
    {
      Serial.println("Connected to the MQTT Broker");
    }
    else
    {
      Serial.print("Failed with state");
      Serial.print(client.state());
      delay(2000);
    }
  }

  // publish and subscribe
  client.publish(topic, "LED");
  client.subscribe(topic);
}

void callback(char *topic, byte *payload, unsigned int length)
{
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  String message;
  for (int i = 0; i < length; i++)
  {
    message = message + (char)payload[i]; // convert *byte to string
  }
  Serial.print(message);
  Serial.print(client.subscribe("varx/controlled"));
  if (message == "on")
  {
    digitalWrite(LED, HIGH);
  }
  if (message == "off")
  {
    digitalWrite(LED, LOW);
  }
  Serial.println();
  Serial.println("-----------------------");
}

void loop()
{
  client.loop();
  previousButtonState = presentButtonState;
  presentButtonState = digitalRead(BUTTON);

  String payload = "{\"device\":\"ESP-32\",\"message\":\"LED MENYALA\",\"value\":" + String(1) + "}}";
  String payload2 = "{\"device\":\"ESP-32\",\"massage\":\"LED MATI\",\"value\":" + String(0) + "}";
  payload.toCharArray(data1, (payload.length()));
  payload2.toCharArray(data2, (payload.length()));

  if (previousButtonState == HIGH && presentButtonState == LOW)
  {
    ledState = !ledState;
    digitalWrite(LED, ledState);
    digitalRead(ledState);
    if (ledState == HIGH)
    {
      Serial.println("LED MENYALA");
      Serial.print("LED : ");
      Serial.println(ledState);
      client.publish(topic, data1);
    }
    else
    {
      Serial.println("LED MATI");
      Serial.print("LED : ");
      Serial.println(ledState);
      client.publish(topic, data2);
    }
  }
}
