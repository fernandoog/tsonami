/*******************************************************************************************************************
Copyright (c) 2023 Cycling '74

The code that Max generates automatically and that end users are capable of
exporting and using, and any associated documentation files (the “Software”)
is a work of authorship for which Cycling '74 is the author and owner for
copyright purposes.

This Software is dual-licensed either under the terms of the Cycling '74
License for Max-Generated Code for Export, or alternatively under the terms
of the General Public License (GPL) Version 3. You may use the Software
according to either of these licenses as it is most appropriate for your
project on a case-by-case basis (proprietary or not).

A) Cycling '74 License for Max-Generated Code for Export

A license is hereby granted, free of charge, to any person obtaining a copy
of the Software (“Licensee”) to use, copy, modify, merge, publish, and
distribute copies of the Software, and to permit persons to whom the Software
is furnished to do so, subject to the following conditions:

The Software is licensed to Licensee for all uses that do not include the sale,
sublicensing, or commercial distribution of software that incorporates this
source code. This means that the Licensee is free to use this software for
educational, research, and prototyping purposes, to create musical or other
creative works with software that incorporates this source code, or any other
use that does not constitute selling software that makes use of this source
code. Commercial distribution also includes the packaging of free software with
other paid software, hardware, or software-provided commercial services.

For entities with UNDER $200k in annual revenue or funding, a license is hereby
granted, free of charge, for the sale, sublicensing, or commercial distribution
of software that incorporates this source code, for as long as the entity's
annual revenue remains below $200k annual revenue or funding.

For entities with OVER $200k in annual revenue or funding interested in the
sale, sublicensing, or commercial distribution of software that incorporates
this source code, please send inquiries to licensing@cycling74.com.

The above copyright notice and this license shall be included in all copies or
substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Please see
https://support.cycling74.com/hc/en-us/articles/10730637742483-RNBO-Export-Licensing-FAQ
for additional information

B) General Public License Version 3 (GPLv3)
Details of the GPLv3 license can be found at: https://www.gnu.org/licenses/gpl-3.0.html
*******************************************************************************************************************/

#include "RNBO_Common.h"
#include "RNBO_AudioSignal.h"

