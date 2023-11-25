#include "reverb.h"

namespace reverb {

/****************************************************************************************
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

For entities with UNDER 200k USD in annual revenue or funding, a license is hereby
granted, free of charge, for the sale, sublicensing, or commercial distribution
of software that incorporates this source code, for as long as the entity's
annual revenue remains below 200k USD annual revenue or funding.

For entities with OVER 200k USD in annual revenue or funding interested in the
sale, sublicensing, or commercial distribution of software that incorporates
this source code, please send inquiries to licensing (at) cycling74.com.

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
https://support.cycling74.com/hc/en-us/articles/360050779193-Gen-Code-Export-Licensing-FAQ
for additional information

B) General Public License Version 3 (GPLv3)
Details of the GPLv3 license can be found at: https://www.gnu.org/licenses/gpl-3.0.html
****************************************************************************************/

// global noise generator
Noise noise;
static const int GENLIB_LOOPCOUNT_BAIL = 100000;


// The State struct contains all the state and procedures for the gendsp kernel
typedef struct State {
	CommonState __commonstate;
	Delay m_delay_10;
	Delay m_delay_6;
	Delay m_delay_5;
	Delay m_delay_7;
	Delay m_delay_8;
	Delay m_delay_9;
	Delay m_delay_4;
	Delay m_delay_13;
	Delay m_delay_16;
	Delay m_delay_12;
	Delay m_delay_15;
	Delay m_delay_14;
	Delay m_delay_11;
	SineCycle __m_cycle_22;
	SineCycle __m_cycle_21;
	SineData __sinedata;
	int vectorsize;
	int __exception;
	t_sample m_decay_19;
	t_sample m_ctrl1_wet_20;
	t_sample m_damping_18;
	t_sample m_predelay_17;
	t_sample m_history_1;
	t_sample samplerate;
	t_sample m_history_2;
	t_sample m_history_3;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_history_2 = ((int)0);
		m_history_3 = ((int)0);
		m_delay_4.reset("m_delay_4", ((int)924));
		m_delay_5.reset("m_delay_5", ((int)688));
		m_delay_6.reset("m_delay_6", ((int)4217));
		m_delay_7.reset("m_delay_7", ((int)3163));
		m_delay_8.reset("m_delay_8", ((int)2656));
		m_delay_9.reset("m_delay_9", ((int)3720));
		m_delay_10.reset("m_delay_10", ((int)1800));
		m_delay_11.reset("m_delay_11", ((int)4453));
		m_delay_12.reset("m_delay_12", ((int)142));
		m_delay_13.reset("m_delay_13", ((int)107));
		m_delay_14.reset("m_delay_14", ((int)379));
		m_delay_15.reset("m_delay_15", ((int)277));
		m_delay_16.reset("m_delay_16", (samplerate * 0.1));
		m_predelay_17 = ((int)10);
		m_damping_18 = ((t_sample)0.5);
		m_decay_19 = ((t_sample)0.5);
		m_ctrl1_wet_20 = ((int)0);
		__m_cycle_21.reset(samplerate, 0);
		__m_cycle_22.reset(samplerate, 0);
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		const t_sample * __in2 = __ins[1];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		t_sample mstosamps_94 = (m_predelay_17 * (samplerate * 0.001));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample add_1 = (in1 + in2);
			t_sample tap_125 = m_delay_16.read_linear(mstosamps_94);
			t_sample mix_161 = (tap_125 + (m_damping_18 * (m_history_1 - tap_125)));
			t_sample mix_123 = mix_161;
			t_sample tap_100 = m_delay_15.read_step(((int)277));
			t_sample mul_98 = (tap_100 * ((t_sample)0.625));
			t_sample tap_106 = m_delay_14.read_step(((int)379));
			t_sample mul_104 = (tap_106 * ((t_sample)0.625));
			t_sample tap_112 = m_delay_13.read_step(((int)107));
			t_sample mul_110 = (tap_112 * ((t_sample)0.75));
			t_sample tap_118 = m_delay_12.read_step(((int)142));
			t_sample mul_116 = (tap_118 * ((t_sample)0.75));
			t_sample sub_114 = (mix_123 - mul_116);
			t_sample mul_115 = (sub_114 * ((t_sample)0.75));
			t_sample add_113 = (mul_115 + tap_118);
			t_sample sub_108 = (add_113 - mul_110);
			t_sample mul_109 = (sub_108 * ((t_sample)0.75));
			t_sample add_107 = (mul_109 + tap_112);
			t_sample sub_102 = (add_107 - mul_104);
			t_sample mul_103 = (sub_102 * ((t_sample)0.625));
			t_sample add_101 = (mul_103 + tap_106);
			t_sample sub_96 = (add_101 - mul_98);
			t_sample mul_97 = (sub_96 * ((t_sample)0.625));
			t_sample add_95 = (mul_97 + tap_100);
			t_sample tap_70 = m_delay_11.read_step(((int)4453));
			t_sample tap_71 = m_delay_11.read_step(((int)353));
			t_sample tap_72 = m_delay_11.read_step(((int)3627));
			t_sample tap_73 = m_delay_11.read_step(((int)1990));
			t_sample tap_63 = m_delay_10.read_step(((int)1800));
			t_sample tap_64 = m_delay_10.read_step(((int)187));
			t_sample tap_65 = m_delay_10.read_step(((int)1228));
			t_sample tap_55 = m_delay_9.read_step(((int)3720));
			t_sample tap_56 = m_delay_9.read_step(((int)1066));
			t_sample tap_57 = m_delay_9.read_step(((int)2673));
			t_sample gen_90 = ((tap_57 + tap_71) + tap_72);
			t_sample tap_35 = m_delay_8.read_step(((int)2656));
			t_sample tap_36 = m_delay_8.read_step(((int)335));
			t_sample tap_37 = m_delay_8.read_step(((int)1913));
			t_sample gen_89 = (((tap_37 + tap_56) + tap_64) + tap_73);
			t_sample tap_27 = m_delay_7.read_step(((int)3163));
			t_sample tap_28 = m_delay_7.read_step(((int)121));
			t_sample tap_29 = m_delay_7.read_step(((int)1996));
			t_sample tap_39 = m_delay_6.read_step(((int)4217));
			t_sample tap_40 = m_delay_6.read_step(((int)266));
			t_sample tap_41 = m_delay_6.read_step(((int)2974));
			t_sample tap_42 = m_delay_6.read_step(((int)2111));
			t_sample gen_88 = ((tap_40 + tap_41) + tap_29);
			t_sample gen_91 = (((tap_42 + tap_36) + tap_28) + tap_65);
			t_sample mix_162 = (tap_39 + (m_damping_18 * (m_history_3 - tap_39)));
			t_sample mix_24 = mix_162;
			t_sample mix_163 = (tap_70 + (m_damping_18 * (m_history_2 - tap_70)));
			t_sample mix_68 = mix_163;
			t_sample mul_66 = (mix_68 * m_decay_19);
			t_sample mul_22 = (mix_24 * m_decay_19);
			t_sample mul_59 = (tap_63 * ((t_sample)0.5));
			t_sample sub_60 = (mul_66 - mul_59);
			t_sample mul_58 = (sub_60 * ((t_sample)0.5));
			t_sample add_61 = (mul_58 + tap_63);
			t_sample mul_31 = (tap_35 * ((t_sample)0.5));
			t_sample sub_32 = (mul_22 - mul_31);
			t_sample mul_30 = (sub_32 * ((t_sample)0.5));
			t_sample add_33 = (mul_30 + tap_35);
			t_sample mul_25 = (tap_27 * m_decay_19);
			t_sample add_85 = (add_95 + mul_25);
			__m_cycle_21.freq(((t_sample)0.1));
			t_sample cycle_74 = __m_cycle_21(__sinedata);
			t_sample cycleindex_75 = __m_cycle_21.phase();
			t_sample mul_76 = (cycle_74 * ((int)16));
			t_sample add_77 = (mul_76 + ((int)672));
			t_sample tap_83 = m_delay_5.read_linear(add_77);
			t_sample mul_79 = (tap_83 * ((t_sample)0.7));
			t_sample add_80 = (add_85 + mul_79);
			t_sample mul_78 = (add_80 * ((t_sample)0.7));
			t_sample rsub_81 = (tap_83 - mul_78);
			t_sample mul_53 = (tap_55 * m_decay_19);
			t_sample add_84 = (mul_53 + add_95);
			__m_cycle_22.freq(((t_sample)0.07));
			t_sample cycle_43 = __m_cycle_22(__sinedata);
			t_sample cycleindex_44 = __m_cycle_22.phase();
			t_sample mul_45 = (cycle_43 * ((int)16));
			t_sample add_46 = (mul_45 + ((int)908));
			t_sample tap_52 = m_delay_4.read_linear(add_46);
			t_sample mul_48 = (tap_52 * ((t_sample)0.7));
			t_sample add_49 = (add_84 + mul_48);
			t_sample mul_47 = (add_49 * ((t_sample)0.7));
			t_sample rsub_50 = (tap_52 - mul_47);
			t_sample history_23_next_86 = fixdenorm(mix_24);
			t_sample history_67_next_87 = fixdenorm(mix_68);
			t_sample sub_6 = (gen_90 - gen_91);
			t_sample mul_4 = (sub_6 * ((t_sample)0.6));
			t_sample mix_164 = (in2 + (m_ctrl1_wet_20 * (mul_4 - in2)));
			t_sample out2 = mix_164;
			t_sample sub_7 = (gen_88 - gen_89);
			t_sample mul_5 = (sub_7 * ((t_sample)0.6));
			t_sample mix_165 = (in1 + (m_ctrl1_wet_20 * (mul_5 - in1)));
			t_sample out1 = mix_165;
			t_sample history_122_next_126 = fixdenorm(mix_123);
			m_delay_16.write(add_1);
			m_delay_15.write(sub_96);
			m_delay_12.write(sub_114);
			m_delay_13.write(sub_108);
			m_delay_14.write(sub_102);
			m_delay_11.write(rsub_81);
			m_history_2 = history_67_next_87;
			m_history_3 = history_23_next_86;
			m_delay_4.write(add_49);
			m_delay_5.write(add_80);
			m_delay_6.write(rsub_50);
			m_delay_7.write(add_33);
			m_delay_8.write(sub_32);
			m_delay_9.write(add_61);
			m_delay_10.write(sub_60);
			m_history_1 = history_122_next_126;
			m_delay_4.step();
			m_delay_5.step();
			m_delay_6.step();
			m_delay_7.step();
			m_delay_8.step();
			m_delay_9.step();
			m_delay_10.step();
			m_delay_11.step();
			m_delay_12.step();
			m_delay_13.step();
			m_delay_14.step();
			m_delay_15.step();
			m_delay_16.step();
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			
		};
		return __exception;
		
	};
	inline void set_predelay(t_param _value) {
		m_predelay_17 = (_value < 0 ? 0 : (_value > 100 ? 100 : _value));
	};
	inline void set_damping(t_param _value) {
		m_damping_18 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_decay(t_param _value) {
		m_decay_19 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl1_wet(t_param _value) {
		m_ctrl1_wet_20 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 2;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 4; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "out1", "out2" };

/// Invoke the signal process of a State object

int perform(CommonState *cself, t_sample **ins, long numins, t_sample **outs, long numouts, long n) {
	State* self = (State *)cself;
	return self->perform(ins, outs, n);
}

/// Reset all parameters and stateful operators of a State object

void reset(CommonState *cself) {
	State* self = (State *)cself;
	self->reset(cself->sr, cself->vs);
}

/// Set a parameter of a State object

void setparameter(CommonState *cself, long index, t_param value, void *ref) {
	State *self = (State *)cself;
	switch (index) {
		case 0: self->set_ctrl1_wet(value); break;
		case 1: self->set_damping(value); break;
		case 2: self->set_decay(value); break;
		case 3: self->set_predelay(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_ctrl1_wet_20; break;
		case 1: *value = self->m_damping_18; break;
		case 2: *value = self->m_decay_19; break;
		case 3: *value = self->m_predelay_17; break;
		
		default: break;
	}
}

/// Get the name of a parameter of a State object

const char *getparametername(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].name;
	}
	return 0;
}

/// Get the minimum value of a parameter of a State object

t_param getparametermin(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmin;
	}
	return 0;
}

