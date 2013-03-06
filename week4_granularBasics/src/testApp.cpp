#include "testApp.h"
#include "stdio.h"



//--------------------------------------------------------------
void testApp::setup(){	 
	
	ofBackground(255,255,255);	
	
	// 2 output channels, 
	// 0 input channels
	// 44100 samples per second
	// 256 samples per buffer
	// 4 num buffers (latency)
	
	
	ofSoundStreamSetup(2,0,this, 44100, 1024, 4);
    
	audioData = new float[1024];
	
	ofSetFrameRate(60);

}


//--------------------------------------------------------------
void testApp::update(){
	
	GM.idle();
}

//--------------------------------------------------------------
void testApp::draw(){
	
	
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){ 

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

//--------------------------------------------------------------
void testApp::audioRequested(float * output, int bufferSize, int nChannels){	
	
	for (int i = 0; i < bufferSize; i++){
		output[i*nChannels    ] = 0;
		output[i*nChannels + 1] = 0;
	}
	
	GM.addToSoundBuffer(output, bufferSize);
	
	for (int i = 0; i < bufferSize; i++){
		audioData[i] = output[i*2]*0.4f;
	}
	
}



