#pragma once

class GameResource;

class Sprite : public GameResource
{
public:

	Sprite();
	~Sprite();

	bool Load(const std::wstring& _path);

	Gdiplus::Image* GetImage() { return m_image; }
	Gdiplus::Bitmap* GetBitmap() { return m_bitmap; }
	HDC GetHDC() { return m_hdc; }
	int GetWidth() { return data.fullSize.x / data.count.x; }
	int GetHeight() { return data.fullSize.y / data.count.y; }

	// 스프라이트 정보
	SpriteData data;

private:

	Gdiplus::Image* m_image;
	Gdiplus::Bitmap* m_bitmap;
	HDC m_hdc;

};