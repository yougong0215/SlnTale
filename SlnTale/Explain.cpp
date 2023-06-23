#include "stdafx.h"
#include "Explain.h"
#include "SceneManager.h"

Explain::Explain()
{
}

Explain::~Explain()
{
}

void Explain::Init()
{
	cur = 0;
}

void Explain::Update()
{
	cur += GET_SINGLE(Timer)->DeltaTime();
	if(cur > 0.1f)
		if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
			SceneManager::GetInstance().LoadScene(L"Start");
}

void Explain::Render()
{
	pos = new Vector2(110, 10);
	int i = 0;

	SceneManager::GetInstance().ScreenPrint(pos->x, pos->y, "�Ϲ� ���", COLOR::RED);
	SceneManager::GetInstance().ScreenPrint(pos->x, pos->y + (i += 2), "�̵� : WASD");
	SceneManager::GetInstance().ScreenPrint(pos->x, pos->y+ (i += 10), "�߷� ���", COLOR::BLUE);
	SceneManager::GetInstance().ScreenPrint(pos->x, pos->y + (i += 2), "�̵� : AS");
	SceneManager::GetInstance().ScreenPrint(pos->x, pos->y + (i+=2), "���� : W || Space");
	pos = new Vector2(110, 40);

	SceneManager::GetInstance().ScreenPrint(pos->x, pos->y, " ( ESC ) ���ư���");
}

void Explain::Release()
{
}
