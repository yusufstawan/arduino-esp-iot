/*********************************
 * ESP32 I2C LCD
 * Board  : ESP32 Dev Module
 * Output : LCD 16x2
 * SDA    : D21 (GPIO 21
 * SCL    : D22 (GPIO 22)
 *********************************/

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Setting Alamat I2C LCD dan ukuran LCD

void setup()
{
  lcd.init();
  lcd.clear();
  lcd.backlight();

  lcd.setCursor(2, 0); // Set cursor to character 2 on line 0
  lcd.print("Hello World!");

  lcd.setCursor(2, 1); // Move cursor to character 2 on line 1
  lcd.print("Use I2C LCD");
}

void loop()
{
  for (int i = 0; i < 16; i++)
  {
    lcd.scrollDisplayLeft();
    delay(500);
  }
  delay(1000);
  for (int i = 0; i < 16; i++)
  {
    lcd.scrollDisplayRight();
    delay(500);
  }
  delay(1000);
}
