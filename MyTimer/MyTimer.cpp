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
	days = costTime * 1000000u / _freq;     //��Ϊ������ᱣ�浽 days �����У��˴���ֱ���� days �洢�м�����  
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
