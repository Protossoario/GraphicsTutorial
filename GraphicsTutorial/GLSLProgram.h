//
//  GLSLProgram.h
//  GraphicsTutorial
//
//  Created by Eduardo Alberto Sanchez Alvarado on 3/1/15.
//  Copyright (c) 2015 Eduardo Alberto Sanchez Alvarado. All rights reserved.
//

#ifndef __GraphicsTutorial__GLSLProgram__
#define __GraphicsTutorial__GLSLProgram__

#include <OpenGL/gl3.h>
#include <fstream>
#include <string>
#include <vector>
#include "Errors.h"

class GLSLProgram {
public:
    GLSLProgram();
    ~GLSLProgram();
    
    void compileShaders(const std::string& vertexShaderFilePath, const std::string& fragmentShaderFilePath);
    void linkShaders();
    void addAttribute(const std::string& attributeName);
    void use();
    void unuse();
    
    GLint getUniformLocation(const std::string& uniformName);
    
private:
    int _numAttributes;
    
    void compileShader(const std::string& filePath, const GLuint shaderID);
    
    GLuint _programID;
    
    GLuint _vertexShaderID;
    GLuint _fragmentShaderID;
};

#endif /* defined(__GraphicsTutorial__GLSLProgram__) */
