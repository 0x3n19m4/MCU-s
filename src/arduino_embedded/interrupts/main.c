// comparison of delay and interruption

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/* --- delay --- */
/*
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
*/

volatile uint32_t ticks = 0;

void timer_init(void)
{
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS11) | (1 << CS10);

  OCR1A = 249;
  TIMSK1 |= (1 << OCIE1A);
}

ISR(TIMER1_COMPA_vect)
{
  ticks++;
}

/* -- interruption -- */
int main(void)
{
  DDRB |= (1 << DDB5) | (1 << DDB4);
  DDRD &= ~((1 << DDD2) | (1 << DDD3));
  PORTD |= (1 << PORTD2) | (1 << PORTD3); // pull-up

  timer_init();
  sei();

  uint32_t last_tick = 0;

  while (1)
  {
    if (ticks - last_tick >= 1000)
    {
      PORTB ^= (1 << PORTB5);
      last_tick = ticks;
    }

    if (!(PIND & (1 << PIND2)))
      PORTB |= (1 << PORTB4);

    if (!(PIND & (1 << PIND3)))
      PORTB &= ~(1 << PORTB4);
  }
}
