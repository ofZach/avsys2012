#include "testApp.h"
#include "ofMain.h"
#include "stdio.h"


//--------------------------------------------------------------

void testApp::setup(){	 
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	ofBackground(0,0,0);
	//fondo.loadImage("images/wall_10.jpg");
	
	
	helvetica.loadFont("NewMedia Fett.ttf",24);
	counter = 0;
	
	
	
	
	
	// 2 output channels, 
	// 0 input channels
	// 44100 samples per second
	// 512 samples per buffer
	// 4 num buffers (latency)
	
	//volume				= 0.1f;
	//pan					= 0.5f;
	//bNoise 				= false;
	
	ofSoundStreamSetup(2,2,this, 44100, 512, 4);
	
	left = new float[512];
	right = new float[512];

	//maxBufferLength = 44100 * 10;
	//audioRecordingBuffer = new float[maxBufferLength];
	//bufferLength = 0;
	//bAreRecording = false;
	
	//bPlayback = false;
	//playbackPos = 0;
	//bAreRecording = 0;
	
	//audioData = new float[512];
	//bufferLength = 0;
	//bPlayback = false;
	
	gsamples.samples = AR.audioRecordingBuffer;
	gsamples.nSamples = 0;
	gsamples.pct = (float)mouseX / (float)ofGetWidth();
	GM[0].samples = &gsamples;		
			
	
	pctUpdate = 0;
	
	AR.setup();
	
}

//--------------------------------------------------------------
void testApp::update(){
	
	
		
	
	if(AR.bPlayback){
					
			gsamples.samples = AR.audioRecordingBuffer;
			gsamples.nSamples = AR.bufferLength;
			gsamples.pct = pctUpdate;  
        gsamples.pct =  ofMap(mouseX, 0, ofGetWidth(), 0, 1);
			gsamples.pctOffset = (float)mouseY / (float)ofGetHeight();
			
			GM[0].samples = &gsamples;
						
		
	} else {
		
		gsamples.samples = AR.audioRecordingBuffer;
		gsamples.nSamples = 0;
		gsamples.pct = (float)mouseX / (float)ofGetWidth();
		
		GM[0].samples = &gsamples;

	
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(255,255,255);
	//fondo.draw(0,0);
		
	
	
	char tempString[255];
	sprintf(tempString,"%i", (int)counter);
	helvetica.drawString(tempString, 50,55);
	
	
	
	
	
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
 if (key == 'r'){
	AR.bAreRecording = true;
	AR.bPlayback = false;
 }
 if (key == 'p'){
	AR.bAreRecording = false;
	AR.bPlayback = true;
 }

		
	
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
		 
	
	
	//------------- this section is for the AR object
	
	//AR.bAreRecording = true;
	//AR.bPlayback = false;

		
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
	
		
	//------------- this section is for the AR object
	
	//AR.setup();
	
	
	
}
//--------------------------------------------------------------
void testApp::playAll(vector <int> arr){
	playing=true;
}
//--------------------------------------------------------------
void testApp::mouseReleased(){
		
	//------------- this section is for the AR object
	
}

//--------------------------------------------------------------
void testApp::audioReceived (float * input, int bufferSize, int nChannels){
	
	if (AR.bAreRecording == true){
		AR.audioReceived(input,bufferSize,nChannels);
	}
		
}

//--------------------------------------------------------------
void testApp::audioRequested(float * output, int bufferSize, int nChannels){	
	
	for (int i = 0; i < bufferSize; i++){
			output[i*nChannels    ] = 0;
			output[i*nChannels + 1] = 0;
		}
	
	if (AR.bPlayback == true && bufferSize>0)
	{
		//AR.audioRequested(output,bufferSize,nChannels);
			
		}


	if (!AR.bAreRecording){
	GM[0].addToSoundBuffer(output, bufferSize);
	}
	
	
	
}
	
