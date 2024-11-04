/*
 * fsm_manual.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Admin
 */

#include "fsm_manual.h"

uint8_t manual_led_0 = 0;
uint8_t manual_led_1 = 0;
void fsm_manual(){
	if(isButtonPressed(1)){
		manual_led_0++;
		if(manual_led_0>2) manual_led_0 = 0;
	}
	if(isButtonLongPressed(1)){
		manual_led_1++;
		if(manual_led_1>2) manual_led_1 = 0;
	}

	manual_led(manual_led_0, manual_led_1);
	updateClockBuffer(0, 0);
	scan_led();

}
