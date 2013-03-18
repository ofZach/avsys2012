#include "testApp.h"


/*
 

 for a sender you need to know the ip address and port you are sending to.
 
 on osx, if you do ifconfig, you can see an ipaddress: 
 
 en0: flags=8863<UP,BROADCAST,SMART,RUNNING,SIMPLEX,MULTICAST> mtu 1500
 inet 192.168.2.94 netmask 0xffffff00 broadcast 192.168.2.255
 media: autoselect
 
 here my ip address is 192.168.2.94
 
*/



//--------------------------------------------------------------
void testApp::setup(){

    
    recvr.setup(6666);   // be sure to set the port in your sending app right...
    
}

//--------------------------------------------------------------
void testApp::update(){

    
    while (recvr.hasWaitingMessages()){
        
        
        ofxOscMessage message;
        recvr.getNextMessage(&message);
        
        cout << "message address: " << message.getAddress() << endl;
        cout << "message num arguments: " << message.getNumArgs() << endl;
        
        for (int i = 0; i < message.getNumArgs(); i++){
            cout << "argument " << i << " is type " << message.getArgTypeName(i);
            
            if (message.getArgType(i) == OFXOSC_TYPE_FLOAT){
                cout << " val = " << message.getArgAsFloat(i) << endl;
            } else if (message.getArgType(i) == OFXOSC_TYPE_INT32){
                cout << " val = " << message.getArgAsInt32(i) << endl;
            } else if (message.getArgType(i) == OFXOSC_TYPE_STRING){
                cout << " val = " << message.getArgAsString(i) << endl;
            }
        }
        
        
        
        
        
        
    }
    
    
}

//--------------------------------------------------------------
void testApp::draw(){

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