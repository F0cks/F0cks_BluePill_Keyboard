#include "keyboard_config.h"
#include "keyboard_led.h"

gpio_table LED_GPIO_ARRAY[LED_USED] = LED_GPIO_INIT;
uint8_t LED_FUNCTION_ARRAY[LED_USED] = LED_FUNCTION_INIT;
gpio_table LED_matrix[3]; // LED_matrix[0]: Caps lock, LED_matrix[1]: Num lock, LED_matrix[2] : Scroll Lock

// Initialize GPIO used
void LED_GPIO_Init() {
	int i = 0;
	GPIO_InitTypeDef GPIO_InitStruct;

	// A C D already enable
	__HAL_RCC_GPIOB_CLK_ENABLE();

	for (i=0; i<LED_USED; i++) {
		// Set LEDs pins as output
		GPIO_InitStruct.Pin = LED_GPIO_ARRAY[i].gpio_pin;
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		HAL_GPIO_Init(LED_GPIO_ARRAY[i].gpio_port, &GPIO_InitStruct);
		HAL_GPIO_WritePin(LED_GPIO_ARRAY[i].gpio_port, LED_GPIO_ARRAY[i].gpio_pin, GPIO_PIN_RESET);
		// Generate LED matrix
		LED_matrix[ LED_FUNCTION_ARRAY[i] ] = LED_GPIO_ARRAY[i];
	}
}

void LED_update_status(uint8_t index){
	// Caps lock
	if( (index & 0b10) == 0b10 ) {
		HAL_GPIO_WritePin(LED_matrix[CAPS_LOCK].gpio_port, LED_matrix[CAPS_LOCK].gpio_pin, GPIO_PIN_SET);
	}
	else{
		HAL_GPIO_WritePin(LED_matrix[CAPS_LOCK].gpio_port, LED_matrix[CAPS_LOCK].gpio_pin, GPIO_PIN_RESET);
	}
	// Num lock
	if( (index & 0b01) == 0b01 ) {
		HAL_GPIO_WritePin(LED_matrix[NUM_LOCK].gpio_port, LED_matrix[NUM_LOCK].gpio_pin, GPIO_PIN_SET);
	}
	else{
		HAL_GPIO_WritePin(LED_matrix[NUM_LOCK].gpio_port, LED_matrix[NUM_LOCK].gpio_pin, GPIO_PIN_RESET);
	}
	// Scroll lock
	if( (index & 0b100) == 0b100 ) {
		HAL_GPIO_WritePin(LED_matrix[SCROLL_LOCK].gpio_port, LED_matrix[SCROLL_LOCK].gpio_pin, GPIO_PIN_SET);
	}
	else{
		HAL_GPIO_WritePin(LED_matrix[SCROLL_LOCK].gpio_port, LED_matrix[SCROLL_LOCK].gpio_pin, GPIO_PIN_RESET);
	}
}
