#include "Framework.h"



void RenderManager::DrawBackGround()
{
    HBITMAP hBitmap;

    if (SceneManager::Get()->GetActiveScene() == nullptr) return;
    GameScene* _curScene = SceneManager::Get()->GetActiveScene();
    if (_curScene->GetBackGround() == nullptr) return;
    _curScene->GetBackGround()->GetBitmap()->GetHBITMAP(Gdiplus::Color::Black, &hBitmap);

    if (!hBitmap) {
        assert(false);
    }

    // 메모리 DC 생성
    HDC hMemDC = CreateCompatibleDC(m_frontDC);

    // 비트맵 선택
    HBITMAP hOldBitmap = (HBITMAP)SelectObject(hMemDC, hBitmap);

    // 비트맵 크기 얻기
    BITMAP bitmap;
    GetObject(hBitmap, sizeof(BITMAP), &bitmap);

    // BitBlt를 사용하여 m_backDC에 그리기
    BitBlt(m_backDC, 0, 0, bitmap.bmWidth, bitmap.bmHeight, hMemDC, 0, 0, SRCCOPY);

    // 클린업
    SelectObject(hMemDC, hOldBitmap);
    DeleteDC(hMemDC);
    DeleteObject(hBitmap);
}

void RenderManager::Initialize(HWND _hwnd, int _wid, int _hei)
{

    m_hWnd = _hwnd;
    m_renderSize = { _wid, _hei };
    m_frontDC = GetDC(_hwnd);
    m_backDC = CreateCompatibleDC(m_frontDC);
    _backBitmap = CreateCompatibleBitmap(m_frontDC, m_renderSize.x, m_renderSize.y);
    HBITMAP oldBitmap = (HBITMAP)SelectObject(m_backDC, _backBitmap);
    DeleteObject(oldBitmap);

    GdiplusStartup(&m_GPToken, &m_GPIn, NULL);
    graphics = Gdiplus::Graphics::FromHDC(m_backDC);

    Fadealpha = 0.f;

    FadeOutStart();
}

void RenderManager::Clear()
{
    PatBlt(m_backDC, -1, -1, m_renderSize.x, m_renderSize.y, WHITENESS);
}

void RenderManager::Show()
{
    BitBlt(m_frontDC, -1, -1, m_renderSize.x, m_renderSize.y, m_backDC, 0, 0, SRCCOPY);
}

void RenderManager::Render()
{
    Clear();
    DrawBackGround();
    SceneManager::Get()->Render();
    FadeRectRender();
    SceneManager::Get()->UIRender();
    DialogManager::Get()->Update();
    DialogManager::Get()->Render();
    FadeIn();
    FadeOut();
    Show();
}

void RenderManager::Finalize()
{
    Gdiplus::GdiplusShutdown(m_GPToken);
}

void RenderManager::Reset()
{
    isFadeIn = false;
    isFadeOut = false;
}

bool RenderManager::FadeInOutStart()
{
    if (!isFadeIn && !isFadeOut)
    {
        Fadealpha = 0.f;
        isFadeIn = true;
        isFadeOut = true;
        return true;
    }
    return false;
}

void RenderManager::FadeInStart()
{
    Fadealpha = 0.f;
    isFadeIn = true;
    isFadeOut = false;
}

void RenderManager::FadeOutStart()
{
    Fadealpha = 1.f;
    isFadeOut = true;
    isFadeIn = false;
}

void RenderManager::FadeIn()
{
	if (isFadeIn && Fadealpha < 1.f)
	{
		float d = DELTA;
		Fadealpha += DELTA; // 알파값 증가
		if (Fadealpha >= 1.f)
		{
			Fadealpha = 1.0f;
			isFadeIn = false;
			EventManager::Get()->ProcessEventlist();
		}
	}
}

void RenderManager::FadeOut()
{
	if (!isFadeIn && isFadeOut && Fadealpha > 0)
	{
		Fadealpha -= DELTA; // 알파값 감소
		if (Fadealpha <= 0.f)
		{
			Fadealpha = 0.f;
			isFadeOut = false;
		}
	}
}

bool RenderManager::IsFadeIn()
{
    return isFadeIn;
}

bool RenderManager::IsFadeOut()
{
    return isFadeOut;
}

void RenderManager::FadeRectRender()
{
    Gdiplus::ColorMatrix colorMatrixAlpha = // 알파블렌딩
    {
       1.0f,  0.0f,  0.0f,  0.0f,  0.0f, //r값
       0.0f,  1.0f,  0.0f,  0.0f,  0.0f, //g값
       0.0f,  0.0f,  1.0f,  0.0f,  0.0f, //b값
       0.0f,  0.0f,  0.0f,  Fadealpha,  0.0f, //a값 : 이것만 건드리면..ㅇㅇ
       0.0f,  0.0f,  0.0f,  0.0f,  1.0f,
    };
    Gdiplus::ImageAttributes imgAtt = {};
    imgAtt.SetColorMatrix(&colorMatrixAlpha, Gdiplus::ColorMatrixFlagsDefault, Gdiplus::ColorAdjustTypeBitmap); //알파블렌딩

    // 알파값을 255 범위로 변환
    BYTE alpha = static_cast<BYTE>(Fadealpha * 255);

    // 색상과 브러쉬 생성
    Gdiplus::Color color(alpha, 0, 0, 0);
    Gdiplus::SolidBrush brush(color);

    // 사각형 위치와 크기 설정
    Gdiplus::Rect rect(0, 0, 1024, 768);

    // 그래픽 디바이스 컨텍스트에 사각형 그리기
    graphics->FillRectangle(&brush, rect);
}