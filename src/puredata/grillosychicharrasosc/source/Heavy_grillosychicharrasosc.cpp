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

#include "Heavy_grillosychicharrasosc.hpp"

#define Context(_c) reinterpret_cast<Heavy_grillosychicharrasosc *>(_c)



/*
 * C Functions
 */

extern "C" {
  HV_EXPORT HeavyContextInterface *hv_grillosychicharrasosc_new(double sampleRate) {
    return new Heavy_grillosychicharrasosc(sampleRate);
  }

  HV_EXPORT HeavyContextInterface *hv_grillosychicharrasosc_new_with_options(double sampleRate,
      int poolKb, int inQueueKb, int outQueueKb) {
    return new Heavy_grillosychicharrasosc(sampleRate, poolKb, inQueueKb, outQueueKb);
  }
} // extern "C"







/*
 * Class Functions
 */

Heavy_grillosychicharrasosc::Heavy_grillosychicharrasosc(double sampleRate, int poolKb, int inQueueKb, int outQueueKb)
    : HeavyContext(sampleRate, poolKb, inQueueKb, outQueueKb) {
  numBytes += sPhasor_k_init(&sPhasor_LxiTXIU7, 10.0f, sampleRate);
  numBytes += sBiquad_k_init(&sBiquad_k_kIL0xY3G, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sPhasor_k_init(&sPhasor_f0uDpVMO, 13000.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_xEJfWmd4, 4500.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_k3VLT3AV, 9000.0f, sampleRate);
  numBytes += sLine_init(&sLine_Oh08yDd7);
  numBytes += cDelay_init(this, &cDelay_1W2kzZDN, 0.0f);
  numBytes += cVar_init_f(&cVar_qwyg9nS7, 1000.0f);
  numBytes += cBinop_init(&cBinop_4GfUaJEx, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_PCWvP2ew, 0.0f);
  numBytes += cVar_init_f(&cVar_fu2iHazL, 0.0f);
  numBytes += cIf_init(&cIf_wDzm9Od4, false);
  numBytes += cRandom_init(&cRandom_PQynaYg8, -1312843012);
  numBytes += cSlice_init(&cSlice_8jWCv1Te, 1, 1);
  numBytes += sVari_init(&sVari_pK2hcXbz, 0, 0, false);
  numBytes += cVar_init_f(&cVar_TY9ShC1k, 0.0f);
  numBytes += cVar_init_f(&cVar_mT7tJEeZ, 0.0f);
  numBytes += cVar_init_f(&cVar_x1YSGd3n, 0.0f);
  numBytes += cVar_init_f(&cVar_qbhidx3Y, 0.0f);
  numBytes += cDelay_init(this, &cDelay_d1qIvJ9m, 0.0f);
  numBytes += cVar_init_f(&cVar_Y0F9OsCr, 20.0f);
  numBytes += cBinop_init(&cBinop_lPFfKlsd, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_okCuyCA4, 0.0f);
  numBytes += cSlice_init(&cSlice_ezc7jNlR, 1, -1);
  numBytes += cSlice_init(&cSlice_LIs4t4ql, 1, -1);
  numBytes += cVar_init_f(&cVar_3XqijbAZ, 0.0f);
  numBytes += cVar_init_f(&cVar_fhcbwBIH, 20.0f);
  numBytes += cVar_init_f(&cVar_wukYta38, 2000.0f);
  numBytes += cVar_init_f(&cVar_XaasXUl7, 0.0f);
  numBytes += cVar_init_f(&cVar_kCnTwIWU, 2000.0f);
  numBytes += cSlice_init(&cSlice_HAu0xLeD, 1, 1);
  numBytes += cSlice_init(&cSlice_cEctcs0I, 0, 1);
  numBytes += cBinop_init(&cBinop_sHbRClgO, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_ppKn1uB5, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_BJF2iMRx, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_BtOC5oZ5, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_u1bVMgSR, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_7NgviVao, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_go5bROKj, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_TukbXVrH, 0.0f); // __sub
  numBytes += cRandom_init(&cRandom_RVxOnytA, 718421635);
  numBytes += cSlice_init(&cSlice_ypVywBA4, 1, 1);
  numBytes += cVar_init_f(&cVar_inGNZZDB, 5000.0f);
  numBytes += cVar_init_f(&cVar_9p2rJHnY, 6.0f);
  numBytes += cBinop_init(&cBinop_VvbZc6SQ, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_2E35JuJ5, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_Vrj34Bmg, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_T8tBRUJQ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Oay94lWZ, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_9PR2FXG3, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_mg7Zr8Lf, 0.0f);
  numBytes += cVar_init_f(&cVar_eUHSYi7u, 20.0f);
  numBytes += cBinop_init(&cBinop_YyyRCI0N, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_aCS6INYl, 0.0f);
  numBytes += cSlice_init(&cSlice_1PovdWxB, 1, -1);
  numBytes += cSlice_init(&cSlice_ssCLQNHa, 1, -1);
  numBytes += cVar_init_f(&cVar_bioSjHl5, 0.0f);
  numBytes += cVar_init_f(&cVar_g2K61cxW, 20.0f);
  numBytes += cVar_init_f(&cVar_PbDU57wZ, 0.0f);
  numBytes += cVar_init_f(&cVar_8actfqwO, 0.0f);
  numBytes += cVar_init_f(&cVar_O2R8rIqR, 0.0f);
  numBytes += cSlice_init(&cSlice_GdI2hEJP, 1, 1);
  numBytes += cSlice_init(&cSlice_sG9BFD3G, 0, 1);
  numBytes += cBinop_init(&cBinop_mfnpm9x0, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_ekhY3QLw, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_BlSB0VbZ, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_vCjPmpjt, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_QsgV9zYT, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_00iCDUR9, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_dpTjFXWU, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_Vjaq7jXj, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_RuQ4S2vT, 0.0f);
  numBytes += cVar_init_f(&cVar_I0yuZqOI, 0.0f);
  numBytes += cVar_init_f(&cVar_CumYpKff, 0.0f);
  numBytes += cRandom_init(&cRandom_vK2MN3aJ, 6106731);
  numBytes += cSlice_init(&cSlice_lKMHde7c, 1, 1);
  numBytes += cRandom_init(&cRandom_F1h325lB, -959592058);
  numBytes += cSlice_init(&cSlice_zLol8OfS, 1, 1);
  numBytes += cVar_init_f(&cVar_DbO3QLUW, 1.0f);
  numBytes += cDelay_init(this, &cDelay_zJAiWiVJ, 0.0f);
  numBytes += cVar_init_f(&cVar_Xwwsrbpg, 5000.0f);
  numBytes += cBinop_init(&cBinop_GzxoCS6E, 0.0f); // __mul
  numBytes += cRandom_init(&cRandom_DCttPl7q, 643561556);
  numBytes += cSlice_init(&cSlice_X67VeFI3, 1, 1);
  numBytes += cDelay_init(this, &cDelay_YZS2UE8n, 0.0f);
  numBytes += cVar_init_f(&cVar_M1yeaAnC, 5000.0f);
  numBytes += cBinop_init(&cBinop_rUdemX9s, 0.0f); // __mul
  numBytes += cRandom_init(&cRandom_ABMk6KNc, 1456082457);
  numBytes += cSlice_init(&cSlice_CTcLER8b, 1, 1);
  numBytes += cRandom_init(&cRandom_JMgv08m3, -1870467821);
  numBytes += cSlice_init(&cSlice_JSCNGRxu, 1, 1);
  numBytes += cDelay_init(this, &cDelay_FYmDNgRU, 0.0f);
  numBytes += cVar_init_f(&cVar_woiTrk6W, 20.0f);
  numBytes += cBinop_init(&cBinop_8TEqWAid, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_JjBolIbR, 0.0f);
  numBytes += cSlice_init(&cSlice_awh2ib9f, 1, -1);
  numBytes += cSlice_init(&cSlice_NEXXL2QM, 1, -1);
  numBytes += cVar_init_f(&cVar_xpf6GBEd, 0.0f);
  numBytes += cVar_init_f(&cVar_EbuEpSgM, 20.0f);
  numBytes += cVar_init_f(&cVar_1F8Sb4gT, 0.0f);
  numBytes += cVar_init_f(&cVar_uHqE8HuL, 0.0f);
  numBytes += cVar_init_f(&cVar_GIRUblSa, 0.0f);
  numBytes += cSlice_init(&cSlice_UZQeejUQ, 1, 1);
  numBytes += cSlice_init(&cSlice_N3doIsrB, 0, 1);
  numBytes += cBinop_init(&cBinop_Nj71YuHQ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_JvB4Yd25, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_QjtkWKXU, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_YFcUktke, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_t5O2YxJ2, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_FNADSqay, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_M62PhVRg, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_zkZbSnoa, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_LZSxNqmR, 1.0f);
  numBytes += cVar_init_f(&cVar_t6BwMB2Q, 0.0f);
  numBytes += cVar_init_f(&cVar_EellGHUk, 0.0f);
  numBytes += cDelay_init(this, &cDelay_DCOySfGo, 0.0f);
  numBytes += cVar_init_f(&cVar_TmNyvxKQ, 500.0f);
  numBytes += cBinop_init(&cBinop_5x30xgW6, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_jZ0oU64w, 1.0f);
  numBytes += cDelay_init(this, &cDelay_z3JWA8vp, 20.0f);
  numBytes += cDelay_init(this, &cDelay_OyHKIz4x, 20.0f);
  numBytes += cDelay_init(this, &cDelay_k2UAidvz, 20.0f);
  numBytes += cDelay_init(this, &cDelay_QkcFAt5v, 30.0f);
  numBytes += cDelay_init(this, &cDelay_hblxrXtV, 30.0f);
  numBytes += cDelay_init(this, &cDelay_9Xw96O2f, 30.0f);
  numBytes += cDelay_init(this, &cDelay_B0ACDsqo, 30.0f);
  numBytes += cVar_init_f(&cVar_irrNU027, 0.0f);
  numBytes += cVar_init_f(&cVar_AOvZZNkF, 0.0f);
  numBytes += cVar_init_f(&cVar_dldsdwqn, 0.0f);
  numBytes += cVar_init_f(&cVar_thenDPbx, 1.0f);
  numBytes += cDelay_init(this, &cDelay_yQjWCTNJ, 0.0f);
  numBytes += cVar_init_f(&cVar_vh66bxML, 2000.0f);
  numBytes += cBinop_init(&cBinop_PLphhueJ, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_dYC2hQlY, 1000.0f);
  numBytes += cBinop_init(&cBinop_1UvyqNeu, 1.0f); // __add
  numBytes += cBinop_init(&cBinop_G3DWhTEH, 30.0f); // __bimod
  numBytes += sVarf_init(&sVarf_wcDzhft9, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_vp4LEFaY, 0.5f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_mlDm3D8z, 0.5f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_mbHVKxDb, 0.5f, 0.0f, false);
  
  // schedule a message to trigger all loadbangs via the __hv_init receiver
  scheduleMessageForReceiver(0xCE5CC65B, msg_initWithBang(HV_MESSAGE_ON_STACK(1), 0));
}

Heavy_grillosychicharrasosc::~Heavy_grillosychicharrasosc() {
  // nothing to free
}

HvTable *Heavy_grillosychicharrasosc::getTableForHash(hv_uint32_t tableHash) {
  return nullptr;
}

void Heavy_grillosychicharrasosc::scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) {
  switch (receiverHash) {
    case 0xCE5CC65B: { // __hv_init
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_QOe7WQiP_sendMessage);
      break;
    }
    case 0xE062E1CE: { // button
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Oqu0KUFg_sendMessage);
      break;
    }
    case 0x44BF7D9D: { // ctrl
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_Jt0dmOKW_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_grillosychicharrasosc::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "button";
        info->hash = 0xE062E1CE;
        info->type = HvParameterType::HV_PARAM_TYPE_PARAMETER_IN;
        info->minVal = 0.0f;
        info->maxVal = 1.0f;
        info->defaultVal = 0.5f;
        break;
      }
      case 1: {
        info->name = "ctrl";
        info->hash = 0x44BF7D9D;
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
  return 2;
}



