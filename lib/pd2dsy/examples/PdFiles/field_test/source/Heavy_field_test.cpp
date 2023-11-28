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

#include "Heavy_field_test.hpp"

#define Context(_c) reinterpret_cast<Heavy_field_test *>(_c)



/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_field_test_new(double sampleRate) {
    return new Heavy_field_test(sampleRate);
  }

  HV_EXPORT HeavyContextInterface *hv_field_test_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    return new Heavy_field_test(sampleRate, poolKb, inQueueKb, outQueueKb);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_field_test::Heavy_field_test(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_gG39ytJg, 440.0f, sampleRate);
  numBytes += cVar_init_f(&cVar_YbmYTOgC, 1.0f);
  numBytes += cVar_init_f(&cVar_wznNpzOt, 1.0f);
  numBytes += cIf_init(&cIf_SCIsnYp2, true);
  numBytes += cVar_init_f(&cVar_Uq3pRUqZ, 0.0f);
  numBytes += cBinop_init(&cBinop_JeVCazul, 1.0f); // __pow
  numBytes += cVar_init_f(&cVar_lo1ruBO6, 1.0f);
  numBytes += cIf_init(&cIf_4PwmGUFf, true);
  numBytes += cVar_init_f(&cVar_7onKY6QJ, 0.0f);
  
}

Heavy_field_test::~Heavy_field_test() {
  // nothing to free
}

