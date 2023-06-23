#include "stdafx.h"
#include "ArrowInstance.h"
#include "SceneManager.h"
#include "ArrowManager.h"

ArrowInstance::ArrowInstance()
{
}

ArrowInstance::~ArrowInstance()
{
}

void ArrowInstance::Init()
{
	// ArrowInfo 만들어주기
	Info[ArrowShot::normal] = ArrowInfo(Vector2(0,0),0.5f,20, ArrowMod::normal, false);
	Info[ArrowShot::Sans1] = ArrowInfo(Vector2(0, 0), 0.5f, 20, ArrowMod::WaSans, false);
	Info[ArrowShot::Sans2] = ArrowInfo(Vector2(0, 0), 0.5f, 20, ArrowMod::SAS, true);

	//Info[ArrowShot::Sasn] = ArrowInfo(GET_SINGLE(SceneManager).pos, Vector2(0, 0))
	//GET_SINGLE(ArrowManager)->NormalArrowSommon(posed, Vector2(1, 0), 0.00005f, 100, 60, ArrowMod::WaSans);
	//GET_SINGLE(ArrowManager)->NormalArrowSommon(posed, Vector2(1, 0), 0.00000005f, 100, 60, ArrowMod::SAS);

}

void ArrowInstance::Update()
{
}

void ArrowInstance::Render()
{
}

void ArrowInstance::Release()
{
}

void ArrowInstance::RandomSizeGet()
{
	static Vector2 vec = *SceneManager::GetInstance().pos();
	static Vector2 vec2 = *SceneManager::GetInstance().WH();

	int x = (rand() % vec2.x) + vec.x; // 안값
	int y = (rand() % vec2.y) + vec.y;
	//	if (position->y + i + 1 > vec.y && position->y < position->y - 1 + i< vec.y + vec2.y
//	&& position->x + j - 1 > vec.x && position->x + j + 1 < vec.x + vec2.x)
}


