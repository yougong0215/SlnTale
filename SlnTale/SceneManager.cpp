#include "stdafx.h"
#include "SceneManager.h"
#include "Scene.h"
#include "GameScene.h"






#define _CRT_SECURE_NO_WARNINGS



void SceneManager::RegisterScene(const wstring& sceneName, shared_ptr<Scene> scene)
{
	if (sceneName.empty() || scene == NULL)
		return;

	m_sceneContainer.insert(m_sceneContainer.end(), pair<wstring, shared_ptr<Scene>>(sceneName, scene));
}

void SceneManager::LoadScene(const wstring& sceneName)
{
	if (m_activeScene != NULL)
	{
		m_activeScene->Release();
		m_activeScene = NULL;
	}

	auto it = m_sceneContainer.find(sceneName);
	if (it != m_sceneContainer.end())
	{
		m_activeScene = it->second;
		m_activeScene->Init();
	}
}

void SceneManager::Init()
{
	CONSOLE_CURSOR_INFO cci;

	g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	// 커서를 숨긴다.
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(g_hScreen[0], &cci);
	SetConsoleCursorInfo(g_hScreen[1], &cci);

	//if (m_activeScene != nullptr)
	//{
	//	m_activeScene->Init();
	//}



}

void SceneManager::Update()
{
	rendering += GET_SINGLE(Timer)->DeltaTime();
	GET_SINGLE(Timer)->Update();
	if (m_activeScene != nullptr)
	{
		m_activeScene->Update();
	}
}

void SceneManager::Render()
{
	if(renderSpeed < rendering) // 출력 코드
	{
		g_numOfFPS = g_numOfFrame;
		g_numOfFrame = 0;
		rendering = 0;

	}


	ScreenFlipping();
	if (m_activeScene != nullptr)
	{
		m_activeScene->Render();
	}

}

void SceneManager::Release()
{
	if (m_activeScene != nullptr)
	{
		m_activeScene->Release();
	}
}

