#include "../include/globals.h"

namespace MageEngine
{

 // -------- VERTEXPOS2D --------
    VertexPos2D::VertexPos2D()
    {
        x = 0.0f;
        y = 0.0f;
    }

    VertexPos2D::VertexPos2D(GLfloat X, GLfloat Y)
    {
        x = X;
        y = Y;
    }

// -------- TEXCOORD --------
    TexCoord::TexCoord()
    {
        s = 0;
        t = 0;
    }

    TexCoord::TexCoord(GLfloat S, GLfloat T)
    {
        s = S;
        t = T;
    }

// -------- VERTEX2D --------
    Vertex2D::Vertex2D()
    {
        position = VertexPos2D();
        texCoord = TexCoord();
    }

    Vertex2D::Vertex2D(VertexPos2D Position, TexCoord TextureCoord)
    {
        position = Position;
        texCoord = TextureCoord;
    }

// -------- VECTOR2 --------
    Vector2::Vector2()
    {
        x = 0;
        y = 0;
    }

    Vector2::Vector2(GLfloat X, GLfloat Y)
    {
        x = X;
        y = Y;
    }

    Vector2::~Vector2()
    {

    }

    int32 Vector2::dot(Vector2 vec)
    {
        return (x * vec.x) + (y * vec.y);
    }

    Vector2 Vector2::operator+(Vector2 param) const
    {
        return Vector2(param.x + x, param.y + y);
    }

    Vector2 Vector2::operator-(Vector2 param) const
    {
        return Vector2(param.x - x, param.y - y);
    }

    Vector2& Vector2::operator=(const Vector2& param)
    {
        if(this == &param)
            return *this;
        else
        {
            x = param.x;
            y = param.y;
        }

        return *this;
    }

// -------- RECT --------
    Rect::Rect()
    {
        x = 0;
        y = 0;
        width = 0;
        height = 0;
    }

    Rect::Rect(int32 X, int32 Y, int32 Width, int32 Height)
    {
        x = X;
        y = Y;
        width = Width;
        height = Height;
    }

    Rect::~Rect()
    {

    }

    bool Rect::intersect(Rect rec)
    {
        // INTERSECTS LOGIC
    }
}
