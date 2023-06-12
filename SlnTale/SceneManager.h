#pragma once


class player;
class ArrowManager;
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
	player* GetPlayer()
	{
		return _player;
	}

	void ScreenFlipping()
	{
		SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
		g_nScreenIndex = !g_nScreenIndex;
	}

	void ScreenClear()
	{
		COORD Coor = { 0, 0 };
		DWORD dw;
		FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', 80 * 40, Coor, &dw);
	}

	void ScreenPrint(int x, int y, char* string)
	{
		DWORD dw;
		COORD CursorPosition = { x, y };
		SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
		WriteFile(g_hScreen[g_nScreenIndex], string, strlen(string), &dw, NULL);
	}

public:
	Vector2* pos;
	Vector2* WH;

private:
	 player* _player ;
public:
	float renderSpeed =0;
	float rendering = 1;
	vector<vector<int>> v;
	vector<int> v2;

	int g_nScreenIndex;//콘솔 접근 인덱스
	HANDLE g_hScreen[2];//콘솔2개
	int g_numOfFrame;//누적 프레임
	int g_numOfFPS;//분당 프레임

	char* FPSTextInfo;//콘솔에 출력할 char 포인터

};

