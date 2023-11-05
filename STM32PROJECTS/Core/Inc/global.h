#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "software_timer.h"
#include "button.h"

#define INIT 		1
#define AUTO_RED	2
#define AUTO_GREEN 	3
#define AUTO_AMBER 	4
#define RED 		0
#define GREEN		1
#define AMBER		2

extern int status;
extern int red;
extern int green;
extern int amber;
extern int led_buffer[4];

//7segment
void display7SEG(int);
void update7SEG (int);
void updateCounterBuffer(int, int);

//Traffic lights
void clearTrafficLights();
void controlTrafficLights(int, int);
#endif /* INC_GLOBAL_H_ */
