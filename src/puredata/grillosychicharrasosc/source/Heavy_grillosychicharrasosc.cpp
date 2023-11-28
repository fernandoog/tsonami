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
  numBytes += sPhasor_k_init(&sPhasor_3Iq721RA, 10.0f, sampleRate);
  numBytes += sBiquad_k_init(&sBiquad_k_nGDESKZU, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
  numBytes += sPhasor_k_init(&sPhasor_jheYmMUo, 13000.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_q0quS1iW, 4500.0f, sampleRate);
  numBytes += sPhasor_k_init(&sPhasor_P3LuLCLz, 9000.0f, sampleRate);
  numBytes += sLine_init(&sLine_ZEhsY3GJ);
  numBytes += cDelay_init(this, &cDelay_Yu8ay0lQ, 0.0f);
  numBytes += cVar_init_f(&cVar_Nnfc7x9C, 1000.0f);
  numBytes += cBinop_init(&cBinop_whoE78sD, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_P3KL6noN, 0.0f);
  numBytes += cVar_init_f(&cVar_eUIKfLve, 0.0f);
  numBytes += cIf_init(&cIf_hOFE8kyf, false);
  numBytes += cRandom_init(&cRandom_v7pWLsoa, 19582766);
  numBytes += cSlice_init(&cSlice_TQ5jAajU, 1, 1);
  numBytes += sVari_init(&sVari_7VgJQjRv, 0, 0, false);
  numBytes += cVar_init_f(&cVar_ObOUWnoI, 0.0f);
  numBytes += cVar_init_f(&cVar_mKyLpCkL, 0.0f);
  numBytes += cVar_init_f(&cVar_n2TyQRTN, 0.0f);
  numBytes += cVar_init_f(&cVar_SQRUBity, 0.0f);
  numBytes += cDelay_init(this, &cDelay_u22bsNJt, 0.0f);
  numBytes += cVar_init_f(&cVar_VuUO8pOT, 20.0f);
  numBytes += cBinop_init(&cBinop_V9kkKiuu, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_b7X8kTRD, 0.0f);
  numBytes += cSlice_init(&cSlice_suiSbvgo, 1, -1);
  numBytes += cSlice_init(&cSlice_gQaBz8x0, 1, -1);
  numBytes += cVar_init_f(&cVar_1Go5tnsh, 0.0f);
  numBytes += cVar_init_f(&cVar_XyTmFvhx, 20.0f);
  numBytes += cVar_init_f(&cVar_yUmE2zKD, 2000.0f);
  numBytes += cVar_init_f(&cVar_kumb9KeP, 0.0f);
  numBytes += cVar_init_f(&cVar_IaKoKe7K, 2000.0f);
  numBytes += cSlice_init(&cSlice_AUvEPHcH, 1, 1);
  numBytes += cSlice_init(&cSlice_9901yvQJ, 0, 1);
  numBytes += cBinop_init(&cBinop_MnWPJHoa, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_OfvUtCed, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_DqCOIhPF, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_6HWKc81T, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_mV5g0T3w, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_2EhbrWuc, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_Cq97QXLx, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_6x8OpbvE, 0.0f); // __sub
  numBytes += cRandom_init(&cRandom_cBjjgoSs, 616061152);
  numBytes += cSlice_init(&cSlice_sZfVq8jD, 1, 1);
  numBytes += cVar_init_f(&cVar_9qp5BItd, 5000.0f);
  numBytes += cVar_init_f(&cVar_R45Qg3wP, 6.0f);
  numBytes += cBinop_init(&cBinop_LwzhYklL, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_6vxLx8Vr, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_K7ebZwft, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_yip3Mvj2, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_wmR3cs6y, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_shVLnjCS, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_3RJCOYcc, 0.0f);
  numBytes += cVar_init_f(&cVar_cZOROno5, 20.0f);
  numBytes += cBinop_init(&cBinop_PKYneWMg, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_bfBrGQS9, 0.0f);
  numBytes += cSlice_init(&cSlice_b5EiwBH6, 1, -1);
  numBytes += cSlice_init(&cSlice_JQV7rzsL, 1, -1);
  numBytes += cVar_init_f(&cVar_RNwsu7Qp, 0.0f);
  numBytes += cVar_init_f(&cVar_TqsPRgvJ, 20.0f);
  numBytes += cVar_init_f(&cVar_USNPbtPW, 0.0f);
  numBytes += cVar_init_f(&cVar_FA9HM06u, 0.0f);
  numBytes += cVar_init_f(&cVar_68g9fpZP, 0.0f);
  numBytes += cSlice_init(&cSlice_9Rcv20sv, 1, 1);
  numBytes += cSlice_init(&cSlice_H5REGhA3, 0, 1);
  numBytes += cBinop_init(&cBinop_NWGmmZbL, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_HkobI4YQ, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Id4eDgmg, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_sYjQzHyd, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_U8PTT4zA, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_kHEXUx6A, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_aVLrzYKi, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_Z3lEbYEy, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_wYXJkuu3, 0.0f);
  numBytes += cVar_init_f(&cVar_7XMFG1Jx, 0.0f);
  numBytes += cVar_init_f(&cVar_4SrcHYHo, 0.0f);
  numBytes += cRandom_init(&cRandom_JF0BuKA0, -553475535);
  numBytes += cSlice_init(&cSlice_77b0Z3qh, 1, 1);
  numBytes += cRandom_init(&cRandom_i9t3pPrX, -98399279);
  numBytes += cSlice_init(&cSlice_khUFGaEr, 1, 1);
  numBytes += cVar_init_f(&cVar_lJiJqIrv, 1.0f);
  numBytes += cDelay_init(this, &cDelay_p7OdiHgQ, 0.0f);
  numBytes += cVar_init_f(&cVar_MBFODPm4, 5000.0f);
  numBytes += cBinop_init(&cBinop_0QS5SfF7, 0.0f); // __mul
  numBytes += cRandom_init(&cRandom_2so6wfvk, 866301503);
  numBytes += cSlice_init(&cSlice_0bPF1CDO, 1, 1);
  numBytes += cDelay_init(this, &cDelay_Cyt5ljfN, 0.0f);
  numBytes += cVar_init_f(&cVar_KZzpRZHu, 5000.0f);
  numBytes += cBinop_init(&cBinop_EaLgdUhr, 0.0f); // __mul
  numBytes += cRandom_init(&cRandom_YHJH6zTc, 1738728339);
  numBytes += cSlice_init(&cSlice_H8WLX0Iq, 1, 1);
  numBytes += cRandom_init(&cRandom_PiQsvku9, 1535940773);
  numBytes += cSlice_init(&cSlice_jIX7xxc7, 1, 1);
  numBytes += cDelay_init(this, &cDelay_PqaUaY8t, 0.0f);
  numBytes += cVar_init_f(&cVar_QQ3c7mjd, 20.0f);
  numBytes += cBinop_init(&cBinop_0EEBEXb9, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_OIqXkG1F, 0.0f);
  numBytes += cSlice_init(&cSlice_5Qo8DRgA, 1, -1);
  numBytes += cSlice_init(&cSlice_8dT8qj1B, 1, -1);
  numBytes += cVar_init_f(&cVar_L86GS0rj, 0.0f);
  numBytes += cVar_init_f(&cVar_pOgk2fvX, 20.0f);
  numBytes += cVar_init_f(&cVar_rRmXwkhu, 0.0f);
  numBytes += cVar_init_f(&cVar_hdQhtWbh, 0.0f);
  numBytes += cVar_init_f(&cVar_BGG0hetm, 0.0f);
  numBytes += cSlice_init(&cSlice_y08LbGNS, 1, 1);
  numBytes += cSlice_init(&cSlice_ov2A0O1C, 0, 1);
  numBytes += cBinop_init(&cBinop_96fhtK7S, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_quEGVJ1U, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_Y9zFco5H, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_ea3HLll1, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_zeg3ioTW, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_khxlaUhk, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_5P1Hb7z4, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_Gqj0ryco, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_NXTkXCSs, 1.0f);
  numBytes += cVar_init_f(&cVar_OwvzQoYk, 0.0f);
  numBytes += cVar_init_f(&cVar_s8NSUgUT, 0.0f);
  numBytes += cDelay_init(this, &cDelay_9cTclMV7, 0.0f);
  numBytes += cVar_init_f(&cVar_AVMDlWey, 500.0f);
  numBytes += cBinop_init(&cBinop_hkTMVp8Q, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_ottfoJXb, 1.0f);
  numBytes += cDelay_init(this, &cDelay_gRRCpeNl, 20.0f);
  numBytes += cDelay_init(this, &cDelay_li9JZJAJ, 20.0f);
  numBytes += cDelay_init(this, &cDelay_bDp0Em7l, 20.0f);
  numBytes += cDelay_init(this, &cDelay_KYdtSpcr, 30.0f);
  numBytes += cDelay_init(this, &cDelay_QrGvT5Yt, 30.0f);
  numBytes += cDelay_init(this, &cDelay_nvxwvLIr, 30.0f);
  numBytes += cDelay_init(this, &cDelay_S5MaK3OA, 30.0f);
  numBytes += cVar_init_f(&cVar_8CyP6UBV, 0.0f);
  numBytes += cVar_init_f(&cVar_qoAHRdJi, 0.0f);
  numBytes += cVar_init_f(&cVar_u2p8tCx9, 0.0f);
  numBytes += cVar_init_f(&cVar_HkiDCFMJ, 1.0f);
  numBytes += cDelay_init(this, &cDelay_kLoEC4eE, 0.0f);
  numBytes += cVar_init_f(&cVar_U4EkIXYq, 2000.0f);
  numBytes += cBinop_init(&cBinop_DF6o1oSK, 0.0f); // __mul
  numBytes += cDelay_init(this, &cDelay_ElIMyhI4, 1000.0f);
  numBytes += cRandom_init(&cRandom_NjsBlyXK, -185236850);
  numBytes += cSlice_init(&cSlice_pFc3oYz0, 1, 1);
  numBytes += cDelay_init(this, &cDelay_5umfRAyp, 0.0f);
  numBytes += cVar_init_f(&cVar_pS2KruIk, 1000.0f);
  numBytes += cBinop_init(&cBinop_chgNfAfk, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_V503mQR2, 1.0f);
  numBytes += cDelay_init(this, &cDelay_J1E6pX7q, 5000.0f);
  numBytes += cVar_init_f(&cVar_I3lWjcEm, 1.0f);
  numBytes += cRandom_init(&cRandom_j8IJW7sl, -1743963944);
  numBytes += cSlice_init(&cSlice_pZkf2HDY, 1, 1);
  numBytes += cDelay_init(this, &cDelay_41evEucb, 5000.0f);
  numBytes += cDelay_init(this, &cDelay_CZ43RpKE, 0.0f);
  numBytes += cVar_init_f(&cVar_sgz0sbH8, 20.0f);
  numBytes += cBinop_init(&cBinop_ZnzomJYv, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_y46Bm6Zu, 0.0f);
  numBytes += cSlice_init(&cSlice_psW4eCG8, 1, -1);
  numBytes += cSlice_init(&cSlice_7m0Inwpv, 1, -1);
  numBytes += cVar_init_f(&cVar_A9IDcNzF, 0.0f);
  numBytes += cVar_init_f(&cVar_v7M1WUqA, 20.0f);
  numBytes += cVar_init_f(&cVar_lzt4oFBo, 0.0f);
  numBytes += cVar_init_f(&cVar_RNoZ0NsK, 0.0f);
  numBytes += cVar_init_f(&cVar_EZN8BtLf, 0.0f);
  numBytes += cSlice_init(&cSlice_HemW1RcB, 1, 1);
  numBytes += cSlice_init(&cSlice_MEWQBFaB, 0, 1);
  numBytes += cBinop_init(&cBinop_p1hgJmgs, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_bIceu0a5, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_DViOseny, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_9G2yErcz, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_rv88LeR6, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_QuUF7Uto, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_8zEWHjmM, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_oXfbQjHp, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_yxSrksL3, 0.0f);
  numBytes += cRandom_init(&cRandom_GbGZkESD, -612919467);
  numBytes += cSlice_init(&cSlice_I86YF72x, 1, 1);
  numBytes += cDelay_init(this, &cDelay_a5wfCUjy, 0.0f);
  numBytes += cVar_init_f(&cVar_PyhZPnaU, 1000.0f);
  numBytes += cBinop_init(&cBinop_Gk65LOcD, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_YrGju7j8, 1.0f);
  numBytes += cDelay_init(this, &cDelay_7U1bb9hT, 5000.0f);
  numBytes += cVar_init_f(&cVar_ZZUedFlg, 1.0f);
  numBytes += cRandom_init(&cRandom_psO9A26B, 1755727079);
  numBytes += cSlice_init(&cSlice_ecqJ4sfE, 1, 1);
  numBytes += cDelay_init(this, &cDelay_2vxR4c2p, 5000.0f);
  numBytes += cDelay_init(this, &cDelay_pIKdjt2k, 0.0f);
  numBytes += cVar_init_f(&cVar_HZC1ip7W, 20.0f);
  numBytes += cBinop_init(&cBinop_NmPYD90t, 0.0f); // __mul
  numBytes += cVar_init_f(&cVar_eOO7M87x, 0.0f);
  numBytes += cSlice_init(&cSlice_xWoOn2P4, 1, -1);
  numBytes += cSlice_init(&cSlice_35rqWCye, 1, -1);
  numBytes += cVar_init_f(&cVar_8np9dfCS, 0.0f);
  numBytes += cVar_init_f(&cVar_yC2Epoyf, 20.0f);
  numBytes += cVar_init_f(&cVar_tPIfC3EU, 0.0f);
  numBytes += cVar_init_f(&cVar_uGmXX6Pk, 0.0f);
  numBytes += cVar_init_f(&cVar_utPgX8hA, 0.0f);
  numBytes += cSlice_init(&cSlice_cK9ucvDU, 1, 1);
  numBytes += cSlice_init(&cSlice_ZeZu8QhV, 0, 1);
  numBytes += cBinop_init(&cBinop_pIXcJ2vz, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_cmzPEfkn, 0.0f); // __mul
  numBytes += cBinop_init(&cBinop_flOCJfnO, 0.0f); // __sub
  numBytes += cBinop_init(&cBinop_0GJHY5Lk, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_oIxuVsnq, 20.0f); // __div
  numBytes += cBinop_init(&cBinop_UGKDYVI2, 0.0f); // __div
  numBytes += cBinop_init(&cBinop_8eVEy7Al, 0.0f); // __add
  numBytes += cBinop_init(&cBinop_XTQTY9Cb, 0.0f); // __sub
  numBytes += cVar_init_f(&cVar_MdAGGFnZ, 0.0f);
  numBytes += cBinop_init(&cBinop_F0IQVI6d, 1.0f); // __add
  numBytes += cBinop_init(&cBinop_hbyRQ0zt, 30.0f); // __bimod
  numBytes += sVarf_init(&sVarf_OQxdukrC, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_Ie4VYlva, 0.5f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_nw3eEMj2, 0.5f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_ewXMsNMW, 0.5f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_jmhQqPsJ, 1.0f, 0.0f, false);
  numBytes += sVarf_init(&sVarf_zMC2F8vL, 0.0f, 0.0f, false);
  
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
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_PLadF4GM_sendMessage);
      break;
    }
    case 0xFB2DC5B6: { // button1
      mq_addMessageByTimestamp(&mq, m, 0, &cReceive_xHrx9b6t_sendMessage);
      break;
    }
    default: return;
  }
}

