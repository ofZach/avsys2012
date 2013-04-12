#include "pointRecorder.h"


//------------------------------------------------------------------
pointRecorder::pointRecorder(){
	maxNumPts = 500;  // try 50, for example....
	startTime = 0;
	lineComplete=false;
	
	tone.setup();
	tone.setModulationStrength(1.0);
	tone.setModulatorIndex(300);
	tone.setVolume(1.0);
}
//------------------------------------------------------------------
void pointRecorder::addToSoundBuffer(float * buffer, int bufferSize) {
	
	//get the information about what frequency to set based on the most recent point drawn in the gesture
	float targetCarrierFrequency = mostRecentPoint.x;
	float targetModulatorFrequency = ofGetHeight() - mostRecentPoint.y; // invert the mod freq so that high notes are at the top of the screen
	
	tone.setCarrierFrequency(	tone.carrierFrequency	+ ( targetCarrierFrequency		- tone.carrierFrequency		)/8 ); //xeno to the new freq so no clipping
	tone.setModulatorFrequency( tone.modulatorFrequency + ( targetModulatorFrequency	- tone.modulatorFrequency	)/8 ); 
	
	tone.addToSoundBuffer(buffer, bufferSize); //add the tone to the sound buffer
}

//------------------------------------------------------------------
void pointRecorder::draw() {
	
	ofSetColor(100,100,100);
	// get the time of the last point:
	totalDuration = 0;
	if (pts.size() > 0){
		totalDuration = pts[pts.size() - 1].time;
	}
	
	
	
	//---------------------------
	// (b) draw the line: 
	ofSetColor(255, 255, 255);
	ofNoFill();
	ofBeginShape();
	for (int i = 0; i < pts.size(); i++){
		
		if(ofGetElapsedTimef() > pts[i].time+newStartTime){ //if we have gotten to this point in playback
			ofVertex(pts[i].pos.x, pts[i].pos.y); //draw it on the line
			mostRecentPoint = pts[i].pos; // set the most recent point variable so we can access it outside
			mostRecentPointIndex = i;
		}
		else
			break;
	}
	ofEndShape(false);
	
}

//------------------------------------------------------------------
void pointRecorder::addPoint(ofPoint pt) {
	
	
	// on the first point, grab the start time
	if (pts.size() == 0){
		startTime = ofGetElapsedTimef();
		newStartTime = startTime;
	} 
	
	
	// combine the position and the time here: 
	timePt	myPoint;
	myPoint.pos			= pt;
	myPoint.time		= ofGetElapsedTimef() - startTime;
	mostRecentPoint = pt;
	
	pts.push_back(myPoint);
	if (pts.size() > maxNumPts){
		pts.erase(pts.begin());
	}
}

//------------------------------------------------------------------
void pointRecorder::clear() {
	pts.clear();
}

