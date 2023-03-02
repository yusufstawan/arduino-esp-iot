/*********************************
 * Analog Sensor : Potensiometer
 * Sensor : Potensio
 * Board  : Arduino UNO
 * Output : Serial (9600)
 * Analog : A0, A1, A2, A3, A4, A5
 * Recommended pin use: A0
 *********************************/

// pilih salah satu pin untuk koneksi sensor
int potensioPin = A0;
// int potensioPin = A1;
// int potensioPin = A2;
// int potensioPin = A3;
// int potensioPin = A4;
// int potensioPin = A5;

int potensioValue = 0; // potensio value

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  potensioValue = analogRead(potensioPin); // baca potensio value
  Serial.println(potensioValue);           // tampilkan ke serial monitor
  delay(1000);
}
