#ifndef ENTITY_H
#define ENTITY_H

#include "Texture2D.h"
#include "globals.h"

namespace MageEngine
{
    class Entity
    {
        public:
            Entity();
            Entity(Vector2 Position, IRect BoundingBox);
            ~Entity();

            Vector2 Position() const;
            IRect BoundingBox() const;

            void setPos(Vector2 newPos);
            void Move(Vector2 offset);

            void setBoundingBox(IRect newBox);

        protected:
            Vector2 position;
            IRect boundingBox;
    };
}

#endif
