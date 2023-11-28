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

#ifndef _HEAVY_CONTEXT_FIELD_TEST_HPP_
#define _HEAVY_CONTEXT_FIELD_TEST_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlCast.h"
#include "HvControlIf.h"
#include "HvSignalVar.h"
#include "HvMath.h"
#include "HvControlVar.h"
#include "HvControlUnop.h"
#include "HvControlBinop.h"
#include "HvSignalPhasor.h"

class Heavy_field_test : public HeavyContext {

 public:
  Heavy_field_test(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_field_test();

  const char *getName() override { return "field_test"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        PADA2 = 0x955E4C4F, // PadA2
        PADA2_PRESS = 0xB9377F3C, // PadA2_press
        PADA3_PRESS = 0xCD4F78D, // PadA3_press
        PADA4_PRESS = 0xCD6E7B97, // PadA4_press
        PADA5_PRESS = 0x6DF370F6, // PadA5_press
        PADA6_PRESS = 0x5C946564, // PadA6_press
        PADA7_PRESS = 0x39F54655, // PadA7_press
        PADA8_PRESS = 0xBC7889BE, // PadA8_press
        PADB1_PRESS = 0x9F39D20, // PadB1_press
        PADB2_PRESS = 0x1D1E36FE, // PadB2_press
        PADB3_PRESS = 0xCCC2F57F, // PadB3_press
        PADB4_PRESS = 0x18C78FB9, // PadB4_press
        PADB5_PRESS = 0xF3439FEF, // PadB5_press
        PADB6_PRESS = 0xBBCE70D4, // PadB6_press
        PADB7_PRESS = 0x4867ADFF, // PadB7_press
        PADB8_PRESS = 0x24C6DDCB, // PadB8_press
        GATEIN = 0xF037DCE4, // gatein
        KNOB1 = 0x3A6EC41A, // knob1
        KNOB2 = 0x17356E1C, // knob2
        KNOB3 = 0xA28F86ED, // knob3
        KNOB4 = 0x569E2BA8, // knob4
        KNOB5 = 0x6FCE8675, // knob5
        KNOB6 = 0x340FAFE3, // knob6
        KNOB7 = 0xF48D9325, // knob7
        KNOB8 = 0x64AB52FE, // knob8
        SW1 = 0xC360BB65, // sw1
      };
    };
    struct Out {
      enum ParameterOut : hv_uint32_t {
        GATEOUT = 0x1753CB6C, // gateout
        LED_KEY_A1 = 0xEDE662C3, // led_Key_A1
        LED_KEY_A2 = 0x5DEBB39C, // led_Key_A2
        LED_KEY_A3 = 0x5CDCD3A1, // led_Key_A3
        LED_KEY_A4 = 0x8F74D5C5, // led_Key_A4
        LED_KEY_A5 = 0x9F309EDE, // led_Key_A5
        LED_KEY_A6 = 0x3B9FC2A4, // led_Key_A6
        LED_KEY_A7 = 0x5510797E, // led_Key_A7
        LED_KEY_A8 = 0xDE05590F, // led_Key_A8
        LED_KEY_B1 = 0x8C00CB5A, // led_Key_B1
        LED_KEY_B2 = 0xFE1262FC, // led_Key_B2
        LED_KEY_B3 = 0x9DB2A36B, // led_Key_B3
        LED_KEY_B4 = 0x85515E57, // led_Key_B4
        LED_KEY_B5 = 0x9AD3B48D, // led_Key_B5
        LED_KEY_B6 = 0xE0B917FB, // led_Key_B6
        LED_KEY_B7 = 0x3A4B4D50, // led_Key_B7
        LED_KEY_B8 = 0x39C4E896, // led_Key_B8
        LED_KNOB_1 = 0x4FD1D105, // led_knob_1
        LED_KNOB_2 = 0x14BEC3B4, // led_knob_2
        LED_KNOB_3 = 0xCC96B5AB, // led_knob_3
        LED_KNOB_4 = 0x4108B637, // led_knob_4
        LED_KNOB_5 = 0xF76339BD, // led_knob_5
        LED_KNOB_6 = 0xB607CD97, // led_knob_6
        LED_KNOB_7 = 0x9EBE7795, // led_knob_7
        LED_KNOB_8 = 0x42A149DC, // led_knob_8
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cVar_YbmYTOgC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ADA5LPrM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_wznNpzOt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_eGAFFi4v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_KfUQ1QrE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_SCIsnYp2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_29vvjYLq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Uq3pRUqZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GXtbTG1R_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PrwKXa1T_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YAQY9k8y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JeVCazul_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_bFWwdgHF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Cde0ldey_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_lo1ruBO6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_RadAczig_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_mjZ8wQgL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_4PwmGUFf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_qj5nnED0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_7onKY6QJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_zENzomDC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_7taqioyf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_aYGhfxY3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_KigVw01B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_z84KLhbi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_PyEekuUB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_6JbY5xRq_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_aiO6fOmP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_rdKBeXKi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_3HdHI9hY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_12XWECLg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_XeSC5JFE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_E3QHpNRc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_xTnKHpZH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_FyyfkGPO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_XaggnB9f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_zNbv5VPZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_Hkrth0wi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_hKmKUb1B_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_X25AnAsi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_F7ak9DGA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_RnFm2C62_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_7lAdtIjk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_SZd9fzJP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_5SD60qc7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_nEsK6CVu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSend_VMQfOJr7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YKIWTRh9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4SX7B7PV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ErdPBsz2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5jlAvgEM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6E6VAKzo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_OyeUDm3A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_H0dKsEJF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_489AME9M_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_MdHnhCnG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_NecYUlU0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_qZ63e64U_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_uy9f8DsV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_PJEpg0ns_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_6K6qx3uZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_hPkeL2hH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_bBmLuv0j_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_zGioJMqT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_FMIUlN32_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_fWP7YWUl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_2bs0voB5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_vTNePGO7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_O2BDMwdi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_eT3Q6dRb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_CpAz1Jgs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_G0MfzvCG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_jFf8VeEL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_R8vv5NQx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_qZF9Smpj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_R8FELewE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_diyXIAD7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_qPdW2jFA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_LBMTdGEL_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_gG39ytJg;
  ControlVar cVar_YbmYTOgC;
  ControlBinop cBinop_ADA5LPrM;
  ControlVar cVar_wznNpzOt;
  ControlIf cIf_SCIsnYp2;
  ControlBinop cBinop_29vvjYLq;
  ControlVar cVar_Uq3pRUqZ;
  ControlBinop cBinop_GXtbTG1R;
  ControlBinop cBinop_PrwKXa1T;
  ControlBinop cBinop_YAQY9k8y;
  ControlBinop cBinop_JeVCazul;
  ControlVar cVar_lo1ruBO6;
  ControlIf cIf_4PwmGUFf;
  ControlBinop cBinop_qj5nnED0;
  ControlVar cVar_7onKY6QJ;
  ControlBinop cBinop_YKIWTRh9;
  ControlBinop cBinop_ErdPBsz2;
  ControlBinop cBinop_5jlAvgEM;
  ControlBinop cBinop_6E6VAKzo;
};

#endif // _HEAVY_CONTEXT_FIELD_TEST_HPP_
