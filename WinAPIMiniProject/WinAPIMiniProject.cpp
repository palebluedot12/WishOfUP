#include "Framework.h"
#include "WinAPIMiniProject.h"

namespace Global {
    Application Winapp;

    const Application& GetWinApp() {
        return Winapp;
    }
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    MSG msg;

    Global::Winapp.InitWin(hInstance);

    GameManager::Get()->Initialize(Global::GetWinApp().Get_HWND());

    while (GameManager::Get()->IsLoop())
    {
        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                GameManager::Get()->SetLoop(false);
                break;
            }
            else
            {
                if (msg.message == WM_KEYDOWN || msg.message == WM_KEYUP)
                {
                    KeyManager::Get()->GetKey(msg);
                }
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        Time::Get()->Update();

        GameManager::Get()->FixedUpdate();

        GameManager::Get()->Update();

        GameManager::Get()->LateUpdate();

        GameManager::Get()->Render();
    }
    GameManager::Get()->Finalize();
}

// 윈도우를 가운데로 옮김
void PlaceInCenterOfScreen(HWND window, DWORD style, DWORD exStyle)
{
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);

    RECT clientRect;
    GetClientRect(window, &clientRect);

    int clientWidth = clientRect.right - clientRect.left;
    int clientHeight = clientRect.bottom - clientRect.top;

    SetWindowPos(window, NULL,
        screenWidth / 2 - clientWidth / 2,
        screenHeight / 2 - clientHeight / 2,
        clientWidth, clientHeight, 0
    );
}

LRESULT CALLBACK Application::WndProc(HWND HWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    // Alt 키 비활성화용
    case WM_SYSKEYDOWN:
    case WM_SYSKEYUP:
        if (wParam == VK_MENU) 
            return 0;
        break;
    // 윈도우 만들어 졌을 때
    case WM_CREATE:
    {
        PlaceInCenterOfScreen(HWnd, WS_OVERLAPPEDWINDOW, WS_EX_APPWINDOW | WS_EX_WINDOWEDGE);
    }
    break;
    // 윈도우 없어질 때
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(HWnd, message, wParam, lParam);
    }
    return 0;
}

void Application::InitWin(HINSTANCE hInstance)
{
    m_hInstance = hInstance;

    WNDCLASS WndC;
    WndC.style = CS_HREDRAW | CS_VREDRAW;
    WndC.lpfnWndProc = WndProc;
    WndC.cbClsExtra = 0;
    WndC.cbWndExtra = 0;
    WndC.hInstance = hInstance;
    WndC.hIcon = LoadIcon(hInstance, IDI_APPLICATION);
    WndC.hCursor = LoadCursor(NULL, IDC_ARROW);
    WndC.hbrBackground = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
    WndC.lpszMenuName = NULL;
    WndC.lpszClassName = Title;

    RegisterClass(&WndC);

    RECT SCREEN_Size{ 0, 0, MAX_WIDTH, MAX_HEIGHT };

    ::AdjustWindowRect(&SCREEN_Size, WS_OVERLAPPEDWINDOW, FALSE);
    int WIDTH = SCREEN_Size.right - SCREEN_Size.left;
    int HEIGHT = SCREEN_Size.bottom - SCREEN_Size.top;

    m_hWnd = CreateWindow(Title, Title, WS_OVERLAPPED | WS_SYSMENU,
        0, 0, WIDTH, HEIGHT,
        NULL, NULL, m_hInstance, NULL);

    ShowWindow(m_hWnd, SW_SHOWNORMAL);
    UpdateWindow(m_hWnd);
}