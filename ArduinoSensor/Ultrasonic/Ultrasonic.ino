/****************************************
  Pengukur jarak dengan sensor Ultrasonik
  HC-SR04   |   Arduino UNO
  ---------------------------
  Vcc       |   5V
  Gnd       |   GND
  TRIG      |   2
  ECHO      |   3
  www.ardutech.com
*****************************************/
int trig_pin = 2;
int echo_pin = 3;
long echotime;
float distance;

void setup()
{
  Serial.begin(9600);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  digitalWrite(trig_pin, LOW);
}

void loop()
{
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  echotime = pulseIn(echo_pin, HIGH);
  distance = 0.0001 * ((float)echotime * 340.0) / 2.0;
  Serial.print(distance);
  Serial.println(" cm");
  delay(2000);
}
