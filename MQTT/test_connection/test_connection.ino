#include "env.h"
#include <WiFi.h>
#include <PubSubClient.h>

// WiFi
const char *ssid = wifi_ssid;         // Enter your WiFi name
const char *password = wifi_password; // Enter WiFi password

// MQTT Broker
const char *mqtt_broker = mqtt_broker_server;
const int mqtt_port = mqtt_port_server;
const char *mqtt_username = mqtt_username_server;
const char *mqtt_password = mqtt_password_server;
const char *topic = "/VARX/test";

WiFiClient espClient;
PubSubClient client(espClient);

void setup()
{
  // Set software serial baud to 115200;
  Serial.begin(115200);
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
  client.setCallback(callback);
  while (!client.connected())
  {
    String client_id = "esp32-client-";
    client_id += String(WiFi.macAddress());
    Serial.printf("The client %s connects to the public mqtt broker\n", client_id.c_str());
    if (client.connect(client_id.c_str(), mqtt_username, mqtt_password))
    {
      Serial.println("test connected");
    }
    else
    {
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }
  // publish and subscribe
  client.publish(topic, "{\"test_connect\": {\"value\":\"Hello World!\",\"unit\":\"OK\"}}");
  client.subscribe(topic);
}

void callback(char *topic, byte *payload, unsigned int length)
{
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  Serial.print("Message:");
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
  }
}

void loop()
{
  client.loop();
}
