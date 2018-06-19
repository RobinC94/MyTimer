#include <graphics.h>
#include <iostream>
#include <conio.h>

#include "MyTimer.h"
#include "console.h"

using namespace CRBTimer;

int main(int argc, char *argv[])
{
	
	bool loopOn = true;
	MyTimer timer;
	char key = NULL;

	Graphic::Create();

	while (loopOn)
	{
		timer.GetStatus() != RUN || _kbhit() ? key = _getch() : key = NULL;
		switch (key)
		{
		case '\r':case '\n':case VK_SPACE:
			switch (timer.GetStatus())
			{
			case ZERO:case PAUSE:
				timer.Start();
				break;
			case RUN:
				Graphic::AddRecord(timer.GetTime());
				timer.Reset();
				break;
			default:
				break;
			}
			break;

		case 'r':case 'R':
			timer.Pause();
			timer.Reset();
			Graphic::DeleteRecord();
			break;

		case VK_ESCAPE:
			timer.Pause();
			loopOn = false;
			break;

		default:
			if (timer.GetStatus() == RUN)
				timer.CalculateTime();
			break;
		}

		Graphic::Display(timer);
	}

	Graphic::Destroy();
	
	Sleep(1000);
}