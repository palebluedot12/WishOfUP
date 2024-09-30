#pragma once

class Sprite;

class Spriterenderer : public Component
{
public:

	Spriterenderer();
	~Spriterenderer();

	void SetSprite(Sprite* _sprite);
	void SetColor(float _r = 1.f, float _g = 1.f, float _b = 1.f, float _a = 1.f, bool _rending = true);
	Sprite* GetSprite() { return image; }
	void SetActive(bool _val) { _isActive = _val; }
	bool GetActive() { return _isActive; }

	virtual void Render() override;

	int index; // 가져올 이미지의 위치 (왼쪽위부터 오른쪽으로 한 줄씩 카운트)

private:

	bool _isActive = true;
	Gdiplus::ColorMatrix colorMatrix;
	Sprite* image;
	HDC hdc;

};