int Heavy_grillosychicharrasosc::getParameterInfo(int index, HvParameterInfo *info) {
  if (info != nullptr) {
    switch (index) {
      case 0: {
        info->name = "button1";
        info->hash = 0xFB2DC5B6;
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
  return 1;
}



/*
 * Send Function Implementations
 */


void Heavy_grillosychicharrasosc::cSwitchcase_Cbwk7oy4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_XuD0Af2d_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_XuD0Af2d_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_vH7CHwhb_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_Yu8ay0lQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Yu8ay0lQ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Yu8ay0lQ, 0, m, &cDelay_Yu8ay0lQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_eUIKfLve, 0, m, &cVar_eUIKfLve_sendMessage);
  cSwitchcase_PCO0VYX9_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cCast_vH7CHwhb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XuD0Af2d_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Yu8ay0lQ, 0, m, &cDelay_Yu8ay0lQ_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_eUIKfLve, 0, m, &cVar_eUIKfLve_sendMessage);
  cSwitchcase_PCO0VYX9_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_RWQj5MQd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_QuSBQYIg_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_QuSBQYIg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_A6MVYCVF_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_Nnfc7x9C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_whoE78sD, HV_BINOP_MULTIPLY, 0, m, &cBinop_whoE78sD_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_XuD0Af2d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Yu8ay0lQ, 0, m, &cDelay_Yu8ay0lQ_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_dWrblezy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Yu8ay0lQ, 2, m, &cDelay_Yu8ay0lQ_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_A6MVYCVF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_whoE78sD, HV_BINOP_MULTIPLY, 1, m, &cBinop_whoE78sD_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_whoE78sD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_dWrblezy_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_P3KL6noN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_LNbTDWEF_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_hbyRQ0zt, HV_BINOP_MOD_BIPOLAR, 0, m, &cBinop_hbyRQ0zt_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_eUIKfLve_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_GREATER_THAN, 0.0f, 0, m, &cBinop_WuU3C4Lp_sendMessage);
  cIf_onMessage(_c, &Context(_c)->cIf_hOFE8kyf, 0, m, &cIf_hOFE8kyf_sendMessage);
}

void Heavy_grillosychicharrasosc::cUnop_7lFwUGAG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_F0IQVI6d, HV_BINOP_ADD, 0, m, &cBinop_F0IQVI6d_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_P3KL6noN, 0, m, &cVar_P3KL6noN_sendMessage);
}

void Heavy_grillosychicharrasosc::cUnop_UGP0k8lj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_F0IQVI6d, HV_BINOP_ADD, 0, m, &cBinop_F0IQVI6d_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_P3KL6noN, 0, m, &cVar_P3KL6noN_sendMessage);
}

void Heavy_grillosychicharrasosc::cIf_hOFE8kyf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cUnop_onMessage(_c, HV_UNOP_CEIL, m, &cUnop_UGP0k8lj_sendMessage);
      break;
    }
    case 1: {
      cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_7lFwUGAG_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cBinop_WuU3C4Lp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cIf_onMessage(_c, &Context(_c)->cIf_hOFE8kyf, 1, m, &cIf_hOFE8kyf_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_mSey5KC8_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_TQ5jAajU, 0, m, &cSlice_TQ5jAajU_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_v7pWLsoa, 0, m, &cRandom_v7pWLsoa_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cBinop_7NQTkXJf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_QRu4amnD_sendMessage);
}

void Heavy_grillosychicharrasosc::cUnop_QRu4amnD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_XX4B0Ylm_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cRandom_v7pWLsoa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 8388610.0f, 0, m, &cBinop_7NQTkXJf_sendMessage);
}

void Heavy_grillosychicharrasosc::cSlice_TQ5jAajU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_v7pWLsoa, 1, m, &cRandom_v7pWLsoa_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cMsg_XX4B0Ylm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1.0f);
  sVari_onMessage(_c, &Context(_c)->sVari_7VgJQjRv, m);
}

void Heavy_grillosychicharrasosc::cUnop_MvzFBJsX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ObOUWnoI, 0, m, &cVar_ObOUWnoI_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_ObOUWnoI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_grillosychicharrasosc::cVar_mKyLpCkL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_grillosychicharrasosc::cVar_n2TyQRTN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.0f, 0, m, &cBinop_xvEgfs4S_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_SQRUBity_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_3Iq721RA, 0, m);
}

void Heavy_grillosychicharrasosc::cMsg_3iEOSrVd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_gi6wfGWj_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_gi6wfGWj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_OfvUtCed, HV_BINOP_MULTIPLY, 1, m, &cBinop_OfvUtCed_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_MnWPJHoa, HV_BINOP_MULTIPLY, 1, m, &cBinop_MnWPJHoa_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_rSCzT55f_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_q79nJAh7_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_q79nJAh7_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2KYMBCXH_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_u22bsNJt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_u22bsNJt, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_u22bsNJt, 0, m, &cDelay_u22bsNJt_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_b7X8kTRD, 0, m, &cVar_b7X8kTRD_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_2KYMBCXH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_q79nJAh7_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_u22bsNJt, 0, m, &cDelay_u22bsNJt_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_b7X8kTRD, 0, m, &cVar_b7X8kTRD_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_Ys5vXoGF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_8JCiD3xu_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_8JCiD3xu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_lEGH7x11_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_VuUO8pOT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_V9kkKiuu, HV_BINOP_MULTIPLY, 0, m, &cBinop_V9kkKiuu_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_q79nJAh7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_u22bsNJt, 0, m, &cDelay_u22bsNJt_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_GUwf6car_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_u22bsNJt, 2, m, &cDelay_u22bsNJt_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_lEGH7x11_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_V9kkKiuu, HV_BINOP_MULTIPLY, 1, m, &cBinop_V9kkKiuu_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_V9kkKiuu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_GUwf6car_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_b7X8kTRD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DqCOIhPF, HV_BINOP_SUBTRACT, 0, m, &cBinop_DqCOIhPF_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_K7HGzSWC_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_1gnwmFKC_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_I9HGiHfh_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0Cq6OON0_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cCast_I9HGiHfh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IaKoKe7K, 0, m, &cVar_IaKoKe7K_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_0Cq6OON0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Q2oXPhBt_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZbtC0Rmd_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_jMqHt8CW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_suiSbvgo, 0, m, &cSlice_suiSbvgo_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_gQaBz8x0, 0, m, &cSlice_gQaBz8x0_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_B5PReqbP_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_AUvEPHcH, 0, m, &cSlice_AUvEPHcH_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_9901yvQJ, 0, m, &cSlice_9901yvQJ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sTIyL0PO_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_apMnaPfX_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cSlice_suiSbvgo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_LwIxeSF8_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_LwIxeSF8_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cSlice_gQaBz8x0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_asUbGycQ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RaaKDN2X_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_asUbGycQ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_RaaKDN2X_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cVar_1Go5tnsh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jj0I2Gyy_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_n7BdOojc_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_XyTmFvhx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_dJJFMQQg_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cSwitchcase_dJJFMQQg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rfoxT6AR_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_OfvUtCed, HV_BINOP_MULTIPLY, 0, m, &cBinop_OfvUtCed_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_mV5g0T3w, HV_BINOP_DIVIDE, 1, m, &cBinop_mV5g0T3w_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_VuUO8pOT, 0, m, &cVar_VuUO8pOT_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cCast_rfoxT6AR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_E9AObh1O_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cVar_yUmE2zKD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6x8OpbvE, HV_BINOP_SUBTRACT, 1, m, &cBinop_6x8OpbvE_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_kumb9KeP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IaKoKe7K, 0, m, &cVar_IaKoKe7K_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_IaKoKe7K_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6HWKc81T, HV_BINOP_ADD, 0, m, &cBinop_6HWKc81T_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Cq97QXLx, HV_BINOP_ADD, 0, m, &cBinop_Cq97QXLx_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_SQRUBity, 0, m, &cVar_SQRUBity_sendMessage);
}

