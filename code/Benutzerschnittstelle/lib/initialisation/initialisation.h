#include <avr\io.h>

#define LED_R DDB1
#define LED_G DDB2
#define LED_B DDB3
#define TASTER_1 DDD7
#define TASTER_2 DDD6
#define BtoS_1 DDB4 //Benutzeroberfläche to Steuereinheit
#define BtoS_2 DDB5
#define INIT_DELAY 500




void initialisation();
