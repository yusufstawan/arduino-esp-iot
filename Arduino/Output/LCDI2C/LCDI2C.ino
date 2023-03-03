/*********************************
 * Arduino Uno I2C LCD
 * Board  : Arduino Uno
 * Output : LCD 16x2
 * SDA    : A4
 * SCL    : A5
 *********************************/

#include <Wire.h>              // Library komunikasi I2C
#include <LiquidCrystal_I2C.h> // Library modul I2C LCD

// default address 0x27
// tipe LCD 16x2 (16,2)
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2);

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