HvTable *Heavy_field_test::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_field_test::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0x955E4C4F: { // PadA2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_LBMTdGEL_sendMessage);
      break;
    }
    case 0xB9377F3C: { // PadA2_press
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qPdW2jFA_sendMessage);
      break;
    }
    case 0xCD4F78D: { // PadA3_press
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_bBmLuv0j_sendMessage);
      break;
    }
    case 0xCD6E7B97: { // PadA4_press
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_zGioJMqT_sendMessage);
      break;
    }
    case 0x6DF370F6: { // PadA5_press
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_FMIUlN32_sendMessage);
      break;
    }
    case 0x5C946564: { // PadA6_press
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_fWP7YWUl_sendMessage);
      break;
    }
    case 0x39F54655: { // PadA7_press
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_2bs0voB5_sendMessage);
      break;
    }
    case 0xBC7889BE: { // PadA8_press
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_vTNePGO7_sendMessage);
      break;
    }
    case 0x9F39D20: { // PadB1_press
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_O2BDMwdi_sendMessage);
      break;
    }
    case 0x1D1E36FE: { // PadB2_press
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_H0dKsEJF_sendMessage);
      break;
    }
    case 0xCCC2F57F: { // PadB3_press
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_CpAz1Jgs_sendMessage);
      break;
    }
    case 0x18C78FB9: { // PadB4_press
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_eT3Q6dRb_sendMessage);
      break;
    }
    case 0xF3439FEF: { // PadB5_press
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_G0MfzvCG_sendMessage);
      break;
    }
    case 0xBBCE70D4: { // PadB6_press
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_jFf8VeEL_sendMessage);
      break;
    }
    case 0x4867ADFF: { // PadB7_press
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_R8vv5NQx_sendMessage);
      break;
    }
    case 0x24C6DDCB: { // PadB8_press
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qZF9Smpj_sendMessage);
      break;
    }
    case 0xF037DCE4: { // gatein
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_R8FELewE_sendMessage);
      break;
    }
    case 0x3A6EC41A: { // knob1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_489AME9M_sendMessage);
      break;
    }
    case 0x17356E1C: { // knob2
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_MdHnhCnG_sendMessage);
      break;
    }
    case 0xA28F86ED: { // knob3
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_NecYUlU0_sendMessage);
      break;
    }
    case 0x569E2BA8: { // knob4
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_qZ63e64U_sendMessage);
      break;
    }
    case 0x6FCE8675: { // knob5
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_uy9f8DsV_sendMessage);
      break;
    }
    case 0x340FAFE3: { // knob6
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_PJEpg0ns_sendMessage);
      break;
    }
    case 0xF48D9325: { // knob7
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_6K6qx3uZ_sendMessage);
      break;
    }
    case 0x64AB52FE: { // knob8
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_hPkeL2hH_sendMessage);
      break;
    }
    case 0xC360BB65: { // sw1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_diyXIAD7_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_field_test::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "PadA2";
        info->hash = 0x955E4C4F;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 1: {
        info->name = "PadA2_press";
        info->hash = 0xB9377F3C;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 2: {
        info->name = "PadA3_press";
        info->hash = 0xCD4F78D;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 3: {
        info->name = "PadA4_press";
        info->hash = 0xCD6E7B97;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 4: {
        info->name = "PadA5_press";
        info->hash = 0x6DF370F6;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 5: {
        info->name = "PadA6_press";
        info->hash = 0x5C946564;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 6: {
        info->name = "PadA7_press";
        info->hash = 0x39F54655;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 7: {
        info->name = "PadA8_press";
        info->hash = 0xBC7889BE;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 8: {
        info->name = "PadB1_press";
        info->hash = 0x9F39D20;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 9: {
        info->name = "PadB2_press";
        info->hash = 0x1D1E36FE;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 10: {
        info->name = "PadB3_press";
        info->hash = 0xCCC2F57F;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 11: {
        info->name = "PadB4_press";
        info->hash = 0x18C78FB9;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 12: {
        info->name = "PadB5_press";
        info->hash = 0xF3439FEF;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 13: {
        info->name = "PadB6_press";
        info->hash = 0xBBCE70D4;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 14: {
        info->name = "PadB7_press";
        info->hash = 0x4867ADFF;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 15: {
        info->name = "PadB8_press";
        info->hash = 0x24C6DDCB;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 16: {
        info->name = "gatein";
        info->hash = 0xF037DCE4;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 17: {
        info->name = "knob1";
        info->hash = 0x3A6EC41A;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 18: {
        info->name = "knob2";
        info->hash = 0x17356E1C;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 19: {
        info->name = "knob3";
        info->hash = 0xA28F86ED;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 20: {
        info->name = "knob4";
        info->hash = 0x569E2BA8;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 21: {
        info->name = "knob5";
        info->hash = 0x6FCE8675;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 22: {
        info->name = "knob6";
        info->hash = 0x340FAFE3;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 23: {
        info->name = "knob7";
        info->hash = 0xF48D9325;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 24: {
        info->name = "knob8";
        info->hash = 0x64AB52FE;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 25: {
        info->name = "sw1";
        info->hash = 0xC360BB65;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      default: {
        info->name = "invalid parameter index";
        info->hash = 0;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 0.0f;
        info->defaultVal = 0.0f;
        break;
      }
    }
  }
  return 26;
}



/*
 * Send Function Implementations
 */


void Heavy_field_test::cVar_YbmYTOgC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_ADA5LPrM_sendMessage);
  cSend_VMQfOJr7_sendMessage(_c, 0, m);
}

void Heavy_field_test::cBinop_ADA5LPrM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YbmYTOgC, 1, m, &cVar_YbmYTOgC_sendMessage);
}

void Heavy_field_test::cVar_wznNpzOt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_29vvjYLq_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_SCIsnYp2, 0, m, &cIf_SCIsnYp2_sendMessage);
}

void Heavy_field_test::cUnop_eGAFFi4v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_YKIWTRh9_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 7.0f, 0, m, &cBinop_4SX7B7PV_sendMessage);
}

void Heavy_field_test::cUnop_KfUQ1QrE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_YKIWTRh9_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 7.0f, 0, m, &cBinop_4SX7B7PV_sendMessage);
}

void Heavy_field_test::cIf_SCIsnYp2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_KfUQ1QrE_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_eGAFFi4v_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_field_test::cBinop_29vvjYLq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_SCIsnYp2, 1, m, &cIf_SCIsnYp2_sendMessage);
}

void Heavy_field_test::cVar_Uq3pRUqZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_5jlAvgEM_sendMessage);
}

void Heavy_field_test::cBinop_GXtbTG1R_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_gG39ytJg, 0, m);
}

void Heavy_field_test::cBinop_PrwKXa1T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 12.0f, 0, m, &cBinop_YAQY9k8y_sendMessage);
}

void Heavy_field_test::cBinop_YAQY9k8y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JeVCazul, HV_BINOP_POW, 1, m, &cBinop_JeVCazul_sendMessage);
  cMsg_bFWwdgHF_sendMessage(_c, 0, m);
}

void Heavy_field_test::cBinop_JeVCazul_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 440.0f, 0, m, &cBinop_GXtbTG1R_sendMessage);
}

void Heavy_field_test::cMsg_bFWwdgHF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 2.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JeVCazul, HV_BINOP_POW, 0, m, &cBinop_JeVCazul_sendMessage);
}

