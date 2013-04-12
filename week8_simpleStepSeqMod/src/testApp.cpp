#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSoundStreamSetup(2,0,this, 44100, 512, 4);
	
	ofSetColor(255, 255, 255);
	
	ofSetFrameRate(60);
	
	//set up the notes
	for(int i=0;i<24;i++){
		notePlayer[23-i].setup();
		notePlayer[23-i].setVolume(1.0);
		notePlayer[23-i].setFrequency(midi.getFreqForNote(48+i));
	}
	
	resetSequencer();
	
	setBPM(220);
}
//--------------------------------------------------------------

void testApp::setBPM(int targetBPM){
	bpmInt = targetBPM;
	bpm = 60.0f / bpmInt; //60 seconds in a minute / 120 beats per second
	noteLength = bpm; // have notes play for 100% of the bpm time.
}
//--------------------------------------------------------------
void testApp::resetSequencer(){
	for(int x=0;x<32;x++)
	{
		for(int y=0;y<24;y++){
			notes[x][y]=false;	
			notesAlt[x][y]=false;	
		}
	}
	
	lastNoteStartTime = ofGetElapsedTimef();
	sequencerPosition = 0;
	
	movedThisFrame=0;
}

//--------------------------------------------------------------
void testApp::update(){
	if(ofGetElapsedTimef() > lastNoteStartTime + bpm)
	{
		sequencerPosition++;
		lastNoteStartTime = ofGetElapsedTimef();
		
		if(sequencerPosition == ofGetWidth()/32)
			sequencerPosition = 0;
		
		movedThisFrame=0;
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	
	//draw the sequencer playbar
	ofSetColor(255, 0, 0);
	ofRect(sequencerPosition*32, 0, 32, ofGetHeight());
	
	//draw the sequencer notes
	
	for(int x=0;x<32;x++)
	{
		for(int y=0;y<24;y++)
		{
			ofSetColor(0,0,0);
			if(notes[x][y])
				ofRect(x*32, y*32, 32, 32);
			
			ofSetColor(0,255,0);
			if(notesAlt[x][y]) //draw the alt notes
				ofRect(x*32+10, y*32+10, 12, 12);
		}
	}
	
	ofSetColor(0, 0, 255);
	ofDrawBitmapString("bpm = "+ofToString(bpmInt), 10, 10);
	ofDrawBitmapString("press a/z to modify", 10, 25);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

	if(key=='a')
		bpmInt+=10;
	else if(key == 'z')
		bpmInt-=10;
	
	setBPM(bpmInt);
	
	if(key=='x')
		resetSequencer();
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
	if(button == 0)
		notes[x/32][y/32] = setVal;
	else
		notesAlt[x/32][y/32] = setVal;
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	
	if(button == 0){ // if left mouse click, set a up moving note
		setVal = !notes[x/32][y/32];
		notes[x/32][y/32] = setVal;
	}else { //if right mouse click, set a down moving note
		setVal = !notesAlt[x/32][y/32];
		notesAlt[x/32][y/32] = setVal;
	}

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

void testApp::audioRequested(float * output, int bufferSize, int nChannels){	
	
	int column = sequencerPosition; // store this in case it changes while this function is running
	int notesPlayed = 0;
	
	for (int i = 0; i < bufferSize; i++){
		output[i*nChannels    ] = 0;
		output[i*nChannels + 1] = 0;
	}
	
	if(ofGetElapsedTimef() < lastNoteStartTime + noteLength) //move notes up
	{
		for(int y=0; y<24; y++){
			if(notes[column][y]){
				
				notePlayer[y].addToSoundBuffer(output, bufferSize);
				notesPlayed++;
				
				if(movedThisFrame<2){
					notes[column][y] = false;
					if(y>0)
						notes[column][y-1] = true;
					else
						notes[column][23] = true;
				}
			}
		}
		
		for(int y=24; y>=0; y--){ // go through backwards, move notes down. we have to loop through backwards because otherwise, we'll move a note down, and then check the same note we just moved next frame and move it down again, instantly moving all notes to the bottom
			if(notesAlt[column][y]){
				
				notePlayer[y].addToSoundBuffer(output, bufferSize);
				notesPlayed++;
				
				if(movedThisFrame<2){
					notesAlt[column][y] = false;
					if(y!=23)
						notesAlt[column][y+1] = true;
					else
						notesAlt[column][0] = true;
				}
			}
		}
	}
	
	movedThisFrame++;
	
	notesPlayed = MAX(notesPlayed, 4); // if we have less than 4 things playing at once, we'll notice the volume shift too clearly
	
	for (int i = 0; i < bufferSize; i++){ // avgerage all the inputs so the sound never goes over 1.0
		output[i*nChannels    ] /= notesPlayed;
		output[i*nChannels + 1] /= notesPlayed;
	}
}
