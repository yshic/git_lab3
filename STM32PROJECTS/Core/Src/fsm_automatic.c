#include "fsm_automatic.h"
#include "global.h"

int counter1 = 0;
int counter2 = 0;

void fsm_automatic_run(){
	switch(status){
	case INIT:
		status = AUTO_RED;
		setTimer( (red - amber) * 1000, 0); //timer for traffic light
		setTimer(500, 1);					//timer for updateCounterBuffer
		setTimer(100, 2);					//timer for update7SEG
		setTimer(1000, 3);					//timer for counter1, counter2 decrement
		counter1 = red;
		counter2 = green;
		break;
	case AUTO_RED:
		controlTrafficLights(0, RED);
		controlTrafficLights(1, GREEN);
		if(timer_flag[0] == 1){
			status = AUTO_RED1_AMBER2;
			counter2 = amber;
			setTimer(amber * 1000, 0);
		}
		if(timer_flag[1] == 1){
			updateCounterBuffer(counter1, counter2);
			setTimer(500, 1);
		}
		if(timer_flag[2] == 1){
			setTimer(100, 2);
			update7SEG(index_led);
			index_led++;
			if(index_led >= MAX_LED){index_led = 0;}
		}
		if(timer_flag[3] == 1){
			counter1--;
			counter2--;
			setTimer(1000, 3);
		}
		if(isBTPressed(0) == 1){
			status = MANUAL_INIT;
			clearTrafficLights();
		}
		break;
	case AUTO_GREEN:
		controlTrafficLights(0, GREEN);
		controlTrafficLights(1, RED);
		if(timer_flag[0] == 1){
			counter1 = amber;
			status = AUTO_AMBER;
			setTimer(amber * 1000, 0);
		}
		if(timer_flag[1] == 1){
			updateCounterBuffer(counter1, counter2);
			setTimer(500, 1);
		}
		if(timer_flag[2] == 1){
			setTimer(100, 2);
			update7SEG(index_led);
			index_led++;
			if(index_led >= MAX_LED){index_led = 0;}
		}
		if(timer_flag[3] == 1){
			counter1--;
			counter2--;
			setTimer(1000, 3);
		}
		if(isBTPressed(0) == 1){
			status = MANUAL_INIT;
			clearTrafficLights();
		}
		break;
	case AUTO_AMBER:
		controlTrafficLights(0, AMBER);
		controlTrafficLights(1, RED);
		if(timer_flag[0] == 1){
			counter1 = red;
			counter2 = green;
			status = AUTO_RED;
			setTimer((red - amber) * 1000, 0);
		}
		if(timer_flag[1] == 1){
			updateCounterBuffer(counter1, counter2);
			setTimer(500, 1);
		}
		if(timer_flag[2] == 1){
			setTimer(100, 2);
			update7SEG(index_led);
			index_led++;
			if(index_led >= MAX_LED){index_led = 0;}
		}
		if(timer_flag[3] == 1){
			counter1--;
			counter2--;
			if (counter1 == 0) counter1 = red;
			if (counter2 == 0) counter2 = green;
			setTimer(1000, 3);
		}
		if(isBTPressed(0) == 1){
			status = MANUAL_INIT;
			clearTrafficLights();
		}
		break;
	case AUTO_RED1_AMBER2:
		controlTrafficLights(0, RED);
		controlTrafficLights(1, AMBER);
		if(timer_flag[0] == 1){
			counter1 = green;
			counter2 = red;
			status = AUTO_GREEN;
			setTimer(green * 1000, 0);
		}
		if(timer_flag[1] == 1){
			updateCounterBuffer(counter1, counter2);
			setTimer(500, 1);
		}
		if(timer_flag[2] == 1){
			setTimer(100, 2);
			update7SEG(index_led);
			index_led++;
			if(index_led >= MAX_LED){index_led = 0;}
		}
		if(timer_flag[3] == 1){
			counter1--;
			counter2--;
			setTimer(1000, 3);
		}
		if(isBTPressed(0) == 1){
			status = MANUAL_INIT;
			clearTrafficLights();
		}
		break;
	default:
		break;
	}
}

