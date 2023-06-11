#include "Console.h"

#define STDOUTHND GetStdHandle(STD_OUTPUT_HANDLE)

void FullScreen()
{

	SetConsoleDisplayMode(
		STDOUTHND,
		CONSOLE_FULLSCREEN_MODE,
		NULL);

}

void Gotoxy(int x, int y)
{

	COORD cur = { x, y };

	SetConsoleCursorPosition(STDOUTHND, cur);

}

void GotoxyPlayer(int x, int y)
{
	COORD cur = { x * 2, y };

	SetConsoleCursorPosition(STDOUTHND, cur);

}

BOOL GotoxyTest(int x, int y)
{

	COORD cur = { x * 2, y };

	return SetConsoleCursorPosition(STDOUTHND, cur);

}

void Cursorset(bool visible, DWORD size)
{

	CONSOLE_CURSOR_INFO info;
	info.bVisible = visible;
	info.dwSize = size;

	SetConsoleCursorInfo(STDOUTHND, &info);

}

void SetColor(int color, int bgColor)
{

	SetConsoleTextAttribute(STDOUTHND, (bgColor << 4) | color);

}

int GetColor()
{

	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(STDOUTHND, &info);

	int color = info.wAttributes & 0xf;

	return color;

}

int GetBgColor()
{

	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(STDOUTHND, &info);

	int color = (info.wAttributes & 0xf) >> 4;

	return color;

}

void fontsize(UINT _weight, UINT _sizex, UINT _sizey)
{
	static CONSOLE_FONT_INFOEX font;
	font.cbSize = sizeof(font);
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hout, false, &font); //핸들, 최대창인지, 폰트
	font.FontWeight = _weight;
	font.dwFontSize.X = _sizex;
	font.dwFontSize.Y = _sizey;
	SetCurrentConsoleFontEx(hout, false, &font);
}