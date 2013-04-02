/*
 *  particle.cpp
 *  openFrameworks
 *
 *  Created by Zach Lieberman on 10/29/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#include "particle.h"


void particle::setup(){
	pos.x = ofRandom(0,ofGetWidth());
	pos.y = ofRandom(0,ofGetHeight());
	energy = 1;
}

void particle::update(){
	energy = 0.99f * energy + 0.01f * 1.0f;
}

void particle::checkImage( ofxCvGrayscaleImage & myImage){
	
	float pctx = pos.x / (float)ofGetWidth();
	pctx = ofClamp(pctx, 0,1);
	float pcty = pos.y / (float)ofGetHeight();
	pcty = ofClamp(pcty, 0,1);
	
	int pixXinImage = myImage.width * pctx;
	int pixYinImage = myImage.height * pcty;
	
	unsigned char * pixels = myImage.getPixels();
	if (pixels[pixYinImage * myImage.width + pixXinImage] > 127){
		energy = 0;
	}
}



void particle::draw(){
	ofEnableAlphaBlending();
	ofSetColor(255, 0, 0, 100);
	ofCircle(pos.x, pos.y, 30 * energy);
}
