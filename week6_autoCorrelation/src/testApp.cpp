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
	
	ofSoundStreamSetup(0,2,this, 44100, 512, 4);	
	
	left				= new float[512];
	right				= new float[512];
	autoCorrelation		= new float[512];
		
	ofSetVerticalSync(true);
	
	bufferCounter = 0;
	drawCounter = 0;
	
	bNormalize =true;

}

//--------------------------------------------------------------
void testApp::draw(){
	
	
	
	// draw the left:
	ofSetHexColor(0x333333);
	ofRect(100,100,512,200);
	ofSetHexColor(0xFFFFFF);
	for (int i = 0; i < 512; i++){
		ofLine(100+i,200,100+i,200+left[i]*100.0f);
	}
	
	// draw the right:
	ofSetHexColor(0x333333);
	ofRect(100,500,512,200);
	ofSetHexColor(0xFF0000);
	for (int i = 0; i < 512; i++){
		ofLine(100+i,600,100+i,600-autoCorrelation[i]*100.0f);
	}
	
    

	ofSetHexColor(0x333333);
	drawCounter++;
	char reportString[255];
	sprintf(reportString, "buffers received: %i\ndraw routines called: %i\n", bufferCounter,drawCounter);
	ofDrawBitmapString(reportString,80,380);
}


//--------------------------------------------------------------
void testApp::doAutoCorrelation(){
    
    float sum;
	float autoCorrelationResults[512];
	
    for (int i = 0; i < 512; i++) {
        
        
        // acyclic
        sum = 0;
        for (int j = 0; j < 512-i; j++) {
            sum += left[j]*left[j+i];
        }
        autoCorrelationResults[i]=sum;
        
        /*
        // cyclic
        sum = 0;
        for (int j = 0; j < 512; j++) {
            sum += left[j]*left[(j+i) % 512];
        }
        autoCorrelationResults[i]=sum;
        */
        
    }
	
	
	if (bNormalize == true){
		float maxValue = 0;
		
		 for (int i=0;i<512;i++) {
			 if (fabs(autoCorrelationResults[i]) > maxValue){
				 maxValue = fabs(autoCorrelationResults[i]);
			 }
		 }
		
		if (maxValue > 0){
			for (int i=0;i<512;i++) {
				autoCorrelationResults[i] /= maxValue;
			}
		}
	}
	
	memcpy(autoCorrelation, autoCorrelationResults, 512 * sizeof(float));
	
}




//--------------------------------------------------------------
void testApp::audioReceived 	(float * input, int bufferSize, int nChannels){	
	// samples are "interleaved"
	for (int i = 0; i < bufferSize; i++){
		left[i] = input[i*2];
		right[i] = input[i*2+1];
	}
	bufferCounter++;	
	doAutoCorrelation();
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	if (key == 'n'){
		bNormalize = !bNormalize;
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


