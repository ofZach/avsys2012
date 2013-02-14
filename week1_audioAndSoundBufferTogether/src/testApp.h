#pragma once

#include "ofMain.h"

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
		
    
    
        // image things:
    
        int width, height;                           // width and height of the image
        unsigned char * pixelBuffer;        // array to store data
        ofTexture tex;                      // texture to draw iteself
    
    
        // sound things:
    
        ofSoundStream soundStream;
        void audioOut(float * input, int bufferSize, int nChannels);
        
        int sampleCount;                    // count our way through the image pixels to put them in the sound buffer
    
    
};
