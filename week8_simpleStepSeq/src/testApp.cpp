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
	
	setBPM(220); // set the bpm to 220
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
		for(int y=0;y<24;y++)
			notes[x][y]=false;	//turn off all of the notes
	
	lastNoteStartTime = ofGetElapsedTimef(); //start the note time counter to the current time
	sequencerPosition = 0; // return the playhead to the start
}

//--------------------------------------------------------------
void testApp::update(){
	
	if(ofGetElapsedTimef() > lastNoteStartTime + bpm) // if the current time is more than the time the last note was played + the timing between notes, then advance the playhead
	{
		sequencerPosition++; // advance the playhead
		lastNoteStartTime = ofGetElapsedTimef(); //set the time of this note start to the current time
		
		if(sequencerPosition == ofGetWidth()/32) //if the sequencer has passed the end of the screen, move it back to the start
			sequencerPosition = 0;
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	
	//draw the sequencer playbar
	ofSetColor(255, 0, 0);
	ofRect(sequencerPosition*32, 0, 32, ofGetHeight());
	
	//draw the sequencer notes
	ofSetColor(0,0,0);
	for(int x=0;x<32;x++)
	{
		for(int y=0;y<24;y++)
		{
			if(notes[x][y])
				ofRect(x*32, y*32, 32, 32);
		}
	}
	
	ofDrawBitmapString("bpm = "+ofToString(bpmInt), 10, 10);
	ofDrawBitmapString("press a/z to modify", 10, 25);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

	if(key=='a')
		bpmInt+=10;
	else if(key == 'z')
		bpmInt-=10;
	
	if(key=='x')
		resetSequencer();
	
	setBPM(bpmInt);
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	notes[x/32][y/32] = setVal;
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	setVal = !notes[x/32][y/32]; //store whether we are adding or erasing notes
	notes[x/32][y/32] = setVal; //set the value of the note we've clicked on to 'setVal'
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

void testApp::audioRequested(float * output, int bufferSize, int nChannels){	
	
	int column = sequencerPosition; // store this in case it changes while this function is running
	int notesPlayed = 0; // count how many notes have been played for the averaging
	
	for (int i = 0; i < bufferSize; i++){ //clear the buffers
		output[i*nChannels    ] = 0;
		output[i*nChannels + 1] = 0;
	}
	
	if(ofGetElapsedTimef() < lastNoteStartTime + noteLength) //if the time that we are at is within the time specified by note length
	{
		for(int y=0; y<24; y++){ // go through the column and 
			if(notes[column][y]){ //if a note is turned on
				
				notePlayer[y].addToSoundBuffer(output, bufferSize); //add that note to the sound buffer
				notesPlayed++; //and to our count of how many notes are being played
			}
		}
	}
	
	notesPlayed = MAX(notesPlayed, 4); // if we have less than 4 things playing at once, we'll notice the volume shift too clearly, so always divide by at least 4
	
	for (int i = 0; i < bufferSize; i++){ // avgerage all the inputs so the sound never goes over 1.0
		output[i*nChannels    ] /= notesPlayed;
		output[i*nChannels + 1] /= notesPlayed;
	}
}
