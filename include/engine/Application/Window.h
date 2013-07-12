#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include "../globals.h"

namespace MageEngine
{
    class Window
    {
        public:
            Window(void);
            Window(int32 Width, int32 Height, std::string caption);
            ~Window(void);

            void SetCaption(std::string caption);
            void SetSize(int32 Width, int32 Height);

            int32 Width(void);
            int32 Height(void);
        private:
            int32 width, height;
            std::string wndCaption;

    };
}

#endif
