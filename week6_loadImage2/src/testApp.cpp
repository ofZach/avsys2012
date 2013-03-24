#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	squirrel.loadImage("squirrel.png");
	squirrel.setImageType(OF_IMAGE_COLOR);
	
	ofBackground(0,0,0);
    
    ofSetCircleResolution(100);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofSetColor(0,0,0);
	squirrel.draw(0,0);
	
	
	unsigned char * pixels = squirrel.getPixels();
	
	for (int i = 0; i < squirrel.width; i+=MAX(1,mouseX)){
		for (int j = 0; j < squirrel.height; j+=MAX(1,mouseX)){
			
			int red = pixels[ (j * squirrel.width + i) * 3];
			int green = pixels[ (j * squirrel.width + i) * 3 + 1];
			int blue = pixels[ (j * squirrel.width + i) * 3 + 2];
			
			ofSetColor(red,green,blue);
			ofCircle(300 + i, j, mouseX/2);
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

