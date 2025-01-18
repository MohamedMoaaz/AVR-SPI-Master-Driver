/**
 * @file    DIO_program.c
 * @author  Mohamed Moaaz
 * @brief   DIO program file
 * @version 0.1
 * @date    2023-10-31
 *
 * @copyright Copyright (c) 2023
 */

//==============================================================================
// Includes
//==============================================================================

#include "STD_TYPES.h"
#include "MCAL/DIO_interface.h"
#include "MCAL/DIO_register.h"

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

E_Status DIO_u8SetPinValue(uint8_t copy_u8Port, uint8_t copy_u8Pin, uint8_t copy_u8Value)
{
    E_Status Local_u8ErrorState = E_OK;
    if (copy_u8Pin <= DIO_u8PIN7)
    {
        if (copy_u8Value == DIO_u8PIN_LOW)
        {
            switch (copy_u8Port)
            {
            case DIO_u8PORTA:
                CLEAR_BIT(PORTA, copy_u8Pin);
                break;
            case DIO_u8PORTB:
                CLEAR_BIT(PORTB, copy_u8Pin);
                break;
            case DIO_u8PORTC:
                CLEAR_BIT(PORTC, copy_u8Pin);
                break;
            case DIO_u8PORTD:
                CLEAR_BIT(PORTD, copy_u8Pin);
                break;
            default:
                Local_u8ErrorState = E_NOK;
                break;
            }
        }
        else if (copy_u8Value == DIO_u8PIN_HIGH)
        {
            switch (copy_u8Port)
            {
            case DIO_u8PORTA:
                SET_BIT(PORTA, copy_u8Pin);
                break;
            case DIO_u8PORTB:
                SET_BIT(PORTB, copy_u8Pin);
                break;
            case DIO_u8PORTC:
                SET_BIT(PORTC, copy_u8Pin);
                break;
            case DIO_u8PORTD:
                SET_BIT(PORTD, copy_u8Pin);
                break;
            default:
                Local_u8ErrorState = E_NOK;
                break;
            }
        }
        else
        {
            Local_u8ErrorState = E_NOK;
        }
    }
    else
    {
        Local_u8ErrorState = E_NOK;
    }
    return Local_u8ErrorState;
}

E_Status DIO_u8SetPortValue(uint8_t copy_u8Port, uint8_t copy_u8Value)
{
    E_Status Local_u8ErrorState = E_OK;

    switch (copy_u8Port)
    {
    case DIO_u8PORTA:
        PORTA = copy_u8Value;
        break;
    case DIO_u8PORTB:
        PORTB = copy_u8Value;
        break;
    case DIO_u8PORTC:
        PORTC = copy_u8Value;
        break;
    case DIO_u8PORTD:
        PORTD = copy_u8Value;
        break;
    default:
        Local_u8ErrorState = E_NOK;
        break;
    }
    return Local_u8ErrorState;
}

E_Status DIO_u8GetPinValue(uint8_t copy_u8Port, uint8_t copy_u8Pin, uint8_t *copy_pu8Value)
{
    E_Status Local_u8ErrorState = E_OK;
    if ((copy_pu8Value != NULL) && (copy_u8Pin <= DIO_u8PIN7))
    {
        switch (copy_u8Port)
        {
        case DIO_u8PORTA:
            *copy_pu8Value = GET_BIT(PINA, copy_u8Pin);
            break;
        case DIO_u8PORTB:
            *copy_pu8Value = GET_BIT(PINB, copy_u8Pin);
            break;
        case DIO_u8PORTC:
            *copy_pu8Value = GET_BIT(PINC, copy_u8Pin);
            break;
        case DIO_u8PORTD:
            *copy_pu8Value = GET_BIT(PIND, copy_u8Pin);
            break;
        default:
            Local_u8ErrorState = E_NOK;
            break;
        }
    }
    else
    {
        Local_u8ErrorState = E_NOK;
    }
    return Local_u8ErrorState;
}
