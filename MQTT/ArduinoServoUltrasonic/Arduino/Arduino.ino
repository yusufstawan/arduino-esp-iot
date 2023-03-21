#include <Servo.h>

Servo myservo;
#define TRIG_PIN 9
#define ECHO_PIN 10

void setup()
{
  Serial.begin(9600);

  myservo.attach(9);
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
    Serial.println("Pintu terbuka");
    delay(2000);
  }
  else
  {
    myservo.write(0);
    Serial.println("Pintu tertutup");
    delay(2000);
  }
}
