//
//  Camera2D.cpp
//  GraphicsTutorial
//
//  Created by Eduardo Alberto Sanchez Alvarado on 3/21/15.
//  Copyright (c) 2015 Eduardo Alberto Sanchez Alvarado. All rights reserved.
//

#include "Camera2D.h"

Camera2D::Camera2D() : _position(0, 0), _cameraMatrix(1.0f), _orthoMatrix(1.0f), _scale(1.0f), _needsMatrixUpdate(true), _screenWidth(500), _screenHeight(500) {}

void Camera2D::init(int screenWidth, int screenHeight) {
    _screenWidth = screenWidth;
    _screenHeight = screenHeight;
    _orthoMatrix = glm::ortho(0.0f, (float)_screenWidth, 0.0f, (float)_screenHeight);
}

void Camera2D::update() {
    if (_needsMatrixUpdate) {
        glm::vec3 translate(_screenWidth / 2 - _position.x, _screenHeight / 2 - _position.y, 0.0f);
        _cameraMatrix = glm::translate(_orthoMatrix, translate);
        
        glm::vec3 scale(_scale, _scale, 0.0f);
        _cameraMatrix = glm::scale(glm::mat4(1.0f), scale) * _cameraMatrix;
        
        _needsMatrixUpdate = false;
    }
}