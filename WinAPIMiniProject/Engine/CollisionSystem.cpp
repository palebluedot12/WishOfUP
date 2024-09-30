#include "Framework.h"
#include "CollisionSystem.h"

bool CollisionSystem::AABB(RectCollider* left, RectCollider* right)
{

	Transform* lefttr = left->GetOwner()->GetComponent<Transform>();
	Transform* righttr = right->GetOwner()->GetComponent<Transform>();

	Vector2 _leftPos = lefttr->worldPosition + left->offset;
	Vector2 _rightPos = righttr->worldPosition + right->offset;

	RECT a_rect = { _leftPos.x, _leftPos.y, _leftPos.x + left->size.x, _leftPos.y + left->size.y };
	RECT b_rect = { _rightPos.x, _rightPos.y, _rightPos.x + right->size.x, _rightPos.y + right->size.y };

	if (a_rect.bottom >= b_rect.top && a_rect.top <= b_rect.bottom &&
		a_rect.left <= b_rect.right && a_rect.right >= b_rect.left)
		return true;

	else return false;
}

POINT CollisionSystem::AABB_Dir(RectCollider* left, RectCollider* right)
{
	// AABB충돌 검사가 true일 때
	if (AABB(left, right))
	{
		Transform* lefttr = left->GetOwner()->GetComponent<Transform>();
		Transform* righttr = right->GetOwner()->GetComponent<Transform>();

		Vector2 _leftPos = lefttr->worldPosition + left->offset;
		Vector2 _leftSize = left->size;
		Vector2 _rightPos = righttr->worldPosition + right->offset;
		Vector2 _rightSize = right->size;

		float Dir_arr[4], min = 10000.f;
		int Dir = -1;

		RECT a_rect = { _leftPos.x, _leftPos.y, _leftPos.x + _leftSize.x, _leftPos.y + _leftSize.y };
		RECT b_rect = { _rightPos.x, _rightPos.y, _rightPos.x + _rightSize.x, _rightPos.y + _rightSize.y };

		Dir_arr[0] = a_rect.right - b_rect.left + 1; // a_right Hit To b_left
		Dir_arr[1] = a_rect.left - b_rect.right - 1; // a_left Hit To b_Right
		Dir_arr[2] = a_rect.top - b_rect.bottom; // a_top Hit To b_bottom
		Dir_arr[3] = a_rect.bottom - b_rect.top; // a_bottom Hit To b_top

		// 절대값으로 할 것
		for (int i = 0; i < 4; i++) {
			if (abs(Dir_arr[i]) < min) {
				min = abs(Dir_arr[i]);
				Dir = i;
			}
		}
		if (Dir == 0) return { 1, 0 };
		else if (Dir == 1) return { -1, 0 };
		else if (Dir == 2) return { 0, 1 };
		else if (Dir == 3) return { 0, -1 };
	}
	return { 0, 0 };
}
