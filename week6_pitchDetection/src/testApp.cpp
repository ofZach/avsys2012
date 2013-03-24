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
	ofSoundStreamSetup(0, 2, this, 44100, 256, 4);	
	left = new float[256];	
	right = new float[256];
	
	AA.setup();
	
	dinFont.loadFont("DIN.otf", 50);
		
	
}

//--------------------------------------------------------------
void testApp::update(){
		

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
	
	ofSetHexColor(0x000000);
	
	dinFont.drawString( "pitch is : " + ofToString((int)AA.pitch), 50,300);
    dinFont.drawString( "amplitude is : " + ofToString(AA.amplitude,3), 50,375);
	dinFont.drawString( "confidence is : " + ofToString(AA.confidence), 50,450);
	
}


//--------------------------------------------------------------
void testApp::audioReceived (float * input, int bufferSize, int nChannels){	
	
	
	// samples are "interleaved"
	for (int i = 0; i < bufferSize; i++){
		left[i] = input[i*2];		
		right[i] = input[i*2+1];
	}

	AA.processAudio(left, bufferSize);
}



//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
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


