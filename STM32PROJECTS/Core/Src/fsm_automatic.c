#include "fsm_automatic.h"

void fsm_automatic_run(){
	switch(status){
	case INIT:
		clearTrafficLights();
		status = AUTO_RED;
		setTimer(5000, 0);
		break;
	case AUTO_RED:
		HAL_GPIO_WritePin(GPIOA, LED_RED0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_AMBER0_Pin, GPIO_PIN_SET);
		if(timer_flag[0] == 1){
			status = AUTO_GREEN;
			setTimer(3000, 0);
		}
		break;
	case AUTO_GREEN:
		HAL_GPIO_WritePin(GPIOA, LED_RED0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOA, LED_AMBER0_Pin, GPIO_PIN_SET);
		if(timer_flag[0] == 1){
			status = AUTO_AMBER;
			setTimer(2000, 0);
		}
		break;
	case AUTO_AMBER:
		HAL_GPIO_WritePin(GPIOA, LED_RED0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_GREEN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOA, LED_AMBER0_Pin, GPIO_PIN_RESET);
		if(timer_flag[0] == 1){
			status = AUTO_RED;
			setTimer(5000, 0);
		}
		break;
	default:
		break;
	}
}

