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
	float				grainsPerSecond;
	float				grainCount;
	
	vector < granularGrain > grains;
	
};

#endif	