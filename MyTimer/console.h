#pragma once
#include <graphics.h>
#include <list>

#include "MyTimer.h"

using std::list;

namespace CRBTimer {
	const int SCREEN_WIDTH = 1024;
	const int SCREEN_HEIGHT = 768;

	const int TITLE_LEFT = 10;
	const int TITLE_TOP = 10;
	const int TIME_LEFT = 10;
	const int TIME_TOP = 250;

	const int RESULT_LEFT = 100;
	const int RESULT_TOP = 500;

	static class Graphic
	{
	public:
		static void Create();
		static void Destroy();

		static void AddRecord(std::chrono::milliseconds timeRecord);
		static void DeleteRecord();

		static void Display(MyTimer timer);
		static void DisplayRecord();

	private:
		static char m_pArray[100];
		static list<UINT> record;
	};
}