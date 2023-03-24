#include <Servo.h>

Servo myservo;
#define TRIG_PIN 9
#define ECHO_PIN 10

void setup()
{
  Serial.begin(9600);

  myservo.attach(6);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop()
{
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  float duration_us = pulseIn(ECHO_PIN, HIGH);
  float distance_cm = 0.017 * duration_us;

  if (distance_cm < 10)
  {
    myservo.write(180);
    Serial.print("Pintu Terbuka");
    Serial.write('\0');
    delay(1000);
  }
  else
  {
    myservo.write(0);
    Serial.print("Pintu Tertutup");
    Serial.write('\0');
    delay(1000);
  }
}
