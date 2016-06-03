#if HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "fluidsynth_priv.h"


#include "fluidsynth.h"

#if defined(WIN32) && !defined(MINGW32)
#include "config_win32.h"
#endif

#ifdef HAVE_SIGNAL_H
#include "signal.h"
#endif

#include "fluid_lash.h"

#ifndef WITH_MIDI
#define WITH_MIDI 1
#endif

//#include <iostream>

#if 0
class SoundButton
{
public:

	SoundButton() : SomeButton() {
		if (!_synth) {
			initSynth();
		}
	}

	static void initSynth() {
		_settings = new_fluid_settings();
		_synth = new_fluid_synth(_settings);
		_adriver = new_fluid_audio_driver(_settings, _synth);
	}

	/* ... */

	virtual int handleMouseDown(int x, int y)
	{
		/* Play a note on key 60 with velocity 100 on MIDI channel 0 */
		fluid_synth_noteon(_synth, 0, 60, 100);
	}

	virtual int handleMouseUp(int x, int y) {
		/* Release the note on key 60 */
		fluid_synth_noteoff(_synth, 0, 60);
	}

protected:

	static fluid_settings_t* _settings;
	static fluid_synth_t* _synth;
	static fluid_audio_driver_t* _adriver;
};
#endif
