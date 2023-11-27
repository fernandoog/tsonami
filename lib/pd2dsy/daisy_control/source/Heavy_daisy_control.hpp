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
#include "HvMath.h"
#include "HvSignalVar.h"
#include "HvControlVar.h"
#include "HvSignalLine.h"
#include "HvSignalPhasor.h"
#include "HvControlBinop.h"
#include "HvControlCast.h"

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
        BUTTON1 = 0xB4D78F23, // Button1
        KNOB1 = 0x62DD3F82, // Knob1
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
  static void cVar_DU4on1I1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_EW6MIK6f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_fMyvlf5T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ODSNRTUG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_QGZtihvE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_oio2xWTw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NTrFVKv8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_QzJYLzd5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_uJq0jSAk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Ahhwyyym_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_7O7uFTyH_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_nBlKNgpF;
  SignalLine sLine_hLDlSdkD;
  ControlVar cVar_DU4on1I1;
  ControlBinop cBinop_NTrFVKv8;
  SignalVarf sVarf_UGQZDSRt;
};

#endif // _HEAVY_CONTEXT_DAISY_CONTROL_HPP_
