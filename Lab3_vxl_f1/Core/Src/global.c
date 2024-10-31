/*
 * global.c
 *
 *  Created on: Oct 29, 2024
 *      Author: Admin
 */
#include "global.h"


//value 3 button
uint16_t button0_value = 0;
uint16_t button1_value = 0;
uint16_t button2_value = 0;

///value 7 segment
uint16_t value_7seg_red_0 = 15;
uint16_t value_7seg_red_01 = 15;
uint16_t value_7seg_red_02 = 15;
uint16_t value_7seg_yellow_0 = 5;
uint16_t value_7seg_green_0 = 10;






///////////////CONFIG LED 7 SEGMENT
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

void System_scan_value_led_init(){
	Led7Seg_int(Led_7Seg_Array);
	timer_init();

	update_value_7segment();
	//Data buffer	//Scan_led
	setTimer(0, 50);
	//timer step 1s for 7 segment
	setTimer(1, 1000);

}
