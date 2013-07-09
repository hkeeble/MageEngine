#include "../include/MageGame.h"

namespace MageEngine
{
    MageGame::MageGame(int32 wndWidth, int32 wndHeight, std::string wndCaption)
    {
        log("Initializing SDL...\n");
        if(SDLInit() == false)
            printf("Failed to initialize SDL.\n");

        log("Initializing OpenGL...\n");
        GLInit();

        log("Initializing DevIL...\n");
        ILInit();

        running = false;

        log("Initializing Window...\n");
        wnd = Window(wndWidth, wndHeight, wndCaption);

        log("Initializing Input State...\n");
        inputState = InputState();
    }

    MageGame::~MageGame()
    {

    }

    void MageGame::Run()
    {
        running = true;

        Initialize();

        if(running)
            LoadContent();

        while(running == true)
        {
            Update();
            Render();
        }

        UnloadContent();
        log("Ending game context...\n");
    }

    void MageGame::Initialize()
    {

    }

    void MageGame::LoadContent()
    {
        log("Loading game content...\n");

        Texture2D img = loadPNG("test");
        testImg = Image(Vector2(0, 0), img);
    }

    void MageGame::Update()
    {
        inputState.Update();

        if(inputState.IsActionActive(ME_QUIT))
            Exit();

        if(inputState.IsActionActive(ME_MOVE_DOWN))
            log("Down button pressed!\n");
    }

    void MageGame::Render()
    {
        // Clear Screen
        glClear(GL_COLOR_BUFFER_BIT);

        testImg.render();


        // Swap Buffers
        SDL_GL_SwapBuffers();
    }

    void MageGame::UnloadContent()
    {
        log("Unloading game content...\n");
    }

    void MageGame::Exit()
    {
        running = false;
        log("Exit called...\n");
    }

    bool MageGame::SDLInit()
    {
        if(SDL_Init(SDL_INIT_AUDIO) == -1)
        {
            printf("Failed to initialize SDL_AUDIO. Check error log for more information.");
            log("FAILED TO INITIALIZE SDL_AUDIO: ");
            log(SDL_GetError());
            log("\n");
            return false;
        }

        if(SDL_Init(SDL_INIT_EVENTTHREAD) == -1)
        {
            printf("Failed to initialize SDL_EVENTTHREAD. Check error log for more information.");
            log("FAILED TO INITIALIZE SDL_EVENTTHREAD: ");
            log(SDL_GetError());
            log("\n");
            return false;
        }

        if(SDL_Init(SDL_INIT_TIMER) == -1)
        {
            printf("Failed to initialize SDL_TIMER. Check error log for more information.");
            log("FAILED TO INITIALIZE SDL_TIMER: ");
            log(SDL_GetError());
            log("\n");
            return false;
        }

        if(SDL_Init(SDL_OPENGL) == -1)
        {
            printf("Failed to initialize SDL_OPENGL. Check error log for more information.");
            log("FAILED TO INITIALIZE SDL_OPENGL: ");
            log(SDL_GetError());
            log("\n");
            return false;
        }

        SDL_SetVideoMode(wnd.Width(), wnd.Height(), 32, SDL_OPENGL);

        return true;
    }

    void MageGame::GLInit()
    {

        log("Initializing GLEW...\n");
        GLenum glewErr = glewInit();
        if(glewErr != GLEW_OK)
        {
            printf(("Failed to initialize GLEW. Check log for more information."));
            log("FAILED TO INITIALIZE GLEW: ");
            log((char*)glewGetErrorString(glewErr));
            log("\n");
        }

        log("GLEW Version: ");
        log((char*)glewGetString(GLEW_VERSION));
        log("\n");

        log("OpenGL Context Version: ");
        log((char*)glGetString(GL_VERSION));
        log("\n");
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, wnd.Width(), wnd.Height(), 0, 0, 32);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // Enable Texturing
        glEnable(GL_TEXTURE_2D);

        // Set Clear Color
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

        // Set Draw Color
        glColor3f(1.0f, 1.0f, 1.0f);

        GLenum err = glGetError();
        if(err != GL_NO_ERROR)
        {
            printf("Error initializing OpenGL! See log for more information.");
            log("ERROR INITIALIZING OPENGL: ");
            log((char*)glGetString(err));
            log("\n");
        }
    }

    void MageGame::ILInit()
    {
        ilInit();

        ILenum err = ilGetError();
        if(err != IL_NO_ERROR)
        {
            printf(("Failed to initialize DevIL. Check log for more information."));
            log("FAILED TO INITIALIZE DEVIL: ");
            log(ilGetString(err));
            log("\n");
        }

        log("DevIL version: ");
        log(ilGetString(IL_VERSION_NUM));
        log("\n");
    }
}
