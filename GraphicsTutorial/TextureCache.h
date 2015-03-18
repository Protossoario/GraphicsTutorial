//
//  TextureCache.h
//  GraphicsTutorial
//
//  Created by Eduardo Alberto Sanchez Alvarado on 3/17/15.
//  Copyright (c) 2015 Eduardo Alberto Sanchez Alvarado. All rights reserved.
//

#ifndef __GraphicsTutorial__TextureCache__
#define __GraphicsTutorial__TextureCache__

#include <map>
#include <string>
#include "GLTexture.h"
#include "ImageLoader.h"
#include "Errors.h"

class TextureCache {
public:
    GLTexture getTexture(std::string);
    
private:
    std::map<std::string, GLTexture> _textureMap;
};

#endif /* defined(__GraphicsTutorial__TextureCache__) */
