#include "button.h"

uint16_t KeyReg[MAX_BUTTON][4]; // [number button][register key]

uint16_t TimeOutForKeyPress[MAX_BUTTON];
uint16_t button_pressed[MAX_BUTTON] = {0};
uint16_t button_long_pressed[MAX_BUTTON] = {0};
uint16_t button_flag[MAX_BUTTON] = {0};

void init_button(){
    for (int i = 0; i < MAX_BUTTON; i++) {
        for (int j = 0; j < 4; j++) {
            KeyReg[i][j] = NORMAL_STATE;
        }
        TimeOutForKeyPress[i] = TIME_OUT;
    }
}
void init_gpi_button(int i) {
    switch (i) {
        case 0:
            KeyReg[i][0] = HAL_GPIO_ReadPin(BUTTON_0_GPIO_Port, BUTTON_0_Pin);
            break;
        case 1:
            KeyReg[i][0] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
            break;
        case 2:
            KeyReg[i][0] = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);
            break;
        // Thêm các nút khác nếu có
        default:
            break;
    }
}
int isButtonPressed(int number){
	if(button_flag[number] == 1){
		button_flag[number] = 0;
		return 1;
	}
	return 0;
}

int isButtonLongPressed(int number){
	if(button_long_pressed[number] == 1){
		button_long_pressed[number] = 0;
		return 1;
	}
	return 0;
}

//void subKeyProcess(){
//	//TODO
//	//HAL_GPIO_TogglePin(LED1_GPIO_Port, LED1_Pin);
//	button1_flag = 1;
//}



//// Các định nghĩa trạng thái
//#define INIT 0
//#define WAIT 1
//#define PRESSED 2
//#define HELD 3
//// Các biến toàn cục
//int state[MAX_BUTTON] = {INIT};
//void getKeyInput() {
//    for (int i = 0; i < MAX_BUTTON; i++) {
//        KeyReg[i][2] = KeyReg[i][1];
//        KeyReg[i][1] = KeyReg[i][0];
//        //adder_pin
//        init_gpi_button(i);
//        switch (state[i]) {
//            case INIT:

//				if ((KeyReg[i][1] == KeyReg[i][0]) && (KeyReg[i][1] == KeyReg[i][2])) {
//					if (KeyReg[i][2] != KeyReg[i][3]) {
//						KeyReg[i][3] = KeyReg[i][2];
//						if (KeyReg[i][3] == PRESSED_STATE) {
//							TimeOutForKeyPress[i] = TIME_OUT;
//							button_flag[i] = 1;
//							state[i] = PRESSED;
//						}
//					}
//					else {
//						state[i] = WAIT;
//					}
//				}
//
//
//                break;
//            case WAIT:

//				TimeOutForKeyPress[i]--;
//				if (TimeOutForKeyPress[i] == 0) {
//					TimeOutForKeyPress[i] = TIME_OUT;
//					if (KeyReg[i][3] == PRESSED_STATE) {
//						button_long_pressed[i] = 1;
//						state[i] = HELD;
//					}
//				}
//                break;
//
//            case PRESSED:
//				if (KeyReg[i][3] == PRESSED_STATE) {
//					TimeOutForKeyPress[i]--;
//					if (TimeOutForKeyPress[i] == 0) {
//						button_flag[i] = 1;
//						state[i] = HELD;
//					}
//				}
//				else {
//					state[i] = WAIT;
//				}
//

//                break;
//
//            case HELD:
//                if (KeyReg[i][3] != PRESSED_STATE) {
//                    state[i] = INIT;
//                } else {
//                    TimeOutForKeyPress[i] = TIME_OUT;
//                }
//                break;
//
//            default:
//                state[i] = INIT;
//                break;
//        }
//    }
//
//}



void getKeyInput() {
    for (int i = 0; i < MAX_BUTTON; i++) {
        KeyReg[i][2] = KeyReg[i][1];
        KeyReg[i][1] = KeyReg[i][0];
    }
    // Cập nhật trạng thái từ nút nhấn cho từng nút
    for (int i = 0; i < MAX_BUTTON; i++) {
        init_gpi_button(i);
        // Kiểm tra trạng thái debounce
        if ((KeyReg[i][1] == KeyReg[i][0]) && (KeyReg[i][1] == KeyReg[i][2])) {
            if (KeyReg[i][2] != KeyReg[i][3]) {
                KeyReg[i][3] = KeyReg[i][2];
                if (KeyReg[i][3] == PRESSED_STATE) {
                    TimeOutForKeyPress[i] = TIME_OUT;
                    button_flag[i] = 1;
                }
            } else {
                // Giảm TimeOutForKeyPress và kiểm tra nhấn giữ
                TimeOutForKeyPress[i]--;
                if (TimeOutForKeyPress[i] == 0) {
                    TimeOutForKeyPress[i] = TIME_OUT;
                    if (KeyReg[i][3] == PRESSED_STATE) {
                        button_long_pressed[i] = 1;
                    }
                }
            }
        }
    }
}
