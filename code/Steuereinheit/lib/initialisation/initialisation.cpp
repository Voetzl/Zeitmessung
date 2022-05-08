#include "initialisation.h"
#include <avr/io.h>
#include <Arduino.h>

void led_test(){
    _delay_ms(INIT_DELAY);
    PORTB |= (1 << LED_R);
    _delay_ms(INIT_DELAY);
    PORTB &= ~(1 << LED_R);
    PORTB |= (1 << LED_G);
    _delay_ms(INIT_DELAY);
    PORTB &= ~(1 << LED_G);
    PORTB |= (1 << LED_B);
    _delay_ms(INIT_DELAY);
    PORTB &= ~(1 << LED_B);
    _delay_ms(INIT_DELAY);
}

void initialisation(){

    DDRB |= (1 << DDB3); //LEDs
    DDRB |= (1 << DDB2);
    DDRB |= (1 << DDB1);
    

    DDRD |= (1 << RUPT_0);  //Outputs Interrupt-Arduino
    DDRD |= (1 << RUPT_1);
    PORTD |= (1 << RUPT_0);   //Damit PINS_RUPT am Anfang an
    PORTD |= (1 << RUPT_1);


    DDRB &= ~(1 << DATA_1); //Inputs Benutzerschnittstelle
    DDRB &= ~(1 << DATA_2);
    PORTB |= (1 << DATA_1); //Pull up!!
    PORTB |= (1 << DATA_2);



    led_test();
}