//
//  Bullet.cpp
//  GraphicsTutorial
//
//  Created by Eduardo Alberto Sanchez Alvarado on 3/21/15.
//  Copyright (c) 2015 Eduardo Alberto Sanchez Alvarado. All rights reserved.
//

#include "Bullet.h"

Bullet::Bullet(glm::vec2 pos, glm::vec2 dir, float speed, int lifeTime) :
_position(pos),
_direction(dir),
_speed(speed),
_lifeTime(lifeTime)
{}

void Bullet::draw(SpriteBatch &spriteBatch) {
    glm::vec4 uv(0.0f, 0.0f, 1.0f, 1.0f);
    static GLTexture texture = ResourceManager::getTexture("/Users/EduardoS/Documents/Programacion/XCode Projects/GraphicsTutorial/GraphicsTutorial/Textures/CharacterRight_Standing.png");
    Color color;
    color.r = 255;
    color.g = 255;
    color.b = 255;
    color.a = 255;
    
    glm::vec4 rectangle(_position.x, _position.y, 30.0f, 30.0f);
    spriteBatch.draw(rectangle, uv, texture.textureId, 0.0f, color);
}

bool Bullet::update() {
    _position += _direction * _speed;
    
    _lifeTime--;
    
    if (_lifeTime == 0) {
        return true;
    }
    else {
        return false;
    }
}