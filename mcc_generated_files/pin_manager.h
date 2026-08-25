/**
  PIN MANAGER Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for PIN MANAGER.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.5
        Device            :  dsPIC33EP128MC506
    The generated drivers are tested against the following:
        Compiler          :  XC16 v2.10
        MPLAB 	          :  MPLAB X v6.05
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

#ifndef _PIN_MANAGER_H
#define _PIN_MANAGER_H
/**
    Section: Includes
*/
#include <xc.h>

/**
    Section: Device Pin Macros
*/
/**
  @Summary
    Sets the GPIO pin, RA0, high using LATA0.

  @Description
    Sets the GPIO pin, RA0, high using LATA0.

  @Preconditions
    The RA0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA0 high (1)
    channel_AN0_SetHigh();
    </code>

*/
#define channel_AN0_SetHigh()          (_LATA0 = 1)
/**
  @Summary
    Sets the GPIO pin, RA0, low using LATA0.

  @Description
    Sets the GPIO pin, RA0, low using LATA0.

  @Preconditions
    The RA0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA0 low (0)
    channel_AN0_SetLow();
    </code>

*/
#define channel_AN0_SetLow()           (_LATA0 = 0)
/**
  @Summary
    Toggles the GPIO pin, RA0, using LATA0.

  @Description
    Toggles the GPIO pin, RA0, using LATA0.

  @Preconditions
    The RA0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA0
    channel_AN0_Toggle();
    </code>

*/
#define channel_AN0_Toggle()           (_LATA0 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RA0.

  @Description
    Reads the value of the GPIO pin, RA0.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA0
    postValue = channel_AN0_GetValue();
    </code>

*/
#define channel_AN0_GetValue()         _RA0
/**
  @Summary
    Configures the GPIO pin, RA0, as an input.

  @Description
    Configures the GPIO pin, RA0, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA0 as an input
    channel_AN0_SetDigitalInput();
    </code>

*/
#define channel_AN0_SetDigitalInput()  (_TRISA0 = 1)
/**
  @Summary
    Configures the GPIO pin, RA0, as an output.

  @Description
    Configures the GPIO pin, RA0, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA0 as an output
    channel_AN0_SetDigitalOutput();
    </code>

*/
#define channel_AN0_SetDigitalOutput() (_TRISA0 = 0)
/**
  @Summary
    Sets the GPIO pin, RA1, high using LATA1.

  @Description
    Sets the GPIO pin, RA1, high using LATA1.

  @Preconditions
    The RA1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA1 high (1)
    channel_AN1_SetHigh();
    </code>

*/
#define channel_AN1_SetHigh()          (_LATA1 = 1)
/**
  @Summary
    Sets the GPIO pin, RA1, low using LATA1.

  @Description
    Sets the GPIO pin, RA1, low using LATA1.

  @Preconditions
    The RA1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA1 low (0)
    channel_AN1_SetLow();
    </code>

*/
#define channel_AN1_SetLow()           (_LATA1 = 0)
/**
  @Summary
    Toggles the GPIO pin, RA1, using LATA1.

  @Description
    Toggles the GPIO pin, RA1, using LATA1.

  @Preconditions
    The RA1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA1
    channel_AN1_Toggle();
    </code>

*/
#define channel_AN1_Toggle()           (_LATA1 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RA1.

  @Description
    Reads the value of the GPIO pin, RA1.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA1
    postValue = channel_AN1_GetValue();
    </code>

*/
#define channel_AN1_GetValue()         _RA1
/**
  @Summary
    Configures the GPIO pin, RA1, as an input.

  @Description
    Configures the GPIO pin, RA1, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA1 as an input
    channel_AN1_SetDigitalInput();
    </code>

*/
#define channel_AN1_SetDigitalInput()  (_TRISA1 = 1)
/**
  @Summary
    Configures the GPIO pin, RA1, as an output.

  @Description
    Configures the GPIO pin, RA1, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA1 as an output
    channel_AN1_SetDigitalOutput();
    </code>

*/
#define channel_AN1_SetDigitalOutput() (_TRISA1 = 0)
/**
  @Summary
    Sets the GPIO pin, RA4, high using LATA4.

  @Description
    Sets the GPIO pin, RA4, high using LATA4.

  @Preconditions
    The RA4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA4 high (1)
    SDO1_SetHigh();
    </code>

*/
#define SDO1_SetHigh()          (_LATA4 = 1)
/**
  @Summary
    Sets the GPIO pin, RA4, low using LATA4.

  @Description
    Sets the GPIO pin, RA4, low using LATA4.

  @Preconditions
    The RA4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA4 low (0)
    SDO1_SetLow();
    </code>

*/
#define SDO1_SetLow()           (_LATA4 = 0)
/**
  @Summary
    Toggles the GPIO pin, RA4, using LATA4.

  @Description
    Toggles the GPIO pin, RA4, using LATA4.

  @Preconditions
    The RA4 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA4
    SDO1_Toggle();
    </code>

*/
#define SDO1_Toggle()           (_LATA4 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RA4.

  @Description
    Reads the value of the GPIO pin, RA4.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA4
    postValue = SDO1_GetValue();
    </code>

