#include "Framework.h"

Animator::Animator()
	: animationList{}
{
	SetType(ComponentType::Animator);
	hdc = RenderManager::Get()->Get_BackDC();
	activeAnimation = nullptr;
	isLoop = false;
	isStop = false;
	frame = 0;
	frameCount = 0.f;
}

Animator::~Animator()
{
	for (auto& it : animationList)
	{
		delete it.second;
		it.second = nullptr;
	}
}

void Animator::AddAnimation(std::wstring _key, Animation* _ani)
{

	if (_ani == nullptr)
		assert(false);

	if (FindAnimation(_key) != nullptr)
		return;

	_ani->SetOwner(this);
	animationList.insert(std::make_pair(_key, _ani));

}

Animation* Animator::FindAnimation(const std::wstring& _key)
{
	auto it = animationList.find(_key);
	if (it == animationList.end())
		return nullptr;
	return it->second;
}

void Animator::ActiveAnimation(const std::wstring& _key, bool _loop)
{
	Animation* _ani = FindAnimation(_key);
	if (_ani == nullptr)
		assert(false);
	if (_ani == activeAnimation)
		return;

	isLoop = _loop;
	frame = 0;
	frameCount = 0.f;
	isStop = false;
	activeAnimation = _ani;
}

int Animator::GetFrame()
{
	return frame;
}

void Animator::GotoAndPlay(int _val)
{
	if (activeAnimation)
	{
		this->frame = _val;
		this->isStop = false;
	}
}

void Animator::GotoAndStop(int _val)
{
	if (activeAnimation)
	{
		this->frame = _val;
		this->isStop = true;
	}
}

void Animator::GotoAndNextFrame()
{
	this->frame++;
	this->frameCount = 0.f;
}

void Animator::GotoAndPrevFrame()
{
	this->frame--;
	this->frameCount = 0.f;
}

void Animator::Play()
{
	if (activeAnimation)
		this->isStop = false;
}

void Animator::Stop()
{
	if (activeAnimation)
		this->isStop = true;
}

bool Animator::IsEnd()
{
	return (frame >= activeAnimation->GetClip().size() - 1) && frameCount >= activeAnimation->GetClip()[frame].second;
}

void Animator::Update()
{
	if (activeAnimation)
	{
		if (!isStop)
		{
			frameCount += DELTA;

			if (frameCount > activeAnimation->GetClip()[frame].second)
			{
				if (!IsEnd())
				{
					frame++;
					frameCount = 0.f;
				}
				else if (IsEnd() && isLoop)
				{
					GotoAndPlay(0);
					frameCount = 0.f;
				}	
			}
		}
	}
}



void Animator::Render()
{
	// 텍스쳐가 없으면 에러가 나야해용
	if (activeAnimation == nullptr)
		return;
	Transform* _tr = this->GetOwner()->GetComponent<Transform>();
	// 트랜스폼 컴포넌트를 가지고 있지 않으면 작동할 이유가 없습니당
	if (_tr == nullptr)
		return;

	else if (_tr != nullptr)
	{
		std::vector<std::pair<int, float>>& _Clip = activeAnimation->GetClip();
		Vector2 _pos = _tr->worldPosition;
		Vector2 _sca = _tr->scale;
		int index = _Clip[frame].first;

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
		Gdiplus::Graphics* graphics = RenderManager::Get()->Get_Grapics();

		if (activeAnimation->GetExt() == ExtType::Bmp)
		{
			// 투명화 시킬 픽셀의 색 범위
			Gdiplus::Color _alpha_Color(255, 0, 255);
			Gdiplus::ColorMatrix colorMatrixAlpha = // 알파블렌딩
			{
				1.0f,  0.0f,  0.0f,  0.0f,  0.0f, //r값
				0.0f,  1.0f,  0.0f,  0.0f,  0.0f, //g값
				0.0f,  0.0f,  1.0f,  0.0f,  0.0f, //b값
				0.0f,  0.0f,  0.0f,  _alpha,  0.0f, //a값 : 이것만 건드리면..ㅇㅇ
				0.0f,  0.0f,  0.0f,  0.0f,  1.0f,
			};
			Gdiplus::ImageAttributes imgAtt = {};
			imgAtt.SetColorKey(_alpha_Color, _alpha_Color, Gdiplus::ColorAdjustTypeBitmap);
			imgAtt.SetColorMatrix(&colorMatrixAlpha, Gdiplus::ColorMatrixFlagsDefault, Gdiplus::ColorAdjustTypeBitmap); //알파블렌딩

			Gdiplus::Rect srcRect(
				(index % activeAnimation->GetImage()->data.count.x) * activeAnimation->GetImage()->GetWidth()
				, (index / activeAnimation->GetImage()->data.count.x) * activeAnimation->GetImage()->GetHeight()
				, activeAnimation->GetImage()->GetWidth()
				, activeAnimation->GetImage()->GetHeight()); // 소스의 영역
			Gdiplus::Rect destRect(_pos.x, _pos.y, _sca.x, _sca.y); // 화면에 그릴 영역	

			graphics->DrawImage(activeAnimation->GetImage()->GetBitmap()
				, destRect, srcRect.X, srcRect.Y, srcRect.Width, srcRect.Height
				, Gdiplus::UnitPixel, &imgAtt);
		}
		else if (activeAnimation->GetImage()->GetExt() == ExtType::Png)
		{
			graphics->DrawImage(activeAnimation->GetImage()->GetImage()
				, Gdiplus::Rect(_pos.x, _pos.y, _sca.x, _sca.y)
				, (index % activeAnimation->GetImage()->data.count.x) * activeAnimation->GetImage()->GetWidth()
				, (index / activeAnimation->GetImage()->data.count.x) * activeAnimation->GetImage()->GetHeight()
				, activeAnimation->GetImage()->GetWidth()
				, activeAnimation->GetImage()->GetHeight()
				, Gdiplus::UnitPixel
				, nullptr);
		}
	}
}
