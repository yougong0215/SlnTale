
#include "stdafx.h"
#include "player.h"
#include <ctime>
#include "SceneManager.h"

#pragma comment(lib, "user32")


int main()
{

	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	Cursorset(false, DWORD(1));
	SceneManager::GetInstance().Init();
	while (true)
	{
		SceneManager::GetInstance().Update();
		SceneManager::GetInstance().Render();
	}
}