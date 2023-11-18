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

#ifndef _HEAVY_CONTEXT_DAISISPI_HPP_
#define _HEAVY_CONTEXT_DAISISPI_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlBinop.h"
#include "HvMath.h"
#include "HvSignalPhasor.h"
#include "HvSignalVar.h"
#include "HvControlVar.h"

class Heavy_daisiSPI : public HeavyContext {

 public:
  Heavy_daisiSPI(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_daisiSPI();

  const char *getName() override { return "daisiSPI"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cVar_wlVKX9gk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FIChmvMr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JTMczcYU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Jyn65ylg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BDSEPqyt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_syaTLOhI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PbjUu1XL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sEn9bNjH_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_RBvhg4gc;
  ControlVar cVar_wlVKX9gk;
  ControlBinop cBinop_FIChmvMr;
  ControlBinop cBinop_JTMczcYU;
  ControlBinop cBinop_Jyn65ylg;
  ControlBinop cBinop_BDSEPqyt;
  ControlBinop cBinop_PbjUu1XL;
  ControlBinop cBinop_sEn9bNjH;
};

#endif // _HEAVY_CONTEXT_DAISISPI_HPP_
