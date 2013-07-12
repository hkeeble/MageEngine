#include "InGame.h"
#include "engine/Application/Content.h"

InGame::InGame()
{
    Initialize();
    LoadContent();
}

InGame::~InGame()
{

}

void InGame::Update(InputState& inputState)
{
    if(inputState.IsActionActive(ME_MOVE_DOWN))
        testImg.Move(Vector2(0, 1));
    if(inputState.IsActionActive(ME_MOVE_LEFT))
        testImg.Move(Vector2(-1, 0));
    if(inputState.IsActionActive(ME_MOVE_RIGHT))
        testImg.Move(Vector2(1, 0));
    if(inputState.IsActionActive(ME_MOVE_UP))
        testImg.Move(Vector2(0, -1));
}

void InGame::Render()
{
    FRect* r = new FRect(0, 0, 300, 300);

    backgroundTest.render(r);
    testImg.render(NULL);
}

void InGame::Initialize()
{

}

void InGame::LoadContent()
{
    Texture2D img = loadPNG("test");
    Texture2D backgroundImg = loadPNG("ground");

    Image im(Vector2(0, 0), img);

    testImg = im;
    backgroundTest = Image(Vector2(0, 0), backgroundImg);
}
