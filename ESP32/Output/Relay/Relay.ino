/*********************************
 * Sensor : Relay 1 Channel
 * Board  : ESP32
 * Output : Serial (9600)
 * S      : D15
 *********************************/

int RelayPin = 15;

void setup()
{
  Serial.begin(9600);
  pinMode(RelayPin, OUTPUT);
}

void loop()
{
  digitalWrite(RelayPin, LOW);
  Serial.println("Relay ON");
  delay(3000);

  digitalWrite(RelayPin, HIGH);
  Serial.println("Relay OFF");
  delay(3000);
}
