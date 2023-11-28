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

#ifndef _HEAVY_CONTEXT_DAISY_CONTROL_HPP_
#define _HEAVY_CONTEXT_DAISY_CONTROL_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvSignalPhasor.h"
#include "HvSignalLine.h"
#include "HvControlBinop.h"
#include "HvMath.h"
#include "HvControlPrint.h"
#include "HvControlCast.h"
#include "HvSignalVar.h"
#include "HvControlVar.h"

class Heavy_daisy_control : public HeavyContext {

 public:
  Heavy_daisy_control(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_daisy_control();

  const char *getName() override { return "daisy_control"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        BUTTON1_PRESS = 0xDF1CF8D9, // button1_press
        BUTTON2 = 0x1024490E, // button2
        BUTTON2_PRESS = 0x1AE0B6E, // button2_press
        KNOB2 = 0x17356E1C, // knob2
      };
    };
    struct Out {
      enum ParameterOut : hv_uint32_t {
        LED1 = 0xE817C68D, // led1
        LED2 = 0xBB2E5490, // led2
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cVar_grWCaW4p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_6HZcNku4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ZwMOhwtf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_2KN9EZg0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_RODCYcPN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_hLaZLRRk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YWAl0xbV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_Wk1oeKzk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_mqPUqI12_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_hHKhPdyW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_4rnrgOtS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_ZRbF8LzW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_HJqiPwC4_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_z5fj0JKi;
  SignalLine sLine_VXL0ae3m;
  ControlVar cVar_grWCaW4p;
  ControlBinop cBinop_YWAl0xbV;
  SignalVarf sVarf_FH8hpn3Y;
};

#endif // _HEAVY_CONTEXT_DAISY_CONTROL_HPP_
