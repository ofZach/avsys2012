#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    ofSetFrameRate(60);
   
    
    for (int i = 0; i < 32; i++){
        for (int j = 0; j < 24; j++){
            pixels[i][j] = false;
        }
    }
    
    
}

//--------------------------------------------------------------
void testApp::update(){

    
    
}

//--------------------------------------------------------------
void testApp::draw(){

    
    ofFill();
    
    for (int i = 0; i < 32; i++){
        for (int j = 0; j < 24; j++){
            if (pixels[i][j] == true) ofSetColor(255);
            else ofSetColor(0);
            ofRect(i*32, j*32, 32, 32);
        }
    }
    
    
    
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

    pixels[x/32][y/32] =  drawVal;
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

    drawVal = !pixels[x/32][y/32];
    
    pixels[x/32][y/32] =  drawVal;
  
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