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
	// -1f ~ 1f ������ �ε巯�� �� ����
	float Horizontal_Axis = 0.f;
	float Vertical_Axis = 0.f;
	// -1, 0, 1���� ��ȯ
	int Horizontal_AxisRaw = 0;
	int Vertical_AxisRaw = 0;
	// Ű���� �Է��� ������ �迭 ����
	KeyState Key_Code[256];

	void Axis();
	void AxisRaw();

public:

	void GetKey(MSG msg);
	void UpdateInput();
	void ResetInput();

	// Ű���尡 ���ȴ��� Ȯ���մϴ�.
	bool IsDown(int code) const;
	// Ű���尡 ������ �ִ� ������ Ȯ���մϴ�.
	bool IsHold(int code) const;
	// Ű���带 �´��� Ȯ���մϴ�.
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