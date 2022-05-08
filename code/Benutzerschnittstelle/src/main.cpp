#include <avr\io.h>
#include "initialisation.h"
#include <Arduino.h>

//Benutzersteuerung: Zwei Schalter mit vier Zuständen, nc (da Arduino nur Pull-Up)

void input_received(){ //Zeitverzögerung, sobald Befehl an Steuereinheit gesendet wurde

    _delay_ms(200);
}

void pin_reset(){

    //PORT's resetten
    PORTB &= ~(1 << BtoS_1);
    PORTB &= ~(1 << BtoS_2);  
    
    //LED resetten
    PORTB &= ~(1 << LED_R);
    PORTB &= ~(1 << LED_G);
    PORTB &= ~(1 << LED_B);  
    
}


int main(void){

    initialisation();

    while(1){

        if (PIND & (1 << TASTER_2) || PIND & (1 << TASTER_1)){
            _delay_ms(100);  //In case of pressing two buttons simultaniously: Pressing them is not                     
            pin_reset(); //Not nixe here, but it has to be here, after the delay
            
            if (PIND & (1 << TASTER_2) && PIND & (1 << TASTER_1)){
                PORTB |= (1 << LED_R);
                PORTB |= (1 << BtoS_1);
                PORTB |= (1 << BtoS_2);
                input_received();
            }
            else if (PIND & (1 << TASTER_1)){
                PORTB |= (1 << LED_G);  
                PORTB |= (1 << BtoS_1);
                input_received();          
            }
            else if (PIND & (1 << TASTER_2)){
                PORTB |= (1 << LED_B);
                PORTB |= (1 << BtoS_2);
                input_received();
            }
            else{
                initialisation(); //In case of really short pressing...
            }
        }
        else {
                pin_reset(); //Not happy about this, but it has to be here again or it blinks because of the delay
                PORTB = (15); //it's white. And it's shorter.
                
        }   
    }    
}