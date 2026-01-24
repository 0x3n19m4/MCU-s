const int voltage_pin = A0;
const int relay_pin = 8;

void setup() {
  Serial.begin(9600);

  pinMode(relay_pin, OUTPUT);
}

void loop() {
  float voltage = analogRead(voltage_pin) * (5.0 / 1023.0);

  Serial.print("Voltage: ");
  Serial.println(voltage);

  if (voltage <= 11)
  {
    relay_off();
  } 
  else 
  {
    relay_on();
  }
}

void relay_on()
{
  digitalWrite(relay_pin, HIGH);
}

void relay_off()
{
    digitalWrite(relay_pin, LOW);
}
