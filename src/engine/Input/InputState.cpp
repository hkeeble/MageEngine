/*
/-------------------------------------------------------------------------------\
|                                   INPUTSTATE.CPP                              |
| Implementation of a general purpose SDL Input Handler by Henri Keeble.        |
\-------------------------------------------------------------------------------/
*/

#include "engine/Input/InputState.h"

namespace MageEngine
{
    // -- Constructor --
    InputState::InputState()
    {
        prevKeyboardState = new Uint8;
        keyboardState = new Uint8;
    }

    // -- Destructor --
    InputState::~InputState()
    {
        if(keyboardState != NULL)
            delete keyboardState;
        if(prevKeyboardState != NULL)
            delete prevKeyboardState;
    }

    // -- Update --
    void InputState::Update()
    {
        SDL_PollEvent(&event);

        if(event.type == SDL_QUIT)
            quit = true;
        else
        {
            prevKeyboardState = keyboardState;
            keyboardState = SDL_GetKeyboardState(NULL);

            prevMouseState = mouseState;
            mouseState = SDL_GetMouseState(&mouseX, &mouseY);
        }
    }

    // -- Input Tests --

    bool InputState::IsKeyPressed(SDL_Scancode scancode)
    {
        return (prevKeyboardState[scancode] == false) && (keyboardState[scancode] == true);
    }

    bool InputState::IsKeyDown(SDL_Scancode scancode)
    {
        return (prevKeyboardState[scancode] == true) && (keyboardState[scancode] == true);
    }

    bool InputState::IsKeyReleased(SDL_Scancode scancode)
    {
        return (prevKeyboardState[scancode] == true) && (keyboardState[scancode] == false);
    }

    bool InputState::IsKeyUp(SDL_Scancode scancode)
    {
        return ((prevKeyboardState[scancode] == false) && (keyboardState[scancode] == false)) || IsKeyReleased(scancode);
    }

    bool InputState::IsButtonDown(Uint32 button)
    {

    }

    bool InputState::IsButtonPressed(Uint32 button)
    {

    }

    bool InputState::IsButtonReleased(Uint32 button)
    {

    }

    bool InputState::HasQuit() const
    {
        return quit;
    }

    int InputState::MouseX() const
    {
        return mouseX;
    }

    int InputState::MouseY() const
    {
        return mouseY;
    }
}
