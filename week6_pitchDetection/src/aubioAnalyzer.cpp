#include "aubioAnalyzer.h"


//--------------------------------------------------------------
void aubioAnalyzer::setup(){	 
			
	//the two variables that hold pitch and volume
	amplitude		= 0;
	pitch			= 0;
			
	//aubio stuff
	win_s      = 1024;                       /* window size */
	hop_s      = win_s/4;                    /* hop size */
	samplerate = 44100;                      /* samplerate */
	channels   = 1;                          /* number of channel */
	
	//setup aubio buffer and pitch detection
	in  = new_fvec (hop_s);
    out = new_fvec (1);
    
    // other options: "yinfft"  "mcomb"  "yin"  "schmitt"  "fcomb" "default"
    
	pitch_output = new_aubio_pitch("default", win_s, hop_s, samplerate);


}

//--------------------------------------------------------------
aubioAnalyzer::~aubioAnalyzer(){
	  del_aubio_pitch(pitch_output);
	  del_fvec(in);
	  aubio_cleanup();
}

//--------------------------------------------------------------
void aubioAnalyzer::processAudio (float * input, int bufferSize){	
	
	float rmsAmplitude  = 0;

	for (int i = 0; i < bufferSize; i++){
		
		//calculate the root mean square amplitude
		rmsAmplitude += sqrt(input[i]*input[i]);
		
		//put the data into aubio
		in->data[i] = input[i];
	}
	
	//now we need to get the average
	rmsAmplitude /= bufferSize;
	amplitude = rmsAmplitude;
	
	//don't update the pitch if the sound is very quiet
	if( amplitude > 0.01 ){
		//finally get the pitch of the sound
        aubio_pitch_do(pitch_output,in, out);
        pitch = out->data[0];
        confidence = aubio_pitch_get_confidence(pitch_output);
    }
}