void Heavy_grillosychicharrasosc::cSlice_AUvEPHcH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_jj0I2Gyy_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_n7BdOojc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cSlice_9901yvQJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LkvaFqZl_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QW4mOUH0_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cBinop_miFiRetk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_b7X8kTRD, 1, m, &cVar_b7X8kTRD_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_MnWPJHoa_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_miFiRetk_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_OfvUtCed_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_RwHb5AJR_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_RwHb5AJR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DqCOIhPF, HV_BINOP_SUBTRACT, 1, m, &cBinop_DqCOIhPF_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_DqCOIhPF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_b7X8kTRD, 1, m, &cVar_b7X8kTRD_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_MLSWh2ar_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_rSCzT55f_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_nt8XXNDD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_rSCzT55f_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Cq97QXLx, HV_BINOP_ADD, 1, m, &cBinop_Cq97QXLx_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6HWKc81T, HV_BINOP_ADD, 1, m, &cBinop_6HWKc81T_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_K7HGzSWC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_1gnwmFKC_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cBinop_6HWKc81T_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_IaKoKe7K, 1, m, &cVar_IaKoKe7K_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_mV5g0T3w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2EhbrWuc, HV_BINOP_DIVIDE, 1, m, &cBinop_2EhbrWuc_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_2EhbrWuc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Cq97QXLx, HV_BINOP_ADD, 1, m, &cBinop_Cq97QXLx_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6HWKc81T, HV_BINOP_ADD, 1, m, &cBinop_6HWKc81T_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_n7BdOojc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_mV5g0T3w, HV_BINOP_DIVIDE, 0, m, &cBinop_mV5g0T3w_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_jj0I2Gyy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_MnWPJHoa, HV_BINOP_MULTIPLY, 0, m, &cBinop_MnWPJHoa_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_QW4mOUH0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6x8OpbvE, HV_BINOP_SUBTRACT, 0, m, &cBinop_6x8OpbvE_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_LkvaFqZl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kumb9KeP, 1, m, &cVar_kumb9KeP_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_Q2oXPhBt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nt8XXNDD_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cCast_ZbtC0Rmd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_kumb9KeP, 0, m, &cVar_kumb9KeP_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_Cq97QXLx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_yUmE2zKD, 0, m, &cVar_yUmE2zKD_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_LwIxeSF8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_rSCzT55f_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_AstJS1GT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_1Go5tnsh, 1, m, &cVar_1Go5tnsh_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_xvEgfs4S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_XyTmFvhx, 0, m, &cVar_XyTmFvhx_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_E9AObh1O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_OfvUtCed, HV_BINOP_MULTIPLY, 0, m, &cBinop_OfvUtCed_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_mV5g0T3w, HV_BINOP_DIVIDE, 1, m, &cBinop_mV5g0T3w_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_VuUO8pOT, 0, m, &cVar_VuUO8pOT_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_asUbGycQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_LwIxeSF8_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cCast_RaaKDN2X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_DS1seFj6_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_Cq97QXLx, HV_BINOP_ADD, 0, m, &cBinop_Cq97QXLx_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_IaKoKe7K, 1, m, &cVar_IaKoKe7K_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_6x8OpbvE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_2EhbrWuc, HV_BINOP_DIVIDE, 0, m, &cBinop_2EhbrWuc_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_DS1seFj6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_nt8XXNDD_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cCast_B5PReqbP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_1Go5tnsh, 0, m, &cVar_1Go5tnsh_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_sTIyL0PO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_MLSWh2ar_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cCast_apMnaPfX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AstJS1GT_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cSwitchcase_0E56Ry9P_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_sZfVq8jD, 0, m, &cSlice_sZfVq8jD_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_cBjjgoSs, 0, m, &cRandom_cBjjgoSs_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cBinop_07Fccqhv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_W4LTFttb_sendMessage);
}

void Heavy_grillosychicharrasosc::cUnop_W4LTFttb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hbyRQ0zt, HV_BINOP_MOD_BIPOLAR, 1, m, &cBinop_hbyRQ0zt_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_n2TyQRTN, 0, m, &cVar_n2TyQRTN_sendMessage);
}

void Heavy_grillosychicharrasosc::cRandom_cBjjgoSs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 20.0f, 0, m, &cBinop_07Fccqhv_sendMessage);
}

void Heavy_grillosychicharrasosc::cSlice_sZfVq8jD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_cBjjgoSs, 1, m, &cRandom_cBjjgoSs_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cMsg_waQ539xS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_OHJwD2Ih_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_OHJwD2Ih_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LwzhYklL, HV_BINOP_DIVIDE, 1, m, &cBinop_LwzhYklL_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_9qp5BItd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 6.28319f, 0, m, &cBinop_g0xgEbCg_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_R45Qg3wP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 0.001f, 0, m, &cBinop_NYxrAlj3_sendMessage);
}

void Heavy_grillosychicharrasosc::cUnop_Vktpfbd8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_eogoMDMN_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_LwzhYklL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_yip3Mvj2, HV_BINOP_MULTIPLY, 1, m, &cBinop_yip3Mvj2_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_COS, m, &cUnop_Vktpfbd8_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_6vxLx8Vr, HV_BINOP_DIVIDE, 0, m, &cBinop_6vxLx8Vr_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_g0xgEbCg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_LwzhYklL, HV_BINOP_DIVIDE, 0, m, &cBinop_LwzhYklL_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_6vxLx8Vr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MIN, 1.0f, 0, m, &cBinop_KWQ8SFiE_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_LYXvGp3l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 1.0f, 0, m, &cBinop_Wsj5boRx_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_Wsj5boRx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_POW, 2.0f, 0, m, &cBinop_c0YyRIgN_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_K7ebZwft, HV_BINOP_MULTIPLY, 0, m, &cBinop_K7ebZwft_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_yip3Mvj2, HV_BINOP_MULTIPLY, 0, m, &cBinop_yip3Mvj2_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_eogoMDMN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_K7ebZwft, HV_BINOP_MULTIPLY, 1, m, &cBinop_K7ebZwft_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_K7ebZwft_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_OAggoaE2_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_YvzUZ60u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9qp5BItd, 0, m, &cVar_9qp5BItd_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_5rhoA3ga_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_eRBgk2p4_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_eRBgk2p4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_nGDESKZU, 5, m);
}

void Heavy_grillosychicharrasosc::cBinop_OAggoaE2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_nGDESKZU, 4, m);
}

void Heavy_grillosychicharrasosc::cBinop_sBYYDrxv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_shVLnjCS, HV_BINOP_MULTIPLY, 0, m, &cBinop_shVLnjCS_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_yip3Mvj2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_wmR3cs6y, HV_BINOP_ADD, 1, m, &cBinop_wmR3cs6y_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_c0YyRIgN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_5rhoA3ga_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_wmR3cs6y_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_shVLnjCS, HV_BINOP_MULTIPLY, 1, m, &cBinop_shVLnjCS_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_shVLnjCS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sBiquad_k_onMessage(&Context(_c)->sBiquad_k_nGDESKZU, 1, m);
}

void Heavy_grillosychicharrasosc::cBinop_NYxrAlj3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_6vxLx8Vr, HV_BINOP_DIVIDE, 1, m, &cBinop_6vxLx8Vr_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_KWQ8SFiE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, -1.0f, 0, m, &cBinop_LYXvGp3l_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_wmR3cs6y, HV_BINOP_ADD, 0, m, &cBinop_wmR3cs6y_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2.0f, 0, m, &cBinop_sBYYDrxv_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_vlwLyyMZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_Q2YtODBe_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_Q2YtODBe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_HkobI4YQ, HV_BINOP_MULTIPLY, 1, m, &cBinop_HkobI4YQ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_NWGmmZbL, HV_BINOP_MULTIPLY, 1, m, &cBinop_NWGmmZbL_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_FXYnpodj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_J14XC6HZ_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_J14XC6HZ_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Vr5tWdRJ_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_3RJCOYcc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_3RJCOYcc, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3RJCOYcc, 0, m, &cDelay_3RJCOYcc_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bfBrGQS9, 0, m, &cVar_bfBrGQS9_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_Vr5tWdRJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_J14XC6HZ_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_3RJCOYcc, 0, m, &cDelay_3RJCOYcc_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_bfBrGQS9, 0, m, &cVar_bfBrGQS9_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_M5qb9FJm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_6UaQ42gt_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_6UaQ42gt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_yDPQIzrg_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_cZOROno5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PKYneWMg, HV_BINOP_MULTIPLY, 0, m, &cBinop_PKYneWMg_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_J14XC6HZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_3RJCOYcc, 0, m, &cDelay_3RJCOYcc_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_S6u3ul1z_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_3RJCOYcc, 2, m, &cDelay_3RJCOYcc_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_yDPQIzrg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_PKYneWMg, HV_BINOP_MULTIPLY, 1, m, &cBinop_PKYneWMg_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_PKYneWMg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_S6u3ul1z_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_bfBrGQS9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Id4eDgmg, HV_BINOP_SUBTRACT, 0, m, &cBinop_Id4eDgmg_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_8KP0bSZt_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_5y7LJokT_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_IALkIGZq_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_olTf5TCP_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cCast_IALkIGZq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_68g9fpZP, 0, m, &cVar_68g9fpZP_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_olTf5TCP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eAvouhNx_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qO9ClLqz_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_ndDSPe0t_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_b5EiwBH6, 0, m, &cSlice_b5EiwBH6_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_JQV7rzsL, 0, m, &cSlice_JQV7rzsL_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2dLqX6Uz_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_9Rcv20sv, 0, m, &cSlice_9Rcv20sv_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_H5REGhA3, 0, m, &cSlice_H5REGhA3_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_x9CLsONl_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lJd1a9G1_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cSlice_b5EiwBH6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_G2p8G4dJ_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_G2p8G4dJ_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cSlice_JQV7rzsL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EWKnOX91_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9Gc7fXz6_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_EWKnOX91_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_9Gc7fXz6_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cVar_RNwsu7Qp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QeDD2wjJ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SKzc1gku_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_TqsPRgvJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_SOXreitf_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cSwitchcase_SOXreitf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OoKTuXfx_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_HkobI4YQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_HkobI4YQ_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_U8PTT4zA, HV_BINOP_DIVIDE, 1, m, &cBinop_U8PTT4zA_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_cZOROno5, 0, m, &cVar_cZOROno5_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cCast_OoKTuXfx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YrgDY46N_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cVar_USNPbtPW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z3lEbYEy, HV_BINOP_SUBTRACT, 1, m, &cBinop_Z3lEbYEy_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_FA9HM06u_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_68g9fpZP, 0, m, &cVar_68g9fpZP_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_68g9fpZP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_sYjQzHyd, HV_BINOP_ADD, 0, m, &cBinop_sYjQzHyd_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_aVLrzYKi, HV_BINOP_ADD, 0, m, &cBinop_aVLrzYKi_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_wYXJkuu3, 0, m, &cVar_wYXJkuu3_sendMessage);
}

void Heavy_grillosychicharrasosc::cSlice_9Rcv20sv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QeDD2wjJ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SKzc1gku_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cSlice_H5REGhA3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_JqPRFbjn_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_LoWJZoQf_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cBinop_HOIkovc2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bfBrGQS9, 1, m, &cVar_bfBrGQS9_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_NWGmmZbL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_HOIkovc2_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_HkobI4YQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_LgjHNIXb_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_LgjHNIXb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Id4eDgmg, HV_BINOP_SUBTRACT, 1, m, &cBinop_Id4eDgmg_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_Id4eDgmg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_bfBrGQS9, 1, m, &cVar_bfBrGQS9_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_g8b8l7i3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_FXYnpodj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_zKMxahOq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_FXYnpodj_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_aVLrzYKi, HV_BINOP_ADD, 1, m, &cBinop_aVLrzYKi_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sYjQzHyd, HV_BINOP_ADD, 1, m, &cBinop_sYjQzHyd_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_8KP0bSZt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_5y7LJokT_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cBinop_sYjQzHyd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_68g9fpZP, 1, m, &cVar_68g9fpZP_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_U8PTT4zA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kHEXUx6A, HV_BINOP_DIVIDE, 1, m, &cBinop_kHEXUx6A_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_kHEXUx6A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_aVLrzYKi, HV_BINOP_ADD, 1, m, &cBinop_aVLrzYKi_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_sYjQzHyd, HV_BINOP_ADD, 1, m, &cBinop_sYjQzHyd_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_SKzc1gku_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_U8PTT4zA, HV_BINOP_DIVIDE, 0, m, &cBinop_U8PTT4zA_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_QeDD2wjJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NWGmmZbL, HV_BINOP_MULTIPLY, 0, m, &cBinop_NWGmmZbL_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_LoWJZoQf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Z3lEbYEy, HV_BINOP_SUBTRACT, 0, m, &cBinop_Z3lEbYEy_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_JqPRFbjn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FA9HM06u, 1, m, &cVar_FA9HM06u_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_qO9ClLqz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_FA9HM06u, 0, m, &cVar_FA9HM06u_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_eAvouhNx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zKMxahOq_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cBinop_aVLrzYKi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_USNPbtPW, 0, m, &cVar_USNPbtPW_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_G2p8G4dJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_FXYnpodj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_QsbALApc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_RNwsu7Qp, 1, m, &cVar_RNwsu7Qp_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_YrgDY46N_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_HkobI4YQ, HV_BINOP_MULTIPLY, 0, m, &cBinop_HkobI4YQ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_U8PTT4zA, HV_BINOP_DIVIDE, 1, m, &cBinop_U8PTT4zA_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_cZOROno5, 0, m, &cVar_cZOROno5_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_EWKnOX91_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_G2p8G4dJ_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cCast_9Gc7fXz6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hBWMRujS_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_aVLrzYKi, HV_BINOP_ADD, 0, m, &cBinop_aVLrzYKi_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_68g9fpZP, 1, m, &cVar_68g9fpZP_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_Z3lEbYEy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_kHEXUx6A, HV_BINOP_DIVIDE, 0, m, &cBinop_kHEXUx6A_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_hBWMRujS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zKMxahOq_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cCast_x9CLsONl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_g8b8l7i3_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cCast_2dLqX6Uz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RNwsu7Qp, 0, m, &cVar_RNwsu7Qp_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_lJd1a9G1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_QsbALApc_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cVar_wYXJkuu3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_9qp5BItd, 0, m, &cVar_9qp5BItd_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_7XMFG1Jx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_R45Qg3wP, 0, m, &cVar_R45Qg3wP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YvzUZ60u_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_4SrcHYHo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_OQxdukrC, m);
}

