#include <avr/io.h>

#define LED_R DDB1
#define LED_G DDB2
#define LED_B DDB3
#define DATA_1 DDB4 //Daten von Benutzerschnittstelle
#define DATA_2 DDB5
#define RUPT_1 DDD2 //interrupts für Arduino-Interrupt
#define RUPT_2 DDD3
#define INIT_DELAY 500


void initialisation();

