//
//  ImageLoader.h
//  GraphicsTutorial
//
//  Created by Eduardo Alberto Sanchez Alvarado on 3/16/15.
//  Copyright (c) 2015 Eduardo Alberto Sanchez Alvarado. All rights reserved.
//

#ifndef __GraphicsTutorial__ImageLoader__
#define __GraphicsTutorial__ImageLoader__

#include <string>
#include <vector>
#include "GLTexture.h"
#include "IOManager.h"
#include "picoPNG.h"
#include "Errors.h"

class ImageLoader {
public:
    static GLTexture loadPNG(std::string filePath);
};

#endif /* defined(__GraphicsTutorial__ImageLoader__) */
