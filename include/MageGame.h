#ifndef MAGE_GAME_H
#define MAGE_GAME_H

#include "Window.h"
#include <SDL/SDL.h>
#include <GL/glew.h>
#include <il.h>

#include "Log.h"
#include "image.h"
#include "Content.h"
#include "InputState.h"

namespace MageEngine
{
    class MageGame
    {
        public:
            MageGame();
            MageGame(int32 wndWidth, int32 wndHeight, std::string wndCaption);
            ~MageGame();
            void Run();
            Window window();
        private:
            Window wnd;
            bool running;

            bool SDLInit();
            void GLInit();
            void ILInit();

            // Test Instances
            Image testImg;
            Image backgroundTest;

            InputState inputState;

            void Initialize();
            void LoadContent();
            void Update();
            void Render();
            void UnloadContent();
            void Exit();
    };
}
#endif
