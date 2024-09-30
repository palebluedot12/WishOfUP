#pragma once
class Transform : public Component
{
public:
	// �������� �� ���� ���� ������ ���� �ؾ��ϴ� ��������� public���� �����ϴ�.
	Vector2 position;
	float rotation;
	Vector2 scale;

	Vector2 worldPosition;

	virtual void Update() override;

	Transform();
	~Transform() {}

private:

};

