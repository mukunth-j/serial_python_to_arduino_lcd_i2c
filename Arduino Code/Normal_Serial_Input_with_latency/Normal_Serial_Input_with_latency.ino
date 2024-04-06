#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Change the address to match your display's address

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readString();
    lcd.clear();
    lcd.print(input);

  }
}