/// Get the maximum value of a parameter of a State object

t_param getparametermax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmax;
	}
	return 0;
}

/// Get parameter of a State object has a minimum and maximum value

char getparameterhasminmax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].hasminmax;
	}
	return 0;
}

/// Get the units of a parameter of a State object

const char *getparameterunits(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].units;
	}
	return 0;
}

/// Get the size of the state of all parameters of a State object

size_t getstatesize(CommonState *cself) {
	return genlib_getstatesize(cself, &getparameter);
}

/// Get the state of all parameters of a State object

short getstate(CommonState *cself, char *state) {
	return genlib_getstate(cself, state, &getparameter);
}

/// set the state of all parameters of a State object

short setstate(CommonState *cself, const char *state) {
	return genlib_setstate(cself, state, &setparameter);
}

/// Allocate and configure a new State object and it's internal CommonState:

void *create(t_param sr, long vs) {
	State *self = new State;
	self->reset(sr, vs);
	ParamInfo *pi;
	self->__commonstate.inputnames = gen_kernel_innames;
	self->__commonstate.outputnames = gen_kernel_outnames;
	self->__commonstate.numins = gen_kernel_numins;
	self->__commonstate.numouts = gen_kernel_numouts;
	self->__commonstate.sr = sr;
	self->__commonstate.vs = vs;
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(4 * sizeof(ParamInfo));
	self->__commonstate.numparams = 4;
	// initialize parameter 0 ("m_ctrl1_wet_20")
	pi = self->__commonstate.params + 0;
	pi->name = "ctrl1_wet";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl1_wet_20;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_damping_18")
	pi = self->__commonstate.params + 1;
	pi->name = "damping";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_damping_18;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_decay_19")
	pi = self->__commonstate.params + 2;
	pi->name = "decay";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_decay_19;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_predelay_17")
	pi = self->__commonstate.params + 3;
	pi->name = "predelay";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_predelay_17;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 100;
	pi->exp = 0;
	pi->units = "";		// no units defined
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // reverb::
