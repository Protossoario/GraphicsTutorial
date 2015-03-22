//
//  Bullet.h
//  GraphicsTutorial
//
//  Created by Eduardo Alberto Sanchez Alvarado on 3/21/15.
//  Copyright (c) 2015 Eduardo Alberto Sanchez Alvarado. All rights reserved.
//

#ifndef __GraphicsTutorial__Bullet__
#define __GraphicsTutorial__Bullet__

#include <glm.hpp>
#include "SpriteBatch.h"
#include "GLTexture.h"
#include "ResourceManager.h"

class Bullet {
public:
    Bullet(glm::vec2 pos, glm::vec2 dir, float speed, int lifeTime);
    
    void draw(SpriteBatch& spriteBatch);
    bool update();
    
private:
    int _lifeTime;
    float _speed;
    glm::vec2 _direction;
    glm::vec2 _position;
};

#endif /* defined(__GraphicsTutorial__Bullet__) */
