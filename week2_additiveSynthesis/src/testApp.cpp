#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    stream.setup(this, 2, 0, 44100, 512, 4);
    
    totalSoundBuffer = new float[512];
    
    for (int i = 0; i < 3; i++){
        sinWaves[i].setup(44100);
        sinWaves[i].setFrequency( ofRandom(400,1000));
        sinWaves[i].setVolume(0.1);
        
        soundBuffers[i] = new float[512];
    }
    
    
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    
    
    // sinWave.setFrequency( max(1,mouseX) );  // don't want to give a negative frequency...

}

//--------------------------------------------------------------
void testApp::draw(){

    
    for (int i = 0; i < 3; i++){
    
        ofFill();
        ofSetColor(255);
        ofRect(0,0 + i * 300,512, 200);
        
        ofNoFill();
        ofSetColor(0);
        ofBeginShape();
        for (int j = 0; j < 512; j++){
            ofVertex(j, i * 300 + 100 + 100 * soundBuffers[i][j]);
        }
        ofEndShape();

    }
    

    
    ofFill();
    ofSetColor(255);
    ofRect(520,200,512, 200);
    
    ofNoFill();
    ofSetColor(0);
    ofBeginShape();
    for (int i = 0; i < 512; i++){
        ofVertex(520 + i, 300 + 100 * totalSoundBuffer[i]);
    }
    ofEndShape();

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    
    for (int i = 0; i < 3; i++){
        sinWaves[i].setFrequency( ofRandom(20,1000));
    }
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}


//--------------------------------------------------------------
void testApp::audioOut(float * output, int bufferSize, int nChannels){

	for (int i = 0; i < bufferSize; i++){
        
        
        float sample = 0;
        
        for (int j = 0; j < 3; j++){
            float val = sinWaves[j].getSample();
            soundBuffers[j][i] = val;
            sample += val;
        }
        
        output[i*nChannels    ] = sample;
        output[i*nChannels + 1] = sample;
        
        totalSoundBuffer[i] = sample;
	}
    
    
}
