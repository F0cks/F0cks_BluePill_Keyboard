#ifndef __KEYBOARD_MATRIX_H
#define __KEYBOARD_MATRIX_H

#include "keyboard_config.h"

void MATRIX_GPIO_Init();
void MATRIX_Set_Row (uint8_t index);
uint8_t MATRIX_Read_Col_State (uint8_t index);
uint8_t MATRIX_Get_Function (uint8_t r_index, uint8_t c_index);
void MATRIX_Get_Functions_Used (uint8_t* functions_buffer) ;

#endif /* __KEYBOARD_MATRIX_H */
