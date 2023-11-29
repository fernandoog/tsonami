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

#ifndef _HEAVY_CONTEXT_GRILLOSYCHICHARRASOSC_HPP_
#define _HEAVY_CONTEXT_GRILLOSYCHICHARRASOSC_HPP_

// object includes
#include "HeavyContext.hpp"
#include "HvControlVar.h"
#include "HvMath.h"
#include "HvControlCast.h"
#include "HvControlUnop.h"
#include "HvSignalPhasor.h"
#include "HvControlBinop.h"
#include "HvControlDelay.h"
#include "HvControlRandom.h"
#include "HvSignalBiquad.h"
#include "HvControlSlice.h"
#include "HvControlIf.h"
#include "HvControlSystem.h"
#include "HvSignalLine.h"
#include "HvSignalVar.h"

class Heavy_grillosychicharrasosc : public HeavyContext {

 public:
  Heavy_grillosychicharrasosc(double sampleRate, int poolKb=10, int inQueueKb=2, int outQueueKb=0);
  ~Heavy_grillosychicharrasosc();

  const char *getName() override { return "grillosychicharrasosc"; }
  int getNumInputChannels() override { return 0; }
  int getNumOutputChannels() override { return 2; }

  int process(float **inputBuffers, float **outputBuffer, int n) override;
  int processInline(float *inputBuffers, float *outputBuffer, int n) override;
  int processInlineInterleaved(float *inputBuffers, float *outputBuffer, int n) override;

  int getParameterInfo(int index, HvParameterInfo *info) override;
  struct Parameter {
    struct In {
      enum ParameterIn : hv_uint32_t {
        BUTTON = 0xE062E1CE, // button
        CTRL = 0x44BF7D9D, // ctrl
      };
    };
  };

 private:
  HvTable *getTableForHash(hv_uint32_t tableHash) override;
  void scheduleMessageForReceiver(hv_uint32_t receiverHash, HvMessage *m) override;

