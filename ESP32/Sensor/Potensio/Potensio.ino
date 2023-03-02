/*********************************
 * Analog Sensor : Potensiometer
 * Sensor : Potensio
 * Board  : ESP32
 * Output : Serial (9600)
 * Analog : D4, D2, D15, D13, D12, D14, D27, D26, D25, D33, D32, D35, D34, VN, VP
 * Recommended pin use: D2 (GPIO 2)
 *********************************/

// pilih salah satu pin untuk koneksi sensor
int potensioPin = 2;
// int potensioPin = 4;
// int potensioPin = 15;
// int potensioPin = 13;
// int potensioPin = 12;
// int potensioPin = 14;
// int potensioPin = 27;
// int potensioPin = 26;
// int potensioPin = 25;
// int potensioPin = 33;
// int potensioPin = 32;
// int potensioPin = 35;
// int potensioPin = 34;
// int potensioPin = 39;
// int potensioPin = 36;

void setup()
{
  Serial.begin(9600);
  // buat resolusi 12 bit (0-4096)
  analogReadResolution(12);
}

void loop()
{
  // baca potensio value
  int analogValue = analogRead(potensioPin);
  int analogVolts = analogReadMilliVolts(potensioPin);

  // tampilkan ke serial monitor
  Serial.printf("ADC analog value = %d\n", analogValue);
  Serial.printf("ADC millivolts value = %d\n", analogVolts);
  delay(1000);
}
