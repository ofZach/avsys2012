
#include "oscillator.h"


    
void oscillator::setup (int rate){
    sampleRate = rate;
    type = sineWave;
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
    
    
    
    if (type == sineWave){
        return sin(phase) * volume;
    } else if (type == squareWave){
        return (sin(phase) > 0 ? 1 : -1) * volume;
    } else if (type == triangleWave){
        float pct = phase / TWO_PI;
        return ( pct < 0.5 ? ofMap(pct, 0, 0.5, -1, 1) : ofMap(pct, 0.5, 1.0, 1, -1)) * volume;
    } else if (type == sawWave){
        float pct = phase / TWO_PI;
        return ofMap(pct, 0, 1, -1, 1) * volume;
    } else if (type == sawWaveReverse){
        float pct = phase / TWO_PI;
        return ofMap(pct, 0, 1, 1, -1) * volume;
    }
    
}

