#include "engine/Application/SDLTimer.h"
#include <SDL/SDL.h>

namespace MageEngine
{
	SDLTimer::SDLTimer(void)
	{
		running = false;
		startTime = 0;
		currentTime = 0;
	}


	SDLTimer::~SDLTimer(void)
	{

	}

	void SDLTimer::Start()
	{
		running = true;
		startTime = SDL_GetTicks();
	}

	void SDLTimer::Stop()
	{
		running = false;
	}

	void SDLTimer::Reset()
	{
		running = false;
		currentTime = 0;
		startTime = 0;
	}

	float SDLTimer::GetSeconds() const
	{
		return currentTime/10000; // 10000 ticks per second
	}

	int SDLTimer::GetTicks() const
	{
		return currentTime;
	}

	bool SDLTimer::IsRunning() const
	{
		return running;
	}

	void SDLTimer::Update()
	{
		if(running)
			currentTime = SDL_GetTicks() - startTime;
	}
}
