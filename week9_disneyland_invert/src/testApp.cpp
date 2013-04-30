#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    
    disneyland.loadImage("disneyland.jpg");
    disneylandInverted.allocate(disneyland.width,
                                disneyland.height,
                                OF_IMAGE_COLOR);
    
    
    
    // this is wrong, since origPixels is now a copy of disneyland.getPixelsRef
    
    //ofPixels origPixels = disneyland.getPixelsRef();
    //ofPixels newPixels = disneylandInverted.getPixelsRef();
    
    // this is right since origPixels is a reference variable
    // which refers to the original ofPixels.
    // (the getPixelsRef is there to remind you to use it like a references)
    
    ofPixels & origPixels = disneyland.getPixelsRef();
    ofPixels & newPixels = disneylandInverted.getPixelsRef();
    
    for (int i = 0; i < disneyland.width; i++){
        for (int j = 0; j < disneyland.height; j++){

            ofColor pixel = origPixels.getColor(i,j);
            
            pixel.r = 255 - pixel.r;
            pixel.g = 255 - pixel.g;
            pixel.b = 255 - pixel.b;
            
            
            newPixels.setColor(i, j, pixel);
            
        }
    }
    
    disneylandInverted.update();
    
    
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

    disneyland.draw(0,0);
    disneylandInverted.draw(disneyland.width, 0);
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