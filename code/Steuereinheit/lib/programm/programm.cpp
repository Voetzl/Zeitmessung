#include <avr\io.h>
#include "initialisation.h"
#include <util/delay.h>

//Altes Fragment: Rupt-Auslösung durch Taster-Drücker
/*void derrest(){
    int i = 1;
        while(i == 1){
        PORTB |= (1 << LED_R); //rote LED: Noch nicht gestartet!
        if(PIND & (1<<SCHALT)){
            PORTD &= ~(1 << RUPT_1); 
            PORTD |= (1 << AUSGABE_1);
            PORTB |= (1 << LED_OB); 
            PORTB &= ~(1 << LED_R); 
            PORTB |= (1 << LED_G); //Grüne LED: Läuft!
            i = 2;
        }
        }

        _delay_ms(500);
        PORTB &= ~(1 << PB5); //aus LED

        while(i == 2){
        if(PIND & (1<<SCHALT)){
            PORTD &= ~(1 << RUPT_2); 
            PORTD |= (1 << AUSGABE_2);
            PORTB |= (1 << LED_OB); 
            PORTB &= ~(1 << LED_G);
            PORTB |= (1 << LED_B); //Blaue LED: Beendet
            i = 3;
        }
        }

        _delay_ms(500); //Wartezeit Boot-Up
}*/
