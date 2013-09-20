#ifndef INPUTSTATE_H
#define INPUTSTATE_H

#include "SDL2/SDL.h"

namespace MageEngine
{
    enum InputAction
    {
        ME_QUIT,
        ME_MOVE_UP,
        ME_MOVE_DOWN,
        ME_MOVE_LEFT,
        ME_MOVE_RIGHT
    };

    struct Actions
    {
        void Clear();

        bool QUIT;
        bool MOVE_UP;
        bool MOVE_DOWN;
        bool MOVE_LEFT;
        bool MOVE_RIGHT;
    };
    struct Keys
    {
        void Default();

        SDL_Scancode MOVE_UP;

        SDLKey MOVE_UP;
        SDLKey MOVE_DOWN;
        SDLKey MOVE_LEFT;
        SDLKey MOVE_RIGHT;
    };

    class InputState
    {
        public:
            InputState();
            ~InputState();

            void Initialize();
            void AssignKeyToAction(SDLKey key, InputAction action);

            void Update();
            void Clear();

            bool IsActionActive(InputAction action);

        private:
            SDL_Event event;

            const Uint8* keyboardState;

            Actions actions;
            Keys keys;
    };
}
#endif
