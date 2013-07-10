#include "../include/InputState.h"

namespace MageEngine
{
    InputState::InputState()
    {
        Initialize();
    }

    void InputState::AssignKeyToAction(SDLKey key, InputAction action)
    {
        switch(action)
        {
            case ME_MOVE_DOWN:
                keys.MOVE_DOWN = key;
                break;
            case ME_MOVE_UP:
                keys.MOVE_UP = key;
                break;
            case ME_MOVE_LEFT:
                keys.MOVE_LEFT = key;
                break;
            case ME_MOVE_RIGHT:
                keys.MOVE_RIGHT = key;
                break;
        }
    }

    void InputState::Initialize()
    {
        actions.Clear();
        keys.Default();
    }

    InputState::~InputState()
    {

    }

    void InputState::Clear()
    {
        actions.Clear();
    }

    void InputState::Update()
    {
            SDL_PollEvent(&event);

            if(event.type == SDL_QUIT)
                actions.QUIT = true;
            else
            {
                SDLKey key = event.key.keysym.sym;

                if(event.type == SDL_KEYDOWN)
                {
                    if(key == keys.MOVE_DOWN)
                        actions.MOVE_DOWN = true;
                    if(key == keys.MOVE_LEFT)
                        actions.MOVE_LEFT = true;
                    if(key == keys.MOVE_RIGHT)
                        actions.MOVE_RIGHT = true;
                    if(key == keys.MOVE_UP)
                        actions.MOVE_UP = true;
                }
                else if (event.type == SDL_KEYUP)
                {
                    if(key == keys.MOVE_DOWN)
                        actions.MOVE_DOWN = false;
                    if(key == keys.MOVE_LEFT)
                        actions.MOVE_LEFT = false;
                    if(key == keys.MOVE_RIGHT)
                        actions.MOVE_RIGHT = false;
                    if(key == keys.MOVE_UP)
                        actions.MOVE_UP = false;
                }
            }
    }

    bool InputState::IsActionActive(InputAction action)
    {
        switch(action)
        {
            case ME_QUIT:
                return actions.QUIT;
                break;
            case ME_MOVE_UP:
                return actions.MOVE_UP;
                break;
            case ME_MOVE_LEFT:
                return actions.MOVE_LEFT;
                break;
            case ME_MOVE_RIGHT:
                return actions.MOVE_RIGHT;
                break;
            case ME_MOVE_DOWN:
                return actions.MOVE_DOWN;
                break;
        };
    }

    void Actions::Clear()
    {
        QUIT = false;
        MOVE_UP = false;
        MOVE_LEFT = false;
        MOVE_RIGHT = false;
        MOVE_DOWN = false;
    }

    void Keys::Default()
    {
        MOVE_DOWN = SDLK_DOWN;
        MOVE_LEFT = SDLK_LEFT;
        MOVE_RIGHT = SDLK_RIGHT;
        MOVE_UP = SDLK_UP;
    }
}
