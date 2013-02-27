#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    
    img.allocate(640, 480, OF_IMAGE_GRAYSCALE);
    
    
}

//--------------------------------------------------------------
void testApp::update(){

    
    unsigned char * pixels = img.getPixels();
    
    float pct = ofMap(mouseX, 0, ofGetWidth(), 0, 1, true);     // get the mouse as a pct across the screen
    
    for (int i = 0; i < 640*480; i++){
        pixels[i] = ofRandom(0, 255 * pct);
    }
    
    img.update();
    
}

//--------------------------------------------------------------
void testApp::draw(){

    
    img.draw(0,0);
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