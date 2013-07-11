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
#include "SDLTimer.h"

namespace MageEngine
{
    class MageGame
    {
        public:
            MageGame();
            MageGame(int32 wndWidth, int32 wndHeight, std::string wndCaption);
            ~MageGame();

            // Enters the main game loop
            void Run();

            Window window();
        private:
            Window wnd;
            bool running;

            // Initialization Functions
            bool SDLInit();
            void GLInit();
            void ILInit();

            // Timers used for regulating frame rate and update rate
            SDLTimer frameTimer;
            SDLTimer updateTimer;

            // Test Instances
            Image testImg;
            Image backgroundTest;

            // Used to represent and update the current input state
            InputState inputState;

            // Core game functions
            void Initialize();
            void LoadContent();
            void Update();
            void Render();
            void UnloadContent();
            void Exit();
    };
}
#endif
