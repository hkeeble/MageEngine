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

            Image(const Image& param);
            Image& operator=(const Image& param);

            void render(FRect* clip);

        private:
            Image& cpy(const Image& param);
            void initVBO();
            void freeVBO();

            Texture2D tex;
            Vertex2D verts[4];
            GLuint indices[4];
            GLuint vBuffer;
            GLuint iBuffer;
    };
}

#endif
