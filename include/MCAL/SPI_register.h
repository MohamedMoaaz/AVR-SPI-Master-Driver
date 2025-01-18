/**
 * @file    SPI_register.h
 * @author  Mohamed Moaaz
 * @brief   SPI register file
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

#ifndef __SPI_REGISTER_H__
#define __SPI_REGISTER_H__

//==============================================================================
// Macros & Defines
//==============================================================================

/**
 * @brief SPI Registers
 *
 */

#define SPCR            *((volatile uint8_t*)0x2d)  /*SPI Control Register*/
#define SPSR            *((volatile uint8_t*)0x2e)  /*SPI Status Register*/
#define SPDR            *((volatile uint8_t*)0x2f)  /*SPI Data Register*/

/**
 * @brief SPI Register Pins
 *
 */
// SPCR Pins
#define SPCR_SPIE       7                           /*SPI Interrupt Enable*/
#define SPCR_SPE        6                           /*SPI Enable*/
#define SPCR_DORD       5                           /*Data Order*/
#define SPCR_MSTR       4                           /*Master/Slave Select*/
#define SPCR_CPOL       3                           /*Clock Polarity*/
#define SPCR_CPHA       2                           /*Clock Phase*/
#define SPCR_SPR1       1                           /*Clock Rate Bit 1*/
#define SPCR_SPR0       0                           /*Clock Rate Bit 0*/

// SPSR Pins
#define SPSR_SPIF       7                           /*SPI Interrupt Flag*/
#define SPSR_WCOL       6                           /*Write collision Flag*/
#define SPSR_SPI2X      0                           /*Double SPI Speed Bit*/

//==============================================================================
// Typedefs
//==============================================================================


//==============================================================================
// Exported Values
//==============================================================================


//==============================================================================
// Global Functions Prototypes
//==============================================================================

#endif /* __SPI_REGISTER_H__ */