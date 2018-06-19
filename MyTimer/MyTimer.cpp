#include "MyTimer.h"

CRBTimer::MyTimer::MyTimer()
{
	m_status = ZERO;
	m_storeTime = std::chrono::milliseconds(0);
}

void CRBTimer::MyTimer::Start()
{
	if (m_status == RUN)
		return;
	m_start = std::chrono::system_clock::now();
	m_status = TimerStatus::RUN;
}

void CRBTimer::MyTimer::Pause()
{
	m_status = PAUSE;
	CalculateTime();
	m_storeTime = m_time;
}

void CRBTimer::MyTimer::Reset()
{
	m_status = ZERO;
	m_time = std::chrono::milliseconds(0);
	m_storeTime = std::chrono::milliseconds(0);
}

void CRBTimer::MyTimer::CalculateTime()
{
	auto thisTP = std::chrono::system_clock::now();
	m_time = std::chrono::duration_cast<decltype(m_time)>(thisTP - m_start) + m_storeTime;
}

std::chrono::milliseconds CRBTimer::MyTimer::GetTime()
{
	return m_time;
}

CRBTimer::TimerStatus CRBTimer::MyTimer::GetStatus()
{
	return m_status;;
}
