#include "stdafx.h"
#include "player.h"
#include "SceneManager.h"
#include "ArrowManager.h"
///┏━━━━━━━━━━━━━━━━━━━━━┓ 
///┃                     ┃
///┃                     ┃
///┃                     ┃
///┃                     ┃
///┃                     ┃
///┃                     ┃
///┃                     ┃
///┃                     ┃
///┃                     ┃
///┃                     ┃
///┃                     ┃
///┃                     ┃
///┃                     ┃
///┃                     ┃
///┃                     ┃
///┗━━━━━━━━━━━━━━━━━━━━━┛

//4444444444444444444444444444444444444444444444444444444444444444444444
//4444444444444444444444444444444444444444444444444444444444444444444444
//4444444444444444444444444444444444444444444444444444444444444444444444
//4444444444444444444444444444444444444444444444444444444444444444444444
//4444444444444444444444444444444444444444444444444444444444444444444444
//0000044444444444444400000000004444400000000000044444400000000000000000
//0000000444444444440000000000004444400000000000004444000000000000000000
//0000000004444444000000000000000000000000000000004444000000000000000000
//0000000000000000000000000000000000000000000000004444000000000000000000
//0000000000000000000000000000000000000000000000004444000000000000000000
//0000000000000000000000000000000000000010000000004444000000000000000000
//0000000000000000000000000000000000000010000000004444000000000000000000
//0000000000000000000000000000000000000011000000004444000000000000000000
//0000000000000000000000000000000000000011000000004444000000000000000000
//0000000000001000000000000000000000000011000000000000000000000000000000
//0000000000011110000000000000000000000011000000000000000000000000000000
//0000000001111111100000000000000000000111100000000000000111000000000000
//0000000011111111110000000000000000000111100000000000000111000000000000
//1111111111111111111111111111111111111111111111111111111111111111111111
//1111111111111111111111111111111111111111111111111111111111111111111111
//1111111111111111111111111111111111111111111111111111111111111111111111
//1111111111111111111111111111111111111111111111111111111111111111111111
//1111111111111111111111111111111111111111111111111111111111111111111111


#define _CRT_SECURE_NO_WARNINGS
void SceneManager::Init()
{
	CONSOLE_CURSOR_INFO cci;

	g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	// 커서를 숨긴다.
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(g_hScreen[0], &cci);
	SetConsoleCursorInfo(g_hScreen[1], &cci);

	SetMap();
	Scenes();
	Vector2 vec = *WH / 2;
	vec += *pos;
	_player = new player(vec);
	_player->Init();
	GET_SINGLE(Timer)->Init();
	GET_SINGLE(ArrowManager)->Init();

	Vector2 posed = *pos;
	posed.x -= 10;
	//GET_SINGLE(ArrowManager)->NormalArrowSommon(posed, Vector2(1, 0), 0.005f, 100, 60, ArrowMod::WaSans);
	posed.x += 20;
	GET_SINGLE(ArrowManager)->NormalArrowSommon(posed, Vector2(-1, 0), 0.2f, 100, 600, ArrowMod::WaSans);
	
}

void SceneManager::Update()
{
	GET_SINGLE(Timer)->Update();
	GET_SINGLE(ArrowManager)->Update();
	_player->Update();
	rendering += GET_SINGLE(Timer)->DeltaTime();
	//man->Update();
}

void SceneManager::Render()
{

	if (renderSpeed < rendering)
	{
		GET_SINGLE(ArrowManager)->Render();
		_player->Render();
		rendering = 0;
	}
	//Scenes();

	//ScreenClear();

	//if(renderSpeed < rendering) // 출력 코드
	//{
	//	g_numOfFPS = g_numOfFrame;
	//	g_numOfFrame = 0;
	//}
	//sprintf_s(FPSTextInfo, 128, "FPS : %d", g_numOfFPS);
	//ScreenPrint(0, 0, FPSTextInfo);
	//g_numOfFrame++;

	//ScreenFlipping();

	//man->Render();
	//Scenes();

}

void SceneManager::Release()
{
}

void SceneManager::Scenes()
{
	pos = new Vector2(20, 32);
	int i, j;
	for (i = 0; i < v.size(); i++)
	{
		Gotoxy(pos->x + pos->x + 1, pos->y + i);
		for (j = 0; j < v[i].size(); j++)
		{
			switch ((walls)v[i][j])
			{
			case walls::LeftUP:
				cout << "┏";
				break;
			case walls::Up:
				cout << "━━";
				break;
			case walls::RightUP:
				cout << "┓";
				break;
			case walls::Left:
				cout << "┃";
				break;
			case walls::LeftDown:
				cout << "┗";
				break;
			case walls::RightDown:
				cout << "┛";
				break;
			default:
				cout << "  ";
				break;
			}
		}
		cout << endl;
	}
}


void SceneManager::SetMap()
{
	string line;
	ifstream file("map1.txt");
	int t = 0;
	if (file.is_open())
	{
		while (getline(file, line))
		{
			for (int i = 0; i < line.size(); i++) 
			{
				v2.push_back(line[i] - '0');
			}
			t++;
			v.push_back(v2);
			v2.clear();
		}
		WH = new Vector2(line.size(), t);
	}
}
