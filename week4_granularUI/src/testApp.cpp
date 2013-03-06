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

	//sinOsc.setup();
	
	audioData = new float[1024];
	
	ofSetFrameRate(60);
    
    
    gui = new ofxUICanvas();
    gui->addLabel("granular synthesis");
    gui->addSpacer();
    
    gui->addSlider("grainsPerSecond", 0.0, 500.0, &GM.grainsPerSecond);
    gui->addSlider("avg freq", 0.0, 1000.0, &GM.avgFrequency);
    gui->addSlider("avg freq spread", 0, 1000, &GM.avgFrequencySpread);
    gui->addSlider("grain length", 0, 200, &GM.avgGrainLength);
    gui->addSlider("grain length spread", 0, 100, &GM.avgGrainLengthSpread);
    gui->addSlider("avg volume", 0, 0.05, &GM.avgVolume);
    gui->addSlider("avg volume spread", 0, 0.05, &GM.avgVolumeSpread);

    
    gui->loadSettings("GUI/guiSettings.xml");

}


//--------------------------------------------------------------
void testApp::update(){
	
	GM.idle();
}

//---------------------------------------------------`----------
void testApp::draw(){
	
	ofSetColor(0,0,0);
	
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