namespace RNBO {


#define floor(x) ((long)(x))

#if defined(__GNUC__) || defined(__clang__)
    #define RNBO_RESTRICT __restrict__
#elif defined(_MSC_VER)
    #define RNBO_RESTRICT __restrict
#endif

#define FIXEDSIZEARRAYINIT(...) { }

class rnbomatic : public PatcherInterfaceImpl {
public:

rnbomatic()
{
}

~rnbomatic()
{
}

rnbomatic* getTopLevelPatcher() {
    return this;
}

void cancelClockEvents()
{
    getEngine()->flushClockEvents(this, -1987572531, false);
    getEngine()->flushClockEvents(this, -871642103, false);
    getEngine()->flushClockEvents(this, 1935387534, false);
    getEngine()->flushClockEvents(this, 1777613927, false);
}

template <typename T> void listquicksort(T& arr, T& sortindices, Int l, Int h, bool ascending) {
    if (l < h) {
        Int p = (Int)(this->listpartition(arr, sortindices, l, h, ascending));
        this->listquicksort(arr, sortindices, l, p - 1, ascending);
        this->listquicksort(arr, sortindices, p + 1, h, ascending);
    }
}

template <typename T> Int listpartition(T& arr, T& sortindices, Int l, Int h, bool ascending) {
    number x = arr[(Index)h];
    Int i = (Int)(l - 1);

    for (Int j = (Int)(l); j <= h - 1; j++) {
        bool asc = (bool)((bool)(ascending) && arr[(Index)j] <= x);
        bool desc = (bool)((bool)(!(bool)(ascending)) && arr[(Index)j] >= x);

        if ((bool)(asc) || (bool)(desc)) {
            i++;
            this->listswapelements(arr, i, j);
            this->listswapelements(sortindices, i, j);
        }
    }

    i++;
    this->listswapelements(arr, i, h);
    this->listswapelements(sortindices, i, h);
    return i;
}

template <typename T> void listswapelements(T& arr, Int a, Int b) {
    auto tmp = arr[(Index)a];
    arr[(Index)a] = arr[(Index)b];
    arr[(Index)b] = tmp;
}

Index voice() {
    return this->_voiceIndex;
}

number random(number low, number high) {
    number range = high - low;
    return rand01() * range + low;
}

number mstosamps(MillisecondTime ms) {
    return ms * this->sr * 0.001;
}

inline number safediv(number num, number denom) {
    return (denom == 0.0 ? 0.0 : num / denom);
}

number safepow(number base, number exponent) {
    return fixnan(rnbo_pow(base, exponent));
}

number scale(
    number x,
    number lowin,
    number hiin,
    number lowout,
    number highout,
    number pow
) {
    auto inscale = this->safediv(1., hiin - lowin);
    number outdiff = highout - lowout;
    number value = (x - lowin) * inscale;

    if (pow != 1) {
        if (value > 0)
            value = this->safepow(value, pow);
        else
            value = -this->safepow(-value, pow);
    }

    value = value * outdiff + lowout;
    return value;
}

number samplerate() {
    return this->sr;
}

number maximum(number x, number y) {
    return (x < y ? y : x);
}

MillisecondTime currenttime() {
    return this->_currentTime;
}

number tempo() {
    return this->getTopLevelPatcher()->globaltransport_getTempo(this->currenttime());
}

number mstobeats(number ms) {
    return ms * this->tempo() * 0.008 / (number)480;
}

MillisecondTime sampstoms(number samps) {
    return samps * 1000 / this->sr;
}

Index getNumMidiInputPorts() const {
    return 0;
}

void processMidiEvent(MillisecondTime , int , ConstByteArray , Index ) {}

Index getNumMidiOutputPorts() const {
    return 0;
}

void process(
    const SampleValue * const* inputs,
    Index numInputs,
    SampleValue * const* outputs,
    Index numOutputs,
    Index n
) {
    RNBO_UNUSED(numInputs);
    RNBO_UNUSED(inputs);
    this->vs = n;
    this->updateTime(this->getEngine()->getCurrentTime());
    SampleValue * out1 = (numOutputs >= 1 && outputs[0] ? outputs[0] : this->dummyBuffer);
    SampleValue * out2 = (numOutputs >= 2 && outputs[1] ? outputs[1] : this->dummyBuffer);
    this->noise_tilde_01_perform(this->signals[0], n);

    this->saw_tilde_01_perform(
        this->saw_tilde_01_frequency,
        this->saw_tilde_01_syncPhase,
        this->signals[1],
        this->dummyBuffer,
        n
    );

    this->dspexpr_01_perform(this->signals[0], this->signals[1], this->signals[2], n);
    this->gaintilde_01_perform(this->signals[2], out2, n);
    this->metertilde_01_perform(out2, n);
    this->signalforwarder_01_perform(out2, out1, n);
    this->stackprotect_perform(n);
    this->globaltransport_advance();
    this->audioProcessSampleCount += this->vs;
}

void prepareToProcess(number sampleRate, Index maxBlockSize, bool force) {
    if (this->maxvs < maxBlockSize || !this->didAllocateSignals) {
        Index i;

        for (i = 0; i < 3; i++) {
            this->signals[i] = resizeSignal(this->signals[i], this->maxvs, maxBlockSize);
        }

        this->globaltransport_tempo = resizeSignal(this->globaltransport_tempo, this->maxvs, maxBlockSize);
        this->globaltransport_state = resizeSignal(this->globaltransport_state, this->maxvs, maxBlockSize);
        this->zeroBuffer = resizeSignal(this->zeroBuffer, this->maxvs, maxBlockSize);
        this->dummyBuffer = resizeSignal(this->dummyBuffer, this->maxvs, maxBlockSize);
        this->didAllocateSignals = true;
    }

    const bool sampleRateChanged = sampleRate != this->sr;
    const bool maxvsChanged = maxBlockSize != this->maxvs;
    const bool forceDSPSetup = sampleRateChanged || maxvsChanged || force;

    if (sampleRateChanged || maxvsChanged) {
        this->vs = maxBlockSize;
        this->maxvs = maxBlockSize;
        this->sr = sampleRate;
        this->invsr = 1 / sampleRate;
    }

    this->saw_tilde_01_dspsetup(forceDSPSetup);
    this->gaintilde_01_dspsetup(forceDSPSetup);
    this->metertilde_01_dspsetup(forceDSPSetup);
    this->globaltransport_dspsetup(forceDSPSetup);

    if (sampleRateChanged)
        this->onSampleRateChanged(sampleRate);
}

void setProbingTarget(MessageTag id) {
    switch (id) {
    default:
        {
        this->setProbingIndex(-1);
        break;
        }
    }
}

void setProbingIndex(ProbingIndex ) {}

Index getProbingChannels(MessageTag outletId) const {
    RNBO_UNUSED(outletId);
    return 0;
}

DataRef* getDataRef(DataRefIndex index)  {
    switch (index) {
    default:
        {
        return nullptr;
        }
    }
}

DataRefIndex getNumDataRefs() const {
    return 0;
}

void fillDataRef(DataRefIndex , DataRef& ) {}

void processDataViewUpdate(DataRefIndex , MillisecondTime ) {}

void initialize() {
    this->assign_defaults();
    this->setState();
    this->initializeObjects();
    this->allocateDataRefs();
    this->startup();
}

Index getIsMuted()  {
    return this->isMuted;
}

void setIsMuted(Index v)  {
    this->isMuted = v;
}

Index getPatcherSerial() const {
    return 0;
}

void getState(PatcherStateInterface& ) {}

void setState() {}

void getPreset(PatcherStateInterface& preset) {
    preset["__presetid"] = "rnbo";
}

void setPreset(MillisecondTime , PatcherStateInterface& ) {}

void processTempoEvent(MillisecondTime time, Tempo tempo) {
    this->updateTime(time);

    if (this->globaltransport_setTempo(this->_currentTime, tempo, false))
        {}
}

void processTransportEvent(MillisecondTime time, TransportState state) {
    this->updateTime(time);

    if (this->globaltransport_setState(this->_currentTime, state, false)) {
        this->metro_01_onTransportChanged(state);
        this->metro_02_onTransportChanged(state);
    }
}

void processBeatTimeEvent(MillisecondTime time, BeatTime beattime) {
    this->updateTime(time);

    if (this->globaltransport_setBeatTime(this->_currentTime, beattime, false)) {
        this->metro_01_onBeatTimeChanged(beattime);
        this->metro_02_onBeatTimeChanged(beattime);
    }
}

void onSampleRateChanged(double ) {}

void processTimeSignatureEvent(MillisecondTime time, int numerator, int denominator) {
    this->updateTime(time);

    if (this->globaltransport_setTimeSignature(this->_currentTime, numerator, denominator, false))
        {}
}

void setParameterValue(ParameterIndex , ParameterValue , MillisecondTime ) {}

void processParameterEvent(ParameterIndex index, ParameterValue value, MillisecondTime time) {
    this->setParameterValue(index, value, time);
}

void processNormalizedParameterEvent(ParameterIndex index, ParameterValue value, MillisecondTime time) {
    this->setParameterValueNormalized(index, value, time);
}

ParameterValue getParameterValue(ParameterIndex index)  {
    switch (index) {
    default:
        {
        return 0;
        }
    }
}

ParameterIndex getNumSignalInParameters() const {
    return 0;
}

ParameterIndex getNumSignalOutParameters() const {
    return 0;
}

ParameterIndex getNumParameters() const {
    return 0;
}

ConstCharPointer getParameterName(ParameterIndex index) const {
    switch (index) {
    default:
        {
        return "bogus";
        }
    }
}

ConstCharPointer getParameterId(ParameterIndex index) const {
    switch (index) {
    default:
        {
        return "bogus";
        }
    }
}

void getParameterInfo(ParameterIndex , ParameterInfo * ) const {}

void sendParameter(ParameterIndex index, bool ignoreValue) {
    this->getEngine()->notifyParameterValueChanged(index, (ignoreValue ? 0 : this->getParameterValue(index)), ignoreValue);
}

ParameterValue applyStepsToNormalizedParameterValue(ParameterValue normalizedValue, int steps) const {
    if (steps == 1) {
        if (normalizedValue > 0) {
            normalizedValue = 1.;
        }
    } else {
        ParameterValue oneStep = (number)1. / (steps - 1);
        ParameterValue numberOfSteps = rnbo_fround(normalizedValue / oneStep * 1 / (number)1) * (number)1;
        normalizedValue = numberOfSteps * oneStep;
    }

    return normalizedValue;
}

ParameterValue convertToNormalizedParameterValue(ParameterIndex index, ParameterValue value) const {
    switch (index) {
    default:
        {
        return value;
        }
    }
}

ParameterValue convertFromNormalizedParameterValue(ParameterIndex index, ParameterValue value) const {
    value = (value < 0 ? 0 : (value > 1 ? 1 : value));

    switch (index) {
    default:
        {
        return value;
        }
    }
}

ParameterValue constrainParameterValue(ParameterIndex index, ParameterValue value) const {
    switch (index) {
    default:
        {
        return value;
        }
    }
}

void scheduleParamInit(ParameterIndex index, Index order) {
    this->paramInitIndices->push(index);
    this->paramInitOrder->push(order);
}

void processParamInitEvents() {
    this->listquicksort(
        this->paramInitOrder,
        this->paramInitIndices,
        0,
        (int)(this->paramInitOrder->length - 1),
        true
    );

    for (Index i = 0; i < this->paramInitOrder->length; i++) {
        this->getEngine()->scheduleParameterChange(
            this->paramInitIndices[i],
            this->getParameterValue(this->paramInitIndices[i]),
            0
        );
    }
}

void processClockEvent(MillisecondTime time, ClockId index, bool hasValue, ParameterValue value) {
    RNBO_UNUSED(hasValue);
    this->updateTime(time);

    switch (index) {
    case -1987572531:
        {
        this->metro_01_tick_bang();
        break;
        }
    case -871642103:
        {
        this->loadbang_01_startupbang_bang();
        break;
        }
    case 1935387534:
        {
        this->metro_02_tick_bang();
        break;
        }
    case 1777613927:
        {
        this->metertilde_01_value_set(value);
        break;
        }
    }
}

void processOutletAtCurrentTime(EngineLink* , OutletIndex , ParameterValue ) {}

void processOutletEvent(
    EngineLink* sender,
    OutletIndex index,
    ParameterValue value,
    MillisecondTime time
) {
    this->updateTime(time);
    this->processOutletAtCurrentTime(sender, index, value);
}

void processNumMessage(MessageTag tag, MessageTag objectId, MillisecondTime time, number payload) {
    this->updateTime(time);

    switch (tag) {
    case TAG("valin"):
        {
        if (TAG("gain~_obj-11") == objectId)
            this->gaintilde_01_valin_set(payload);

        if (TAG("number_obj-6") == objectId)
            this->numberobj_01_valin_set(payload);

        if (TAG("toggle_obj-2") == objectId)
            this->toggle_01_valin_set(payload);

        if (TAG("toggle_obj-22") == objectId)
            this->toggle_02_valin_set(payload);

        break;
        }
    case TAG("format"):
        {
        if (TAG("number_obj-6") == objectId)
            this->numberobj_01_format_set(payload);

        break;
        }
    case TAG("listin"):
        {
        if (TAG("message_obj-13") == objectId)
            this->message_01_listin_number_set(payload);

        break;
        }
    }
}

void processListMessage(
    MessageTag tag,
    MessageTag objectId,
    MillisecondTime time,
    const list& payload
) {
    this->updateTime(time);

    switch (tag) {
    case TAG("listin"):
        {
        if (TAG("message_obj-13") == objectId)
            this->message_01_listin_list_set(payload);

        break;
        }
    }
}

void processBangMessage(MessageTag tag, MessageTag objectId, MillisecondTime time) {
    this->updateTime(time);

    switch (tag) {
    case TAG("startupbang"):
        {
        if (TAG("loadbang_obj-15") == objectId)
            this->loadbang_01_startupbang_bang();

        break;
        }
    case TAG("listin"):
        {
        if (TAG("message_obj-13") == objectId)
            this->message_01_listin_bang_bang();

        break;
        }
    }
}

MessageTagInfo resolveTag(MessageTag tag) const {
    switch (tag) {
    case TAG("setup"):
        {
        return "setup";
        }
    case TAG("meter~_obj-14"):
        {
        return "meter~_obj-14";
        }
    case TAG("peak"):
        {
        return "peak";
        }
    case TAG("valout"):
        {
        return "valout";
        }
    case TAG("gain~_obj-11"):
        {
        return "gain~_obj-11";
        }
    case TAG("number_obj-6"):
        {
        return "number_obj-6";
        }
    case TAG("toggle_obj-2"):
        {
        return "toggle_obj-2";
        }
    case TAG("listout"):
        {
        return "listout";
        }
    case TAG("message_obj-13"):
        {
        return "message_obj-13";
        }
    case TAG("toggle_obj-22"):
        {
        return "toggle_obj-22";
        }
    case TAG("valin"):
        {
        return "valin";
        }
    case TAG("format"):
        {
        return "format";
        }
    case TAG("startupbang"):
        {
        return "startupbang";
        }
    case TAG("loadbang_obj-15"):
        {
        return "loadbang_obj-15";
        }
    case TAG("listin"):
        {
        return "listin";
        }
    }

    return "";
}

MessageIndex getNumMessages() const {
    return 0;
}

const MessageInfo& getMessageInfo(MessageIndex index) const {
    switch (index) {

    }

    return NullMessageInfo;
}

protected:

void gaintilde_01_valin_set(number v) {
    this->gaintilde_01_value_set(v);
}

void numberobj_01_valin_set(number v) {
    this->numberobj_01_value_set(v);
}

void numberobj_01_format_set(number v) {
    this->numberobj_01_currentFormat = rnbo_trunc((v > 6 ? 6 : (v < 0 ? 0 : v)));
}

void metro_01_tick_bang() {
    this->metro_01_tickout_bang();
    this->getEngine()->flushClockEvents(this, -1987572531, false);;

    if ((bool)(this->metro_01_on)) {
        {
            this->getEngine()->scheduleClockEvent(this, -1987572531, this->metro_01_interval + this->_currentTime);;
        }
    }
}

void toggle_01_valin_set(number v) {
    this->toggle_01_value_number_set(v);
}

void loadbang_01_startupbang_bang() {
    this->loadbang_01_output_bang();
}

void message_01_listin_list_set(const list& v) {
    {
        list __value = jsCreateListCopy(v);
        this->message_01_input = jsCreateListCopy(__value);
    };
}

void message_01_listin_number_set(number v) {
    {
        list __value = v;
        this->message_01_input = jsCreateListCopy(__value);
    };
}

void message_01_listin_bang_bang() {
    this->message_01_input_bang();
}

void metro_02_tick_bang() {
    this->metro_02_tickout_bang();
    this->getEngine()->flushClockEvents(this, 1935387534, false);;

    if ((bool)(this->metro_02_on)) {
        {
            this->getEngine()->scheduleClockEvent(this, 1935387534, this->metro_02_interval + this->_currentTime);;
        }
    }
}

void toggle_02_valin_set(number v) {
    this->toggle_02_value_number_set(v);
}

void metertilde_01_value_set(number ) {}

number msToSamps(MillisecondTime ms, number sampleRate) {
    return ms * sampleRate * 0.001;
}

MillisecondTime sampsToMs(SampleIndex samps) {
    return samps * (this->invsr * 1000);
}

Index getMaxBlockSize() const {
    return this->maxvs;
}

number getSampleRate() const {
    return this->sr;
}

bool hasFixedVectorSize() const {
    return false;
}

Index getNumInputChannels() const {
    return 0;
}

Index getNumOutputChannels() const {
    return 2;
}

void allocateDataRefs() {}

void initializeObjects() {
    this->noise_tilde_01_init();
    this->metertilde_01_init();
    this->gaintilde_01_init();
    this->numberobj_01_init();
    this->message_01_init();
    this->random_01_nz_init();
}

void sendOutlet(OutletIndex index, ParameterValue value) {
    this->getEngine()->sendOutlet(this, index, value);
}

void startup() {
    this->updateTime(this->getEngine()->getCurrentTime());

    if ((bool)(this->metro_01_on))
        this->metro_01_on_set(1);

    this->getEngine()->scheduleClockEvent(this, -871642103, 0 + this->_currentTime);;

    if ((bool)(this->metro_02_on))
        this->metro_02_on_set(1);

    this->processParamInitEvents();
}

void gaintilde_01_outval_set(number ) {}

void gaintilde_01_value_set(number v) {
    this->gaintilde_01_value = v;
    number value;
    value = this->scale(v, 0, 157, 0, 158 - 1, 1);
    this->getEngine()->sendNumMessage(TAG("valout"), TAG("gain~_obj-11"), v, this->_currentTime);
    this->gaintilde_01_outval_set(value);
}

void saw_tilde_01_frequency_set(number v) {
    this->saw_tilde_01_frequency = v;
}

void metro_01_interval_set(number v) {
    this->metro_01_interval_setter(v);
    v = this->metro_01_interval;
}

void expr_01_out1_set(number v) {
    this->expr_01_out1 = v;
    this->metro_01_interval_set(this->expr_01_out1);
}

void expr_01_in1_set(number in1) {
    this->expr_01_in1 = in1;
    this->expr_01_out1_set(this->expr_01_in1 * this->expr_01_in2);//#map:*_obj-7:1
}

void numberobj_01_output_set(number v) {
    this->saw_tilde_01_frequency_set(v);
    this->expr_01_in1_set(v);
}

void numberobj_01_value_set(number v) {
    this->numberobj_01_value_setter(v);
    v = this->numberobj_01_value;
    number localvalue = v;

    if (this->numberobj_01_currentFormat != 6) {
        localvalue = rnbo_trunc(localvalue);
    }

    this->getEngine()->sendNumMessage(TAG("valout"), TAG("number_obj-6"), localvalue, this->_currentTime);
    this->numberobj_01_output_set(localvalue);
}

void counter_01_output_set(number v) {
    this->counter_01_output = v;
    this->numberobj_01_value_set(v);
}

void counter_01_overflow_bang_bang() {}

static number counter_01_overflow_number_constrain(number v) {
    if (v < 0)
        v = 0;

    if (v > 1)
        v = 1;

    return v;
}

void counter_01_overflow_number_set(number v) {
    v = this->counter_01_overflow_number_constrain(v);
    this->counter_01_overflow_number = v;
}

void counter_01_carry_set(number v) {
    this->counter_01_carry = v;
}

void counter_01_underflow_bang_bang() {}

static number counter_01_underflow_number_constrain(number v) {
    if (v < 0)
        v = 0;

    if (v > 1)
        v = 1;

    return v;
}

void counter_01_underflow_number_set(number v) {
    v = this->counter_01_underflow_number_constrain(v);
    this->counter_01_underflow_number = v;
}

void counter_01_input_bang() {
    this->counter_01_output_set(this->counter_01_count);
    this->counter_01_inc();

    if (this->counter_01_count > this->counter_01_maximum) {
        if (this->counter_01_direction == 2) {
            this->counter_01_phase = !(bool)(this->counter_01_phase);
            this->counter_01_count = this->counter_01_maximum;
            this->counter_01_inc();
        } else
            this->counter_01_count = this->counter_01_minimum;

        if ((bool)(!(bool)(this->counter_01_overflow_number))) {
            if (this->counter_01_carryflag == 1)
                this->counter_01_overflow_bang_bang();
            else
                this->counter_01_overflow_number_set(1);
        }

        this->counter_01_carry_set(this->counter_01_carry + 1);
    } else if ((bool)(this->counter_01_overflow_number) && this->counter_01_carryflag == 0)
        this->counter_01_overflow_number_set(0);

    if (this->counter_01_count < this->counter_01_minimum) {
        if (this->counter_01_direction == 2) {
            this->counter_01_phase = !(bool)(this->counter_01_phase);
            this->counter_01_count = this->counter_01_minimum;
            this->counter_01_inc();
        } else
            this->counter_01_count = this->counter_01_maximum;

        if ((bool)(!(bool)(this->counter_01_underflow_number))) {
            if (this->counter_01_carryflag == 1)
                this->counter_01_underflow_bang_bang();
            else
                this->counter_01_underflow_number_set(1);
        }

        this->counter_01_carry_set(this->counter_01_carry + 1);
    } else if ((bool)(this->counter_01_underflow_number) && this->counter_01_carryflag == 0)
        this->counter_01_underflow_number_set(0);
}

void metro_01_tickout_bang() {
    this->counter_01_input_bang();
}

void metro_01_on_set(number v) {
    this->metro_01_on = v;
    this->getEngine()->flushClockEvents(this, -1987572531, false);;

    if ((bool)(v)) {
        {
            this->getEngine()->scheduleClockEvent(this, -1987572531, 0 + this->_currentTime);;
        }
    }
}

void toggle_01_output_set(number v) {
    this->metro_01_on_set(v);
}

void toggle_01_value_number_set(number v) {
    this->toggle_01_value_number_setter(v);
    v = this->toggle_01_value_number;
    this->getEngine()->sendNumMessage(TAG("valout"), TAG("toggle_obj-2"), v, this->_currentTime);
    this->toggle_01_output_set(v);
}

void metro_02_on_set(number v) {
    this->metro_02_on = v;
    this->getEngine()->flushClockEvents(this, 1935387534, false);;

    if ((bool)(v)) {
        {
            this->getEngine()->scheduleClockEvent(this, 1935387534, 0 + this->_currentTime);;
        }
    }
}

void toggle_02_output_set(number v) {
    this->metro_02_on_set(v);
}

void toggle_02_value_number_set(number v) {
    this->toggle_02_value_number_setter(v);
    v = this->toggle_02_value_number;
    this->getEngine()->sendNumMessage(TAG("valout"), TAG("toggle_obj-22"), v, this->_currentTime);
    this->toggle_02_output_set(v);
}

void toggle_02_value_bang_bang() {
    number val = (this->toggle_02_value_number == 1 ? 0 : 1);
    this->toggle_02_value_number_set(val);
}

void gaintilde_01_input_number_set(number v) {
    this->gaintilde_01_input_number = v;

    this->gaintilde_01_value_set(
        this->scale((v > 158 - 1 ? 158 - 1 : (v < 0 ? 0 : v)), 0, 158 - 1, 0, 157, 1)
    );
}

void message_01_out_set(const list& v) {
    {
        number converted = (v->length > 0 ? v[0] : 0);
        this->gaintilde_01_input_number_set(converted);
    }
}

void message_01_input_bang() {
    list v = this->message_01_input;
    this->message_01_out_set(v);
}

void toggle_01_value_bang_bang() {
    number val = (this->toggle_01_value_number == 1 ? 0 : 1);
    this->toggle_01_value_number_set(val);
}

void loadbang_01_output_bang() {
    this->toggle_02_value_bang_bang();
    this->message_01_input_bang();
    this->toggle_01_value_bang_bang();
}

void counter_01_maximum_set(number v) {
    this->counter_01_maximum = v;

    if (this->counter_01_count > this->counter_01_maximum)
        this->counter_01_count = this->counter_01_minimum;
}

void random_01_result_set(number v) {
    this->counter_01_maximum_set(v);
}

void random_01_trigger_bang() {
    {
        this->random_01_result_set(this->random(0, this->random_01_limit));
    }
}

void metro_02_tickout_bang() {
    this->random_01_trigger_bang();
}

void noise_tilde_01_perform(SampleValue * out1, Index n) {
    auto __noise_tilde_01_state = this->noise_tilde_01_state;
    Index i;

    for (i = 0; i < n; i++) {
        out1[(Index)i] = xoshiro_next(__noise_tilde_01_state);
    }
}

void saw_tilde_01_perform(
    number frequency,
    number syncPhase,
    SampleValue * out1,
    SampleValue * out2,
    Index n
) {
    RNBO_UNUSED(syncPhase);
    auto __saw_tilde_01_didSync = this->saw_tilde_01_didSync;
    auto __saw_tilde_01_lastSyncDiff = this->saw_tilde_01_lastSyncDiff;
    auto __saw_tilde_01_lastSyncPhase = this->saw_tilde_01_lastSyncPhase;
    auto __saw_tilde_01_t = this->saw_tilde_01_t;
    Index i;

    for (i = 0; i < n; i++) {
        number dt = frequency / this->samplerate();
        number t1 = __saw_tilde_01_t + 0.5;
        t1 -= rnbo_trunc(t1);
        number y = 2 * t1 - 1;

        if (dt != 0.0) {
            number syncDiff = 0 - __saw_tilde_01_lastSyncPhase;
            __saw_tilde_01_lastSyncPhase = 0;
            __saw_tilde_01_lastSyncDiff = syncDiff;
            number lookahead = 0 + syncDiff;

            if (t1 < dt) {
                number d = t1 / dt;
                y -= d + d - d * d - 1;
            } else if (t1 + dt > 1) {
                number d = (t1 - 1) / dt;
                y -= d + d + d * d + 1;
            } else if ((bool)(__saw_tilde_01_didSync)) {
                y = 0;
                __saw_tilde_01_didSync = false;
            } else if (lookahead > 1) {
                y *= 0.5;
                __saw_tilde_01_t = 0;
                __saw_tilde_01_didSync = true;
            }

            __saw_tilde_01_t += dt;

            if (dt > 0) {
                while (__saw_tilde_01_t >= 1) {
                    __saw_tilde_01_t -= 1;
                }
            } else {
                while (__saw_tilde_01_t <= 0) {
                    __saw_tilde_01_t += 1;
                }
            }
        }

        y = this->saw_tilde_01_dcblocker_next(y, 0.9997);
        out1[(Index)i] = 0.5 * y;
        out2[(Index)i] = __saw_tilde_01_t;
    }

    this->saw_tilde_01_t = __saw_tilde_01_t;
    this->saw_tilde_01_lastSyncPhase = __saw_tilde_01_lastSyncPhase;
    this->saw_tilde_01_lastSyncDiff = __saw_tilde_01_lastSyncDiff;
    this->saw_tilde_01_didSync = __saw_tilde_01_didSync;
}

void dspexpr_01_perform(const Sample * in1, const Sample * in2, SampleValue * out1, Index n) {
    Index i;

    for (i = 0; i < n; i++) {
        out1[(Index)i] = in1[(Index)i] * in2[(Index)i];//#map:_###_obj_###_:1
    }
}

void gaintilde_01_perform(const SampleValue * input_signal, SampleValue * output, Index n) {
    auto __gaintilde_01_interp = this->gaintilde_01_interp;
    auto __gaintilde_01_loginc = this->gaintilde_01_loginc;
    auto __gaintilde_01_zval = this->gaintilde_01_zval;
    auto __gaintilde_01_value = this->gaintilde_01_value;
    number mult = (__gaintilde_01_value <= 0 ? 0. : __gaintilde_01_zval * rnbo_exp(__gaintilde_01_value * __gaintilde_01_loginc));
    auto iv = this->mstosamps(__gaintilde_01_interp);

    for (Index i = 0; i < n; i++) {
        output[(Index)i] = input_signal[(Index)i] * this->gaintilde_01_ramp_next(mult, iv, iv);
    }
}

void metertilde_01_perform(const SampleValue * input, Index n) {
    auto __metertilde_01_currentIntervalInSamples = this->metertilde_01_currentIntervalInSamples;
    auto __metertilde_01_currentInterval = this->metertilde_01_currentInterval;
    auto __metertilde_01_currentPeak = this->metertilde_01_currentPeak;

    for (Index i = 0; i < n; i++) {
        number value = (input[(Index)i] < 0 ? -input[(Index)i] : input[(Index)i]);

        if (value > __metertilde_01_currentPeak)
            __metertilde_01_currentPeak = value;
    }

    __metertilde_01_currentInterval -= n;

    if (__metertilde_01_currentInterval <= 0) {
        __metertilde_01_currentInterval = __metertilde_01_currentIntervalInSamples;

        this->getEngine()->sendNumMessage(
            TAG("peak"),
            TAG("meter~_obj-14"),
            __metertilde_01_currentPeak,
            this->_currentTime
        );;

        this->getEngine()->scheduleClockEventWithValue(
            this,
            1777613927,
            this->sampsToMs((SampleIndex)(this->vs)) + this->_currentTime,
            __metertilde_01_currentPeak
        );;

        __metertilde_01_currentPeak = 0;
    }

    this->metertilde_01_currentPeak = __metertilde_01_currentPeak;
    this->metertilde_01_currentInterval = __metertilde_01_currentInterval;
}

void signalforwarder_01_perform(const SampleValue * input, SampleValue * output, Index n) {
    for (Index i = 0; i < n; i++) {
        output[(Index)i] = input[(Index)i];
    }
}

void stackprotect_perform(Index n) {
    RNBO_UNUSED(n);
    auto __stackprotect_count = this->stackprotect_count;
    __stackprotect_count = 0;
    this->stackprotect_count = __stackprotect_count;
}

void numberobj_01_value_setter(number v) {
    number localvalue = v;

    if (this->numberobj_01_currentFormat != 6) {
        localvalue = rnbo_trunc(localvalue);
    }

    this->numberobj_01_value = localvalue;
}

void metro_01_interval_setter(number v) {
    this->metro_01_interval = (v > 0 ? v : 0);
}

void toggle_01_value_number_setter(number v) {
    this->toggle_01_value_number = (v != 0 ? 1 : 0);
}

void random_01_limit_setter(number v) {
    if (v >= 0)
        this->random_01_limit = v;
}

void metro_02_interval_setter(number v) {
    this->metro_02_interval = (v > 0 ? v : 0);
}

void toggle_02_value_number_setter(number v) {
    this->toggle_02_value_number = (v != 0 ? 1 : 0);
}

void noise_tilde_01_init() {
    this->noise_tilde_01_reset();
}

void noise_tilde_01_reset() {
    xoshiro_reset(
        systemticks() + this->voice() + this->random(0, 10000),
        this->noise_tilde_01_state
    );
}

void metertilde_01_init() {
    this->getEngine()->sendNumMessage(TAG("setup"), TAG("meter~_obj-14"), 1, this->_currentTime);
}

void metertilde_01_dspsetup(bool force) {
    if ((bool)(this->metertilde_01_setupDone) && (bool)(!(bool)(force)))
        return;

    this->metertilde_01_currentIntervalInSamples = this->mstosamps(50);
    this->metertilde_01_currentInterval = this->metertilde_01_currentIntervalInSamples;
    this->metertilde_01_setupDone = true;
}

number gaintilde_01_ramp_d_next(number x) {
    number temp = (number)(x - this->gaintilde_01_ramp_d_prev);
    this->gaintilde_01_ramp_d_prev = x;
    return temp;
}

void gaintilde_01_ramp_d_dspsetup() {
    this->gaintilde_01_ramp_d_reset();
}

void gaintilde_01_ramp_d_reset() {
    this->gaintilde_01_ramp_d_prev = 0;
}

number gaintilde_01_ramp_next(number x, number up, number down) {
    if (this->gaintilde_01_ramp_d_next(x) != 0.) {
        if (x > this->gaintilde_01_ramp_prev) {
            number _up = up;

            if (_up < 1)
                _up = 1;

            this->gaintilde_01_ramp_index = _up;
            this->gaintilde_01_ramp_increment = (x - this->gaintilde_01_ramp_prev) / _up;
        } else if (x < this->gaintilde_01_ramp_prev) {
            number _down = down;

            if (_down < 1)
                _down = 1;

            this->gaintilde_01_ramp_index = _down;
            this->gaintilde_01_ramp_increment = (x - this->gaintilde_01_ramp_prev) / _down;
        }
    }

    if (this->gaintilde_01_ramp_index > 0) {
        this->gaintilde_01_ramp_prev += this->gaintilde_01_ramp_increment;
        this->gaintilde_01_ramp_index -= 1;
    } else {
        this->gaintilde_01_ramp_prev = x;
    }

    return this->gaintilde_01_ramp_prev;
}

void gaintilde_01_ramp_reset() {
    this->gaintilde_01_ramp_prev = 0;
    this->gaintilde_01_ramp_index = 0;
    this->gaintilde_01_ramp_increment = 0;
    this->gaintilde_01_ramp_d_reset();
}

void gaintilde_01_init() {
    this->gaintilde_01_loginc = rnbo_log(1.072);
    this->gaintilde_01_zval = 7.943 * rnbo_exp(-((158 - 1) * this->gaintilde_01_loginc));
}

void gaintilde_01_getPresetValue(PatcherStateInterface& preset) {
    preset["value"] = this->gaintilde_01_value;
}

void gaintilde_01_setPresetValue(PatcherStateInterface& preset) {
    if ((bool)(stateIsEmpty(preset)))
        return;

    this->gaintilde_01_value_set(preset["value"]);
}

void gaintilde_01_dspsetup(bool force) {
    if ((bool)(this->gaintilde_01_setupDone) && (bool)(!(bool)(force)))
        return;

    this->gaintilde_01_setupDone = true;
    this->gaintilde_01_ramp_d_dspsetup();
}

number saw_tilde_01_dcblocker_next(number x, number gain) {
    number y = x - this->saw_tilde_01_dcblocker_xm1 + this->saw_tilde_01_dcblocker_ym1 * gain;
    this->saw_tilde_01_dcblocker_xm1 = x;
    this->saw_tilde_01_dcblocker_ym1 = y;
    return y;
}

void saw_tilde_01_dcblocker_reset() {
    this->saw_tilde_01_dcblocker_xm1 = 0;
    this->saw_tilde_01_dcblocker_ym1 = 0;
}

void saw_tilde_01_dcblocker_dspsetup() {
    this->saw_tilde_01_dcblocker_reset();
}

void saw_tilde_01_dspsetup(bool force) {
    if ((bool)(this->saw_tilde_01_setupDone) && (bool)(!(bool)(force)))
        return;

    this->saw_tilde_01_setupDone = true;
    this->saw_tilde_01_dcblocker_dspsetup();
}

void numberobj_01_init() {
    this->numberobj_01_currentFormat = 6;
    this->getEngine()->sendNumMessage(TAG("setup"), TAG("number_obj-6"), 1, this->_currentTime);
}

void numberobj_01_getPresetValue(PatcherStateInterface& preset) {
    preset["value"] = this->numberobj_01_value;
}

void numberobj_01_setPresetValue(PatcherStateInterface& preset) {
    if ((bool)(stateIsEmpty(preset)))
        return;

    this->numberobj_01_value_set(preset["value"]);
}

void counter_01_inc() {
    this->counter_01_count = ((bool)(this->counter_01_phase) ? this->counter_01_count + 1 : this->counter_01_count - 1);
}

void metro_01_onTransportChanged(number ) {}

void metro_01_onBeatTimeChanged(number ) {}

void toggle_01_getPresetValue(PatcherStateInterface& preset) {
    preset["value"] = this->toggle_01_value_number;
}

void toggle_01_setPresetValue(PatcherStateInterface& preset) {
    if ((bool)(stateIsEmpty(preset)))
        return;

    this->toggle_01_value_number_set(preset["value"]);
}

void message_01_init() {
    {
        list __value = {100};
        this->message_01_input = jsCreateListCopy(__value);
    };
}

void random_01_nz_reset() {
    xoshiro_reset(
        systemticks() + this->voice() + this->random(0, 10000),
        this->random_01_nz_state
    );
}

void random_01_nz_init() {
    this->random_01_nz_reset();
}

void random_01_nz_seed(number v) {
    xoshiro_reset(v, this->random_01_nz_state);
}

number random_01_nz_next() {
    return xoshiro_next(this->random_01_nz_state);
}

void metro_02_onTransportChanged(number ) {}

void metro_02_onBeatTimeChanged(number ) {}

void toggle_02_getPresetValue(PatcherStateInterface& preset) {
    preset["value"] = this->toggle_02_value_number;
}

void toggle_02_setPresetValue(PatcherStateInterface& preset) {
    if ((bool)(stateIsEmpty(preset)))
        return;

    this->toggle_02_value_number_set(preset["value"]);
}

Index globaltransport_getSampleOffset(MillisecondTime time) {
    return this->mstosamps(this->maximum(0, time - this->getEngine()->getCurrentTime()));
}

number globaltransport_getTempoAtSample(SampleIndex sampleOffset) {
    return (sampleOffset >= 0 && sampleOffset < this->vs ? this->globaltransport_tempo[(Index)sampleOffset] : this->globaltransport_lastTempo);
}

number globaltransport_getStateAtSample(SampleIndex sampleOffset) {
    return (sampleOffset >= 0 && sampleOffset < this->vs ? this->globaltransport_state[(Index)sampleOffset] : this->globaltransport_lastState);
}

number globaltransport_getState(MillisecondTime time) {
    return this->globaltransport_getStateAtSample(this->globaltransport_getSampleOffset(time));
}

number globaltransport_getBeatTime(MillisecondTime time) {
    number i = 2;

    while (i < this->globaltransport_beatTimeChanges->length && this->globaltransport_beatTimeChanges[(Index)(i + 1)] <= time) {
        i += 2;
    }

    i -= 2;
    number beatTimeBase = this->globaltransport_beatTimeChanges[(Index)i];

    if (this->globaltransport_getState(time) == 0)
        return beatTimeBase;

    number beatTimeBaseMsTime = this->globaltransport_beatTimeChanges[(Index)(i + 1)];
    number diff = time - beatTimeBaseMsTime;
    return beatTimeBase + this->mstobeats(diff);
}

bool globaltransport_setTempo(MillisecondTime time, number tempo, bool notify) {
    if ((bool)(notify)) {
        this->processTempoEvent(time, tempo);
        this->globaltransport_notify = true;
    } else {
        Index offset = (Index)(this->globaltransport_getSampleOffset(time));

        if (this->globaltransport_getTempoAtSample(offset) != tempo) {
            this->globaltransport_beatTimeChanges->push(this->globaltransport_getBeatTime(time));
            this->globaltransport_beatTimeChanges->push(time);
            fillSignal(this->globaltransport_tempo, this->vs, tempo, offset);
            this->globaltransport_lastTempo = tempo;
            this->globaltransport_tempoNeedsReset = true;
            return true;
        }
    }

    return false;
}

number globaltransport_getTempo(MillisecondTime time) {
    return this->globaltransport_getTempoAtSample(this->globaltransport_getSampleOffset(time));
}

bool globaltransport_setState(MillisecondTime time, number state, bool notify) {
    if ((bool)(notify)) {
        this->processTransportEvent(time, TransportState(state));
        this->globaltransport_notify = true;
    } else {
        Index offset = (Index)(this->globaltransport_getSampleOffset(time));

        if (this->globaltransport_getStateAtSample(offset) != state) {
            fillSignal(this->globaltransport_state, this->vs, state, offset);
            this->globaltransport_lastState = TransportState(state);
            this->globaltransport_stateNeedsReset = true;

            if (state == 0) {
                this->globaltransport_beatTimeChanges->push(this->globaltransport_getBeatTime(time));
                this->globaltransport_beatTimeChanges->push(time);
            }

            return true;
        }
    }

    return false;
}

bool globaltransport_setBeatTime(MillisecondTime time, number beattime, bool notify) {
    if ((bool)(notify)) {
        this->processBeatTimeEvent(time, beattime);
        this->globaltransport_notify = true;
        return false;
    } else {
        bool beatTimeHasChanged = false;
        float oldBeatTime = (float)(this->globaltransport_getBeatTime(time));
        float newBeatTime = (float)(beattime);

        if (oldBeatTime != newBeatTime) {
            beatTimeHasChanged = true;
        }

        this->globaltransport_beatTimeChanges->push(beattime);
        this->globaltransport_beatTimeChanges->push(time);
        return beatTimeHasChanged;
    }
}

number globaltransport_getBeatTimeAtSample(SampleIndex sampleOffset) {
    auto msOffset = this->sampstoms(sampleOffset);
    return this->globaltransport_getBeatTime(this->getEngine()->getCurrentTime() + msOffset);
}

array<number, 2> globaltransport_getTimeSignature(MillisecondTime time) {
    number i = 3;

    while (i < this->globaltransport_timeSignatureChanges->length && this->globaltransport_timeSignatureChanges[(Index)(i + 2)] <= time) {
        i += 3;
    }

    i -= 3;

    return {
        this->globaltransport_timeSignatureChanges[(Index)i],
        this->globaltransport_timeSignatureChanges[(Index)(i + 1)]
    };
}

array<number, 2> globaltransport_getTimeSignatureAtSample(SampleIndex sampleOffset) {
    auto msOffset = this->sampstoms(sampleOffset);
    return this->globaltransport_getTimeSignature(this->getEngine()->getCurrentTime() + msOffset);
}

bool globaltransport_setTimeSignature(MillisecondTime time, number numerator, number denominator, bool notify) {
    if ((bool)(notify)) {
        this->processTimeSignatureEvent(time, (int)(numerator), (int)(denominator));
        this->globaltransport_notify = true;
    } else {
        array<number, 2> currentSig = this->globaltransport_getTimeSignature(time);

        if (currentSig[0] != numerator || currentSig[1] != denominator) {
            this->globaltransport_timeSignatureChanges->push(numerator);
            this->globaltransport_timeSignatureChanges->push(denominator);
            this->globaltransport_timeSignatureChanges->push(time);
            return true;
        }
    }

    return false;
}

void globaltransport_advance() {
    if ((bool)(this->globaltransport_tempoNeedsReset)) {
        fillSignal(this->globaltransport_tempo, this->vs, this->globaltransport_lastTempo);
        this->globaltransport_tempoNeedsReset = false;

        if ((bool)(this->globaltransport_notify)) {
            this->getEngine()->sendTempoEvent(this->globaltransport_lastTempo);
        }
    }

    if ((bool)(this->globaltransport_stateNeedsReset)) {
        fillSignal(this->globaltransport_state, this->vs, this->globaltransport_lastState);
        this->globaltransport_stateNeedsReset = false;

        if ((bool)(this->globaltransport_notify)) {
            this->getEngine()->sendTransportEvent(TransportState(this->globaltransport_lastState));
        }
    }

    if (this->globaltransport_beatTimeChanges->length > 2) {
        this->globaltransport_beatTimeChanges[0] = this->globaltransport_beatTimeChanges[(Index)(this->globaltransport_beatTimeChanges->length - 2)];
        this->globaltransport_beatTimeChanges[1] = this->globaltransport_beatTimeChanges[(Index)(this->globaltransport_beatTimeChanges->length - 1)];
        this->globaltransport_beatTimeChanges->length = 2;

        if ((bool)(this->globaltransport_notify)) {
            this->getEngine()->sendBeatTimeEvent(this->globaltransport_beatTimeChanges[0]);
        }
    }

    if (this->globaltransport_timeSignatureChanges->length > 3) {
        this->globaltransport_timeSignatureChanges[0] = this->globaltransport_timeSignatureChanges[(Index)(this->globaltransport_timeSignatureChanges->length - 3)];
        this->globaltransport_timeSignatureChanges[1] = this->globaltransport_timeSignatureChanges[(Index)(this->globaltransport_timeSignatureChanges->length - 2)];
        this->globaltransport_timeSignatureChanges[2] = this->globaltransport_timeSignatureChanges[(Index)(this->globaltransport_timeSignatureChanges->length - 1)];
        this->globaltransport_timeSignatureChanges->length = 3;

        if ((bool)(this->globaltransport_notify)) {
            this->getEngine()->sendTimeSignatureEvent(
                (int)(this->globaltransport_timeSignatureChanges[0]),
                (int)(this->globaltransport_timeSignatureChanges[1])
            );
        }
    }

    this->globaltransport_notify = false;
}

void globaltransport_dspsetup(bool force) {
    if ((bool)(this->globaltransport_setupDone) && (bool)(!(bool)(force)))
        return;

    fillSignal(this->globaltransport_tempo, this->vs, this->globaltransport_lastTempo);
    this->globaltransport_tempoNeedsReset = false;
    fillSignal(this->globaltransport_state, this->vs, this->globaltransport_lastState);
    this->globaltransport_stateNeedsReset = false;
    this->globaltransport_setupDone = true;
}

bool stackprotect_check() {
    this->stackprotect_count++;

    if (this->stackprotect_count > 128) {
        console->log("STACK OVERFLOW DETECTED - stopped processing branch !");
        return true;
    }

    return false;
}

void updateTime(MillisecondTime time) {
    this->_currentTime = time;
    this->sampleOffsetIntoNextAudioBuffer = (SampleIndex)(rnbo_fround(this->msToSamps(time - this->getEngine()->getCurrentTime(), this->sr)));

    if (this->sampleOffsetIntoNextAudioBuffer >= (SampleIndex)(this->vs))
        this->sampleOffsetIntoNextAudioBuffer = (SampleIndex)(this->vs) - 1;

    if (this->sampleOffsetIntoNextAudioBuffer < 0)
        this->sampleOffsetIntoNextAudioBuffer = 0;
}

void assign_defaults()
{
    expr_01_in1 = 0;
    expr_01_in2 = 20;
    expr_01_out1 = 0;
    dspexpr_01_in1 = 0;
    dspexpr_01_in2 = 0;
    gaintilde_01_input_number = 0;
    gaintilde_01_value = 0;
    gaintilde_01_interp = 10;
    saw_tilde_01_frequency = 0;
    saw_tilde_01_syncPhase = 0;
    numberobj_01_value = 0;
    numberobj_01_value_setter(numberobj_01_value);
    counter_01_carryflag = 0;
    counter_01_direction = 2;
    counter_01_resetnext_number = 0;
    counter_01_resetnow_number = 0;
    counter_01_maximum = 50;
    counter_01_output = 0;
    counter_01_underflow_number = 0;
    counter_01_overflow_number = 0;
    counter_01_carry = 0;
    counter_01_minimum = 0;
    metro_01_on = 0;
    metro_01_interval = 1000;
    metro_01_interval_setter(metro_01_interval);
    toggle_01_value_number = 0;
    toggle_01_value_number_setter(toggle_01_value_number);
    random_01_limit = 30;
    random_01_limit_setter(random_01_limit);
    random_01_seed = 0;
    metro_02_on = 0;
    metro_02_interval = 1000;
    metro_02_interval_setter(metro_02_interval);
    toggle_02_value_number = 0;
    toggle_02_value_number_setter(toggle_02_value_number);
    _currentTime = 0;
    audioProcessSampleCount = 0;
    sampleOffsetIntoNextAudioBuffer = 0;
    zeroBuffer = nullptr;
    dummyBuffer = nullptr;
    signals[0] = nullptr;
    signals[1] = nullptr;
    signals[2] = nullptr;
    didAllocateSignals = 0;
    vs = 0;
    maxvs = 0;
    sr = 44100;
    invsr = 0.00002267573696;
    metertilde_01_currentPeak = 0;
    metertilde_01_currentInterval = 0;
    metertilde_01_currentIntervalInSamples = 0;
    metertilde_01_setupDone = false;
    gaintilde_01_lastValue = 0;
    gaintilde_01_loginc = 1;
    gaintilde_01_zval = 0;
    gaintilde_01_ramp_d_prev = 0;
    gaintilde_01_ramp_prev = 0;
    gaintilde_01_ramp_index = 0;
    gaintilde_01_ramp_increment = 0;
    gaintilde_01_setupDone = false;
    saw_tilde_01_t = 0;
    saw_tilde_01_lastSyncPhase = 0;
    saw_tilde_01_lastSyncDiff = 0;
    saw_tilde_01_didSync = false;
    saw_tilde_01_dcblocker_xm1 = 0;
    saw_tilde_01_dcblocker_ym1 = 0;
    saw_tilde_01_setupDone = false;
    numberobj_01_currentFormat = 6;
    numberobj_01_lastValue = 0;
    counter_01_count = 0;
    counter_01_phase = true;
    toggle_01_lastValue = 0;
    toggle_02_lastValue = 0;
    globaltransport_tempo = nullptr;
    globaltransport_tempoNeedsReset = false;
    globaltransport_lastTempo = 120;
    globaltransport_state = nullptr;
    globaltransport_stateNeedsReset = false;
    globaltransport_lastState = 0;
    globaltransport_beatTimeChanges = { 0, 0 };
    globaltransport_timeSignatureChanges = { 4, 4, 0 };
    globaltransport_notify = false;
    globaltransport_setupDone = false;
    stackprotect_count = 0;
    _voiceIndex = 0;
    _noteNumber = 0;
    isMuted = 1;
}

// member variables