/*
 * Send Function Implementations
 */


void Heavy_grillosychicharrasosc::cSwitchcase_XaAJ8UTk_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_J86RDoeZ_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_J86RDoeZ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9NPre30g_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_1W2kzZDN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_1W2kzZDN, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1W2kzZDN, 0, m, &cDelay_1W2kzZDN_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_fu2iHazL, 0, m, &cVar_fu2iHazL_sendMessage);
  cSwitchcase_7enFm80h_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cCast_9NPre30g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_J86RDoeZ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_1W2kzZDN, 0, m, &cDelay_1W2kzZDN_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_fu2iHazL, 0, m, &cVar_fu2iHazL_sendMessage);
  cSwitchcase_7enFm80h_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_JxpeBAhW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_hHOcDT6N_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_hHOcDT6N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_wwpau6Bz_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_qwyg9nS7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4GfUaJEx, HV_BINOP_MULTIPLY, 0, m, &cBinop_4GfUaJEx_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_J86RDoeZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_1W2kzZDN, 0, m, &cDelay_1W2kzZDN_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_0chsQotA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_1W2kzZDN, 2, m, &cDelay_1W2kzZDN_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_wwpau6Bz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_4GfUaJEx, HV_BINOP_MULTIPLY, 1, m, &cBinop_4GfUaJEx_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_4GfUaJEx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_0chsQotA_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_PCWvP2ew_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_jegGRbOJ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_G3DWhTEH, HV_BINOP_MOD_BIPOLAR, 0, m, &cBinop_G3DWhTEH_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_fu2iHazL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_yZIDBixz_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_wDzm9Od4, 0, m, &cIf_wDzm9Od4_sendMessage);
}

void Heavy_grillosychicharrasosc::cUnop_chSr6BTw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1UvyqNeu, HV_BINOP_ADD, 0, m, &cBinop_1UvyqNeu_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_PCWvP2ew, 0, m, &cVar_PCWvP2ew_sendMessage);
}

void Heavy_grillosychicharrasosc::cUnop_DEbKXhmf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_1UvyqNeu, HV_BINOP_ADD, 0, m, &cBinop_1UvyqNeu_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_PCWvP2ew, 0, m, &cVar_PCWvP2ew_sendMessage);
}

void Heavy_grillosychicharrasosc::cIf_wDzm9Od4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_DEbKXhmf_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_chSr6BTw_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cBinop_yZIDBixz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_wDzm9Od4, 1, m, &cIf_wDzm9Od4_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_RnWRQ7uM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_8jWCv1Te, 0, m, &cSlice_8jWCv1Te_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_PQynaYg8, 0, m, &cRandom_PQynaYg8_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cBinop_kjS7y0lU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Z13KHwoN_sendMessage);
}

void Heavy_grillosychicharrasosc::cUnop_Z13KHwoN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_74L3m7JP_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cRandom_PQynaYg8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_kjS7y0lU_sendMessage);
}

void Heavy_grillosychicharrasosc::cSlice_8jWCv1Te_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_PQynaYg8, 1, m, &cRandom_PQynaYg8_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cMsg_74L3m7JP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_pK2hcXbz, m);
}

void Heavy_grillosychicharrasosc::cUnop_8pUNNwjt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_TY9ShC1k, 0, m, &cVar_TY9ShC1k_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_TY9ShC1k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_grillosychicharrasosc::cVar_mT7tJEeZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_grillosychicharrasosc::cVar_x1YSGd3n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_juqvs7oe_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_qbhidx3Y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_LxiTXIU7, 0, m);
}

