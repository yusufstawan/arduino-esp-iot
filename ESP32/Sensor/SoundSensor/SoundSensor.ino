/*********************************
 * Monitoring Suara dan Sinyal Analog Suara
 * Sensor : Sound Sensor
 * Board  : Arduino UNO
 * Output : Serial (9600)
 * DO     : D15 (GPIO 15), D2 (GPIO 2), D4 (GPIO 4), RX2 (GPIO 16), TX2 (GPIO 17), D5 (GPIO 5), D18 (GPIO 18),
 *          D19 (GPIO 19), D21 (GPIO 21), RX0 (GPIO 3), TX0 (GPIO 1), D22 (GPIO 22), D23 (GPIO 23)
 *          D13 (GPIO 13), D12 (GPIO 12), D14 (GPIO 14), D27 (GPIO 27), D26 (GPIO 26), D25 (GPIO 25),
 *          D33 (GPIO 33), D32 (GPIO 32), D35 (GPIO 35), D34 (GPIO 34), D39 (GPIO 39), VP (GPIO 36),
 *********************************/

#define sensorPin 15

// Variable to store the time when last event happened
unsigned long lastEvent = 0;

void setup()
{
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  // Read Sound sensor
  int sensorData = digitalRead(sensorPin);

  // If pin goes LOW, sound is detected
  if (sensorData == LOW)
  {

    // If 25ms have passed since last LOW state, it means that
    // the clap is detected and not due to any spurious sounds
    if (millis() - lastEvent > 25)
    {
      Serial.println("Suara terdeteksi!");
    }

    // Remember when last event happened
    lastEvent = millis();
  }
}
