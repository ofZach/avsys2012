#include "pointRecorder.h"


//------------------------------------------------------------------
pointRecorder::pointRecorder(){
	maxNumPts = 500;  // try 50, for example....
	startTime = 0;
	lineComplete=false;
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
	myPoint.time		= ofGetElapsedTimef() - startTime; //set the point time to the current time adjusted by the time we started drawing this line. that way all of our times are local to 0, or rather, whatever we later choose the start time to be. this lets us replay the line drawing easily
	mostRecentPoint = pt;
	
	cout << "creating point " << pts.size() << " at time: " << myPoint.time << endl;

	pts.push_back(myPoint);
	if (pts.size() > maxNumPts){
		pts.erase(pts.begin());
	}
}

//------------------------------------------------------------------
void pointRecorder::clear() {
	pts.clear();
}

