#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	// setup video grabber:
	video.initGrabber(320, 240);
	
	// get the width and height, and allocate color and grayscale images: 
	width = video.width; 
	height = video.height;
	
	videoColorCvImage.allocate(width, height);
	videoColorHSVCvImage.allocate(width, height);
	
	videoGrayscaleHueImage.allocate(width, height);
	videoGrayscaleSatImage.allocate(width, height);
	videoGrayscaleBriImage.allocate(width, height);
	
	videoGrayscaleCvImage.allocate(width, height);
	
	grayPixels = new unsigned char [width * height];
	
	// set background color to be white: 
	ofBackground(255, 255, 255);
	
	
	panel.setup("cv settings", 720, 0, 300, 748);
	panel.addPanel("control", 1, false);
	
	panel.setWhichPanel("control");
	panel.setWhichColumn(0);
	
	panel.addToggle("video settings", "VIDEO_SETTINGS", false);
	
	panel.addSlider("hue range ", "HUERANGE", 20, 0, 255, true);
	panel.addSlider("sat range ", "SATRANGE", 30, 0, 255, true);
	panel.addSlider("val range ", "VALRANGE", 25, 0, 255, true);
	
	panel.loadSettings("cvSettings.xml");
	
	
	hueRange = 20;
	satRange = 30;
	valRange = 25;
	
	hue = 0;
	sat = 0;
	val = 0;
	
}

//--------------------------------------------------------------
void testApp::update(){
		
	panel.update();
	
	
	hueRange			= panel.getValueI("HUERANGE");
	satRange			= panel.getValueI("SATRANGE");
	valRange			= panel.getValueI("VALRANGE");
	
	
	if (panel.getValueB("VIDEO_SETTINGS") == true){
		video.videoSettings();
		panel.setValueB("VIDEO_SETTINGS", false);
	}
	
	
	video.update();
	
	if (video.isFrameNew()){
		
		videoColorCvImage.setFromPixels(video.getPixels(), width, height);
		videoColorHSVCvImage = videoColorCvImage;
		videoColorHSVCvImage.convertRgbToHsv();
		
		videoColorHSVCvImage.convertToGrayscalePlanarImages(videoGrayscaleHueImage, videoGrayscaleSatImage, videoGrayscaleBriImage);
		
		videoGrayscaleHueImage.flagImageChanged();		// this is fixing a bug in OF 0.06
		videoGrayscaleSatImage.flagImageChanged();
		videoGrayscaleBriImage.flagImageChanged();
		
		
		unsigned char * colorHsvPixels = videoColorHSVCvImage.getPixels();
		
		for (int i = 0; i < width*height; i++){
			
				// since hue is cyclical:
				int hueDiff = colorHsvPixels[i*3] - hue;
				if (hueDiff < -127) hueDiff += 255;
				if (hueDiff > 127) hueDiff -= 255;
			
			
				if ( (fabs(hueDiff) < hueRange) &&
					(colorHsvPixels[i*3+1] > (sat - satRange) && colorHsvPixels[i*3+1] < (sat + satRange)) &&
					(colorHsvPixels[i*3+2] > (val - valRange) && colorHsvPixels[i*3+2] < (val + valRange))){
	
					grayPixels[i] = 255;
		
				} else {
					
					grayPixels[i] = 0;
				}
				
			}
			
			videoGrayscaleCvImage.setFromPixels(grayPixels, width, height);
			
			
							
								
	}
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofSetColor(255, 255, 255);
	videoColorCvImage.draw(0,0, 320,240);
	videoColorHSVCvImage.draw(320+20, 0, 320, 240);
	videoGrayscaleHueImage.draw(0,240+20);
	videoGrayscaleSatImage.draw(320,240+20);
	videoGrayscaleBriImage.draw(640,240+20);
	
	videoGrayscaleCvImage.draw(0,480+40,320,240);
	
	panel.draw();
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
	panel.mouseDragged(x,y,button);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	panel.mousePressed(x,y,button);
	
	if (x >= 0 && x < 320 && y >= 0 && y < 240){
		int pixel = y * 320 + x;
		hue = videoGrayscaleHueImage.getPixels()[pixel];
		sat = videoGrayscaleSatImage.getPixels()[pixel];
		val = videoGrayscaleBriImage.getPixels()[pixel];
		
	}
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	panel.mouseReleased();
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

