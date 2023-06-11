#pragma once


class Timer
{
public:
	Timer();
	~Timer();

	void Update();

	double DeltaTime();

private:
	float timeScale;
	float deltaTime;
	__int64 periodFrequency;
	__int64 lastTime;
	__int64 curTime;
};

