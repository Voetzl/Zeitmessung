#include "calculation.h"
#include <util\delay.h>
#include <Arduino.h>



int fakultaet(int x) {
	if(x > 1) {
		return x * fakultaet(x-1);
	}else {
		return 1;
	}
}

double calc_pid(){
   
   double sum=3,n = 2, sign=1;  

   for(int i = 0; i < 100; i ++){
       
       sum += sign*(4/((n)*(n+1)*(n+2)));
       sign *= -1;
       n += 2;
   }
   return sum;

}

float calc_pif(){
   
   float sum=3,n = 2, sign=1;  

   for(int i = 0; i < 100; i ++){
       
       sum += sign*(4/((n)*(n+1)*(n+2)));
       sign *= -1;
       n += 2;
   }
   return sum;

}


void float_calc(){
    _delay_ms(1000);
    float res;
    for(int i = 0; i< 100; i++){
       res = calc_pif();
    }
    Serial.println(res);
    Serial.flush();
}

void double_calc(){
    _delay_ms(2000);
    double res;
    for(int i = 0; i< 100; i++){
       res = calc_pid();
    }
    Serial.println(res);
    Serial.flush();
}