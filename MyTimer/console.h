#pragma once
#include <windows.h>

namespace CRBTimer {
	CONSOLE_CURSOR_INFO CursorInfo; 
	COORD coord;
	//移动控制台中的光标至指定位置，第一个参数为横坐标，第二个参数为纵坐标。  
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