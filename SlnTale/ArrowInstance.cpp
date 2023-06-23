#include "stdafx.h"
#include "ArrowInstance.h"
#include "SceneManager.h"
#include "ArrowManager.h"
#include "player.h"



ArrowInstance::ArrowInstance()
{
}

ArrowInstance::~ArrowInstance()
{
}

void ArrowInstance::Init()
{
	// ArrowInfo 만들어주기
	Info[ArrowShot::Rain] = std::bind(&ArrowInstance::ArrowRain, this);
	Info[ArrowShot::Sans1] = std::bind(&ArrowInstance::SansPatton1, this);
	Info[ArrowShot::Sans2] = std::bind(&ArrowInstance::SansPatton2, this);
	Info[ArrowShot::UP] = std::bind(&ArrowInstance::ArrowRainUP, this);
	Info[ArrowShot::Right] = std::bind(&ArrowInstance::ArrowRainRight, this);
	Info[ArrowShot::Miro] = std::bind(&ArrowInstance::ArrowMiro, this);
	//Info[ArrowShot::Sasn] = ArrowInfo(GET_SINGLE(SceneManager).pos, Vector2(0, 0))
	//GET_SINGLE(ArrowManager)->NormalArrowSommon(posed, Vector2(1, 0), 0.00005f, 100, 60, ArrowMod::WaSans);
	//GET_SINGLE(ArrowManager)->NormalArrowSommon(posed, Vector2(1, 0), 0.00000005f, 100, 60, ArrowMod::SAS);

}


// 1111111111111111111111111111111111111111111111111111111111111111111111
// 1111111111111111111111111111111111111111111111111111111111111111111111
// 1111111111111111111111111111111111111111111111111111111111111111111111
// 1111111111111111111111111111111111111111111111111111111111111111111111
// 1111111111111111111111111111111111111111111111111111111111111111111111
// 1111111111111111111111111111111111111111111111111111111111111111111111
// 1111111111111111111111111111111110000000011111111111111111111111111111
// 1111111111111111111111111111111100111110011111111111111111111111111111
// 1111111111111111111111111111110000111110011111111111111111111111111111
// 1111111111111111111111111111110000111111001111111111111111111111111111
// 1111111111111111111111111111100011111111000111111111111111111111111111
// 1111111111111111111111111111000111111111100011111111111111111111111111
// 1111111111111111111111000000001111111111110000001111111111111111111111
// 1111111111111111000000000000001111111111111000000000000000000000000000
// 1111111000000000000000111111111111111111111111111111111111111100000000
// 0000000000011111111111111111111111111111111111111111111111111111111111
// 1111111111111111111111111111111111111111111111111111111111111111111111
// 1111111111111111111111111111111111111111111111111111111111111111111111
// 1111111111111111111111111111111111111111111111111111111111111111111111
// 1111111111111111111111111111111111111111111111111111111111111111111111
// 1111111111111111111111111111111111111111111111111111111111111111111111


void ArrowInstance::Update()
{
	currentTime += GET_SINGLE(Timer)->DeltaTime();
	if (currentTime > sommonTime)
	{
		Info[static_cast<ArrowShot>(rand() % Info.size())]();
	}
}

void ArrowInstance::Render()
{
}

void ArrowInstance::Release()
{
}




Vector2 ArrowInstance::GetRandomDirection()
{
	static Vector2 vec = *SceneManager::GetInstance().pos();
	static Vector2 vec2 = *SceneManager::GetInstance().WH();

	int x = (rand() % vec2.x) + vec.x; // 안값
	int y = (rand() % vec2.y) + vec.y;
	while (true)
	{
		if (y + 1 > vec.y && y < vec.y + vec2.y
			&& x - 1 > vec.x && x + 1 < vec.x + vec2.x)
		{
			x = (rand() % vec2.x) + vec.x; // 안값
			y = (rand() % vec2.y) + vec.y;
		}
		else {
			break;
		}
	}


	return Vector2(x, y).normalize();


}

