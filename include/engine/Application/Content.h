#ifndef CONTENT_H
#define CONTENT_H

#include <GL/glew.h>
#include <string>
#include "../Rendering/Texture2D.h"

namespace MageEngine
{
    Texture2D loadPNG(std::string assetName);
}

#endif
