
#include "granularManager.h"


bool canBeRemoved ( granularGrain  &g ) {
	return g.bAmReadyToBeErased;
}


granularManager::granularManager(){

	sampleCount			= 0;
	grainsPerSecond		= 150; 
	grainCount			= 0;
	
	avgFrequency			= 400;
	avgFrequencySpread		= 10;   // will go from 390-410
	avgGrainLength			= 80;	
	avgGrainLengthSpread	= 10;
	avgVolume				= 0.17f;
	avgVolumeSpread			= 0.005f; 

}


void granularManager::idle(){

}

void granularManager::addToSoundBuffer(float * buffer, int bufferSize){
	
	
	float oldGrainCount		= grainCount;
	grainCount				+= grainsPerSecond * (bufferSize/44100.0f);
	
	int diff = (int)grainCount - (int)oldGrainCount;
	
	
	for (int i = 0; i < diff; i++){
		granularGrain grain;
		grain.gsamples = samples;
		grains.push_back(grain);
		
		// calc random freq, volume and length
		float freq		= ofRandom(avgFrequency - avgFrequencySpread, avgFrequency + avgFrequencySpread);
		float volume	= ofRandom(avgVolume - avgVolumeSpread, avgVolume + avgVolumeSpread);
		float length	= ofRandom(avgGrainLength - avgGrainLengthSpread, avgGrainLength + avgGrainLengthSpread);
		
		// check for extreme conditions: 
		if (length < 1) length = 1;
		if (volume < 0) volume = 0;
		if (freq < 1) freq = 1;
		
		grains[grains.size() - 1].calcuteGrainSamples((int)length, sampleCount + (int)ofRandom(0,bufferSize), freq, volume);
	}
	

	grains.erase(std::remove_if(grains.begin(),grains.end(), canBeRemoved), grains.end());
	

	for (int i = 0; i < bufferSize; i++){
		
		for (int j = 0; j < grains.size();  j++){
			float sample = grains[j].getSampleForPosition (sampleCount);
			//if (sample > 0) printf("sample = %f \n", sample);
			buffer[i*2    ] += sample;
			buffer[i*2 + 1] += sample;
		}
		sampleCount++;
		//printf("sampleCount %i \n", (int) sampleCount);
	}
	
}
	