void Heavy_grillosychicharrasosc::cSwitchcase_ndzgTe5o_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_PFXxURNb_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ywPAqYuv_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cCast_PFXxURNb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_4KVE2N4f_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cCast_ywPAqYuv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_cyVnN6TE_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cSwitchcase_PCO0VYX9_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_77b0Z3qh, 0, m, &cSlice_77b0Z3qh_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_JF0BuKA0, 0, m, &cRandom_JF0BuKA0_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cBinop_LZtWDIcT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_dSh8jpV1_sendMessage);
}

void Heavy_grillosychicharrasosc::cUnop_dSh8jpV1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_ndzgTe5o_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cRandom_JF0BuKA0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 1.0f, 0, m, &cBinop_LZtWDIcT_sendMessage);
}

void Heavy_grillosychicharrasosc::cSlice_77b0Z3qh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_JF0BuKA0, 1, m, &cRandom_JF0BuKA0_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cSwitchcase_AZjTkGDB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_khUFGaEr, 0, m, &cSlice_khUFGaEr_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_i9t3pPrX, 0, m, &cRandom_i9t3pPrX_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cBinop_idOZvx7g_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_0SiIPBmq_sendMessage);
}

void Heavy_grillosychicharrasosc::cUnop_0SiIPBmq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 4000.0f, 0, m, &cBinop_nTtKqV7w_sendMessage);
}

void Heavy_grillosychicharrasosc::cRandom_i9t3pPrX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_idOZvx7g_sendMessage);
}

void Heavy_grillosychicharrasosc::cSlice_khUFGaEr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_i9t3pPrX, 1, m, &cRandom_i9t3pPrX_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cVar_lJiJqIrv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_uqRlI22G_sendMessage);
  cSwitchcase_M9qFHYXJ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cBinop_uqRlI22G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lJiJqIrv, 1, m, &cVar_lJiJqIrv_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_M9qFHYXJ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_262Ji6rS_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_262Ji6rS_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_lkhoEbFH_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_p7OdiHgQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_p7OdiHgQ, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_p7OdiHgQ, 0, m, &cDelay_p7OdiHgQ_sendMessage);
  cSwitchcase_0E56Ry9P_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_AZjTkGDB_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_pQzBDdyv_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cCast_lkhoEbFH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_262Ji6rS_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_p7OdiHgQ, 0, m, &cDelay_p7OdiHgQ_sendMessage);
  cSwitchcase_0E56Ry9P_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_AZjTkGDB_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_pQzBDdyv_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_L94Uxz5Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mMKWm5bv_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_mMKWm5bv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_UoyEAKfN_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_MBFODPm4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0QS5SfF7, HV_BINOP_MULTIPLY, 0, m, &cBinop_0QS5SfF7_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_262Ji6rS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_p7OdiHgQ, 0, m, &cDelay_p7OdiHgQ_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_9vXMw8jJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_p7OdiHgQ, 2, m, &cDelay_p7OdiHgQ_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_UoyEAKfN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0QS5SfF7, HV_BINOP_MULTIPLY, 1, m, &cBinop_0QS5SfF7_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_0QS5SfF7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_9vXMw8jJ_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_pQzBDdyv_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_0bPF1CDO, 0, m, &cSlice_0bPF1CDO_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_2so6wfvk, 0, m, &cRandom_2so6wfvk_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cBinop_tLBIwWgs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_pKlIlXfO_sendMessage);
}

void Heavy_grillosychicharrasosc::cUnop_pKlIlXfO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 10000.0f, 0, m, &cBinop_zBVCIRI5_sendMessage);
}

void Heavy_grillosychicharrasosc::cRandom_2so6wfvk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 2000.0f, 0, m, &cBinop_tLBIwWgs_sendMessage);
}

void Heavy_grillosychicharrasosc::cSlice_0bPF1CDO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_2so6wfvk, 1, m, &cRandom_2so6wfvk_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cSwitchcase_7XYtZaPr_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_YHMVHhtc_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_YHMVHhtc_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_7wQgkZA8_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_Cyt5ljfN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_Cyt5ljfN, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Cyt5ljfN, 0, m, &cDelay_Cyt5ljfN_sendMessage);
  cSwitchcase_NYogtbpd_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_bPVGaSha_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cCast_7wQgkZA8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_YHMVHhtc_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_Cyt5ljfN, 0, m, &cDelay_Cyt5ljfN_sendMessage);
  cSwitchcase_NYogtbpd_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_bPVGaSha_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_mq9mNoep_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_aqddLF7P_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_aqddLF7P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_vfQSCO7E_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_KZzpRZHu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EaLgdUhr, HV_BINOP_MULTIPLY, 0, m, &cBinop_EaLgdUhr_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_YHMVHhtc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_Cyt5ljfN, 0, m, &cDelay_Cyt5ljfN_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_ax2bMkL6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_Cyt5ljfN, 2, m, &cDelay_Cyt5ljfN_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_vfQSCO7E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_EaLgdUhr, HV_BINOP_MULTIPLY, 1, m, &cBinop_EaLgdUhr_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_EaLgdUhr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_ax2bMkL6_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_NYogtbpd_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_H8WLX0Iq, 0, m, &cSlice_H8WLX0Iq_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_YHJH6zTc, 0, m, &cRandom_YHJH6zTc_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cBinop_VSHSmeue_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_GwbmXk9G_sendMessage);
}

void Heavy_grillosychicharrasosc::cUnop_GwbmXk9G_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_XTbeg9bg_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cRandom_YHJH6zTc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 100.0f, 0, m, &cBinop_VSHSmeue_sendMessage);
}

void Heavy_grillosychicharrasosc::cSlice_H8WLX0Iq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_YHJH6zTc, 1, m, &cRandom_YHJH6zTc_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cSwitchcase_bPVGaSha_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_jIX7xxc7, 0, m, &cSlice_jIX7xxc7_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_PiQsvku9, 0, m, &cRandom_PiQsvku9_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cBinop_K87lg2Hy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_tvmSOMPn_sendMessage);
}

void Heavy_grillosychicharrasosc::cUnop_tvmSOMPn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_ADD, 5000.0f, 0, m, &cBinop_5x7W9Etc_sendMessage);
}

void Heavy_grillosychicharrasosc::cRandom_PiQsvku9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 5000.0f, 0, m, &cBinop_K87lg2Hy_sendMessage);
}

void Heavy_grillosychicharrasosc::cSlice_jIX7xxc7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_PiQsvku9, 1, m, &cRandom_PiQsvku9_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cMsg_p6ysPqau_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_fNoxrzOT_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_fNoxrzOT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_quEGVJ1U, HV_BINOP_MULTIPLY, 1, m, &cBinop_quEGVJ1U_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_96fhtK7S, HV_BINOP_MULTIPLY, 1, m, &cBinop_96fhtK7S_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_yIKEkqJb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_mcNBLSnI_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_mcNBLSnI_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2sSdeL2o_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_PqaUaY8t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_PqaUaY8t, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PqaUaY8t, 0, m, &cDelay_PqaUaY8t_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_OIqXkG1F, 0, m, &cVar_OIqXkG1F_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_2sSdeL2o_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_mcNBLSnI_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_PqaUaY8t, 0, m, &cDelay_PqaUaY8t_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_OIqXkG1F, 0, m, &cVar_OIqXkG1F_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_LhmEaKsR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_x30WhkBe_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_x30WhkBe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_SivKmNdC_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_QQ3c7mjd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0EEBEXb9, HV_BINOP_MULTIPLY, 0, m, &cBinop_0EEBEXb9_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_mcNBLSnI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_PqaUaY8t, 0, m, &cDelay_PqaUaY8t_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_LnBVPhpy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_PqaUaY8t, 2, m, &cDelay_PqaUaY8t_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_SivKmNdC_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0EEBEXb9, HV_BINOP_MULTIPLY, 1, m, &cBinop_0EEBEXb9_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_0EEBEXb9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_LnBVPhpy_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_OIqXkG1F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y9zFco5H, HV_BINOP_SUBTRACT, 0, m, &cBinop_Y9zFco5H_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_f28B4zty_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_dzAK6N91_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XnLeU43m_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2idDL7H2_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cCast_XnLeU43m_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BGG0hetm, 0, m, &cVar_BGG0hetm_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_2idDL7H2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HVzaY7BS_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_jVJK1QaI_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_XTbeg9bg_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_5Qo8DRgA, 0, m, &cSlice_5Qo8DRgA_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_8dT8qj1B, 0, m, &cSlice_8dT8qj1B_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_L9XikDLN_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_y08LbGNS, 0, m, &cSlice_y08LbGNS_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_ov2A0O1C, 0, m, &cSlice_ov2A0O1C_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_71qBrZnH_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_XOJVBFJe_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cSlice_5Qo8DRgA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_tCM7NJzz_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_tCM7NJzz_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cSlice_8dT8qj1B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gZMON85b_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fx59ifmX_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_gZMON85b_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fx59ifmX_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cVar_L86GS0rj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5TUORvyu_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0Zhcg7Yj_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_pOgk2fvX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_1xin6sLZ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cSwitchcase_1xin6sLZ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_O8Hz0Abw_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_quEGVJ1U, HV_BINOP_MULTIPLY, 0, m, &cBinop_quEGVJ1U_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_zeg3ioTW, HV_BINOP_DIVIDE, 1, m, &cBinop_zeg3ioTW_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_QQ3c7mjd, 0, m, &cVar_QQ3c7mjd_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cCast_O8Hz0Abw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NQ2cqRZG_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cVar_rRmXwkhu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Gqj0ryco, HV_BINOP_SUBTRACT, 1, m, &cBinop_Gqj0ryco_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_hdQhtWbh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BGG0hetm, 0, m, &cVar_BGG0hetm_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_BGG0hetm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ea3HLll1, HV_BINOP_ADD, 0, m, &cBinop_ea3HLll1_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5P1Hb7z4, HV_BINOP_ADD, 0, m, &cBinop_5P1Hb7z4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_OwvzQoYk, 0, m, &cVar_OwvzQoYk_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 100.0f, 0, m, &cBinop_2gK7CJpd_sendMessage);
}

