#ifndef _TEST_APP
#define _TEST_APP



#include "ofMain.h"
#include "aubioAnalyzer.h"
#include "sinOscillator.h"

class testApp : public ofSimpleApp{
	
	public:
				
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased();		
		
		void audioReceived		(float * input, int bufferSize, int nChannels); 
		void audioRequested		(float * output, int bufferSize, int nChannels); 
		
		
		float * left;
		float * right;
	
		aubioAnalyzer AA;
		sinOscillator sinOsc;
	
		ofTrueTypeFont dinFont;
	
		bool bListening;
	
		vector <float> pitches;
		vector <float> volumes;
	
	
};

#endif	

