/*
 * traffic_light.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Admin
 */
#include "traffic_light.h"

//decoder_Led(0, 1, 1, 1, 1, 0); state 0
//decoder_Led(0, 1, 1, 1, 0, 1); state 1
//decoder_Led(1, 1, 0, 0, 1, 1); state 2
//decoder_Led(1, 0, 1, 0, 1, 1); state 3
void decoder_Led(int index){
	switch (index) {
		// method 1
		case 0:
			//traffic light 1
			HAL_GPIO_WritePin(Led_Red_GPIO_Port, Led_Red_Pin, 0);
			HAL_GPIO_WritePin(Led_Yellow_GPIO_Port, Led_Yellow_Pin, 1);
			HAL_GPIO_WritePin(Led_Green_GPIO_Port, Led_Green_Pin, 1);

			//traffic light 2
			HAL_GPIO_WritePin(Led_Red2_GPIO_Port, Led_Red2_Pin, 1);
			HAL_GPIO_WritePin(Led_Yellow2_GPIO_Port, Led_Yellow2_Pin, 1);
			HAL_GPIO_WritePin(Led_Green2_GPIO_Port, Led_Green2_Pin, 0);
			break;
		case 1:
			//traffic light 1
			HAL_GPIO_WritePin(Led_Red_GPIO_Port, Led_Red_Pin, 0);
			HAL_GPIO_WritePin(Led_Yellow_GPIO_Port, Led_Yellow_Pin, 1);
			HAL_GPIO_WritePin(Led_Green_GPIO_Port, Led_Green_Pin, 1);

			//traffic light 2
			HAL_GPIO_WritePin(Led_Red2_GPIO_Port, Led_Red2_Pin, 1);
			HAL_GPIO_WritePin(Led_Yellow2_GPIO_Port, Led_Yellow2_Pin, 0);
			HAL_GPIO_WritePin(Led_Green2_GPIO_Port, Led_Green2_Pin, 1);
			break;
		case 2:
			//traffic light 1
			HAL_GPIO_WritePin(Led_Red_GPIO_Port, Led_Red_Pin, 1);
			HAL_GPIO_WritePin(Led_Yellow_GPIO_Port, Led_Yellow_Pin, 1);
			HAL_GPIO_WritePin(Led_Green_GPIO_Port, Led_Green_Pin, 0);

			//traffic light 2
			HAL_GPIO_WritePin(Led_Red2_GPIO_Port, Led_Red2_Pin, 0);
			HAL_GPIO_WritePin(Led_Yellow2_GPIO_Port, Led_Yellow2_Pin, 1);
			HAL_GPIO_WritePin(Led_Green2_GPIO_Port, Led_Green2_Pin, 1);
			break;
		case 3:
			//traffic light 1
			HAL_GPIO_WritePin(Led_Red_GPIO_Port, Led_Red_Pin, 1);
			HAL_GPIO_WritePin(Led_Yellow_GPIO_Port, Led_Yellow_Pin, 0);
			HAL_GPIO_WritePin(Led_Green_GPIO_Port, Led_Green_Pin, 1);

			//traffic light 2
			HAL_GPIO_WritePin(Led_Red2_GPIO_Port, Led_Red2_Pin, 0);
			HAL_GPIO_WritePin(Led_Yellow2_GPIO_Port, Led_Yellow2_Pin, 1);
			HAL_GPIO_WritePin(Led_Green2_GPIO_Port, Led_Green2_Pin, 1);
			break;
		//////////////////////////////////// GPIO SETTING /////////////////////////////////////////
		//setting
		//setting blink red
		case 4:
			//traffic light 1
			HAL_GPIO_WritePin(Led_Red_GPIO_Port, Led_Red_Pin, 0);
			HAL_GPIO_WritePin(Led_Yellow_GPIO_Port, Led_Yellow_Pin, 1);
			HAL_GPIO_WritePin(Led_Green_GPIO_Port, Led_Green_Pin, 1);

			//traffic light 2
			HAL_GPIO_WritePin(Led_Red2_GPIO_Port, Led_Red2_Pin, 0);
			HAL_GPIO_WritePin(Led_Yellow2_GPIO_Port, Led_Yellow2_Pin, 1);
			HAL_GPIO_WritePin(Led_Green2_GPIO_Port, Led_Green2_Pin, 1);
			break;

		//setting blink yellow
		case 5:
			//traffic light 1
			HAL_GPIO_WritePin(Led_Red_GPIO_Port, Led_Red_Pin, 1);
			HAL_GPIO_WritePin(Led_Yellow_GPIO_Port, Led_Yellow_Pin, 0);
			HAL_GPIO_WritePin(Led_Green_GPIO_Port, Led_Green_Pin, 1);

			//traffic light 2
			HAL_GPIO_WritePin(Led_Red2_GPIO_Port, Led_Red2_Pin, 1);
			HAL_GPIO_WritePin(Led_Yellow2_GPIO_Port, Led_Yellow2_Pin, 0);
			HAL_GPIO_WritePin(Led_Green2_GPIO_Port, Led_Green2_Pin, 1);
			break;

		//setting blink green
		case 6:
			//traffic light 1
			HAL_GPIO_WritePin(Led_Red_GPIO_Port, Led_Red_Pin, 1);
			HAL_GPIO_WritePin(Led_Yellow_GPIO_Port, Led_Yellow_Pin, 1);
			HAL_GPIO_WritePin(Led_Green_GPIO_Port, Led_Green_Pin, 0);

			//traffic light 2
			HAL_GPIO_WritePin(Led_Red2_GPIO_Port, Led_Red2_Pin, 1);
			HAL_GPIO_WritePin(Led_Yellow2_GPIO_Port, Led_Yellow2_Pin, 1);
			HAL_GPIO_WritePin(Led_Green2_GPIO_Port, Led_Green2_Pin, 0);
			break;
		//turn off all led
		case 7:
			//traffic light 1
			HAL_GPIO_WritePin(Led_Red_GPIO_Port, Led_Red_Pin, 1);
			HAL_GPIO_WritePin(Led_Yellow_GPIO_Port, Led_Yellow_Pin, 1);
			HAL_GPIO_WritePin(Led_Green_GPIO_Port, Led_Green_Pin, 1);

			//traffic light 2
			HAL_GPIO_WritePin(Led_Red2_GPIO_Port, Led_Red2_Pin, 1);
			HAL_GPIO_WritePin(Led_Yellow2_GPIO_Port, Led_Yellow2_Pin, 1);
			HAL_GPIO_WritePin(Led_Green2_GPIO_Port, Led_Green2_Pin, 1);
			break;

		default:
			break;
	}
}


