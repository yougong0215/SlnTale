#pragma once
#include "Scene.h"

class GameOverScene : public Scene
{
public:
	GameOverScene();
	virtual	~GameOverScene();

	void	Init() override;
	void	Update() override;
	void	Render() override;
	void	Release() override;

	void ViewMap();

private:
	int selectnum = 1;
	float updateTIme = 0.1f;
	float udpatecur = 0;

};

