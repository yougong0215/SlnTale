#pragma once
#include "Object.h"



enum class ArrowModify
{
	Up = 1,
	Left = 2,
	Right = 3,
	Down = 4,
	UpLeft = 5,
	UpRight = 6,
	DownLeft = 7,
	DownRight = 8,


	LeftUPWall	= 'a',
	UpWall		= 'b',
	RightUPWall = 'c',
	LeftWall	= 'd',
	LeftDownWall= 'e',
	RightDownWall='f'
};

class Arrow : Object
{
public:
	Arrow();
	Arrow(Vector2 pos);
	Arrow(Vector2 pos, Tag tag);
	Arrow(Vector2 pos, Tag tag, float moveSpeed, Vector2 dir);
	Arrow(Vector2 pos, Tag tag, float moveSpeed, Vector2 dir, int Damaged = 100, float LifeTime = 2.0f, ArrowMod moded = ArrowMod::normal);
	virtual ~Arrow();

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;


	wstring SetArrowModify(ArrowMod mod);

	void SetPosition(Vector2 vec) override
	{
		*position = vec;
	}
	Vector2 GetPosition() override
	{
		return *position;
	}

	void SetDirection(Vector2 vec)
	{
		dir = vec;
	}

public:
	Vector2 dir;
	double speed = 0;
	float moveSpeed = 0.2f;

	int damage = 100;

	float LifeTime = 2.0f;
	
	bool Attacked = false;
	ArrowMod mod;
	vector<vector<int>> v;
	vector<int> v2;
};

