//
//  Timing.h
//  GraphicsTutorial
//
//  Created by Eduardo Alberto Sanchez Alvarado on 3/21/15.
//  Copyright (c) 2015 Eduardo Alberto Sanchez Alvarado. All rights reserved.
//

#ifndef GraphicsTutorial_Timing_h
#define GraphicsTutorial_Timing_h

#include <SDL2/SDL.h>

class FPSLimiter {
public:
    void init(float maxFPS);
    
    void setMaxFPS(float maxFPS);
    
    void begin();
    // end will return the current FPS
    float end();
    
private:
    void calculateFPS();
    
    float _fps;
    float _maxFPS;
    float _frameTime;
    unsigned int _startTicks;
};

#endif
