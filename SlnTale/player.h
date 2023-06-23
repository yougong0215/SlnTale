#pragma once
#include "Object.h"

enum class PlayerMode
{
	fly = 0,
	gravity = 1
};

class player : Object
{
public:
	player();
	player(Vector2 pos);
	virtual ~player();

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;


	void SetPosition(Vector2 vec) override
	{
		*position = vec;
	}
	Vector2 GetPosition() override
	{
		return *position;
	}

	void Damaged(int t)
	{
		if (infintyTime < 0)
		{
			infintyTime = baseInfintime;
			hp -= t;
		}
	}

public:
	void Gravity(Vector2& vec);
	void SetModify(PlayerMode mod);
	void PlayerRender();
	int GetHP()
	{
		return hp;
	}
private:
	float speed = 0;

	float infintyTime = 0.4f;
	float baseInfintime = 0.4f;

	int hp = 1000;
	int oldhp = -1;
	int maxhp = 1000;


	float moveSpeed = 0.05f;

	float gravitymove = 0;
	float gravitySpeed = 0.045f;
	float jumptime = 0.6f;
	float gravityInput = 0;

	float jumpSpeed = 0.5f;
	bool jumpinged = false;
	PlayerMode modify = PlayerMode::fly;
};

