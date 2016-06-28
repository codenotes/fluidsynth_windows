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


class SoundButton 
{
public:

fluid_cmd_handler_t* cmd_handler = NULL;
	SoundButton(char * sfont)
	{
		if (!_synth)
		{
			printf("I should be here\n");
			initSynth(sfont);
			
		}
	}

	
	void listSf(int stackLocation)
	{

		fluid_sfont_t* sf=fluid_synth_get_sfont(_synth, stackLocation);
		
		fluid_preset_t* preset = new fluid_preset_t();

		// Reset the iteration
		sf->iteration_start(sf);

		// Go through all the presets within the soundfont
		int more = 1;
		while (more) 
		{
			more = sf->iteration_next(sf, preset); // Will return 0 if no more soundfonts left
			if (more)
			{
				// Get preset name
				char* presetname = preset->get_name(preset);
				int banknum = preset->get_banknum(preset);
				int num = preset->get_num(preset);
				

				printf("name:%s\t\t\tbank:%d\t\t\tnum:%d\n", presetname,banknum,num);

				// Do something with the presetname, bank number and program number
				// Such as add it to some list so that you can refer to it later
			}
		}

	}

	 void initSynth(char *sfont) {
		_settings = new_fluid_settings();
		//_adriver = new_fluid_audio_driver(_settings, _synth);

		fluid_settings_setint(_settings, "synth.audio-groups", 0);
		_synth = new_fluid_synth(_settings);
		int r=fluid_synth_sfload(_synth, sfont,1);// "c:\\temp\\Framus_western.sf2", 1);
		
		
		printf("result is:%d\n", r);
		
		SoundButton::cmd_handler = new_fluid_cmd_handler(_synth);
		_adriver = new_fluid_audio_driver(_settings, _synth);

		listSf(0);
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

	 void testNote(int chan, int key, int vel)
	{
		fluid_synth_noteon(_synth, chan, key, vel);
	}

protected:

	 fluid_settings_t* _settings;
	 fluid_synth_t* _synth=0;
	 fluid_audio_driver_t* _adriver;
};

#include <stdio.h>
using namespace std;
	
int main()
{
	//SoundButton sb("C:\\temp\\littlemartinchords.sf2");
	//SoundButton sb("C:\\temp\\common.sf2");// glover_64.sf2");
	SoundButton sb("C:\\temp\\glover_64.sf2");
	int n;


	//sb.initSynth("C:\\temp\\common.sf2");
	//sb.testNote(0, 0, 100);
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

