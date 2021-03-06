#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>
#include "../Input/InputState.h"

namespace MageEngine
{
    enum GameStateID
    {
        MENU,
        INGAME
    };

    class GameState
    {
        public:
            GameState();
            GameState(GameStateID stateID);
            ~GameState();

            GameState(const GameState& param);
            GameState& operator=(const GameState& param);

            void Enable();
            void Disable();
            bool IsEnabled() const;

            GameStateID ID();

            virtual void Update(InputState& inputState);
            virtual void Render();

        private:
            GameStateID id;
            bool enabled;

            virtual void Initialize();
            virtual void LoadContent();
    };

    class GameStateCollection
    {
        public:
            GameStateCollection();
            ~GameStateCollection();

            GameStateCollection(const GameStateCollection& param);
            GameStateCollection& operator=(const GameStateCollection& param);

            void AddState(GameState* newState);
            void RemoveState(GameStateID stateID);
            void EnableState(GameStateID stateID);

            std::vector<GameState*>* States();

        private:
            std::vector<GameState*> states;

            std::vector<GameState*>::iterator srch(GameStateID stateID);
    };
}

#endif
