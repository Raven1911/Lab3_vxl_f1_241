/*
 * fsm_automatic.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Admin
 */

#include "fsm_automatic.h"


/////////////////////////////////////////TRAFFIC_LIGHT////////////////////////////////////////////////////
//// 4 way traffic light
typedef enum {state_0, state_1, state_2, state_3} state;
state pre_state = state_0;
void fsm_automatic(){
	//7segment display

	//count_down();
	switch (pre_state) {
		case state_0:
			updateClockBuffer(value_7seg_red_0, value_7seg_green2_0);
			//traffic
			decoder_Led(0);

			if(flag_timer[1]){
				//traffic 1
				--value_7seg_red_01;
				--value_7seg_red_0;
				//traffic 2
				--value_7seg_green2_0;

				if(value_7seg_red_01 < 1){
					pre_state = state_1;

				}

				flag_timer[1] = 0;
			}


			break;

		case state_1:
			updateClockBuffer(value_7seg_red_0, value_7seg_yellow2_0);
			//traffic
			decoder_Led(1);
			if(flag_timer[1]){

				--value_7seg_red_02;
				--value_7seg_red_0;
				//traffic 2
				--value_7seg_yellow2_0;


				if(value_7seg_red_02 < 1){
					pre_state = state_2;
				}


				flag_timer[1] = 0;
			}

			break;

		case state_2:
			//7segment display
			updateClockBuffer(value_7seg_green_0, value_7seg_red2_0);
			//traffic
			decoder_Led(2);
			if(flag_timer[1]){

				--value_7seg_green_0;
				//traffic 2
				--value_7seg_red2_0;
				if(value_7seg_green_0 < 1){
					pre_state = state_3;
				}


				flag_timer[1] = 0;
			}

			break;

		case state_3:
			//7segment display
			updateClockBuffer(value_7seg_yellow_0, value_7seg_red2_0);
			//traffic
			decoder_Led(3);
			if(flag_timer[1]){

				--value_7seg_yellow_0;
				//traffic 2
				--value_7seg_red2_0;

				if(value_7seg_yellow_0 < 1){
					pre_state = 0;
					update_value_7segment();
				}


				flag_timer[1] = 0;
			}

			break;

		default:
			break;
	}
	scan_led();

}
