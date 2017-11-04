#ifndef __KEYBOARD_DESCRIPTOR_H
#define __KEYBOARD_DESCRIPTOR_H

/* Number of bytes in the descriptor below */
#define CUSTOM_KEYBOARD_DESC_SIZE 63

/* Report descriptor */
#define CUSTOM_KEYBOARD_DESC \
  /* USER CODE BEGIN 0 */																									\
	0x05, 0x01,	/*	Usage Page (Generic Desktop,*/													\
	0x09, 0x06,	/*	Usage (Keyboard), */																		\
	0xA1, 0x01,	/*	Collection (Application), */														\
	0x05, 0x07,	/*		Usage Page (Key Codes); */														\
																																					\
	/* Modifier keys */																											\
	0x19, 0xE0,	/*		Usage Minimum (224), */																\
	0x29, 0xE7,	/*		Usage Maximum (231), */																\
	0x15, 0x00,	/*		Logical Minimum (0), */																\
	0x25, 0x01,	/*		Logical Maximum (1), */																\
	0x75, 0x01,	/*		Report Size (1), */																		\
	0x95, 0x08,	/*		Report Count (8), */																	\
	0x81, 0x02,	/*		Input (Data, Variable, Absolute),   ;Modifier byte */	\
																																					\
	/* LEDs */ 																															\
	0x95, 0x01,	/*		Report Count (1), */																	\
	0x75, 0x08,	/*		Report Size (8), */																		\
	0x81, 0x01,	/*		Input (Constant),  					;Reserved byte */					\
	0x95, 0x05,	/*		Report Count (5), */																	\
	0x75, 0x01,	/*		Report Size (1), */																		\
	0x05, 0x08,	/*		Usage Page (Page# for LEDs), */												\
	0x19, 0x01,	/*		Usage Minimum (1), */																	\
	0x29, 0x05,	/*		Usage Maximum (5), */																	\
	0x91, 0x02,	/*		Output (Data, Variable, Absolute), 	;LED report */		\
	0x95, 0x01,	/*		Report Count (1), */																	\
	0x75, 0x03,	/*		Report Size (3), */																		\
	0x91, 0x01,	/*		Output (Constant),					;LED report padding */		\
																																					\
	/* Slot for 6 keys at same time */																			\
	0x95, 0x06,	/*		Report Count (6), */																	\
	0x75, 0x08,	/*		Report Size (8), */																		\
	0x15, 0x00,	/*		Logical Minimum (0), */																\
	0x25, 0x65,	/*		Logical Maximum(101), */															\
	0x05, 0x07,	/*		Usage Page (Key Codes), */														\
	0x19, 0x00,	/*		Usage Minimum (0), */																	\
	0x29, 0x65,	/*		Usage Maximum (101), */																\
	0x81, 0x00,	/*		Input (Data, Array),				;Key arrays (6 bytes) */	\
	0xC0				/*  End collection */

#endif // __KEYBOARD_DESCRIPTOR_H
