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

public:
	void Gravity(Vector2& vec);
	void SetModify(PlayerMode mod);

private:
	float speed = 0;

	int hp = 1000;
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

