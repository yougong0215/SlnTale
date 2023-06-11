#pragma once
#include<Windows.h>

enum class COLOR
{

	BLACK, BLUE, GREEN,
	SKYBLUE, RED, VIOLET,
	YELLOW, LIGHT_GTAY, GRAY,
	LIGHT_BLUE, LIGHT_GREEN,
	MINT, LIGHT_RED, LIGHT_VIOLET,
	LIGHT_YELLOW, WHITE

};
void FullScreen();
void Gotoxy(int, int);
void GotoxyPlayer(int x, int y);
BOOL GotoxyTest(int x, int y);
void Cursorset(bool, DWORD);
void SetColor(int color, int bgColor);
int GetColor();
int GetBgColor();
void fontsize(UINT _weight, UINT _sizex, UINT _sizey);