void Heavy_grillosychicharrasosc::cSlice_y08LbGNS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5TUORvyu_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0Zhcg7Yj_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cSlice_ov2A0O1C_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_QwN4hcs7_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_fz4B2R0F_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cBinop_Zkut63Cf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OIqXkG1F, 1, m, &cVar_OIqXkG1F_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_96fhtK7S_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Zkut63Cf_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_quEGVJ1U_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_QoV1xBwp_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_QoV1xBwp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Y9zFco5H, HV_BINOP_SUBTRACT, 1, m, &cBinop_Y9zFco5H_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_Y9zFco5H_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_OIqXkG1F, 1, m, &cVar_OIqXkG1F_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_ObZXda0t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_yIKEkqJb_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_d0ISqZnl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_yIKEkqJb_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5P1Hb7z4, HV_BINOP_ADD, 1, m, &cBinop_5P1Hb7z4_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ea3HLll1, HV_BINOP_ADD, 1, m, &cBinop_ea3HLll1_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_f28B4zty_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_dzAK6N91_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cBinop_ea3HLll1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_BGG0hetm, 1, m, &cVar_BGG0hetm_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_zeg3ioTW_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_khxlaUhk, HV_BINOP_DIVIDE, 1, m, &cBinop_khxlaUhk_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_khxlaUhk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_5P1Hb7z4, HV_BINOP_ADD, 1, m, &cBinop_5P1Hb7z4_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_ea3HLll1, HV_BINOP_ADD, 1, m, &cBinop_ea3HLll1_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_0Zhcg7Yj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_zeg3ioTW, HV_BINOP_DIVIDE, 0, m, &cBinop_zeg3ioTW_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_5TUORvyu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_96fhtK7S, HV_BINOP_MULTIPLY, 0, m, &cBinop_96fhtK7S_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_QwN4hcs7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hdQhtWbh, 1, m, &cVar_hdQhtWbh_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_fz4B2R0F_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Gqj0ryco, HV_BINOP_SUBTRACT, 0, m, &cBinop_Gqj0ryco_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_jVJK1QaI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_hdQhtWbh, 0, m, &cVar_hdQhtWbh_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_HVzaY7BS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_d0ISqZnl_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cBinop_5P1Hb7z4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_rRmXwkhu, 0, m, &cVar_rRmXwkhu_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_tCM7NJzz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_yIKEkqJb_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_zYn8oOMA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_L86GS0rj, 1, m, &cVar_L86GS0rj_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_NQ2cqRZG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_quEGVJ1U, HV_BINOP_MULTIPLY, 0, m, &cBinop_quEGVJ1U_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_zeg3ioTW, HV_BINOP_DIVIDE, 1, m, &cBinop_zeg3ioTW_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_QQ3c7mjd, 0, m, &cVar_QQ3c7mjd_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_fx59ifmX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_MuUhe7YQ_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_5P1Hb7z4, HV_BINOP_ADD, 0, m, &cBinop_5P1Hb7z4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_BGG0hetm, 1, m, &cVar_BGG0hetm_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_gZMON85b_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_tCM7NJzz_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cBinop_Gqj0ryco_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_khxlaUhk, HV_BINOP_DIVIDE, 0, m, &cBinop_khxlaUhk_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_MuUhe7YQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_d0ISqZnl_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cCast_71qBrZnH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ObZXda0t_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cCast_L9XikDLN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_L86GS0rj, 0, m, &cVar_L86GS0rj_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_XOJVBFJe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_zYn8oOMA_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cVar_NXTkXCSs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_MmUXlvgn_sendMessage);
  cSwitchcase_7XYtZaPr_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cBinop_MmUXlvgn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_NXTkXCSs, 1, m, &cVar_NXTkXCSs_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_OwvzQoYk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_grillosychicharrasosc::cVar_s8NSUgUT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
}

void Heavy_grillosychicharrasosc::cCast_AJdW1FPq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_DyMtiyRr_sendMessage(_c, 0, m);
  cSwitchcase_ZIJ4W7mW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cCast_QubbZ0D8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IYPgHCrh_sendMessage(_c, 0, m);
  cSwitchcase_JRFly6Hw_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cCast_6UkvfsRs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_RPMD2deY_sendMessage(_c, 0, m);
  cSwitchcase_DO95o62p_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cCast_xi3LmSMS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_kAHAtOKN_sendMessage(_c, 0, m);
  cSwitchcase_nmH9dcXV_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cCast_BjPyovvN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_NZ5bNGXY_sendMessage(_c, 0, m);
  cSwitchcase_RyT5ZXVQ_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cCast_j9PNCChJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_yzwGR7Nb_sendMessage(_c, 0, m);
  cSwitchcase_6ESnmxbt_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cCast_YKbiM2Yc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_xPpl2QEo_sendMessage(_c, 0, m);
  cSwitchcase_7qmFv4m2_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cCast_ag7ixMZ3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_eP6bEtJO_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cSwitchcase_Kstu0Sqb_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_IeCZWF9q_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_IeCZWF9q_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BFhDUGdS_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_9cTclMV7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_9cTclMV7, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9cTclMV7, 0, m, &cDelay_9cTclMV7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AJdW1FPq_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_BFhDUGdS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_IeCZWF9q_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_9cTclMV7, 0, m, &cDelay_9cTclMV7_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_AJdW1FPq_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_RQtgzNmD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_LWwHKmvR_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_LWwHKmvR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_ZYlNZIe7_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_AVMDlWey_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hkTMVp8Q, HV_BINOP_MULTIPLY, 0, m, &cBinop_hkTMVp8Q_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_IeCZWF9q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_9cTclMV7, 0, m, &cDelay_9cTclMV7_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_YHtR9sI5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_9cTclMV7, 2, m, &cDelay_9cTclMV7_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_ZYlNZIe7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_hkTMVp8Q, HV_BINOP_MULTIPLY, 1, m, &cBinop_hkTMVp8Q_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_hkTMVp8Q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_YHtR9sI5_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_ottfoJXb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_BI6RTa4n_sendMessage);
  cSwitchcase_Kstu0Sqb_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cBinop_BI6RTa4n_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ottfoJXb, 1, m, &cVar_ottfoJXb_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_JRFly6Hw_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_yCRKlYhO_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_yCRKlYhO_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_gRRCpeNl, 1, m, &cDelay_gRRCpeNl_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kTkKM3lN_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_gRRCpeNl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_gRRCpeNl, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6UkvfsRs_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_yCRKlYhO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_gRRCpeNl, 0, m, &cDelay_gRRCpeNl_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_kTkKM3lN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_gRRCpeNl, 0, m, &cDelay_gRRCpeNl_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_nmH9dcXV_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_UxxCBAm2_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_UxxCBAm2_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_li9JZJAJ, 1, m, &cDelay_li9JZJAJ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Jq4NC0G9_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_li9JZJAJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_li9JZJAJ, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_BjPyovvN_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_UxxCBAm2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_li9JZJAJ, 0, m, &cDelay_li9JZJAJ_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_Jq4NC0G9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_li9JZJAJ, 0, m, &cDelay_li9JZJAJ_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_6ESnmxbt_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_t4IRbPTR_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_t4IRbPTR_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_bDp0Em7l, 1, m, &cDelay_bDp0Em7l_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_sFIJQhen_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_bDp0Em7l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_bDp0Em7l, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YKbiM2Yc_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_t4IRbPTR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_bDp0Em7l, 0, m, &cDelay_bDp0Em7l_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_sFIJQhen_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_bDp0Em7l, 0, m, &cDelay_bDp0Em7l_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_ZIJ4W7mW_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_JAF9aq0A_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_JAF9aq0A_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_KYdtSpcr, 1, m, &cDelay_KYdtSpcr_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HCoUAokI_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_KYdtSpcr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_KYdtSpcr, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QubbZ0D8_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_JAF9aq0A_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_KYdtSpcr, 0, m, &cDelay_KYdtSpcr_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_HCoUAokI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_KYdtSpcr, 0, m, &cDelay_KYdtSpcr_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_DO95o62p_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_NOEJplFD_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_NOEJplFD_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_QrGvT5Yt, 1, m, &cDelay_QrGvT5Yt_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_x8Nl8tQI_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_QrGvT5Yt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_QrGvT5Yt, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xi3LmSMS_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_NOEJplFD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_QrGvT5Yt, 0, m, &cDelay_QrGvT5Yt_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_x8Nl8tQI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_QrGvT5Yt, 0, m, &cDelay_QrGvT5Yt_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_RyT5ZXVQ_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_WGhcCpSe_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_WGhcCpSe_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_nvxwvLIr, 1, m, &cDelay_nvxwvLIr_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_oPDXrTDJ_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_nvxwvLIr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_nvxwvLIr, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_j9PNCChJ_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_WGhcCpSe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_nvxwvLIr, 0, m, &cDelay_nvxwvLIr_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_oPDXrTDJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_nvxwvLIr, 0, m, &cDelay_nvxwvLIr_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_7qmFv4m2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_qf5Y3e97_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_qf5Y3e97_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_S5MaK3OA, 1, m, &cDelay_S5MaK3OA_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_OGDc7kV1_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_S5MaK3OA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_S5MaK3OA, m);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ag7ixMZ3_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_qf5Y3e97_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_S5MaK3OA, 0, m, &cDelay_S5MaK3OA_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_OGDc7kV1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_S5MaK3OA, 0, m, &cDelay_S5MaK3OA_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_8CyP6UBV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_ewXMsNMW, m);
}

void Heavy_grillosychicharrasosc::cVar_qoAHRdJi_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_nw3eEMj2, m);
}

void Heavy_grillosychicharrasosc::cVar_u2p8tCx9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_Ie4VYlva, m);
}

void Heavy_grillosychicharrasosc::cVar_HkiDCFMJ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_4VgONu0p_sendMessage);
  cSwitchcase_a8yLBkSB_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cBinop_4VgONu0p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_HkiDCFMJ, 1, m, &cVar_HkiDCFMJ_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_a8yLBkSB_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_E1uwUDIp_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_E1uwUDIp_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tSAO1GqL_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_kLoEC4eE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_kLoEC4eE, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kLoEC4eE, 0, m, &cDelay_kLoEC4eE_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ottfoJXb, 0, m, &cVar_ottfoJXb_sendMessage);
  cSwitchcase_FtUTs4zj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cCast_tSAO1GqL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_E1uwUDIp_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_kLoEC4eE, 0, m, &cDelay_kLoEC4eE_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_ottfoJXb, 0, m, &cVar_ottfoJXb_sendMessage);
  cSwitchcase_FtUTs4zj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_kcO1FnU0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_rS9Noy4a_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_rS9Noy4a_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_raPv7gtG_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_U4EkIXYq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DF6o1oSK, HV_BINOP_MULTIPLY, 0, m, &cBinop_DF6o1oSK_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_E1uwUDIp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_kLoEC4eE, 0, m, &cDelay_kLoEC4eE_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_Xh1pArzI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_kLoEC4eE, 2, m, &cDelay_kLoEC4eE_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_raPv7gtG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DF6o1oSK, HV_BINOP_MULTIPLY, 1, m, &cBinop_DF6o1oSK_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_DF6o1oSK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_Xh1pArzI_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_FtUTs4zj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_TNvjw0Dv_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_TNvjw0Dv_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_ElIMyhI4, 1, m, &cDelay_ElIMyhI4_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2VlMbUbv_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_ElIMyhI4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_ElIMyhI4, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ottfoJXb, 0, m, &cVar_ottfoJXb_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_TNvjw0Dv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_ElIMyhI4, 0, m, &cDelay_ElIMyhI4_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_2VlMbUbv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_ElIMyhI4, 0, m, &cDelay_ElIMyhI4_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_sgMtOFhI_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_pFc3oYz0, 0, m, &cSlice_pFc3oYz0_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_NjsBlyXK, 0, m, &cRandom_NjsBlyXK_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cBinop_OBSHeIX0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_ZQJscbhm_sendMessage);
}

void Heavy_grillosychicharrasosc::cUnop_ZQJscbhm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_J1E6pX7q, 1, m, &cDelay_J1E6pX7q_sendMessage);
}

void Heavy_grillosychicharrasosc::cRandom_NjsBlyXK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000.0f, 0, m, &cBinop_OBSHeIX0_sendMessage);
}

