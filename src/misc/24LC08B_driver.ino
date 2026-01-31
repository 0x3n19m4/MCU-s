#include <Wire.h>

#define EEPROM_ADDR 0x50

void setup() {
    Wire.begin();
    Serial.begin(9600);

    byte byte2write = 0xAB;

    EEPROM_write_byte(0x10, byte2write);
    byte value = EEPROM_read_byte(0x10);

    Serial.print("Readed: 0x");
    Serial.println(value, HEX);
}

void loop() {}

void EEPROM_write_byte(uint16_t addr, byte data)
{
    Wire.beginTransmission(EEPROM_ADDR);
    Wire.write((byte)addr);
    Wire.write(data);
    Wire.endTransmission();

    Serial.print("Writed: ");
    Serial.println(data, HEX);
    delay(5);
}

byte EEPROM_read_byte(uint16_t addr)
{
    Wire.beginTransmission(EEPROM_ADDR);
    Wire.write((byte)addr);
    Wire.endTransmission();

    Wire.requestFrom(EEPROM_ADDR, 1);
    return Wire.read();
}
