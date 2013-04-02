/*
 *  particle.h
 *  openFrameworks
 *
 *  Created by Zach Lieberman on 10/29/09.
 *  Copyright 2009 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once


#include "ofMain.h"
#include "ofxCvMain.h"

class particle {

	public: 
	ofPoint pos;
	float energy;
	void setup();
	void update();
	void draw();
	
	void checkImage( ofxCvGrayscaleImage & myImage);


};