*/
#define SDO1_GetValue()         _RA4
/**
  @Summary
    Configures the GPIO pin, RA4, as an input.

  @Description
    Configures the GPIO pin, RA4, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA4 as an input
    SDO1_SetDigitalInput();
    </code>

*/
#define SDO1_SetDigitalInput()  (_TRISA4 = 1)
/**
  @Summary
    Configures the GPIO pin, RA4, as an output.

  @Description
    Configures the GPIO pin, RA4, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA4 as an output
    SDO1_SetDigitalOutput();
    </code>

*/
#define SDO1_SetDigitalOutput() (_TRISA4 = 0)
/**
  @Summary
    Sets the GPIO pin, RA9, high using LATA9.

  @Description
    Sets the GPIO pin, RA9, high using LATA9.

  @Preconditions
    The RA9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA9 high (1)
    IO_SPI1_CS1_SetHigh();
    </code>

*/
#define IO_SPI1_CS1_SetHigh()          (_LATA9 = 1)
/**
  @Summary
    Sets the GPIO pin, RA9, low using LATA9.

  @Description
    Sets the GPIO pin, RA9, low using LATA9.

  @Preconditions
    The RA9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RA9 low (0)
    IO_SPI1_CS1_SetLow();
    </code>

*/
#define IO_SPI1_CS1_SetLow()           (_LATA9 = 0)
/**
  @Summary
    Toggles the GPIO pin, RA9, using LATA9.

  @Description
    Toggles the GPIO pin, RA9, using LATA9.

  @Preconditions
    The RA9 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RA9
    IO_SPI1_CS1_Toggle();
    </code>

*/
#define IO_SPI1_CS1_Toggle()           (_LATA9 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RA9.

  @Description
    Reads the value of the GPIO pin, RA9.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RA9
    postValue = IO_SPI1_CS1_GetValue();
    </code>

*/
#define IO_SPI1_CS1_GetValue()         _RA9
/**
  @Summary
    Configures the GPIO pin, RA9, as an input.

  @Description
    Configures the GPIO pin, RA9, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA9 as an input
    IO_SPI1_CS1_SetDigitalInput();
    </code>

*/
#define IO_SPI1_CS1_SetDigitalInput()  (_TRISA9 = 1)
/**
  @Summary
    Configures the GPIO pin, RA9, as an output.

  @Description
    Configures the GPIO pin, RA9, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RA9 as an output
    IO_SPI1_CS1_SetDigitalOutput();
    </code>

*/
#define IO_SPI1_CS1_SetDigitalOutput() (_TRISA9 = 0)
/**
  @Summary
    Sets the GPIO pin, RB0, high using LATB0.

  @Description
    Sets the GPIO pin, RB0, high using LATB0.

  @Preconditions
    The RB0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB0 high (1)
    channel_AN2_SetHigh();
    </code>

*/
#define channel_AN2_SetHigh()          (_LATB0 = 1)
/**
  @Summary
    Sets the GPIO pin, RB0, low using LATB0.

  @Description
    Sets the GPIO pin, RB0, low using LATB0.

  @Preconditions
    The RB0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RB0 low (0)
    channel_AN2_SetLow();
    </code>

*/
#define channel_AN2_SetLow()           (_LATB0 = 0)
/**
  @Summary
    Toggles the GPIO pin, RB0, using LATB0.

  @Description
    Toggles the GPIO pin, RB0, using LATB0.

  @Preconditions
    The RB0 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RB0
    channel_AN2_Toggle();
    </code>

*/
#define channel_AN2_Toggle()           (_LATB0 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RB0.

  @Description
    Reads the value of the GPIO pin, RB0.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RB0
    postValue = channel_AN2_GetValue();
    </code>