void Heavy_grillosychicharrasosc::cMsg_OdqaGZHM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_GjqtwKXI_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_GjqtwKXI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ppKn1uB5, HV_BINOP_MULTIPLY, 1, m, &cBinop_ppKn1uB5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sHbRClgO, HV_BINOP_MULTIPLY, 1, m, &cBinop_sHbRClgO_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_wJLycNEH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_Eh3XFCdg_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_Eh3XFCdg_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mTTt9Xpj_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_d1qIvJ9m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_d1qIvJ9m, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_d1qIvJ9m, 0, m, &cDelay_d1qIvJ9m_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_okCuyCA4, 0, m, &cVar_okCuyCA4_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_mTTt9Xpj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Eh3XFCdg_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_d1qIvJ9m, 0, m, &cDelay_d1qIvJ9m_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_okCuyCA4, 0, m, &cVar_okCuyCA4_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_jhGuDpka_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iWy80D1N_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_iWy80D1N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_fJaenERv_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_Y0F9OsCr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lPFfKlsd, HV_BINOP_MULTIPLY, 0, m, &cBinop_lPFfKlsd_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_Eh3XFCdg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_d1qIvJ9m, 0, m, &cDelay_d1qIvJ9m_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_MsvdTvhd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_d1qIvJ9m, 2, m, &cDelay_d1qIvJ9m_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_fJaenERv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_lPFfKlsd, HV_BINOP_MULTIPLY, 1, m, &cBinop_lPFfKlsd_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_lPFfKlsd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_MsvdTvhd_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_okCuyCA4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BJF2iMRx, HV_BINOP_SUBTRACT, 0, m, &cBinop_BJF2iMRx_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_Cf76BNze_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_KDtlwU9z_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QkKKX34a_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2xYDiArF_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cCast_QkKKX34a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kCnTwIWU, 0, m, &cVar_kCnTwIWU_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_2xYDiArF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_x0ekL7zB_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Bv2BIy3P_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_tfdIqxwo_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ezc7jNlR, 0, m, &cSlice_ezc7jNlR_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_LIs4t4ql, 0, m, &cSlice_LIs4t4ql_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ypxe8d9r_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_HAu0xLeD, 0, m, &cSlice_HAu0xLeD_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_cEctcs0I, 0, m, &cSlice_cEctcs0I_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XMDq4Qhf_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GqwZmAEV_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cSlice_ezc7jNlR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_ORl2y4O3_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_ORl2y4O3_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cSlice_LIs4t4ql_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JatIPlmQ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fRlEG5nz_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_JatIPlmQ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fRlEG5nz_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cVar_3XqijbAZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_B2ICtnpj_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4xvSJVyD_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_fhcbwBIH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_aRUwFzss_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cSwitchcase_aRUwFzss_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2kRImG4s_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ppKn1uB5, HV_BINOP_MULTIPLY, 0, m, &cBinop_ppKn1uB5_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_u1bVMgSR, HV_BINOP_DIVIDE, 1, m, &cBinop_u1bVMgSR_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_Y0F9OsCr, 0, m, &cVar_Y0F9OsCr_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cCast_2kRImG4s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gAi9RXvJ_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cVar_wukYta38_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TukbXVrH, HV_BINOP_SUBTRACT, 1, m, &cBinop_TukbXVrH_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_XaasXUl7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kCnTwIWU, 0, m, &cVar_kCnTwIWU_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_kCnTwIWU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BtOC5oZ5, HV_BINOP_ADD, 0, m, &cBinop_BtOC5oZ5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_go5bROKj, HV_BINOP_ADD, 0, m, &cBinop_go5bROKj_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_qbhidx3Y, 0, m, &cVar_qbhidx3Y_sendMessage);
}

void Heavy_grillosychicharrasosc::cSlice_HAu0xLeD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_B2ICtnpj_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_4xvSJVyD_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cSlice_cEctcs0I_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_ftL6G1oD_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_yk9WL0S7_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cBinop_MqSSAZKJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_okCuyCA4, 1, m, &cVar_okCuyCA4_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_sHbRClgO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_MqSSAZKJ_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_ppKn1uB5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_4nZVBZDB_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_4nZVBZDB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BJF2iMRx, HV_BINOP_SUBTRACT, 1, m, &cBinop_BJF2iMRx_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_BJF2iMRx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_okCuyCA4, 1, m, &cVar_okCuyCA4_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_j6WS6mwl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_wJLycNEH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_wk4zJM4n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_wJLycNEH_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_go5bROKj, HV_BINOP_ADD, 1, m, &cBinop_go5bROKj_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BtOC5oZ5, HV_BINOP_ADD, 1, m, &cBinop_BtOC5oZ5_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_Cf76BNze_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_KDtlwU9z_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cBinop_BtOC5oZ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kCnTwIWU, 1, m, &cVar_kCnTwIWU_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_u1bVMgSR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7NgviVao, HV_BINOP_DIVIDE, 1, m, &cBinop_7NgviVao_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_7NgviVao_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_go5bROKj, HV_BINOP_ADD, 1, m, &cBinop_go5bROKj_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_BtOC5oZ5, HV_BINOP_ADD, 1, m, &cBinop_BtOC5oZ5_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_B2ICtnpj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sHbRClgO, HV_BINOP_MULTIPLY, 0, m, &cBinop_sHbRClgO_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_4xvSJVyD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_u1bVMgSR, HV_BINOP_DIVIDE, 0, m, &cBinop_u1bVMgSR_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_ftL6G1oD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XaasXUl7, 1, m, &cVar_XaasXUl7_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_yk9WL0S7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_TukbXVrH, HV_BINOP_SUBTRACT, 0, m, &cBinop_TukbXVrH_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_Bv2BIy3P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XaasXUl7, 0, m, &cVar_XaasXUl7_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_x0ekL7zB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wk4zJM4n_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cBinop_go5bROKj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_wukYta38, 0, m, &cVar_wukYta38_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_ORl2y4O3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_wJLycNEH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_zrSQxEbP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_3XqijbAZ, 1, m, &cVar_3XqijbAZ_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_juqvs7oe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fhcbwBIH, 0, m, &cVar_fhcbwBIH_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_gAi9RXvJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ppKn1uB5, HV_BINOP_MULTIPLY, 0, m, &cBinop_ppKn1uB5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_u1bVMgSR, HV_BINOP_DIVIDE, 1, m, &cBinop_u1bVMgSR_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_Y0F9OsCr, 0, m, &cVar_Y0F9OsCr_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_fRlEG5nz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Im1U2iCh_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_go5bROKj, HV_BINOP_ADD, 0, m, &cBinop_go5bROKj_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_kCnTwIWU, 1, m, &cVar_kCnTwIWU_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_JatIPlmQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ORl2y4O3_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cBinop_TukbXVrH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_7NgviVao, HV_BINOP_DIVIDE, 0, m, &cBinop_7NgviVao_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_Im1U2iCh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_wk4zJM4n_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cCast_XMDq4Qhf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_j6WS6mwl_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cCast_GqwZmAEV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zrSQxEbP_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cCast_ypxe8d9r_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_3XqijbAZ, 0, m, &cVar_3XqijbAZ_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_doMIjQZH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ypVywBA4, 0, m, &cSlice_ypVywBA4_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_RVxOnytA, 0, m, &cRandom_RVxOnytA_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cBinop_ZWSl4c93_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_C9Fgh7KK_sendMessage);
}

void Heavy_grillosychicharrasosc::cUnop_C9Fgh7KK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_G3DWhTEH, HV_BINOP_MOD_BIPOLAR, 1, m, &cBinop_G3DWhTEH_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_x1YSGd3n, 0, m, &cVar_x1YSGd3n_sendMessage);
}

void Heavy_grillosychicharrasosc::cRandom_RVxOnytA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_ZWSl4c93_sendMessage);
}

