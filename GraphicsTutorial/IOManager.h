//
//  IOManager.h
//  GraphicsTutorial
//
//  Created by Eduardo Alberto Sanchez Alvarado on 3/15/15.
//  Copyright (c) 2015 Eduardo Alberto Sanchez Alvarado. All rights reserved.
//

#ifndef __GraphicsTutorial__IOManager__
#define __GraphicsTutorial__IOManager__

#include <vector>
#include <string>
#include <fstream>

class IOManager {
public:
    static bool readFileToBuffer(std::string filePath, std::vector<unsigned char>& buffer);
};

#endif /* defined(__GraphicsTutorial__IOManager__) */
