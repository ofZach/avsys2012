#include "pointRecorder.h"


//------------------------------------------------------------------
pointRecorder::pointRecorder(){
	maxNumPts = 500;  // try 50, for example....
	startTime = 0;
	lineComplete=false;
	
	tone.setup();
	tone.setModulationStrength(1.0);
	tone.setModulatorIndex(300);
	tone.carrierFrequency=0;
	tone.setVolume(1.0);
	mostRecentPointIndex=0;
	oldPointDist=0;
}
//------------------------------------------------------------------
void pointRecorder::addToSoundBuffer(float * buffer, int bufferSize) {
	tone.setCarrierFrequency( tone.carrierFrequency + (ofGetHeight()-mostRecentPoint.y - tone.carrierFrequency)/8 ); //xeno to the new freq so no clipping
	tone.setModulatorFrequency( tone.carrierFrequency/2 ); // set the mod to half the carrier
	
	if(mostRecentPointIndex!=0) //if we're not on the first point of our gesture
		tone.setModulationStrength(oldPointDist/10); // set modulation strength based on how far we are from the last point
	else
		tone.setModulationStrength(0); //otherwise set modulation strength back to 0
	
	tone.addToSoundBuffer(buffer, bufferSize); //add the values to our buffer
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
	//ofSetColor(255, 255, 255);
	//ofNoFill();
	//ofBeginShape();
	for (int i = 0; i < pts.size(); i++){
		
		if(ofGetElapsedTimef() > pts[i].time+newStartTime){ //if we have gotten to this point in playback
			ofVertex(pts[i].pos.x, pts[i].pos.y); //draw it on the line
			oldPointDist = fabs(pts[i].pos.y - mostRecentPoint.y);
			mostRecentPoint = pts[i].pos; // set the most recent point variable so we can access it outside
			mostRecentPointIndex = i;
		}
		else
			break;
	}
	//ofEndShape(false);
	
	int yVal = (float)startY/ofGetHeight() * 255;
	ofSetColor(yVal, (255-yVal)-yVal, 255-yVal, 150); // some random way I decided to make one var create a spectrum of colors
	ofSetRectMode(OF_RECTMODE_CENTER);
	if(pts.size()>0)
		ofRect(ofGetWidth()/2,startY,ofGetWidth(), (pts[mostRecentPointIndex].pos.y - startY)*2);
}

//------------------------------------------------------------------
void pointRecorder::addPoint(ofPoint pt) {
	
	
	// on the first point, grab the start time
	if (pts.size() == 0){
		startTime = ofGetElapsedTimef();
		newStartTime = startTime;
		startY = pt.y;
		
		tone.setModulatorIndex(startY*startY); // use the startY to set the modulator index. use the value squared to get a greater range
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

