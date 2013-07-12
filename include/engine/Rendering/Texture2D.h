#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include <GL/glew.h>
#include "../globals.h"

namespace MageEngine
{
    class Texture2D
    {
        public:
            Texture2D();
            ~Texture2D();

            Texture2D(const Texture2D& param);
            Texture2D& operator=(const Texture2D& param);

            void loadTexture(GLuint* Pixels, GLuint width, GLuint height);
            void clearTexture();

            int32 width() const;
            int32 height() const;
            GLuint TextureID() const;

        private:
            Texture2D& cpy(const Texture2D& param);

            GLuint imgID;
            GLuint* pixels;
            int32 texWidth, texHeight;
    };
}

#endif
