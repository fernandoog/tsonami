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

#include "Heavy_field_test.h"
#include "Heavy_field_test.hpp" 
#include "HeavyDaisy_field_test.hpp"                                                                 

#define SAMPLE_RATE 48000.f

using namespace daisy;

json2daisy::DaisyField hardware;

Heavy_field_test hv(SAMPLE_RATE);

void audiocallback(daisy::AudioHandle::InputBuffer in, daisy::AudioHandle::OutputBuffer out, size_t size);
static void sendHook(HeavyContextInterface *c, const char *receiverName, uint32_t receiverHash, const HvMessage * m);
void CallbackWriteIn(Heavy_field_test& hv);
void LoopWriteIn(Heavy_field_test& hv);
void CallbackWriteOut();
void LoopWriteOut();
void PostProcess();
void Display();

constexpr int DaisyNumOutputParameters = 25;
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

void gateout_hook(float sig) {
  dsy_gpio_write(&hardware.gateout, sig);
};

DaisyHvParamOut DaisyOutputParameters[DaisyNumOutputParameters] = {
    { (uint32_t) HV_FIELD_TEST_PARAM_OUT_GATEOUT, 0, &gateout_hook }, // gateout
		{ (uint32_t) HV_FIELD_TEST_PARAM_OUT_LED_KEY_A1, 1, nullptr }, // led_key_a1
		{ (uint32_t) HV_FIELD_TEST_PARAM_OUT_LED_KEY_A2, 2, nullptr }, // led_key_a2
		{ (uint32_t) HV_FIELD_TEST_PARAM_OUT_LED_KEY_A3, 3, nullptr }, // led_key_a3
		{ (uint32_t) HV_FIELD_TEST_PARAM_OUT_LED_KEY_A4, 4, nullptr }, // led_key_a4
		{ (uint32_t) HV_FIELD_TEST_PARAM_OUT_LED_KEY_A5, 5, nullptr }, // led_key_a5
		{ (uint32_t) HV_FIELD_TEST_PARAM_OUT_LED_KEY_A6, 6, nullptr }, // led_key_a6
		{ (uint32_t) HV_FIELD_TEST_PARAM_OUT_LED_KEY_A7, 7, nullptr }, // led_key_a7
		{ (uint32_t) HV_FIELD_TEST_PARAM_OUT_LED_KEY_A8, 8, nullptr }, // led_key_a8
		{ (uint32_t) HV_FIELD_TEST_PARAM_OUT_LED_KEY_B1, 9, nullptr }, // led_key_b1
		{ (uint32_t) HV_FIELD_TEST_PARAM_OUT_LED_KEY_B2, 10, nullptr }, // led_key_b2
		{ (uint32_t) HV_FIELD_TEST_PARAM_OUT_LED_KEY_B3, 11, nullptr }, // led_key_b3
		{ (uint32_t) HV_FIELD_TEST_PARAM_OUT_LED_KEY_B4, 12, nullptr }, // led_key_b4
		{ (uint32_t) HV_FIELD_TEST_PARAM_OUT_LED_KEY_B5, 13, nullptr }, // led_key_b5
		{ (uint32_t) HV_FIELD_TEST_PARAM_OUT_LED_KEY_B6, 14, nullptr }, // led_key_b6
		{ (uint32_t) HV_FIELD_TEST_PARAM_OUT_LED_KEY_B7, 15, nullptr }, // led_key_b7
		{ (uint32_t) HV_FIELD_TEST_PARAM_OUT_LED_KEY_B8, 16, nullptr }, // led_key_b8
		{ (uint32_t) HV_FIELD_TEST_PARAM_OUT_LED_KNOB_1, 17, nullptr }, // led_knob_1
		{ (uint32_t) HV_FIELD_TEST_PARAM_OUT_LED_KNOB_2, 18, nullptr }, // led_knob_2
		{ (uint32_t) HV_FIELD_TEST_PARAM_OUT_LED_KNOB_3, 19, nullptr }, // led_knob_3
		{ (uint32_t) HV_FIELD_TEST_PARAM_OUT_LED_KNOB_4, 20, nullptr }, // led_knob_4
		{ (uint32_t) HV_FIELD_TEST_PARAM_OUT_LED_KNOB_5, 21, nullptr }, // led_knob_5
		{ (uint32_t) HV_FIELD_TEST_PARAM_OUT_LED_KNOB_6, 22, nullptr }, // led_knob_6
		{ (uint32_t) HV_FIELD_TEST_PARAM_OUT_LED_KNOB_7, 23, nullptr }, // led_knob_7
		{ (uint32_t) HV_FIELD_TEST_PARAM_OUT_LED_KNOB_8, 24, nullptr }, // led_knob_8
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
void LoopWriteIn(Heavy_field_test& hv)
{
}

/** Sends signals from the Daisy hardware to the PD patch via the receive objects during the audio callback
 * 
 */
void CallbackWriteIn(Heavy_field_test& hv)
{
 
  if ((json2daisy::pad_shift_debounced[14] == 0xFE))
    hv.sendBangToReceiver((uint32_t) HV_FIELD_TEST_PARAM_IN_PADA2); 
  hv.sendFloatToReceiver((uint32_t) HV_FIELD_TEST_PARAM_IN_PADA2_PRESS, (json2daisy::pad_shift_debounced[14] != 0xFF)); 
  hv.sendFloatToReceiver((uint32_t) HV_FIELD_TEST_PARAM_IN_PADA3_PRESS, (json2daisy::pad_shift_debounced[13] != 0xFF)); 
  hv.sendFloatToReceiver((uint32_t) HV_FIELD_TEST_PARAM_IN_PADA4_PRESS, (json2daisy::pad_shift_debounced[12] != 0xFF)); 
  hv.sendFloatToReceiver((uint32_t) HV_FIELD_TEST_PARAM_IN_PADA5_PRESS, (json2daisy::pad_shift_debounced[11] != 0xFF)); 
  hv.sendFloatToReceiver((uint32_t) HV_FIELD_TEST_PARAM_IN_PADA6_PRESS, (json2daisy::pad_shift_debounced[10] != 0xFF)); 
  hv.sendFloatToReceiver((uint32_t) HV_FIELD_TEST_PARAM_IN_PADA7_PRESS, (json2daisy::pad_shift_debounced[9] != 0xFF)); 
  hv.sendFloatToReceiver((uint32_t) HV_FIELD_TEST_PARAM_IN_PADA8_PRESS, (json2daisy::pad_shift_debounced[8] != 0xFF)); 
  hv.sendFloatToReceiver((uint32_t) HV_FIELD_TEST_PARAM_IN_PADB1_PRESS, (json2daisy::pad_shift_debounced[7] != 0xFF)); 
  hv.sendFloatToReceiver((uint32_t) HV_FIELD_TEST_PARAM_IN_PADB2_PRESS, (json2daisy::pad_shift_debounced[6] != 0xFF)); 
  hv.sendFloatToReceiver((uint32_t) HV_FIELD_TEST_PARAM_IN_PADB3_PRESS, (json2daisy::pad_shift_debounced[5] != 0xFF)); 
  hv.sendFloatToReceiver((uint32_t) HV_FIELD_TEST_PARAM_IN_PADB4_PRESS, (json2daisy::pad_shift_debounced[4] != 0xFF)); 
  hv.sendFloatToReceiver((uint32_t) HV_FIELD_TEST_PARAM_IN_PADB5_PRESS, (json2daisy::pad_shift_debounced[3] != 0xFF)); 
  hv.sendFloatToReceiver((uint32_t) HV_FIELD_TEST_PARAM_IN_PADB6_PRESS, (json2daisy::pad_shift_debounced[2] != 0xFF)); 
  hv.sendFloatToReceiver((uint32_t) HV_FIELD_TEST_PARAM_IN_PADB7_PRESS, (json2daisy::pad_shift_debounced[1] != 0xFF)); 
  hv.sendFloatToReceiver((uint32_t) HV_FIELD_TEST_PARAM_IN_PADB8_PRESS, (json2daisy::pad_shift_debounced[0] != 0xFF)); 
  hv.sendFloatToReceiver((uint32_t) HV_FIELD_TEST_PARAM_IN_GATEIN, (hardware.gatein.State()?1.f:0.f)); 
  hv.sendFloatToReceiver((uint32_t) HV_FIELD_TEST_PARAM_IN_KNOB1, (hardware.knob1.Value())); 
  hv.sendFloatToReceiver((uint32_t) HV_FIELD_TEST_PARAM_IN_KNOB2, (hardware.knob2.Value())); 
  hv.sendFloatToReceiver((uint32_t) HV_FIELD_TEST_PARAM_IN_KNOB3, (hardware.knob3.Value())); 
  hv.sendFloatToReceiver((uint32_t) HV_FIELD_TEST_PARAM_IN_KNOB4, (hardware.knob4.Value())); 
  hv.sendFloatToReceiver((uint32_t) HV_FIELD_TEST_PARAM_IN_KNOB5, (hardware.knob5.Value())); 
  hv.sendFloatToReceiver((uint32_t) HV_FIELD_TEST_PARAM_IN_KNOB6, (hardware.knob6.Value())); 
  hv.sendFloatToReceiver((uint32_t) HV_FIELD_TEST_PARAM_IN_KNOB7, (hardware.knob7.Value())); 
  hv.sendFloatToReceiver((uint32_t) HV_FIELD_TEST_PARAM_IN_KNOB8, (hardware.knob8.Value())); 
 
  if ((hardware.sw1.RisingEdge()?1.f:0.f))
    hv.sendBangToReceiver((uint32_t) HV_FIELD_TEST_PARAM_IN_SW1); 
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
  hardware.led_driver.SetLed(0, output_data[1]);
  hardware.led_driver.SetLed(1, output_data[2]);
  hardware.led_driver.SetLed(2, output_data[3]);
  hardware.led_driver.SetLed(3, output_data[4]);
  hardware.led_driver.SetLed(4, output_data[5]);
  hardware.led_driver.SetLed(5, output_data[6]);
  hardware.led_driver.SetLed(6, output_data[7]);
  hardware.led_driver.SetLed(7, output_data[8]);
  hardware.led_driver.SetLed(15, output_data[9]);
  hardware.led_driver.SetLed(14, output_data[10]);
  hardware.led_driver.SetLed(13, output_data[11]);
  hardware.led_driver.SetLed(12, output_data[12]);
  hardware.led_driver.SetLed(11, output_data[13]);
  hardware.led_driver.SetLed(10, output_data[14]);
  hardware.led_driver.SetLed(9, output_data[15]);
  hardware.led_driver.SetLed(8, output_data[16]);
  hardware.led_driver.SetLed(16, output_data[17]);
  hardware.led_driver.SetLed(17, output_data[18]);
  hardware.led_driver.SetLed(18, output_data[19]);
  hardware.led_driver.SetLed(19, output_data[20]);
  hardware.led_driver.SetLed(20, output_data[21]);
  hardware.led_driver.SetLed(21, output_data[22]);
  hardware.led_driver.SetLed(22, output_data[23]);
  hardware.led_driver.SetLed(23, output_data[24]);
}

/** Handles the display code if the hardware defines a display
 * 
 */
void Display() {
  
}