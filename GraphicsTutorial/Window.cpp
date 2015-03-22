//
//  Window.cpp
//  GraphicsTutorial
//
//  Created by Eduardo Alberto Sanchez Alvarado on 3/21/15.
//  Copyright (c) 2015 Eduardo Alberto Sanchez Alvarado. All rights reserved.
//

#include "Window.h"

Window::Window() : _sdlWindow(nullptr) {}

int Window::create(std::string windowName, int screenWidth, int screenHeight, unsigned int currentFlags) {
    Uint32 flags = SDL_WINDOW_OPENGL;
    
    if (currentFlags & INVISIBLE) {
        flags |= SDL_WINDOW_HIDDEN;
    }
    
    if (currentFlags & FULLSCREEN) {
        flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
    }
    
    if (currentFlags & BORDERLESS) {
        flags |= SDL_WINDOW_BORDERLESS;
    }
    
    _sdlWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, flags);
    
    if (_sdlWindow == nullptr) {
        const char *error = SDL_GetError();
        printf("Error: %s\n", error);
        fatalError("SDL Window could not be created!");
    }
    
    SDL_GLContext glContext = SDL_GL_CreateContext(_sdlWindow);
    if (glContext == nullptr) {
        fatalError("SDL GL Context could not be created!");
    }
    
    glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
    
    // Turn on double buffering
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    // Set VSync off
    SDL_GL_SetSwapInterval(0);
    // Enabled alpha blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    return 0;
}

void Window::swapBuffer() {
    SDL_GL_SwapWindow(_sdlWindow);
}