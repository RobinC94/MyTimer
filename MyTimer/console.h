#pragma once
#include <windows.h>

namespace CRBTimer {
	CONSOLE_CURSOR_INFO CursorInfo; 
	COORD coord;
	//�ƶ�����̨�еĹ����ָ��λ�ã���һ������Ϊ�����꣬�ڶ�������Ϊ�����ꡣ  
	void GotoXY(int x, int y)
	{
		coord = { SHORT(x), SHORT(y) };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}

	void SetCursorSize(DWORD size, BOOL visible)
	{
		CursorInfo = { size, visible };
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CursorInfo);
	}
	
	void SetColor(int colorNum)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
	}

	void FullScreen()
	{
		DWORD dwNewMode = CONSOLE_FULLSCREEN_MODE;
		COORD coord = { 0 };
		SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), dwNewMode, &coord);
	}
}