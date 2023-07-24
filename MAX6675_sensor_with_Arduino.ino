#include <Wire.h>
#include <max6675.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows
#define CLK 13
#define CS 10
#define DO 12
MAX6675 thermocouple(CLK, CS, DO);
void setup() {
  Serial.begin(9600);
  
  Serial.println("MAX6675 Test");
  lcd.init(); // initialize the lcd
  lcd.backlight();

}

void loop() {
  double celsius = thermocouple.readCelsius();
  if (isnan(celsius)) {
    Serial.println("Error reading thermocouple data.");
  } else {
    Serial.print("Temperature: ");
    Serial.print(celsius);
    Serial.println(" °C");
    lcd.clear();                 // clear display
  lcd.setCursor(0, 0);         // move cursor to   (0, 0)
  lcd.print("TEMPERATURE");
  lcd.setCursor(4,1);  
  
    lcd.print(celsius);
    
  delay(3000);
  }
  
}
