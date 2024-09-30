#include "Framework.h"

Spriterenderer::Spriterenderer() : Component()
{
	SetType(ComponentType::Spriterenderer);
	image = nullptr;
	hdc = RenderManager::Get()->Get_BackDC();
	index = 0;
	colorMatrix = // 유피색
	{
		1.0f,  0.0f,  0.0f,  0.0f,  0.0f, //r값
		0.0f,  1.0f,  0.0f,  0.0f,  0.0f, //g값
		0.0f,  0.0f,  1.0f,  0.0f,  0.0f, //b값
		0.0f,  0.0f,  0.0f,  1.0f,  0.0f, //a값 : 이것만 건드리면..ㅇㅇ
		0.0f,  0.0f,  0.0f,  0.0f,  1.0f,
	};
}

Spriterenderer::~Spriterenderer()
{
}

void Spriterenderer::SetSprite(Sprite* _sprite)
{
	image = _sprite;
}

void Spriterenderer::SetColor(float _r, float _g, float _b, float _a, bool _rending)
{
	float temp = _rending;
	colorMatrix = // 유피색
	{
		temp,  0.0f,  0.0f,  0.0f,  0.0f, //r값
		0.0f,  temp,  0.0f,  0.0f,  0.0f, //g값
		0.0f,  0.0f,  temp,  0.0f,  0.0f, //b값
		0.0f,  0.0f,  0.0f, _a,  0.0f, //a값 : 이것만 건드리면..ㅇㅇ
		 _r,  _g,  _b,  0.0f,  1.0f,
	};
}

void Spriterenderer::Render()
{
	if (_isActive)
	{
		// 텍스쳐가 없으면 에러가 나야해용
		if (image == nullptr)
			assert(false);
		Transform* _tr = this->GetOwner()->GetComponent<Transform>();
		// 트랜스폼 컴포넌트를 가지고 있지 않으면 작동할 이유가 없습니당
		if (_tr == nullptr)
			return;

		else if (_tr != nullptr)
		{

			Gdiplus::Graphics* graphics = RenderManager::Get()->Get_Grapics();

			Vector2 _pos = _tr->worldPosition;
			Vector2 _sca = _tr->scale;

			if (GetOwner()->GetTag() != ObjectTag::UI)
			{

				Camera* ca = RenderManager::Get()->GetCamera();

				if (ca != nullptr && ca->GetActive())
				{
					Vector2 viewportMin = RenderManager::Get()->GetCamera()->GetViewportMin();
					Vector2 viewportMax = RenderManager::Get()->GetCamera()->GetViewportMax();

					// offset.x 각각 - , +해보면 지워지는거 확인 가능
					if (_pos.x + _sca.x < viewportMin.x || _pos.x > viewportMax.x ||
						_pos.y + _sca.y < viewportMin.y || _pos.y > viewportMax.y)
					{
						return;
					}
					_pos = RenderManager::Get()->GetCamera()->CalculatePosition(_pos);
					_sca = RenderManager::Get()->GetCamera()->CalculateSize(_sca);
				}
			}

			if (image->GetExt() == ExtType::Bmp)
			{
				// 투명화 시킬 픽셀의 색 범위
				Gdiplus::Color _alpha_Color(255, 0, 255);
				Gdiplus::ImageAttributes imgAtt = {};
				imgAtt.SetColorKey(_alpha_Color, _alpha_Color, Gdiplus::ColorAdjustTypeBitmap);
				imgAtt.SetColorMatrix(&colorMatrix, Gdiplus::ColorMatrixFlagsDefault, Gdiplus::ColorAdjustTypeBitmap);

				Gdiplus::Rect srcRect(
					(index % image->data.count.x) * image->GetWidth()
					, (index / image->data.count.x) * image->GetHeight()
					, image->GetWidth()
					, image->GetHeight()); // 소스의 영역
				Gdiplus::Rect destRect(_pos.x, _pos.y, _sca.x, _sca.y); // 화면에 그릴 영역	

				graphics->DrawImage(image->GetBitmap()
					, destRect, srcRect.X, srcRect.Y, srcRect.Width, srcRect.Height
					, Gdiplus::UnitPixel, &imgAtt);
			}
			else if (image->GetExt() == ExtType::Png)
			{
				Gdiplus::ImageAttributes imgAtt = {};
				imgAtt.SetColorMatrix(&colorMatrix, Gdiplus::ColorMatrixFlagsDefault, Gdiplus::ColorAdjustTypeBitmap);

				graphics->DrawImage(image->GetImage()
					, Gdiplus::Rect(_pos.x, _pos.y, _sca.x, _sca.y)
					, (index % image->data.count.x) * image->GetWidth()
					, (index / image->data.count.x) * image->GetHeight()
					, image->GetWidth()
					, image->GetHeight()
					, Gdiplus::UnitPixel
					, &imgAtt);
			}
		}
	}
}