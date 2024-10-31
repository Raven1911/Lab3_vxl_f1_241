/*
 * traffic_light.h
 *
 *  Created on: Oct 29, 2024
 *      Author: Admin
 */

#ifndef INC_TRAFFIC_LIGHT_H_
#define INC_TRAFFIC_LIGHT_H_

#include "main.h"
#include <stdint.h>
#include "Led7Seg_Display.h"
#include "software_timer.h"
#include "global.h"

void decoder_Led(int);
void update_value_7segment();
void count_down();
void scan_led();
#endif /* INC_TRAFFIC_LIGHT_H_ */
