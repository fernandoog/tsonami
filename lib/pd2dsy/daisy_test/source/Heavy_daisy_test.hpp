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

#ifndef _HEAVY_CONTEXT_DAISY_TEST_HPP_
#define _HEAVY_CONTEXT_DAISY_TEST_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalLine.h"
#include "HvMath.h"
#include "HvSignalVar.h"
#include "HvSignalPhasor.h"
#include "HvControlCast.h"

class Heavy_daisy_test : public HeavyContext {

 public:
  Heavy_daisy_test(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_daisy_test();

  const char *getName() override { return "daisy_test"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        BUTTON1 = 0xB4D78F23, // Button1
        BUTTON1_PRESS = 0xDF1CF8D9, // button1_press
      };
    };
    struct Out {
      enum ParameterOut : hv_uint32_t {
        LED1 = 0xE817C68D, // led1
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cCast_yuY6EDDV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_S0Z9orvR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_tDc5eoD3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_t53MKYnM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Ba9bZcqo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_rgBbgxJU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_7xHu3YUg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_IuXCJmv9_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalLine sLine_eoBqmSRh;
  SignalPhasor sPhasor_ekEOoNSX;
  SignalLine sLine_nnAJjF75;
};

#endif // _HEAVY_CONTEXT_DAISY_TEST_HPP_
