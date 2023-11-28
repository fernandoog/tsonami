/**
 * Copyright (c) 2023 Enzien Audio, Ltd.
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 * 
 * 2. Redistributions in binary form must reproduce the phrase "powered by heavy",
 *    the heavy logo, and a hyperlink to https://enzienaudio.com, all in a visible
 *    form.
 * 
 *   2.1 If the Application is distributed in a store system (for example,
 *       the Apple "App Store" or "Google Play"), the phrase "powered by heavy"
 *       shall be included in the app description or the copyright text as well as
 *       the in the app itself. The heavy logo will shall be visible in the app
 *       itself as well.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef _HEAVY_FIELD_TEST_H_
#define _HEAVY_FIELD_TEST_H_

#include "HvHeavy.h"

#ifdef __cplusplus
extern "C" {
#endif

#if HV_APPLE
#pragma mark - Heavy Context
#endif

typedef enum {
  HV_FIELD_TEST_PARAM_IN_PADA2 = 0x955E4C4F, // PadA2
  HV_FIELD_TEST_PARAM_IN_PADA2_PRESS = 0xB9377F3C, // PadA2_press
  HV_FIELD_TEST_PARAM_IN_PADA3_PRESS = 0xCD4F78D, // PadA3_press
  HV_FIELD_TEST_PARAM_IN_PADA4_PRESS = 0xCD6E7B97, // PadA4_press
  HV_FIELD_TEST_PARAM_IN_PADA5_PRESS = 0x6DF370F6, // PadA5_press
  HV_FIELD_TEST_PARAM_IN_PADA6_PRESS = 0x5C946564, // PadA6_press
  HV_FIELD_TEST_PARAM_IN_PADA7_PRESS = 0x39F54655, // PadA7_press
  HV_FIELD_TEST_PARAM_IN_PADA8_PRESS = 0xBC7889BE, // PadA8_press
  HV_FIELD_TEST_PARAM_IN_PADB1_PRESS = 0x9F39D20, // PadB1_press
  HV_FIELD_TEST_PARAM_IN_PADB2_PRESS = 0x1D1E36FE, // PadB2_press
  HV_FIELD_TEST_PARAM_IN_PADB3_PRESS = 0xCCC2F57F, // PadB3_press
  HV_FIELD_TEST_PARAM_IN_PADB4_PRESS = 0x18C78FB9, // PadB4_press
  HV_FIELD_TEST_PARAM_IN_PADB5_PRESS = 0xF3439FEF, // PadB5_press
  HV_FIELD_TEST_PARAM_IN_PADB6_PRESS = 0xBBCE70D4, // PadB6_press
  HV_FIELD_TEST_PARAM_IN_PADB7_PRESS = 0x4867ADFF, // PadB7_press
  HV_FIELD_TEST_PARAM_IN_PADB8_PRESS = 0x24C6DDCB, // PadB8_press
  HV_FIELD_TEST_PARAM_IN_GATEIN = 0xF037DCE4, // gatein
  HV_FIELD_TEST_PARAM_IN_KNOB1 = 0x3A6EC41A, // knob1
  HV_FIELD_TEST_PARAM_IN_KNOB2 = 0x17356E1C, // knob2
  HV_FIELD_TEST_PARAM_IN_KNOB3 = 0xA28F86ED, // knob3
  HV_FIELD_TEST_PARAM_IN_KNOB4 = 0x569E2BA8, // knob4
  HV_FIELD_TEST_PARAM_IN_KNOB5 = 0x6FCE8675, // knob5
  HV_FIELD_TEST_PARAM_IN_KNOB6 = 0x340FAFE3, // knob6
  HV_FIELD_TEST_PARAM_IN_KNOB7 = 0xF48D9325, // knob7
  HV_FIELD_TEST_PARAM_IN_KNOB8 = 0x64AB52FE, // knob8
  HV_FIELD_TEST_PARAM_IN_SW1 = 0xC360BB65, // sw1
} Hv_field_test_ParameterIn;

typedef enum {
  HV_FIELD_TEST_PARAM_OUT_GATEOUT = 0x1753CB6C, // gateout
  HV_FIELD_TEST_PARAM_OUT_LED_KEY_A1 = 0xEDE662C3, // led_Key_A1
  HV_FIELD_TEST_PARAM_OUT_LED_KEY_A2 = 0x5DEBB39C, // led_Key_A2
  HV_FIELD_TEST_PARAM_OUT_LED_KEY_A3 = 0x5CDCD3A1, // led_Key_A3
  HV_FIELD_TEST_PARAM_OUT_LED_KEY_A4 = 0x8F74D5C5, // led_Key_A4
  HV_FIELD_TEST_PARAM_OUT_LED_KEY_A5 = 0x9F309EDE, // led_Key_A5
  HV_FIELD_TEST_PARAM_OUT_LED_KEY_A6 = 0x3B9FC2A4, // led_Key_A6
  HV_FIELD_TEST_PARAM_OUT_LED_KEY_A7 = 0x5510797E, // led_Key_A7
  HV_FIELD_TEST_PARAM_OUT_LED_KEY_A8 = 0xDE05590F, // led_Key_A8
  HV_FIELD_TEST_PARAM_OUT_LED_KEY_B1 = 0x8C00CB5A, // led_Key_B1
  HV_FIELD_TEST_PARAM_OUT_LED_KEY_B2 = 0xFE1262FC, // led_Key_B2
  HV_FIELD_TEST_PARAM_OUT_LED_KEY_B3 = 0x9DB2A36B, // led_Key_B3
  HV_FIELD_TEST_PARAM_OUT_LED_KEY_B4 = 0x85515E57, // led_Key_B4
  HV_FIELD_TEST_PARAM_OUT_LED_KEY_B5 = 0x9AD3B48D, // led_Key_B5
  HV_FIELD_TEST_PARAM_OUT_LED_KEY_B6 = 0xE0B917FB, // led_Key_B6
  HV_FIELD_TEST_PARAM_OUT_LED_KEY_B7 = 0x3A4B4D50, // led_Key_B7
  HV_FIELD_TEST_PARAM_OUT_LED_KEY_B8 = 0x39C4E896, // led_Key_B8
  HV_FIELD_TEST_PARAM_OUT_LED_KNOB_1 = 0x4FD1D105, // led_knob_1
  HV_FIELD_TEST_PARAM_OUT_LED_KNOB_2 = 0x14BEC3B4, // led_knob_2
  HV_FIELD_TEST_PARAM_OUT_LED_KNOB_3 = 0xCC96B5AB, // led_knob_3
  HV_FIELD_TEST_PARAM_OUT_LED_KNOB_4 = 0x4108B637, // led_knob_4
  HV_FIELD_TEST_PARAM_OUT_LED_KNOB_5 = 0xF76339BD, // led_knob_5
  HV_FIELD_TEST_PARAM_OUT_LED_KNOB_6 = 0xB607CD97, // led_knob_6
  HV_FIELD_TEST_PARAM_OUT_LED_KNOB_7 = 0x9EBE7795, // led_knob_7
  HV_FIELD_TEST_PARAM_OUT_LED_KNOB_8 = 0x42A149DC, // led_knob_8
} Hv_field_test_ParameterOut;


/**
 * Creates a new patch instance.
 * Sample rate should be positive and in Hertz, e.g. 44100.0.
 */
HeavyContextInterface *hv_field_test_new(double sampleRate);

/**
 * Creates a new patch instance.
 * @param sampleRate  Sample rate should be positive (> 0) and in Hertz, e.g. 48000.0.
 * @param poolKb  Pool size is in kilobytes, and determines the maximum amount of memory
 *   allocated to messages at any time. By default this is 10 KB.
 * @param inQueueKb  The size of the input message queue in kilobytes. It determines the
 *   amount of memory dedicated to holding scheduled messages between calls to
 *   process(). Default is 2 KB.
 * @param outQueueKb  The size of the output message queue in kilobytes. It determines the
 *   amount of memory dedicated to holding scheduled messages to the default sendHook.
 *   See getNextSentMessage() for info on accessing these messages. Default is 0 KB.
 */
HeavyContextInterface *hv_field_test_new_with_options(double sampleRate, int poolKb, int inQueueKb, int outQueueKb);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // _HEAVY_FIELD_TEST_H_
