#include "stdafx.h"
#include "SceneManager.h"
#include "player.h"
#include <io.h>
#include <fcntl.h>
player::player()
{
	position = new Vector2(0, 0);
	tag = Tag::None;
	_image = '♥';
	newPosition = new Vector2(-1, -1);

}

player::player(Vector2 pos)
{
	*position = pos;
	tag = Tag::None;
	_image = '♥';
	newPosition = new Vector2(-1, -1);

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
	*newPosition = *position;
	if (GetAsyncKeyState(VK_SPACE) & 0x8000 ? 1 : 0)
		SetModify(PlayerMode::gravity);


	Vector2* vec = SceneManager::GetInstance().pos;

	Gravity(*vec);


	if (speed < moveSpeed)
		return;

	if (_kbhit())
	{

		switch (modify)
		{
		case PlayerMode::fly:
			if (GetAsyncKeyState(VK_UP) & 0x8000)
			{

				if (position->y > 0 && SceneManager::GetInstance().v[position->y - vec->y - 1][position->x - vec->x] == 0)
					newPosition->y -= 1;
			}
			if (GetAsyncKeyState(VK_LEFT) & 0x8000)
			{
				if (position->x > 0 && SceneManager::GetInstance().v[position->y - vec->y][position->x - vec->x - 1] == 0)
					newPosition->x -= 1;
			}
			if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			{
				if (position->x < WIDTHMAX && SceneManager::GetInstance().v[position->y - vec->y][position->x - vec->x + 1] == 0)
					newPosition->x += 1;
			}
			if (GetAsyncKeyState(VK_DOWN) & 0x8000)
			{
				if (position->y < HEIGHTMAX && SceneManager::GetInstance().v[position->y - vec->y + 1][position->x - vec->x] == 0)
					newPosition->y += 1;
			}

			break;
		case PlayerMode::gravity:

			if (GetAsyncKeyState(VK_UP) & 0x8000)
			{

				if (gravityInput < jumptime && position->y > 0 && SceneManager::GetInstance().v[position->y - vec->y - 1][position->x - vec->x] == 0)
				{
					newPosition->y -= 1;
				}
			}

			if (GetAsyncKeyState(VK_UP) & 0x8000 ? 0 : 1)
			{
				gravityInput = jumptime;
			}

			if (GetAsyncKeyState(VK_LEFT) & 0x8000)
			{
				if (position->x > 0 && SceneManager::GetInstance().v[position->y - vec->y][position->x - vec->x - 1] == 0)
					newPosition->x -= 1;
			}
			if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			{
				if (position->x < WIDTHMAX && SceneManager::GetInstance().v[position->y - vec->y][position->x - vec->x + 1] == 0)
					newPosition->x += 1;
			}

			break;
		default:
			break;
		}
		hp--;
		speed = 0;
	}


}

void player::Render()
{
	if (*newPosition == *position)
		return;
	if (*newPosition == Vector2(-1, -1))
	{
		*newPosition = *position;
	}
	//_setmode(_fileno(stdout), _O_U16TEXT);
	Gotoxy(0, 0);
	cout << "                       ";
	Gotoxy(0, 0);
	cout << newPosition->x << ", " << newPosition->y;
	GotoxyPlayer(position->x, position->y);
	cout << "  ";

	GotoxyPlayer(newPosition->x, newPosition->y);
	switch (modify)
	{
	case PlayerMode::fly:
		SetColor((int)COLOR::RED, (int)COLOR::BLACK);
		break;
	case PlayerMode::gravity:
		SetColor((int)COLOR::BLUE, (int)COLOR::BLACK);
		break;
	default:
		break;
	}
	cout << "♥";
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);

	*position = *newPosition;
	//전에 자리 지워주기

	Gotoxy(55, 57);
	cout << "┏━━━━━━━━━━━━━━━━┓" << endl;
	Gotoxy(55, 58);
	cout << "┃ HP : " << hp << "/"<< maxhp<< "\t┃" << endl;
	Gotoxy(55, 59);
	cout << "┗━━━━━━━━━━━━━━━━┛";
}

void player::Release()
{
	SAFE_DELETE(position);
}

void player::Gravity(Vector2& vec)
{
	if (PlayerMode::gravity == modify)
	{
		if (jumpinged == true)
		{
			gravitymove += Time.DeltaTime();
			gravityInput += Time.DeltaTime();
			if (gravitymove > gravitySpeed && gravityInput >= jumptime && position->y < HEIGHTMAX && SceneManager::GetInstance().v[position->y - vec.y + 1][position->x - vec.x] == 0)
			{
				gravitymove = 0;
				newPosition->y += 1;
			}
		}


		if (position->y < HEIGHTMAX && SceneManager::GetInstance().v[position->y - vec.y + 1][position->x - vec.x] == 0)
		{
			jumpinged = true;
		}
		else {
			jumpinged = false;
			gravityInput = 0;
		}

	}
}

void player::SetModify(PlayerMode mod)
{
	switch (mod)
	{
	case PlayerMode::fly:
		modify = mod;
		break;
	case PlayerMode::gravity:
		modify = mod;
		break;
	default:
		break;
	}
}
