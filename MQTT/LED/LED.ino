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
const char *topic = "/VARX/led";

WiFiClient espClient;
PubSubClient client(espClient);

// led pin
#define LED 15
LiquidCrystal_I2C lcd(0x27, 16, 2); // Setting Alamat I2C LCD dan ukuran LCD

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

  // init lcd
  lcd.init();
  lcd.clear();
  lcd.backlight();
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

    lcd.setCursor(0, 1);
    lcd.print("Lampu Hidup");
  }
  if (message == "off")
  {
    digitalWrite(LED, LOW);

    lcd.setCursor(0, 1);
    lcd.print("Lampu  Mati");
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
      lcd.setCursor(0, 0);
      lcd.clear();
      lcd.print("MQTT Connected");

      Serial.println("mqtt connected");

      delay(1000);
    }
    else
    {
      lcd.setCursor(0, 0);
      lcd.clear();
      lcd.print("MQTT Failed");

      Serial.print("failed with state ");
      Serial.print(client.state());

      delay(2000);
    }
  }
}

void loop()
{
  client.subscribe(topic);
  if (!client.connected())
  {
    reconnect();
  }
  client.loop();
}
