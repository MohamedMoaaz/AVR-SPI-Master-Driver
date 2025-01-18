/**
 * @file    DIO_interface.h
 * @author  Mohamed Moaaz
 * @brief   DIO interface file
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

#ifndef __DIO_INTERFACE_H__
#define __DIO_INTERFACE_H__

//==============================================================================
// Macros & Defines
//==============================================================================

#define DIO_u8PIN_HIGH   1
#define DIO_u8PIN_LOW    0

#define DIO_u8PORT_HIGH  0xFF
#define DIO_u8PORT_Low   0

#define DIO_u8PORTA      0
#define DIO_u8PORTB      1
#define DIO_u8PORTC      2
#define DIO_u8PORTD      3

#define DIO_u8PIN0       0
#define DIO_u8PIN1       1
#define DIO_u8PIN2       2
#define DIO_u8PIN3       3
#define DIO_u8PIN4       4
#define DIO_u8PIN5       5
#define DIO_u8PIN6       6
#define DIO_u8PIN7       7

//==============================================================================
// Typedefs
//==============================================================================


//==============================================================================
// Exported Values
//==============================================================================


//==============================================================================
// Global Functions Prototypes
//==============================================================================

E_Status DIO_u8SetPinValue(uint8_t copy_u8Port, uint8_t copy_u8Pin, uint8_t copy_u8Value);
E_Status DIO_u8SetPortValue(uint8_t copy_u8Port, uint8_t copy_u8Value);
E_Status DIO_u8GetPinValue(uint8_t copy_u8Port, uint8_t copy_u8Pin, uint8_t* copy_pu8Value);

#endif /* __DIO_INTERFACE_H__ */