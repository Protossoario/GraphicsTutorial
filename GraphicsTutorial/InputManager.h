//
//  InputManager.h
//  GraphicsTutorial
//
//  Created by Eduardo Alberto Sanchez Alvarado on 3/21/15.
//  Copyright (c) 2015 Eduardo Alberto Sanchez Alvarado. All rights reserved.
//

#ifndef __GraphicsTutorial__InputManager__
#define __GraphicsTutorial__InputManager__

#include <unordered_map>
#include <glm.hpp>

class InputManager {
public:
    InputManager();
    
    void pressKey(unsigned int keyID);
    void releaseKey(unsigned int keyID);
    bool isKeyPressed(unsigned int keyID);
    void setMouseCoords(float x, float y);
    
    glm::vec2 getMouseCoords() const { return _mouseCoords; }
    
private:
    std::unordered_map<unsigned int, bool> _keyMap;
    glm::vec2 _mouseCoords;
};

#endif /* defined(__GraphicsTutorial__InputManager__) */
