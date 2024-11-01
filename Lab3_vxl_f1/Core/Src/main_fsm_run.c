/*
 * main_fsm_run.c
 *
 *  Created on: Nov 1, 2024
 *      Author: Admin
 */
#include "main_fsm_run.h"

void change_method(){
	///button0
	if(isButtonPressed(0)){
		button0_value++;
	}
	if(button0_value > MAX_METHOD - 1){
		button0_value = 0;
	}
	///button1
	if(isButtonPressed(1)){
		button1_value++;
	}
	///button2
	if(isButtonPressed(2)){
		update_led_time();
		button0_value = 0;
	}

}

void main_fsm_run(){
	change_method();
	switch (button0_value) {
		case AUTOMATiC:
			fsm_automatic();
			break;
		case MANUAL:

			break;
		case SETTING_0:
			fsm_setting(SETTING_0);
			break;
		case SETTING_1:
			fsm_setting(SETTING_1);
			break;
		case SETTING_2:
			fsm_setting(SETTING_2);
			break;
		default:
			break;
	}
}