void Heavy_grillosychicharrasosc::cSlice_ypVywBA4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_RVxOnytA, 1, m, &cRandom_RVxOnytA_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cMsg_l0iiwUI8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_PNE1PeMI_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_PNE1PeMI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VvbZc6SQ, HV_BINOP_DIVIDE, 1, m, &cBinop_VvbZc6SQ_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_inGNZZDB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_FPU7qt6N_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_9p2rJHnY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_mPM9cudi_sendMessage);
}

void Heavy_grillosychicharrasosc::cUnop_uUkCg0CV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_SfiLSpvz_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_VvbZc6SQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_T8tBRUJQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_T8tBRUJQ_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_uUkCg0CV_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_2E35JuJ5, HV_BINOP_DIVIDE, 0, m, &cBinop_2E35JuJ5_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_FPU7qt6N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_VvbZc6SQ, HV_BINOP_DIVIDE, 0, m, &cBinop_VvbZc6SQ_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_2E35JuJ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_Q6gWCAb0_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_J0MX6nAF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_EnPrH3jg_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_EnPrH3jg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_k6NTsseB_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Vrj34Bmg, HV_BINOP_MULTIPLY, 0, m, &cBinop_Vrj34Bmg_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_T8tBRUJQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_T8tBRUJQ_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_SfiLSpvz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Vrj34Bmg, HV_BINOP_MULTIPLY, 1, m, &cBinop_Vrj34Bmg_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_Vrj34Bmg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_FsQGagIt_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_Xurk6bPx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_inGNZZDB, 0, m, &cVar_inGNZZDB_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_SADcAMtg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_bBEDVOpH_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_bBEDVOpH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_kIL0xY3G, 5, m);
}

void Heavy_grillosychicharrasosc::cBinop_FsQGagIt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_kIL0xY3G, 4, m);
}

void Heavy_grillosychicharrasosc::cBinop_J0LMh6gp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9PR2FXG3, HV_BINOP_MULTIPLY, 0, m, &cBinop_9PR2FXG3_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_T8tBRUJQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Oay94lWZ, HV_BINOP_ADD, 1, m, &cBinop_Oay94lWZ_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_k6NTsseB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_SADcAMtg_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_Oay94lWZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9PR2FXG3, HV_BINOP_MULTIPLY, 1, m, &cBinop_9PR2FXG3_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_9PR2FXG3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_kIL0xY3G, 1, m);
}

void Heavy_grillosychicharrasosc::cBinop_mPM9cudi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2E35JuJ5, HV_BINOP_DIVIDE, 1, m, &cBinop_2E35JuJ5_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_Q6gWCAb0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_J0MX6nAF_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Oay94lWZ, HV_BINOP_ADD, 0, m, &cBinop_Oay94lWZ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_J0LMh6gp_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_wnm7ytfw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gCGetLzf_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_gCGetLzf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ekhY3QLw, HV_BINOP_MULTIPLY, 1, m, &cBinop_ekhY3QLw_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_mfnpm9x0, HV_BINOP_MULTIPLY, 1, m, &cBinop_mfnpm9x0_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_EktPA8vd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_mQggwLBn_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_mQggwLBn_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AoXcSucd_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_mg7Zr8Lf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_mg7Zr8Lf, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mg7Zr8Lf, 0, m, &cDelay_mg7Zr8Lf_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_aCS6INYl, 0, m, &cVar_aCS6INYl_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_AoXcSucd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mQggwLBn_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_mg7Zr8Lf, 0, m, &cDelay_mg7Zr8Lf_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_aCS6INYl, 0, m, &cVar_aCS6INYl_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_FUQZdAwR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OsCns2zW_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_OsCns2zW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_4hpeQ34q_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_eUHSYi7u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YyyRCI0N, HV_BINOP_MULTIPLY, 0, m, &cBinop_YyyRCI0N_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_mQggwLBn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_mg7Zr8Lf, 0, m, &cDelay_mg7Zr8Lf_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_ui5axBIK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_mg7Zr8Lf, 2, m, &cDelay_mg7Zr8Lf_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_4hpeQ34q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YyyRCI0N, HV_BINOP_MULTIPLY, 1, m, &cBinop_YyyRCI0N_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_YyyRCI0N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_ui5axBIK_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_aCS6INYl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BlSB0VbZ, HV_BINOP_SUBTRACT, 0, m, &cBinop_BlSB0VbZ_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_6Kv6sTf5_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_xuCKSlEB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XQirk9LM_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lbjSMCed_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cCast_XQirk9LM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_O2R8rIqR, 0, m, &cVar_O2R8rIqR_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_lbjSMCed_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Pfsh1sQl_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_e6m6TZ48_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_1tAhchPZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_1PovdWxB, 0, m, &cSlice_1PovdWxB_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ssCLQNHa, 0, m, &cSlice_ssCLQNHa_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vPVY80JQ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_GdI2hEJP, 0, m, &cSlice_GdI2hEJP_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_sG9BFD3G, 0, m, &cSlice_sG9BFD3G_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_zvIsfgwH_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_FMBhAivJ_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cSlice_1PovdWxB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_gbAgks55_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_gbAgks55_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cSlice_ssCLQNHa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8YLNNa8W_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xN08s2Gm_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8YLNNa8W_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_xN08s2Gm_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cVar_bioSjHl5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_18dlB2Rm_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_b4v9PwkY_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_g2K61cxW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_LH6N6P3l_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cSwitchcase_LH6N6P3l_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rZLNz6hG_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_ekhY3QLw, HV_BINOP_MULTIPLY, 0, m, &cBinop_ekhY3QLw_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_QsgV9zYT, HV_BINOP_DIVIDE, 1, m, &cBinop_QsgV9zYT_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_eUHSYi7u, 0, m, &cVar_eUHSYi7u_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cCast_rZLNz6hG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_co50ZB8o_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cVar_PbDU57wZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Vjaq7jXj, HV_BINOP_SUBTRACT, 1, m, &cBinop_Vjaq7jXj_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_8actfqwO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_O2R8rIqR, 0, m, &cVar_O2R8rIqR_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_O2R8rIqR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_vCjPmpjt, HV_BINOP_ADD, 0, m, &cBinop_vCjPmpjt_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_dpTjFXWU, HV_BINOP_ADD, 0, m, &cBinop_dpTjFXWU_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_RuQ4S2vT, 0, m, &cVar_RuQ4S2vT_sendMessage);
}

