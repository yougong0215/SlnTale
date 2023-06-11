#include "stdafx.h"
#include "player.h"

player::player()
{
	position = new Vector2(0, 0);
	tag = Tag::None;
	_image = '♥';

	*newPosition = *position;
}

player::player(Vector2 pos)
{
	*position = pos;
	tag = Tag::None;
	_image = '♥';
	*newPosition = *position;
}



player::~player()
{
}

void player::Init()
{
}

void player::Update()
{
	Time.Update();
	speed += Time.DeltaTime();
	if (speed < moveSpeed)
		return;
	if (_kbhit())
	{

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			if(position->y > 0)
			newPosition->y-=1;
		}
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			if (position->x > 0)
			newPosition->x-=1;
		}
		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			if (position->x < WIDTHMAX)
			newPosition->x+=1;
		}
		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			if (position->y < HEIGHTMAX)
			newPosition->y+=1;
		}
		speed = 0;
	}
	

	
}

void player::Render()
{
	if (*newPosition == *position)
		return;

	Gotoxy(0, 0);
	cout << newPosition->x << ", " <<newPosition->y ;
	GotoxyPlayer(position->x, position->y);
	cout << "  ";
	GotoxyPlayer(newPosition->x, newPosition->y);
	SetColor((int)COLOR::RED, (int)COLOR::BLACK);
	cout << "♥";

	*position = *newPosition;
	 //전에 자리 지워주기
}

void player::Release()
{
	SAFE_DELETE(position);
}
