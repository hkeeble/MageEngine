#include "engine/Rendering/Texture2D.h"
#include "engine/Application/Log.h"
#include <GL/glew.h>
#include <il/il.h>

namespace MageEngine
{
    Texture2D::Texture2D()
    {
        pixels = NULL;
    }

    Texture2D::~Texture2D()
    {
        clearTexture();
    }

    Texture2D::Texture2D(const Texture2D& param)
    {
        *this = cpy(param);
    }

    Texture2D& Texture2D::operator=(const Texture2D& param)
    {
        if(this == &param)
            return *(this);
        else
            return cpy(param);
    }

    Texture2D& Texture2D::cpy(const Texture2D& param)
    {
            glBindTexture(GL_TEXTURE_2D, param.imgID);
            pixels = new GLuint[param.width() * param.height()];
            glGetTexImage(GL_TEXTURE_2D, 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

            glGenTextures(1, &imgID);
            glBindTexture(GL_TEXTURE_2D, imgID);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, param.width(), param.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, pixels);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glBindTexture(GL_TEXTURE_2D, NULL);

            texWidth = param.width();
            texHeight = param.height();

            return *(this);
    }

    void Texture2D::loadTexture(GLuint* Pixels, GLuint width, GLuint height)
    {
        clearTexture();

        texWidth = width;
        texHeight = height;

        // Deep copy pixels
        pixels = new GLuint[texWidth * texHeight];
        for(int i = 0; i < (texWidth*texHeight); i++)
            pixels[i] = Pixels[i];

        glGenTextures(1, &imgID);
        glBindTexture(GL_TEXTURE_2D, imgID);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, Pixels);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

        glBindTexture(GL_TEXTURE_2D, NULL);

        ILenum error = glGetError();
        if(error != GL_NO_ERROR)
        {
            printf("Error loading texture from %p pixels! See log for more info.\n", pixels);
            log("ERROR LOADING TEXTURE FROM PIXELS: ");
            log((char*)gluErrorString(error));
        }
    }

    void Texture2D::clearTexture()
    {
        glDeleteTextures(1, &imgID);

        if(pixels != NULL)
            delete [] pixels;
    }

    int32 Texture2D::width() const
    {
        return texWidth;
    }

    int32 Texture2D::height() const
    {
        return texHeight;
    }

    GLuint Texture2D::TextureID() const
    {
        return imgID;
    }
}
