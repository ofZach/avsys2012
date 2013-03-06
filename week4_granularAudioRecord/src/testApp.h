#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "granularManager.h"
#include "audioRecorder.h"
#include "granularSamples.h"



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
		void playAll(vector <int> arr);
		
		
		void audioRequested(float * input, int bufferSize, int nChannels); 
		
		//******this is for the audio received
		
		void audioReceived 	(float * input, int bufferSize, int nChannels); 
	
		//float 	pan;
		int		sampleRate;
		bool 	bNoise;
		float 	volume;

		float 	* lAudio;
		float   * rAudio;
		
		float * left;
		float * right;
		int 	bufferCounter;
		int 	drawCounter;
		
		float * audioRecordingBuffer;
		//int		bufferLength;
		int		maxBufferLength;
		bool	bAreRecording;
		
		//bool	bPlayback;
		int		playbackPos;
		
		//audioRecorder ar;
		audioRecorder AR;
		
		//*******until this part

		float pctUpdate;

		granularSamples gsamples;
			
		granularManager GM[3];
		float * audioData;
		bool	bPlayback;
		int		bufferLength;	
		bool	bDrawing;
		int		timer;
		int oldX;
		int oldY;
		vector <int> lengthArray;
		int BPM;
		float totalTime;
		int position;
		bool playing;
		int times;	
		vector <ofPoint> posOfPlay;
		int posCircleX;
		int posCircleY;
		
		ofTrueTypeFont  helvetica;
		int	counter;
		
		
		
		
		
	
	
};

#endif
	
