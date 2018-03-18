#pragma once
#include <Windows.h>
#include <vector>

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
		void Display();
		TimerStatus GetStatus();

	protected:
		TimerStatus status;
		UINT _freq;
		LARGE_INTEGER _begin;
		LARGE_INTEGER _end;
		LONGLONG costTime;
		UINT days, hours, minutes, seconds, milliseconds, microseconds;
	};
}
