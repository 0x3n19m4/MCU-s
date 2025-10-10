void transmit()
{
  while (1)
  {
    delay(3000);
    
    Serial.print(1);
    digitalWrite(2, HIGH);
    
    delay(3000);

    digitalWrite(2, LOW);
    Serial.print(2); 
  }
}

void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  transmit();
}
