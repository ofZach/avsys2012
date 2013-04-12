#ifndef POINT_RECORDER_H
#define POINT_RECORDER_H

#include "ofMain.h"
#include "fmOscillator.h"


// ---------------------------
// this is like an old school class, a "struct"
// it doesn't have functions, just data...
// it's C style -
//
// typedef 
// http://bytes.com/forum/thread620088.html
// http://en.wikipedia.org/wiki/Typedef
// struct
// http://www.itee.uq.edu.au/~comp2303/Leslie_C_ref/C/SYNTAX/struct.html
// http://en.wikipedia.org/wiki/C%2B%2B_structures_and_classes


typedef struct {
	ofPoint		pos;
	float		time; // from the start, what time does this pt occur at	
} timePt;



class pointRecorder {

	public:
	
        pointRecorder();
	
		void addPoint(ofPoint pt);
		void clear();
		void draw();
	
	//sound stuff - - -- 
		void addToSoundBuffer(float * buffer, int bufferSize); 
		fmOscillator		tone;
		
		float				startTime;
		int					maxNumPts;
		vector <timePt>		pts;
		
	
		float				newStartTime; //for playback
		float				totalDuration; // the total life of the line
		bool				lineComplete; // for knowing that a line has finished drawing
		ofPoint				mostRecentPoint; // the most recent point drawn during playback
	
		float				oldPointDist; //the distance to the previous y point, used for modulator strength
	
		int					mostRecentPointIndex; // the index of the most recent Point in pts (useful for fading the volume at the beginning and end of a gesture)

		int					startY; // the starting point of the rect, used to calculate the modulator frequency
};

#endif // POINT_RECORDER_H
