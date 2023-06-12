
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
		for (i = 0; i < v.size(); i++)
		{
			for (j = 0; j < v[i].size(); j++)
			{
				if (v[i][j] != 0)
				{
					Vector2 pos = *newPosition;
					pos += Vector2(j, i);
					if (SceneManager::GetInstance().GetPlayer()->GetPosition() == pos)
					{
						SceneManager::GetInstance().GetPlayer()->Damaged(100);
					}
				}
			}
		}

	}


}

void Arrow::Render()
{
	static Vector2 vec = *SceneManager::GetInstance().pos;
	static Vector2 vec2 = *SceneManager::GetInstance().WH;
	{
		//GotoxyPlayer(position->x, position->y);
		int i, j;
		for (i = 0; i < v.size(); i++)
		{
			for (j = 0; j < v[i].size(); j++)
			{
				GotoxyPlayer(position->x + j, position->y + i);
				if (position->y + i + 1 > vec.y && position->y < position->y - 1 + i< vec.y + vec2.y
					&& position->x + j - 1> vec.x && position->x + j + 1 < vec.x + vec2.x)
					cout << "  ";
			}
		}
		*position = *newPosition;

		for (i = 0; i < v.size(); i++)
		{
			Gotoxy(0, 0);
			cout << position->x << "  ";
			cout << position->y;
			for (j = 0; j < v[i].size(); j++)
			{
				GotoxyPlayer(position->x + j, position->y + i);
				if (position->y + i + 1 > vec.y && position->y < position->y - 1 + i< vec.y + vec2.y
					&& position->x + j - 1> vec.x && position->x + j + 1 < vec.x + vec2.x)
					if (mod == ArrowMod::normal)
					{
						if (dir.x > 0 && dir.y == 0)
							cout << "°Ê";
						if (dir.x < 0 && dir.y == 0)
							cout << "°Á";
						if (dir.x == 0 && dir.y > 0)
							cout << "°È";
						if (dir.x == 0 && dir.y < 0)
							cout << "°Ë";
						if (dir.x < 0 && dir.y < 0)
							cout << "¢ÿ";
						if (dir.x < 0 && dir.y > 0)
							cout << "¢÷";
						if (dir.x > 0 && dir.y < 0)
							cout << "¢◊";
						if (dir.x > 0 && dir.y > 0)
							cout << "¢Ÿ";
					}
					else {
						switch ((ArrowModify)v[i][j])
						{
						case ArrowModify::Up:
							cout << "°Ë";
							break;
						case ArrowModify::Left:
							cout << "°Á";
							break;
						case ArrowModify::Right:
							cout << "°Ê";
							break;
						case ArrowModify::Down:
							cout << "°È";
							break;
						case ArrowModify::UpLeft:
							cout << "¢ÿ";
							break;
						case ArrowModify::UpRight:
							cout << "¢÷";
							break;
						case ArrowModify::DownLeft:
							cout << "¢◊";
							break;
						case ArrowModify::DownRight:
							cout << "¢Ÿ";
							break;
						case ArrowModify::LeftUPWall:
							cout << "¶Æ";
							break;
						case ArrowModify::UpWall:
							cout << "¶¨¶¨";
							break;
						case ArrowModify::RightUPWall:
							cout << "¶Ø";
							break;
						case ArrowModify::LeftWall:
							cout << "¶≠";
							break;
						case ArrowModify::LeftDownWall:
							cout << "¶±";
							break;
						case ArrowModify::RightDownWall:
							cout << "¶∞";
							break;
						default:
							cout << "  ";
							break;
						}
					}

			}
		}

	}


}

void Arrow::Release()
{
	int i, j;
	*position = *newPosition;
	static Vector2 vec = *SceneManager::GetInstance().pos;
	static Vector2 vec2 = *SceneManager::GetInstance().WH;
	for (i = 0; i < v.size(); i++)
	{
		for (j = 0; j < v[i].size(); j++)
		{
			if (position->y + i+1 > vec.y && position->y < position->y-1 + i< vec.y + vec2.y
				&& position->x + j - 1> vec.x && position->x + j + 1 < vec.x + vec2.x)
			{

			GotoxyPlayer(position->x + j, position->y + i);
			cout << "  ";
			}
		}
	}
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
	default:
		break;
	}
}
