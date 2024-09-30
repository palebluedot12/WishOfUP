#pragma once

class RenderManager : public Singleton<RenderManager>
{

private:
	friend class Singleton;
	RenderManager() = default;
	~RenderManager() = default;

	void DrawBackGround();

public:

	void Initialize(HWND _hwnd, int _wid, int _hei);
	void Render();
	void Finalize();

	void Reset();

	bool FadeInOutStart();
	void FadeInStart();
	void FadeOutStart();
	bool IsFadeIn();
	bool IsFadeOut();
	void FadeRectRender();
	
	
	HWND Get_HWND() { return m_hWnd; }
	HDC Get_FrontDC() { return m_frontDC; }
	HDC Get_BackDC() { return m_backDC; }
	Gdiplus::Graphics* Get_Grapics() { return  graphics; }
	HBITMAP GetBitmap() { return _backBitmap; }
	Camera* GetCamera() { return _mainCamera; }
	bool GetColliderRender() { return colliderRender; }
	float GetAlpha() { return Fadealpha; }

	// ���� ������ ī�޶� �����մϴ�.
	void SetCamera(Camera* _target) { _mainCamera = _target; }
	void ColliderRender(bool _val) { colliderRender = _val; }

private:

	float Fadealpha;
	bool isFadeIn;
	bool isFadeOut;

	bool colliderRender = false;

	void Clear();
	void Show();
	// ���� ������ ī�޶�
	Camera* _mainCamera;

	// ��¿� ���õ� DC �� �ڵ� ���� �����Դϴ�
	HWND m_hWnd;
	HDC m_frontDC;
	HDC m_backDC;
	POINT m_renderSize;
	HBITMAP _backBitmap;
	// �Ʒ� ���ʹ�  GDIPlus���� ����մϴ�.
	Gdiplus::Graphics* graphics = nullptr;
	ULONG_PTR m_GPToken;
	Gdiplus::GdiplusStartupInput m_GPIn;

	void FadeIn();
	void FadeOut();
	void FadeInOut();
};

