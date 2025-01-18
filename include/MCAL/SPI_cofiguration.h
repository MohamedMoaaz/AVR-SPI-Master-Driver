/**
 * @file    SPI_configuration.h
 * @author  Mohamed Moaaz
 * @brief   SPI configuration file
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

#ifndef __SPI_CONFIGURATION_H__
#define __SPI_CONFIGURATION_H__

//==============================================================================
// Macros & Defines
//==============================================================================

/*choose The order in which the data is transmitted
                                        options
                                        1-LSB_TRANSMITTED_FIRST
                                        2-MSB_TRANSMITTED_FIRST
                                        */
#define DATA_ORDER                      LSB_TRANSMITTED_FIRST

/*choose if the device master or slave
                                        options
                                        1-MASTER
                                        2-SLAVE
                                        */
#define SPI_ROLE                        MASTER

/*choose The clock polarity
                                        options
                                        1-RISING_LEADING_FALLING_TRAILING
                                        2-FALLING_LEADING_RISING_TRAILING
                                        */
#define CLOCK_POLARITY                  RISING_LEADING_FALLING_TRAILING

/*choose The clock phase
                                        options
                                        1-SAMPLE_AT_LEADING_SETUP_AT_TRAILING
                                        2-SETUP_AT_LEADING_SAMPLE_AT_TRAILING
                                        */
#define CLOCK_PHASE                     SAMPLE_AT_LEADING_SETUP_AT_TRAILING

/*choose The clock rate for
                                        options
                                        1-F_CPU_DIV_BY_4
                                        2-F_CPU_DIV_BY_16
                                        3-F_CPU_DIV_BY_64
                                        4-F_CPU_DIV_BY_128
                                        */
#define CLOCK_RATE                      F_CPU_DIV_BY_4

/*choose The clock speed
                                        options
                                        1-NORMAL_SPEED
                                        2-DOUBLE_SPEED
                                        */
#define CLOCK_SPEED                     NORMAL_SPEED

/*set the time out needed to wait for transfer done before function is timed out*/
#define SPI_TIME_OUT                    50000

//==============================================================================
// Typedefs
//==============================================================================


//==============================================================================
// Exported Values
//==============================================================================


//==============================================================================
// Global Functions Prototypes
//==============================================================================


#endif /* __SPI_CONFIGURATION_H__ */