#include "global.h"

int status = 0;
int red = 5;
int green = 3;
int amber = 2;
const int MAX_LED = 4;
int led_buffer[4] = {0, 0, 0, 0};
int index_led = 0;

void display7SEG(int num){
	// 0/RESET = ON, 1/SET = OFF
	switch(num){
	case 0:
		HAL_GPIO_WritePin(GPIOB, SEG_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_D_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_E_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_G_Pin, GPIO_PIN_SET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, SEG_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_D_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG_E_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG_F_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG_G_Pin, GPIO_PIN_SET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, SEG_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_C_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG_D_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_E_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_F_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG_G_Pin, GPIO_PIN_RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, SEG_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_D_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_E_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG_F_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG_G_Pin, GPIO_PIN_RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB, SEG_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_D_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG_E_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG_F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_G_Pin, GPIO_PIN_RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, SEG_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_B_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_D_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_E_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG_F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_G_Pin, GPIO_PIN_RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, SEG_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_B_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_D_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_E_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_G_Pin, GPIO_PIN_RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, SEG_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_D_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG_E_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG_F_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG_G_Pin, GPIO_PIN_RESET);
		break;
	case 8:
		HAL_GPIO_WritePin(GPIOB, SEG_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_D_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_E_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_G_Pin, GPIO_PIN_RESET);
		break;
	case 9:
		HAL_GPIO_WritePin(GPIOB, SEG_A_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_B_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_C_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_D_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_E_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG_F_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOB, SEG_G_Pin, GPIO_PIN_RESET);
		break;
	default: //OFF
		HAL_GPIO_WritePin(GPIOB, SEG_A_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG_B_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG_C_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG_D_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG_E_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG_F_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, SEG_G_Pin, GPIO_PIN_SET);
		break;
	}
}

void update7SEG(int index){
	switch(index){
	case 0:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		display7SEG(led_buffer[index]);
		break;
	case 1:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		display7SEG(led_buffer[index]);
		break;
	case 2:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		display7SEG(led_buffer[index]);
		break;
	case 3:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
		display7SEG(led_buffer[index]);
		break;
	default:
		break;
	}
}

void updateCounterBuffer(int counter1, int counter2){
	led_buffer[0] = counter1 / 10;
	led_buffer[1] = counter1 % 10;
	led_buffer[2] = counter2 / 10;
	led_buffer[3] = counter2 % 10;
}

void controlTrafficLights(int index, int color){
//	index = 0 -> W-E Traffic light
//  index = 1 -> N-S Traffic light
	switch(index){
	case 0:
		switch(color){
		case 0: // RED
			HAL_GPIO_WritePin(GPIOA, LED_RED0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED_AMBER0_Pin, GPIO_PIN_SET);
			break;
		case 1: // GREEN
			HAL_GPIO_WritePin(GPIOA, LED_RED0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_AMBER0_Pin, GPIO_PIN_SET);
			break;
		case 2: // AMBER
			HAL_GPIO_WritePin(GPIOA, LED_RED0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED_AMBER0_Pin, GPIO_PIN_RESET);
			break;
		default:
			break;
		}
		break;
	case 1:
		switch(color){
		case 0: // RED
			HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED_AMBER1_Pin, GPIO_PIN_SET);
			break;
		case 1: // GREEN
			HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(GPIOA, LED_GREEN1_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(GPIOA, LED_AMBER1_Pin, GPIO_PIN_SET);
			break;
		case 2: // AMBER
			HAL_GPIO_WritePin(LED_RED1_GPIO_Port, LED_RED1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_GREEN1_GPIO_Port, LED_GREEN1_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(LED_AMBER1_GPIO_Port, LED_AMBER1_Pin, GPIO_PIN_RESET);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void clearTrafficLights(){
	HAL_GPIO_WritePin(GPIOA, LED_RED0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED_GREEN0_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED_AMBER0_Pin, GPIO_PIN_SET);

	HAL_GPIO_WritePin(GPIOA, LED_RED1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED_GREEN1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, LED_AMBER1_Pin, GPIO_PIN_SET);
}
