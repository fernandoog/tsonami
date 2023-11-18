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
#include "HvSignalPhasor.h"
#include "HvControlBinop.h"
#include "HvControlVar.h"
#include "HvMath.h"
#include "HvSignalVar.h"

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
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        KNOB1 = 0x62DD3F82, // Knob1
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cVar_DIqzVykw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MEz212Sn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9tgexxaL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_cVMQ3N8E_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BzESbFyY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_QFP3OwrQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Yr7OuWjN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jxrOJ5uQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_uYdQ0ceK_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_sK07CGnQ;
  ControlVar cVar_DIqzVykw;
  ControlBinop cBinop_MEz212Sn;
  ControlBinop cBinop_9tgexxaL;
  ControlBinop cBinop_cVMQ3N8E;
  ControlBinop cBinop_BzESbFyY;
  ControlBinop cBinop_Yr7OuWjN;
  ControlBinop cBinop_jxrOJ5uQ;
};

#endif // _HEAVY_CONTEXT_DAISISPI_HPP_
