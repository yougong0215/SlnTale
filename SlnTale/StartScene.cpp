#include "stdafx.h"
#include "StartScene.h"
#include "SceneManager.h"

StartScene::StartScene()
{
}

StartScene::~StartScene()
{
}

void StartScene::Init()
{
	pos = new Vector2(70, 3);
	b2.push_back(".----------------.  .----------------.  .-----------------. .----------------.  .----------------.  .----------------.  .----------------.");
	b2.push_back("| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |");
	b2.push_back("| |    _______   | || |   _____      | || | ____  _____  | || |  _________   | || |      __      | || |   _____      | || |  _________   | |");
	b2.push_back("| |   /  ___  |  | || |  |_   _|     | || ||_   \\|_   _| | || | |  _   _  |  | || |     /  \\     | || |  |_   _|     | || | |_   ___  |  | |");
	b2.push_back("| |  |  (__ \\_|  | || |    | |       | || |  |   \\ | |   | || | |_/ | | \\_|  | || |    / /\\ \\    | || |    | |       | || |   | |_  \\_|  | |");
	b2.push_back("| |   '.___`-.   | || |    | |   _   | || |  | |\\ \\| |   | || |     | |      | || |   / ____ \\   | || |    | |   _   | || |   |  _|  _   | |");
	b2.push_back("| |  |`\\____) |  | || |   _| |__/ |  | || | _| |_\\   |_  | || |    _| |_     | || | _/ /    \\ \\_ | || |   _| |__/ |  | || |  _| |___/ |  | |");
	b2.push_back("| |  |_______.'  | || |  |________|  | || ||_____|\\____| | || |   |_____|    | || ||____|  |____|| || |  |________|  | || | |_________|  | |");
	b2.push_back("| |              | || |              | || |              | || |              | || |              | || |              | || |              | |");
	b2.push_back("| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |");
	b2.push_back("'----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' ");

}

void StartScene::Update()
{
	GET_SINGLE(Timer)->Update();
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



}

void StartScene::Render()
{
	ViewMap();
}

void StartScene::Release()
{
}

void StartScene::ViewMap()
{
	pos = new Vector2(46, 7);
	int i, j;
	for (i = 0; i < b2.size(); i++)
	{

		SceneManager::GetInstance().ScreenPrint(pos->x, pos->y + i, b2[i]);

	}

	i = 0;
	pos = new Vector2(110, 40);

	SceneManager::GetInstance().ScreenPrint(pos->x, pos->y + i, " 게임 시작");
	i += 3;

	SceneManager::GetInstance().ScreenPrint(pos->x, pos->y + i, " 게임 설명");
	i += 3;

	SceneManager::GetInstance().ScreenPrint(pos->x, pos->y + i, " 게임 종료");
	i += 3;

	switch (selectnum)
	{
	case 1:
		SceneManager::GetInstance().ScreenPrint(pos->x, pos->y, ">");
		break;
	case 2:
		SceneManager::GetInstance().ScreenPrint(pos->x, pos->y + 3, ">");
		break;
	case 3:
		SceneManager::GetInstance().ScreenPrint(pos->x, pos->y + 6, ">");
		break;
	default:
		break;
	}

}


