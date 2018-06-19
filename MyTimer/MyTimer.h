#pragma once
#include <chrono>

namespace CRBTimer {
	enum TimerStatus
	{
		ZERO,
		RUN,
		PAUSE
	};

	class MyTimer
	{
	public:
		
		MyTimer();
		void Start();
		void Pause();
		void Reset();
		void CalculateTime();
		std::chrono::milliseconds GetTime();
		TimerStatus GetStatus();

	private:
		std::chrono::time_point<std::chrono::system_clock> m_start;
		std::chrono::milliseconds m_time;
		TimerStatus m_status;
		std::chrono::milliseconds m_storeTime;
		
	};
}
