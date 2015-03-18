//
//  IOManager.cpp
//  GraphicsTutorial
//
//  Created by Eduardo Alberto Sanchez Alvarado on 3/15/15.
//  Copyright (c) 2015 Eduardo Alberto Sanchez Alvarado. All rights reserved.
//

#include "IOManager.h"

bool IOManager::readFileToBuffer(std::string filePath, std::vector<unsigned char> &buffer) {
    // read file as binary data
    std::ifstream file(filePath, std::ios::binary);
    
    if (file.fail()) {
        perror(filePath.c_str());
        return false;
    }
    
    // seek the end of the file
    file.seekg(0, std::ios::end);
    // get file size
    long long fileSize = file.tellg();
    // seek the beginning of the file
    file.seekg(0, std::ios::beg);
    // reduce the file size by any header bytes that might be present
    fileSize -= file.tellg();
    
    buffer.resize(fileSize);
    
    file.read((char*)&(buffer[0]), fileSize);
    file.close();
    
    return true;
}