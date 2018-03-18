#include "MyTimer.h"
using namespace CRBTimer;

MyTimer::MyTimer()
{
	LARGE_INTEGER tmp;
	QueryPerformanceFrequency(&tmp);
	_freq = static_cast<int>(tmp.QuadPart);
	costTime = 0;
	days = hours = minutes = seconds = milliseconds = microseconds = 0u;
	status = ZERO;
}

void MyTimer::Start()
{
	if (status == RUN)
		return;
	status = RUN;
	QueryPerformanceCounter(&_begin);
}

void MyTimer::Pause()
{
	status = PAUSE;
	CalculateTime();

}

void MyTimer::Reset()
{
	status = ZERO;
	costTime = 0;
	microseconds = milliseconds = seconds = minutes = hours = days = 0;
}

void MyTimer::CalculateTime()
{
	QueryPerformanceCounter(&_end);
	costTime += _end.QuadPart - _begin.QuadPart;
	_begin = _end;
	days = costTime * 1000000u / _freq;     //因为最后结果会保存到 days 变量中，此处可直接用 days 存储中间结果。  
	microseconds = days % 1000u;
	milliseconds = (days /= 1000u) % 1000u;
	seconds = (days /= 1000u) % 60u;
	minutes = (days /= 60u) % 60u;
	hours = (days /= 60u) % 24u;
	days = days / 24u;
}

void MyTimer::Display()
{
	printf_s("%2d:%02d\'%02d\"%03d%03d", hours, minutes, seconds,
		milliseconds, microseconds);
}

TimerStatus MyTimer::GetStatus()
{
	return status;
}
