#pragma once
#include "Scene.h"

class StartScene : public Scene
{
public:
	StartScene();
	virtual ~StartScene();
public:

	void	Init() override;
	void	Update() override;
	void	Render() override;
	void	Release() override;

public:
	void ViewMap();

private:
	int selectnum = 1;
	float updateTIme = 0.1f;
	float udpatecur = 0;
};

