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

#include "Heavy_patch_init_test.h"
#include "Heavy_patch_init_test.hpp" 
#include "HeavyDaisy_patch_init_test.hpp"                                                                 

#define SAMPLE_RATE 48000.f

using namespace daisy;

json2daisy::DaisyPatch_init hardware;

Heavy_patch_init_test hv(SAMPLE_RATE);

void audiocallback(daisy::AudioHandle::InputBuffer in, daisy::AudioHandle::OutputBuffer out, size_t size);
static void sendHook(HeavyContextInterface *c, const char *receiverName, uint32_t receiverHash, const HvMessage * m);
void CallbackWriteIn(Heavy_patch_init_test& hv);
void LoopWriteIn(Heavy_patch_init_test& hv);
void CallbackWriteOut();
void LoopWriteOut();
void PostProcess();
void Display();

constexpr int DaisyNumOutputParameters = 4;
/** This array holds the output values received from PD hooks. These values are
 *  then written at the appropriate time in the following callback or loop.
 */
float output_data[DaisyNumOutputParameters];

struct DaisyHvParamOut
{
	uint32_t hash;
	uint32_t index;
  void (*hook_write_out)(float);

	void Process(float sig)
	{
		output_data[index] = sig;
    if (hook_write_out)
      (*hook_write_out)(sig);
	}
};


DaisyHvParamOut DaisyOutputParameters[DaisyNumOutputParameters] = {
		{ (uint32_t) HV_PATCH_INIT_TEST_PARAM_OUT_GATEOUT1, 0, nullptr }, // gate_out_1
		{ (uint32_t) HV_PATCH_INIT_TEST_PARAM_OUT_GATEOUT2, 1, nullptr }, // gate_out_2
		{ (uint32_t) HV_PATCH_INIT_TEST_PARAM_OUT_CVOUT1, 2, nullptr }, // cvout1
		{ (uint32_t) HV_PATCH_INIT_TEST_PARAM_OUT_CVOUT2, 3, nullptr }, // cvout2
};

int main(void)
{
  hardware.Init(true);
  hardware.StartAudio(audiocallback);

  hv.setSendHook(sendHook);

  for(;;)
  {
    hardware.LoopProcess();
    Display();
    LoopWriteOut();
  }
}

/** The audio processing function. At the standard 48KHz sample rate and a block
 *  size of 48, this will fire every millisecond.
 */
void audiocallback(daisy::AudioHandle::InputBuffer in, daisy::AudioHandle::OutputBuffer out, size_t size)
{
  hardware.ProcessAllControls();
  CallbackWriteIn(hv);
  hv.process((float**)in, (float**)out, size);
  CallbackWriteOut();
  hardware.PostProcess();
}

/** Receives messages from PD and writes them to the appropriate 
 *  index in the `output_data` array, to be written later.
 */
static void sendHook(HeavyContextInterface *c, const char *receiverName, uint32_t receiverHash, const HvMessage * m) 
{
  for (int i = 0; i < DaisyNumOutputParameters; i++)
  {
    if (DaisyOutputParameters[i].hash == receiverHash)
    {
      DaisyOutputParameters[i].Process(msg_getFloat(m, 0));
    }
  }
}

/** Sends signals from the Daisy hardware to the PD patch via the receive objects during the main loop
 * 
 */
void LoopWriteIn(Heavy_patch_init_test& hv)
{
}

/** Sends signals from the Daisy hardware to the PD patch via the receive objects during the audio callback
 * 
 */
void CallbackWriteIn(Heavy_patch_init_test& hv)
{
  hv.sendFloatToReceiver((uint32_t) HV_PATCH_INIT_TEST_PARAM_IN_CTRL1, (hardware.som.GetAdcValue((int)daisy::patch_sm::CV_1))); 
  hv.sendFloatToReceiver((uint32_t) HV_PATCH_INIT_TEST_PARAM_IN_CTRL2, (hardware.som.GetAdcValue((int)daisy::patch_sm::CV_2))); 
  hv.sendFloatToReceiver((uint32_t) HV_PATCH_INIT_TEST_PARAM_IN_CTRL3, (hardware.som.GetAdcValue((int)daisy::patch_sm::CV_3))); 
  hv.sendFloatToReceiver((uint32_t) HV_PATCH_INIT_TEST_PARAM_IN_CTRL4, (hardware.som.GetAdcValue((int)daisy::patch_sm::CV_4))); 
  hv.sendFloatToReceiver((uint32_t) HV_PATCH_INIT_TEST_PARAM_IN_GATE1, (hardware.som.gate_in_1.State()?1.f:0.f)); 
 
  if ((hardware.som.gate_in_1.Trig()?1.f:0.f))
    hv.sendBangToReceiver((uint32_t) HV_PATCH_INIT_TEST_PARAM_IN_GATE1_TRIG); 
  hv.sendFloatToReceiver((uint32_t) HV_PATCH_INIT_TEST_PARAM_IN_GATE2, (hardware.som.gate_in_2.State()?1.f:0.f)); 
  hv.sendFloatToReceiver((uint32_t) HV_PATCH_INIT_TEST_PARAM_IN_CV_5, (hardware.som.GetAdcValue((int)daisy::patch_sm::CV_5))); 
}

/** Writes the values sent to PD's receive objects to the Daisy hardware during the main loop
 * 
 */
void LoopWriteOut() {
}

/** Writes the values sent to PD's receive objects to the Daisy hardware during the audio callback
 * 
 */
void CallbackWriteOut() {
  dsy_gpio_write(&hardware.som.gate_out_1, output_data[0]);
  dsy_gpio_write(&hardware.som.gate_out_2, output_data[1]);
  hardware.som.WriteCvOut(daisy::patch_sm::CV_OUT_1, output_data[2] * 5.f);
  hardware.som.WriteCvOut(daisy::patch_sm::CV_OUT_2, output_data[3] * 5.f);
}

/** Handles the display code if the hardware defines a display
 * 
 */
void Display() {
  
}