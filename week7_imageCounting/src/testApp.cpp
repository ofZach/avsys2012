#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	width = 20;
	height = 10;
	pixels = new bool [width * height];
	
	for (int i = 0; i < width; i++){
		for (int j = 0; j < height; j++){	
			pixels[j*width + i] = false;
		}
	}
	
	position = 0;
	
	helvetica.loadFont("helvetica.otf", 15);
	
	ofBackground(255, 255, 255);
}

//--------------------------------------------------------------
void testApp::update(){

	for (int i = 0; i <width*height; i++){
		pixels[i] = false;
	}
	
	pixels[position] = true;
	
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	float widthPixel =  20;
	float heightPixel = 20;
	
	
	for (int i = 0; i < width; i++){
		for (int j = 0; j < height; j++){	
			
			ofFill();
			if (pixels[j*width + i]) ofSetColor(0, 0, 0);
			else ofSetColor(255, 255, 255);
			ofRect( 10 + i * widthPixel, 10 + j * heightPixel, widthPixel, heightPixel);
			
			ofNoFill();
			ofSetColor(0, 0, 0);
			ofRect( 10 + i * widthPixel, 10 + j * heightPixel, widthPixel, heightPixel);

			
		}
	}
	
	ofSetColor(170,170,170);
	helvetica.drawString("position = " + ofToString(position), 25,250);
	helvetica.drawString("position / width (float) = " + ofToString((float) (position / (float)width), 3), 25,280);
	helvetica.drawString("(y) position / width (int) = " + ofToString((int) (position / (float)width)), 25,310);
	helvetica.drawString("(x) position % width = " + ofToString(position % width), 25,340);
	
	int x = (position % width);
	int y = (int) (position / (float)width);
	
	helvetica.drawString("y * width + x = " + ofToString(y*width + x), 25,370);
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

	switch (key){
			
		case OF_KEY_RIGHT:
			position++;
			break;
		case OF_KEY_LEFT:
			position--;
			break;
		case OF_KEY_UP:
			position-= width;
			break;
		case OF_KEY_DOWN:
			position+=width;
			break;
	}
	
	if (position < 0) position += (width*height);
	if (position >= width*height) position -= width*height;
	
	
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

