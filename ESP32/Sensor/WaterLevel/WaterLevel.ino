/*********************************
 * Monitoring Ketinggian Air
 * Sensor : Water Level Sensor
 * Board  : ESP 32
 * Output : Serial (9600)
 * S      : D4, D2, D15, D13, D12, D14, D27, D26, D25, D33, D32, D35, D34, VN, VP
 *********************************/

#define SIGNAL_PIN 15 // define the signal pin

int value = 0; // variable to store the sensor value

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  value = analogRead(SIGNAL_PIN); // read the analog value from sensor
  Serial.print("The water sensor value: ");
  Serial.println(value);

  delay(1000);
}
