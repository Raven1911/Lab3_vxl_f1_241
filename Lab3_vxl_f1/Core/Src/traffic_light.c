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
		default:
			break;
	}
}








//////////////////////////////// LED 7 SEG ////////////////////////////
//gpo led_7 seg
GPIO_7SEG_Config Led_7Seg_Array[7] = {
	{SEG0_0_GPIO_Port, SEG0_0_Pin},  //  a
	{SEG0_1_GPIO_Port, SEG0_1_Pin},  //  b
	{SEG0_2_GPIO_Port, SEG0_2_Pin},  //  c
	{SEG0_3_GPIO_Port, SEG0_3_Pin},  //  d
	{SEG0_4_GPIO_Port, SEG0_4_Pin},  //  e
	{SEG0_5_GPIO_Port, SEG0_5_Pin},  //  f
	{SEG0_6_GPIO_Port, SEG0_6_Pin}   //  g
};

void System_counter_init(){
	Led7Seg_int(Led_7Seg_Array);
	timer_init();

	//Data buffer	//Scan_led
	setTimer(0, 50);
	//DOT 	//DIGITAL CLOCK
	setTimer(1, 1000);

}

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
uint8_t hour = 23 , minute = 59 , second = 50;
void updateClockBuffer(){
	Led_Buffer[0] = hour / 10;
	Led_Buffer[1] = hour % 10;
	Led_Buffer[2] = minute / 10;
	Led_Buffer[3] = minute % 10;

}
void DIGITAL_CLOCK(){
	second ++;
	if ( second >= 60) {
		second = 0;
		minute ++;
	}
	if( minute >= 60) {
		minute = 0;
		hour ++;
	}
	if( hour >= 24) {
		hour = 0;
	}
	updateClockBuffer();


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





void four_Led7Seg_display(){
	if(flag_timer[0]){
		update7SEG(index_led++);
		if(index_led > Max_Led - 1) index_led = 0;
		flag_timer[0] = 0;
	}

	if(flag_timer[1]){
		DIGITAL_CLOCK();
		flag_timer[1] = 0;
	}


}







