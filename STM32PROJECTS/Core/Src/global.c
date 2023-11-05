#include "global.h"

int status;
int red = 5;
int green = 4;
int amber = 3;
const int MAX_LED = 4;
int led_buffer[4] = {0, 0, 0, 0};

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
		display7SEG(led_buffer[index]);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		break;
	case 1:
		display7SEG(led_buffer[index]);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		break;
	case 2:
		display7SEG(led_buffer[index]);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN2_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN3_Pin, GPIO_PIN_SET);
		break;
	case 3:
		display7SEG(led_buffer[index]);
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN3_Pin, GPIO_PIN_RESET);
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