void ArrowInstance::ArrowRain()
{
	static Vector2 vec = *SceneManager::GetInstance().pos();
	static Vector2 vec2 = *SceneManager::GetInstance().WH();
	int cnt = rand() % 40 + 40;

	int x = (rand() % vec2.x) + vec.x; // 안값
	int y = rand() % 30 + 4;


	sommonTime = 5;
	currentTime = 0;

	GET_SINGLE(SceneManager).GetPlayer()->SetModify(PlayerMode::gravity);
	for (int i = 0; i < cnt; i++)
	{
		x = (rand() % vec2.x) + vec.x; // 안값
		y = rand() % 30;

		GET_SINGLE(ArrowManager)->NormalArrowSommon(Vector2(x, y), Vector2(0, 2), 0.05f, 50, 20);

	}


}

void ArrowInstance::ArrowRainUP()
{
	static Vector2 vec = *SceneManager::GetInstance().pos();
	static Vector2 vec2 = *SceneManager::GetInstance().WH();
	int cnt = rand() % 40 + 40;

	int x = (rand() % vec2.x) + vec.x; // 안값
	int y = rand() % 80 + 30;


	sommonTime = 5;
	currentTime = 0;

	GET_SINGLE(SceneManager).GetPlayer()->SetModify(PlayerMode::fly);
	for (int i = 0; i < cnt; i++)
	{
		x = (rand() % vec2.x) + vec.x; // 안값
		y = rand() % 80 + 30;

		GET_SINGLE(ArrowManager)->NormalArrowSommon(Vector2(x, y), Vector2(0, -2), 0.05f, 50, 20);

	}


}

void ArrowInstance::ArrowRainRight()
{
	static Vector2 vec = *SceneManager::GetInstance().pos();
	static Vector2 vec2 = *SceneManager::GetInstance().WH();
	int cnt = rand() % 40 + 40;

	int x = rand() % 15; // 안값
	int y = (rand() % vec2.y) + vec.y;


	sommonTime = 5;
	currentTime = 0;

	GET_SINGLE(SceneManager).GetPlayer()->SetModify(PlayerMode::fly);
	for (int i = 0; i < cnt; i++)
	{
		x = rand() % 30; // 안값
		y = (rand() % vec2.y) + vec.y;

		GET_SINGLE(ArrowManager)->NormalArrowSommon(Vector2(-x, y), Vector2(2, 0), 0.05f, 50, 20);

	}


}

void ArrowInstance::SansPatton1()
{
	Vector2 vec = *SceneManager::GetInstance().pos();
	sommonTime = 16;
	currentTime = 0;
	vec.x -= 50;
	GET_SINGLE(ArrowManager)->NormalArrowSommon(vec, Vector2(1, 0), 0.05f, 40, 60, ArrowMod::WaSans);
	GET_SINGLE(SceneManager).GetPlayer()->SetModify(PlayerMode::fly);
}


void ArrowInstance::SansPatton2()
{
	Vector2 vec = *SceneManager::GetInstance().pos();

	sommonTime = 20;
	currentTime = 0;

	vec.x -= 50;
	GET_SINGLE(ArrowManager)->NormalArrowSommon(vec, Vector2(1, 0), 0.1f, 40, 60, ArrowMod::SAS);
	GET_SINGLE(SceneManager).GetPlayer()->SetModify(PlayerMode::gravity);
}

void ArrowInstance::ArrowMiro()
{
	Vector2 vec = *SceneManager::GetInstance().pos();
	sommonTime = 25;
	currentTime = 0;
	vec.x -= 50;
	GET_SINGLE(ArrowManager)->NormalArrowSommon(vec, Vector2(1, 0), 0.2f, 40, 60, ArrowMod::Miro);
	GET_SINGLE(SceneManager).GetPlayer()->SetModify(PlayerMode::fly);
}



