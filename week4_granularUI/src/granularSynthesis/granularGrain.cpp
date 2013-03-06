#include "granularGrain.h"




void granularGrain::calcuteGrainSamples(int millis, unsigned long long startSample, float freq, float amplitude){

	firstSample				= startSample;
	lengthInMillis			= millis;
	float lengthInSeconds	= millis / 1000.0f;
	lengthInSamples			= (int)(44100.0f * lengthInSeconds);
	float phase				= ofRandom(0,TWO_PI);			// give a random phase
	
	
	float sinProfileAngle		= 0;
	float sinProfileAdder		= PI / (float)lengthInSamples;
	float carrierAngle			= phase;
	float carrierAngleAdder		= (freq / (float) 44100.0f) * TWO_PI;
	
	bAmReadyToBeErased = false;
	
	
	for (int i = 0; i < lengthInSamples; i++){
		
		float sample = sin(carrierAngle) * amplitude * (sin(sinProfileAngle));
		samples.push_back(sample);
		carrierAngle	+= carrierAngleAdder;
		sinProfileAngle += sinProfileAdder;
	}
	
	//printf("made a grain with %i samples starting at %i\n", lengthInSamples, (int)startSample);

}


float granularGrain::getSampleForPosition(unsigned long long samplePosition){

		
	
	if (samplePosition < firstSample) return 0;
	
	float returnVal = 0;
	int position = (int)(samplePosition - firstSample);
	
	if (position < lengthInSamples && position >= 0){
		returnVal = samples[position];
	} else {
		if (samplePosition > (firstSample + lengthInSamples)){
			bAmReadyToBeErased = true;
		}
	}	
	
	return returnVal;
	
}
