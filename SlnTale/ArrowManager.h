#pragma once
#include "Arrow.h"
#include <list>

class ArrowManager
{
	DECLARE_SINGLE(ArrowManager);

public:
	void Init();
	void Update();
	void Render();
	void Release();

	void NormalArrowSommon(Vector2 vec, Vector2 dir, float moveSpeed = 0.05f, int damaged = 100, float LifeTime = 2.0f, ArrowMod md = ArrowMod::normal);
public:
	list<shared_ptr<Arrow>> _arrowed;

};

