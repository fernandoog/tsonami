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
#include "HvSignalPhasor.h"
#include "HvMath.h"
#include "HvControlBinop.h"
#include "HvSignalLine.h"
#include "HvSignalVar.h"
#include "HvControlCast.h"
#include "HvControlVar.h"

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
  static void cVar_zEN6VZ72_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_rH1qNzjR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_rxtNn6JW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_XC8y3sRq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_tUpAe5dv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_AefDzCDj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_3Q0llR1V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_HkznD5h9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_IgLIrdZG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_XQ9Ik22m_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_TGF0pAMg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_33wU0npv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_9XBNvVB2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_vdmCTq2l_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_A7cmsYKw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_sJb6QWvc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wP47IYfd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OjntmuhJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TGK9edh5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_oq1aBgMn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_G3cemTJj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ZsHQOo0S_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_tWAR5Ua7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_uz9WbVYc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DPK7eUeq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_F9dsJGLE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_uAFRkWPt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_cgoWOvn9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_bcLShI3B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_9oVuRln6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_JkbxJ5gp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_4wOI3jVL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_zBkmwXu1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_5mQkeuhu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_PjV7w32P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_o3hFCovO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_8Ch7LqPU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_fb4NyJtR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_SY6qUUfL_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_h2bOTV83;
  SignalPhasor sPhasor_NWNdTsg4;
  SignalLine sLine_jPhjgQdx;
  SignalPhasor sPhasor_UsWodiGr;
  SignalLine sLine_Fyf3ifqH;
  ControlVar cVar_zEN6VZ72;
  ControlVar cVar_rxtNn6JW;
  ControlVar cVar_tUpAe5dv;
  ControlVar cVar_3Q0llR1V;
  ControlVar cVar_HkznD5h9;
  ControlVar cVar_IgLIrdZG;
  ControlBinop cBinop_OjntmuhJ;
  ControlBinop cBinop_TGK9edh5;
  ControlBinop cBinop_oq1aBgMn;
  ControlBinop cBinop_tWAR5Ua7;
  ControlBinop cBinop_F9dsJGLE;
  SignalVarf sVarf_Hzn8sfHk;
  SignalVarf sVarf_JPuSWtzK;
  SignalVarf sVarf_whMtdpPs;
  SignalVarf sVarf_yRmk2ql8;
};

#endif // _HEAVY_CONTEXT_POD_TEST_HPP_
