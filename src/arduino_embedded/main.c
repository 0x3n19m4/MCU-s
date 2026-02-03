/*
 * Author: 0x3n19m4
 * 
 * 24LC08B EEPROM driver
*/

#include <avr/io.h>
#include <util/delay.h>

// MSU is used - ATmega328P
// EEPROM chip - 24LC08B

#define F_CPU 16000000UL
#define EEPROM_ADDR 0x50
#define BYTE 0xAB
#define OUT_LED PB5

#define SUCCESS 2
#define FAULT 3

void i2c_init(void)
{
    TWSR = 0x00;
    TWBR = 72;
    TWCR = (1 << TWEN);
}

void i2c_start(void)
{
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

void i2c_stop(void)
{
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

void i2c_write(uint8_t data)
{
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);

    while (!(TWCR & (1 << TWINT)));
}

uint8_t i2c_read_nack(void)
{
    TWCR = (1 << TWINT) | (1 << TWEN); 
    while (!(TWCR & (1 << TWINT)));
    
    return TWDR;
}

void EEPROM_write_byte(uint8_t addr, uint8_t data)
{
    i2c_start();
    
    i2c_write((EEPROM_ADDR << 1) | 0);
    i2c_write(addr);
    i2c_write(data);
    
    i2c_stop();
    _delay_ms(5);
}

uint8_t EEPROM_read_byte(uint8_t addr)
{
    uint8_t data;

    i2c_start();

    i2c_write((EEPROM_ADDR << 1) | 0);
    i2c_write(addr);

    i2c_start();
    i2c_write((EEPROM_ADDR << 1) | 1);

    data = i2c_read_nack();

    i2c_stop();

    return data;
}

void blink_n(uint8_t n)
{
  for (int i = 0; i < n; i++)
  {
    PORTB |= (1 << OUT_LED);
    _delay_ms(200);

    PORTB &= ~(1 << OUT_LED);
    _delay_ms(200);
  }
}

int main(void)
{
    // DDRB |= (1 << PB5);

    // while (1)
    // {
    //     PORTB ^= (1 << PD5);
    //     _delay_ms(500);
    // }

    i2c_init();

    EEPROM_write_byte(0x10, BYTE);
    uint8_t value = EEPROM_read_byte(0x10);

    uint8_t expected = BYTE;

    if (value == expected)
        blink_n(SUCCESS);
    else
        blink_n(FAULT);

    while (1)
    {
        
    }
}

