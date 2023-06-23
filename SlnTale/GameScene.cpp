#include "stdafx.h"
#include "GameScene.h"
#include "Scene.h"
#include "player.h"

#include "SceneManager.h"
#include "ArrowManager.h"

GameScene::GameScene()
{
}

GameScene::~GameScene()
{
}

void GameScene::Init()
{

	SetMap();
	Scenes();
	Vector2 vec = *WH / 2;
	vec += *pos;
	_player = new player(vec);
	GetPlayer()->Init();
	GET_SINGLE(Timer)->Init();
	GET_SINGLE(ArrowManager)->Init();

	Vector2 posed = *pos;
	posed.x -= 50;
	//GET_SINGLE(ArrowManager)->NormalArrowSommon(posed, Vector2(1, 0), 0.05f, 100, 60, ArrowMod::WaSans);
	//posed.x += 20;
	GET_SINGLE(ArrowManager)->NormalArrowSommon(posed, Vector2(1, 0), 0.1f, 100, 60, ArrowMod::WaSans);
	posed.x -= 120;
	GET_SINGLE(ArrowManager)->NormalArrowSommon(posed, Vector2(1, 0), 0.1f, 100, 60, ArrowMod::SAS);
}

void GameScene::Update()
{

	GET_SINGLE(ArrowManager)->Update();
	GetPlayer()->Update();
	//man->Update();
}
 
void GameScene::Render()
{

	Scenes();
	GET_SINGLE(ArrowManager)->Render();
	GetPlayer()->Render();
}

void GameScene::Release()
{
	SAFE_DELETE(_player);
	SAFE_DELETE(pos);
	SAFE_DELETE(WH);
}

void GameScene::Scenes()
{
	pos = new Vector2(70, 3);
	int i, j;
	for (i = 0; i < b2.size(); i++)
	{

		SceneManager::GetInstance().ScreenPrint(pos->x, pos->y + i, b2[i]);

	}


	pos = new Vector2(20, 32);
	for (i = 0; i < v.size(); i++)
	{
		for (j = 0; j < v[i].size(); j++)
		{
			switch ((walls)v[i][j])
			{
			case walls::LeftUP:
				SceneManager::GetInstance().ScreenPrint(pos->x + pos->x + j, pos->y + i, "¦®");
				break;
			case walls::Up:
				SceneManager::GetInstance().ScreenPrint(pos->x + pos->x + j, pos->y + i, "¦¬");
				break;
			case walls::RightUP:
				SceneManager::GetInstance().ScreenPrint(pos->x + pos->x + j, pos->y + i, "¦¯");
				break;
			case walls::Left:
				SceneManager::GetInstance().ScreenPrint(pos->x + pos->x + j, pos->y + i, "¦­");
				break;
			case walls::LeftDown:
				SceneManager::GetInstance().ScreenPrint(pos->x + pos->x + j, pos->y + i, "¦±");
				break;
			case walls::RightDown:
				SceneManager::GetInstance().ScreenPrint(pos->x + pos->x + j, pos->y + i, "¦°");
				break;
			default:
				//ScreenPrint(pos->x + pos->x + j, pos->y + i, "  ");
				break;
			}
		}
		SceneManager::GetInstance().ScreenPrint(pos->x + pos->x + j, pos->y + i, "\n");
	}

	pos->x *= 2;

}

void GameScene::SetMap()
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

	ifstream bg("Tete.txt");
	if (bg.is_open())
	{
		while (getline(bg, line))
		{
			b2.push_back(line);
		}
		//b.push_back(b2);
	}
}
