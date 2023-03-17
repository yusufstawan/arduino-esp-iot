#include "env.h"
#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <ESP32_Servo.h>
#include <LiquidCrystal_I2C.h>

// WiFi
const char *ssid = wifi_ssid;
const char *password = wifi_password;

// MQTT Broker
const char *mqtt_broker = mqtt_broker_server;
const int mqtt_port = mqtt_port_server;
const char *mqtt_username = mqtt_username_server;
const char *mqtt_password = mqtt_password_server;
const char *topic = "/VARX/dht11";

WiFiClient espClient;
PubSubClient client(espClient);