    number expr_01_in1;
    number expr_01_in2;
    number expr_01_out1;
    number dspexpr_01_in1;
    number dspexpr_01_in2;
    number gaintilde_01_input_number;
    number gaintilde_01_value;
    number gaintilde_01_interp;
    number saw_tilde_01_frequency;
    number saw_tilde_01_syncPhase;
    number numberobj_01_value;
    Int counter_01_carryflag;
    number counter_01_direction;
    number counter_01_resetnext_number;
    number counter_01_resetnow_number;
    number counter_01_maximum;
    number counter_01_output;
    number counter_01_underflow_number;
    number counter_01_overflow_number;
    number counter_01_carry;
    number counter_01_minimum;
    number metro_01_on;
    number metro_01_interval;
    number toggle_01_value_number;
    list message_01_input;
    number random_01_limit;
    number random_01_seed;
    number metro_02_on;
    number metro_02_interval;
    number toggle_02_value_number;
    MillisecondTime _currentTime;
    SampleIndex audioProcessSampleCount;
    SampleIndex sampleOffsetIntoNextAudioBuffer;
    signal zeroBuffer;
    signal dummyBuffer;
    SampleValue * signals[3];
    bool didAllocateSignals;
    Index vs;
    Index maxvs;
    number sr;
    number invsr;
    UInt noise_tilde_01_state[4] = { };
    number metertilde_01_currentPeak;
    SampleIndex metertilde_01_currentInterval;
    SampleIndex metertilde_01_currentIntervalInSamples;
    bool metertilde_01_setupDone;
    number gaintilde_01_lastValue;
    number gaintilde_01_loginc;
    number gaintilde_01_zval;
    number gaintilde_01_ramp_d_prev;
    number gaintilde_01_ramp_prev;
    number gaintilde_01_ramp_index;
    number gaintilde_01_ramp_increment;
    bool gaintilde_01_setupDone;
    number saw_tilde_01_t;
    number saw_tilde_01_lastSyncPhase;
    number saw_tilde_01_lastSyncDiff;
    bool saw_tilde_01_didSync;
    number saw_tilde_01_dcblocker_xm1;
    number saw_tilde_01_dcblocker_ym1;
    bool saw_tilde_01_setupDone;
    Int numberobj_01_currentFormat;
    number numberobj_01_lastValue;
    number counter_01_count;
    bool counter_01_phase;
    number toggle_01_lastValue;
    UInt random_01_nz_state[4] = { };
    number toggle_02_lastValue;
    signal globaltransport_tempo;
    bool globaltransport_tempoNeedsReset;
    number globaltransport_lastTempo;
    signal globaltransport_state;
    bool globaltransport_stateNeedsReset;
    number globaltransport_lastState;
    list globaltransport_beatTimeChanges;
    list globaltransport_timeSignatureChanges;
    bool globaltransport_notify;
    bool globaltransport_setupDone;
    number stackprotect_count;
    Index _voiceIndex;
    Int _noteNumber;
    Index isMuted;
    indexlist paramInitIndices;
    indexlist paramInitOrder;

};

PatcherInterface* creaternbomatic()
{
    return new rnbomatic();
}

#ifndef RNBO_NO_PATCHERFACTORY

extern "C" PatcherFactoryFunctionPtr GetPatcherFactoryFunction(PlatformInterface* platformInterface)
#else

extern "C" PatcherFactoryFunctionPtr rnbomaticFactoryFunction(PlatformInterface* platformInterface)
#endif

{
    Platform::set(platformInterface);
    return creaternbomatic;
}

} // end RNBO namespace