*/
#define channel_AN2_GetValue()         _RB0
/**
  @Summary
    Configures the GPIO pin, RB0, as an input.

  @Description
    Configures the GPIO pin, RB0, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB0 as an input
    channel_AN2_SetDigitalInput();
    </code>

*/
#define channel_AN2_SetDigitalInput()  (_TRISB0 = 1)
/**
  @Summary
    Configures the GPIO pin, RB0, as an output.

  @Description
    Configures the GPIO pin, RB0, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RB0 as an output
    channel_AN2_SetDigitalOutput();
    </code>

*/
#define channel_AN2_SetDigitalOutput() (_TRISB0 = 0)
/**
  @Summary
    Sets the GPIO pin, RC1, high using LATC1.

  @Description
    Sets the GPIO pin, RC1, high using LATC1.

  @Preconditions
    The RC1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC1 high (1)
    KEY0_RC1_SetHigh();
    </code>

*/
#define KEY0_RC1_SetHigh()          (_LATC1 = 1)
/**
  @Summary
    Sets the GPIO pin, RC1, low using LATC1.

  @Description
    Sets the GPIO pin, RC1, low using LATC1.

  @Preconditions
    The RC1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC1 low (0)
    KEY0_RC1_SetLow();
    </code>

*/
#define KEY0_RC1_SetLow()           (_LATC1 = 0)
/**
  @Summary
    Toggles the GPIO pin, RC1, using LATC1.

  @Description
    Toggles the GPIO pin, RC1, using LATC1.

  @Preconditions
    The RC1 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC1
    KEY0_RC1_Toggle();
    </code>

*/
#define KEY0_RC1_Toggle()           (_LATC1 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RC1.

  @Description
    Reads the value of the GPIO pin, RC1.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC1
    postValue = KEY0_RC1_GetValue();
    </code>

*/
#define KEY0_RC1_GetValue()         _RC1
/**
  @Summary
    Configures the GPIO pin, RC1, as an input.

  @Description
    Configures the GPIO pin, RC1, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC1 as an input
    KEY0_RC1_SetDigitalInput();
    </code>

*/
#define KEY0_RC1_SetDigitalInput()  (_TRISC1 = 1)
/**
  @Summary
    Configures the GPIO pin, RC1, as an output.

  @Description
    Configures the GPIO pin, RC1, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC1 as an output
    KEY0_RC1_SetDigitalOutput();
    </code>

*/
#define KEY0_RC1_SetDigitalOutput() (_TRISC1 = 0)
/**
  @Summary
    Sets the GPIO pin, RC11, high using LATC11.

  @Description
    Sets the GPIO pin, RC11, high using LATC11.

  @Preconditions
    The RC11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC11 high (1)
    KEY2_RC11_SetHigh();
    </code>

*/
#define KEY2_RC11_SetHigh()          (_LATC11 = 1)
/**
  @Summary
    Sets the GPIO pin, RC11, low using LATC11.

  @Description
    Sets the GPIO pin, RC11, low using LATC11.

  @Preconditions
    The RC11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC11 low (0)
    KEY2_RC11_SetLow();
    </code>

*/
#define KEY2_RC11_SetLow()           (_LATC11 = 0)
/**
  @Summary
    Toggles the GPIO pin, RC11, using LATC11.

  @Description
    Toggles the GPIO pin, RC11, using LATC11.

  @Preconditions
    The RC11 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC11
    KEY2_RC11_Toggle();
    </code>

*/
#define KEY2_RC11_Toggle()           (_LATC11 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RC11.

  @Description
    Reads the value of the GPIO pin, RC11.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC11
    postValue = KEY2_RC11_GetValue();
    </code>

