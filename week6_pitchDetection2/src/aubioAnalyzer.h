#ifndef _AUBIO_SOUND_PROCESSOR
#define _AUBIO_SOUND_PROCESSOR

#include "aubio.h"
#include "fvec.h"
#include "ofMain.h"

class aubioAnalyzer{
	
	public:
		
		void setup();
		void processAudio(float * buffer, int bufferSize);		
		
		~aubioAnalyzer();
	
		float pitch;
		float amplitude;
        float confidence;
		
		// ------------------------------------------------------------------
		// internal aubio variables

		uint_t win_s;							/* window size */
		uint_t hop_s;							/* hop size */
		uint_t samplerate;						/* samplerate */
		uint_t channels;						/* number of channel */
		
        fvec_t * out;
		fvec_t * in;
		aubio_pitch_t * pitch_output ;
	
		// ------------------------------------------------------------------

};

#endif	

