#ifndef _AUDIO_RECORDER
#define _AUDIO_RECORDER

/*
 *  audioRecorder.h
 *  MultiLineWithVoiceThesis2
 *
 *  Created by Eduardo Menendez on 3/11/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofMain.h"

class audioRecorder {
	
	public:
	
	void setup();
	void audioReceived 	(float * input, int bufferSize, int nChannels);
	void audioRequested(float * input, int bufferSize, int nChannels); 
	void update(float * output, int bufferSize, int nChannels);
	
	float 	pan;
	int		sampleRate;
	bool 	bNoise;
	float 	volume;

	float 	* lAudio;
	float   * rAudio;
		
	float * left;
	float * right;
	int 	bufferCounter;
	int 	drawCounter;
		
	float * audioRecordingBuffer;
	int		bufferLength;
	int		maxBufferLength;
	bool	bAreRecording;
		
	bool	bPlayback;
	int		playbackPos;
};







#endif