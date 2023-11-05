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

void display7SEG(int);

#endif /* INC_GLOBAL_H_ */
