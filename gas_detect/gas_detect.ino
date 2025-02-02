#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define GAS_PIN A0  // Define the pin to which the gas sensor is connected.
#define THRESHOLD 450// Define the threshold value above which gas leakage is detected.
#define LED_PIN D0  // Define the pin to which the LED is connected.

LiquidCrystal_I2C lcd(0x27,16,2);  // Set the LCD address to 0x27 for a 16 chars and 2 line display.

void setup() {
  Serial.begin(9600);  // Initialize serial communication.
  pinMode(LED_PIN, OUTPUT);  // Set the LED pin as output.
  lcd.init();  // Initialize the LCD.
  lcd.backlight();  // Turn on the backlight.
  lcd.setCursor(0,0);
  lcd.print("Gas Leakage");
  lcd.setCursor(0,1);
  lcd.print("Detector");
  delay(2000);
}

void loop() {
  int gasLevel = analogRead(GAS_PIN);  // Read the gas sensor value.
  Serial.print("Gas Level: ");
  Serial.println(gasLevel);
  if (gasLevel > THRESHOLD) {
    // Gas leakage detected.
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Gas Leakage!");
    lcd.setCursor(0,1);
    lcd.print("Evacuate!");
    digitalWrite(LED_PIN, HIGH);  // Turn on the LED.
  }
  else {
    // No gas leakage.
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Gas Level:");
    lcd.setCursor(0,1);
    lcd.print(gasLevel);
    digitalWrite(LED_PIN, LOW);  // Turn off the LED.
  }
  delay(1000);
}