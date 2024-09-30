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

	int index; // ������ �̹����� ��ġ (���������� ���������� �� �پ� ī��Ʈ)

private:

	bool _isActive = true;
	Gdiplus::ColorMatrix colorMatrix;
	Sprite* image;
	HDC hdc;

};