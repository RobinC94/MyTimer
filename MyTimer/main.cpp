#include "MyTimer.h"
#include "console.h"
#include <iostream>
#include <conio.h>

using namespace CRBTimer;

int main(int argc, char *argv[])
{
	SetThreadAffinityMask(GetCurrentThread(), 0x01);    //�̶�ֻʹ��һ���߳�  
	FullScreen();
	bool LoopOn = true;
	MyTimer timer;
	char key = NULL;
	GotoXY(0, 2);
	SetColor(7);
	std::cout << "��ʱ��������Enter/�ո񡿿�ʼ/��ͣ������R�����㣬����Esc��������" << std::endl;
	while (LoopOn)
	{
		GotoXY(23, 12);
		SetColor(6);
		timer.Display();
		timer.GetStatus() != RUN || _kbhit() ? key = _getch() : key = NULL;
		switch (key)
		{
		case '\r':case '\n':case VK_SPACE:
			switch (timer.GetStatus())
			{
			case ZERO:case PAUSE:
				GotoXY(27, 10);
				SetColor(1);
				std::cout << "��ʱ������" << std::endl;
				timer.Start();
				SetCursorSize(1, 0);
				break;
			case RUN:
				GotoXY(27, 10);
				SetColor(1);
				std::cout << "��ͣ������" << std::endl;
				timer.Pause();
				SetCursorSize(16, 1);
				break;
			default:
				break;
			}
			break;
		case 'r':case 'R':
			GotoXY(27, 10);
			SetColor(1);
			std::cout << "���㡣����" << std::endl;
			timer.Pause();
			timer.Reset();
			SetCursorSize(16, 1);
			break;
		case VK_ESCAPE:
			GotoXY(27, 10);
			SetColor(1);
			std::cout << "���˳�������" << std::endl;
			timer.Pause();
			SetCursorSize(16, 1);
			LoopOn = false;
			break;
		default:
			if (timer.GetStatus() == RUN)
				timer.CalculateTime();
			break;
		}
	}
	putchar(10);
	Sleep(2000);
}