void blink_Led(int index, int index1){
	if(index1 == 1){
		switch (index) {
			//////////////////////////////////// GPIO SETTING /////////////////////////////////////////
			//setting
			//setting blink red
			case 0:
				//traffic light 1
				HAL_GPIO_WritePin(Led_Red_GPIO_Port, Led_Red_Pin, 0);
				HAL_GPIO_WritePin(Led_Yellow_GPIO_Port, Led_Yellow_Pin, 1);
				HAL_GPIO_WritePin(Led_Green_GPIO_Port, Led_Green_Pin, 1);

				//traffic light 2
				HAL_GPIO_WritePin(Led_Red2_GPIO_Port, Led_Red2_Pin, 0);
				HAL_GPIO_WritePin(Led_Yellow2_GPIO_Port, Led_Yellow2_Pin, 1);
				HAL_GPIO_WritePin(Led_Green2_GPIO_Port, Led_Green2_Pin, 1);
				break;

			//setting blink yellow
			case 1:
				//traffic light 1
				HAL_GPIO_WritePin(Led_Red_GPIO_Port, Led_Red_Pin, 1);
				HAL_GPIO_WritePin(Led_Yellow_GPIO_Port, Led_Yellow_Pin, 0);
				HAL_GPIO_WritePin(Led_Green_GPIO_Port, Led_Green_Pin, 1);

				//traffic light 2
				HAL_GPIO_WritePin(Led_Red2_GPIO_Port, Led_Red2_Pin, 1);
				HAL_GPIO_WritePin(Led_Yellow2_GPIO_Port, Led_Yellow2_Pin, 0);
				HAL_GPIO_WritePin(Led_Green2_GPIO_Port, Led_Green2_Pin, 1);
				break;

			//setting blink green
			case 2:
				//traffic light 1
				HAL_GPIO_WritePin(Led_Red_GPIO_Port, Led_Red_Pin, 1);
				HAL_GPIO_WritePin(Led_Yellow_GPIO_Port, Led_Yellow_Pin, 1);
				HAL_GPIO_WritePin(Led_Green_GPIO_Port, Led_Green_Pin, 0);

				//traffic light 2
				HAL_GPIO_WritePin(Led_Red2_GPIO_Port, Led_Red2_Pin, 1);
				HAL_GPIO_WritePin(Led_Yellow2_GPIO_Port, Led_Yellow2_Pin, 1);
				HAL_GPIO_WritePin(Led_Green2_GPIO_Port, Led_Green2_Pin, 0);
				break;
			default:
				break;
		}
	}
	else{
		//turn off all led
		//traffic light 1
		HAL_GPIO_WritePin(Led_Red_GPIO_Port, Led_Red_Pin, 1);
		HAL_GPIO_WritePin(Led_Yellow_GPIO_Port, Led_Yellow_Pin, 1);
		HAL_GPIO_WritePin(Led_Green_GPIO_Port, Led_Green_Pin, 1);

		//traffic light 2
		HAL_GPIO_WritePin(Led_Red2_GPIO_Port, Led_Red2_Pin, 1);
		HAL_GPIO_WritePin(Led_Yellow2_GPIO_Port, Led_Yellow2_Pin, 1);
		HAL_GPIO_WritePin(Led_Green2_GPIO_Port, Led_Green2_Pin, 1);
	}




}





