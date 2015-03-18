//
//  TextureCache.cpp
//  GraphicsTutorial
//
//  Created by Eduardo Alberto Sanchez Alvarado on 3/17/15.
//  Copyright (c) 2015 Eduardo Alberto Sanchez Alvarado. All rights reserved.
//

#include "TextureCache.h"

GLTexture TextureCache::getTexture(std::string texturePath) {
    auto mit = _textureMap.find(texturePath);
    
    if (mit == _textureMap.end()) {
        GLTexture newTexture = ImageLoader::loadPNG(texturePath);
        
        std::pair<std::string, GLTexture> newPair(texturePath, newTexture);
        
        _textureMap.insert(newPair);
        
        return newTexture;
    }
    
    // return the second element of the <string, GLTexture> pair
    return mit->second;
}