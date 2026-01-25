#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 20, 2);

const int voltage_pin = A0;
const int relay_pin = 8;

bool relay_state = false; // false = off, true = on

void setup() {
  Serial.begin(9600);

  pinMode(relay_pin, OUTPUT);

  lcd.begin();
  lcd.backlight();
}

void loop() {
  float voltage = analogRead(voltage_pin) * (5.0 / 1023.0);

  Serial.print("Voltage: ");
  Serial.println(voltage);

  out2lcd(voltage);
  delay(1000);
}

void relay_on()
{
  digitalWrite(relay_pin, HIGH);
}

void relay_off()
{
    digitalWrite(relay_pin, LOW);
}

void out2lcd(float voltage)
{
  lcd.setCursor(1, 0);
  lcd.print("Voltage: ");

  lcd.setCursor(10, 0);
  lcd.print(voltage);
}
