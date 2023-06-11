#include "stdafx.h"
#include "player.h"
#include "SceneManager.h"
///���������������������������������������������� 
///��                     ��
///��                     ��
///��                     ��
///��                     ��
///��                     ��
///��                     ��
///��                     ��
///��                     ��
///��                     ��
///��                     ��
///��                     ��
///��                     ��
///��                     ��
///��                     ��
///��                     ��
///����������������������������������������������



void SceneManager::Init()
{
	SetMap();
	Scenes();
	Vector2 vec = *WH / 2;
	vec += *pos;
	p = new player(vec);

	p->Init();
	
}

void SceneManager::Update()
{
	p->Update();
}

void SceneManager::Render()
{
	p->Render();
	//Scenes();

}

void SceneManager::Release()
{
}

void SceneManager::Scenes()
{
	pos = new Vector2(20, 32);
	int i, j;
	for (i = 0; i < v.size(); i++)
	{
		Gotoxy(pos->x + pos->x + 1, pos->y + i);
		for (j = 0; j < v[i].size(); j++)
		{
			switch ((walls)v[i][j])
			{
			case walls::LeftUP:
				cout << "��";
				break;
			case walls::Up:
				cout << "����";
				break;
			case walls::RightUP:
				cout << "��";
				break;
			case walls::Left:
				cout << "��";
				break;
			case walls::LeftDown:
				cout << "��";
				break;
			case walls::RightDown:
				cout << "��";
				break;
			default:
				cout << "  ";
				break;
			}
		}
		cout << endl;
	}
}


void SceneManager::SetMap()
{
	string line;
	ifstream file("map1.txt");
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
		WH = new Vector2(line.size(), t);
	}
}
