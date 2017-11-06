#ifndef __KEYBOARD_MISC_H
#define __KEYBOARD_MISC_H

#include "stm32f1xx_hal.h"

/*
 * Key definition
 */

// AZERTY
enum {
	NO_KEY 	= 0x00,

	#ifndef AZERTY
	KEY_A 	= 0x04,
	KEY_M 	= 0x10,
	KEY_Q 	= 0x14,
	KEY_W 	= 0x1A,
	KEY_Z 	= 0x1D,
	#else
	KEY_A 	= 0x14,
	KEY_M 	= 0x33,
	KEY_Q   = 0x04,
	KEY_W 	= 0x1D,
	KEY_Z 	= 0x1A,
	#endif
	KEY_B 	= 0x05,
	KEY_C 	= 0x06,
	KEY_D 	= 0x07,
	KEY_E 	= 0x08,
	KEY_F 	= 0x09,
	KEY_G 	= 0x0A,
	KEY_H 	= 0x0B,
	KEY_I 	= 0x0C,
	KEY_J 	= 0x0D,
	KEY_K 	= 0x0E,
	KEY_L 	= 0x0F,
	KEY_N 	= 0x11,
	KEY_O 	= 0x12,
	KEY_P 	= 0x13,
	KEY_R 	= 0x15,
	KEY_S 	= 0x16,
	KEY_T 	= 0x17,
	KEY_U 	= 0x18,
	KEY_V 	= 0x19,
	KEY_X 	= 0x1B,
	KEY_Y 	= 0x1C,

	KEY_1 	= 0x1E,
	KEY_2 	= 0x1F,
	KEY_3 	= 0x20,
	KEY_4 	= 0x21,
	KEY_5 	= 0x22,
	KEY_6 	= 0x23,
	KEY_7 	= 0x24,
	KEY_8 	= 0x25,
	KEY_9 	= 0x26,
	KEY_0 	= 0x27,

	KEY_ENT = 0x28, // Enter
	KEY_ESC = 0x29, // Escape
	KEY_BSP = 0x2A, // Delete backspace
	KEY_TAB = 0x2B,	// Tabulation
	KEY_SPC = 0x2C, // Space bar

	KEY_MIN = 0x2D, // - and _ ( azerty: ) and ° )
	KEY_EQU = 0x2E, // = and +
	KEY_LCR = 0x2F, // [ and { ( azerty: ^ and ¨ )
	KEY_RCR = 0x30, // [ and } ( azerty: $ and £ )
	KEY_ASL = 0x31, // \ and | ( azerty: * and µ )
	KEY_VIR = 0x10, // AZERTY : , and ?

	KEY_SPE = 0x32,
	KEY_APO = 0x34, // ‘ and “ ( azerty: % and ù )
	KEY_COM = 0x36, // , and < ( azerty: ; and . )
	KEY_DOT = 0x37, // . and > ( azerty: : and / )
	KEY_SLA = 0x38, // / and ? ( azerty: ! and § )
	KEY_CLK = 0x39, // Caps lock

	/* Functions */
	KEY_F1  = 0x3A,
	KEY_F2  = 0x3B,
	KEY_F3  = 0x3C,
	KEY_F4  = 0x3D,
	KEY_F5  = 0x3E,
	KEY_F6  = 0x3F,
	KEY_F7  = 0x40,
	KEY_F8  = 0x41,
	KEY_F9  = 0x42,
	KEY_F10 = 0x43,
	KEY_F11 = 0x44,
	KEY_F12 = 0x45,

	KEY_PS	= 0x46, // Print Screen
	KEY_SL	= 0x47, // Scroll Lock
	KEY_PAU = 0x48, // Pause
	KEY_INS	= 0x49, // Insert
	KEY_HOM = 0x4A, // Home
	KEY_PU 	= 0x4B, // Page Up
	KEY_DF 	= 0x4C, // Delete forward
	KEY_END = 0x4D, // Key end
	KEY_PD	= 0x4E, // Page down
	KEY_RA	= 0x4F, // Right arrow
	KEY_LA	= 0x50, // Left arrow
	KEY_DA	= 0x51, // Down arrow
	KEY_UA	= 0x52, // Up Arrow

	/* Key pad */
	KEY_PNU = 0x53, // Num lock
	KEY_PSL = 0x54, // /
	KEY_PAS = 0x55, // *
	KEY_PMI = 0x56, // -
	KEY_PPL = 0x57, // +
	KEY_PEN = 0x58, // Enter
	KEY_P1	= 0x59, // 1
	KEY_P2	= 0x5A, // 2
	KEY_P3	= 0x5B, // 3
	KEY_P4	= 0x5C, // 4
	KEY_P5	= 0x5D, // 5
	KEY_P6	= 0x5E, // 6
	KEY_P7	= 0x5F, // 7
	KEY_P8	= 0x60, // 8
	KEY_P9	= 0x61, // 9
	KEY_P0	= 0x62, // 0
	KEY_PDO = 0x63, // .

	KEY_CHV = 0x64, // < >

	/* Modifiers */
	KEY_LCT = 0xE0, // Left Control
	KEY_LSH = 0XE1, // Left shift
	KEY_LAL = 0xE2, // Left ALT
	KEY_LGU = 0xE3, // Left GUI
	KEY_RCT = 0xE4, // Right Control
	KEY_RSH = 0xE5, // Right shift
	KEY_RAL = 0xE6, // Right ALT
	KEY_RGU = 0xE7  // Right GUI

}key_function;

enum {
	CAPS_LOCK		= 0x00,
	NUM_LOCK		= 0x01,
	SCROLL_LOCK	= 0x02
}led_function;
/*
 *  GPIO structure for configuration file
 */
typedef struct {
	GPIO_TypeDef*	gpio_port;
	uint32_t		gpio_pin;

} gpio_table;

#endif /* __KEYBOARD_MISC_H */
