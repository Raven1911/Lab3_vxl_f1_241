/*
 * traffic_light.h
 *
 *  Created on: Oct 29, 2024
 *      Author: Admin
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "main.h"
#include "Led7Seg_Display.h"
#include "software_timer.h"

void System_counter_init();
void decoder_Led(int);
void four_Led7Seg_display();

#endif /* INC_TRAFFIC_LIGHT_H_ */
