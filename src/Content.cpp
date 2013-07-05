#include "../include/Content.h"
#include "../include/Texture2D.h"
#include <IL/il.h>
#include <IL/ilu.h>

namespace MageEngine
{
    Texture2D loadPNG(std::string assetName)
    {
        Texture2D tex;

        assetName = "Content/" + assetName + ".png";

        ILuint imgID = 0;
        ilGenImages(1, &imgID);
        ilBindImage(imgID);

        ILboolean success = ilLoadImage(assetName.c_str());

        if(success == IL_TRUE)
        {
            success = ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
            if(success == IL_TRUE)
            {
                tex.loadTexture((GLuint*)ilGetData(), (GLuint)ilGetInteger(IL_IMAGE_WIDTH), (GLuint)ilGetInteger(IL_IMAGE_HEIGHT));
            }
        }

        ilClearImage();
        return tex;
    }
}
