/**
 * @file    SPI_private.h
 * @author  Mohamed Moaaz
 * @brief   SPI private file
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

#ifndef __SPI_PRIVATE_H__
#define __SPI_PRIVATE_H__

//==============================================================================
// Macros & Defines
//==============================================================================

/*data order*/
#define LSB_TRANSMITTED_FIRST                       1
#define MSB_TRANSMITTED_FIRST                       0

/*spi role*/
#define MASTER                                      1
#define SLAVE                                       0

/*clock polarity*/
#define FALLING_LEADING_RISING_TRAILING             1
#define RISING_LEADING_FALLING_TRAILING             0

/*clock phase*/
#define SETUP_AT_LEADING_SAMPLE_AT_TRAILING         1
#define SAMPLE_AT_LEADING_SETUP_AT_TRAILING         0

/*clock rate*/
#define F_CPU_DIV_BY_4                              0
#define F_CPU_DIV_BY_16                             1
#define F_CPU_DIV_BY_64                             2
#define F_CPU_DIV_BY_128                            3

/*clock speed*/
#define NORMAL_SPEED                                1
#define DOUBLE_SPEED                                2

/*function selection*/
#define UART_IDLE                                   0
#define SPI_TRANSCEIVE_CHARACTER                    1
#define SPI_TRANSCEIVE_BUFFER                       2

//==============================================================================
// Typedefs
//==============================================================================

//==============================================================================
// Exported Values
//==============================================================================

//==============================================================================
// Global Functions Prototypes
//==============================================================================

#endif /* __SPI_PRIVATE_H__ */