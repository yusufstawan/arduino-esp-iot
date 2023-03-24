#include "env.h"
#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

// WiFi
const char *ssid = wifi_ssid;
const char *password = wifi_password;

// MQTT Broker
const char *mqtt_broker = mqtt_broker_server;
const int mqtt_port = mqtt_port_server;
const char *mqtt_username = mqtt_username_server;
const char *mqtt_password = mqtt_password_server;
const char *topic = "/VARX/lampu";

WiFiClient espClient;
PubSubClient client(espClient);

void setup()
{
  Serial.begin(9600);
  // connecting to a WiFi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");

  // connecting to a mqtt broker
  client.setServer(mqtt_broker, mqtt_port);
}

void loop()
{
  client.loop();
  if (!client.connected())
  {
    reconnect();
  }
  else
  {
    StaticJsonDocument<200> doc;
    doc["statusLampu"]["value"] = Serial.readStringUntil('\0');
    doc["statusLampu"]["timestamp"] = __DATE__ " " __TIME__;
    char payload[200];
    serializeJson(doc, payload);

    client.publish(topic, payload);
    Serial.println("Data Arduino send to mqtt broker");
    delay(1000);
  }
}

void reconnect()
{
  String client_id = "esp32-client-";
  client_id += String(WiFi.macAddress());
  Serial.printf("The client %s connects to the public mqtt broker\n", client_id.c_str());
  if (client.connect(client_id.c_str(), mqtt_username, mqtt_password))
  {
    Serial.println("mqtt connected");
    delay(1000);
  }
  else
  {
    Serial.print("failed with state ");
    Serial.print(client.state());
    delay(2000);
  }
}