void Heavy_field_test::cCast_Cde0ldey_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wznNpzOt, 0, m, &cVar_wznNpzOt_sendMessage);
}

void Heavy_field_test::cVar_lo1ruBO6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_qj5nnED0_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_4PwmGUFf, 0, m, &cIf_4PwmGUFf_sendMessage);
}

void Heavy_field_test::cUnop_RadAczig_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_6E6VAKzo_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 2.0f, 0, m, &cBinop_OyeUDm3A_sendMessage);
}

void Heavy_field_test::cUnop_mjZ8wQgL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_6E6VAKzo_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MOD_BIPOLAR, 2.0f, 0, m, &cBinop_OyeUDm3A_sendMessage);
}

void Heavy_field_test::cIf_4PwmGUFf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_mjZ8wQgL_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_RadAczig_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_field_test::cBinop_qj5nnED0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_4PwmGUFf, 1, m, &cIf_4PwmGUFf_sendMessage);
}

void Heavy_field_test::cVar_7onKY6QJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_3HdHI9hY_sendMessage(_c, 0, m);
}

void Heavy_field_test::cSend_zENzomDC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led_Key_B2", 0xFE1262FC, m);
}

void Heavy_field_test::cSend_7taqioyf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led_knob_1", 0x4FD1D105, m);
}

void Heavy_field_test::cSend_aYGhfxY3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led_knob_2", 0x14BEC3B4, m);
}

void Heavy_field_test::cSend_KigVw01B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led_knob_3", 0xCC96B5AB, m);
}

void Heavy_field_test::cSend_z84KLhbi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led_knob_4", 0x4108B637, m);
}

void Heavy_field_test::cSend_PyEekuUB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led_knob_5", 0xF76339BD, m);
}

void Heavy_field_test::cSend_6JbY5xRq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led_knob_6", 0xB607CD97, m);
}

void Heavy_field_test::cSend_aiO6fOmP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led_knob_7", 0x9EBE7795, m);
}

void Heavy_field_test::cSend_rdKBeXKi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led_knob_8", 0x42A149DC, m);
}

void Heavy_field_test::cSend_3HdHI9hY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led_Key_A1", 0xEDE662C3, m);
}

void Heavy_field_test::cSend_12XWECLg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led_Key_A2", 0x5DEBB39C, m);
}

void Heavy_field_test::cSend_XeSC5JFE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led_Key_A3", 0x5CDCD3A1, m);
}

void Heavy_field_test::cSend_E3QHpNRc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led_Key_A4", 0x8F74D5C5, m);
}

void Heavy_field_test::cSend_xTnKHpZH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led_Key_A5", 0x9F309EDE, m);
}

void Heavy_field_test::cSend_FyyfkGPO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led_Key_A6", 0x3B9FC2A4, m);
}

void Heavy_field_test::cSend_XaggnB9f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led_Key_A7", 0x5510797E, m);
}

void Heavy_field_test::cSend_zNbv5VPZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led_Key_A8", 0xDE05590F, m);
}

void Heavy_field_test::cSend_Hkrth0wi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led_Key_B1", 0x8C00CB5A, m);
}

void Heavy_field_test::cSend_hKmKUb1B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led_Key_B2", 0xFE1262FC, m);
}

void Heavy_field_test::cSend_X25AnAsi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led_Key_B3", 0x9DB2A36B, m);
}

void Heavy_field_test::cSend_F7ak9DGA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led_Key_B4", 0x85515E57, m);
}

void Heavy_field_test::cSend_RnFm2C62_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led_Key_B5", 0x9AD3B48D, m);
}

void Heavy_field_test::cSend_7lAdtIjk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led_Key_B6", 0xE0B917FB, m);
}

void Heavy_field_test::cSend_SZd9fzJP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led_Key_B7", 0x3A4B4D50, m);
}

void Heavy_field_test::cSend_5SD60qc7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "led_Key_B8", 0x39C4E896, m);
}

void Heavy_field_test::cSend_nEsK6CVu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "gateout", 0x1753CB6C, m);
}