void Heavy_grillosychicharrasosc::cSlice_GdI2hEJP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_18dlB2Rm_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_b4v9PwkY_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cSlice_sG9BFD3G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_uMfAEj0o_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_oUUIrPzY_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cBinop_9L6Vgr4C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aCS6INYl, 1, m, &cVar_aCS6INYl_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_mfnpm9x0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9L6Vgr4C_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_ekhY3QLw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_RPLQtzcu_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_RPLQtzcu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_BlSB0VbZ, HV_BINOP_SUBTRACT, 1, m, &cBinop_BlSB0VbZ_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_BlSB0VbZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_aCS6INYl, 1, m, &cVar_aCS6INYl_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_88SFvLwU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_EktPA8vd_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_DcWxyFuh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_EktPA8vd_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_dpTjFXWU, HV_BINOP_ADD, 1, m, &cBinop_dpTjFXWU_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_vCjPmpjt, HV_BINOP_ADD, 1, m, &cBinop_vCjPmpjt_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_6Kv6sTf5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_xuCKSlEB_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cBinop_vCjPmpjt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_O2R8rIqR, 1, m, &cVar_O2R8rIqR_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_QsgV9zYT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_00iCDUR9, HV_BINOP_DIVIDE, 1, m, &cBinop_00iCDUR9_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_00iCDUR9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_dpTjFXWU, HV_BINOP_ADD, 1, m, &cBinop_dpTjFXWU_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_vCjPmpjt, HV_BINOP_ADD, 1, m, &cBinop_vCjPmpjt_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_b4v9PwkY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QsgV9zYT, HV_BINOP_DIVIDE, 0, m, &cBinop_QsgV9zYT_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_18dlB2Rm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mfnpm9x0, HV_BINOP_MULTIPLY, 0, m, &cBinop_mfnpm9x0_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_uMfAEj0o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8actfqwO, 1, m, &cVar_8actfqwO_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_oUUIrPzY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Vjaq7jXj, HV_BINOP_SUBTRACT, 0, m, &cBinop_Vjaq7jXj_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_e6m6TZ48_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8actfqwO, 0, m, &cVar_8actfqwO_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_Pfsh1sQl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DcWxyFuh_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cBinop_dpTjFXWU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_PbDU57wZ, 0, m, &cVar_PbDU57wZ_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_gbAgks55_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_EktPA8vd_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_PgdOcIlL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_bioSjHl5, 1, m, &cVar_bioSjHl5_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_co50ZB8o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ekhY3QLw, HV_BINOP_MULTIPLY, 0, m, &cBinop_ekhY3QLw_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_QsgV9zYT, HV_BINOP_DIVIDE, 1, m, &cBinop_QsgV9zYT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_eUHSYi7u, 0, m, &cVar_eUHSYi7u_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_8YLNNa8W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_gbAgks55_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cCast_xN08s2Gm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hjWBG6R6_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_dpTjFXWU, HV_BINOP_ADD, 0, m, &cBinop_dpTjFXWU_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_O2R8rIqR, 1, m, &cVar_O2R8rIqR_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_Vjaq7jXj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_00iCDUR9, HV_BINOP_DIVIDE, 0, m, &cBinop_00iCDUR9_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_hjWBG6R6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DcWxyFuh_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cCast_zvIsfgwH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_88SFvLwU_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cCast_vPVY80JQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bioSjHl5, 0, m, &cVar_bioSjHl5_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_FMBhAivJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_PgdOcIlL_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cVar_RuQ4S2vT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_inGNZZDB, 0, m, &cVar_inGNZZDB_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_I0yuZqOI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9p2rJHnY, 0, m, &cVar_9p2rJHnY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Xurk6bPx_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_CumYpKff_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_wcDzhft9, m);
}

void Heavy_grillosychicharrasosc::cSwitchcase_JtcMRlq1_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_l0l5pXI9_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_exF5YyjU_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cCast_l0l5pXI9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_JarzlpuP_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cCast_exF5YyjU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_M1j0EzAH_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cSwitchcase_7enFm80h_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_lKMHde7c, 0, m, &cSlice_lKMHde7c_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_vK2MN3aJ, 0, m, &cRandom_vK2MN3aJ_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cBinop_cYBzWNM7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_w2hc3irA_sendMessage);
}

void Heavy_grillosychicharrasosc::cUnop_w2hc3irA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_JtcMRlq1_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cRandom_vK2MN3aJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_cYBzWNM7_sendMessage);
}

void Heavy_grillosychicharrasosc::cSlice_lKMHde7c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_vK2MN3aJ, 1, m, &cRandom_vK2MN3aJ_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cSwitchcase_nsMTWnpM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_zLol8OfS, 0, m, &cSlice_zLol8OfS_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_F1h325lB, 0, m, &cRandom_F1h325lB_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cBinop_N7FfgkdV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_FjfgzF9p_sendMessage);
}

void Heavy_grillosychicharrasosc::cUnop_FjfgzF9p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 4000.0f, 0, m, &cBinop_ekNBrCgL_sendMessage);
}

void Heavy_grillosychicharrasosc::cRandom_F1h325lB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_N7FfgkdV_sendMessage);
}

void Heavy_grillosychicharrasosc::cSlice_zLol8OfS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_F1h325lB, 1, m, &cRandom_F1h325lB_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cVar_DbO3QLUW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_zj6QvmdZ_sendMessage);
  cSwitchcase_fLZSzvVH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cBinop_zj6QvmdZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DbO3QLUW, 1, m, &cVar_DbO3QLUW_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_fLZSzvVH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_lmTd1PZ5_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_lmTd1PZ5_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8cGXFtIB_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_zJAiWiVJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_zJAiWiVJ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zJAiWiVJ, 0, m, &cDelay_zJAiWiVJ_sendMessage);
  cSwitchcase_doMIjQZH_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_nsMTWnpM_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_raocFvnH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cCast_8cGXFtIB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_lmTd1PZ5_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_zJAiWiVJ, 0, m, &cDelay_zJAiWiVJ_sendMessage);
  cSwitchcase_doMIjQZH_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_nsMTWnpM_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_raocFvnH_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_VYRlg0ev_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1BESHbOZ_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_1BESHbOZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Qb924igc_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_Xwwsrbpg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GzxoCS6E, HV_BINOP_MULTIPLY, 0, m, &cBinop_GzxoCS6E_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_lmTd1PZ5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_zJAiWiVJ, 0, m, &cDelay_zJAiWiVJ_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_YurT3zAA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_zJAiWiVJ, 2, m, &cDelay_zJAiWiVJ_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_Qb924igc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_GzxoCS6E, HV_BINOP_MULTIPLY, 1, m, &cBinop_GzxoCS6E_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_GzxoCS6E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_YurT3zAA_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_raocFvnH_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_X67VeFI3, 0, m, &cSlice_X67VeFI3_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_DCttPl7q, 0, m, &cRandom_DCttPl7q_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cBinop_exjPWCRW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Ar4vYV7V_sendMessage);
}

void Heavy_grillosychicharrasosc::cUnop_Ar4vYV7V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 10000.0f, 0, m, &cBinop_oG4PUueB_sendMessage);
}

void Heavy_grillosychicharrasosc::cRandom_DCttPl7q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_exjPWCRW_sendMessage);
}

void Heavy_grillosychicharrasosc::cSlice_X67VeFI3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_DCttPl7q, 1, m, &cRandom_DCttPl7q_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cSwitchcase_PPiMezQU_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_80CI1zFl_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_80CI1zFl_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LABZKoXR_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_YZS2UE8n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_YZS2UE8n, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_YZS2UE8n, 0, m, &cDelay_YZS2UE8n_sendMessage);
  cSwitchcase_RyHq4Tde_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_11hdN5UF_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cCast_LABZKoXR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_80CI1zFl_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_YZS2UE8n, 0, m, &cDelay_YZS2UE8n_sendMessage);
  cSwitchcase_RyHq4Tde_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_11hdN5UF_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_PN2w6QLZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_uMnq1i60_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_uMnq1i60_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_NsgFfIkS_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_M1yeaAnC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rUdemX9s, HV_BINOP_MULTIPLY, 0, m, &cBinop_rUdemX9s_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_80CI1zFl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_YZS2UE8n, 0, m, &cDelay_YZS2UE8n_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_xg8zyMrs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_YZS2UE8n, 2, m, &cDelay_YZS2UE8n_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_NsgFfIkS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rUdemX9s, HV_BINOP_MULTIPLY, 1, m, &cBinop_rUdemX9s_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_rUdemX9s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_xg8zyMrs_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_RyHq4Tde_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_CTcLER8b, 0, m, &cSlice_CTcLER8b_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ABMk6KNc, 0, m, &cRandom_ABMk6KNc_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cBinop_FmHIUoPt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_oCksKOVV_sendMessage);
}

void Heavy_grillosychicharrasosc::cUnop_oCksKOVV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_gyIpQVor_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cRandom_ABMk6KNc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_FmHIUoPt_sendMessage);
}

void Heavy_grillosychicharrasosc::cSlice_CTcLER8b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_ABMk6KNc, 1, m, &cRandom_ABMk6KNc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cSwitchcase_11hdN5UF_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_JSCNGRxu, 0, m, &cSlice_JSCNGRxu_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_JMgv08m3, 0, m, &cRandom_JMgv08m3_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cBinop_hRcY31HM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_xBmJ7lSC_sendMessage);
}

