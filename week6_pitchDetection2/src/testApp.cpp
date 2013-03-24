#include "testApp.h"
#include "stdio.h"

//--------------------------------------------------------------
void testApp::setup(){	 
	
	ofBackground(255,255,255);	
	
	// 0 output channels, 
	// 2 input channels
	// 44100 samples per second
	// 256 samples per buffer
	// 4 num buffers (latency)
	
	//setup of sound input
	ofSoundStreamSetup(2, 2, this, 44100, 256, 4);	
	left = new float[256];	
	right = new float[256];
	
	AA.setup();
	sinOsc.setup();
	
	dinFont.loadFont("DIN.otf", 50);
	
	bListening = true;
		
	ofSetFrameRate(60);
}

//--------------------------------------------------------------
void testApp::update(){
	
	if (bListening){
		pitches.push_back(AA.pitch);
		volumes.push_back(AA.amplitude);
		
		printf("reacording frame %i \n", pitches.size());
	} else {
		if (pitches.size() > 0){
			int pos = ofGetFrameNum() % pitches.size();
			
			printf("playing frame %i \n", pos);
			
			sinOsc.setFrequency(pitches[pos]);
			sinOsc.setVolume(volumes[pos]);
		}
	}
	
}


//--------------------------------------------------------------
void testApp::draw(){
	
	
	// draw the left:
	ofSetHexColor(0x333333);
	ofRect(0,0,256,200);
	ofSetHexColor(0xFFFFFF);
	for (int i = 0; i < 256; i++){
		ofLine(i,100,i,100+left[i]*200);
	}
	
	
	if (bListening)  ofSetHexColor(0xff0000);
	else  ofSetHexColor(0x000000);
	
	dinFont.drawString( "pitch is : " + ofToString((int)AA.pitch) + "\namplitude is : " + ofToString(AA.amplitude,3), 50,300);
	
	if (bListening)  ofSetHexColor(0x000000);
	else  ofSetHexColor(0xff0000);
	
	dinFont.drawString( "oscillator freq : " + ofToString((int)sinOsc.frequency) + "\noscillator amplitude is : " + ofToString(sinOsc.volume,3), 50,450);
	
	ofSetHexColor(0x999999);
	
	dinFont.drawString( "press space to toggle", 50,650);
	
}


//--------------------------------------------------------------
void testApp::audioReceived (float * input, int bufferSize, int nChannels){	
	
	
	// samples are "interleaved"
	for (int i = 0; i < bufferSize; i++){
		left[i] = input[i*2];		
		right[i] = input[i*2+1];
	}

	
	if (bListening){
		AA.processAudio(left, bufferSize);
	}
}


//--------------------------------------------------------------
void testApp::audioRequested (float * output, int bufferSize, int nChannels){
	
	for (int i = 0; i < bufferSize; i++){
		output[i*2] = 0;		
		output[i*2+1] = 0;
	}
	
	if (!bListening){
		sinOsc.addToSoundBuffer(output, bufferSize);
	}
}




//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	if (key == ' '){
		bListening = !bListening;
	
		if (bListening == true){
			pitches.clear();
			volumes.clear();
		}
	}
	
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	
}


