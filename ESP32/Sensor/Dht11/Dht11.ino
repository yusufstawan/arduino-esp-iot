/*********************************
 * Monitoring Suhu Kelembaban
 * Sensor : DHT11
 * Board  : ESP32
 * Output : Serial (9600)
 * DATA : D15 (GPIO 15), D2 (GPIO 2), D4 (GPIO 4), RX2 (GPIO 16), TX2 (GPIO 17), D5 (GPIO 5), D18 (GPIO 18),
 *        D19 (GPIO 19), D21 (GPIO 21), RX0 (GPIO 3), TX0 (GPIO 1), D22 (GPIO 22), D23 (GPIO 23)
 *        D13 (GPIO 13), D12 (GPIO 12), D14 (GPIO 14), D27 (GPIO 27), D26 (GPIO 26), D25 (GPIO 25),
 *        D33 (GPIO 33), D32 (GPIO 32), D35 (GPIO 35), D34 (GPIO 34), D39 (GPIO 39), VP (GPIO 36),
 * Recommended pin use : D21 (GPIO 21)
 *********************************/

#include <DHT.h>

// pilih salah satu pin untuk koneksi sensor
// jika menggunakan pin RX0, TX0, RX2, TX2, maka serial monitor tidak bisa digunakan

#define DHT_SENSOR_PIN 21
// #define DHT_SENSOR_PIN 15
// #define DHT_SENSOR_PIN 2
// #define DHT_SENSOR_PIN 4
// #define DHT_SENSOR_PIN 5
// #define DHT_SENSOR_PIN 18
// #define DHT_SENSOR_PIN 19
// #define DHT_SENSOR_PIN 22
// #define DHT_SENSOR_PIN 23
// #define DHT_SENSOR_PIN 13
// #define DHT_SENSOR_PIN 12
// #define DHT_SENSOR_PIN 14
// #define DHT_SENSOR_PIN 27
// #define DHT_SENSOR_PIN 26
// #define DHT_SENSOR_PIN 25
// #define DHT_SENSOR_PIN 33
// #define DHT_SENSOR_PIN 32
// #define DHT_SENSOR_PIN 35
// #define DHT_SENSOR_PIN 34
// #define DHT_SENSOR_PIN 39
// #define DHT_SENSOR_PIN 36

#define DHT_SENSOR_TYPE DHT11

DHT dht_sensor(DHT_SENSOR_PIN, DHT_SENSOR_TYPE);

void setup()
{
  Serial.begin(9600);
  dht_sensor.begin();
}

void loop()
{
  float humi = dht_sensor.readHumidity();
  float tempC = dht_sensor.readTemperature();
  float tempF = dht_sensor.readTemperature(true);

  if (isnan(tempC) || isnan(tempF) || isnan(humi))
  {
    Serial.println("Sensor tidak terhubung!");
  }
  else
  {
    Serial.print("Kelembaban: ");
    Serial.print(humi);
    Serial.print("%");

    Serial.print("  |  ");

    Serial.print("Suhu: ");
    Serial.print(tempC);
    Serial.print(" C  ~  ");
    Serial.print(tempF);
    Serial.println(" F");
  }
  delay(2000);
}
