/*********************************
 * Monitoring Suhu
 * Sensor : LM35
 * Board  : Arduino UNO
 * Output : Serial (9600)
 * DATA : A0, A1, A2, A3, A4, A5
 *********************************/

// Define the analog pin, the LM35's Vout pin is connected to
#define sensorPin A0
// #define sensorPin A1
// #define sensorPin A2
// #define sensorPin A3
// #define sensorPin A4
// #define sensorPin A5

void setup()
{
  // Begin serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop()
{
  // Get the voltage reading from the LM35
  int reading = analogRead(sensorPin);

  // Convert that reading into voltage
  float voltage = reading * (5.0 / 1024.0);

  // Convert the voltage into the temperature in Celsius
  float temperatureC = voltage * 100;

  // Print the temperature in Celsius
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print(" C  |  ");

  // Print the temperature in Fahrenheit
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  Serial.print(temperatureF);
  Serial.println(" F");

  delay(1000); // wait a second between readings
}
