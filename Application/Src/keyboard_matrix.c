#include "keyboard_matrix.h"

// ROWS
gpio_table ROWS_GPIO [MATRIX_ROW] =	ROWS_GPIO_INIT;

// COLS
gpio_table COLS_GPIO [MATRIX_COL] = COLS_GPIO_INIT;

// Matrix functions
uint8_t matrix_function [MATRIX_ROW] [MATRIX_COL] = MATRIX_FUNCTIONS_INIT;

// Initialize GPIO used
void MATRIX_GPIO_Init() {
	int i = 0;
	GPIO_InitTypeDef GPIO_InitStruct;

	// A C D already enable
	__HAL_RCC_GPIOB_CLK_ENABLE();

	// Set rows pins as output
	for (i=0; i<MATRIX_ROW; i++) {
		GPIO_InitStruct.Pin = ROWS_GPIO[i].gpio_pin;
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
		HAL_GPIO_Init(ROWS_GPIO[i].gpio_port, &GPIO_InitStruct);
		HAL_GPIO_WritePin(ROWS_GPIO[i].gpio_port, ROWS_GPIO[i].gpio_pin, GPIO_PIN_RESET);
	}

	// Set columns pin as input
	for (i=0; i<MATRIX_COL; i++) {
		GPIO_InitStruct.Pin = COLS_GPIO[i].gpio_pin;
		GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
		GPIO_InitStruct.Pull = GPIO_PULLDOWN;
		HAL_GPIO_Init(COLS_GPIO[i].gpio_port, &GPIO_InitStruct);
	}
}

// Set VCC to only one row
void MATRIX_Set_Row (uint8_t index) {
	int r_index = 0;

	// Deactivate all rows
	for ( r_index = 0; r_index <  MATRIX_ROW; r_index++) {
		HAL_GPIO_WritePin(ROWS_GPIO[r_index].gpio_port, ROWS_GPIO[r_index].gpio_pin, GPIO_PIN_RESET);
	}
	// Activate only the one wanted
	HAL_GPIO_WritePin(ROWS_GPIO[index].gpio_port, ROWS_GPIO[index].gpio_pin, GPIO_PIN_SET);
}

// Read column state
uint8_t MATRIX_Read_Col_State (uint8_t index) {
	return HAL_GPIO_ReadPin(COLS_GPIO[index].gpio_port, COLS_GPIO[index].gpio_pin);
}

// Get key function used
uint8_t MATRIX_Get_Function (uint8_t r_index, uint8_t c_index) {
	return matrix_function[r_index][c_index];
}

// Get key functions used
void MATRIX_Get_Functions_Used (uint8_t* functions_buffer) {
	int r_index = 0,
	    c_index = 0,
		i = SIMULT_KEYS;

	// For all rows
	for ( r_index = 0; r_index <  MATRIX_ROW; r_index++) {
		MATRIX_Set_Row(r_index);
		// Read all columns
		for ( c_index = 0; c_index <  MATRIX_COL; c_index++) {
			// If column is activated
			if ( MATRIX_Read_Col_State(c_index) ) {
				// Store function in buffer
				*functions_buffer = MATRIX_Get_Function(r_index, c_index);
				// Prevent buffer overflow
				i--;
				if ( i > 0) {
					functions_buffer++;
				}
				else {
					functions_buffer -=  SIMULT_KEYS;
					i = SIMULT_KEYS;
				}
			}
		}
	}
}
