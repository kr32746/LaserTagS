/******************************************************************************

 @file board_led.h

 @brief This file contains the LED Service definitions and prototypes.

 Group: WCS LPC
 Target Device: CC13xx

 ******************************************************************************
 
 Copyright (c) 2016-2017, Texas Instruments Incorporated
 All rights reserved.

 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions
 are met:

 *  Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.

 *  Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.

 *  Neither the name of Texas Instruments Incorporated nor the names of
    its contributors may be used to endorse or promote products derived
    from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 ******************************************************************************
 Release Name: simplelink_cc13x0_sdk_1_50_00_
 Release Date: 2017-09-27 23:49:29
 *****************************************************************************/
#ifndef BOARD_LED_H
#define BOARD_LED_H

/******************************************************************************
 Includes
 *****************************************************************************/
#if !defined(COPROCESSOR)
#include "config.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/*!
 \defgroup BoardLED Board LED Functions
 <BR>
 This module is a collection of functions to control LEDs.
 <BR>
 */

/******************************************************************************
 Typedefs
 *****************************************************************************/

/*!
 * \ingroup BoardLED
 * @{
 */

/*! LED Identifications */
typedef enum
{
    board_led_type_LED1,
    board_led_type_LED2,
    board_led_type_ACTION,
#if !defined(CC13XX_LAUNCHXL) && !defined(CC26XX_LAUNCHXL) && !defined(CC26X2R1_LAUNCHXL) && !defined(CC13X2R1_LAUNCHXL)
    /* The Launchpads only have 2 LEDs */
    board_led_type_LED3,
    board_led_type_LED4,
#endif
#if defined(CC13XX_LAUNCHXL) || defined(CC13X2R1_LAUNCHXL)
    board_rfSwitch_select,
#if defined(CC13XX_LAUNCHXL) && !defined(COPROCESSOR)
#if (CONFIG_RANGE_EXT_MODE == APIMAC_NO_EXTENDER)
    board_rfSwitch_pwr,
#endif
#endif
#endif
    MAX_LEDS
} board_led_type;

/*! LED States */
typedef enum
{
    board_led_state_OFF,
    board_led_state_ON,
    board_led_state_BLINK,
    board_led_state_BLINKING,
} board_led_state;

/******************************************************************************
 API Functions
 *****************************************************************************/

/*!
 * @brief   Initialize LED System
 */
void Board_Led_initialize(void);

/*!
 * @brief   Control the state of an LED
 *
 * @param   led - Which LED
 * @param   state - control, set to board_led_state_BLINK for blink once,
 *                  set to board_led_state_BLINKING to continual blinking,
 *                  set to board_led_state_ON to turn LED on,
 *                  set to board_led_state_OFF to turn the LED off.
 */
void Board_Led_control(board_led_type led, board_led_state state);

/*!
 * @brief   Toggle the state of an LED from off to on, and from on
 *          or blinking to off.
 *
 * @param   led - Which LED
 */
void Board_Led_toggle(board_led_type led);

/*! @} end group BoardLED */


#ifdef __cplusplus
}
#endif

#endif /* BOARD_LED_H */