void Heavy_grillosychicharrasosc::cUnop_xBmJ7lSC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 5000.0f, 0, m, &cBinop_YoBxHtnj_sendMessage);
}

void Heavy_grillosychicharrasosc::cRandom_JMgv08m3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_hRcY31HM_sendMessage);
}

void Heavy_grillosychicharrasosc::cSlice_JSCNGRxu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_JMgv08m3, 1, m, &cRandom_JMgv08m3_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cMsg_OgiuVFXd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_IV1OzJr2_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_IV1OzJr2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_JvB4Yd25, HV_BINOP_MULTIPLY, 1, m, &cBinop_JvB4Yd25_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Nj71YuHQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_Nj71YuHQ_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_SNrOOz03_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_rxo7qI6k_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_rxo7qI6k_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7xLhRdfi_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_FYmDNgRU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_FYmDNgRU, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FYmDNgRU, 0, m, &cDelay_FYmDNgRU_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_JjBolIbR, 0, m, &cVar_JjBolIbR_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_7xLhRdfi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_rxo7qI6k_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_FYmDNgRU, 0, m, &cDelay_FYmDNgRU_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_JjBolIbR, 0, m, &cVar_JjBolIbR_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_GLgFFxWj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_L5bA9zUA_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_L5bA9zUA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_dgXZzTVz_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_woiTrk6W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8TEqWAid, HV_BINOP_MULTIPLY, 0, m, &cBinop_8TEqWAid_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_rxo7qI6k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_FYmDNgRU, 0, m, &cDelay_FYmDNgRU_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_ryGAukQO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_FYmDNgRU, 2, m, &cDelay_FYmDNgRU_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_dgXZzTVz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8TEqWAid, HV_BINOP_MULTIPLY, 1, m, &cBinop_8TEqWAid_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_8TEqWAid_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_ryGAukQO_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_JjBolIbR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QjtkWKXU, HV_BINOP_SUBTRACT, 0, m, &cBinop_QjtkWKXU_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_1xNd4vjN_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_QApmPfby_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Zsi6BWVX_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_9kpnqw3Z_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cCast_Zsi6BWVX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GIRUblSa, 0, m, &cVar_GIRUblSa_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_9kpnqw3Z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KK2fUkiK_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vF5Ex0WW_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_gyIpQVor_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_awh2ib9f, 0, m, &cSlice_awh2ib9f_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_NEXXL2QM, 0, m, &cSlice_NEXXL2QM_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Njpao7ll_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_UZQeejUQ, 0, m, &cSlice_UZQeejUQ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_N3doIsrB, 0, m, &cSlice_N3doIsrB_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BLhuxW5Q_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_89PowJvb_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cSlice_awh2ib9f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_NbeixWiF_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_NbeixWiF_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cSlice_NEXXL2QM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PdjB9Jwy_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_annvTzMo_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PdjB9Jwy_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_annvTzMo_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cVar_xpf6GBEd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_R78BbqmP_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Xt0Esorv_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_EbuEpSgM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_yZ8UaUzD_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cSwitchcase_yZ8UaUzD_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_KrOu05RS_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_JvB4Yd25, HV_BINOP_MULTIPLY, 0, m, &cBinop_JvB4Yd25_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_t5O2YxJ2, HV_BINOP_DIVIDE, 1, m, &cBinop_t5O2YxJ2_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_woiTrk6W, 0, m, &cVar_woiTrk6W_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cCast_KrOu05RS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_piph5Q6N_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cVar_1F8Sb4gT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zkZbSnoa, HV_BINOP_SUBTRACT, 1, m, &cBinop_zkZbSnoa_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_uHqE8HuL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GIRUblSa, 0, m, &cVar_GIRUblSa_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_GIRUblSa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_YFcUktke, HV_BINOP_ADD, 0, m, &cBinop_YFcUktke_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_M62PhVRg, HV_BINOP_ADD, 0, m, &cBinop_M62PhVRg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_t6BwMB2Q, 0, m, &cVar_t6BwMB2Q_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_LQDTgiyi_sendMessage);
}

