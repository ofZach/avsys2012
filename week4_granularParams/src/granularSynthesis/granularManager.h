#ifndef _GRANULAR_MANAGER
#define _GRANULAR_MANAGER


#include "ofMain.h"
#include "granularGrain.h"


class granularManager{
	
public:
	
	
	granularManager();
	void	idle();
	void	addToSoundBuffer(float * buffer, int bufferSize); 
	
	unsigned long long	sampleCount;
	
	float				grainCount;
	
	vector < granularGrain > grains;
	
	// these are params to alter: 
	
	float				grainsPerSecond;
	float				avgFrequency;
	float				avgFrequencySpread;
	float				avgGrainLength;
	float				avgGrainLengthSpread;
	float				avgVolume;
	float				avgVolumeSpread;
	
	
};

#endif	