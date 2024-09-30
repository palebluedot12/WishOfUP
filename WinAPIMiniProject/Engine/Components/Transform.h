#pragma once
class Transform : public Component
{
public:
	// 포지션은 쓸 일이 많고 수정도 자주 해야하는 멤버변수라 public으로 뺏습니다.
	Vector2 position;
	float rotation;
	Vector2 scale;

	Vector2 worldPosition;

	virtual void Update() override;

	Transform();
	~Transform() {}

private:

};