*/
#define KEY2_RC11_GetValue()         _RC11
/**
  @Summary
    Configures the GPIO pin, RC11, as an input.

  @Description
    Configures the GPIO pin, RC11, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC11 as an input
    KEY2_RC11_SetDigitalInput();
    </code>

*/
#define KEY2_RC11_SetDigitalInput()  (_TRISC11 = 1)
/**
  @Summary
    Configures the GPIO pin, RC11, as an output.

  @Description
    Configures the GPIO pin, RC11, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC11 as an output
    KEY2_RC11_SetDigitalOutput();
    </code>

*/
#define KEY2_RC11_SetDigitalOutput() (_TRISC11 = 0)
/**
  @Summary
    Sets the GPIO pin, RC2, high using LATC2.

  @Description
    Sets the GPIO pin, RC2, high using LATC2.

  @Preconditions
    The RC2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC2 high (1)
    KEY1_RC2_SetHigh();
    </code>

*/
#define KEY1_RC2_SetHigh()          (_LATC2 = 1)
/**
  @Summary
    Sets the GPIO pin, RC2, low using LATC2.

  @Description
    Sets the GPIO pin, RC2, low using LATC2.

  @Preconditions
    The RC2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC2 low (0)
    KEY1_RC2_SetLow();
    </code>

*/
#define KEY1_RC2_SetLow()           (_LATC2 = 0)
/**
  @Summary
    Toggles the GPIO pin, RC2, using LATC2.

  @Description
    Toggles the GPIO pin, RC2, using LATC2.

  @Preconditions
    The RC2 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC2
    KEY1_RC2_Toggle();
    </code>

*/
#define KEY1_RC2_Toggle()           (_LATC2 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RC2.

  @Description
    Reads the value of the GPIO pin, RC2.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC2
    postValue = KEY1_RC2_GetValue();
    </code>

*/
#define KEY1_RC2_GetValue()         _RC2
/**
  @Summary
    Configures the GPIO pin, RC2, as an input.

  @Description
    Configures the GPIO pin, RC2, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC2 as an input
    KEY1_RC2_SetDigitalInput();
    </code>

*/
#define KEY1_RC2_SetDigitalInput()  (_TRISC2 = 1)
/**
  @Summary
    Configures the GPIO pin, RC2, as an output.

  @Description
    Configures the GPIO pin, RC2, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC2 as an output
    KEY1_RC2_SetDigitalOutput();
    </code>

*/
#define KEY1_RC2_SetDigitalOutput() (_TRISC2 = 0)
/**
  @Summary
    Sets the GPIO pin, RC3, high using LATC3.

  @Description
    Sets the GPIO pin, RC3, high using LATC3.

  @Preconditions
    The RC3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC3 high (1)
    SCK1_SetHigh();
    </code>

*/
#define SCK1_SetHigh()          (_LATC3 = 1)
/**
  @Summary
    Sets the GPIO pin, RC3, low using LATC3.

  @Description
    Sets the GPIO pin, RC3, low using LATC3.

  @Preconditions
    The RC3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RC3 low (0)
    SCK1_SetLow();
    </code>

*/
#define SCK1_SetLow()           (_LATC3 = 0)
/**
  @Summary
    Toggles the GPIO pin, RC3, using LATC3.

  @Description
    Toggles the GPIO pin, RC3, using LATC3.

  @Preconditions
    The RC3 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RC3
    SCK1_Toggle();
    </code>

*/
#define SCK1_Toggle()           (_LATC3 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RC3.

  @Description
    Reads the value of the GPIO pin, RC3.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RC3
    postValue = SCK1_GetValue();
    </code>

*/
#define SCK1_GetValue()         _RC3
/**
  @Summary
    Configures the GPIO pin, RC3, as an input.

  @Description
    Configures the GPIO pin, RC3, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC3 as an input
    SCK1_SetDigitalInput();
    </code>

*/
#define SCK1_SetDigitalInput()  (_TRISC3 = 1)
/**
  @Summary
    Configures the GPIO pin, RC3, as an output.

  @Description
    Configures the GPIO pin, RC3, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RC3 as an output
    SCK1_SetDigitalOutput();
    </code>

*/
#define SCK1_SetDigitalOutput() (_TRISC3 = 0)
/**
  @Summary
    Sets the GPIO pin, RD8, high using LATD8.

  @Description
    Sets the GPIO pin, RD8, high using LATD8.

  @Preconditions
    The RD8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD8 high (1)
    IO_SPI1_CS2_SetHigh();
    </code>

*/
#define IO_SPI1_CS2_SetHigh()          (_LATD8 = 1)
/**
  @Summary
    Sets the GPIO pin, RD8, low using LATD8.

  @Description
    Sets the GPIO pin, RD8, low using LATD8.

  @Preconditions
    The RD8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RD8 low (0)
    IO_SPI1_CS2_SetLow();
    </code>

*/
#define IO_SPI1_CS2_SetLow()           (_LATD8 = 0)
/**
  @Summary
    Toggles the GPIO pin, RD8, using LATD8.

  @Description
    Toggles the GPIO pin, RD8, using LATD8.

  @Preconditions
    The RD8 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RD8
    IO_SPI1_CS2_Toggle();
    </code>

*/
#define IO_SPI1_CS2_Toggle()           (_LATD8 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RD8.

  @Description
    Reads the value of the GPIO pin, RD8.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RD8
    postValue = IO_SPI1_CS2_GetValue();
    </code>

