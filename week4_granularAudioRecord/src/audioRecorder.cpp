/*
 *  audioRecorder.cpp
 *  MultiLineWithVoiceThesis2
 *
 *  Created by Eduardo Menendez on 3/11/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "audioRecorder.h"

//--------------------------------------------------------------
void audioRecorder::setup(){
	
	// 2 output channels, 
	// 0 input channels
	// 44100 samples per second
	// 256 samples per buffer
	// 4 num buffers (latency)
	volume				= 0.5f;
	pan					= 0.5f;
	
	
	
	left = new float[512];
	right = new float[512];

	maxBufferLength = 44100 * 10;
	audioRecordingBuffer = new float[maxBufferLength];
	bufferLength = 0;
	bAreRecording = false;
	
	bPlayback = false;
	playbackPos = 0;

}


//--------------------------------------------------------------
void audioRecorder::update(float * output, int bufferSize, int nChannels)
{
	audioRequested(output,bufferSize,nChannels);
}


//--------------------------------------------------------------



void audioRecorder::audioReceived 	(float * input, int bufferSize, int nChannels){	

		
	if (bAreRecording == true && (bufferLength < maxBufferLength-bufferSize)){
		
		
		for (int i = 0; i < bufferSize; i++){
			
			left[i] = input[i*2];
			right[i] = input[i*2+1];
			audioRecordingBuffer[bufferLength + i] = left[i];
			

		}
		bufferLength += bufferSize;
		//printf("adding to %i \n", bufferLength);
	}
	
}
//--------------------------------------------------------------
void audioRecorder::audioRequested(float * output, int bufferSize, int nChannels){	
	
	float leftScale = 1 - pan;
	float rightScale = pan;
	
	if (bPlayback == true && bufferSize>0)
	{
		//printf("here in playbck %i \n", playbackPos);
	
		for (int i = 0; i < bufferSize; i++){
			output[i*nChannels    ] += audioRecordingBuffer[playbackPos] * volume * leftScale;
			output[i*nChannels + 1] += audioRecordingBuffer[playbackPos] * volume * rightScale;
			playbackPos++;
			playbackPos %= bufferLength;
		}
	
	
		
	}
	//	cout<<pan<<"\n";
	
}