void Heavy_grillosychicharrasosc::cSlice_UZQeejUQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_R78BbqmP_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Xt0Esorv_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cSlice_N3doIsrB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_Sgn2gLDX_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_gVxj59TK_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cBinop_FljePwOe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JjBolIbR, 1, m, &cVar_JjBolIbR_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_Nj71YuHQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_FljePwOe_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_JvB4Yd25_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_SMoDiCnz_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_SMoDiCnz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QjtkWKXU, HV_BINOP_SUBTRACT, 1, m, &cBinop_QjtkWKXU_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_QjtkWKXU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_JjBolIbR, 1, m, &cVar_JjBolIbR_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_0FD29E0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_SNrOOz03_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_KtfALpeR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_SNrOOz03_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_M62PhVRg, HV_BINOP_ADD, 1, m, &cBinop_M62PhVRg_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_YFcUktke, HV_BINOP_ADD, 1, m, &cBinop_YFcUktke_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_1xNd4vjN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_QApmPfby_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cBinop_YFcUktke_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_GIRUblSa, 1, m, &cVar_GIRUblSa_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_t5O2YxJ2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FNADSqay, HV_BINOP_DIVIDE, 1, m, &cBinop_FNADSqay_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_FNADSqay_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_M62PhVRg, HV_BINOP_ADD, 1, m, &cBinop_M62PhVRg_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_YFcUktke, HV_BINOP_ADD, 1, m, &cBinop_YFcUktke_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_Xt0Esorv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_t5O2YxJ2, HV_BINOP_DIVIDE, 0, m, &cBinop_t5O2YxJ2_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_R78BbqmP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Nj71YuHQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_Nj71YuHQ_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_Sgn2gLDX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uHqE8HuL, 1, m, &cVar_uHqE8HuL_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_gVxj59TK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zkZbSnoa, HV_BINOP_SUBTRACT, 0, m, &cBinop_zkZbSnoa_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_KK2fUkiK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KtfALpeR_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cCast_vF5Ex0WW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uHqE8HuL, 0, m, &cVar_uHqE8HuL_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_M62PhVRg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1F8Sb4gT, 0, m, &cVar_1F8Sb4gT_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_NbeixWiF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_SNrOOz03_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_pDPhNcvh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_xpf6GBEd, 1, m, &cVar_xpf6GBEd_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_piph5Q6N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_JvB4Yd25, HV_BINOP_MULTIPLY, 0, m, &cBinop_JvB4Yd25_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_t5O2YxJ2, HV_BINOP_DIVIDE, 1, m, &cBinop_t5O2YxJ2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_woiTrk6W, 0, m, &cVar_woiTrk6W_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_PdjB9Jwy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NbeixWiF_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cCast_annvTzMo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Edng5CKd_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_M62PhVRg, HV_BINOP_ADD, 0, m, &cBinop_M62PhVRg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_GIRUblSa, 1, m, &cVar_GIRUblSa_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_zkZbSnoa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_FNADSqay, HV_BINOP_DIVIDE, 0, m, &cBinop_FNADSqay_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_Edng5CKd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KtfALpeR_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cCast_89PowJvb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_pDPhNcvh_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cCast_Njpao7ll_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xpf6GBEd, 0, m, &cVar_xpf6GBEd_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_BLhuxW5Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_0FD29E0d_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cVar_LZSxNqmR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_Vm875hrC_sendMessage);
  cSwitchcase_PPiMezQU_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cBinop_Vm875hrC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_LZSxNqmR, 1, m, &cVar_LZSxNqmR_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_t6BwMB2Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_grillosychicharrasosc::cVar_EellGHUk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_grillosychicharrasosc::cCast_vQgMzr5A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_w4t9qp8v_sendMessage(_c, 0, m);
  cSwitchcase_EQGQctFb_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cCast_W9FAWGf5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QCd8cBvY_sendMessage(_c, 0, m);
  cSwitchcase_u8EyFy58_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cCast_dcrTIOf2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_w9wIiiZ6_sendMessage(_c, 0, m);
  cSwitchcase_xccGKJY2_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cCast_D41OjgcZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Lyuz0fVH_sendMessage(_c, 0, m);
  cSwitchcase_8fGOa8dJ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cCast_7TjdZHWj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_igD5514b_sendMessage(_c, 0, m);
  cSwitchcase_D94ut090_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cCast_mPTyI8bE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NQhlKg8V_sendMessage(_c, 0, m);
  cSwitchcase_03KLaLAK_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cCast_wZ8kzHBT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HpHjZaHp_sendMessage(_c, 0, m);
  cSwitchcase_b8zFdTFv_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cCast_LwIxFdvT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kYsKfOV2_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cSwitchcase_zmQoK1OM_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_2EEU4O5P_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_2EEU4O5P_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8LSMd5L5_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_DCOySfGo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_DCOySfGo, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DCOySfGo, 0, m, &cDelay_DCOySfGo_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vQgMzr5A_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_8LSMd5L5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2EEU4O5P_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_DCOySfGo, 0, m, &cDelay_DCOySfGo_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vQgMzr5A_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_5SwHlRzp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Pvcwolld_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_Pvcwolld_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_9csvGmBn_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_TmNyvxKQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5x30xgW6, HV_BINOP_MULTIPLY, 0, m, &cBinop_5x30xgW6_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_2EEU4O5P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_DCOySfGo, 0, m, &cDelay_DCOySfGo_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_p127OyeQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_DCOySfGo, 2, m, &cDelay_DCOySfGo_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_9csvGmBn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5x30xgW6, HV_BINOP_MULTIPLY, 1, m, &cBinop_5x30xgW6_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_5x30xgW6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_p127OyeQ_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_jZ0oU64w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_SVPnbg7P_sendMessage);
  cSwitchcase_zmQoK1OM_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cBinop_SVPnbg7P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_jZ0oU64w, 1, m, &cVar_jZ0oU64w_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_u8EyFy58_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_s5Xl48Tw_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_s5Xl48Tw_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_z3JWA8vp, 1, m, &cDelay_z3JWA8vp_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mCydZE6d_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_z3JWA8vp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_z3JWA8vp, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_dcrTIOf2_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_s5Xl48Tw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_z3JWA8vp, 0, m, &cDelay_z3JWA8vp_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_mCydZE6d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_z3JWA8vp, 0, m, &cDelay_z3JWA8vp_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_8fGOa8dJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_N3XMIN6h_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_N3XMIN6h_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_OyHKIz4x, 1, m, &cDelay_OyHKIz4x_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_enOv5Itt_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_OyHKIz4x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_OyHKIz4x, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7TjdZHWj_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_N3XMIN6h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_OyHKIz4x, 0, m, &cDelay_OyHKIz4x_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_enOv5Itt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_OyHKIz4x, 0, m, &cDelay_OyHKIz4x_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_03KLaLAK_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_CNw7orMV_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_CNw7orMV_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_k2UAidvz, 1, m, &cDelay_k2UAidvz_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8mIlcwpl_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_k2UAidvz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_k2UAidvz, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_wZ8kzHBT_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_CNw7orMV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_k2UAidvz, 0, m, &cDelay_k2UAidvz_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_8mIlcwpl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_k2UAidvz, 0, m, &cDelay_k2UAidvz_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_EQGQctFb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_d3ZuxwMD_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_d3ZuxwMD_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_QkcFAt5v, 1, m, &cDelay_QkcFAt5v_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ckFcVNSh_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_QkcFAt5v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_QkcFAt5v, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_W9FAWGf5_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_d3ZuxwMD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_QkcFAt5v, 0, m, &cDelay_QkcFAt5v_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_ckFcVNSh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_QkcFAt5v, 0, m, &cDelay_QkcFAt5v_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_xccGKJY2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_NqbgnOVI_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_NqbgnOVI_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_hblxrXtV, 1, m, &cDelay_hblxrXtV_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Uylwl7eS_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_hblxrXtV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_hblxrXtV, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_D41OjgcZ_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_NqbgnOVI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_hblxrXtV, 0, m, &cDelay_hblxrXtV_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_Uylwl7eS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_hblxrXtV, 0, m, &cDelay_hblxrXtV_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_D94ut090_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_ANOuc6mg_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_ANOuc6mg_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_9Xw96O2f, 1, m, &cDelay_9Xw96O2f_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_N6QSYD1s_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_9Xw96O2f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9Xw96O2f, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mPTyI8bE_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_ANOuc6mg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_9Xw96O2f, 0, m, &cDelay_9Xw96O2f_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_N6QSYD1s_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_9Xw96O2f, 0, m, &cDelay_9Xw96O2f_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_b8zFdTFv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_mLWgIQu0_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_mLWgIQu0_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_B0ACDsqo, 1, m, &cDelay_B0ACDsqo_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gcFDepbn_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_B0ACDsqo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_B0ACDsqo, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_LwIxFdvT_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_mLWgIQu0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_B0ACDsqo, 0, m, &cDelay_B0ACDsqo_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_gcFDepbn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_B0ACDsqo, 0, m, &cDelay_B0ACDsqo_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_irrNU027_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_mbHVKxDb, m);
}

void Heavy_grillosychicharrasosc::cVar_AOvZZNkF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_mlDm3D8z, m);
}

void Heavy_grillosychicharrasosc::cVar_dldsdwqn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_vp4LEFaY, m);
}

void Heavy_grillosychicharrasosc::cVar_thenDPbx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_us8LVpBF_sendMessage);
  cSwitchcase_aT5xmtxy_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cBinop_us8LVpBF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_thenDPbx, 1, m, &cVar_thenDPbx_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_aT5xmtxy_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_5tZexWOE_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_5tZexWOE_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_UnsI3B7K_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_yQjWCTNJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_yQjWCTNJ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yQjWCTNJ, 0, m, &cDelay_yQjWCTNJ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_jZ0oU64w, 0, m, &cVar_jZ0oU64w_sendMessage);
  cSwitchcase_k8S5gcQg_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cCast_UnsI3B7K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5tZexWOE_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_yQjWCTNJ, 0, m, &cDelay_yQjWCTNJ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_jZ0oU64w, 0, m, &cVar_jZ0oU64w_sendMessage);
  cSwitchcase_k8S5gcQg_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_8m4u3acF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_RETd5ExZ_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_RETd5ExZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_vq2xer2Q_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_vh66bxML_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PLphhueJ, HV_BINOP_MULTIPLY, 0, m, &cBinop_PLphhueJ_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_5tZexWOE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_yQjWCTNJ, 0, m, &cDelay_yQjWCTNJ_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_Rb7Om7L2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_yQjWCTNJ, 2, m, &cDelay_yQjWCTNJ_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_vq2xer2Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PLphhueJ, HV_BINOP_MULTIPLY, 1, m, &cBinop_PLphhueJ_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_PLphhueJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_Rb7Om7L2_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_k8S5gcQg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_hC6YH8Yp_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_hC6YH8Yp_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_dYC2hQlY, 1, m, &cDelay_dYC2hQlY_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5TTwnq9h_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_dYC2hQlY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_dYC2hQlY, m);
  cVar_onMessage(_c, &Context(_c)->cVar_jZ0oU64w, 0, m, &cVar_jZ0oU64w_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_hC6YH8Yp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_dYC2hQlY, 0, m, &cDelay_dYC2hQlY_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_5TTwnq9h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_dYC2hQlY, 0, m, &cDelay_dYC2hQlY_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_jegGRbOJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_qwyg9nS7, 0, m, &cVar_qwyg9nS7_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_ABS, m, &cUnop_8pUNNwjt_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_1UvyqNeu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_fu2iHazL, 1, m, &cVar_fu2iHazL_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_JarzlpuP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1UvyqNeu, HV_BINOP_ADD, 1, m, &cBinop_1UvyqNeu_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_O6WQwC5n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_LxiTXIU7, 0, m);
}

