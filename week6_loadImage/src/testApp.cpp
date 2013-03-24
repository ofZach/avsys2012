#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	squirrel.loadImage("squirrel.png");
	squirrel.setImageType(OF_IMAGE_GRAYSCALE);
	
	ofBackground(0,0,0);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
	squirrel.draw(0,0);
	
	
	unsigned char * pixels = squirrel.getPixels();
	
	for (int i = 0; i < squirrel.width; i+=8){
		for (int j = 0; j < squirrel.height; j+=8){
			int value = pixels[j * squirrel.width + i];
			//ofSetColor(value, value, value);
			float pct = ofMap(value, 0,255, 1,5);
			ofSetColor(255,255,255);
			ofCircle(300 + i, j, pct);
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

