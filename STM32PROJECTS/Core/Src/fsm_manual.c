#include "fsm_manual.h"
#include "global.h"

int redTemp = 1;
int greenTemp = 1;
int amberTemp = 1;

void ledBalance(){
	if(red == (green + amber)) return;
	else if(red > (green + amber)){
		red = green + amber;
	}
	else{
		green = red - amber;
	}
}

void fsm_manual_run(){
	switch(status){
	case MANUAL_INIT:
		status = MANUAL_RED;
		setTimer(500, 1);		//timer for updateCounterBuffer()
		setTimer(100, 2);		//timer for update7SEG()
		setTimer(250, 3);		//timer for led blinking
		break;
	case MANUAL_RED:
		if(timer_flag[1] == 1){
			updateCounterBuffer(redTemp, 2);
			setTimer(500, 1);
		}
		if(timer_flag[2] == 1){
			setTimer(100, 2);
			update7SEG(index_led);
			index_led++;
			if(index_led >= MAX_LED){index_led = 0;}
		}
		if(timer_flag[3] == 1){
			toggleRedLED();
			setTimer(250, 3);
		}
		if(isBTPressed(0) == 1){
			status = MANUAL_AMBER;
			setTimer(250, 2);
			clearTrafficLights();
		}
		if(isBTPressed(1) == 1){
			redTemp++;
			if(redTemp > 99) redTemp = 1;
		}
		if(isBTPressed(2) == 1){
			red = redTemp;
		}
		break;
	case MANUAL_GREEN:
		if(timer_flag[1] == 1){
			updateCounterBuffer(greenTemp, 4);
			setTimer(500, 1);
		}
		if(timer_flag[2] == 1){
			setTimer(100, 2);
			update7SEG(index_led);
			index_led++;
			if(index_led >= MAX_LED){index_led = 0;}
		}
		if(timer_flag[3] == 1){
			toggleGreenLED();
			setTimer(250, 3);
		}
		if(isBTPressed(0) == 1){
			ledBalance();
			clearTrafficLights();
			status = INIT;
		}
		if(isBTPressed(1) == 1){
			greenTemp++;
			if(greenTemp > 99) greenTemp = 1;
		}
		if(isBTPressed(2) == 1){
			green = greenTemp;
		}
		break;
	case MANUAL_AMBER:
		if(timer_flag[1] == 1){
			updateCounterBuffer(amberTemp, 3);
			setTimer(500, 1);
		}
		if(timer_flag[2] == 1){
			setTimer(100, 2);
			update7SEG(index_led);
			index_led++;
			if(index_led >= MAX_LED){index_led = 0;}
		}
		if(timer_flag[3] == 1){
			toggleAmberLED();
			setTimer(250, 3);
		}
		if(isBTPressed(0) == 1){
			status = MANUAL_GREEN;
			setTimer(250, 2);
			clearTrafficLights();
		}
		if(isBTPressed(1) == 1){
			amberTemp++;
			if(amberTemp > 99) amberTemp = 1;
		}
		if(isBTPressed(2) == 1){
			amber = amberTemp;
		}
		break;
	default:
		break;
	}
}
