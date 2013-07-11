#include "../include/GameState.h"

namespace MageEngine
{
    // -------- GAMESTATE --------
    GameState::GameState()
    {
        enabled = false;
        id = (GameStateID)0;
    }

    GameState::GameState(GameStateID stateID)
    {
        enabled = false;
        id = stateID;
    }

    GameState::~GameState()
    {

    }

    GameState::GameState(const GameState& param)
    {
        enabled = param.enabled;
        id = param.id;
    }

    GameState& GameState::operator=(const GameState& param)
    {
        if(this == &param)
            return *(this);
        else
        {
            enabled = param.enabled;
            id = param.id;
            return *(this);
        }
    }

    GameStateID GameState::ID()
    {
        return id;
    }

    void GameState::Enable()
    {
        enabled = true;
    }

    void GameState::Disable()
    {
        enabled = false;
    }

    void GameState::Update()
    {

    }

    void GameState::Render()
    {

    }

    // -------- GAME STATE COLLECTION --------
    GameStateCollection::GameStateCollection()
    {
        states = std::vector<GameState>();
    }

    GameStateCollection::~GameStateCollection()
    {
        states.clear();
    }

    GameStateCollection::GameStateCollection(const GameStateCollection& param)
    {
        states = param.states;
    }

    GameStateCollection& GameStateCollection::operator=(const GameStateCollection& param)
    {
        if(this == &param)
            return *(this);
        else
        {
            states = param.states;
            return *(this);
        }
    }

    void GameStateCollection::AddState(GameState newState)
    {
        states.push_back(newState);
    }

    void GameStateCollection::RemoveState(GameStateID stateID)
    {
        std::vector<GameState>::iterator iter = srch(stateID);
        states.erase(iter);
    }

    void GameStateCollection::EnableState(GameStateID stateID)
    {
        std::vector<GameState>::iterator iter = srch(stateID);
        iter->Enable();
    }

    std::vector<GameState>::iterator GameStateCollection::srch(GameStateID stateID)
    {
        for(std::vector<GameState>::iterator iter = states.begin(); iter != states.end(); ++iter)
        {
            GameState state = *iter;
            if(state.ID() == stateID)
                return iter;
        }
    }
}
