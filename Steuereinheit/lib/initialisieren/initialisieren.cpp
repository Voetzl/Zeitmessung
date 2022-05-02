#include "initialisieren.h"
#include <avr/io.h>
#include <Arduino.h>


void einfachnurinitialisieren(){

    DDRB |= (1 << DDB5); //Output On-Board-LED

    DDRB |= (1 << DDB3); //LEDs
    DDRB |= (1 << DDB2);
    DDRB |= (1 << DDB1);
    

    DDRD &= ~(1 << DDD7); //Input Schalter
    PORTD |= (1 << PD7); //PULL-UP


    DDRD |= (1 << DDD2);  //Outputs Interrupt-Arduino
    DDRD |= (1 << DDD3);

    DDRD |= (1 << DDD5);  //Outputs Ausgabe-Arduino
    DDRD |= (1 << DDD6);

    PORTD |= (1 << RUPT_1);   //Damit PINS_RUPT am Anfang an
    PORTD |= (1 << RUPT_2);
    PORTD &= ~(1 << AUSGABE_1); //Samit PINS_AUSGABE am Anfang aus
    PORTD &= ~(1 << AUSGABE_2);

    for (int k = 0; k < 10; k++){
      PORTB |= (1 << LED_OB); //an LED
      _delay_ms(200);
      PORTB &= ~(1 << LED_OB); //aus LED
      _delay_ms(200);
    }
    for (int l = 0; l < 5; l++){

      PORTB |= (1 << PB3);
      PORTB |= (1 << PB2);
      PORTB |= (1 << PB1);
      _delay_ms(100);
      PORTB &= ~(1 << PB3);
      PORTB &= ~(1 << PB2);
      PORTB &= ~(1 << PB1);
      _delay_ms(100);
    }
}