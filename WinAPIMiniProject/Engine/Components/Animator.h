#pragma once

class Animation;

class Animator : public Component
{
public:

	Animator();
	~Animator();

	void AddAnimation(std::wstring _key, Animation* _ani);
	Animation* FindAnimation(const std::wstring& _key);
	void ActiveAnimation(const std::wstring& _key, bool _loop = true);
	Animation* GetActiveAnimation() { return activeAnimation; }

	int GetFrame();
	void GotoAndPlay(int _val);
	void GotoAndStop(int _val);
	void GotoAndNextFrame();
	void GotoAndPrevFrame();
	void Play();
	void Stop();
	bool IsEnd();

	void Update() override;
	void Render() override;

	bool IsLoop() { return isLoop; }

	void SetAlpha(float _val) { _alpha = _val; }
	float GetAlpha() { return _alpha; }

private:

	HDC hdc;

	std::map<std::wstring, Animation*> animationList;
	Animation* activeAnimation;

	int frame;
	float frameCount;
	bool isLoop;
	bool isStop;
	float _alpha = 1.0f;

};

