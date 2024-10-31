/*
 * global.h
 *
 *  Created on: Oct 29, 2024
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_


#include <stdint.h>
#include "main.h"
#include "Led7Seg_Display.h"
#include "software_timer.h"


#define AUTOMATiC 0
#define MANUAL 1
#define SETTING_0 2
#define SETTING_1 3
#define SETTING_2 4

///button
extern uint16_t button0_value;
extern uint16_t button1_value;
extern uint16_t button2_value;



#define RED_TIME 15
#define YELLOW_TIME 5
#define GREEN_TIME 10

//value 7 segment
extern uint16_t value_7seg_red_0;
extern uint16_t value_7seg_red_01;
extern uint16_t value_7seg_red_02;
extern uint16_t value_7seg_yellow_0;
extern uint16_t value_7seg_green_0;


void System_scan_value_led_init();

#endif /* INC_GLOBAL_H_ */
