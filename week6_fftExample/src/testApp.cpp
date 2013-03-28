#include "testApp.h"
		
//--------------------------------------------------------------
void testApp::setup(){	 
	
	// 0 output channels, 
	// 2 input channels
	// 44100 samples per second
	// BUFFER_SIZE samples per buffer
	// 4 num buffers (latency)
	
	ofSoundStreamSetup(0,2,this, 44100, BUFFER_SIZE, 4);	
	
	//left = new float[BUFFER_SIZE];
	//right = new float[BUFFER_SIZE];

	ofSetHexColor(0x666666);
	
	
	FFTanalyzer.setup(44100, BUFFER_SIZE/2, 2);
	
	FFTanalyzer.peakHoldTime = 15; // hold longer
	FFTanalyzer.peakDecayRate = 0.95f; // decay slower
	FFTanalyzer.linearEQIntercept = 0.9f; // reduced gain at lowest frequency
	FFTanalyzer.linearEQSlope = 0.01f; // increasing gain at higher frequencies
	
	ofSetVerticalSync(true);
}


//--------------------------------------------------------------
void testApp::update(){
		ofBackground(80,80,20);
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
	float avg_power = 0.0f;	
		
	/* do the FFT	*/
	myfft.powerSpectrum(0,(int)BUFFER_SIZE/2, left,BUFFER_SIZE,&magnitude[0],&phase[0],&power[0],&avg_power);
	 
	for (int i = 0; i < (int)(BUFFER_SIZE/2); i++){
		freq[i] = magnitude[i];
	}
	
	FFTanalyzer.calculate(freq);
	
	ofSetHexColor(0xffffff);
	for (int i = 0; i < (int)(BUFFER_SIZE/2 - 1); i++){
		//ofRect(200+(i*4),600,4,-freq[i]*10.0f);
	}
	
	for (int i = 0; i < FFTanalyzer.nAverages; i++){
		ofRect(200+(i*20),600,20,-FFTanalyzer.averages[i] * 6);
	}
	
	ofSetHexColor(0xff0000);
	for (int i = 0; i < FFTanalyzer.nAverages; i++){
		ofRect(200+(i*20),600-FFTanalyzer.peaks[i] * 6,20,-4);
	}
		 
}


//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
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

//--------------------------------------------------------------
void testApp::audioReceived 	(float * input, int bufferSize, int nChannels){	
	// samples are "interleaved"
	for (int i = 0; i < bufferSize; i++){
		left[i] = input[i*2];
		right[i] = input[i*2+1];
	}
}

