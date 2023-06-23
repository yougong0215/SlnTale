
#include "stdafx.h"
#include "player.h"
#include <ctime>
#include "SceneManager.h"
#include "StartScene.h"
#include "GameScene.h"

#pragma comment(lib, "user32")


int main()
{

	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	srand((unsigned)time(0));
	Cursorset(false, DWORD(1));
	SceneManager::GetInstance().RegisterScene(L"Start", make_shared<StartScene>());
	SceneManager::GetInstance().RegisterScene(L"Game", make_shared<GameScene>());
	SceneManager::GetInstance().LoadScene(L"Start");
	SceneManager::GetInstance().Init();
	while (true)
	{
		SceneManager::GetInstance().Update();
		SceneManager::GetInstance().Render();
	}
}