*/
#define IO_SPI1_CS2_GetValue()         _RD8
/**
  @Summary
    Configures the GPIO pin, RD8, as an input.

  @Description
    Configures the GPIO pin, RD8, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD8 as an input
    IO_SPI1_CS2_SetDigitalInput();
    </code>

*/
#define IO_SPI1_CS2_SetDigitalInput()  (_TRISD8 = 1)
/**
  @Summary
    Configures the GPIO pin, RD8, as an output.

  @Description
    Configures the GPIO pin, RD8, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RD8 as an output
    IO_SPI1_CS2_SetDigitalOutput();
    </code>

*/
#define IO_SPI1_CS2_SetDigitalOutput() (_TRISD8 = 0)
/**
  @Summary
    Sets the GPIO pin, RE12, high using LATE12.

  @Description
    Sets the GPIO pin, RE12, high using LATE12.

  @Preconditions
    The RE12 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE12 high (1)
    LED0_RE12_SetHigh();
    </code>

*/
#define LED0_RE12_SetHigh()          (_LATE12 = 1)
/**
  @Summary
    Sets the GPIO pin, RE12, low using LATE12.

  @Description
    Sets the GPIO pin, RE12, low using LATE12.

  @Preconditions
    The RE12 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE12 low (0)
    LED0_RE12_SetLow();
    </code>

*/
#define LED0_RE12_SetLow()           (_LATE12 = 0)
/**
  @Summary
    Toggles the GPIO pin, RE12, using LATE12.

  @Description
    Toggles the GPIO pin, RE12, using LATE12.

  @Preconditions
    The RE12 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE12
    LED0_RE12_Toggle();
    </code>

*/
#define LED0_RE12_Toggle()           (_LATE12 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RE12.

  @Description
    Reads the value of the GPIO pin, RE12.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE12
    postValue = LED0_RE12_GetValue();
    </code>

*/
#define LED0_RE12_GetValue()         _RE12
/**
  @Summary
    Configures the GPIO pin, RE12, as an input.

  @Description
    Configures the GPIO pin, RE12, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE12 as an input
    LED0_RE12_SetDigitalInput();
    </code>

*/
#define LED0_RE12_SetDigitalInput()  (_TRISE12 = 1)
/**
  @Summary
    Configures the GPIO pin, RE12, as an output.

  @Description
    Configures the GPIO pin, RE12, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE12 as an output
    LED0_RE12_SetDigitalOutput();
    </code>

*/
#define LED0_RE12_SetDigitalOutput() (_TRISE12 = 0)
/**
  @Summary
    Sets the GPIO pin, RE13, high using LATE13.

  @Description
    Sets the GPIO pin, RE13, high using LATE13.

  @Preconditions
    The RE13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE13 high (1)
    LED1_RE13_SetHigh();
    </code>

*/
#define LED1_RE13_SetHigh()          (_LATE13 = 1)
/**
  @Summary
    Sets the GPIO pin, RE13, low using LATE13.

  @Description
    Sets the GPIO pin, RE13, low using LATE13.

  @Preconditions
    The RE13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE13 low (0)
    LED1_RE13_SetLow();
    </code>

*/
#define LED1_RE13_SetLow()           (_LATE13 = 0)
/**
  @Summary
    Toggles the GPIO pin, RE13, using LATE13.

  @Description
    Toggles the GPIO pin, RE13, using LATE13.

  @Preconditions
    The RE13 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE13
    LED1_RE13_Toggle();
    </code>

*/
#define LED1_RE13_Toggle()           (_LATE13 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RE13.

  @Description
    Reads the value of the GPIO pin, RE13.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE13
    postValue = LED1_RE13_GetValue();
    </code>

