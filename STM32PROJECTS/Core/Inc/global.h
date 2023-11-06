#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "software_timer.h"
#include "button.h"

#define INIT 				1
#define AUTO_RED			2
#define AUTO_GREEN 			3
#define AUTO_AMBER 			4
#define AUTO_RED1_AMBER2 	5
#define MANUAL_INIT			6
#define MANUAL_RED			7
#define MANUAL_GREEN		8
#define MANUAL_AMBER		9
#define RED 				0
#define GREEN				1
#define AMBER				2

extern int status;
extern const int MAX_LED;
extern int red;
extern int green;
extern int amber;
extern int led_buffer[4];
extern int index_led;

//7segment
void display7SEG(int);
void update7SEG (int);
void updateCounterBuffer(int, int);

//Traffic lights
void clearTrafficLights();
void controlTrafficLights(int, int);

//LEDS
void toggleRedLED();
void toggleGreenLED();
void toggleAmberLED();
#endif /* INC_GLOBAL_H_ */
