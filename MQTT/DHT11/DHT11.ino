#include "env.h"
#include <WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>
#include <DHT.h>
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

#define DHT_SENSOR_PIN 15
#define DHT_SENSOR_TYPE DHT11
DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); // Setting Alamat I2C LCD dan ukuran LCD

void setup()
{
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

  // init dht sensor
  dht_sensor.begin();
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
    // make lcd print scroll left

    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("Message:");

    lcd.setCursor(0, 1);
    lcd.print((char)payload[i]);

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
      lcd.setCursor(0, 0);
      lcd.clear();
      lcd.print("MQTT Connected");

      Serial.println("mqtt connected");

      delay(1000);
      lcd.clear();
    }
    else
    {
      lcd.setCursor(0, 0);
      lcd.clear();
      lcd.print("MQTT Failed");

      Serial.print("failed with state ");
      Serial.print(client.state());

      delay(2000);
      lcd.clear();
    }
  }
}

void loop()
{
  // send sensor dht 11 to mqtt broker
  float temperature = dht_sensor.readTemperature();
  float humidity = dht_sensor.readHumidity();

  // send JSON using ArduinoJson
  StaticJsonDocument<200> doc;
  doc["dht11"]["temperature"]["value"] = temperature;
  doc["dht11"]["temperature"]["unit"] = "C";
  doc["dht11"]["humidity"]["value"] = humidity;
  doc["dht11"]["humidity"]["unit"] = "%";
  char payload[200];
  serializeJson(doc, payload);

  // publish and subscribe
  client.publish(topic, payload);
  client.subscribe("/VARX/receive");

  Serial.printf("Temperature: %.2f C, Humidity: %.2f %%\n", temperature, humidity);

  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");
  lcd.setCursor(0, 1);
  lcd.print("Humd: ");
  lcd.print(humidity);
  lcd.print(" %");

  delay(5000);

  if (!client.connected())
  {
    reconnect();
  }
  client.loop();
}
