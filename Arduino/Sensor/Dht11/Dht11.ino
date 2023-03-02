/*********************************
 * Monitoring Suhu Kelembaban
 * Sensor : DHT11
 * Board  : Arduino UNO
 * Output : Serial (9600)
 * DATA : 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13
 *********************************/
#include <DHT.h> //library DHT

// pilih salah satu pin untuk koneksi sensor
// jika menggunakan pin 0 & 1, maka serial monitor tidak bisa digunakan
// #define DHTPIN 0
// #define DHTPIN 1
// #define DHTPIN 2
// #define DHTPIN 3
// #define DHTPIN 4
// #define DHTPIN 5
// #define DHTPIN 6
#define DHTPIN 7
// #define DHTPIN 8
// #define DHTPIN 9
// #define DHTPIN 10
// #define DHTPIN 11
// #define DHTPIN 12
// #define DHTPIN 13

#define DHTTYPE DHT11     // tipe sensor DHT11
DHT dht(DHTPIN, DHTTYPE); // set sensor + koneksi pin

float humi, temp; // deklarasi variabel

// make code for dht11 sensor and arduino uno
void setup()
{
  Serial.begin(9600); // set baudrate
  dht.begin();        // inisialisasi sensor
}

void loop()
{
  humi = dht.readHumidity();    // baca kelembaban
  temp = dht.readTemperature(); // baca suhu

  // cek apakah sensor terhubung
  if (isnan(humi) || isnan(temp))
  {
    Serial.println("Sensor tidak terhubung");
    return;
  }

  // tampilkan data ke serial monitor
  Serial.print("Kelembaban : ");
  Serial.print(humi);
  Serial.print(" %\t");
  Serial.print("Suhu : ");
  Serial.print(temp);
  Serial.println(" *C ");
  delay(2000);
}
