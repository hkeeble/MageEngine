#include "../include/Entity.h"

namespace MageEngine
{
    Entity::Entity()
    {
        boundingBox = Rect();
        position = Vector2();
    }

    Entity::~Entity()
    {

    }

    Entity::Entity(Vector2 Position, Rect BoundingBox)
    {
        position = Position;
        boundingBox = BoundingBox;
    }

    void Entity::Move(Vector2 offset)
    {
        position = position + offset;
    }

    Vector2 Entity::Position() const
    {
        return position;
    }

    Rect Entity::BoundingBox() const
    {
        return boundingBox;
    }

    void Entity::setPos(Vector2 newPos)
    {
        position = newPos;
    }

    void Entity::setBoundingBox(Rect newBox)
    {
        boundingBox = newBox;
    }
}
