#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

    
    sender.setup("localhost", 4567);
    
    ofSetVerticalSync(true);
    
    bouncingBallPos.set(300,300);
    bouncingBallVel.set(ofRandom(-10,10), ofRandom(-10,10));
    
    
    
    
}

//--------------------------------------------------------------
void testApp::update(){

    
    bouncingBallPos += bouncingBallVel;
    
    
    if (bouncingBallPos.x < 0){
        bouncingBallPos.x = 0;
        bouncingBallVel.x *= -1;
        ofxOscMessage message;
        message.setAddress("/playtone");
        
        float tone = ofMap(bouncingBallPos.y, 0, ofGetHeight(), 400, 60);
        message.addFloatArg( tone );
        
        sender.sendMessage(message);
    }
    
    if (bouncingBallPos.x > ofGetWidth()){
        bouncingBallPos.x = ofGetWidth();
        bouncingBallVel.x *= -1;
        ofxOscMessage message;
        message.setAddress("/playtone");
        float tone = ofMap(bouncingBallPos.y, 0, ofGetHeight(), 400, 60);
        message.addFloatArg( tone );
        
        sender.sendMessage(message);
    }
    
    if (bouncingBallPos.y < 0){
        bouncingBallPos.y = 0;
        bouncingBallVel.y *= -1;
        ofxOscMessage message;
        message.setAddress("/playtone");
        float tone = ofMap(bouncingBallPos.y, 0, ofGetHeight(), 400, 60);
        message.addFloatArg( tone );
        
        sender.sendMessage(message);
    }
    
    if (bouncingBallPos.y > ofGetHeight()){
        bouncingBallPos.y = ofGetHeight();
        bouncingBallVel.y *= -1;
        ofxOscMessage message;
        message.setAddress("/playtone");
        float tone = ofMap(bouncingBallPos.y, 0, ofGetHeight(), 400, 60);
        message.addFloatArg( tone );
        
        sender.sendMessage(message);
    }
    
  
    
}

//--------------------------------------------------------------
void testApp::draw(){

    ofCircle( bouncingBallPos.x, bouncingBallPos.y, 20);
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