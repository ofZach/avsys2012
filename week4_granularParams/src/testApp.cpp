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

}


//--------------------------------------------------------------
void testApp::update(){
	
	GM.idle();
}

//---------------------------------------------------`----------
void testApp::draw(){
	
	ofSetColor(0,0,0);
	
	ofDrawBitmapString("avg freq (a/z) : " + ofToString(GM.avgFrequency, 3), 30, 30);
	ofDrawBitmapString("avg freqSpread (s/x) : " + ofToString(GM.avgFrequencySpread,3), 30, 45);
	ofDrawBitmapString("freqencies between : " + ofToString(GM.avgFrequency - GM.avgFrequencySpread, 3) + " - " + ofToString(GM.avgFrequency + GM.avgFrequencySpread, 3), 30, 60);

	ofDrawBitmapString("avg length (d/c) : " + ofToString(GM.avgGrainLength, 3), 30, 90);
	ofDrawBitmapString("avg length spread (f/v) : " + ofToString(GM.avgGrainLengthSpread,3), 30, 105);
	ofDrawBitmapString("length between : " + ofToString(GM.avgGrainLength - GM.avgGrainLengthSpread, 3) + " - " + ofToString(GM.avgGrainLength + GM.avgGrainLengthSpread, 3), 30, 120);
	
	ofDrawBitmapString("avg volume (g/b) : " + ofToString(GM.avgVolume, 3), 30, 150);
	ofDrawBitmapString("avg volume spread (h/n) : " + ofToString(GM.avgVolumeSpread,3), 30, 165);
	ofDrawBitmapString("volumes between : " + ofToString(GM.avgVolume - GM.avgVolumeSpread, 3) + " - " + ofToString(GM.avgVolume + GM.avgVolumeSpread, 3), 30, 180);
	
	ofDrawBitmapString("grains per second  (j/m) : " + ofToString((int)(GM.grainsPerSecond)), 30, 210);
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){ 

	switch (key){
			
		case 'a':
			GM.avgFrequency += 10;
			break;
		case 'z':
			GM.avgFrequency -= 10;
			if (GM.avgFrequency < 30) GM.avgFrequency = 30;
			break;
		case 's':
			GM.avgFrequencySpread += 10;
			break;
		case 'x':
			GM.avgFrequencySpread -= 10;
			if (GM.avgFrequencySpread < 0) GM.avgFrequencySpread = 0;
			break;	
			
		case 'd':
			GM.avgGrainLength += 1;
			break;
		case 'c':
			GM.avgGrainLength -= 1;
			if (GM.avgGrainLength < 0) GM.avgFrequency = 0;
			break;
		case 'f':
			GM.avgGrainLengthSpread += 1;
			break;
		case 'v':
			GM.avgGrainLengthSpread -= 1;
			if (GM.avgGrainLengthSpread < 0) GM.avgGrainLengthSpread = 0;
			break;
			
		case 'g':
			GM.avgVolume += 0.01f;
			break;
		case 'b':
			GM.avgVolume -= 0.01f;
			if (GM.avgVolume < 0) GM.avgVolume = 0;
			break;
		case 'h':
			GM.avgVolumeSpread += 0.001f;
			break;
		case 'n':
			GM.avgVolumeSpread -= 0.001f;
			if (GM.avgVolumeSpread < 0) GM.avgVolumeSpread = 0;
			break;
			
		case 'j':
			GM.grainsPerSecond += 1;
			break;
		case 'm':
			GM.grainsPerSecond -= 1;
			if (GM.grainsPerSecond < 0) GM.grainsPerSecond = 0;
			break;
			
			
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



