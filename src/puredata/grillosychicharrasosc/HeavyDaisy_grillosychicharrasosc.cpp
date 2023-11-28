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

#include "Heavy_grillosychicharrasosc.h"
#include "Heavy_grillosychicharrasosc.hpp" 
#include "HeavyDaisy_grillosychicharrasosc.hpp"                                                                 

#define SAMPLE_RATE 48000.f

using namespace daisy;

json2daisy::DaisyPod hardware;

Heavy_grillosychicharrasosc hv(SAMPLE_RATE);

void audiocallback(daisy::AudioHandle::InputBuffer in, daisy::AudioHandle::OutputBuffer out, size_t size);
static void sendHook(HeavyContextInterface *c, const char *receiverName, uint32_t receiverHash, const HvMessage * m);
void CallbackWriteIn(Heavy_grillosychicharrasosc& hv);
void LoopWriteIn(Heavy_grillosychicharrasosc& hv);
void CallbackWriteOut();
void LoopWriteOut();
void PostProcess();
void Display();


int main(void)
{
  hardware.Init(true);
  hardware.StartAudio(audiocallback);

  hv.setSendHook(sendHook);

  for(;;)
  {
    hardware.LoopProcess();
    Display();
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
  hardware.PostProcess();
}

/** Receives messages from PD and writes them to the appropriate 
 *  index in the `output_data` array, to be written later.
 */
static void sendHook(HeavyContextInterface *c, const char *receiverName, uint32_t receiverHash, const HvMessage * m) 
{
}

/** Sends signals from the Daisy hardware to the PD patch via the receive objects during the main loop
 * 
 */
void LoopWriteIn(Heavy_grillosychicharrasosc& hv)
{
}

/** Sends signals from the Daisy hardware to the PD patch via the receive objects during the audio callback
 * 
 */
void CallbackWriteIn(Heavy_grillosychicharrasosc& hv)
{
 
  if ((hardware.sw1.RisingEdge()?1.f:0.f))
    hv.sendBangToReceiver((uint32_t) HV_GRILLOSYCHICHARRASOSC_PARAM_IN_BUTTON1); 
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
}

/** Handles the display code if the hardware defines a display
 * 
 */
void Display() {
  
}