#include "engine/Application/Window.h"
#include "SDL/SDL.h"

namespace MageEngine
{
    Window::Window()
    {
        SetSize(800, 600);
        SetCaption("Untitled");
    }

    Window::Window(int32 Width, int32 Height, std::string caption)
    {
        SetSize(Width, Height);
        SetCaption(caption);
    }

    Window::~Window()
    {

    }

    void Window::SetSize(int32 Width, int32 Height)
    {
        width = Width;
        height = Height;
        SDL_SetVideoMode(width, height, 32, SDL_OPENGL);
    }

    void Window::SetCaption(std::string caption)
    {
        wndCaption = caption + " - MageEngine v" + MAGE_MAJOR_VERSION + "." + MAGE_MINOR_VERSION + "." + MAGE_PATCH_NUMBER + " - " + OSTYPE;
        SDL_WM_SetCaption(wndCaption.c_str(), NULL);
    }

    int32 Window::Height(void)
    {
        return height;
    }

    int32 Window::Width(void)
    {
        return width;
    }
}
