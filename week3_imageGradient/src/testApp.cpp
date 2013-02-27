#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    
    img.allocate(640, 480, OF_IMAGE_GRAYSCALE);
    
    
}

//--------------------------------------------------------------
void testApp::update(){

    
    unsigned char * pixels = img.getPixels();
    
    
    // (note: the order of these for loops doesn't matter)
    
    for (int i = 0; i < 640; i++){
        for (int j = 0; j < 480; j++){
            
            
            // horizontal gradient 
            // this "wraps" over
            //pixels[ j * 640 + i ] = i;
            
            pixels[ j * 640 + i ] = ofMap(i, 0, 640, 255, 0);
            
            
            // this is funky and weird
            //pixels[ j * 640 + i ] = ofMap(i + sin(j/10.0 + ofGetElapsedTimef()) * j, 0, 640, 255, 0, true);

            
            
            
        }
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