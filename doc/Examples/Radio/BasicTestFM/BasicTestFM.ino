#include "si5351.h"
#include "Wire.h"

Si5351 si5351;

void setup()
{
  // Start serial and initialize the Si5351
  Serial.begin(57600);
  si5351.init(SI5351_CRYSTAL_LOAD_8PF, 0, 0);

  // We will output 14.1 MHz on CLK0 and CLK1.
  // A PLLA frequency of 705 MHz was chosen to give an even
  // divisor by 14.1 MHz.
  unsigned long long freq = 985000000ULL;
                           //985000000ULL;
                           //98500000
  unsigned long long pll_freq = 985000000ULL;

  // Set CLK0 and CLK1 to output 14.1 MHz with a fixed PLL frequency
  si5351.set_freq_manual(freq, pll_freq, SI5351_CLK0);

  // Now we can set CLK1 to have a 90 deg phase shift by entering
  // 50 in the CLK1 phase register, since the ratio of the PLL to
  // the clock frequency is 50.
  si5351.set_phase(SI5351_CLK0, 0);

  // We need to reset the PLL before they will be in phase alignment
  si5351.pll_reset(SI5351_PLLA);

  // Query a status update and wait a bit to let the Si5351 populate the
  // status flags correctly.
  si5351.update_status();
  delay(500);
}

void loop()
{
 
}
