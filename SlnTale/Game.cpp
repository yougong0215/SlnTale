
#include "stdafx.h"
#include "player.h"
#include <ctime>
#include "SceneManager.h"
#include "StartScene.h"
#include "GameScene.h"
#include "GameOverScene.h"
#include "Explain.h"
#pragma comment(lib, "user32")


int main()
{
	PlaySound(L"Sound/1.wav", 0, SND_FILENAME | SND_ASYNC); // 
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	srand((unsigned)time(0));
	Cursorset(false, DWORD(1));
	SceneManager::GetInstance().RegisterScene(L"Start", make_shared<StartScene>());
	SceneManager::GetInstance().RegisterScene(L"Game", make_shared<GameScene>());
	SceneManager::GetInstance().RegisterScene(L"Ex", make_shared<Explain>());
	SceneManager::GetInstance().RegisterScene(L"Over", make_shared<GameOverScene>());
	SceneManager::GetInstance().LoadScene(L"Start");
	SceneManager::GetInstance().Init();
	while (!SceneManager::GetInstance().GameEnd)
	{
		SceneManager::GetInstance().Update();
		SceneManager::GetInstance().Render();
	}
	SceneManager::GetInstance().Release();
}