//////////////////////////////// LED 7 SEG ////////////////////////////


unsigned Led_Pos[4] = {1, 1, 1, 1};
unsigned En_Led_Pos[4] = {0b1110, 0b1101, 0b1011, 0b0111};
unsigned Led_Buffer[4] = {0, 0, 0, 0};

uint8_t index_led = 0;
uint8_t Max_Led = 4;
uint8_t Buffer = 0;

void En_led_7_seg(){
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, Led_Pos[0]);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, Led_Pos[1]);
	HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, Led_Pos[2]);
	HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, Led_Pos[3]);
}

/////////////////// counter ///////////////////
void updateClockBuffer(uint16_t value_7seg0, uint16_t value_7seg1 ){
	Led_Buffer[0] = value_7seg0 / 10;
	Led_Buffer[1] = value_7seg0 % 10;
	Led_Buffer[2] = value_7seg1 / 10;
	Led_Buffer[3] = value_7seg1 % 10;


}

void update_value_7segment(){
	//contrans value
	//traffic 1
	value_7seg_red_0 = RED_TIME;
	value_7seg_yellow_0 = YELLOW_TIME;
	value_7seg_green_0 = GREEN_TIME;

	value_7seg_red_01 = value_7seg_red_0 - value_7seg_yellow_0;
	value_7seg_red_02 = value_7seg_red_0 - value_7seg_green_0;
	//traffic 2
	value_7seg_red2_0 = RED_TIME;
	value_7seg_yellow2_0 = YELLOW_TIME;
	value_7seg_green2_0 = GREEN_TIME;


}

/////////////////////
void update7SEG(int index){
		//DATA BUFFER
		Buffer = Led_Buffer[index];

		//scan led
		for(int i = 0; i < Max_Led; i++){
			Led_Pos[i] = (En_Led_Pos[index] >> i) & 0b1;
		}

		///////////////////////
		display7SEG(Buffer);
		En_led_7_seg();
}




void scan_led(){
	if(flag_timer[0]){
		update7SEG(index_led++);
		if(index_led > Max_Led - 1) index_led = 0;
		flag_timer[0] = 0;
	}




}




