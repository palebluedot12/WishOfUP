#pragma once
class TestScene;

class GameManager : public Singleton<GameManager>
{
private:
	friend class Singleton;
	GameManager();
	~GameManager();

public:

	void Initialize(HWND hwnd);
	void Update();
	void FixedUpdate();
	void LateUpdate();
	void Render();
	void Finalize();

	void SetLoop(bool _val) { isLoop = _val; }
	void SetStop(bool _val) { isStop = _val; }
	bool IsLoop() { return isLoop; }
	bool IsStop() { return isStop; }

private:

	static GameManager* instance;

	bool isLoop = true;
	bool isStop = false;

};