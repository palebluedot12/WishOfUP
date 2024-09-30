#include "Framework.h"

std::vector<short> KeyDown_Reset;
std::vector<short> KeyUp_Reset;

// 누른 키보드 값을 저장합니다.
void KeyManager::GetKey(MSG msg)
{
	// 딜레이 없게 하려고 
	Key_Code[msg.wParam].IsDown = false;
	if (msg.message == WM_KEYDOWN) {
		if (Key_Code[msg.wParam].IsHold == false) {
			Key_Code[msg.wParam].IsDown = true;
			Key_Code[msg.wParam].IsHold = true;
			KeyDown_Reset.push_back(msg.wParam);
		}
	}
	else if (msg.message == WM_KEYUP) {
		Key_Code[msg.wParam].IsHold = false;
		Key_Code[msg.wParam].IsUp = true;
		KeyUp_Reset.push_back(msg.wParam);
	}
}

// 매 업데이트 마지막에 Down이나 Up의 정보들을 초기화시킵니다.
void KeyManager::ResetInput()
{
	while (!KeyDown_Reset.empty())
	{
		Key_Code[KeyDown_Reset.back()].IsDown = false;
		KeyDown_Reset.pop_back();
	}
	while (!KeyUp_Reset.empty()) 
	{
		Key_Code[KeyUp_Reset.back()].IsUp = false;
		KeyUp_Reset.pop_back();
	}
}

// Axis 정보를 갱신합니다.
void KeyManager::UpdateInput()
{
	Axis();
	AxisRaw();
}

bool KeyManager::IsDown(int code) const
{
	return Key_Code[code].IsDown;
}
bool KeyManager::IsHold(int code) const
{
	return Key_Code[code].IsHold;
}
bool KeyManager::IsUp(int code) const
{
	return Key_Code[code].IsUp;
}

void KeyManager::Axis()
{
	
	float deltaTime = DELTA * 3;

	if (Horizontal_Axis >= deltaTime * -1  && Horizontal_Axis <= deltaTime * 1) Horizontal_Axis = 0.f;
	if (Vertical_Axis >= deltaTime * -1  && Vertical_Axis <= deltaTime * 1) Vertical_Axis = 0.f;

	if (Horizontal_Axis >= -1.f && Horizontal_Axis <= 1.f) {
		if (IsHold((int)KeyType::RIGHT)) Horizontal_Axis += deltaTime;
		else if (IsHold((int)KeyType::LEFT)) Horizontal_Axis -= deltaTime;
		else if (Horizontal_Axis != 0.f) Horizontal_Axis += deltaTime * (Horizontal_Axis <= 0 ? 1 : -1);
	}
	if (Horizontal_Axis <= -1.f) Horizontal_Axis = -1.f;
	if (Horizontal_Axis >= 1.f) Horizontal_Axis = 1.f;

	if (Vertical_Axis >= -1.f && Vertical_Axis <= 1.f) {
		if (IsHold((int)KeyType::DOWN)) Vertical_Axis += deltaTime;
		else if (IsHold((int)KeyType::UP)) Vertical_Axis -= deltaTime;
		else if (Vertical_Axis != 0.f) Vertical_Axis += deltaTime * (Vertical_Axis < 0.f ? 1 : -1);
	}
	if (Vertical_Axis <= -1.f) Vertical_Axis = -1.f;
	if (Vertical_Axis >= 1.f) Vertical_Axis = 1.f;
	
}

void KeyManager::AxisRaw()
{
	if (IsHold((int)KeyType::RIGHT)) Horizontal_AxisRaw = 1;
	else if (IsHold((int)KeyType::LEFT)) Horizontal_AxisRaw =- 1;
	else Horizontal_AxisRaw = 0;
	if (IsHold((int)KeyType::DOWN)) Vertical_AxisRaw = 1;
	else if (IsHold((int)KeyType::UP)) Vertical_AxisRaw = -1;
	else Vertical_AxisRaw = 0;
}

float KeyManager::GetAxis(string dir) const
{
	if (dir == "Horizontal") return Horizontal_Axis;
	else if (dir == "Vertical") return Vertical_Axis;
	else return 0;
}

int KeyManager::GetAxisRaw(string dir) const
{
	if (dir == "Horizontal") return Horizontal_AxisRaw;
	else if (dir == "Vertical") return Vertical_AxisRaw;
	else return 0;
}

void KeyManager::SetAxis(string dir, float value)
{
	if (dir == "Horizontal") Horizontal_Axis = value;
	if (dir == "Vertical") Vertical_Axis = value;
}

void KeyManager::SetAxisRaw(string dir, int value)
{
	if (dir == "Horizontal") Horizontal_AxisRaw = value;
	if (dir == "Vertical") Vertical_AxisRaw = value;
}


void MouseManager::UpdateMouse()
{
	Pre_Mouse = Cur_Mouse;

	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(RenderManager::Get()->Get_HWND(), &pt);

	position = { (float)pt.x, (float)pt.y };
	//Cur_Mouse.Mid = 0;

	Cur_Mouse.Left = (GetKeyState(VK_LBUTTON) & 0x8000) != 0;
	Cur_Mouse.Right = (GetKeyState(VK_RBUTTON) & 0x8000) != 0;
	Cur_Mouse.Mid = (GetKeyState(VK_MBUTTON) & 0x8000) != 0;
}

bool MouseManager::IsDown(MouseType _code) const
{
	if (_code == MouseType::RIGHT && !Pre_Mouse.Right) return Cur_Mouse.Right;
	if (_code == MouseType::ROLL && !Pre_Mouse.Mid) return Cur_Mouse.Mid;
	if (_code == MouseType::LEFT && !Pre_Mouse.Left) return Cur_Mouse.Left;
	return false;
}

bool MouseManager::IsHold(MouseType _code) const
{
	if (_code == MouseType::RIGHT) return Cur_Mouse.Right;
	if (_code == MouseType::ROLL) return Cur_Mouse.Mid;
	if (_code == MouseType::LEFT) return Cur_Mouse.Left;
	return false;
}

bool MouseManager::IsUp(MouseType _code) const
{
	if (_code == MouseType::RIGHT && !Cur_Mouse.Right && Pre_Mouse.Right) return true;
	if (_code == MouseType::ROLL && !Cur_Mouse.Mid && Pre_Mouse.Mid) return true;
	if (_code == MouseType::LEFT && !Cur_Mouse.Left && Pre_Mouse.Left) return true;
	return false;
}