void Heavy_grillosychicharrasosc::cSlice_pFc3oYz0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_NjsBlyXK, 1, m, &cRandom_NjsBlyXK_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cSwitchcase_84idmOMj_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_WFJPLhdD_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_WFJPLhdD_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_tngapHCw_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_5umfRAyp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_5umfRAyp, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5umfRAyp, 0, m, &cDelay_5umfRAyp_sendMessage);
  cSwitchcase_sgMtOFhI_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_1PZetlpz_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cCast_tngapHCw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_WFJPLhdD_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_5umfRAyp, 0, m, &cDelay_5umfRAyp_sendMessage);
  cSwitchcase_sgMtOFhI_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_1PZetlpz_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_XOFJBKrB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_ZjVhKfR8_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_ZjVhKfR8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_EK0xFzzX_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_pS2KruIk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_chgNfAfk, HV_BINOP_MULTIPLY, 0, m, &cBinop_chgNfAfk_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_WFJPLhdD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_5umfRAyp, 0, m, &cDelay_5umfRAyp_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_R30E2bCV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_5umfRAyp, 2, m, &cDelay_5umfRAyp_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_EK0xFzzX_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_chgNfAfk, HV_BINOP_MULTIPLY, 1, m, &cBinop_chgNfAfk_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_chgNfAfk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_R30E2bCV_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_V503mQR2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_cJmF00rT_sendMessage);
  cSwitchcase_84idmOMj_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cBinop_cJmF00rT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_V503mQR2, 1, m, &cVar_V503mQR2_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_1PZetlpz_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_DxlzWABp_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_DxlzWABp_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_J1E6pX7q, 1, m, &cDelay_J1E6pX7q_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_iRRDEkAR_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_J1E6pX7q_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_J1E6pX7q, m);
  cVar_onMessage(_c, &Context(_c)->cVar_I3lWjcEm, 0, m, &cVar_I3lWjcEm_sendMessage);
  cSwitchcase_17VP22zG_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_tActedTf_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_DxlzWABp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_J1E6pX7q, 0, m, &cDelay_J1E6pX7q_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_iRRDEkAR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_J1E6pX7q, 0, m, &cDelay_J1E6pX7q_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_I3lWjcEm_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_AFG1TkyL_sendMessage);
  cMsg_UyOu1Ss6_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cBinop_AFG1TkyL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_I3lWjcEm, 1, m, &cVar_I3lWjcEm_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_tActedTf_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_pZkf2HDY, 0, m, &cSlice_pZkf2HDY_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_j8IJW7sl, 0, m, &cRandom_j8IJW7sl_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cBinop_CqpVnGSo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Ablg45kn_sendMessage);
}

void Heavy_grillosychicharrasosc::cUnop_Ablg45kn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_41evEucb, 1, m, &cDelay_41evEucb_sendMessage);
}

void Heavy_grillosychicharrasosc::cRandom_j8IJW7sl_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000.0f, 0, m, &cBinop_CqpVnGSo_sendMessage);
}

void Heavy_grillosychicharrasosc::cSlice_pZkf2HDY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_j8IJW7sl, 1, m, &cRandom_j8IJW7sl_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cSwitchcase_17VP22zG_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_92bjR1cG_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_92bjR1cG_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_41evEucb, 1, m, &cDelay_41evEucb_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_SV5aDU0X_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_41evEucb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_41evEucb, m);
  cVar_onMessage(_c, &Context(_c)->cVar_I3lWjcEm, 0, m, &cVar_I3lWjcEm_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_92bjR1cG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_41evEucb, 0, m, &cDelay_41evEucb_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_SV5aDU0X_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_41evEucb, 0, m, &cDelay_41evEucb_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_Ypo4ingG_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_1Oz9TWlk_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_1Oz9TWlk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_bIceu0a5, HV_BINOP_MULTIPLY, 1, m, &cBinop_bIceu0a5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_p1hgJmgs, HV_BINOP_MULTIPLY, 1, m, &cBinop_p1hgJmgs_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_HGWyZfQk_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_ql3UBbmu_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_ql3UBbmu_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_RaZJZmvw_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_CZ43RpKE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_CZ43RpKE, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CZ43RpKE, 0, m, &cDelay_CZ43RpKE_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_y46Bm6Zu, 0, m, &cVar_y46Bm6Zu_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_RaZJZmvw_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_ql3UBbmu_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_CZ43RpKE, 0, m, &cDelay_CZ43RpKE_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_y46Bm6Zu, 0, m, &cVar_y46Bm6Zu_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_TsKNQGgZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_MbWwxM0i_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_MbWwxM0i_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_CAWdFQ4V_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_sgz0sbH8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZnzomJYv, HV_BINOP_MULTIPLY, 0, m, &cBinop_ZnzomJYv_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_ql3UBbmu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_CZ43RpKE, 0, m, &cDelay_CZ43RpKE_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_ic3FAA6P_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_CZ43RpKE, 2, m, &cDelay_CZ43RpKE_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_CAWdFQ4V_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_ZnzomJYv, HV_BINOP_MULTIPLY, 1, m, &cBinop_ZnzomJYv_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_ZnzomJYv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_ic3FAA6P_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_y46Bm6Zu_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DViOseny, HV_BINOP_SUBTRACT, 0, m, &cBinop_DViOseny_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_Zo1wzf0f_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_3uhvegNS_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_6uxqwjiH_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_8yhx1Npx_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cCast_6uxqwjiH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EZN8BtLf, 0, m, &cVar_EZN8BtLf_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_8yhx1Npx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_H20LG1xg_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_eZFq3xOR_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_KUSUXSCG_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_psW4eCG8, 0, m, &cSlice_psW4eCG8_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_7m0Inwpv, 0, m, &cSlice_7m0Inwpv_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_3DQu3LKQ_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_HemW1RcB, 0, m, &cSlice_HemW1RcB_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_MEWQBFaB, 0, m, &cSlice_MEWQBFaB_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_qv5EJqbZ_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QFcaq8s1_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cSlice_psW4eCG8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_Njw4S64e_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_Njw4S64e_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cSlice_7m0Inwpv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZBGL1L65_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SP1OHu8E_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_ZBGL1L65_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_SP1OHu8E_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cVar_A9IDcNzF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5krcrkWQ_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0QnbITFr_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_v7M1WUqA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_v3nlIKKL_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cSwitchcase_v3nlIKKL_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_TH8lc9hP_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_bIceu0a5, HV_BINOP_MULTIPLY, 0, m, &cBinop_bIceu0a5_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_rv88LeR6, HV_BINOP_DIVIDE, 1, m, &cBinop_rv88LeR6_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_sgz0sbH8, 0, m, &cVar_sgz0sbH8_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cCast_TH8lc9hP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_5VXiDuXB_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cVar_lzt4oFBo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oXfbQjHp, HV_BINOP_SUBTRACT, 1, m, &cBinop_oXfbQjHp_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_RNoZ0NsK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EZN8BtLf, 0, m, &cVar_EZN8BtLf_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_EZN8BtLf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_9G2yErcz, HV_BINOP_ADD, 0, m, &cBinop_9G2yErcz_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8zEWHjmM, HV_BINOP_ADD, 0, m, &cBinop_8zEWHjmM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_yxSrksL3, 0, m, &cVar_yxSrksL3_sendMessage);
}

void Heavy_grillosychicharrasosc::cSlice_HemW1RcB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_5krcrkWQ_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_0QnbITFr_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cSlice_MEWQBFaB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_77hkn075_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_B0cgen1l_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cBinop_aFhbokg6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_y46Bm6Zu, 1, m, &cVar_y46Bm6Zu_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_p1hgJmgs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_aFhbokg6_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_bIceu0a5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_Q8hCu2ql_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_Q8hCu2ql_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_DViOseny, HV_BINOP_SUBTRACT, 1, m, &cBinop_DViOseny_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_DViOseny_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_y46Bm6Zu, 1, m, &cVar_y46Bm6Zu_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_GHVf6mf8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_HGWyZfQk_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_KjNFx3u3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_HGWyZfQk_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8zEWHjmM, HV_BINOP_ADD, 1, m, &cBinop_8zEWHjmM_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9G2yErcz, HV_BINOP_ADD, 1, m, &cBinop_9G2yErcz_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_Zo1wzf0f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_3uhvegNS_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cBinop_9G2yErcz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_EZN8BtLf, 1, m, &cVar_EZN8BtLf_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_rv88LeR6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QuUF7Uto, HV_BINOP_DIVIDE, 1, m, &cBinop_QuUF7Uto_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_QuUF7Uto_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8zEWHjmM, HV_BINOP_ADD, 1, m, &cBinop_8zEWHjmM_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_9G2yErcz, HV_BINOP_ADD, 1, m, &cBinop_9G2yErcz_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_5krcrkWQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_p1hgJmgs, HV_BINOP_MULTIPLY, 0, m, &cBinop_p1hgJmgs_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_0QnbITFr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_rv88LeR6, HV_BINOP_DIVIDE, 0, m, &cBinop_rv88LeR6_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_77hkn075_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RNoZ0NsK, 1, m, &cVar_RNoZ0NsK_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_B0cgen1l_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oXfbQjHp, HV_BINOP_SUBTRACT, 0, m, &cBinop_oXfbQjHp_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_eZFq3xOR_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_RNoZ0NsK, 0, m, &cVar_RNoZ0NsK_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_H20LG1xg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KjNFx3u3_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cBinop_8zEWHjmM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lzt4oFBo, 0, m, &cVar_lzt4oFBo_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_Njw4S64e_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_HGWyZfQk_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_86JKvPAP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_A9IDcNzF, 1, m, &cVar_A9IDcNzF_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_5VXiDuXB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_bIceu0a5, HV_BINOP_MULTIPLY, 0, m, &cBinop_bIceu0a5_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_rv88LeR6, HV_BINOP_DIVIDE, 1, m, &cBinop_rv88LeR6_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_sgz0sbH8, 0, m, &cVar_sgz0sbH8_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_SP1OHu8E_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_2zVoIiD2_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8zEWHjmM, HV_BINOP_ADD, 0, m, &cBinop_8zEWHjmM_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_EZN8BtLf, 1, m, &cVar_EZN8BtLf_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_ZBGL1L65_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Njw4S64e_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cBinop_oXfbQjHp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_QuUF7Uto, HV_BINOP_DIVIDE, 0, m, &cBinop_QuUF7Uto_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_2zVoIiD2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_KjNFx3u3_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cCast_qv5EJqbZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_GHVf6mf8_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cCast_3DQu3LKQ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_A9IDcNzF, 0, m, &cVar_A9IDcNzF_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_QFcaq8s1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_86JKvPAP_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cVar_yxSrksL3_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_jmhQqPsJ, m);
}

void Heavy_grillosychicharrasosc::cSwitchcase_kXjW19El_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_I86YF72x, 0, m, &cSlice_I86YF72x_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_GbGZkESD, 0, m, &cRandom_GbGZkESD_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cBinop_JFylwJxp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_zbnjIPXp_sendMessage);
}

void Heavy_grillosychicharrasosc::cUnop_zbnjIPXp_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7U1bb9hT, 1, m, &cDelay_7U1bb9hT_sendMessage);
}

void Heavy_grillosychicharrasosc::cRandom_GbGZkESD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000.0f, 0, m, &cBinop_JFylwJxp_sendMessage);
}

void Heavy_grillosychicharrasosc::cSlice_I86YF72x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_GbGZkESD, 1, m, &cRandom_GbGZkESD_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cSwitchcase_cYet3INk_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_HsOWXSIB_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_HsOWXSIB_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_R84Z2oq8_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_a5wfCUjy_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_a5wfCUjy, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_a5wfCUjy, 0, m, &cDelay_a5wfCUjy_sendMessage);
  cSwitchcase_kXjW19El_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_RkfCb5PP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cCast_R84Z2oq8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_HsOWXSIB_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_a5wfCUjy, 0, m, &cDelay_a5wfCUjy_sendMessage);
  cSwitchcase_kXjW19El_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_RkfCb5PP_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_JYsQVmzn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_iVsW13E1_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_iVsW13E1_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_jHFUXb03_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_PyhZPnaU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Gk65LOcD, HV_BINOP_MULTIPLY, 0, m, &cBinop_Gk65LOcD_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_HsOWXSIB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_a5wfCUjy, 0, m, &cDelay_a5wfCUjy_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_VT7Ojn4h_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_a5wfCUjy, 2, m, &cDelay_a5wfCUjy_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_jHFUXb03_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_Gk65LOcD, HV_BINOP_MULTIPLY, 1, m, &cBinop_Gk65LOcD_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_Gk65LOcD_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_VT7Ojn4h_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_YrGju7j8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_JuTMwHW7_sendMessage);
  cSwitchcase_cYet3INk_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cBinop_JuTMwHW7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_YrGju7j8, 1, m, &cVar_YrGju7j8_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_RkfCb5PP_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_XtSXhodI_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_XtSXhodI_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_7U1bb9hT, 1, m, &cDelay_7U1bb9hT_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_HLJGbWmI_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_7U1bb9hT_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_7U1bb9hT, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ZZUedFlg, 0, m, &cVar_ZZUedFlg_sendMessage);
  cSwitchcase_XPlfbjP2_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_XozGNktq_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_XtSXhodI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_7U1bb9hT, 0, m, &cDelay_7U1bb9hT_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_HLJGbWmI_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_7U1bb9hT, 0, m, &cDelay_7U1bb9hT_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_ZZUedFlg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_EQ, 0.0f, 0, m, &cBinop_Iq8wPRXE_sendMessage);
  cMsg_MqzXnxEP_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cBinop_Iq8wPRXE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_ZZUedFlg, 1, m, &cVar_ZZUedFlg_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_XozGNktq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7E64BD01: { // "seed"
      cSlice_onMessage(_c, &Context(_c)->cSlice_ecqJ4sfE, 0, m, &cSlice_ecqJ4sfE_sendMessage);
      break;
    }
    default: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_psO9A26B, 0, m, &cRandom_psO9A26B_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cBinop_5PvoTscH_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cUnop_onMessage(_c, HV_UNOP_FLOOR, m, &cUnop_Wp5EFefg_sendMessage);
}

