#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	// load the image from the data folder
	myPicture.loadImage("test.png");
	
	// set the image type to be grayscale (1 byte per pixel)
	myPicture.setImageType(OF_IMAGE_GRAYSCALE);
	
	// allocate opencv, load in: 
	
	myPictureAsCvImage.allocate(myPicture.width, myPicture.height);
	//myPictureAsCvImage.setFromPixels(myPicture.getPixels(),myPicture.width, myPicture.height);
	
	// set background color to be white: 
	ofBackground(255, 255, 255);
}

//--------------------------------------------------------------
void testApp::update(){
	
	myPictureAsCvImage.setFromPixels(myPicture.getPixels(),myPicture.width, myPicture.height);
	
	
	//myPictureAsCvImage.blur( mouseX * 2 + 1);
	myPictureAsCvImage.threshold(mouseX);
}

//--------------------------------------------------------------
void testApp::draw(){
	
	// when we draw, the drawing color "tints" the drawing, so white is best for image
	// ie, white = no tint.
	ofSetColor(255, 255, 255);
	myPicture.draw(0,0);
	myPictureAsCvImage.draw(myPicture.width, 0);
	
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

