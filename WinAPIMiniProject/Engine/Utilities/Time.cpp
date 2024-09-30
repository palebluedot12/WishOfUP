#include "Framework.h"

Time::Time()
{
	//1초동안 cpu진동수 반환
	QueryPerformanceFrequency((LARGE_INTEGER*)&periodFrequency);

	//prevTime에 현재 cpu진동수 반환
	QueryPerformanceCounter((LARGE_INTEGER*)&prevTime);
	QueryPerformanceCounter((LARGE_INTEGER*)&curTime);
}

Time::~Time()
{
}

void Time::Update()
{
	//curTime에 현재 cpu진동수 반환
	prevTime = curTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&curTime);

	//경과시간은 현재시간 - 마지막시간 * 1초동안 cpu진동수
	deltaTime = (curTime - prevTime) / (float)periodFrequency * TimeScale * !isTimeStop;
	elapsedTime += deltaTime;
	oneSecCount += deltaTime;//1초

	frameCount++;

	if (oneSecCount >= 1.0f)
	{
		frameRate = frameCount;
		frameCount = 0;
		oneSecCount = 0.0f;
	}
}

void Time::Render(HDC hdc)
{
	//const wchar_t* clock = L"FPS: "+
}

bool Time::FrameLock()
{
	if (elapsedTime > 1.f / frameLock)
	{
		elapsedTime -= 1.f / frameLock;
		return true;
	}
	return false;
}

void Time::SetTimeScale(float _val)
{
	PreTimeScale = TimeScale;
	TimeScale = _val;
}

void Time::UndoTimeScale()
{
	TimeScale = PreTimeScale;
}