void Heavy_grillosychicharrasosc::cUnop_Wp5EFefg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_2vxR4c2p, 1, m, &cDelay_2vxR4c2p_sendMessage);
}

void Heavy_grillosychicharrasosc::cRandom_psO9A26B_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MULTIPLY, 10000.0f, 0, m, &cBinop_5PvoTscH_sendMessage);
}

void Heavy_grillosychicharrasosc::cSlice_ecqJ4sfE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cRandom_onMessage(_c, &Context(_c)->cRandom_psO9A26B, 1, m, &cRandom_psO9A26B_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cSwitchcase_XPlfbjP2_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cMsg_WnUscKg8_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cMsg_WnUscKg8_sendMessage(_c, 0, m);
      cDelay_onMessage(_c, &Context(_c)->cDelay_2vxR4c2p, 1, m, &cDelay_2vxR4c2p_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_M5FzdTSj_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_2vxR4c2p_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_2vxR4c2p, m);
  cVar_onMessage(_c, &Context(_c)->cVar_ZZUedFlg, 0, m, &cVar_ZZUedFlg_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_WnUscKg8_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_2vxR4c2p, 0, m, &cDelay_2vxR4c2p_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_M5FzdTSj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_2vxR4c2p, 0, m, &cDelay_2vxR4c2p_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_O2hLJNtL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_mEHrCKVt_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_mEHrCKVt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_cmzPEfkn, HV_BINOP_MULTIPLY, 1, m, &cBinop_cmzPEfkn_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_pIXcJ2vz, HV_BINOP_MULTIPLY, 1, m, &cBinop_pIXcJ2vz_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_YxHvxcXE_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cMsg_jNid9xwK_sendMessage(_c, 0, m);
      break;
    }
    case 0x7A5B032D: { // "stop"
      cMsg_jNid9xwK_sendMessage(_c, 0, m);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_mM5UXZhs_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cDelay_pIKdjt2k_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const m) {
  cDelay_clearExecutingMessage(&Context(_c)->cDelay_pIKdjt2k, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pIKdjt2k, 0, m, &cDelay_pIKdjt2k_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_eOO7M87x, 0, m, &cVar_eOO7M87x_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_mM5UXZhs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_jNid9xwK_sendMessage(_c, 0, m);
  cDelay_onMessage(_c, &Context(_c)->cDelay_pIKdjt2k, 0, m, &cDelay_pIKdjt2k_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_eOO7M87x, 0, m, &cVar_eOO7M87x_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_VbzQyZsc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "samplerate");
  cSystem_onMessage(_c, NULL, 0, m, &cSystem_9lAUyyFV_sendMessage);
}

void Heavy_grillosychicharrasosc::cSystem_9lAUyyFV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_5l3EpQ0c_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_HZC1ip7W_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NmPYD90t, HV_BINOP_MULTIPLY, 0, m, &cBinop_NmPYD90t_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_jNid9xwK_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setSymbol(m, 0, "clear");
  cDelay_onMessage(_c, &Context(_c)->cDelay_pIKdjt2k, 0, m, &cDelay_pIKdjt2k_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_Vz02BJP2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cDelay_onMessage(_c, &Context(_c)->cDelay_pIKdjt2k, 2, m, &cDelay_pIKdjt2k_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_5l3EpQ0c_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_NmPYD90t, HV_BINOP_MULTIPLY, 1, m, &cBinop_NmPYD90t_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_NmPYD90t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_MAX, 1.0f, 0, m, &cBinop_Vz02BJP2_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_eOO7M87x_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_flOCJfnO, HV_BINOP_SUBTRACT, 0, m, &cBinop_flOCJfnO_sendMessage);
  cBinop_k_onMessage(_c, NULL, HV_BINOP_LESS_THAN_EQL, 0.0f, 0, m, &cBinop_7FflU3lv_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_DVxfVyKA_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_xGZDr5Uo_sendMessage);
      break;
    }
    case 0x3F800000: { // "1.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_rYo2LH85_sendMessage);
      break;
    }
    default: {
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cCast_xGZDr5Uo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_utPgX8hA, 0, m, &cVar_utPgX8hA_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_rYo2LH85_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_GOgJZRgL_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_5XgxrFvB_sendMessage);
}

void Heavy_grillosychicharrasosc::cSwitchcase_8N9H8BR4_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x7A5B032D: { // "stop"
      cSlice_onMessage(_c, &Context(_c)->cSlice_xWoOn2P4, 0, m, &cSlice_xWoOn2P4_sendMessage);
      break;
    }
    case 0x3E004DAB: { // "set"
      cSlice_onMessage(_c, &Context(_c)->cSlice_35rqWCye, 0, m, &cSlice_35rqWCye_sendMessage);
      break;
    }
    default: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_Z3RBmib2_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_cK9ucvDU, 0, m, &cSlice_cK9ucvDU_sendMessage);
      cSlice_onMessage(_c, &Context(_c)->cSlice_ZeZu8QhV, 0, m, &cSlice_ZeZu8QhV_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_0jRJjp0d_sendMessage);
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_QZFeunUz_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cSlice_xWoOn2P4_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cMsg_dyB1mDQj_sendMessage(_c, 0, m);
      break;
    }
    case 1: {
      cMsg_dyB1mDQj_sendMessage(_c, 0, m);
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cSlice_35rqWCye_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uAEzBQTL_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cXPHuEcs_sendMessage);
      break;
    }
    case 1: {
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_uAEzBQTL_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_cXPHuEcs_sendMessage);
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cVar_8np9dfCS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IdxNvkpt_sendMessage);
  cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3vZteMRU_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_yC2Epoyf_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_LtBibLJq_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cSwitchcase_LtBibLJq_onMessage(HeavyContextInterface *_c, void *o, int letIn, const HvMessage *const m, void *sendMessage) {
  switch (msg_getHash(m, 0)) {
    case 0x0: { // "0.0"
      cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_hvn0Mv1j_sendMessage);
      break;
    }
    default: {
      cBinop_onMessage(_c, &Context(_c)->cBinop_cmzPEfkn, HV_BINOP_MULTIPLY, 0, m, &cBinop_cmzPEfkn_sendMessage);
      cBinop_onMessage(_c, &Context(_c)->cBinop_oIxuVsnq, HV_BINOP_DIVIDE, 1, m, &cBinop_oIxuVsnq_sendMessage);
      cVar_onMessage(_c, &Context(_c)->cVar_HZC1ip7W, 0, m, &cVar_HZC1ip7W_sendMessage);
      break;
    }
  }
}

void Heavy_grillosychicharrasosc::cCast_hvn0Mv1j_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_7NeliUc7_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cVar_tPIfC3EU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XTQTY9Cb, HV_BINOP_SUBTRACT, 1, m, &cBinop_XTQTY9Cb_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_uGmXX6Pk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_utPgX8hA, 0, m, &cVar_utPgX8hA_sendMessage);
}

void Heavy_grillosychicharrasosc::cVar_utPgX8hA_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_0GJHY5Lk, HV_BINOP_ADD, 0, m, &cBinop_0GJHY5Lk_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8eVEy7Al, HV_BINOP_ADD, 0, m, &cBinop_8eVEy7Al_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_MdAGGFnZ, 0, m, &cVar_MdAGGFnZ_sendMessage);
}

void Heavy_grillosychicharrasosc::cSlice_cK9ucvDU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_IdxNvkpt_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_3vZteMRU_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cSlice_ZeZu8QhV_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  switch (letIn) {
    case 0: {
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_aId4GUTx_sendMessage);
      cCast_onMessage(_c, HV_CAST_FLOAT, 0, m, &cCast_iqmBZb7O_sendMessage);
      break;
    }
    case 1: {
      break;
    }
    default: return;
  }
}

void Heavy_grillosychicharrasosc::cBinop_iWsXH9Pe_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eOO7M87x, 1, m, &cVar_eOO7M87x_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_pIXcJ2vz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_iWsXH9Pe_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_cmzPEfkn_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_k_onMessage(_c, NULL, HV_BINOP_DIVIDE, 1000.0f, 0, m, &cBinop_sBoO1FvS_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_sBoO1FvS_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_flOCJfnO, HV_BINOP_SUBTRACT, 1, m, &cBinop_flOCJfnO_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_flOCJfnO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eOO7M87x, 1, m, &cVar_eOO7M87x_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_AbTYYZOE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cSwitchcase_YxHvxcXE_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_aoP3xZx7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_YxHvxcXE_onMessage(_c, NULL, 0, m, NULL);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8eVEy7Al, HV_BINOP_ADD, 1, m, &cBinop_8eVEy7Al_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0GJHY5Lk, HV_BINOP_ADD, 1, m, &cBinop_0GJHY5Lk_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_7FflU3lv_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cSwitchcase_DVxfVyKA_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cBinop_0GJHY5Lk_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_utPgX8hA, 1, m, &cVar_utPgX8hA_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_oIxuVsnq_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UGKDYVI2, HV_BINOP_DIVIDE, 1, m, &cBinop_UGKDYVI2_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_UGKDYVI2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_8eVEy7Al, HV_BINOP_ADD, 1, m, &cBinop_8eVEy7Al_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_0GJHY5Lk, HV_BINOP_ADD, 1, m, &cBinop_0GJHY5Lk_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_IdxNvkpt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_pIXcJ2vz, HV_BINOP_MULTIPLY, 0, m, &cBinop_pIXcJ2vz_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_3vZteMRU_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_oIxuVsnq, HV_BINOP_DIVIDE, 0, m, &cBinop_oIxuVsnq_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_iqmBZb7O_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_XTQTY9Cb, HV_BINOP_SUBTRACT, 0, m, &cBinop_XTQTY9Cb_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_aId4GUTx_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uGmXX6Pk, 1, m, &cVar_uGmXX6Pk_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_5XgxrFvB_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_uGmXX6Pk, 0, m, &cVar_uGmXX6Pk_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_GOgJZRgL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aoP3xZx7_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cBinop_8eVEy7Al_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_tPIfC3EU, 0, m, &cVar_tPIfC3EU_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_dyB1mDQj_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cSwitchcase_YxHvxcXE_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_B9sX0lQ9_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_8np9dfCS, 1, m, &cVar_8np9dfCS_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_7NeliUc7_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 20.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_cmzPEfkn, HV_BINOP_MULTIPLY, 0, m, &cBinop_cmzPEfkn_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_oIxuVsnq, HV_BINOP_DIVIDE, 1, m, &cBinop_oIxuVsnq_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_HZC1ip7W, 0, m, &cVar_HZC1ip7W_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_cXPHuEcs_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_kamMYSrY_sendMessage);
  cBinop_onMessage(_c, &Context(_c)->cBinop_8eVEy7Al, HV_BINOP_ADD, 0, m, &cBinop_8eVEy7Al_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_utPgX8hA, 1, m, &cVar_utPgX8hA_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_uAEzBQTL_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_dyB1mDQj_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cBinop_XTQTY9Cb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cBinop_onMessage(_c, &Context(_c)->cBinop_UGKDYVI2, HV_BINOP_DIVIDE, 0, m, &cBinop_UGKDYVI2_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_kamMYSrY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_aoP3xZx7_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cCast_QZFeunUz_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_B9sX0lQ9_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cCast_Z3RBmib2_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_8np9dfCS, 0, m, &cVar_8np9dfCS_sendMessage);
}

