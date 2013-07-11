#include "../include/Content.h"
#include "../include/Texture2D.h"
#include "../include/Log.h"
#include "../include/globals.h"
#include <il.h>
#include <ilu.h>

namespace MageEngine
{
    // Global transparent color
    Color TRANS_COLOR(255, 0, 255, 255);

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

            // Handle Transparency
            GLuint Size = (GLuint)ilGetInteger(IL_IMAGE_WIDTH)*(GLuint)ilGetInteger(IL_IMAGE_HEIGHT);
            GLuint* pixels = new GLuint[Size];
            pixels = (GLuint*)ilGetData();
            for(int i = 0; i < Size; i++)
            {
                GLubyte* colors = (GLubyte*)&pixels[i];

                if(colors[0] == TRANS_COLOR.r && colors[1] == TRANS_COLOR.g && colors[2] == TRANS_COLOR.b && colors[3] != 0)
                {
                    colors[0] = 255;
                    colors[1] = 255;
                    colors[2] = 255;
                    colors[3] = 0;
                }
            }

            if(success == IL_TRUE)
                tex.loadTexture(pixels, (GLuint)ilGetInteger(IL_IMAGE_WIDTH), (GLuint)ilGetInteger(IL_IMAGE_HEIGHT));
        }
        else
        {
            log("ERROR: FILE '");
            log(assetName);
            log("' COULD NOT BE FOUND!");
        }

        ilClearImage();
        return tex;
    }
}
