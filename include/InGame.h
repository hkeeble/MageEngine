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
        void Update(InputState& inputState) override;
        void Render() override;
    private:
        void Initialize() override;
        void LoadContent() override;

        // Test Instances
        Image testImg;
        Image backgroundTest;
};

#endif
