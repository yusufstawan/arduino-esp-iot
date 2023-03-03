/*********************************
 * Pengukuran jarak dengan sensor ultrasonic
 * Sensor : HC-SR04
 * Board  : Arduino UNO
 * Output : Serial (9600)
 * Trig   : 3, 5, 6, 9, 10, 11
 * Echo   : 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13
 *********************************/

#include "NewPing.h"

// #define TRIGGER_PIN 3
// #define TRIGGER_PIN 5
// #define TRIGGER_PIN 6
#define TRIGGER_PIN 9
// #define TRIGGER_PIN 10
// #define TRIGGER_PIN 11

// #define ECHO_PIN 0
// #define ECHO_PIN 1
// #define ECHO_PIN 2
// #define ECHO_PIN 3
// #define ECHO_PIN 4
// #define ECHO_PIN 5
// #define ECHO_PIN 6
// #define ECHO_PIN 7
// #define ECHO_PIN 8
// #define ECHO_PIN 9
#define ECHO_PIN 10
// #define ECHO_PIN 11
// #define ECHO_PIN 12
// #define ECHO_PIN 13

// Maximum distance we want to ping for (in centimeters).
#define MAX_DISTANCE 400

// NewPing setup of pins and maximum distance.
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  Serial.print("Distance = ");
  Serial.print(sonar.ping_cm());
  Serial.println(" cm");
  delay(500);
}
