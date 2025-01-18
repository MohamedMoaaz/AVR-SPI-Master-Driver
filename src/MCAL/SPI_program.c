/**
 * @file    SPI.c
 * @author  Mohamed Moaaz
 * @brief   @SPI Program file
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

//==============================================================================
// Includes
//==============================================================================

#include "STD_TYPES.h"
#include "MCAL/SPI_register.h"
#include "MCAL/SPI_Private.h"
#include "MCAL/SPI_cofiguration.h"
#include "MCAL/SPI_Interface.h"

//==============================================================================
// Extern Variables
//==============================================================================

//==============================================================================
// Private Macros & Defines
//==============================================================================

//==============================================================================
// Private Typedefs
//==============================================================================

//==============================================================================
// Static Variables
//==============================================================================

static void (*SPI_pvCallBackNotificationFunc)(void) = NULL; /*global pointer to function to carry notification function*/
static uint8_t *SPI_pu8TransceivedCharacterCarry = NULL;    /*global pointer to u8 to carry character in transceive character function*/
static char *SPI_pcTransceivedBufferCarry = NULL;           /*global pointer to char to carry buffer in transceive buffer function*/
static uint8_t SPI_BufferSize = 0;                          /*global variable to carry buffer size in transceive buffer function*/
static uint8_t SPI_IsBuffer = 0;                            /*flag to prevent interruption in ISR from different function*/
static uint8_t SPI_FunctionSelect = UART_IDLE;              /*flag to select function to be executed in ISR*/

//==============================================================================
// Global Variables
//==============================================================================

//==============================================================================
// Exported Values
//==============================================================================

//==============================================================================
// Static Functions Prototypes
//==============================================================================

//==============================================================================
// Static Functions
//==============================================================================

//==============================================================================
// Global Functions
//==============================================================================

void SPI_voidInit()
{
    /*set the configuration in SPCR register*/
    /*____select the order of data ___select master or slave__choose the clock polarity___choose the clock phase__*/
    SPCR |= (DATA_ORDER << SPCR_DORD) | (SPI_ROLE << SPCR_MSTR) | (CLOCK_POLARITY << SPCR_CPOL) | (CLOCK_PHASE << SPCR_CPHA) | (CLOCK_RATE << SPCR_SPR0);

/*clock frequency divided by two is selected*/
#if (CLOCK_SPEED == DOUBLE_SPEED)
    SET_BIT(SPSR, SPSR_SPI2X);
#endif

    // enable SPI
    SET_BIT(SPCR, SPCR_SPE);
}

uint8_t SPI_u8TransceiveCharacterSynchronous(uint8_t copy_u8Character)
{
    /*counter to count time before function is timed out*/
    uint32_t Local_u32TimeCounter = 0;

    /*Send the data*/
    SPDR = copy_u8Character;

    /*wait (busy waiting) until transfer complete*/
    while (GET_BIT(SPSR, SPSR_SPIF) != 1 && Local_u32TimeCounter < SPI_TIME_OUT)
    {
        Local_u32TimeCounter++;
    }

    /*Get the exchanged data*/
    return SPDR;
}

uint8_t SPI_u8TransceiveBufferSynchronous(uint8_t *copy_u8Buffer, uint8_t copy_u8BufferSize)
{
    uint8_t Local_u8StringCounter;

    /*loop till the whole the Buffer is transceived*/
    for (Local_u8StringCounter = 0; Local_u8StringCounter < copy_u8BufferSize; Local_u8StringCounter++)
    {
        /*call transceive character function*/
        SPI_u8TransceiveCharacterSynchronous(copy_u8Buffer[Local_u8StringCounter]);
        Local_u8StringCounter++;
    }
}

E_Status SPI_xTransceiveCharacterASynchronous(uint8_t *copy_u8Character, void (*copy_pvNotificationFunc)(void))
{
    E_Status Local_ErrorStatus = E_OK;

    /*check if the ISR is busy*/
    if (SPI_IsBuffer == 1)
    {
        Local_ErrorStatus = BUSY_FUNC;
    }
    else
    {
        /*check NULL pointer*/
        if (copy_pvNotificationFunc == NULL)
        {
            Local_ErrorStatus = NULL_POINTER;
        }
        else
        {
            /*raise the flag of this function*/
            SPI_FunctionSelect = SPI_TRANSCEIVE_CHARACTER;

            /*assign character into global one to use it in ISR*/
            SPI_pu8TransceivedCharacterCarry = copy_u8Character;

            /*initialize notification function*/
            SPI_pvCallBackNotificationFunc = copy_pvNotificationFunc;

            /*SPI interrupt enable*/
            SET_BIT(SPCR, SPCR_SPIE);

            /*transceive the character*/
            SPDR = *copy_u8Character;
        }
    }
    return Local_ErrorStatus;
}

E_Status SPI_xTransceiveBufferASynchronous(uint8_t copy_u8Buffer, uint8_t copy_u8BufferSize, void (*copy_pvNotificationFunc)(void))
{
    E_Status Local_ErrorStatus = E_OK;

    /*check if the ISR is busy*/
    if (SPI_IsBuffer == 1)
    {
        Local_ErrorStatus = BUSY_FUNC;
    }
    else
    {
        /*check NULL pointer*/
        if (copy_pvNotificationFunc == NULL)
        {
            Local_ErrorStatus = NULL_POINTER;
        }
        else
        {
            /*raise the flag of this function*/
            SPI_FunctionSelect = SPI_TRANSCEIVE_BUFFER;

            /*assign buffer into global one to use it in ISR*/
            SPI_pcTransceivedBufferCarry = copy_u8Buffer;

            /*initialize notification function*/
            SPI_pvCallBackNotificationFunc = copy_pvNotificationFunc;

            /*SPI interrupt enable*/
            SET_BIT(SPCR, SPCR_SPIE);

            /*transceive the first character*/
            SPDR = SPI_pcTransceivedBufferCarry[0];
        }
    }
    return Local_ErrorStatus;
}

// void __vector_12(void) __attribute__((signal));
// void __vector_12(void)
// {
//     /*check for the trigger function*/
//     if (SPI_FunctionSelect == SPI_TRANSCEIVE_BUFFER)
//     {
//         /*enable read buffer flag*/
//         SPI_IsBuffer = 1;

//         /*initialize counter to loop for characters*/
//         static uint8_t Local_u8BufferCounter = 1;

//         /*transceive the data*/
//         SPDR = SPI_pcTransceivedBufferCarry[Local_u8BufferCounter];

//         /*increment the counter to transceive the next character*/
//         Local_u8BufferCounter++;

//         /*check if the whole buffer is received*/
//         if (Local_u8BufferCounter == SPI_BufferSize)
//         {
//             /*invoke the notification function*/
//             SPI_pvCallBackNotificationFunc();

//             /*clear Buffer counter*/
//             Local_u8BufferCounter = 0;

//             /*disable Buffer flag*/
//             SPI_IsBuffer = 0;

//             /*disable the interrupt enable*/
//             CLEAR_BIT(SPCR, SPCR_SPIE);
//         }
//     }
//     else if (SPI_FunctionSelect == SPI_TRANSCEIVE_CHARACTER)
//     {
//         /*invoke the notification function*/
//         SPI_pvCallBackNotificationFunc();

//         /*disable the interrupt enable*/
//         CLEAR_BIT(SPCR, SPCR_SPIE);
//     }
// }