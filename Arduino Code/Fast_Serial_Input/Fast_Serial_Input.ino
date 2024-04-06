#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
String stringa;
const unsigned long TimeOut = 10; 
String stringa1;
String stringa2;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  stringa = "";
  unsigned long T = 0; 
  T = millis(); 
  while (millis() - T < TimeOut) {
    while (Serial.available() > 0) {
      stringa += char(Serial.read()); 
      T = millis(); 
      lcd.clear();
    }
  }
    stringa1 = stringa.substring(0 , 16);
    stringa2 = stringa.substring(16);
    lcd.setCursor(0, 0);
    lcd.print(stringa1);
    lcd.setCursor(0, 1);
    lcd.print(stringa2);
}
