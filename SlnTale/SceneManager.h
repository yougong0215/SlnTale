#pragma once

enum class walls
{
	None = 0,
	LeftUP = 1,
	Up =2,
	RightUP=3,
	Left=4,
	LeftDown,
	RightDown,
};

class player;
class SceneManager
{
private:
	SceneManager() {}
	SceneManager(const SceneManager& ref) {}
	SceneManager& operator=(const SceneManager& ref) {}
	~SceneManager() {}

public:
	static SceneManager& GetInstance() {
		static SceneManager s;
		return s;
	}
	void Init();
	void Update();
	void Render();
	void Release();

	void Scenes();
	void SetMap();


public:
	Vector2* pos;
	Vector2* WH;

private:
	 player* p ;
public:
	vector<vector<int>> v;
	vector<int> v2;
};

