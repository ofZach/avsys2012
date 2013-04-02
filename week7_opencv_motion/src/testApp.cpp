#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	// setup video grabber:
	video.initGrabber(320, 240);
	video.setDesiredFrameRate(30);
    //video.videoSettings();
	// get the width and height, and allocate color and grayscale images: 
	width = video.width; 
	height = video.height;
	
    
	videoColorCvImage.allocate(width, height);
	videoGrayscaleCvImage.allocate(width, height);
	videoPrevFrameImage.allocate(width, height);
	videoDiffImage.allocate(width, height);
	
	// set background color to be white: 
	ofBackground(255, 255, 255);
	
	
	panel.setup("cv settings", 720, 0, 300, 748);
	panel.addPanel("control", 1, false);
	
	panel.setWhichPanel("control");
	panel.setWhichColumn(0);
	panel.addSlider("threshold ", "THRESHOLD", 127, 0, 255, true);
	
	panel.loadSettings("cvSettings.xml");
	
	beats.loadSound("1085.mp3");
	beats.setLoop(true);
	beats.play();
	beats.setSpeed(0.1);
}

//--------------------------------------------------------------
void testApp::update(){
		
	panel.update();
	
	
	int threshold			= panel.getValueI("THRESHOLD");

	
	video.update();
	
	if (video.isFrameNew()){
		
		videoColorCvImage.setFromPixels(video.getPixels(), width, height);
		videoGrayscaleCvImage = videoColorCvImage;
		
		videoDiffImage.absDiff(videoGrayscaleCvImage, videoPrevFrameImage);
		videoDiffImage.threshold(threshold);
		
		videoPrevFrameImage = videoGrayscaleCvImage;
							
		float speed = ofMap(videoDiffImage.countNonZeroInRegion(0, 0, 320, 240), 0,5000, 0.3, 3);
		
		beats.setSpeed(speed);
	}
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	printf("number of pixels moving = %i \n", videoDiffImage.countNonZeroInRegion(0, 0, 320, 240));
	
	ofSetColor(255, 255, 255);
	videoGrayscaleCvImage.draw(20,20, 320,240);
	videoPrevFrameImage.draw(320+40, 20, 320, 240);
	videoDiffImage.draw(20,240+40, 640, 480);
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
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
	panel.mouseReleased();
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

