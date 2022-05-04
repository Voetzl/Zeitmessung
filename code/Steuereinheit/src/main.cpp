#include "initialisation.h"
#include "programm.h"

int main(void){

  initialisation(); //Initialisierung
  
  while(1){
    
    if(PIND & (1 << DATA_1)){
      PINB |= (1 << LED_B);
    }
    else{
      PINB |= (1 << LED_G);
    }
    

    PINB &= ~(1 << LED_G);
    PINB &= ~(1 << LED_B);
    
    
    
    
    //derrest(); //Eigentliches Programm  
  }

  return 0;
}