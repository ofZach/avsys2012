#ifndef _FM_OSCILLATOR
#define _FM_OSCILLATOR


#include "ofMain.h"
//#include "ofAddons.h"


class fmOscillator{
	
public:
	
	
	void	setup();
	
	void	setCarrierFrequency(float frequency);
	void	setModulatorFrequency(float frequency);
	void	setModulatorIndex(float amount);
	void	setModulationStrength(float strength);
	
	void	setVolume(float newVolume);
	void	addToSoundBuffer(float * buffer, int bufferSize); 
	
	float	carrierFrequency;
	float	modulatorFrequency;
	float   modulatorIndex;
	float	modulatorStrength;
	
	int		sampleRate;
	float 	volume;

	float	angle;
	float	angleAdder;
	
	float	modPhase;
	float   modPhaseAdder;
	
	
};

#endif	