/**
 * @file    SPI_interface.h
 * @author  Mohamed Moaaz
 * @brief   SPI interfacing file
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

#ifndef __SPI_INTERFACE_H__
#define __SPI_INTERFACE_H__

//==============================================================================
// Macros & Defines
//==============================================================================


//==============================================================================
// Typedefs
//==============================================================================


//==============================================================================
// Exported Values
//==============================================================================


//==============================================================================
// Global Functions Prototypes
//==============================================================================

void SPI_voidInit();

uint8_t SPI_u8TransceiveCharacterSynchronous(uint8_t copy_u8Character);

uint8_t SPI_u8TransceiveBufferSynchronous(uint8_t *copy_u8Buffer, uint8_t copy_u8BufferSize);

E_Status SPI_xTransceiveCharacterASynchronous(uint8_t *copy_u8Character, void (*copy_pvNotificationFunc)(void));

E_Status SPI_xTransceiveBufferASynchronous(uint8_t copy_u8Buffer, uint8_t copy_u8BufferSize, void (*copy_pvNotificationFunc)(void));

#endif /* __SPI_INTERFACE_H__ */