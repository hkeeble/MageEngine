#include "../include/image.h"
#include "GL/glew.h"
#include <SDL/SDL.h>

namespace MageEngine
{
    Image::Image()
    {

    }

    Image::~Image()
    {
        freeVBO();
    }

    void Image::freeVBO()
    {

    }

    Image::Image(Vector2 pos, Texture2D texture) : Entity(pos, Rect((int32)pos.x, (int32)pos.y, texture.width(), texture.height()))
    {
        // Initialize Vertex and Index buffer
        vBuffer = 0;
        iBuffer = 0;

        tex = texture;

        initVBO();
    }

    void Image::initVBO()
    {
        Vertex2D verts[4];
        GLuint indices[4];

        // Assign vertices
        verts[0] = Vertex2D(VertexPos2D(0, 0),
                            TexCoord(1.0f, 0.0f));
        verts[1] = Vertex2D(VertexPos2D((GLfloat)tex.width(), 0),
                            TexCoord(0.0f, 0.0f));
        verts[2] = Vertex2D(VertexPos2D((GLfloat)tex.width(), (GLfloat)tex.height()),
                            TexCoord(0.0f, 1.0f));
        verts[3] = Vertex2D(VertexPos2D(0, (GLfloat)tex.height()),
                            TexCoord(1.0f, 1.0f));

        // Initialize indices
        indices[0] = 0;
        indices[1] = 1;
        indices[2] = 2;
        indices[3] = 3;

        // Create VBO
        glGenBuffers(1, &vBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, vBuffer);
        glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex2D), verts, GL_STATIC_DRAW);

        // Create IBO
        glGenBuffers(1, &iBuffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iBuffer);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(GLuint), indices, GL_STATIC_DRAW);

        // Unbind Buffers
        glBindBuffer(GL_ARRAY_BUFFER, NULL);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);
    }

    void Image::render()
    {
        glBindTexture(GL_TEXTURE_2D, tex.TextureID());

        glEnableClientState(GL_VERTEX_ARRAY);
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);

            // Bind buffers
            glBindBuffer(GL_ARRAY_BUFFER, vBuffer);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iBuffer);

            // Assign pointers
            glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex2D), (GLvoid*)offsetof(Vertex2D, texCoord));
            glVertexPointer(2, GL_FLOAT, sizeof(Vertex2D), (GLvoid*)offsetof(Vertex2D, position));

            glDrawElements(GL_QUADS, 4, GL_UNSIGNED_INT, NULL);

        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    }
}
