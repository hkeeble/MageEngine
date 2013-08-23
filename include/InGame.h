#ifndef INGAME_H
#define INGAME_H

#include "engine/Application/GameState.h"
#include "engine/Rendering/image.h"

using namespace MageEngine;

class InGame: public GameState
{
    public:
        InGame();
        ~InGame();
        virtual void Update(InputState& inputState);
        virtual void Render();
    private:
        virtual void Initialize();
        virtual void LoadContent();

        // Test Instances
        Image testImg;
        Image backgroundTest;
};

#endif
