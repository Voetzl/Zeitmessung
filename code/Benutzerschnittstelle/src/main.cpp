#include <avr\io.h>
#include "initialisation.h"
#include <Arduino.h>

//Benutzersteuerung: Zwei Schalter mit vier Zuständen, nc (da Arduino nur Pull-Up)

void input_received(){ //Zeitverzögerung, sobald Befehl an Steuereinheit gesendet wurde

    _delay_ms(1500);
}


int main(void){

    initialisation();

    while(1){
        if (PIND & (1 << TASTER_2) && PIND & (1 << TASTER_1)){
            PORTB |= (1 << LED_R);
            input_received();
        }
        else if (PIND & (1 << TASTER_1)){
            PORTB |= (1 << LED_G);  
            PORTB |= (1 << BtoS_1);
            input_received();          
        }
        else if (PIND & (1 << TASTER_2)){
            PORTB |= (1 << LED_B);
            PORTB |= (1 << BtoS_1);
            input_received();
        }
        else {
            PORTB |= (1 << LED_R);
            PORTB |= (1 << LED_B);
        }

        //LED resetten
        PORTB &= ~(1 << LED_R);
        PORTB &= ~(1 << LED_G);
        PORTB &= ~(1 << LED_B);       
    }
    

}