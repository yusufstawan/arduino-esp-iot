## Example Project for Arduino, ESP32 and ESP8266

This is a simple example project for Arduino, ESP32 and ESP8266. It is intended to be used as a starting point for your own projects.

### Arduino IDE

- Install the Arduino IDE
- Install the ESP8266 board support package
- Install the ESP32 board support package

### Visual Studio Code

- Install Visual Studio Code
- Install the Arduino extension
- Install the C/C++ extension

### Project Setup

- Clone this repository
- Open the project folder in Visual Studio Code
- Select the correct board in the Arduino extension
- Select the correct port in the Arduino extension
- Build and upload the sketch
- create env.h file in the project folder need credetial for wifi or mqtt broker:

```c++

#ifndef env_h
#define env_h

// Wifi
const char *wifi_ssid = "your_ssid";
const char *wifi_password = "your_password";

// MQTT broker
const char *mqtt_broker_server = "your_server";
const int mqtt_port_server = 1234;
const char *mqtt_username_server = "username";
const char *mqtt_password_server = "password";

#endif

```

### Project Structure

- `Arduino/` - Arduino sketches
- `ESP32/` - ESP32 sketches
- `ESP8266/` - ESP8266 sketches
- `lib/` - Libraries
- `MQTT/` - MQTT sketches
- `Project/` - Project sketches
- `README.md` - This file

### License

MIT License
