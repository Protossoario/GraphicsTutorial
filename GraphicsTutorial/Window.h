//
//  Window.h
//  GraphicsTutorial
//
//  Created by Eduardo Alberto Sanchez Alvarado on 3/21/15.
//  Copyright (c) 2015 Eduardo Alberto Sanchez Alvarado. All rights reserved.
//

#ifndef __GraphicsTutorial__Window__
#define __GraphicsTutorial__Window__

#include <OpenGL/gl3.h>
#include <SDL2/SDL.h>
#include <string>
#include "Errors.h"

enum WindowFlags { INVISIBLE = 0x1, FULLSCREEN = 0x2, BORDERLESS = 0x4 };

class Window {
public:
    Window();
    
    int create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags);
    
    void swapBuffer();
    
    int getScreenWidth() { return _screenWidth; }
    int getScreenHeight() { return _screenHeight; }
    
private:
    SDL_Window* _sdlWindow;
    int _screenWidth, _screenHeight;
};

#endif /* defined(__GraphicsTutorial__Window__) */
