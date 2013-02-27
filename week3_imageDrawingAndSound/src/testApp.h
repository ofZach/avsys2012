#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
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
	
		void audioRequested(float * input, int bufferSize, int nChannels); 
		
        ofImage             img;
		float				verticalPos;
	
	
		sinOscillator		oscillators[30];
	
		int w, h;
	
		bool bDoFade;
		float speed;
	
	
		
		
};

#endif	

