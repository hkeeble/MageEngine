#include "engine/Application/MageGame.h"

namespace MageEngine
{
    MageGame::MageGame(int32 wndWidth, int32 wndHeight, std::string wndCaption)
    {
        log("Initializing SDL...\n");
        if(SDLInit() == false)
            printf("Failed to initialize SDL.\n");

        log("Initializing Window...\n");
        wnd = Window(wndWidth, wndHeight, wndCaption, true);

        log("Initializing OpenGL...\n");
        GLInit();

        log("Initializing DevIL...\n");
        ILInit();

        running = false;

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

    }

    void MageGame::AddState(GameState* state)
    {
        gameStates.AddState(state);
    }

    void MageGame::Update()
    {
        updateTimer.Start();
        inputState.Update();

        if(inputState.HasQuit())
            Exit();

        for(std::vector<GameState*>::iterator iter = gameStates.States()->begin(); iter != gameStates.States()->end(); ++iter)
        {
            GameState* state = *iter;

            if(state->IsEnabled())
                state->Update(inputState);
        }

        if(updateTimer.GetTicks() < 1000 / FPS)
            SDL_Delay((1000 / FPS) - updateTimer.GetTicks());

        updateTimer.Stop();
        updateTimer.Reset();
    }

    void MageGame::Render()
    {
        frameTimer.Start();

        // Clear Screen
        glClear(GL_COLOR_BUFFER_BIT);

        for(std::vector<GameState*>::iterator iter = gameStates.States()->begin(); iter != gameStates.States()->end(); ++iter)
        {
            GameState* state = *iter;

            if(state->IsEnabled())
                state->Render();
        }

        // Swap Buffers
        SDL_GL_SwapWindow(wnd.window);

        if(frameTimer.GetTicks() < 1000 / FPS)
            SDL_Delay((1000 / FPS) - frameTimer.GetTicks());

        frameTimer.Stop();
        frameTimer.Reset();
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
        if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
        {
            printf("Failed to initialize SDL. Check error log for more information.");
            log("FAILED TO INITIALIZE SDL: ");
            log(SDL_GetError());
            log("\n");
            return false;
        }

        return true;
    }

    void MageGame::GLInit()
    {
        SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3 );
		SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );
		SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE );

        glContext = SDL_GL_CreateContext(wnd.window);

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

        // Enable Blending
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        // Disable Depth
        glDisable(GL_DEPTH_TEST);

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
