/*
/-------------------------------------------------------------------------------\
|                                   INPUTSTATE.CPP                              |
| Declaration of a general purpose SDL Input Handler by Henri Keeble.           |
\-------------------------------------------------------------------------------/
*/

#ifndef INPUTSTATE_H
#define INPUTSTATE_H

#include "SDL2/SDL.h"

namespace MageEngine
{
    class InputState
    {
        public:
            InputState();
            ~InputState();

            void Update();

            bool IsKeyPressed(SDL_Scancode scancode);
            bool IsKeyDown(SDL_Scancode scancode);
            bool IsKeyReleased(SDL_Scancode scancode);
            bool IsKeyUp(SDL_Scancode scancode);

            bool IsButtonDown(Uint32 button);
            bool IsButtonPressed(Uint32 button);
            bool IsButtonReleased(Uint32 button);

            bool HasQuit() const;

            int MouseX() const;
            int MouseY() const;

        private:
            SDL_Event event;

            const Uint8* prevKeyboardState;
            const Uint8* keyboardState;

            Uint32 prevMouseState;
            Uint32 mouseState;

            int mouseX, mouseY;

            bool quit;
    };
}
#endif
