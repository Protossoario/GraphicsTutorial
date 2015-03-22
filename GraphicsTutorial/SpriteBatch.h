//
//  SpriteBatch.h
//  GraphicsTutorial
//
//  Created by Eduardo Alberto Sanchez Alvarado on 3/21/15.
//  Copyright (c) 2015 Eduardo Alberto Sanchez Alvarado. All rights reserved.
//

#ifndef __GraphicsTutorial__SpriteBatch__
#define __GraphicsTutorial__SpriteBatch__

#include <OpenGL/gl3.h>
#include <glm.hpp>
#include <vector>
#include <algorithm>
#include "Vertex.h"

enum class GlyphSortType {
    NONE,
    FRONT_TO_BACK,
    BACK_TO_FRONT,
    TEXTURE
};

struct Glyph {
    GLuint texture;
    float depth;
    
    Vertex topLeft;
    Vertex bottomLeft;
    Vertex topRight;
    Vertex bottomRight;
};

class RenderBatch {
public:
    RenderBatch(GLuint Offset, GLuint NumVertices, GLuint Texture) : offset(Offset), numVertices(NumVertices), texture(Texture) {}
    
    GLuint offset;
    GLuint numVertices;
    GLuint texture;
};

class SpriteBatch {
public:
    SpriteBatch();
    
    void init();
    
    void begin(GlyphSortType sortType = GlyphSortType::TEXTURE);
    void end();
    
    void draw(const glm::vec4& destRect, const glm::vec4& uvRect, GLuint texture, float depth, const Color& color);
    
    void renderBatch();
    
private:
    void createRenderBatches();
    void createVertexArray();
    void sortGlyphs();
    
    static bool compareFrontToBack(Glyph* a, Glyph* b);
    static bool compareBackToFront(Glyph* a, Glyph* b);
    static bool compareTexture(Glyph* a, Glyph* b);
    
    GLuint _vbo;
    GLuint _vao;
    
    GlyphSortType _sortType;
    
    std::vector<Glyph*> _glyphs;
    std::vector<RenderBatch> _renderBatches;
};

#endif /* defined(__GraphicsTutorial__SpriteBatch__) */
