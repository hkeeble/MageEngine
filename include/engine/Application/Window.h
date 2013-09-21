#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <SDL2/SDL.h>
#include "../globals.h"

namespace MageEngine
{
    class Window
    {
        public:
            Window(void);
            Window(int32 Width, int32 Height, std::string caption, bool GL);
            ~Window(void);

            void SetCaption(std::string caption);
            void SetSize(int32 Width, int32 Height);

            int32 Width(void);
            int32 Height(void);

            SDL_Window* window;

        private:
            bool glEnabled;

            int32 width, height;
            std::string wndCaption;
    };
}

#endif
