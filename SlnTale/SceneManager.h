#pragma once
#include "Scene.h"

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
	void RegisterScene(const wstring& sceneName, shared_ptr<Scene> scene);
	void LoadScene(const wstring& sceneName);


	static SceneManager& GetInstance() {
		static SceneManager s;
		return s;
	}
	void Init(); 
	void Update();
	void Render();
	void Release();


public:
	bool GameEnd = false;

	void ScreenFlipping()  // 스크린 바꾸는거
	{
		SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
		g_nScreenIndex = !g_nScreenIndex;
		ScreenClear();
	}

	void ScreenClear()
	{
		COORD Coor = { 0, 0 };
		DWORD dw;
		FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', 800 * 250, Coor, &dw);
	}

	void ScreenPrint(int x, int y, string string, COLOR col = COLOR::WHITE, COLOR cols = COLOR::BLACK) // x y 위치로 가서 출력
	{
		DWORD dw;
		COORD CursorPosition = { x, y };
		SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
		SetConsoleTextAttribute(g_hScreen[g_nScreenIndex], (int)col | (int)cols);
		WriteFile(g_hScreen[g_nScreenIndex], const_cast<char*>(string.c_str()), strlen(string.c_str()), &dw, NULL);
	}

public:
	player* GetPlayer()
	{
		return (*m_activeScene).GetPlayer();
	}

	Vector2* pos()
	{
		return (*m_activeScene).pos;
	}

	Vector2* WH()
	{
		return (*m_activeScene).WH;
	}

	vector<vector<int>> v()
	{
		return (*m_activeScene).v;
	}

public:

	int g_nScreenIndex;//콘솔 접근 인덱스
	HANDLE g_hScreen[2];//콘솔2개
	int g_numOfFrame;//누적 프레임
	int g_numOfFPS;//분당 프레임
	
	char* FPSTextInfo;//콘솔에 출력할 char 포인터

	float GameTime = .0f;

public:
	float renderSpeed =0.3f;
	float rendering = 0;
	shared_ptr<Scene>				m_activeScene;
	
	map<wstring, shared_ptr<Scene>> m_sceneContainer;


};

