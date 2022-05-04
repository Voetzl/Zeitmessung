#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <Arduino.h>

volatile unsigned int timer_overflow_counter = 0;
volatile unsigned int timer_start = 0, timer_end = 0;

unsigned int timer_max = 0xffff;
double timer_sec = 0;

ISR(TIMER1_OVF_vect)
{
  timer_overflow_counter++;

  Serial.println("+");
  Serial.flush();
}

ISR(INT0_vect)
{
  timer_overflow_counter = 0;
  timer_start = TCNT1;

  Serial.println("INT0");
  Serial.flush();
}

ISR(INT1_vect)
{
  timer_end = TCNT1;

  Serial.println("INT1");
  Serial.flush();

  timer_sec = (double)timer_start / (double)timer_max + timer_overflow_counter + (double)timer_end / (double)timer_max;

  Serial.println(timer_overflow_counter);
  Serial.println(timer_start);
  Serial.println(timer_end);
  Serial.println(timer_sec);
  Serial.flush();

  // exit(0);
}

int main(void)
{
  Serial.begin(9600);
  Serial.println("start");
  Serial.flush();

  // setup pins
  DDRD &= ~((1 << DDD2) | (1 << DDD3));
  PORTD |= (1 << PD2) | (1 << PD3);

  // setup timer
  TCCR1A = 0; // normal mode
  TCCR1B |= (1 << CS11) | (1 << CS10); // prescaler: clk/64 (eig. komplett sinnlos)

  // setup timer interrupt
  TIMSK1 |= (1 << TOIE1);

  // setup external interrupts
  EICRA |= (1 << ISC10) | (1 << ISC00);
  EIMSK |= (1 << INT1) | (1 << INT0);

  // enable interrupts
  sei();
  _delay_ms(1000);

  // wait for interrupts
  Serial.println("wait forever");
  Serial.flush();
  for(;;){}

  Serial.println("not possible output");
  Serial.flush();

  return -1;
}


