	/*
 * fsm_setting.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Admin
 */
#include "fsm_setting.h"

int var_blink = 0;

uint16_t config_value_red = 10;
uint16_t config_value_yellow = 3;
uint16_t config_value_green = 7;

void update_led_time(){
	value_7seg_red_0 = config_value_red;
	value_7seg_yellow_0 = config_value_yellow;
	value_7seg_green_0 = config_value_green;

	value_7seg_red2_0 = config_value_red;
	value_7seg_yellow2_0 = config_value_yellow;
	value_7seg_green2_0 = config_value_green;

	value_7seg_red_01 = value_7seg_red_0 - value_7seg_yellow_0;
	value_7seg_red_02 = value_7seg_red_0 - value_7seg_green_0;
}

void fsm_setting(int index){

	switch (index) {
		case SETTING_0:
			updateClockBuffer(config_value_red, config_value_red);
			blink_Led(0, var_blink);
			if(flag_timer[2]){
				var_blink = !var_blink;
				flag_timer[2] = 0;
			}
			if(isButtonPressed(1)){
				config_value_red++;
			}
			if(isButtonLongPressed(1)){
				config_value_red--;
			}

			break;

		case SETTING_1:
			updateClockBuffer(config_value_yellow, config_value_yellow);
			blink_Led(1, var_blink);
			if(flag_timer[2]){
				var_blink = !var_blink;
				flag_timer[2] = 0;
			}

			if(isButtonPressed(1)){
				config_value_yellow++;
			}
			if(isButtonLongPressed(1)){
				config_value_yellow--;
			}

			break;

		case SETTING_2:
			updateClockBuffer(config_value_green, config_value_green);
			blink_Led(2, var_blink);
			if(flag_timer[2]){
				var_blink = !var_blink;
				flag_timer[2] = 0;
			}

			if(isButtonPressed(1)){
				config_value_green++;
			}
			if(isButtonLongPressed(1)){
				config_value_green--;
			}
			break;

		default:
			break;
	}
	scan_led();
}
