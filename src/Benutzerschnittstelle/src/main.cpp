#include <Arduino.h>





int main(void){

    DDRB |= (1 << DDB3); //LEDs
    DDRB |= (1 << DDB2);
    DDRB |= (1 << DDB1);

int i;
for (int l = 0; l < 5; i++){

    PORTB |= (1 << PB3);
    PORTB |= (1 << PB2);
    PORTB |= (1 << PB1);
    _delay_ms(500);
    PORTB &= ~(1 << PB3);
    PORTB &= ~(1 << PB2);
    PORTB &= ~(1 << PB1);
    _delay_ms(500);
}

}