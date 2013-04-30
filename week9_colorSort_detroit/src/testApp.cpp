#include "testApp.h"


bool colorCompare (ofColor i,ofColor j) {
    
    int briI = i.getBrightness();
    int briJ = j.getBrightness();
    
    return ( briI > briJ );
}

//--------------------------------------------------------------
void testApp::setup(){

    myImage.loadImage("Red_eyed_tree_frog_edit2.jpg");
    myImage.setImageType(OF_IMAGE_COLOR);
    myNewImage.allocate(myImage.width, myImage.height, OF_IMAGE_COLOR);
    
    
    unsigned char * pixelsOrig = myImage.getPixels();
    unsigned char * pixelsNew = myNewImage.getPixels();
    
    
    for (int i = 0; i < myImage.width; i++){
        for (int j = 0; j < myImage.height; j++){
            
            int newI = ofClamp(i + ofRandom(-5,5), 0, myImage.width-1);
            int newJ = ofClamp(j + ofRandom(-5,5), 0, myImage.height-1);
            
            
            pixelsNew[ (j*myImage.width + i) * 3] =
                pixelsOrig[(j*myImage.width + i) * 3];
            pixelsNew[ (j*myImage.width + i) * 3+1] =
                pixelsOrig[(j*myImage.width + i) * 3+1];
            pixelsNew[ (j*myImage.width + i) * 3+2] =
                pixelsOrig[(j*myImage.width + i) * 3+2];
            
            
        }
    }
    
    
    colors.clear();
    for (int i = 0; i < myImage.width * myImage.height; i++){
        
        ofColor temp;
        colors.push_back(  ofColor(pixelsOrig[i*3+0],
                                   pixelsOrig[i*3+1],
                                   pixelsOrig[i*3+2]) );
    }
    
    ofSort(colors, colorCompare);
    
    for (int i = 0; i < colors.size(); i++){
        
        pixelsNew[i*3] = colors[i].r;
        pixelsNew[i*3+1] = colors[i].g;
        pixelsNew[i*3+2] = colors[i].b;
        
    }


    
    myNewImage.update();
    
}

//--------------------------------------------------------------
void testApp::update(){

    
    // this does some fun spinning of pixels
    
//    unsigned char * pixelsOrig = myImage.getPixels();
//    unsigned char * pixelsNew = myNewImage.getPixels();
//  
//    
//    for (int i = 0; i < myImage.width; i++){
//        for (int j = 0; j < myImage.height; j++){
//            
//            float di = i - myImage.width/2;
//            float dj = j - myImage.height/2;
//            
//            float dist = ofDist(0,0,di, dj);
//            float angle = atan2(dj,di);
//            
//            float newAngle = angle += ofRandom(mouseX / 100.0, -mouseX/100.0);
//            
//            int newI =  ofClamp(myImage.width/2 + dist * cos(newAngle),  0, myImage.width-1);
//            int newJ =  ofClamp(myImage.height/2 + dist * sin(newAngle),0, myImage.height-1);
//
//            
//            
//            //int newI = ofClamp(i + ofRandom(-mouseX,mouseX), 0, myImage.width-1);
//            //int newJ = ofClamp(j + ofRandom(-mouseX,mouseX), 0, myImage.height-1);
//            
//            
//            pixelsNew[ (j*myImage.width + i) * 3] =
//            pixelsOrig[(newJ*myImage.width + newI) * 3];
//            pixelsNew[ (j*myImage.width + i) * 3+1] =
//            pixelsOrig[(newJ*myImage.width + newI) * 3+1];
//            pixelsNew[ (j*myImage.width + i) * 3+2] =
//            pixelsOrig[(newJ*myImage.width + newI) * 3+2];
//            
//            
//        }
//    }
    
    
    
    
    myNewImage.update();
    
    
}

//--------------------------------------------------------------
void testApp::draw(){

    myImage.draw(0,0);
    myNewImage.draw(myImage.width,0);
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