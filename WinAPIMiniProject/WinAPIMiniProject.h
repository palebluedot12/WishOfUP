#pragma once

class Application
{
public:

	Application() = default;
	~Application() = default;

	void InitWin(HINSTANCE hInstance);

	static LRESULT CALLBACK WndProc(HWND HWnd, UINT message, WPARAM wParam, LPARAM lParam);

	HWND Get_HWND() const { return m_hWnd; }
	HINSTANCE Get_HINST() const { return m_hInstance; }

private:
	// ������ ����
	const TCHAR* Title = TEXT("������ �ҿ�");

	HINSTANCE m_hInstance;
	HWND m_hWnd;

};
namespace Global
{
	const Application& GetWinApp();
}
