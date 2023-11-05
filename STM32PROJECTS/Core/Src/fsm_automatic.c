#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch(status){
	case INIT:
		clearTrafficLights();
		status = AUTO_RED;
		setTimer(5000, 0);
		setTimer(3000, 1);
		break;
	case AUTO_RED:
		controlTrafficLights(0, RED);
		controlTrafficLights(1, GREEN);
		if(timer_flag[0] == 1){
			status = AUTO_GREEN;
			setTimer(3000, 0);
		}
		if(timer_flag[1] == 1){
			controlTrafficLights(1, AMBER);
		}
		break;
	case AUTO_GREEN:
		controlTrafficLights(0, GREEN);
		controlTrafficLights(1, RED);
		if(timer_flag[0] == 1){
			status = AUTO_AMBER;
			setTimer(2000, 0);
		}
		break;
	case AUTO_AMBER:
		controlTrafficLights(0, AMBER);
		controlTrafficLights(1, RED);
		if(timer_flag[0] == 1){
			status = AUTO_RED;
			setTimer(5000, 0);
		}
		break;
	default:
		break;
	}
}

