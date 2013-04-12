#include "fmOscillator.h"



//--------------------------------------------------------------
void fmOscillator::setup(){	 
	
	sampleRate 			= 44100;
	angle 				= 0;
	angleAdder 			= 0.0f;
	volume				= 0.1f;	
	
	setCarrierFrequency(440);
	setModulatorFrequency(200);
	setModulationStrength(1.0);
	
}

//--------------------------------------------------------------
void fmOscillator::setVolume(float newVolume){
	volume = newVolume;
}

//--------------------------------------------------------------
void fmOscillator::setCarrierFrequency(float newFrequency){
	carrierFrequency = newFrequency;
	angleAdder = (newFrequency / (float) sampleRate) * TWO_PI;
}

//--------------------------------------------------------------
void fmOscillator::setModulatorFrequency(float newFrequency){
	modulatorFrequency = newFrequency;
	modPhaseAdder = (newFrequency / (float) sampleRate) * TWO_PI;
}

//--------------------------------------------------------------
void fmOscillator::setModulatorIndex(float newIndex){
	modulatorIndex = newIndex;
}

//--------------------------------------------------------------
void fmOscillator::setModulationStrength(float newStrength){
	modulatorStrength = newStrength;
}


//--------------------------------------------------------------
void fmOscillator::addToSoundBuffer(float * buffer, int bufferSize){

	// sin (n) seems to have trouble when n is very large, so we
	// keep phase in the range of 0-TWO_PI like this:
	
	while (angle > TWO_PI){
		angle -= TWO_PI;
	}
	
	while (modPhase > TWO_PI){
		modPhase -= TWO_PI;
	}
	
	
	float sample		= 0;
	float modSample		= 0;
	float resultSample	= 0;
	float newFreq		= 0;
	float newPhaseAdder = 0;
	
	for (int i = 0; i < bufferSize; i++){
		
		// calculate our new frequency: 
		modPhase += modPhaseAdder;
	
		newFreq	= carrierFrequency * ( 0.5f * sin(modPhase) + 0.5);
		newPhaseAdder = (newFreq / (float) sampleRate) * TWO_PI;
	
		angle		+= (1-modulatorStrength) * angleAdder + (modulatorStrength) * newPhaseAdder;
	
		sample			= sin(angle);
		
		buffer[i*2    ] += sample * volume;
		buffer[i*2 + 1] += sample * volume;
	
	}
	
	
}

