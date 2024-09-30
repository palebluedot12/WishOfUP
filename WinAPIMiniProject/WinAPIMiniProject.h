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
	// 윈도우 제목
	const TCHAR* Title = TEXT("유피의 소원");

	HINSTANCE m_hInstance;
	HWND m_hWnd;

};
namespace Global
{
	const Application& GetWinApp();
}
