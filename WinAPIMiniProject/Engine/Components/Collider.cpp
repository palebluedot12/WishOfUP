#include "Framework.h"

//Rect
RectCollider::RectCollider()
{
	SetType(ComponentType::RectCollider);
	isActive = true;
}

RectCollider::~RectCollider()
{
}


void RectCollider::Initialize()
{
	Transform* _tr = GetOwner()->GetComponent<Transform>();
	if (_tr != nullptr)
	{
		this->size = _tr->scale;
	}
}

void RectCollider::Render()
{
	if (!isActive) return;
	if (!RenderManager::Get()->GetColliderRender()) return;

	Transform* _tr = this->GetOwner()->GetComponent<Transform>();

	if (_tr != nullptr)
	{
		HDC _hdc = RenderManager::Get()->Get_BackDC();

		Vector2 _pos = _tr->worldPosition + offset;
		Vector2 _sca = size;

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

		HPEN alphaPen = CreatePen(PS_SOLID, 2, RGB(100, 255, 100));
		HPEN oldPen = (HPEN)SelectObject(_hdc, alphaPen);
		HBRUSH alphaBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(_hdc, alphaBrush);

		Rectangle(_hdc, _pos.x
			, _pos.y
			, _pos.x + _sca.x
			, _pos.y + _sca.y);

		SelectObject(_hdc, oldBrush);
		SelectObject(_hdc, oldPen);
		DeleteObject(alphaPen);
	}
}


//Circle
CircleCollider::CircleCollider()
{
	SetType(ComponentType::CircleCollider);
	radius = 0.f;
	isActive = true;
}

CircleCollider::~CircleCollider()
{
}

void CircleCollider::Initialize()
{

	Transform* _tr = GetOwner()->GetComponent<Transform>();

	if (_tr != nullptr)
	{
		this->radius = _tr->scale.x;
	}
}

void CircleCollider::Render()
{
	if (!isActive) return;
	if (!RenderManager::Get()->GetColliderRender()) return;

	Transform* _tr = this->GetOwner()->GetComponent<Transform>();

	if (_tr != nullptr)
	{
		HDC _hdc = RenderManager::Get()->Get_BackDC();

		Vector2 _pos = _tr->position;

		Ellipse(_hdc, _pos.x + offset.x
			, _pos.y + offset.y
			, _pos.x + offset.x + size.x
			, _pos.y + offset.y + size.y);
	}
}