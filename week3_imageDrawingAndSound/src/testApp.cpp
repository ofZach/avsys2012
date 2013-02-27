#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){	

	w = 300;
	h = 500;
	
	img.allocate(w,h,OF_IMAGE_GRAYSCALE);
	
    
    unsigned char * pixels = img.getPixels();
	
    for (int i = 0; i < w; i++){
        for (int j = 0; j < h; j++){
            pixels[j*w + i] = 0;
        }
    }
    
    
	img.update();
	
	ofSoundStreamSetup(2,0,this, 44100,256, 4);
	
	ofSetVerticalSync(true);
	
	verticalPos = 0;
	
	for (int i = 0; i < 30; i++){
		oscillators[i].setup();
		oscillators[i].setFrequency(30 + i * 100);
		oscillators[i].setVolume(0);
	}
	
	bDoFade = false;
	
	speed = 2;
	
}
 

//--------------------------------------------------------------
void testApp::update(){
	
	unsigned char * pixels = img.getPixels();
	
	if (bDoFade == true){
		for (int i = 0; i < w; i++){
			for (int j = 0; j < h; j++){
				pixels[j*w + i] = MAX(0, pixels[j*w + i] - 1);
			}
		}
	}
	 
	
	
	ofBackground(255,255,255);
	
	verticalPos += speed;
	if (verticalPos > (h-1)) verticalPos = 0;
	if (verticalPos < 0) verticalPos = (h-1);
	// now, for the given line of pixels, calculate how "loud" each oscillator is: 
	
	int pixWidth = (int)(w / 30.0f);
	for (int i = 0; i < 30; i++){
		
		float total = 0;
		for (int j = 0; j < pixWidth; j++){
			int ypos = verticalPos;
			int xpos = i * pixWidth + j;
			total += pixels[ypos * w + xpos];
		}
		total /= (float)pixWidth;
		total /= 255;
		total *= (1/30.0f);
		oscillators[i].setVolume(total);
	}
    
    img.update();

}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofSetColor(255);
	img.draw(0,0,w,h);
	
	//calculate where the position is: 
	
	ofSetColor(255, 0, 0);
	
	ofLine(0,verticalPos, w, verticalPos);
	
	ofSetColor(0,0,0);
	ofDrawBitmapString("press (f) to toggle fade", 330, 30);
	ofDrawBitmapString("press (+/-) to adjust speed: " + ofToString(speed, 3), 330, 45);
	
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 
	
	if (key == 'f'){
		bDoFade = !bDoFade;
	} else if (key == '-'){
		speed -= 0.15f;
	} else if (key == '+'){
		speed += 0.15f;
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
    
    unsigned char * pixels = img.getPixels();
	
    
	for (int i = 0; i < w; i++){
		for (int j = 0; j < h; j++){
			float dist = ofDist(mouseX, mouseY, i, j);      // calculate the distance between two 2d points (pythogrean)
            
            if (dist < 10){
                pixels[ j * 300 + i ] = MIN(255, pixels[ j * 300 + i ] + ofMap(dist, 0, 10, 100, 0));
            }

		}
	}
    
    img.update();
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
}

//--------------------------------------------------------------
void testApp::mouseReleased(){

}

//--------------------------------------------------------------
void testApp::audioRequested(float * output, int bufferSize, int nChannels){	
	
	float volume = 0.3f;
	
	for (int i = 0; i < bufferSize; i++){
		output[i*nChannels    ] = 0;
		output[i*nChannels + 1] = 0;
	}
	
	for (int i = 0; i < 30; i++){
		oscillators[i].addToSoundBuffer(output, bufferSize);
	}
	
	/*for (int i = 0; i < bufferSize; i++){
		pos ++;
		pos %= (w*h);
		output[i*nChannels    ] = (pixels[pos]/127.0f - 1) * volume;
		output[i*nChannels + 1] = (pixels[pos]/127.0f - 1) * volume;
	}*/
	
	
}