  // static sendMessage functions
  static void cSwitchcase_XaAJ8UTk_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_1W2kzZDN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9NPre30g_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_JxpeBAhW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_hHOcDT6N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_qwyg9nS7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_J86RDoeZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_0chsQotA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_wwpau6Bz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4GfUaJEx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_PCWvP2ew_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_fu2iHazL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_chSr6BTw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_DEbKXhmf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cIf_wDzm9Od4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_yZIDBixz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_RnWRQ7uM_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_kjS7y0lU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_Z13KHwoN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_PQynaYg8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_8jWCv1Te_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_74L3m7JP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_8pUNNwjt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_TY9ShC1k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_mT7tJEeZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_x1YSGd3n_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_qbhidx3Y_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_OdqaGZHM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_GjqtwKXI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_wJLycNEH_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_d1qIvJ9m_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_mTTt9Xpj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_jhGuDpka_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_iWy80D1N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Y0F9OsCr_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Eh3XFCdg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MsvdTvhd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_fJaenERv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_lPFfKlsd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_okCuyCA4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_KDtlwU9z_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_QkKKX34a_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_2xYDiArF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_tfdIqxwo_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_ezc7jNlR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_LIs4t4ql_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_3XqijbAZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_fhcbwBIH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_aRUwFzss_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_2kRImG4s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_wukYta38_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_XaasXUl7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_kCnTwIWU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_HAu0xLeD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_cEctcs0I_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_MqSSAZKJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_sHbRClgO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ppKn1uB5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4nZVBZDB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BJF2iMRx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_j6WS6mwl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wk4zJM4n_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Cf76BNze_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BtOC5oZ5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_u1bVMgSR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_7NgviVao_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_B2ICtnpj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_4xvSJVyD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ftL6G1oD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_yk9WL0S7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Bv2BIy3P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_x0ekL7zB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_go5bROKj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ORl2y4O3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_zrSQxEbP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_juqvs7oe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_gAi9RXvJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_fRlEG5nz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_JatIPlmQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_TukbXVrH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Im1U2iCh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_XMDq4Qhf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_GqwZmAEV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ypxe8d9r_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_doMIjQZH_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_ZWSl4c93_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_C9Fgh7KK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_RVxOnytA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_ypVywBA4_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_l0iiwUI8_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_PNE1PeMI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_inGNZZDB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_9p2rJHnY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_uUkCg0CV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_VvbZc6SQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FPU7qt6N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_2E35JuJ5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_J0MX6nAF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_EnPrH3jg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SfiLSpvz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Vrj34Bmg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Xurk6bPx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SADcAMtg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_bBEDVOpH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FsQGagIt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_J0LMh6gp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_T8tBRUJQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_k6NTsseB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Oay94lWZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9PR2FXG3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mPM9cudi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Q6gWCAb0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_wnm7ytfw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_gCGetLzf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_EktPA8vd_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_mg7Zr8Lf_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_AoXcSucd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_FUQZdAwR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_OsCns2zW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_eUHSYi7u_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_mQggwLBn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ui5axBIK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_4hpeQ34q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YyyRCI0N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_aCS6INYl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_xuCKSlEB_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_XQirk9LM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_lbjSMCed_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_1tAhchPZ_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_1PovdWxB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_ssCLQNHa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_bioSjHl5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_g2K61cxW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_LH6N6P3l_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_rZLNz6hG_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_PbDU57wZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_8actfqwO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_O2R8rIqR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_GdI2hEJP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_sG9BFD3G_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9L6Vgr4C_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_mfnpm9x0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ekhY3QLw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_RPLQtzcu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_BlSB0VbZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_88SFvLwU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_DcWxyFuh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_6Kv6sTf5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vCjPmpjt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QsgV9zYT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_00iCDUR9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_b4v9PwkY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_18dlB2Rm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_uMfAEj0o_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_oUUIrPzY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_e6m6TZ48_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Pfsh1sQl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dpTjFXWU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_gbAgks55_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_PgdOcIlL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_co50ZB8o_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_8YLNNa8W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_xN08s2Gm_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Vjaq7jXj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_hjWBG6R6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_zvIsfgwH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_vPVY80JQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_FMBhAivJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_RuQ4S2vT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_I0yuZqOI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_CumYpKff_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_JtcMRlq1_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_l0l5pXI9_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_exF5YyjU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_7enFm80h_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_cYBzWNM7_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_w2hc3irA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_vK2MN3aJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_lKMHde7c_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_nsMTWnpM_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_N7FfgkdV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_FjfgzF9p_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_F1h325lB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_zLol8OfS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_DbO3QLUW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zj6QvmdZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_fLZSzvVH_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_zJAiWiVJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_8cGXFtIB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_VYRlg0ev_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_1BESHbOZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_Xwwsrbpg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_lmTd1PZ5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YurT3zAA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Qb924igc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_GzxoCS6E_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_raocFvnH_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_exjPWCRW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_Ar4vYV7V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_DCttPl7q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_X67VeFI3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_PPiMezQU_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_YZS2UE8n_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_LABZKoXR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_PN2w6QLZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_uMnq1i60_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_M1yeaAnC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_80CI1zFl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_xg8zyMrs_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_NsgFfIkS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_rUdemX9s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_RyHq4Tde_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_FmHIUoPt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_oCksKOVV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_ABMk6KNc_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_CTcLER8b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_11hdN5UF_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cBinop_hRcY31HM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cUnop_xBmJ7lSC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cRandom_JMgv08m3_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_JSCNGRxu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_OgiuVFXd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_IV1OzJr2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_SNrOOz03_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_FYmDNgRU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7xLhRdfi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_GLgFFxWj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_L5bA9zUA_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_woiTrk6W_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_rxo7qI6k_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ryGAukQO_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_dgXZzTVz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_8TEqWAid_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_JjBolIbR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_QApmPfby_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_Zsi6BWVX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_9kpnqw3Z_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_gyIpQVor_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cSlice_awh2ib9f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_NEXXL2QM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_xpf6GBEd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_EbuEpSgM_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_yZ8UaUzD_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cCast_KrOu05RS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_1F8Sb4gT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_uHqE8HuL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_GIRUblSa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_UZQeejUQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSlice_N3doIsrB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FljePwOe_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Nj71YuHQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_JvB4Yd25_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SMoDiCnz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_QjtkWKXU_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_0FD29E0d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_KtfALpeR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1xNd4vjN_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YFcUktke_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_t5O2YxJ2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_FNADSqay_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Xt0Esorv_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_R78BbqmP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Sgn2gLDX_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_gVxj59TK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_KK2fUkiK_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_vF5Ex0WW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_M62PhVRg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_NbeixWiF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_pDPhNcvh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_piph5Q6N_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_PdjB9Jwy_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_annvTzMo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_zkZbSnoa_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Edng5CKd_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_89PowJvb_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Njpao7ll_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_BLhuxW5Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_LZSxNqmR_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Vm875hrC_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_t6BwMB2Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_EellGHUk_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_vQgMzr5A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_W9FAWGf5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_dcrTIOf2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_D41OjgcZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_7TjdZHWj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_mPTyI8bE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_wZ8kzHBT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_LwIxFdvT_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_zmQoK1OM_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_DCOySfGo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_8LSMd5L5_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5SwHlRzp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_Pvcwolld_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_TmNyvxKQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2EEU4O5P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_p127OyeQ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_9csvGmBn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_5x30xgW6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_jZ0oU64w_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_SVPnbg7P_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_u8EyFy58_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_z3JWA8vp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_s5Xl48Tw_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_mCydZE6d_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_8fGOa8dJ_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_OyHKIz4x_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_N3XMIN6h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_enOv5Itt_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_03KLaLAK_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_k2UAidvz_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_CNw7orMV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_8mIlcwpl_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_EQGQctFb_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_QkcFAt5v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_d3ZuxwMD_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_ckFcVNSh_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_xccGKJY2_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_hblxrXtV_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_NqbgnOVI_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_Uylwl7eS_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_D94ut090_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_9Xw96O2f_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_ANOuc6mg_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_N6QSYD1s_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_b8zFdTFv_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_B0ACDsqo_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_mLWgIQu0_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_gcFDepbn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_irrNU027_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_AOvZZNkF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_dldsdwqn_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_thenDPbx_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_us8LVpBF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_aT5xmtxy_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_yQjWCTNJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_UnsI3B7K_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_8m4u3acF_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSystem_RETd5ExZ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cVar_vh66bxML_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_5tZexWOE_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_Rb7Om7L2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_vq2xer2Q_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_PLphhueJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cSwitchcase_k8S5gcQg_onMessage(HeavyContextInterface *, void *, int letIn, const HvMessage *const, void *);
  static void cDelay_dYC2hQlY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_hC6YH8Yp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cCast_5TTwnq9h_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_jegGRbOJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_1UvyqNeu_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_JarzlpuP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_O6WQwC5n_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_G3DWhTEH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_M1oD9q2A_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_M1j0EzAH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_2qsEEP08_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_ekNBrCgL_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_3lWl0kIJ_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_YoBxHtnj_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_oG4PUueB_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cBinop_LQDTgiyi_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_QCd8cBvY_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_Lyuz0fVH_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_NQhlKg8V_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_kYsKfOV2_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_w4t9qp8v_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_w9wIiiZ6_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_igD5514b_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cMsg_HpHjZaHp_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_QOe7WQiP_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Jt0dmOKW_sendMessage(HeavyContextInterface *, int, const HvMessage *);
  static void cReceive_Oqu0KUFg_sendMessage(HeavyContextInterface *, int, const HvMessage *);

