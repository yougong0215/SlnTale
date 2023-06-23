#pragma once

class player;
class Scene
{
public:
	Scene() = default;
	virtual ~Scene() = default;

public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Release() = 0;

public:
	player* GetPlayer()
	{
		return _player;
	}

	Vector2* pos;
	Vector2* WH;

	vector<vector<int>> v;
	vector<int> v2;

	vector<string> b2;



protected:
	player* _player;



};

