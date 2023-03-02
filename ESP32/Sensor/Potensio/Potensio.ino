/*********************************
 * Analog Sensor : Potensiometer
 * Sensor : Potensio
 * Board  : ESP32
 * Output : Serial (9600)
 * Analog :
 * Recommended pin use: A0
 *********************************/

// pilih salah satu pin untuk koneksi sensor
int potensioPin = 2;

void setup()
{
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);

  // set the resolution to 12 bits (0-4096)
  analogReadResolution(12);
}

void loop()
{
  // read the analog / millivolts value for pin 2:
  int analogValue = analogRead(potensioPin);
  int analogVolts = analogReadMilliVolts(potensioPin);

  // print out the values you read:
  Serial.printf("ADC analog value = %d\n", analogValue);
  Serial.printf("ADC millivolts value = %d\n", analogVolts);

  delay(100); // delay in between reads for clear read from serial
}
