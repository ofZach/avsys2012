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
            
            // the formula for adressing the 1d pixel via 2d is:
            // pos = y * w + x
            // so for us that's
            // pos = j * 640 + i
            
            float dist = ofDist(mouseX, mouseY, i, j);      // calculate the distance between two 2d points (pythogrean)
            
            //pixels[ j * 640 + i ] = ofMap(sin(dist), -1, 1, 0, 255);
            //pixels[ j * 640 + i ] = ofMap(sin(dist/10.0), -1, 1, 0, 255);
            
            pixels[ j * 640 + i ] = ofMap(sin(dist/10.0 + j/10.0), -1, 1, 0, 255);      // no idea!
            
            
            //pixels[ j * 640 + i ] = i * j / MAX(1,mouseX);      // also, no idea!
            
            
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