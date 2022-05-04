#include <avr\io.h>
#include "initialisation.h"
#include <Arduino.h>

//Benutzersteuerung: Zwei Schalter mit vier Zuständen, nc (da Arduino nur Pull-Up)

void input_received(){ //Zeitverzögerung, sobald Befehl an Steuereinheit gesendet wurde

    _delay_ms(1500);
}

void pin_reset(){

    //LED resetten
    PORTB &= ~(1 << LED_R);
    PORTB &= ~(1 << LED_G);
    PORTB &= ~(1 << LED_B);  
    //PORT's resetten
    PORTD &= ~(1 << BtoS_1);
    PORTD &= ~(1 << BtoS_2);  
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
            PORTD |= (1 << BtoS_1);
            input_received();          
        }
        else if (PIND & (1 << TASTER_2)){
            PORTB |= (1 << LED_B);
            PORTD |= (1 << BtoS_1);
            input_received();
        }
        else {
            PORTB |= (1 << LED_R);
            PORTB |= (1 << LED_B);
        }

        pin_reset();
   
    }
    

}