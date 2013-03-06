
#include "granularManager.h"


bool canBeRemoved ( granularGrain  &g ) {
	return g.bAmReadyToBeErased;
}


granularManager::granularManager(){

	sampleCount			= 0;
	grainsPerSecond		= 3;
	grainCount			= 0;
}


void granularManager::idle(){

    
    
    grainsPerSecond = ofMap(sin(ofGetElapsedTimef()), -1, 1, 3, 300);
}

void granularManager::addToSoundBuffer(float * buffer, int bufferSize){
	
	
    
    
    
	float oldGrainCount		= grainCount;
	grainCount				+= grainsPerSecond * (bufferSize/44100.0f);
    
    
    
	
	int diff = (int)grainCount - (int)oldGrainCount;
	
	
	for (int i = 0; i < diff; i++){
		granularGrain grain;
		grains.push_back(grain);
		grains[grains.size() - 1].calcuteGrainSamples(60, sampleCount + (int)ofRandom(0,bufferSize), ofGetMouseX() + ofRandom(-ofGetMouseY(),ofGetMouseY()), 0.06f);
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
	