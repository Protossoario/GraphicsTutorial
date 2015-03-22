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

class InputManager {
public:
    void pressKey(unsigned int keyID);
    void releaseKey(unsigned int keyID);
    bool isKeyPressed(unsigned int keyID);
    
private:
    std::unordered_map<unsigned int, bool> _keyMap;
};

#endif /* defined(__GraphicsTutorial__InputManager__) */
