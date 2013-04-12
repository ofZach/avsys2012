#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(0, 0, 0);
	
	ofSoundStreamSetup(2,0,this, 44100, 512, 4);
	
	ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	for(int i=0;i<gestures.size();i++){
		
		gestures[i].draw(); // draw the gesture
		
		//draw information about the gesture //
		string report = "gesture "+ofToString(i)+": nPts = " + ofToString(gestures[i].pts.size(), 0) + "\t total time = " + ofToString(gestures[i].totalDuration, 3);
		ofDrawBitmapString(report, 10, 14+i*14);
		
		if(gestures[i].lineComplete) // if the line is finished being drawn
		{
			float waitTime = 0; // how much time the gesture will wait after it's last point before resetting
			
			if(gestures[i].newStartTime + gestures[i].totalDuration + waitTime < ofGetElapsedTimef()) // check to see if it's finished it's loop, if it has, reset it
				gestures[i].newStartTime = ofGetElapsedTimef();
		}
		
	}
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	gestures.clear(); // press any key to clear
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	gestures[gestures.size()-1].addPoint(ofPoint(x,y));
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
	gestures.push_back(pointRecorder());
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	gestures[gestures.size()-1].addPoint(ofPoint(x,y)); //add one last point so that we can hold down at the end of the line and have that recorded
	gestures[gestures.size()-1].lineComplete = true; // set the line to finished
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

void testApp::audioRequested(float * output, int bufferSize, int nChannels){	
	
	for (int i = 0; i < bufferSize; i++){
		output[i*nChannels    ] = 0;
		output[i*nChannels + 1] = 0;
	}
	
	if(gestures.size()>0){
		for(int i=0;i<gestures.size();i++)
			gestures[i].addToSoundBuffer(output, bufferSize);
		
		for (int i = 0; i < bufferSize; i++){ // avgerage all the inputs so the sound never goes over 1.0
			output[i*nChannels    ] /= gestures.size();
			output[i*nChannels + 1] /= gestures.size();
		}
	}
}

