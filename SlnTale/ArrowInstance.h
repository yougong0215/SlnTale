#pragma once


enum class ArrowShot
{
	normal = 0,
	Sans1 = 1,
	Sans2 = 2,
};

struct ArrowInfo
{
public:
	ArrowInfo() {};
	ArrowInfo(Vector2 dir, float upTime, float lifeTime, ArrowMod ar, bool b = false, float nextTime = 0)
		: Direction(dir), UpdateTime(upTime), LifeTime(lifeTime), mode(ar), BlueMod(b)
	{

	}

	Vector2 Direction;
	float UpdateTime = 0;
	float LifeTime = 0;
	ArrowMod mode;
	bool BlueMod = false;
	
};

class ArrowInstance
{
public:
	ArrowInstance();
	~ArrowInstance();

	void Init();
	void Update();
	void Render();
	void Release();

public:
	void RandomSizeGet();

private:
	map<ArrowShot, ArrowInfo> Info;
	float currentTime = 0;
	float sommonTime = 5;
};

