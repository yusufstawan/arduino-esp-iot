#include "env.h"
#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <LiquidCrystal_I2C.h>

// WiFi
const char *ssid = wifi_ssid;
const char *password = wifi_password;

// MQTT Broker
const char *mqtt_broker = mqtt_broker_server;
const int mqtt_port = mqtt_port_server;
const char *mqtt_username = mqtt_username_server;
const char *mqtt_password = mqtt_password_server;
const char *topic = "/VARX/ultrasonic";

WiFiClient espClient;
PubSubClient client(espClient);

#define TRIG_PIN 2
#define ECHO_PIN 15
float duration_us, distance_cm;
LiquidCrystal_I2C lcd(0x27, 16, 2);

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

  // configure the trigger pin to output mode
  pinMode(TRIG_PIN, OUTPUT);
  // configure the echo pin to input mode
  pinMode(ECHO_PIN, INPUT);

  // init lcd
  lcd.init();
  lcd.clear();
  lcd.backlight();
}

void callback(char *topic, byte *payload, unsigned int length)
{
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  Serial.print("Message:");
  for (int i = 0; i < length; i++)
  {
    Serial.print((char)payload[i]);
    lcd.setCursor(2, 0);
    lcd.print("Message: ");
    lcd.print((char)payload[i]);

    lcd.setCursor(2, 1);
    lcd.print("Topic: ");
    lcd.print(topic);

    delay(1000);
    lcd.clear();
  }
  Serial.println();
  Serial.println("-----------------------");
}

void reconnect()
{
  if (!client.connected())
  {
    String client_id = "esp32-client-";
    client_id += String(WiFi.macAddress());
    Serial.printf("The client %s connects to the public mqtt broker\n", client_id.c_str());
    if (client.connect(client_id.c_str(), mqtt_username, mqtt_password))
    {
      Serial.println("mqtt connected");
      lcd.setCursor(2, 0);
      lcd.print("MQTT Connected");
      delay(1000);
      lcd.clear();
    }
    else
    {
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

void loop()
{
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);

  // calculate the distance
  distance_cm = 0.017 * duration_us;

  // print the value to Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance_cm);
  Serial.println(" cm");

  // send JSON using ArduinoJson
  StaticJsonDocument<200> doc;
  doc["distance"]["value"] = distance_cm;
  doc["distance"]["unit"] = "cm";
  char payload[200];
  serializeJson(doc, payload);

  // publish and subscribe
  client.publish(topic, payload);
  client.subscribe("/VARX/receive");

  lcd.setCursor(2, 0);
  lcd.print("Distance: ");
  lcd.print(distance_cm);
  lcd.print(" cm");
  lcd.clear();

  delay(5000);

  if (!client.connected())
  {
    reconnect();
  }
  client.loop();
}
