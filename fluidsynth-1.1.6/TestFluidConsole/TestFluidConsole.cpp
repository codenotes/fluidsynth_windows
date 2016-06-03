// TestFluidConsole.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#if HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "fluidsynth_priv.h"

#if !defined(WIN32) && !defined(MACINTOSH)
#define _GNU_SOURCE
#endif

#if defined(HAVE_GETOPT_H)
#include <getopt.h>
#endif

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

fluid_cmd_handler_t* cmd_handler = NULL;

class SoundButton 
{
public:

	SoundButton(char * sfont)
	{
		if (!_synth) {
			initSynth(sfont);
			
		}
	}

	 void initSynth(char *sfont) {
		_settings = new_fluid_settings();
		//_adriver = new_fluid_audio_driver(_settings, _synth);

		fluid_settings_setint(_settings, "synth.audio-groups", 0);
		_synth = new_fluid_synth(_settings);
		fluid_synth_sfload(_synth, sfont,1);// "c:\\temp\\Framus_western.sf2", 1);
		
		cmd_handler = new_fluid_cmd_handler(_synth);
		

		_adriver = new_fluid_audio_driver(_settings, _synth);
	}

	/* ... */

	 int handleMouseDown(int x, int y) {
		/* Play a note on key 60 with velocity 100 on MIDI channel 0 */
		fluid_synth_noteon(_synth, 0, 60, 100);
	}

	 int handleMouseUp(int x, int y) {
		/* Release the note on key 60 */
		fluid_synth_noteoff(_synth, 0, 60);
	}

	 void testNote(int chan=0, int key=60, int vel=100)
	{
		fluid_synth_noteon(_synth, chan, key, vel);
	}

protected:

	 fluid_settings_t* _settings;
	 fluid_synth_t* _synth;
	 fluid_audio_driver_t* _adriver;
};

#include <stdio.h>
using namespace std;

int main()
{
	//SoundButton sb("C:\\temp\\littlemartinchords.sf2");
	SoundButton sb("C:\\temp\\common.sf2");
	int n;

	while (1)
	{
		printf("enter note: ");
		n = fgetc(stdin);
		sb.testNote(0,  n, 100);
	}
	
	return 0;
	printf("done\n");
    return 0;
}

