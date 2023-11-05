#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "software_timer.h"
#include "button.h"

#define INIT 	1
#define LED_ON	2
#define LED_OFF 3

extern int red;
extern int green;
extern int amber;
extern int int led_buffer[4];

void display7SEG(int);
void update7SEG (int);
void updateCounterBuffer(int, int);

#endif /* INC_GLOBAL_H_ */
