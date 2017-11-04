#ifndef __KEYBOARD_CONFIG_H
#define __KEYBOARD_CONFIG_H

#include "stm32f1xx_hal.h"

/*
 *
 */
#define AZERTY

/*
 * Do not edit this include
 */
#include "keyboard_misc.h"


/*
 * Set number of rows and columns
 */
#define MATRIX_ROW 8
#define MATRIX_COL 19

/*
 * Matrix and GPIO assignment
 */
// ROWS
#define ROWS_GPIO_INIT {\
	/*ROW 0 */ { .gpio_port = GPIOA, .gpio_pin = GPIO_PIN_0 },\
	/*ROW 1 */ { .gpio_port = GPIOA, .gpio_pin = GPIO_PIN_1 },\
	/*ROW 2 */ { .gpio_port = GPIOA, .gpio_pin = GPIO_PIN_2 },\
	/*ROW 3 */ { .gpio_port = GPIOA, .gpio_pin = GPIO_PIN_3 },\
	/*ROW 4 */ { .gpio_port = GPIOA, .gpio_pin = GPIO_PIN_4 },\
	/*ROW 5 */ { .gpio_port = GPIOA, .gpio_pin = GPIO_PIN_5 },\
	/*ROW 6 */ { .gpio_port = GPIOA, .gpio_pin = GPIO_PIN_6 },\
	/*ROW 7 */ { .gpio_port = GPIOA, .gpio_pin = GPIO_PIN_7 } \
}
// COLS
#define COLS_GPIO_INIT {\
	/*COL 0  */ { .gpio_port = GPIOB, .gpio_pin = GPIO_PIN_8  },\
	/*COL 1  */ { .gpio_port = GPIOB, .gpio_pin = GPIO_PIN_7  },\
	/*COL 2  */ { .gpio_port = GPIOB, .gpio_pin = GPIO_PIN_6  },\
	/*COL 3  */ { .gpio_port = GPIOB, .gpio_pin = GPIO_PIN_5  },\
	/*COL 4  */ { .gpio_port = GPIOB, .gpio_pin = GPIO_PIN_4  },\
	/*COL 5  */ { .gpio_port = GPIOB, .gpio_pin = GPIO_PIN_3  },\
	/*COL 6  */ { .gpio_port = GPIOA, .gpio_pin = GPIO_PIN_15 },\
	/*COL 7  */ { .gpio_port = GPIOB, .gpio_pin = GPIO_PIN_9  },\
	/*COL 8  */ { .gpio_port = GPIOB, .gpio_pin = GPIO_PIN_0  },\
	/*COL 9  */ { .gpio_port = GPIOA, .gpio_pin = GPIO_PIN_10 },\
	/*COL 10 */ { .gpio_port = GPIOA, .gpio_pin = GPIO_PIN_9  },\
	/*COL 11 */ { .gpio_port = GPIOA, .gpio_pin = GPIO_PIN_8  },\
	/*COL 12 */ { .gpio_port = GPIOB, .gpio_pin = GPIO_PIN_15 },\
	/*COL 13 */ { .gpio_port = GPIOB, .gpio_pin = GPIO_PIN_14 },\
	/*COL 14 */ { .gpio_port = GPIOB, .gpio_pin = GPIO_PIN_13 },\
	/*COL 15 */ { .gpio_port = GPIOB, .gpio_pin = GPIO_PIN_12 },\
	/*COL 16 */ { .gpio_port = GPIOB, .gpio_pin = GPIO_PIN_11 },\
	/*COL 17 */ { .gpio_port = GPIOB, .gpio_pin = GPIO_PIN_10 },\
	/*COL 18 */ { .gpio_port = GPIOB, .gpio_pin = GPIO_PIN_1  } \
}

/*
 *  Matrix and key function assignment (keyboard key map)
 */
#define MATRIX_FUNCTIONS_INIT {\
	{ NO_KEY , NO_KEY , NO_KEY , KEY_Q  , KEY_D , KEY_SPE, KEY_F1 , KEY_G , KEY_J , KEY_L  , KEY_APO, KEY_ENT, NO_KEY , KEY_P4 , NO_KEY  ,NO_KEY , KEY_P6 , KEY_PDO, NO_KEY  },\
	{ NO_KEY , NO_KEY , NO_KEY , KEY_CLK, KEY_S , KEY_F2 , KEY_F3 , KEY_F , KEY_H , KEY_K  , KEY_M  , KEY_ASL, NO_KEY , NO_KEY , NO_KEY  ,NO_KEY , KEY_P5 , KEY_PEN, NO_KEY  },\
	{ NO_KEY , NO_KEY , NO_KEY , KEY_A  , KEY_E , KEY_F4 , KEY_F5 , KEY_T , KEY_U , KEY_O  , KEY_LCR, NO_KEY , KEY_END, KEY_P7 , NO_KEY  ,NO_KEY , KEY_P9 , NO_KEY , NO_KEY  },\
	{ NO_KEY , NO_KEY , NO_KEY , KEY_TAB, KEY_Z , KEY_F6 , KEY_F7 , KEY_R , KEY_Y , KEY_I  , KEY_P  , KEY_RCR, KEY_DF , KEY_PD , NO_KEY  ,NO_KEY , KEY_P8 , KEY_PPL, NO_KEY  },\
	{ NO_KEY , NO_KEY , NO_KEY , KEY_ESC, KEY_2 , KEY_F8 , KEY_F9 , KEY_4 , KEY_6 , KEY_8  , KEY_0  , KEY_EQU, KEY_BSP, KEY_HOM, NO_KEY  ,NO_KEY , KEY_PNU, KEY_PAS, NO_KEY  },\
	{ NO_KEY , NO_KEY , NO_KEY , KEY_1  , KEY_3 , KEY_F10, KEY_F11, KEY_5 , KEY_7 , KEY_9  , KEY_MIN, NO_KEY , KEY_INS, KEY_PU , NO_KEY  ,NO_KEY , KEY_PSL, KEY_PMI, NO_KEY  },\
	{ NO_KEY , NO_KEY , NO_KEY , KEY_CHV, KEY_X , KEY_F12, KEY_PS , KEY_V , KEY_N , KEY_VIR, KEY_DOT, NO_KEY , KEY_UA , KEY_P1 , NO_KEY  ,NO_KEY , KEY_P2 , NO_KEY , NO_KEY  },\
	{ KEY_LAL, KEY_LCT, KEY_LSH, KEY_W  , KEY_C , KEY_SPC, KEY_DA , KEY_B , KEY_SL, KEY_COM, KEY_SLA, KEY_LA , KEY_PAU, KEY_RA , KEY_RSH ,KEY_RGU, KEY_P3 , KEY_P0 , KEY_RAL } \
}

#endif /* __CONFIG_H */
