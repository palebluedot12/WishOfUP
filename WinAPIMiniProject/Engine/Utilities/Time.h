#pragma once

class Time :public Singleton<Time>
{
private:
	float EPSILON = 0.01f;

	friend class Singleton;
	Time();
	~Time();

public:
	void Update();
	void Render(HDC hdc);
	void SetFrameLock(int inValue) { frameLock = inValue; }
	bool FrameLock();

	float GetElapsedTime() { return elapsedTime; }
	float GetDeltaTime() { return deltaTime; }
	int   GetFPS() { return frameRate; }
	float GetTimeScale() { return TimeScale; }

	void SetTimeScale(float _val);
	void SetTimeStop(bool _val) { isTimeStop = _val; }
	void UndoTimeScale();

private:
	float deltaTime = 0.f;
	float elapsedTime = 0.f;
	float oneSecCount = 0.f;

	__int64 curTime = 0;
	__int64 prevTime = 0;
	__int64 periodFrequency = 0;

	int frameRate = 0;
	int frameCount = 0;
	int frameLock = 50;

	bool isTimeStop = false;
	float TimeScale = 1.f;
	float PreTimeScale;
};