#pragma once

#include "ofMain.h"
#include "oscillator.h"


class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
         void audioOut(float * input, int bufferSize, int nChannels);
    
        ofSoundStream stream;
    
        float * soundBuffer;
    
        oscillator carrierWave;
        oscillator modulatorWave;
        float carrierMinFreq;
        float carrierMaxFreq;
    
		
};
