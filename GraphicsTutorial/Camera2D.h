//
//  Camera2D.h
//  GraphicsTutorial
//
//  Created by Eduardo Alberto Sanchez Alvarado on 3/21/15.
//  Copyright (c) 2015 Eduardo Alberto Sanchez Alvarado. All rights reserved.
//

#ifndef __GraphicsTutorial__Camera2D__
#define __GraphicsTutorial__Camera2D__

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

class Camera2D {
public:
    Camera2D();
    
    void init(int screenWidth, int screenHeight);
    
    void update();
    
    glm::vec2 convertScreenToWorld(glm::vec2 screenCoords);
    
    // setters
    void setPosition(glm::vec2 newPosition) { _position = newPosition; _needsMatrixUpdate = true; }
    void setScale(float newScale) { _scale = newScale; _needsMatrixUpdate = true; }
    
    // getters
    glm::vec2 getPosition() { return _position; }
    float getScale() { return _scale; }
    glm::mat4 getCameraMatrix() { return _cameraMatrix; }
    
private:
    bool _needsMatrixUpdate;
    int _screenWidth, _screenHeight;
    float _scale;
    glm::vec2 _position;
    glm::mat4 _cameraMatrix;
    glm::mat4 _orthoMatrix;
};

#endif /* defined(__GraphicsTutorial__Camera2D__) */
