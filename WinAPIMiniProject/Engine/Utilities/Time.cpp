#include "Framework.h"

Time::Time()
{
	//1�ʵ��� cpu������ ��ȯ
	QueryPerformanceFrequency((LARGE_INTEGER*)&periodFrequency);

	//prevTime�� ���� cpu������ ��ȯ
	QueryPerformanceCounter((LARGE_INTEGER*)&prevTime);
	QueryPerformanceCounter((LARGE_INTEGER*)&curTime);
}

Time::~Time()
{
}

void Time::Update()
{
	//curTime�� ���� cpu������ ��ȯ
	prevTime = curTime;
	QueryPerformanceCounter((LARGE_INTEGER*)&curTime);

	//����ð��� ����ð� - �������ð� * 1�ʵ��� cpu������
	deltaTime = (curTime - prevTime) / (float)periodFrequency * TimeScale * !isTimeStop;
	elapsedTime += deltaTime;
	oneSecCount += deltaTime;//1��

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

