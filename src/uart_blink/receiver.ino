// esp32

void receive()
{
  if (Serial.available())
  {
    int data = Serial.parseInt();
    if (data == 1)
    {
      digitalWrite(2, HIGH);
      Serial.println("LED ON");
    }
    else
    {
      digitalWrite(2, LOW);
      Serial.println("LED OFF");  
    }
  }
}

void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  receive();
}
