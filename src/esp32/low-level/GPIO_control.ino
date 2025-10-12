#define GPIO_OUT_REG 0x3FF44004

void setup() {
  pinMode(2, OUTPUT);
}

void loop() {
  *(volatile uint32_t *)GPIO_OUT_REG |= (1 << 2);
  delay(500);

  *(volatile uint32_t *)GPIO_OUT_REG &= ~(1 << 2);
  delay(500);
}
