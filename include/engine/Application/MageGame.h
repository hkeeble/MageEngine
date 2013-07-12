#ifndef MAGE_GAME_H
#define MAGE_GAME_H

#include "Window.h"
#include <SDL/SDL.h>
#include <GL/glew.h>
#include <il.h>

#include "Log.h"
#include "../Rendering/image.h"
#include "Content.h"
#include "../Input/InputState.h"
#include "SDLTimer.h"
#include "GameState.h"

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

            void AddState(GameState* state);

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

            // Used to represent and update the current input state
            InputState inputState;

            // Game State Collection
            GameStateCollection gameStates;

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
