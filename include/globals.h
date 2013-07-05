#ifndef GLOBALS_H
#define GLOBALS_H

#include <GL/glew.h>

namespace MageEngine
{
    // Define Engine Version
    #define MAGE_MAJOR_VERSION "0"
    #define MAGE_MINOR_VERSION "1"
    #define MAGE_PATCH_NUMBER "0"

    // Detect OS Type
    #ifdef _WIN32
    #define OSTYPE "Windows(32-bit)"
    #elif _WIN64
    #define OSTYPE "Windows (64-bit)"
    #elif __linux
    #define OSTYPE "Linux"
    #elif __unix
    #define OSTYPE "Unix"
    #el
    #define OSTYPE "Untested OS"
    #endif

    // Define platform-independent types
    #if INT_2_BYTE
    typedef char int8;
    typedef int int16;
    typedef long int32;
    #endif
    typedef char int8;
    typedef short int16;
    typedef int int32;

    // Define global structs
    struct VertexPos2D
    {
        VertexPos2D();
        VertexPos2D(GLfloat X, GLfloat Y);
        GLfloat x, y;
    };

    struct TexCoord
    {
        TexCoord();
        TexCoord(GLfloat S, GLfloat T);
        GLfloat s, t;
    };

    struct Vertex2D
    {
        Vertex2D();
        Vertex2D(VertexPos2D Position, TexCoord TextureCoord);
        VertexPos2D position;
        TexCoord texCoord;
    };

    struct Vector2
    {
        Vector2();
        Vector2(GLfloat X, GLfloat Y);
        ~Vector2();
        GLfloat x, y;
        int32 dot(Vector2 vec);

        Vector2& operator=(const Vector2& param);
        Vector2 operator+(Vector2 param) const;
        Vector2 operator-(Vector2 param) const;
    };

    struct Rect
    {
        Rect();
        Rect(int32 X, int32 Y, int32 Width, int32 Height);
        ~Rect();
        int32 x, y, width, height;
        bool intersect(Rect rec);
    };
}
#endif