void Heavy_field_test::cSend_VMQfOJr7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  if (_c->getSendHook() != nullptr) _c->getSendHook()(_c, "gateout", 0x1753CB6C, m);
}

void Heavy_field_test::cBinop_YKIWTRh9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wznNpzOt, 1, m, &cVar_wznNpzOt_sendMessage);
}

void Heavy_field_test::cBinop_4SX7B7PV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Uq3pRUqZ, 0, m, &cVar_Uq3pRUqZ_sendMessage);
}

void Heavy_field_test::cBinop_ErdPBsz2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_SUBTRACT, 69.0f, 0, m, &cBinop_PrwKXa1T_sendMessage);
}

void Heavy_field_test::cBinop_5jlAvgEM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 60.0f, 0, m, &cBinop_ErdPBsz2_sendMessage);
}

void Heavy_field_test::cBinop_6E6VAKzo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lo1ruBO6, 1, m, &cVar_lo1ruBO6_sendMessage);
}

void Heavy_field_test::cBinop_OyeUDm3A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_7onKY6QJ, 0, m, &cVar_7onKY6QJ_sendMessage);
}

void Heavy_field_test::cReceive_H0dKsEJF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_zENzomDC_sendMessage(_c, 0, m);
  cSend_hKmKUb1B_sendMessage(_c, 0, m);
}

void Heavy_field_test::cReceive_489AME9M_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_7taqioyf_sendMessage(_c, 0, m);
}

void Heavy_field_test::cReceive_MdHnhCnG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_aYGhfxY3_sendMessage(_c, 0, m);
}

void Heavy_field_test::cReceive_NecYUlU0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_KigVw01B_sendMessage(_c, 0, m);
}

void Heavy_field_test::cReceive_qZ63e64U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_z84KLhbi_sendMessage(_c, 0, m);
}

void Heavy_field_test::cReceive_uy9f8DsV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_PyEekuUB_sendMessage(_c, 0, m);
}

void Heavy_field_test::cReceive_PJEpg0ns_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_6JbY5xRq_sendMessage(_c, 0, m);
}

void Heavy_field_test::cReceive_6K6qx3uZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_aiO6fOmP_sendMessage(_c, 0, m);
}

void Heavy_field_test::cReceive_hPkeL2hH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_rdKBeXKi_sendMessage(_c, 0, m);
}

void Heavy_field_test::cReceive_bBmLuv0j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_XeSC5JFE_sendMessage(_c, 0, m);
}

void Heavy_field_test::cReceive_zGioJMqT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_E3QHpNRc_sendMessage(_c, 0, m);
}

void Heavy_field_test::cReceive_FMIUlN32_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_xTnKHpZH_sendMessage(_c, 0, m);
}

void Heavy_field_test::cReceive_fWP7YWUl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_FyyfkGPO_sendMessage(_c, 0, m);
}

void Heavy_field_test::cReceive_2bs0voB5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_XaggnB9f_sendMessage(_c, 0, m);
}

void Heavy_field_test::cReceive_vTNePGO7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_zNbv5VPZ_sendMessage(_c, 0, m);
}

void Heavy_field_test::cReceive_O2BDMwdi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_Hkrth0wi_sendMessage(_c, 0, m);
}

void Heavy_field_test::cReceive_eT3Q6dRb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_F7ak9DGA_sendMessage(_c, 0, m);
}

void Heavy_field_test::cReceive_CpAz1Jgs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_X25AnAsi_sendMessage(_c, 0, m);
}

void Heavy_field_test::cReceive_G0MfzvCG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_RnFm2C62_sendMessage(_c, 0, m);
}

void Heavy_field_test::cReceive_jFf8VeEL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_7lAdtIjk_sendMessage(_c, 0, m);
}

void Heavy_field_test::cReceive_R8vv5NQx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_SZd9fzJP_sendMessage(_c, 0, m);
}

void Heavy_field_test::cReceive_qZF9Smpj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_5SD60qc7_sendMessage(_c, 0, m);
}

void Heavy_field_test::cReceive_R8FELewE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_nEsK6CVu_sendMessage(_c, 0, m);
}

void Heavy_field_test::cReceive_diyXIAD7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YbmYTOgC, 0, m, &cVar_YbmYTOgC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wznNpzOt, 0, m, &cVar_wznNpzOt_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lo1ruBO6, 0, m, &cVar_lo1ruBO6_sendMessage);
}

