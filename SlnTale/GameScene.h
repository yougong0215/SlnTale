#pragma once
#include "Scene.h"

class ArrowInstance;
class GameScene : public Scene
{
public:
	GameScene();
	virtual ~GameScene();

	void	Init() override;
	void	Update() override;
	void	Render() override;
	void	Release() override;


public:

	void Scenes();
	void SetMap();

public:
	ArrowInstance* ArrowSommon;

};

