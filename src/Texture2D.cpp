#include "../include/Texture2D.h"
#include "../include/Log.h"
#include <GL/glew.h>
#include <il.h>

namespace MageEngine
{
Texture2D::Texture2D()
{

}

Texture2D::~Texture2D()
{
    clearTexture();
}

void Texture2D::loadTexture(GLuint* Pixels, GLuint width, GLuint height)
{
    clearTexture();

    texWidth = width;
    texHeight = height;

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
