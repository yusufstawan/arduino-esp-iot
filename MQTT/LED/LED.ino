#include "env.h"
#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <LiquidCrystal_I2C.h>

#define LED 15

// WiFi
const char *ssid = wifi_ssid;
const char *password = wifi_password;

// MQTT Broker
const char *mqtt_broker = mqtt_broker_server;
const int mqtt_port = mqtt_port_server;
const char *mqtt_username = mqtt_username_server;
const char *mqtt_password = mqtt_password_server;
const char *topic = "/VARX/led";

WiFiClient espClient;
PubSubClient client(espClient);

void setup()
{
  Serial.begin(115200);
  pinMode(LED, OUTPUT);

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
}
