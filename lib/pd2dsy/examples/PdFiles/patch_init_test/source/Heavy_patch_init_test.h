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

#ifndef _HEAVY_PATCH_INIT_TEST_H_
#define _HEAVY_PATCH_INIT_TEST_H_

#include "HvHeavy.h"

#ifdef __cplusplus
extern "C" {
#endif

#if HV_APPLE
#pragma mark - Heavy Context
#endif

typedef enum {
  HV_PATCH_INIT_TEST_PARAM_IN_CTRL1 = 0xCFD93C2D, // Ctrl1
  HV_PATCH_INIT_TEST_PARAM_IN_CTRL2 = 0xA6D27094, // Ctrl2
  HV_PATCH_INIT_TEST_PARAM_IN_CTRL3 = 0xB00C3479, // Ctrl3
  HV_PATCH_INIT_TEST_PARAM_IN_CTRL4 = 0x4BA4C205, // Ctrl4
  HV_PATCH_INIT_TEST_PARAM_IN_GATE1 = 0x378CB51F, // Gate1
  HV_PATCH_INIT_TEST_PARAM_IN_GATE1_TRIG = 0xDA902E89, // Gate1_Trig
  HV_PATCH_INIT_TEST_PARAM_IN_GATE2 = 0x8924DDEB, // Gate2
  HV_PATCH_INIT_TEST_PARAM_IN_CV_5 = 0x14031CB1, // cv_5
} Hv_patch_init_test_ParameterIn;

typedef enum {
  HV_PATCH_INIT_TEST_PARAM_OUT_GATEOUT1 = 0x7B142873, // GateOut1
  HV_PATCH_INIT_TEST_PARAM_OUT_GATEOUT2 = 0xA1808D49, // GateOut2
  HV_PATCH_INIT_TEST_PARAM_OUT_CVOUT1 = 0x28359A74, // cvout1
  HV_PATCH_INIT_TEST_PARAM_OUT_CVOUT2 = 0x1847749, // cvout2
} Hv_patch_init_test_ParameterOut;


/**
 * Creates a new patch instance.
 * Sample rate should be positive and in Hertz, e.g. 44100.0.
 */
HeavyContextInterface *hv_patch_init_test_new(double sampleRate);

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
HeavyContextInterface *hv_patch_init_test_new_with_options(double sampleRate, int poolKb, int inQueueKb, int outQueueKb);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // _HEAVY_PATCH_INIT_TEST_H_
