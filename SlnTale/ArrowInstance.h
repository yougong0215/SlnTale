#pragma once
#include <functional>

enum class ArrowShot
{
	Rain = 0,
	Sans1 = 1,
	Sans2 = 2,
	UP= 3,
	Right = 4,
	Miro = 5
};

//struct ArrowInfo
//{
//public:
//	ArrowInfo() {}
//	ArrowInfo(Vector2 dir, float upTime, float lifeTime, ArrowMod ar, bool b = false, float nextTime = 0)
//		: Direction(dir), UpdateTime(upTime), LifeTime(lifeTime), mode(ar), BlueMod(b)
//	{
//
//	}
//	~ArrowInfo(){}
//
//	Vector2 Direction;
//	float UpdateTime = 0;
//	float LifeTime = 0;
//	ArrowMod mode;
//	bool BlueMod = false;
//	
//};
//


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
	Vector2 GetRandomDirection();
	void ArrowRain();

	void ArrowRainUP();

	void ArrowRainRight();

	void SansPatton1();

	void SansPatton2();

	void ArrowMiro();

private:
	std::map<ArrowShot, std::function<void()>> Info;
	float currentTime = 0;
	float sommonTime = 5;
};

