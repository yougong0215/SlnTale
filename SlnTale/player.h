#pragma once
#include "Object.h"

class player : Object
{
public:
	player();
	player(Vector2 pos);
	virtual ~player();

	void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

private:
	float speed = 0;
	float moveSpeed = 0.05f;
};

