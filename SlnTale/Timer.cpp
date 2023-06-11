#include "Timer.h"
#include <Windows.h>
Timer::Timer()
{

    QueryPerformanceFrequency((LARGE_INTEGER*)&periodFrequency);
   


    QueryPerformanceCounter((LARGE_INTEGER*)&lastTime);
   

    timeScale = 1.0 / (double)periodFrequency;
    
}

Timer::~Timer()
{
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

