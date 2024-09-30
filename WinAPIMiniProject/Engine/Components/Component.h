#pragma once

class GameObject;

class Component
{
public:

	Component() = default;
	~Component() = default;

	virtual void Initialize() {}
	virtual void Update() {}
	virtual void FixedUpdate() {}
	virtual void LateUpdate() {}
	virtual void Render() {}

	ComponentType GetType() const { return type; }
	GameObject* GetOwner() const { return owner; }

	void SetType(ComponentType _type) { type = _type; }
	void SetOwner(GameObject* _owner) { owner = _owner; }

private:

	GameObject* owner = nullptr; // 소유 중인 오브젝트를 가르키는 포인터
	ComponentType type; // 해당 컴포넌트의 타입

};

