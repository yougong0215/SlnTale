#include "stdafx.h"



void Timer::Init()
{
    QueryPerformanceFrequency((LARGE_INTEGER*)&periodFrequency);



    QueryPerformanceCounter((LARGE_INTEGER*)&lastTime);


    timeScale = 1.0 / (double)periodFrequency;

}

void Timer::Update()
{
    QueryPerformanceCounter((LARGE_INTEGER*)&curTime); // ���� ������ ������ ����.

    deltaTime = (double)(curTime - lastTime) * timeScale; // (���� ������ ������ - ���� ������ ������) * ( 1 / �ʴ������� )

    lastTime = curTime; // ���� �������� ���� ���������� ����. ���� ��� �ݺ�.

}

double Timer::DeltaTime()
{
    return deltaTime;
}

