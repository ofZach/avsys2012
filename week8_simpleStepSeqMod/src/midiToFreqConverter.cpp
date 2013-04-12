/*
 *  midiToFreqConverter.cpp
 *  simpleStepSeq
 *
 *  Created by Zach Gage on 3/8/11.
 *  Copyright 2011 stfj. All rights reserved.
 *
 */

#include "midiToFreqConverter.h"

float midiToFreqConverter::getFreqForNote(int note){
	return 440 * pow(2.0,(note-69.0)/12.0);
}