void Heavy_grillosychicharrasosc::cCast_0jRJjp0d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_AbTYYZOE_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cVar_MdAGGFnZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  sVarf_onMessage(_c, &Context(_c)->sVarf_zMC2F8vL, m);
}

void Heavy_grillosychicharrasosc::cBinop_LNbTDWEF_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_Nnfc7x9C, 0, m, &cVar_Nnfc7x9C_sendMessage);
  cUnop_onMessage(_c, HV_UNOP_ABS, m, &cUnop_MvzFBJsX_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_F0IQVI6d_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_eUIKfLve, 1, m, &cVar_eUIKfLve_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_4KVE2N4f_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, -1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_F0IQVI6d, HV_BINOP_ADD, 1, m, &cBinop_F0IQVI6d_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_ThEGFAkZ_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  sPhasor_k_onMessage(_c, &Context(_c)->sPhasor_3Iq721RA, 0, m);
}

void Heavy_grillosychicharrasosc::cBinop_hbyRQ0zt_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_mKyLpCkL, 0, m, &cVar_mKyLpCkL_sendMessage);
  cMsg_vvJRTVSO_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cMsg_vvJRTVSO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1000.0f);
  cSwitchcase_jMqHt8CW_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_cyVnN6TE_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  cBinop_onMessage(_c, &Context(_c)->cBinop_F0IQVI6d, HV_BINOP_ADD, 1, m, &cBinop_F0IQVI6d_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_deFPkyO0_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 1000.0f);
  cSwitchcase_ndDSPe0t_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cBinop_nTtKqV7w_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_deFPkyO0_sendMessage(_c, 0, m);
}

void Heavy_grillosychicharrasosc::cMsg_EK4vo7dg_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(1);
  msg_init(m, 1, msg_getTimestamp(n));
  msg_setFloat(m, 0, 8.0f);
  cVar_onMessage(_c, &Context(_c)->cVar_R45Qg3wP, 0, m, &cVar_R45Qg3wP_sendMessage);
  cCast_onMessage(_c, HV_CAST_BANG, 0, m, &cCast_YvzUZ60u_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_5x7W9Etc_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_L86GS0rj, 1, m, &cVar_L86GS0rj_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_zBVCIRI5_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_MBFODPm4, 0, m, &cVar_MBFODPm4_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_KZzpRZHu, 0, m, &cVar_KZzpRZHu_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_s8NSUgUT, 0, m, &cVar_s8NSUgUT_sendMessage);
}

void Heavy_grillosychicharrasosc::cBinop_2gK7CJpd_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_4SrcHYHo, 0, m, &cVar_4SrcHYHo_sendMessage);
}

void Heavy_grillosychicharrasosc::cMsg_IYPgHCrh_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ZEhsY3GJ, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_kAHAtOKN_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ZEhsY3GJ, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_yzwGR7Nb_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ZEhsY3GJ, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_eP6bEtJO_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 0.0f);
  msg_setFloat(m, 1, 20.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ZEhsY3GJ, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_DyMtiyRr_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ZEhsY3GJ, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_RPMD2deY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ZEhsY3GJ, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_NZ5bNGXY_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ZEhsY3GJ, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_xPpl2QEo_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setFloat(m, 0, 1.0f);
  msg_setFloat(m, 1, 25.0f);
  sLine_onMessage(_c, &Context(_c)->sLine_ZEhsY3GJ, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_UyOu1Ss6_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 2000.0f);
  cSwitchcase_KUSUXSCG_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cMsg_MqzXnxEP_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *const n) {
  HvMessage *m = nullptr;
  m = HV_MESSAGE_ON_STACK(2);
  msg_init(m, 2, msg_getTimestamp(n));
  msg_setElementToFrom(m, 0, n, 0);
  msg_setFloat(m, 1, 2000.0f);
  cSwitchcase_8N9H8BR4_onMessage(_c, NULL, 0, m, NULL);
}

void Heavy_grillosychicharrasosc::cReceive_PLadF4GM_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cMsg_Ys5vXoGF_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_VuUO8pOT, 0, m, &cVar_VuUO8pOT_sendMessage);
  cMsg_M5qb9FJm_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_cZOROno5, 0, m, &cVar_cZOROno5_sendMessage);
  cMsg_LhmEaKsR_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_QQ3c7mjd, 0, m, &cVar_QQ3c7mjd_sendMessage);
  cMsg_TsKNQGgZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_sgz0sbH8, 0, m, &cVar_sgz0sbH8_sendMessage);
  cMsg_VbzQyZsc_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_HZC1ip7W, 0, m, &cVar_HZC1ip7W_sendMessage);
  cMsg_RWQj5MQd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_Nnfc7x9C, 0, m, &cVar_Nnfc7x9C_sendMessage);
  cSwitchcase_mSey5KC8_onMessage(_c, NULL, 0, m, NULL);
  cMsg_3iEOSrVd_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_yUmE2zKD, 0, m, &cVar_yUmE2zKD_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_XyTmFvhx, 0, m, &cVar_XyTmFvhx_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_R45Qg3wP, 0, m, &cVar_R45Qg3wP_sendMessage);
  cMsg_waQ539xS_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_9qp5BItd, 0, m, &cVar_9qp5BItd_sendMessage);
  cMsg_vlwLyyMZ_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_USNPbtPW, 0, m, &cVar_USNPbtPW_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_TqsPRgvJ, 0, m, &cVar_TqsPRgvJ_sendMessage);
  cMsg_L94Uxz5Q_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_MBFODPm4, 0, m, &cVar_MBFODPm4_sendMessage);
  cMsg_mq9mNoep_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_KZzpRZHu, 0, m, &cVar_KZzpRZHu_sendMessage);
  cMsg_p6ysPqau_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_rRmXwkhu, 0, m, &cVar_rRmXwkhu_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_pOgk2fvX, 0, m, &cVar_pOgk2fvX_sendMessage);
  cMsg_RQtgzNmD_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_AVMDlWey, 0, m, &cVar_AVMDlWey_sendMessage);
  cMsg_kcO1FnU0_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_U4EkIXYq, 0, m, &cVar_U4EkIXYq_sendMessage);
  cMsg_XOFJBKrB_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_pS2KruIk, 0, m, &cVar_pS2KruIk_sendMessage);
  cMsg_Ypo4ingG_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_lzt4oFBo, 0, m, &cVar_lzt4oFBo_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_v7M1WUqA, 0, m, &cVar_v7M1WUqA_sendMessage);
  cMsg_JYsQVmzn_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_PyhZPnaU, 0, m, &cVar_PyhZPnaU_sendMessage);
  cMsg_O2hLJNtL_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_tPIfC3EU, 0, m, &cVar_tPIfC3EU_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_yC2Epoyf, 0, m, &cVar_yC2Epoyf_sendMessage);
  cSwitchcase_Cbwk7oy4_onMessage(_c, NULL, 0, m, NULL);
  cSwitchcase_M9qFHYXJ_onMessage(_c, NULL, 0, m, NULL);
  cMsg_EK4vo7dg_sendMessage(_c, 0, m);
  cVar_onMessage(_c, &Context(_c)->cVar_NXTkXCSs, 0, m, &cVar_NXTkXCSs_sendMessage);
}

void Heavy_grillosychicharrasosc::cReceive_xHrx9b6t_sendMessage(HeavyContextInterface *_c, int letIn, const HvMessage *m) {
  cVar_onMessage(_c, &Context(_c)->cVar_lJiJqIrv, 0, m, &cVar_lJiJqIrv_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_V503mQR2, 0, m, &cVar_V503mQR2_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_YrGju7j8, 0, m, &cVar_YrGju7j8_sendMessage);
  cVar_onMessage(_c, &Context(_c)->cVar_HkiDCFMJ, 0, m, &cVar_HkiDCFMJ_sendMessage);
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
    __hv_varread_i(&sVari_7VgJQjRv, VOi(Bi0));
    __hv_var_k_i(VOi(Bi1), 16807, 16807, 16807, 16807, 16807, 16807, 16807, 16807);
    __hv_mul_i(VIi(Bi0), VIi(Bi1), VOi(Bi1));
    __hv_cast_if(VIi(Bi1), VOf(Bf0));
    __hv_var_k_f(VOf(Bf1), 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f, 4.65661e-10f);
    __hv_mul_f(VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varwrite_i(&sVari_7VgJQjRv, VIi(Bi1));
    __hv_phasor_k_f(&sPhasor_3Iq721RA, VOf(Bf0));
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
    __hv_biquad_k_f(&sBiquad_k_nGDESKZU, VIf(Bf2), VOf(Bf2));
    __hv_varread_f(&sVarf_OQxdukrC, VOf(Bf1));
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_jmhQqPsJ, VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_add_f(VIf(Bf2), VIf(O1), VOf(O1));
    __hv_add_f(VIf(Bf2), VIf(O0), VOf(O0));
    __hv_phasor_k_f(&sPhasor_jheYmMUo, VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_abs_f(VIf(Bf1), VOf(Bf1));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf1), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf1), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf2), VIf(Bf1), VOf(Bf1));
    __hv_mul_f(VIf(Bf1), VIf(Bf1), VOf(Bf2));
    __hv_mul_f(VIf(Bf1), VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf0), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf5), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf5), VIf(Bf1), VOf(Bf1));
    __hv_fma_f(VIf(Bf2), VIf(Bf0), VIf(Bf1), VOf(Bf1));
    __hv_varread_f(&sVarf_ewXMsNMW, VOf(Bf0));
    __hv_phasor_k_f(&sPhasor_q0quS1iW, VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_abs_f(VIf(Bf5), VOf(Bf5));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf5), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf5), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf2), VIf(Bf5), VOf(Bf5));
    __hv_mul_f(VIf(Bf5), VIf(Bf5), VOf(Bf2));
    __hv_mul_f(VIf(Bf5), VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf3), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf6), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf6), VIf(Bf5), VOf(Bf5));
    __hv_fma_f(VIf(Bf2), VIf(Bf3), VIf(Bf5), VOf(Bf5));
    __hv_varread_f(&sVarf_Ie4VYlva, VOf(Bf3));
    __hv_phasor_k_f(&sPhasor_P3LuLCLz, VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_sub_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_abs_f(VIf(Bf6), VOf(Bf6));
    __hv_var_k_f(VOf(Bf2), 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f, 0.25f);
    __hv_sub_f(VIf(Bf6), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf6), 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f, 6.283185307179586f);
    __hv_mul_f(VIf(Bf2), VIf(Bf6), VOf(Bf6));
    __hv_mul_f(VIf(Bf6), VIf(Bf6), VOf(Bf2));
    __hv_mul_f(VIf(Bf6), VIf(Bf2), VOf(Bf4));
    __hv_mul_f(VIf(Bf4), VIf(Bf2), VOf(Bf2));
    __hv_var_k_f(VOf(Bf7), 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f, 0.007833333333333f);
    __hv_var_k_f(VOf(Bf8), -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f, -0.166666666666667f);
    __hv_fma_f(VIf(Bf4), VIf(Bf8), VIf(Bf6), VOf(Bf6));
    __hv_fma_f(VIf(Bf2), VIf(Bf7), VIf(Bf6), VOf(Bf6));
    __hv_varread_f(&sVarf_nw3eEMj2, VOf(Bf7));
    __hv_mul_f(VIf(Bf6), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf5), VIf(Bf3), VIf(Bf7), VOf(Bf7));
    __hv_fma_f(VIf(Bf1), VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_var_k_f(VOf(Bf0), 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f, 0.5f);
    __hv_mul_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_line_f(&sLine_ZEhsY3GJ, VOf(Bf7));
    __hv_mul_f(VIf(Bf0), VIf(Bf7), VOf(Bf7));
    __hv_varread_f(&sVarf_zMC2F8vL, VOf(Bf0));
    __hv_mul_f(VIf(Bf7), VIf(Bf0), VOf(Bf0));
    __hv_add_f(VIf(Bf0), VIf(O0), VOf(O0));
    __hv_add_f(VIf(Bf0), VIf(O1), VOf(O1));

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
