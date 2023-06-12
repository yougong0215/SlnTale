#pragma once

class Timer
{
public:
	DECLARE_SINGLE(Timer);
	void Init();

	void Update();

	double DeltaTime();

private:
	float timeScale;
	float deltaTime;
	__int64 periodFrequency;
	__int64 lastTime;
	__int64 curTime;
};

