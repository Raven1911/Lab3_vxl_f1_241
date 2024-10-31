/*
 * main_fsm_run.c
 *
 *  Created on: Nov 1, 2024
 *      Author: Admin
 */
#include "main_fsm_run.h"



void main_fsm_run(){
	switch (button0_value) {
		case AUTOMATiC:
			fsm_automatic();
			//four_Led7Seg_display();
			break;
		case MANUAL:

			break;
		case SETTING_0:

			break;
		case SETTING_1:

			break;
		case SETTING_2:

			break;
		default:
			break;
	}
}
