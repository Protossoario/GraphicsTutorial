//
//  Vertex.h
//  GraphicsTutorial
//
//  Created by Eduardo Alberto Sanchez Alvarado on 3/15/15.
//  Copyright (c) 2015 Eduardo Alberto Sanchez Alvarado. All rights reserved.
//

#ifndef GraphicsTutorial_Vertex_h
#define GraphicsTutorial_Vertex_h

#include <OpenGL/gl3.h>

struct Position {
    float x;
    float y;
};

struct Color {
    GLubyte r;
    GLubyte g;
    GLubyte b;
    GLubyte a;
};

struct UV {
    float u;
    float v;
};

struct Vertex {
    Position position;
    Color color;
    UV uv;
    
    void setPosition(float x, float y) {
        position.x = x;
        position.y = y;
    }
    
    void setColor(GLubyte r, GLubyte g, GLubyte b, GLubyte a) {
        color.r = r;
        color.g = g;
        color.b = b;
        color.a = a;
    };
    
    void setUV(float u, float v) {
        uv.u = u;
        uv.v = v;
    }
};

#endif
