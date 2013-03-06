#ifndef _GRANULAR_GRAIN
#define _GRANULAR_GRAIN

#include "ofMain.h"



class granularGrain{
	
	public:
	
		void calcuteGrainSamples(int millis, unsigned long long startSample, float freq, float amplitude);
		
		bool					bAmReadyToBeErased;
		unsigned long long		firstSample;				// the time of the first sample, should be not an int
		int						lengthInSamples;					
		float					lengthInMillis;
		
		
		float getSampleForPosition(unsigned long long samplePosition);
	
		vector <float>		samples;  // this is fairly inneficient.  better is preallocated arrays.
	
	
};

#endif	