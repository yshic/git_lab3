#include "main.h"
#include "button.h"

uint16_t btArr[3] = {BT1_Pin, BT2_Pin, BT3_Pin};

int KeyReg0[NUM_BUTTONS] = {NORMAL_STATE};
int KeyReg1[NUM_BUTTONS] = {NORMAL_STATE};
int KeyReg2[NUM_BUTTONS] = {NORMAL_STATE};
int KeyReg3[NUM_BUTTONS] = {NORMAL_STATE};

int TimeOutForKeyPress =  500;
int BT_flag[NUM_BUTTONS] = {0};

int isBTPressed(int index){
	if (BT_flag[index] == 1){
		BT_flag[index] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index){
	//TODO
	//HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
	BT_flag[index] = 1;
}

void getKeyInput(){
	for (int i = 0; i < NUM_BUTTONS; i++){
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
		//Add your button here
		KeyReg0[i] = HAL_GPIO_ReadPin(GPIOA, btArr[i]);

		if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
			if (KeyReg2[i] != KeyReg3[i]){
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg3[i] == PRESSED_STATE){
						TimeOutForKeyPress = 500;
						subKeyProcess(i);
				}
			}else{
				TimeOutForKeyPress --;
				if (TimeOutForKeyPress == 0){
					TimeOutForKeyPress = 500;
					subKeyProcess(i);
				}
			}
		}
	}
}

