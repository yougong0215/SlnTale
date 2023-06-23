#include "stdafx.h"
#include "GameOverScene.h"
#include "SceneManager.h"

GameOverScene::GameOverScene()
{
}

GameOverScene::~GameOverScene()
{
}

void GameOverScene::Init()
{
}

void GameOverScene::Update()
{
	udpatecur += GET_SINGLE(Timer)->DeltaTime();

	if (updateTIme < udpatecur)
	{
		if (GetAsyncKeyState(VK_UP) & 0x8000 ? 1 : 0)
		{
			if (selectnum > 1)
			{
				selectnum--;

			}
			udpatecur = 0;
		}



		if (GetAsyncKeyState(VK_DOWN) & 0x8000 ? 1 : 0)
		{
			if (selectnum < 3)
				selectnum++;
			udpatecur = 0;

		}


	}

	if (GetAsyncKeyState(VK_RETURN) & 0x8000 ? 1 : 0)
	switch (selectnum)
	{
	case 1:
		SceneManager::GetInstance().LoadScene(L"Game");
		break;
	case 2:
		SceneManager::GetInstance().GameEnd = true;
		//SceneManager::GetInstance().ScreenPrint(pos->x, pos->y + 6, ">");
		break;
	default:
		break;
	}
}

void GameOverScene::Render()
{
	ViewMap();
}

void GameOverScene::Release()
{
	v.clear();
	v2.clear();
	b2.clear();
}



void GameOverScene::ViewMap()
{
	pos = new Vector2(46, 7);
	int i, j;
	for (i = 0; i < b2.size(); i++)
	{

		SceneManager::GetInstance().ScreenPrint(pos->x, pos->y + i, b2[i]);

	}

	i = 0;
	pos = new Vector2(110, 40);

	string t = "버틴 시간 : " + to_string(SceneManager::GetInstance().GameTime);
	SceneManager::GetInstance().ScreenPrint(pos->x, pos->y + i, t);
	i += 3;
	SceneManager::GetInstance().ScreenPrint(pos->x, pos->y + i, "  게임 재 시작");
	i += 3;
	SceneManager::GetInstance().ScreenPrint(pos->x, pos->y + i, "  게임 종료");
	i += 3;


	switch (selectnum)
	{
	case 1:
		SceneManager::GetInstance().ScreenPrint(pos->x, pos->y + 3, "♥", COLOR::RED);
		break;
	case 2:
		SceneManager::GetInstance().ScreenPrint(pos->x, pos->y + 6, "♥", COLOR::RED);
		break;
		break;
	default:
		break;
	}

}