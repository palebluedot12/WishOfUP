#include "Framework.h"

Transform::Transform()
{
	SetType(ComponentType::Transform);
	position = { 0,0 };
	rotation = 0.f;
	scale = { 0,0 };
	worldPosition = { 0,0 };
}

void Transform::Update()
{
	// �θ� ������Ʈ�� ���� ��
	if (this->GetOwner()->GetParent() != nullptr)
	{
		this->worldPosition = this->GetOwner()->GetParent()->GetComponent<Transform>()->position + this->position;
	}
	else
	{
		this->worldPosition = this->position;
	}
}