*/
#define LED1_RE13_GetValue()         _RE13
/**
  @Summary
    Configures the GPIO pin, RE13, as an input.

  @Description
    Configures the GPIO pin, RE13, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE13 as an input
    LED1_RE13_SetDigitalInput();
    </code>

*/
#define LED1_RE13_SetDigitalInput()  (_TRISE13 = 1)
/**
  @Summary
    Configures the GPIO pin, RE13, as an output.

  @Description
    Configures the GPIO pin, RE13, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE13 as an output
    LED1_RE13_SetDigitalOutput();
    </code>

*/
#define LED1_RE13_SetDigitalOutput() (_TRISE13 = 0)
/**
  @Summary
    Sets the GPIO pin, RE14, high using LATE14.

  @Description
    Sets the GPIO pin, RE14, high using LATE14.

  @Preconditions
    The RE14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE14 high (1)
    LED2_RE14_SetHigh();
    </code>

*/
#define LED2_RE14_SetHigh()          (_LATE14 = 1)
/**
  @Summary
    Sets the GPIO pin, RE14, low using LATE14.

  @Description
    Sets the GPIO pin, RE14, low using LATE14.

  @Preconditions
    The RE14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE14 low (0)
    LED2_RE14_SetLow();
    </code>

*/
#define LED2_RE14_SetLow()           (_LATE14 = 0)
/**
  @Summary
    Toggles the GPIO pin, RE14, using LATE14.

  @Description
    Toggles the GPIO pin, RE14, using LATE14.

  @Preconditions
    The RE14 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE14
    LED2_RE14_Toggle();
    </code>

*/
#define LED2_RE14_Toggle()           (_LATE14 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RE14.

  @Description
    Reads the value of the GPIO pin, RE14.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE14
    postValue = LED2_RE14_GetValue();
    </code>

*/
#define LED2_RE14_GetValue()         _RE14
/**
  @Summary
    Configures the GPIO pin, RE14, as an input.

  @Description
    Configures the GPIO pin, RE14, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE14 as an input
    LED2_RE14_SetDigitalInput();
    </code>

*/
#define LED2_RE14_SetDigitalInput()  (_TRISE14 = 1)
/**
  @Summary
    Configures the GPIO pin, RE14, as an output.

  @Description
    Configures the GPIO pin, RE14, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE14 as an output
    LED2_RE14_SetDigitalOutput();
    </code>

*/
#define LED2_RE14_SetDigitalOutput() (_TRISE14 = 0)
/**
  @Summary
    Sets the GPIO pin, RE15, high using LATE15.

  @Description
    Sets the GPIO pin, RE15, high using LATE15.

  @Preconditions
    The RE15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE15 high (1)
    LED3_RE15_SetHigh();
    </code>

*/
#define LED3_RE15_SetHigh()          (_LATE15 = 1)
/**
  @Summary
    Sets the GPIO pin, RE15, low using LATE15.

  @Description
    Sets the GPIO pin, RE15, low using LATE15.

  @Preconditions
    The RE15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Set RE15 low (0)
    LED3_RE15_SetLow();
    </code>

*/
#define LED3_RE15_SetLow()           (_LATE15 = 0)
/**
  @Summary
    Toggles the GPIO pin, RE15, using LATE15.

  @Description
    Toggles the GPIO pin, RE15, using LATE15.

  @Preconditions
    The RE15 must be set to an output.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Toggle RE15
    LED3_RE15_Toggle();
    </code>

*/
#define LED3_RE15_Toggle()           (_LATE15 ^= 1)
/**
  @Summary
    Reads the value of the GPIO pin, RE15.

  @Description
    Reads the value of the GPIO pin, RE15.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    uint16_t portValue;

    // Read RE15
    postValue = LED3_RE15_GetValue();
    </code>

*/
#define LED3_RE15_GetValue()         _RE15
/**
  @Summary
    Configures the GPIO pin, RE15, as an input.

  @Description
    Configures the GPIO pin, RE15, as an input.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE15 as an input
    LED3_RE15_SetDigitalInput();
    </code>

*/
#define LED3_RE15_SetDigitalInput()  (_TRISE15 = 1)
/**
  @Summary
    Configures the GPIO pin, RE15, as an output.

  @Description
    Configures the GPIO pin, RE15, as an output.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    // Sets the RE15 as an output
    LED3_RE15_SetDigitalOutput();
    </code>

*/
#define LED3_RE15_SetDigitalOutput() (_TRISE15 = 0)

/**
    Section: Function Prototypes
*/
/**
  @Summary
    Configures the pin settings of the dsPIC33EP128MC506
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    void SYSTEM_Initialize(void)
    {
        // Other initializers are called from this function
        PIN_MANAGER_Initialize();
    }
    </code>

*/
void PIN_MANAGER_Initialize (void);



#endif
