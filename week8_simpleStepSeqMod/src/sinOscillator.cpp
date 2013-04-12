#include "sinOscillator.h"



//--------------------------------------------------------------
void sinOscillator::setup(){	 
	sampleRate 			= 44100;
	angle 				= 0;
	angleAdder 			= 0.0f;
	volume				= 0.1f;	
	setFrequency (440);
	setVolume(0.1);
}

//--------------------------------------------------------------
void sinOscillator::setVolume(float newVolume){
	volume = newVolume;
}

//--------------------------------------------------------------
void sinOscillator::setFrequency(float newFrequency){
	frequency = newFrequency;
	angleAdder = (newFrequency / (float) sampleRate) * TWO_PI;
}

//--------------------------------------------------------------
void sinOscillator::addToSoundBuffer(float * buffer, int bufferSize){

	// sin (n) seems to have trouble when n is very large, so we
	// keep angle in the range of 0-TWO_PI like this:
	
	while (angle > TWO_PI){
		angle -= TWO_PI;
	}
	
	float sample = 0;
	
	for (int i = 0; i < bufferSize; i++){
		angle += angleAdder;
		sample = round(sin(angle)); // square wave
		buffer[i*2    ] += sample * volume;
		buffer[i*2 + 1] += sample * volume;
	}
	
	
}

