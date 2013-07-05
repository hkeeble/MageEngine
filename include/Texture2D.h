#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include <GL/glew.h>
#include "globals.h"

namespace MageEngine
{
    class Texture2D
    {
        public:
            Texture2D();
            ~Texture2D();

            void loadTexture(GLuint* Pixels, GLuint width, GLuint height);
            void clearTexture();

            int32 width() const;
            int32 height() const;
            GLuint TextureID() const;

        private:
            GLuint imgID;
            GLuint* pixels;
            int32 imgWidth, imgHeight;
            int32 texWidth, texHeight;
    };
}

#endif
