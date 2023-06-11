
#include "stdafx.h"
#include "player.h"

#pragma comment(lib, "user32")
int main()
{

	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	float x = 0;
	player* p = new player(Vector2(10,10));

	p->Init();

	while (true)
	{
		p->Update();
		p->Render();
	}
}