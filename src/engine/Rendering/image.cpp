#include "engine/Rendering/image.h"
#include "GL/glew.h"
#include <SDL/SDL.h>

namespace MageEngine
{
    Image::Image()
    {
        // Initialize Vertex and Index buffer
        vBuffer = 0;
        iBuffer = 0;

        int i;
        for(i = 0; i < 4; i++)
            verts[i] = Vertex2D(VertexPos2D(0, 0), TexCoord(0, 0));
        for(i = 0; i < 4; i++)
            indices[i] = 0;
    }

    Image::~Image()
    {
        freeVBO();
    }

    Image::Image(const Image& param)
    {
        *(this) = cpy(param);
    }

    Image& Image::operator=(const Image& param)
    {
        if(this == &param)
            return *(this);
        else
            return cpy(param);
    }

    Image& Image::cpy(const Image& param)
    {
        tex = param.tex;

        initVBO();

        return *(this);
    }

    void Image::freeVBO()
    {
        glDeleteBuffers(1, &vBuffer);
        glDeleteBuffers(1, &iBuffer);
    }

    Image::Image(Vector2 pos, Texture2D texture) : Entity(pos, IRect((int32)pos.x, (int32)pos.y, texture.width(), texture.height()))
    {
        // Initialize Vertex and Index buffer
        vBuffer = 0;
        iBuffer = 0;

        tex = texture;

        initVBO();
    }

    void Image::initVBO()
    {
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
        glBufferData(GL_ARRAY_BUFFER, 4 * sizeof(Vertex2D), verts, GL_DYNAMIC_DRAW);

        // Create IBO
        glGenBuffers(1, &iBuffer);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iBuffer);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(GLuint), indices, GL_DYNAMIC_DRAW);

        // Unbind Buffers
        glBindBuffer(GL_ARRAY_BUFFER, NULL);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);
    }

    void Image::render(FRect* clip)
    {
        if(clip != NULL)
        {
            glBindBuffer(GL_ARRAY_BUFFER, vBuffer);

            verts[1].position = VertexPos2D(clip->width, 0);
            verts[2].position = VertexPos2D(clip->width, clip->height);
            verts[3].position = VertexPos2D(0, clip->height);

            GLfloat texLeft = clip->x / tex.width();
            GLfloat texRight = ( clip->x + clip->width ) / tex.width();
            GLfloat texTop = clip->y / tex.height();
            GLfloat texBottom = ( clip->y + clip->height ) / tex.height();

            verts[0].texCoord = TexCoord(texLeft, texTop);
            verts[1].texCoord = TexCoord(texRight, texTop);
            verts[2].texCoord = TexCoord(texRight, texBottom);
            verts[3].texCoord = TexCoord(texLeft, texBottom);

            glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(Vertex2D) * 4, verts);
        }
        else
            initVBO();

        glPushMatrix();
        glTranslatef(position.x, position.y, 0);

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

        // Unbind Buffers
        glBindBuffer(GL_ARRAY_BUFFER, NULL);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);

        glDisableClientState(GL_VERTEX_ARRAY);
        glDisableClientState(GL_TEXTURE_COORD_ARRAY);
        glPopMatrix();
    }
}
