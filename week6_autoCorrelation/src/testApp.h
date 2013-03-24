#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"


class testApp : public ofSimpleApp{
	
	public:
		
		void setup();
		void update(){};
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased();
		
		void audioReceived 	(float * input, int bufferSize, int nChannels); 
	
		float * left;
		float * right;
	
		float * autoCorrelation;
	
		bool bNormalize;
	
		void doAutoCorrelation();
	
	
		int 	bufferCounter;
		int 	drawCounter;
};

#endif	

