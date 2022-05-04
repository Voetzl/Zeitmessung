#include <avr\io.h>
#include <Arduino.h>
#include "initialisation.h"

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

    //Initialiserung der Benutzerschnittstelle

    //LED
    //Pin-Config
    DDRB |= (1 << LED_R); 
    DDRB |= (1 << LED_G);
    DDRB |= (1 << LED_B);
    led_test();

    //Taster-Input
    DDRB &= ~(1 << TASTER_1);
    DDRB &= ~(1 << TASTER_2);
    //Pull-Up
    PORTD |= (1 << TASTER_1);
    PORTD |= (1 << TASTER_2);

    //Output-Ports to Arduinos
    //Steuereinheit
    DDRB |= (1 << BtoS_1); 
    DDRB |= (1 << BtoS_2);
    //Standard: HIGH
    PORTD |= (1 << BtoS_1);
    PORTD |= (1 << BtoS_2); 

}