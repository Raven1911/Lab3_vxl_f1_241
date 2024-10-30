#include "button.h"

uint16_t KeyReg[MAX_BUTTON][4]= {{NORMAL_STATE}}; // [number button][register key]

uint16_t TimeOutForKeyPress[MAX_BUTTON] =  {TIME_OUT};
uint16_t button_pressed[MAX_BUTTON] = {0};
uint16_t button_long_pressed[MAX_BUTTON] = {0};
uint16_t button_flag[MAX_BUTTON] = {0};


void init_gpi_button(){
	KeyReg[0][0] = HAL_GPIO_ReadPin(BUTTON_0_GPIO_Port, BUTTON_0_Pin);
	KeyReg[1][0] = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
	KeyReg[2][0] = HAL_GPIO_ReadPin(BUTTON_2_GPIO_Port, BUTTON_2_Pin);
//	KeyReg[3][0] = ....

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



// Các định nghĩa trạng thái
#define INIT 0
#define WAIT 1
#define PRESSED 2
#define HELD 3
// Các biến toàn cục
int state[MAX_BUTTON] = {INIT};
void getKeyInput() {
    for (int i = 0; i < MAX_BUTTON; i++) {
        KeyReg[i][2] = KeyReg[i][1];
        KeyReg[i][1] = KeyReg[i][0];
        //adder_pin
        init_gpi_button();
        switch (state[i]) {
            case INIT:
				// Kiểm tra debounce, nếu nút ổn định chuyển sang trạng thái WAIT
				if ((KeyReg[i][1] == KeyReg[i][0]) && (KeyReg[i][1] == KeyReg[i][2])) {
					if (KeyReg[i][2] != KeyReg[i][3]) {
						KeyReg[i][3] = KeyReg[i][2];
						if (KeyReg[i][3] == PRESSED_STATE) {
							TimeOutForKeyPress[i] = TIME_OUT;
							button_flag[i] = 1;  // Đánh dấu nút đã được nhấn
							state[i] = PRESSED;   // Chuyển sang trạng thái PRESSED
						}
					}
					else {
						state[i] = WAIT; // Chờ thêm để kiểm tra lại
					}
				}


                break;
            case WAIT:
				// Trạng thái chờ và giảm TimeOutForKeyPress khi nhấn giữ
				TimeOutForKeyPress[i]--;
				if (TimeOutForKeyPress[i] == 0) {
					TimeOutForKeyPress[i] = TIME_OUT;
					if (KeyReg[i][3] == PRESSED_STATE) {
						button_long_pressed[i] = 1;  // Đánh dấu nút nhấn giữ
						state[i] = HELD;      // Chuyển sang trạng thái nhấn giữ
					}
				}
                break;

            case PRESSED:
				if (KeyReg[i][3] == PRESSED_STATE) {
					TimeOutForKeyPress[i]--;
					if (TimeOutForKeyPress[i] == 0) {
						button_flag[i] = 1;
						state[i] = HELD; // Đổi sang trạng thái giữ
					}
				}
				else {
					state[i] = WAIT; // Quay về trạng thái chờ khi nhả nút
				}

				// Xử lý khi nút được nhấn lần đầu và có thể chuyển sang trạng thái HELD
                break;

            case HELD:
                // Xử lý khi nút ở trạng thái nhấn giữ
                if (KeyReg[i][3] != PRESSED_STATE) {
                    state[i] = INIT;  // Quay về trạng thái INIT khi nhả nút
                } else {
                    TimeOutForKeyPress[i] = TIME_OUT; // Giữ thời gian nhấn giữ
                }
                break;

            default:
                state[i] = INIT;
                break;
        }
    }

}