  // objects
  SignalPhasor sPhasor_LxiTXIU7;
  SignalBiquad_k sBiquad_k_kIL0xY3G;
  SignalPhasor sPhasor_f0uDpVMO;
  SignalPhasor sPhasor_xEJfWmd4;
  SignalPhasor sPhasor_k3VLT3AV;
  SignalLine sLine_Oh08yDd7;
  ControlDelay cDelay_1W2kzZDN;
  ControlVar cVar_qwyg9nS7;
  ControlBinop cBinop_0chsQotA;
  ControlBinop cBinop_wwpau6Bz;
  ControlBinop cBinop_4GfUaJEx;
  ControlVar cVar_PCWvP2ew;
  ControlVar cVar_fu2iHazL;
  ControlIf cIf_wDzm9Od4;
  ControlBinop cBinop_yZIDBixz;
  ControlBinop cBinop_kjS7y0lU;
  ControlRandom cRandom_PQynaYg8;
  ControlSlice cSlice_8jWCv1Te;
  SignalVari sVari_pK2hcXbz;
  ControlVar cVar_TY9ShC1k;
  ControlVar cVar_mT7tJEeZ;
  ControlVar cVar_x1YSGd3n;
  ControlVar cVar_qbhidx3Y;
  ControlDelay cDelay_d1qIvJ9m;
  ControlVar cVar_Y0F9OsCr;
  ControlBinop cBinop_MsvdTvhd;
  ControlBinop cBinop_fJaenERv;
  ControlBinop cBinop_lPFfKlsd;
  ControlVar cVar_okCuyCA4;
  ControlSlice cSlice_ezc7jNlR;
  ControlSlice cSlice_LIs4t4ql;
  ControlVar cVar_3XqijbAZ;
  ControlVar cVar_fhcbwBIH;
  ControlVar cVar_wukYta38;
  ControlVar cVar_XaasXUl7;
  ControlVar cVar_kCnTwIWU;
  ControlSlice cSlice_HAu0xLeD;
  ControlSlice cSlice_cEctcs0I;
  ControlBinop cBinop_MqSSAZKJ;
  ControlBinop cBinop_sHbRClgO;
  ControlBinop cBinop_ppKn1uB5;
  ControlBinop cBinop_4nZVBZDB;
  ControlBinop cBinop_BJF2iMRx;
  ControlBinop cBinop_Cf76BNze;
  ControlBinop cBinop_BtOC5oZ5;
  ControlBinop cBinop_u1bVMgSR;
  ControlBinop cBinop_7NgviVao;
  ControlBinop cBinop_go5bROKj;
  ControlBinop cBinop_juqvs7oe;
  ControlBinop cBinop_TukbXVrH;
  ControlBinop cBinop_ZWSl4c93;
  ControlRandom cRandom_RVxOnytA;
  ControlSlice cSlice_ypVywBA4;
  ControlVar cVar_inGNZZDB;
  ControlVar cVar_9p2rJHnY;
  ControlBinop cBinop_VvbZc6SQ;
  ControlBinop cBinop_FPU7qt6N;
  ControlBinop cBinop_2E35JuJ5;
  ControlBinop cBinop_J0MX6nAF;
  ControlBinop cBinop_EnPrH3jg;
  ControlBinop cBinop_SfiLSpvz;
  ControlBinop cBinop_Vrj34Bmg;
  ControlBinop cBinop_SADcAMtg;
  ControlBinop cBinop_bBEDVOpH;
  ControlBinop cBinop_FsQGagIt;
  ControlBinop cBinop_J0LMh6gp;
  ControlBinop cBinop_T8tBRUJQ;
  ControlBinop cBinop_k6NTsseB;
  ControlBinop cBinop_Oay94lWZ;
  ControlBinop cBinop_9PR2FXG3;
  ControlBinop cBinop_mPM9cudi;
  ControlBinop cBinop_Q6gWCAb0;
  ControlDelay cDelay_mg7Zr8Lf;
  ControlVar cVar_eUHSYi7u;
  ControlBinop cBinop_ui5axBIK;
  ControlBinop cBinop_4hpeQ34q;
  ControlBinop cBinop_YyyRCI0N;
  ControlVar cVar_aCS6INYl;
  ControlSlice cSlice_1PovdWxB;
  ControlSlice cSlice_ssCLQNHa;
  ControlVar cVar_bioSjHl5;
  ControlVar cVar_g2K61cxW;
  ControlVar cVar_PbDU57wZ;
  ControlVar cVar_8actfqwO;
  ControlVar cVar_O2R8rIqR;
  ControlSlice cSlice_GdI2hEJP;
  ControlSlice cSlice_sG9BFD3G;
  ControlBinop cBinop_9L6Vgr4C;
  ControlBinop cBinop_mfnpm9x0;
  ControlBinop cBinop_ekhY3QLw;
  ControlBinop cBinop_RPLQtzcu;
  ControlBinop cBinop_BlSB0VbZ;
  ControlBinop cBinop_6Kv6sTf5;
  ControlBinop cBinop_vCjPmpjt;
  ControlBinop cBinop_QsgV9zYT;
  ControlBinop cBinop_00iCDUR9;
  ControlBinop cBinop_dpTjFXWU;
  ControlBinop cBinop_Vjaq7jXj;
  ControlVar cVar_RuQ4S2vT;
  ControlVar cVar_I0yuZqOI;
  ControlVar cVar_CumYpKff;
  ControlBinop cBinop_cYBzWNM7;
  ControlRandom cRandom_vK2MN3aJ;
  ControlSlice cSlice_lKMHde7c;
  ControlBinop cBinop_N7FfgkdV;
  ControlRandom cRandom_F1h325lB;
  ControlSlice cSlice_zLol8OfS;
  ControlVar cVar_DbO3QLUW;
  ControlBinop cBinop_zj6QvmdZ;
  ControlDelay cDelay_zJAiWiVJ;
  ControlVar cVar_Xwwsrbpg;
  ControlBinop cBinop_YurT3zAA;
  ControlBinop cBinop_Qb924igc;
  ControlBinop cBinop_GzxoCS6E;
  ControlBinop cBinop_exjPWCRW;
  ControlRandom cRandom_DCttPl7q;
  ControlSlice cSlice_X67VeFI3;
  ControlDelay cDelay_YZS2UE8n;
  ControlVar cVar_M1yeaAnC;
  ControlBinop cBinop_xg8zyMrs;
  ControlBinop cBinop_NsgFfIkS;
  ControlBinop cBinop_rUdemX9s;
  ControlBinop cBinop_FmHIUoPt;
  ControlRandom cRandom_ABMk6KNc;
  ControlSlice cSlice_CTcLER8b;
  ControlBinop cBinop_hRcY31HM;
  ControlRandom cRandom_JMgv08m3;
  ControlSlice cSlice_JSCNGRxu;
  ControlDelay cDelay_FYmDNgRU;
  ControlVar cVar_woiTrk6W;
  ControlBinop cBinop_ryGAukQO;
  ControlBinop cBinop_dgXZzTVz;
  ControlBinop cBinop_8TEqWAid;
  ControlVar cVar_JjBolIbR;
  ControlSlice cSlice_awh2ib9f;
  ControlSlice cSlice_NEXXL2QM;
  ControlVar cVar_xpf6GBEd;
  ControlVar cVar_EbuEpSgM;
  ControlVar cVar_1F8Sb4gT;
  ControlVar cVar_uHqE8HuL;
  ControlVar cVar_GIRUblSa;
  ControlSlice cSlice_UZQeejUQ;
  ControlSlice cSlice_N3doIsrB;
  ControlBinop cBinop_FljePwOe;
  ControlBinop cBinop_Nj71YuHQ;
  ControlBinop cBinop_JvB4Yd25;
  ControlBinop cBinop_SMoDiCnz;
  ControlBinop cBinop_QjtkWKXU;
  ControlBinop cBinop_1xNd4vjN;
  ControlBinop cBinop_YFcUktke;
  ControlBinop cBinop_t5O2YxJ2;
  ControlBinop cBinop_FNADSqay;
  ControlBinop cBinop_M62PhVRg;
  ControlBinop cBinop_zkZbSnoa;
  ControlVar cVar_LZSxNqmR;
  ControlBinop cBinop_Vm875hrC;
  ControlVar cVar_t6BwMB2Q;
  ControlVar cVar_EellGHUk;
  ControlDelay cDelay_DCOySfGo;
  ControlVar cVar_TmNyvxKQ;
  ControlBinop cBinop_p127OyeQ;
  ControlBinop cBinop_9csvGmBn;
  ControlBinop cBinop_5x30xgW6;
  ControlVar cVar_jZ0oU64w;
  ControlBinop cBinop_SVPnbg7P;
  ControlDelay cDelay_z3JWA8vp;
  ControlDelay cDelay_OyHKIz4x;
  ControlDelay cDelay_k2UAidvz;
  ControlDelay cDelay_QkcFAt5v;
  ControlDelay cDelay_hblxrXtV;
  ControlDelay cDelay_9Xw96O2f;
  ControlDelay cDelay_B0ACDsqo;
  ControlVar cVar_irrNU027;
  ControlVar cVar_AOvZZNkF;
  ControlVar cVar_dldsdwqn;
  ControlVar cVar_thenDPbx;
  ControlBinop cBinop_us8LVpBF;
  ControlDelay cDelay_yQjWCTNJ;
  ControlVar cVar_vh66bxML;
  ControlBinop cBinop_Rb7Om7L2;
  ControlBinop cBinop_vq2xer2Q;
  ControlBinop cBinop_PLphhueJ;
  ControlDelay cDelay_dYC2hQlY;
  ControlBinop cBinop_jegGRbOJ;
  ControlBinop cBinop_1UvyqNeu;
  ControlBinop cBinop_G3DWhTEH;
  SignalVarf sVarf_wcDzhft9;
  ControlBinop cBinop_ekNBrCgL;
  ControlBinop cBinop_YoBxHtnj;
  ControlBinop cBinop_oG4PUueB;
  ControlBinop cBinop_LQDTgiyi;
  SignalVarf sVarf_vp4LEFaY;
  SignalVarf sVarf_mlDm3D8z;
  SignalVarf sVarf_mbHVKxDb;
};

#endif // _HEAVY_CONTEXT_GRILLOSYCHICHARRASOSC_HPP_
