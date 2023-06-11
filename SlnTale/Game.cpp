
#include "stdafx.h"
#include "player.h"
#include "SceneManager.h"


#pragma comment(lib, "user32")
int main()
{

	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

	SceneManager::GetInstance().Init();
	while (true)
	{
		SceneManager::GetInstance().Update();
		SceneManager::GetInstance().Render();
	}
}