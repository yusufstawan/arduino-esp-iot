/*********************************
 * Sensor : RTC DS1302
 * Board  : ESP32
 * Output : Serial (9600)
 *********************************/

// memanggil library header virtuabotixRTC
#include <virtuabotixRTC.h>

// Inisialisasi pin (CLK, DAT, RST)
// CLK = D15 (GPIO 15)
// DAT = D2 (GPIO 2)
// RST = D4 (GPIO 4)
virtuabotixRTC myRTC(15, 2, 4);

void setup()
{
  // Inisialisasi port serial arduino dengan komputer
  Serial.begin(9600);

  // penulisan data pertama kali dan disarankan saat transfer
  // ke-2 ini tidak digunakan dikarenakan akan menghapus data
  // sebelumnya
  myRTC.setDS1302Time(13, 23, 13, 7, 07, 03, 2023);
  // detik, menit, jam, hari dalam seminggu, tanggal, bulan, tahun
}

void loop()
{
  // memanggil fungsi untuk update data waktu
  myRTC.updateTime();

  // penulisan data pada serial monitor komputer
  Serial.print("Current Date / Time: ");
  // fungsi penulisan data untuk tanggal
  Serial.print(myRTC.dayofmonth);

  // penulisan data "/" sebagai separator
  Serial.print("/");

  // fungsi penulisan data untuk bulan
  Serial.print(myRTC.month);

  // penulisan data "/" sebagai separator
  Serial.print("/");

  // fungsi penulisan data untuk tahun
  Serial.print(myRTC.year);

  // penulisan data untuk jarak
  Serial.print(" ");

  // fungsi penulisan data untuk jam
  Serial.print(myRTC.hours);

  Serial.print(":");

  // fungsi penulisan data untuk menit
  Serial.print(myRTC.minutes);

  Serial.print(":");

  // fungsi penulisan data untuk detik
  Serial.println(myRTC.seconds);
  delay(1000);
}
