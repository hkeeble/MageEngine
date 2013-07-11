#include "../include/Entity.h"

namespace MageEngine
{
    Entity::Entity()
    {
        boundingBox = IRect();
        position = Vector2();
    }

    Entity::~Entity()
    {

    }

    Entity::Entity(Vector2 Position, IRect BoundingBox)
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

    IRect Entity::BoundingBox() const
    {
        return boundingBox;
    }

    void Entity::setPos(Vector2 newPos)
    {
        position = newPos;
    }

    void Entity::setBoundingBox(IRect newBox)
    {
        boundingBox = newBox;
    }
}
