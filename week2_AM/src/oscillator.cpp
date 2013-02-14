
#include "oscillator.h"


    
void oscillator::setup (int rate){
    sampleRate = rate;
}

void oscillator::setFrequency (float freq){
    frequency = freq;
    phaseAdder = (float)(frequency * TWO_PI) / (float)sampleRate;
}

void oscillator::setVolume (float vol){
    volume = vol;
}

float oscillator::getSample(){
    phase += phaseAdder;
    while (phase > TWO_PI) phase -= TWO_PI;
    return sin(phase) * volume;
}