void Heavy_grillosychicharrasosc::cBinop_G3DWhTEH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mT7tJEeZ, 0, m, &cVar_mT7tJEeZ_sendMessage);
  cMsg_M1oD9q2A_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cMsg_M1oD9q2A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1000.0f);
  cSwitchcase_tfdIqxwo_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_M1j0EzAH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_1UvyqNeu, HV_BINOP_ADD, 1, m, &cBinop_1UvyqNeu_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_2qsEEP08_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1000.0f);
  cSwitchcase_1tAhchPZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cBinop_ekNBrCgL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_2qsEEP08_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cMsg_3lWl0kIJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 8.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_9p2rJHnY, 0, m, &cVar_9p2rJHnY_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Xurk6bPx_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_YoBxHtnj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_xpf6GBEd, 1, m, &cVar_xpf6GBEd_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_oG4PUueB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Xwwsrbpg, 0, m, &cVar_Xwwsrbpg_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_M1yeaAnC, 0, m, &cVar_M1yeaAnC_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_EellGHUk, 0, m, &cVar_EellGHUk_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_LQDTgiyi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_CumYpKff, 0, m, &cVar_CumYpKff_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_QCd8cBvY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Oh08yDd7, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_Lyuz0fVH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Oh08yDd7, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_NQhlKg8V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Oh08yDd7, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_kYsKfOV2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Oh08yDd7, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_w4t9qp8v_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Oh08yDd7, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_w9wIiiZ6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Oh08yDd7, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_igD5514b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Oh08yDd7, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_HpHjZaHp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_Oh08yDd7, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cReceive_QOe7WQiP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jhGuDpka_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Y0F9OsCr, 0, m, &cVar_Y0F9OsCr_sendMessage);
  cMsg_FUQZdAwR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_eUHSYi7u, 0, m, &cVar_eUHSYi7u_sendMessage);
  cMsg_GLgFFxWj_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_woiTrk6W, 0, m, &cVar_woiTrk6W_sendMessage);
  cMsg_JxpeBAhW_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_qwyg9nS7, 0, m, &cVar_qwyg9nS7_sendMessage);
  cSwitchcase_RnWRQ7uM_onMessage(_c, NULL, 0, m, NULL);
  cMsg_OdqaGZHM_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_wukYta38, 0, m, &cVar_wukYta38_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_fhcbwBIH, 0, m, &cVar_fhcbwBIH_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_9p2rJHnY, 0, m, &cVar_9p2rJHnY_sendMessage);
  cMsg_l0iiwUI8_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_inGNZZDB, 0, m, &cVar_inGNZZDB_sendMessage);
  cMsg_wnm7ytfw_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_PbDU57wZ, 0, m, &cVar_PbDU57wZ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_g2K61cxW, 0, m, &cVar_g2K61cxW_sendMessage);
  cMsg_VYRlg0ev_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Xwwsrbpg, 0, m, &cVar_Xwwsrbpg_sendMessage);
  cMsg_PN2w6QLZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_M1yeaAnC, 0, m, &cVar_M1yeaAnC_sendMessage);
  cMsg_OgiuVFXd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_1F8Sb4gT, 0, m, &cVar_1F8Sb4gT_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_EbuEpSgM, 0, m, &cVar_EbuEpSgM_sendMessage);
  cMsg_5SwHlRzp_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_TmNyvxKQ, 0, m, &cVar_TmNyvxKQ_sendMessage);
  cMsg_8m4u3acF_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_vh66bxML, 0, m, &cVar_vh66bxML_sendMessage);
  cSwitchcase_XaAJ8UTk_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_fLZSzvVH_onMessage(_c, NULL, 0, m, NULL);
  cMsg_3lWl0kIJ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_LZSxNqmR, 0, m, &cVar_LZSxNqmR_sendMessage);
}

void Heavy_grillosychicharrasosc::cReceive_Jt0dmOKW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_DbO3QLUW, 0, m, &cVar_DbO3QLUW_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_thenDPbx, 0, m, &cVar_thenDPbx_sendMessage);
}

void Heavy_grillosychicharrasosc::cReceive_Oqu0KUFg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_thenDPbx, 0, m, &cVar_thenDPbx_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_DbO3QLUW, 0, m, &cVar_DbO3QLUW_sendMessage);
}




/*
 * Context Process Implementation
 */

int Heavy_grillosychicharrasosc::process(float **inputBuffers, float **outputBuffers, int n) {
  while (hLp_hasData(&inQueue)) {
    hv_uint32_t numBytes = 0;
    ReceiverMessagePair *p = reinterpret_cast<ReceiverMessagePair *>(hLp_getReadBuffer(&inQueue, &numBytes));
    hv_assert(numBytes >= sizeof(ReceiverMessagePair));
    scheduleMessageForReceiver(p->receiverHash, &p->msg);
    hLp_consume(&inQueue);
  }
  const int n4 = n & ~HV_N_SIMD_MASK; // ensure that the block size is a multiple of HV_N_SIMD

  // temporary signal vars
  hv_bufferf_t Bf0, Bf1, Bf2, Bf3, Bf4, Bf5, Bf6, Bf7, Bf8;
  hv_bufferi_t Bi0, Bi1;

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
    __hv_varread_i(&sVari_pK2hcXbz, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_i(&sVari_pK2hcXbz, VIi(Bi1));
    __hv_phasor_k_f(&sPhasor_LxiTXIU7, VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf2), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf0));
    __hv_mul_f(VIf(Bf2), VIf(Bf0), VOf(Bf3));
    __hv_mul_f(VIf(Bf3), VIf(Bf0), VOf(Bf0));
    __hv_var_k_f(VOf(Bf4), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf5), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf3), VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf0), VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_biquad_k_f(&sBiquad_k_kIL0xY3G, VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_wcDzhft9, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_add_f(VIf(Bf1), VIf(O1), VOf(O1));
    __hv_add_f(VIf(Bf1), VIf(O0), VOf(O0));
    __hv_phasor_k_f(&sPhasor_f0uDpVMO, VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_abs_f(VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_mul_f(VIf(Bf2), VIf(Bf2), VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf0), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf5), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_fma_f(VIf(Bf1), VIf(Bf0), VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_mbHVKxDb, VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_xEJfWmd4, VOf(Bf1));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf5), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf1), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf1));
    __hv_mul_f(VIf(Bf5), VIf(Bf1), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf3), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf6), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf1), VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_vp4LEFaY, VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_k3VLT3AV, VOf(Bf1));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf1), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf6), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf1), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf1));
    __hv_mul_f(VIf(Bf6), VIf(Bf1), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf7), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf8), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf1), VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_mlDm3D8z, VOf(Bf7));
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf5), VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf2), VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_Oh08yDd7, VOf(Bf7));
    __hv_mul_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_add_f(VIf(ZERO), VIf(O0), VOf(O0));
    __hv_add_f(VIf(ZERO), VIf(O1), VOf(O1));

    // save output vars to output buffer
    __hv_store_f(outputBuffers[0]+n, VIf(O0));
    __hv_store_f(outputBuffers[1]+n, VIf(O1));
  }

  blockStartTimestamp = nextBlock;

  return n4; // return the number of frames processed
}

int Heavy_grillosychicharrasosc::processInline(float *inputBuffers, float *outputBuffers, int n4) {
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

int Heavy_grillosychicharrasosc::processInlineInterleaved(float *inputBuffers, float *outputBuffers, int n4) {
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
