#include "initialisation.h"
#include "programm.h"
#include <util\delay.h>
#include <Arduino.h>

int main(void){

  initialisation(); //Initialisierung
  
  while(1){
    
    if(PINB & (1 << DATA_1)){
      PORTB = (1 << LED_G);
    }
    else if(PINB & (1 << DATA_2)){
      PORTB = (1 << LED_B);
    }
    else{
      PORTB = (1 << LED_R);    
    }
    

    
    
    

    //PINB &= ~(1 << LED_G);
    //PINB &= ~(1 << LED_B);
    //PINB &= ~(1 << LED_R);
    
    
    
    
    //derrest(); //Eigentliches Programm  
  }

  return 0;
}