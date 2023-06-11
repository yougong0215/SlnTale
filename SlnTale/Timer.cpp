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
    QueryPerformanceCounter((LARGE_INTEGER*)&curTime); // 현재 프레임 진동수 저장.

    deltaTime = (double)(curTime - lastTime) * timeScale; // (현재 프레임 진동수 - 이전 프레임 진동수) * ( 1 / 초당진동수 )

    lastTime = curTime; // 현재 프레임을 이전 프레임으로 저장. 이후 계속 반복.

}

double Timer::DeltaTime()
{
    return deltaTime;
}

