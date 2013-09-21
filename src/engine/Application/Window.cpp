#include "engine/Application/Window.h"
#include "SDL2/SDL.h"
#include "engine/Application/Log.h"

namespace MageEngine
{
    Window::Window()
    {
        glEnabled = false;
        SetSize(800, 600);
        SetCaption("Untitled");
    }

    Window::Window(int32 Width, int32 Height, std::string caption, bool GL)
    {
        width = Width;
        height = Height;
        window = SDL_CreateWindow(caption.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
        SetCaption(caption.c_str());
    }

    Window::~Window()
    {

    }

    void Window::SetSize(int32 Width, int32 Height)
    {
        width = Width;
        height = Height;
        SDL_SetWindowSize(window, width, height);
    }

    void Window::SetCaption(std::string caption)
    {
        wndCaption = caption + " - MageEngine v" + MAGE_MAJOR_VERSION + "." + MAGE_MINOR_VERSION + "." + MAGE_PATCH_NUMBER + " - " + OSTYPE;
        SDL_SetWindowTitle(window, wndCaption.c_str());
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
