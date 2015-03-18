//
//  ResourceManager.h
//  GraphicsTutorial
//
//  Created by Eduardo Alberto Sanchez Alvarado on 3/17/15.
//  Copyright (c) 2015 Eduardo Alberto Sanchez Alvarado. All rights reserved.
//

#ifndef __GraphicsTutorial__ResourceManager__
#define __GraphicsTutorial__ResourceManager__

#include "TextureCache.h"
#include <string>

class ResourceManager {
public:
    static GLTexture getTexture(std::string texturePath);
    
private:
    static TextureCache _textureCache;
};

#endif /* defined(__GraphicsTutorial__ResourceManager__) */
