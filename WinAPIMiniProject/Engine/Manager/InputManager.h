#pragma once

using namespace std;

struct KeyState {
	bool IsDown = false;
	bool IsHold = false;
	bool IsUp = false;
};

struct MouseState {
	bool Left = false;
	bool Right = false;
	bool Mid = false;
};

class KeyManager : public Singleton<KeyManager>
{
private:

	friend class Singleton;
	KeyManager() = default;
	~KeyManager() = default;

private:
	// -1f ~ 1f 까지의 부드러운 값 변경
	float Horizontal_Axis = 0.f;
	float Vertical_Axis = 0.f;
	// -1, 0, 1만을 반환
	int Horizontal_AxisRaw = 0;
	int Vertical_AxisRaw = 0;
	// 키보드 입력을 관리할 배열 생성
	KeyState Key_Code[256];

	void Axis();
	void AxisRaw();

public:

	void GetKey(MSG msg);
	void UpdateInput();
	void ResetInput();

	// 키보드가 눌렸는지 확인합니다.
	bool IsDown(int code) const;
	// 키보드가 누르고 있는 중인지 확인합니다.
	bool IsHold(int code) const;
	// 키보드를 뗏는지 확인합니다.
	bool IsUp(int code) const;

	float GetAxis(string dir) const;
	int GetAxisRaw(string dir) const;

	void SetAxis(string dir, float value);
	void SetAxisRaw(string dir, int value);

};
class MouseManager : public Singleton<MouseManager>
{
private:

	friend class Singleton;
	MouseManager() = default;
	~MouseManager() = default;

	MouseState Cur_Mouse;
	MouseState Pre_Mouse;

public:
	
	Vector2 position = {0, 0};

	void UpdateMouse();

	bool IsDown(MouseType _code) const;
	bool IsHold(MouseType _code) const;
	bool IsUp(MouseType _code) const;
};