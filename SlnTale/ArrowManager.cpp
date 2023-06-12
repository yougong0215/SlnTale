#include "stdafx.h"
#include "ArrowManager.h"
#include "Arrow.h"

void ArrowManager::Init()
{
	//_arrowed.clear();
}

void ArrowManager::Update()
{
	int i = 0;
	list<shared_ptr<Arrow>>::iterator iter;
	for (iter = _arrowed.begin(); iter != _arrowed.end();)
	{
		GotoxyPlayer(0, 10);
		cout << i++;
		(*iter)->Update();

		if ((*iter)->LifeTime < 0)
		{
			(*iter)->Release();
			iter = _arrowed.erase(iter);
			if (iter != _arrowed.begin())
				--iter; // 이전 원소로 반복자를 이동시킴
		}
		else
		{
			++iter; // 다음 원소로 반복자를 이동시킴
		}
	}
}

void ArrowManager::Render()
{
	list<shared_ptr<Arrow>>::iterator iter;
	for (iter = _arrowed.begin(); iter != _arrowed.end(); ++iter)
	{
		(*iter)->Render();


	}
}

void ArrowManager::Release()
{
	if (_arrowed.empty())
		return;
	list<shared_ptr<Arrow>>::iterator iter;
	for (iter = _arrowed.begin(); iter != _arrowed.end(); ++iter)
	{
		(*iter)->Release();
	}
}

void ArrowManager::NormalArrowSommon(Vector2 vec, Vector2 dir, float moveSpeed, int damaged, float LifeTime, ArrowMod md)
{
	// 88 50
	shared_ptr<Arrow> pt = make_shared<Arrow>(vec, Tag::Arrow, moveSpeed, dir, damaged, LifeTime, md);
	pt->Init();
	_arrowed.push_back(pt);
	
}
