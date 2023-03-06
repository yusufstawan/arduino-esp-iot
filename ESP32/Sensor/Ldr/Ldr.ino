/*********************************
 * Sensor : LDR (Light Dependant Resistor)
 * Board  : ESP32
 * Output : Serial (9600)
 * PIN    : D4, D2, D15, D13, D12, D14, D27, D26, D25, D33, D32, D35, D34, VN, VP
 *********************************/

#define LIGHT_SENSOR_PIN 35

void setup()
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop()
{
  // reads the input on analog pin (value between 0 and 4095)
  int analogValue = analogRead(LIGHT_SENSOR_PIN);

  Serial.print("Analog Value = ");
  Serial.print(analogValue); // the raw analog reading

  // We'll have a few threshholds, qualitatively determined
  if (analogValue < 40)
  {
    Serial.println(" => Dark");
  }
  else if (analogValue < 800)
  {
    Serial.println(" => Dim");
  }
  else if (analogValue < 2000)
  {
    Serial.println(" => Light");
  }
  else if (analogValue < 3200)
  {
    Serial.println(" => Bright");
  }
  else
  {
    Serial.println(" => Very bright");
  }

  delay(500);
}
