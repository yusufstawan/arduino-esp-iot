/*********************************
 * Monitoring Suara dan Sinyal Analog Suara
 * Sensor : Sound Sensor
 * Board  : Arduino UNO
 * Output : Serial (9600)
 * DO     : D2, D3, D4, D5, D6, D7, D8, D9, D10, D11, D12, D13
 *********************************/

#define sensorPin 8

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
