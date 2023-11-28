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

#ifndef _HEAVY_CONTEXT_PATCH_INIT_TEST_HPP_
#define _HEAVY_CONTEXT_PATCH_INIT_TEST_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlCast.h"
#include "HvSignalLine.h"
#include "HvSignalVar.h"
#include "HvMath.h"
#include "HvControlBinop.h"
#include "HvSignalPhasor.h"

class Heavy_patch_init_test : public HeavyContext {

 public:
  Heavy_patch_init_test(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_patch_init_test();

  const char *getName() override { return "patch_init_test"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        CTRL1 = 0xCFD93C2D, // Ctrl1
        CTRL2 = 0xA6D27094, // Ctrl2
        CTRL3 = 0xB00C3479, // Ctrl3
        CTRL4 = 0x4BA4C205, // Ctrl4
        GATE1 = 0x378CB51F, // Gate1
        GATE1_TRIG = 0xDA902E89, // Gate1_Trig
        GATE2 = 0x8924DDEB, // Gate2
        CV_5 = 0x14031CB1, // cv_5
      };
    };
    struct Out {
      enum ParameterOut : hv_uint32_t {
        GATEOUT1 = 0x7B142873, // GateOut1
        GATEOUT2 = 0xA1808D49, // GateOut2
        CVOUT1 = 0x28359A74, // cvout1
        CVOUT2 = 0x1847749, // cvout2
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cBinop_YZiGzXE3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_B4KJ1byD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RbwkohBt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Pl30kMEo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_p4a3qfYf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sE3K0xr1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9sRmYio1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_xAej96xq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_tfIYbVY6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_3Sgl3ZUv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_9rQEFzca_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_DQItvtP3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LtiX8qRc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_SKAazQ9Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_93ijzxP5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_ypzPcZvr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_iKd26sbI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_j8l7B2aa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Rq52kwkL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_nWQ51Zv1_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_OPWM8fP7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_MoppfghN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_5IyvTUEy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_qyXvXhTC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_DAeZfGPS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_L2fnr8pg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_McSbLp1i_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_n3qmE4bC;
  SignalLine sLine_u1hQJ3NN;
  ControlBinop cBinop_YZiGzXE3;
  ControlBinop cBinop_B4KJ1byD;
  ControlBinop cBinop_RbwkohBt;
  ControlBinop cBinop_Pl30kMEo;
  ControlBinop cBinop_sE3K0xr1;
  ControlBinop cBinop_9sRmYio1;
  ControlBinop cBinop_DQItvtP3;
  ControlBinop cBinop_LtiX8qRc;
  ControlBinop cBinop_j8l7B2aa;
  ControlBinop cBinop_Rq52kwkL;
  SignalVarf sVarf_NTUaZKtI;
  SignalVarf sVarf_2be6C8IA;
};

#endif // _HEAVY_CONTEXT_PATCH_INIT_TEST_HPP_
