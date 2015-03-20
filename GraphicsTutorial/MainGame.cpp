//
//  MainGame.cpp
//  GraphicsTutorial
//
//  Created by Eduardo Alberto Sanchez Alvarado on 3/1/15.
//  Copyright (c) 2015 Eduardo Alberto Sanchez Alvarado. All rights reserved.
//

#include "MainGame.h"

MainGame::MainGame() : _window(nullptr), _screenWidth(500), _screenHeight(500), _gameState(GameState::PLAY), _time(0), _maxFPS(60.0f) {}

MainGame::~MainGame() {}

void MainGame::run() {
    initSystems();
    
    _sprites.push_back(new Sprite());
    _sprites.back()->init(-1.0f, -1.0f, 1.0f, 1.0f, "/Users/EduardoS/Documents/Programacion/XCode Projects/GraphicsTutorial/GraphicsTutorial/Textures/CharacterRight_Standing.png");
    
    _sprites.push_back(new Sprite());
    _sprites.back()->init(0.0f, -1.0f, 1.0f, 1.0f, "/Users/EduardoS/Documents/Programacion/XCode Projects/GraphicsTutorial/GraphicsTutorial/Textures/CharacterRight_Standing.png");
    
    _sprites.push_back(new Sprite());
    _sprites.back()->init(-1.0f, 0.0f, 1.0f, 1.0f, "/Users/EduardoS/Documents/Programacion/XCode Projects/GraphicsTutorial/GraphicsTutorial/Textures/CharacterRight_Standing.png");
    
    gameLoop();
}

void MainGame::initSystems() {
    // Initialize SDL
    SDL_Init(SDL_INIT_EVERYTHING);
    
    // Required for Mac OS X to support GLSL version 130 or higher
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    
    _window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_OPENGL);
    
    if (_window == nullptr) {
        fatalError("SDL Window could not be created!");
    }
    
    SDL_GLContext glContext = SDL_GL_CreateContext(_window);
    if (glContext == nullptr) {
        fatalError("SDL GL Context could not be created!");
    }
    
    // Required for Mac OS X
    GLuint vertexArrayID;
    glGenVertexArrays(1, &vertexArrayID);
    if (vertexArrayID == 0) {
        printf("%s\n", gluErrorString(glGetError()));
        fatalError("Could not generate Vertex Array Object!");
    }
    glBindVertexArray(vertexArrayID);
    
    printf("OpenGL version %s\n", glGetString(GL_VERSION));
    printf("GLSL version %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
    
    // Turn on double buffering
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    // Set VSync off
    SDL_GL_SetSwapInterval(0);
    
    glClearColor(0.0f, 1.0f, 1.0f, 1.0f);
    
    initShaders();
}

void MainGame::initShaders() {
    _colorProgram.compileShaders("/Users/EduardoS/Documents/Programacion/XCode Projects/GraphicsTutorial/GraphicsTutorial/Shaders/colorShading.vert", "/Users/EduardoS/Documents/Programacion/XCode Projects/GraphicsTutorial/GraphicsTutorial/Shaders/colorShading.frag");
    _colorProgram.addAttribute("vertexPosition");
    _colorProgram.addAttribute("vertexColor");
    _colorProgram.addAttribute("vertexUV");
    _colorProgram.linkShaders();
}

void MainGame::gameLoop() {
    while (_gameState != GameState::EXIT) {
        float startTicks = SDL_GetTicks();
        
        processInput();
        _time += 0.05;
        drawGame();
        calculateFPS();
        
        static int frameCounter = 0;
        frameCounter++;
        if (frameCounter == 10) {
            printf("FPS: %.1f\n", _fps);
            frameCounter = 0;
        }
        
        float frameTicks = SDL_GetTicks() - startTicks;
        if (1000.0f / _maxFPS > frameTicks) {
            SDL_Delay(1000.0f / _maxFPS - frameTicks);
        }
    }
}

void MainGame::processInput() {
    SDL_Event ev;
    while (SDL_PollEvent(&ev)) {
        switch (ev.type) {
            case SDL_QUIT:
                _gameState = GameState::EXIT;
                break;
                
            case SDL_MOUSEMOTION:
                printf("x: %d y: %d\n", ev.motion.x, ev.motion.y);
                break;
        }
    }
}

void MainGame::drawGame() {
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    _colorProgram.use();
    
    glActiveTexture(GL_TEXTURE0);
    GLint textureLocation = _colorProgram.getUniformLocation("mySampler");
    glUniform1i(textureLocation, 0);
    
    GLint timeLocation = _colorProgram.getUniformLocation("time");
    glUniform1f(timeLocation, _time);
    
    for (int i = 0; i < _sprites.size(); i++) {
        _sprites[i]->draw();
    }
    
    glBindTexture(GL_TEXTURE_2D, 0);
    
    _colorProgram.unuse();
    
    SDL_GL_SwapWindow(_window);
}

void MainGame::calculateFPS() {
    static const int NUM_SAMPLES = 10;
    static float frameTimes[NUM_SAMPLES];
    static int currentFrame = 0;
    
    static float prevTicks = SDL_GetTicks();
    
    float currentTicks;
    currentTicks = SDL_GetTicks();
    
    _frameTime = currentTicks - prevTicks;
    
    frameTimes[currentFrame % NUM_SAMPLES] = _frameTime;
    
    prevTicks = currentTicks;
    
    int count;
    
    currentFrame++;
    if (currentFrame < NUM_SAMPLES) {
        count = currentFrame;
    }
    else {
        count = NUM_SAMPLES;
    }
    
    float frameTimeAverage = 0;
    for (int i = 0; i < count; i++) {
        frameTimeAverage += frameTimes[i];
    }
    frameTimeAverage /= count;
    
    if (frameTimeAverage > 0) {
        _fps = 1000.0f / frameTimeAverage;
    }
    else {
        _fps = 60.0f;
    }
}