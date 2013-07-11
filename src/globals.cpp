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

    Vertex2D::Vertex2D(const Vertex2D& param)
    {
        *(this) = cpy(param);
    }

    Vertex2D& Vertex2D::operator=(const Vertex2D& param)
    {
        if(this == &param)
            return *(this);
        else
            return cpy(param);
    }

    Vertex2D& Vertex2D::cpy(const Vertex2D& param)
    {
        position = param.position;
        texCoord = param.texCoord;
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

// -------- IRECT --------
    IRect::IRect()
    {
        x = 0;
        y = 0;
        width = 0;
        height = 0;
    }

    IRect::IRect(int32 X, int32 Y, int32 Width, int32 Height)
    {
        x = X;
        y = Y;
        width = Width;
        height = Height;
    }

    IRect::~IRect()
    {

    }

    bool IRect::intersect(IRect rec)
    {
        return intersect(FRect((GLfloat)rec.x, (GLfloat)rec.y, (GLfloat)rec.width, (GLfloat)rec.height));
    }

    bool IRect::intersect(FRect rec)
    {
        // INTERSECT LOGIC
    }

// -------- FRECT --------
    FRect::FRect()
    {
        x = 0.0f;
        y = 0.0f;
        width = 0.0f;
        height = 0.0f;
    }

    FRect::FRect(GLfloat X, GLfloat Y, GLfloat Width, GLfloat Height)
    {
        x = X;
        y = Y;
        width = Width;
        height = Height;
    }

    FRect::~FRect()
    {

    }

    bool FRect::intersect(FRect rec)
    {
        // INTERSECT LOGIC
    }

    bool FRect::intersect(IRect rec)
    {
        return intersect(FRect((GLfloat)rec.x, (GLfloat)rec.y, (GLfloat)rec.width, (GLfloat)rec.height));
    }

    // -------- COLOR --------
    Color::Color()
    {
        r = 0;
        g = 0;
        b = 0;
        a = 0;
    }

    Color::Color(GLubyte R, GLubyte G, GLubyte B, GLubyte A)
    {
        r = R;
        g = G;
        b = B;
        a = A;
    }

    Color::~Color()
    {

    }
}