void Heavy_field_test::cReceive_qPdW2jFA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSend_12XWECLg_sendMessage(_c, 0, m);
}

void Heavy_field_test::cReceive_LBMTdGEL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YbmYTOgC, 0, m, &cVar_YbmYTOgC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wznNpzOt, 0, m, &cVar_wznNpzOt_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_lo1ruBO6, 0, m, &cVar_lo1ruBO6_sendMessage);
}




/*
 * Context Process Implementation
 */

int Heavy_field_test::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4;

  // input and output vars
  hv_bufferf_t O0, O1;

  // declare and init the zero buffer
  hv_bufferf_t ZERO; __hv_zero_f(VOf(ZERO));

  hv_uint32_t nextBlock = blockStartTimestamp;
  for (int n = 0; n < n4; n += HV_N_SIMD) {

    // process all of the messages for this block
    nextBlock += HV_N_SIMD;
    while (mq_hasMessageBefore(&mq, nextBlock)) {
      MessageNode *const node = mq_peek(&mq);
      node->sendMessage(this, node->let, node->m);
      mq_pop(&mq);
    }

    

    // zero output buffers
    __hv_zero_f(VOf(O0));
    __hv_zero_f(VOf(O1));

    // process all signal functions
    __hv_phasor_k_f(&sPhasor_gG39ytJg, VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf0));
    __hv_mul_f(VIf(Bf1), VIf(Bf0), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf3), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf4), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf2), VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf0), VIf(Bf3), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(O0), VOf(O0));
    __hv_add_f(VIf(Bf1), VIf(O1), VOf(O1));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int Heavy_field_test::processInline(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(!(n4 & HV_N_SIMD_MASK)); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s)
  float **const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float **const bOut = reinterpret_cast<float **>(hv_alloca(2*sizeof(float *)));
  bOut[0] = outputBuffers+(0*n4);
  bOut[1] = outputBuffers+(1*n4);

  int n = process(bIn, bOut, n4);
  return n;
}

int Heavy_field_test::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
  hv_assert(n4 & ~HV_N_SIMD_MASK); // ensure that n4 is a multiple of HV_N_SIMD

  // define the heavy input buffer for 0 channel(s), uninterleave
  float *const bIn = NULL;

  // define the heavy output buffer for 2 channel(s)
  float *const bOut = reinterpret_cast<float *>(hv_alloca(2*n4*sizeof(float)));

  int n = processInline(bIn, bOut, n4);

  // interleave the heavy output into the output buffer
  #if HV_SIMD_AVX
  for (int i = 0, j = 0; j < n4; j += 8, i += 16) {
    __m256 x = _mm256_load_ps(bOut+j);    // LLLLLLLL
    __m256 y = _mm256_load_ps(bOut+n4+j); // RRRRRRRR
    __m256 a = _mm256_unpacklo_ps(x, y);  // LRLRLRLR
    __m256 b = _mm256_unpackhi_ps(x, y);  // LRLRLRLR
    _mm256_store_ps(outputBuffers+i, a);
    _mm256_store_ps(outputBuffers+8+i, b);
  }
  #elif HV_SIMD_SSE
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    __m128 x = _mm_load_ps(bOut+j);    // LLLL
    __m128 y = _mm_load_ps(bOut+n4+j); // RRRR
    __m128 a = _mm_unpacklo_ps(x, y);  // LRLR
    __m128 b = _mm_unpackhi_ps(x, y);  // LRLR
    _mm_store_ps(outputBuffers+i, a);
    _mm_store_ps(outputBuffers+4+i, b);
  }
  #elif HV_SIMD_NEON
  // https://community.arm.com/groups/processors/blog/2012/03/13/coding-for-neon--part-5-rearranging-vectors
  for (int i = 0, j = 0; j < n4; j += 4, i += 8) {
    float32x4_t x = vld1q_f32(bOut+j);
    float32x4_t y = vld1q_f32(bOut+n4+j);
    float32x4x2_t z = {x, y};
    vst2q_f32(outputBuffers+i, z); // interleave and store
  }
  #else // HV_SIMD_NONE
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n4; ++j) {
      outputBuffers[i+2*j] = bOut[i*n4+j];
    }
  }
  #endif

  return n;
}
