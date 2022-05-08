#include "initialisation.h"
#include "calculation.h"
#include <util\delay.h>
#include <Arduino.h>

int main(void){

  initialisation(); //initialisation
  Serial.begin(9600);

  while(1){  

    if (PINB & (1 << DATA_1) || PINB & (1 << DATA_2)){
      _delay_ms(1);  //In case of pressing two buttons simultaniously: Pressing them is not                     

      // red, both, both
      if(PINB & (1 << DATA_1) && PINB & (1 << DATA_2)){
        PORTB = (1 << LED_R);
        PORTD ^= (1 << RUPT_0); 
        float_calc();
        double_calc();
        PORTD ^= (1 << RUPT_1);
      }
      // green, taster1, right, double
      else if(PINB & ((1 << DATA_1) & ~(1 << DATA_2))){
        PORTB = (1 << LED_G);
        PORTD ^= (1 << RUPT_0); 
        double_calc();
        PORTD ^= (1 << RUPT_1); 
      }
      // blue, taster2, left, float
      else if(PINB & (~(1 << DATA_1) & (1 << DATA_2))){
        PORTB = (1 << LED_B);
        PORTD ^= (1 << RUPT_0); 
        float_calc();
        PORTD ^= (1 << RUPT_1);
      }
    }
    else{
      PORTB = (15); //It's white. But in this case I overwrite the colours mit '=' not '|=', so this in necessary
    } 

  }
  return 0;
}