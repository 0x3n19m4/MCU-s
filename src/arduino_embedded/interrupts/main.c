// comparison of delay and interruption

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/* --- delay --- */
int main(void)
{
  DDRB |= (1 << DDB5) | (1 << DDB4);
  DDRD &= ~((1 << DDD2) | (1 << DDD3));
  PORTD |= (1 << PORTD2) | (1 << PORTD3);

  while (1)
  {
    PORTB ^= (1 << PORTB5);
    _delay_ms(1000);

    if (!(PIND & (1 << PIND2)))
      PORTB |= (1 << PORTB4);

    if (!(PIND & (1 << PIND3)))
      PORTB &= ~(1 << PORTB4);
  }
}
