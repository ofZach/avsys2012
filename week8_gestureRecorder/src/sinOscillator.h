#ifndef _SIN_OSCILLATOR
#define _SIN_OSCILLATOR


#include "ofMain.h"


class sinOscillator{
	
public:
	
	
	void	setup();
	void	setFrequency(float newFrequency);
	void	setVolume(float newVolume);
	void	addToSoundBuffer(float * buffer, int bufferSize); 
	
	float 	pan;
	int		sampleRate;
	float 	volume;
	float	frequency;

	float	angle;
	float	angleAdder;
	
};

#endif	