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

#ifndef _HEAVY_CONTEXT_POD_TEST_HPP_
#define _HEAVY_CONTEXT_POD_TEST_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlCast.h"
#include "HvSignalLine.h"
#include "HvSignalVar.h"
#include "HvMath.h"
#include "HvControlVar.h"
#include "HvControlBinop.h"
#include "HvSignalPhasor.h"

class Heavy_pod_test : public HeavyContext {

 public:
  Heavy_pod_test(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_pod_test();

  const char *getName() override { return "pod_test"; }
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
        BUTTON2 = 0x3FE62CA, // Button2
        ENCSWITCH = 0x7AAC371F, // EncSwitch
        ENCODER = 0x39ADE514, // Encoder
        KNOB1 = 0x62DD3F82, // Knob1
        KNOB2 = 0x6BE4E001, // Knob2
        BUTTON1_PRESS = 0xDF1CF8D9, // button1_press
        BUTTON2_PRESS = 0x1AE0B6E, // button2_press
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
  static void cVar_8gWUgCZb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_hGDG013f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_4W8Wppjj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_fpdZ19SK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_GxqMMMRS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_O6AsKRqH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_xCJmEwcm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_wDaSk0M4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_DmLwS3Iy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_TXf94mwo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_IPrXixXu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_eCXiKyqK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ndhWVK0S_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ZWjugWaD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_f5bConR4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_xLBqOJzv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_WOUAjjcV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_r7c77W2I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wWt1lrXw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6yPV0tPL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2iqD23wl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_cj45nEip_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_IJpJ5Exl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DB3l5mlM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2n55thNf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_IrAT2ps6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_xuqlQId9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_zrdD00Dn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_LbX6uWaQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_eY0gGriQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_vTmYvqM0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_CNlk6TOz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_1HbAqfRg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_DQasqTIP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_erBbvhh8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_1jGpw6Jk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_JgOHvvHh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_vY9RqCRW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_GQejqsHP_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_Iu8rdcTM;
  SignalPhasor sPhasor_tT5PNJ9o;
  SignalLine sLine_Db1MT7ba;
  SignalPhasor sPhasor_EyzftYko;
  SignalLine sLine_qODZ43F2;
  ControlVar cVar_8gWUgCZb;
  ControlVar cVar_4W8Wppjj;
  ControlVar cVar_GxqMMMRS;
  ControlVar cVar_xCJmEwcm;
  ControlVar cVar_wDaSk0M4;
  ControlVar cVar_DmLwS3Iy;
  ControlBinop cBinop_r7c77W2I;
  ControlBinop cBinop_wWt1lrXw;
  ControlBinop cBinop_6yPV0tPL;
  ControlBinop cBinop_IJpJ5Exl;
  ControlBinop cBinop_IrAT2ps6;
  SignalVarf sVarf_JQcYNSRV;
  SignalVarf sVarf_BF6xo4Yi;
  SignalVarf sVarf_NLAVTbQ9;
  SignalVarf sVarf_RO8mgcjg;
};

#endif // _HEAVY_CONTEXT_POD_TEST_HPP_
