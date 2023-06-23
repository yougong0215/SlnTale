#pragma once
#include "Scene.h"
class Explain : public Scene
{
public:

	Explain();
	virtual ~Explain();

public:

	void	Init() override;
	void	Update() override;
	void	Render() override;
	void	Release() override;

public:
	float cur = 0;
};

