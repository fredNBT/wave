#ifndef PARAMS_H_
#define PARAMS_H_

#include "Arduino.h"

#define Speed  80 // The lower the number the faster the wave goes
const int BackoffDistance = 250; // where the wave begings
const int waveLength = 1900; // how long the wave is
const int numberOfWaves = 250; // how many waves per cycle
const int waveDelay = 0; // delay in ms between waves 0 means runs contiuesly 
const int RampUpDistance = 120; // how far until the wave is at full speed
const int RampdownDistance = 1000; // how far away does the wave begin to slow dowm
// these params you should not need to change when they are set
const int HardStopSpeed = 1000; // the speed the paddle is turning when turning around
const int returnSpeen = 5000; // the speed the paddle returns after a reset 
#endif
