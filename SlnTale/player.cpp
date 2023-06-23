#include "stdafx.h"
#include "SceneManager.h"
#include "player.h"
#include <io.h>
#include <fcntl.h>
player::player()
	:Object()
{
	position = new Vector2(0, 0);
	tag = Tag::None;
	_image = '♥';
	newPosition = new Vector2(-1, -1);

}

player::player(Vector2 pos)
	:Object(pos)
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


	if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)

	{
		SceneManager::GetInstance().LoadScene(L"Over");
		return;
	}

	speed += GET_SINGLE(Timer)->DeltaTime();
	infintyTime -= GET_SINGLE(Timer)->DeltaTime();
	*newPosition = *position;
	//if (GetAsyncKeyState(VK_SPACE) & 0x8000 ? 1 : 0)
	//	SetModify(PlayerMode::gravity);


	static Vector2 vec = *SceneManager::GetInstance().pos();

	static Vector2 vec2 = *SceneManager::GetInstance().WH();

	Gravity(vec);


	if (speed < moveSpeed)
		return;

	if (_kbhit())
	{

		switch (modify)
		{
		case PlayerMode::fly:
			if (GetAsyncKeyState(VK_UP) & 0x8000)
			{

				if (position->y > 0 && SceneManager::GetInstance().v()[position->y - vec.y - 1][position->x - vec.x] == 0)
					newPosition->y -= 1;
			}
			if (GetAsyncKeyState(VK_LEFT) & 0x8000)
			{
				if (position->x > 0 && SceneManager::GetInstance().v()[position->y - vec.y][position->x - vec.x - 1] == 0)
					newPosition->x -= 1;
			}
			if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			{
				if (position->x < vec2.x + vec.x && SceneManager::GetInstance().v()[position->y - vec.y][position->x - vec.x + 1] == 0)
					newPosition->x += 1;
			}
			if (GetAsyncKeyState(VK_DOWN) & 0x8000)
			{
				if (position->y < HEIGHTMAX && SceneManager::GetInstance().v()[position->y - vec.y + 1][position->x - vec.x] == 0)
					newPosition->y += 1;
			}

			break;
		case PlayerMode::gravity:

			if ((GetAsyncKeyState(VK_UP) & 0x8000) || (GetAsyncKeyState(VK_SPACE) & 0x8000))
			{

				if (gravityInput < jumptime && position->y > 0 && SceneManager::GetInstance().v()[position->y - vec.y - 1][position->x - vec.x] == 0)
				{
					newPosition->y -= 1;
				}
			}

			if ((GetAsyncKeyState(VK_UP) & 0x8000) || (GetAsyncKeyState(VK_SPACE) & 0x8000) ? 0 : 1)
			{
				gravityInput = jumptime;
			}

			if (GetAsyncKeyState(VK_LEFT) & 0x8000)
			{
				if (position->x > 0 && SceneManager::GetInstance().v()[position->y - vec.y][position->x - vec.x - 1] == 0)
					newPosition->x -= 1;
			}
			if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
			{
				if (position->x < vec2.x + vec.x && SceneManager::GetInstance().v()[position->y - vec.y][position->x - vec.x + 1] == 0)
					newPosition->x += 1;
			}

			break;
		default:
			break;
		}

		speed = 0;
	}


}

void player::Render()
{
	if (hp <= 0)
	{

	}


		string a = "HP : ";
		a += to_string(hp);
		a += " / ";
		a += to_string(maxhp);
		SceneManager::GetInstance().ScreenPrint(55, 58, a);
	

	//if(infintyTime < 0)
	//if (*newPosition == *position)
	//	return;


	if (*newPosition == Vector2(-1, -1))
	{
		*newPosition = *position;
	}
	//_setmode(_fileno(stdout), _O_U16TEXT);
	//Gotoxy(0, 0);
	//cout << "                       ";
	//Gotoxy(0, 0);
	//cout << newPosition->x << ", " << newPosition->y;
	PlayerRender();
	//전에 자리 지워주기
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
			gravitymove += GET_SINGLE(Timer)->DeltaTime();
			gravityInput += GET_SINGLE(Timer)->DeltaTime();
			if (gravitymove > gravitySpeed && gravityInput >= jumptime && position->y < HEIGHTMAX && SceneManager::GetInstance().v()[position->y - vec.y + 1][position->x - vec.x] == 0)
			{
				gravitymove = 0;
				newPosition->y += 1;
			}
		}


		if (position->y < HEIGHTMAX && SceneManager::GetInstance().v()[position->y - vec.y + 1][position->x - vec.x] == 0)
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

void player::PlayerRender()
{

	switch (modify)
	{
	case PlayerMode::fly:
		SceneManager::GetInstance().ScreenPrint(newPosition->x, newPosition->y, "♥", COLOR::RED);

		break;
	case PlayerMode::gravity:
		SceneManager::GetInstance().ScreenPrint(newPosition->x, newPosition->y, "♥", COLOR::BLUE);
		break;
	default:
		break;
	}
	//SceneManager::GetInstance().ScreenPrint(newPosition->x, newPosition->y, "♥");

	*position = *newPosition;
}
