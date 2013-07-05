#ifndef IMAGE_H
#define IMAGE_H

#include "Texture2D.h"
#include "Entity.h"

namespace MageEngine
{
    class Image : public Entity
    {
        public:
            Image();
            Image(Vector2 pos, Texture2D texture);
            ~Image();

            void render();

        private:
            Texture2D tex;

            Vertex2D verts[4];

            void initVBO();
            void freeVBO();

            GLuint indices[4];
            GLuint vBuffer;
            GLuint iBuffer;
    };
}

#endif
