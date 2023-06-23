#include "stdafx.h"
#include "Arrow.h"
#include "SceneManager.h"
#include "player.h"

Arrow::Arrow()
{
	position = new Vector2(0, 0);
}

Arrow::Arrow(Vector2 pos)
	:Object(pos)
{
	*position = pos;
}

Arrow::Arrow(Vector2 pos, Tag tag)
	: Object('d', pos, tag)
{
	*position = pos;
	this->tag = tag;
}

Arrow::Arrow(Vector2 pos, Tag tag, float moveSpeed, Vector2 dir)
	:Object('d', pos, tag)
{
	*position = pos;
	this->tag = tag;
	this->moveSpeed = moveSpeed;
	this->dir = dir;
}
Arrow::Arrow(Vector2 pos, Tag tag, float moveSpeed, Vector2 dir, int Damaged, float LifeTime, ArrowMod moded)
	:Object('d', pos, tag)
{
	*position = pos;
	this->tag = tag;
	this->moveSpeed = moveSpeed;
	this->dir = dir;
	damage = Damaged;
	this->LifeTime = LifeTime;
	mod = moded;
}

Arrow::~Arrow()
{
}

void Arrow::Init()
{
	// dir normalized «ÿ¡‡æﬂµ…±Ó?
	string line;
	wstring fed = L"Arrow/" + SetArrowModify(mod) + L".txt";
	ifstream file(fed);
	int t = 0;
	if (file.is_open())
	{
		while (getline(file, line))
		{
			for (int i = 0; i < line.size(); i++)
			{
				v2.push_back(line[i] - '0');
			}
			t++;
			v.push_back(v2);
			v2.clear();
		}
		//WH = new Vector2(line.size(), t);
	}
}

void Arrow::Update()
{
	LifeTime -= GET_SINGLE(Timer)->DeltaTime();
	speed += GET_SINGLE(Timer)->DeltaTime();

	if (speed > moveSpeed)
	{
		speed = 0;
		*newPosition += dir;
		int i, j;
		Vector2 posed = SceneManager::GetInstance().GetPlayer()->GetPosition();
		for (i = 0; i < v.size(); i++)
		{
			for (j = 0; j < v[i].size(); j++)
			{
				if (v[i][j] != 0)
				{
					Vector2 pos = *newPosition;
					pos += Vector2(j, i);
					if (posed == pos)
					{
						SceneManager::GetInstance().GetPlayer()->Damaged(100);
					}
				}
			}
		}
		*position = *newPosition;

	}


}

void Arrow::Render()
{
	static Vector2 vec = *SceneManager::GetInstance().pos();
	static Vector2 vec2 = *SceneManager::GetInstance().WH();
	{
		int i, j;

		for (i = 0; i < v.size(); i++)
		{
			for (j = 0; j < v[i].size(); j++)
			{
				if (position->y + i > vec.y && position->y + 1 + i < vec.y + vec2.y
					&& position->x + j - 1> vec.x && position->x + j + 2 < vec.x + vec2.x)
					if (mod == ArrowMod::normal)
					{
						if (dir.x > 0 && dir.y == 0)
							SceneManager::GetInstance().ScreenPrint(position->x + j, position->y + i, "°Ê");
						if (dir.x < 0 && dir.y == 0)
							SceneManager::GetInstance().ScreenPrint(position->x + j, position->y + i, "°Á");
						if (dir.x == 0 && dir.y > 0)
							SceneManager::GetInstance().ScreenPrint(position->x + j, position->y + i, "°È");
						if (dir.x == 0 && dir.y < 0)
							SceneManager::GetInstance().ScreenPrint(position->x + j, position->y + i, "°Ë");
						if (dir.x < 0 && dir.y < 0)
							SceneManager::GetInstance().ScreenPrint(position->x + j, position->y + i, "¢ÿ");
						if (dir.x < 0 && dir.y > 0)
							SceneManager::GetInstance().ScreenPrint(position->x + j, position->y + i, "¢÷");
						if (dir.x > 0  && dir.y < 0)
							SceneManager::GetInstance().ScreenPrint(position->x + j, position->y + i, "¢◊");
						if (dir.x > 0 && dir.y > 0)
							SceneManager::GetInstance().ScreenPrint(position->x + j, position->y + i, "¢Ÿ");
					}
					else {
						switch ((ArrowModify)v[i][j])
						{
						case ArrowModify::Up:
							SceneManager::GetInstance().ScreenPrint(position->x + j, position->y + i, "°Ë");
							break;
						case ArrowModify::Left:
							SceneManager::GetInstance().ScreenPrint(position->x + j, position->y + i, "°Á");
							break;

						case ArrowModify::Right:
							SceneManager::GetInstance().ScreenPrint(position->x + j, position->y + i, "°Ê");
							break;
						case ArrowModify::Down:
							SceneManager::GetInstance().ScreenPrint(position->x + j, position->y + i, "°È");
							break;
						case ArrowModify::UpLeft:
							SceneManager::GetInstance().ScreenPrint(position->x + j, position->y + i, "¢ÿ");
							break;
						case ArrowModify::UpRight:
							SceneManager::GetInstance().ScreenPrint(position->x + j, position->y + i, "¢÷");
							break;
						case ArrowModify::DownLeft:
							SceneManager::GetInstance().ScreenPrint(position->x + j, position->y + i, "¢◊");
							break;
						case ArrowModify::DownRight:
							SceneManager::GetInstance().ScreenPrint(position->x + j, position->y + i, "¢Ÿ");
							break;
						case ArrowModify::LeftUPWall:
							SceneManager::GetInstance().ScreenPrint(position->x + j, position->y + i, "¶Æ");
							break;
						case ArrowModify::UpWall:
							SceneManager::GetInstance().ScreenPrint(position->x + j, position->y + i, "¶¨");
							break;
						case ArrowModify::RightUPWall:
							SceneManager::GetInstance().ScreenPrint(position->x + j, position->y + i, "¶Ø");
							break;
						case ArrowModify::LeftWall:
							SceneManager::GetInstance().ScreenPrint(position->x + j, position->y + i, "¶≠");
							break;
						case ArrowModify::LeftDownWall:
							SceneManager::GetInstance().ScreenPrint(position->x + j, position->y + i, "¶±");
							break;
						case ArrowModify::RightDownWall:
							SceneManager::GetInstance().ScreenPrint(position->x + j, position->y + i, "¶∞");
							break;
						default:
							//SceneManager::GetInstance().ScreenPrint(position->x + j, position->y + i, "  ");
							break;
						}
					}

			}
		}

	}


}

void Arrow::Release()
{
}


wstring Arrow::SetArrowModify(ArrowMod mod)
{
	switch (mod)
	{
	case ArrowMod::normal:
		return L"normal";
		break;
	case ArrowMod::shipja:
		return L"shipja";
		break;
	case ArrowMod::WaSans:
		return L"WaSans";
		break;
	case ArrowMod::SAS:
		return L"SAS";
	default:
		break;
	}
}
