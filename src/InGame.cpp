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
