//
//  MainGame.h
//  GraphicsTutorial
//
//  Created by Eduardo Alberto Sanchez Alvarado on 3/1/15.
//  Copyright (c) 2015 Eduardo Alberto Sanchez Alvarado. All rights reserved.
//

#ifndef __GraphicsTutorial__MainGame__
#define __GraphicsTutorial__MainGame__

#include <SDL2/SDL.h>
#include <OpenGL/glu.h>
#include <OpenGL/gl3.h>
#include <vector>
#include "Errors.h"
#include "Sprite.h"
#include "GLSLProgram.h"

enum class GameState { PLAY, EXIT };

class MainGame {
public:
    MainGame();
    ~MainGame();
    
    void run();
    
private:
    void initSystems();
    void initShaders();
    void gameLoop();
    void processInput();
    void drawGame();
    void calculateFPS();
    
    SDL_Window* _window;
    int _screenWidth;
    int _screenHeight;
    GameState _gameState;
    
    std::vector<Sprite*> _sprites;
    Sprite _sprite;
    
    GLSLProgram _colorProgram;
    
    float _fps;
    float _maxFPS;
    float _frameTime;
    
    float _time;
};

#endif /* defined(__GraphicsTutorial__MainGame__) */
