#pragma once

namespace MageEngine
{
	class SDLTimer
	{
		public:
			SDLTimer(void);
			~SDLTimer(void);
			void Start();
			void Stop();
			void Reset();
			float GetSeconds() const;
			int GetTicks() const;
			bool IsRunning() const;
			void Update();
		private:
			bool running;
			float startTime;
			float currentTime;
	};
}