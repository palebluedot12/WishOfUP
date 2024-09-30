#pragma once

class GameObject;
class GameScene;
class ResourceManager;
class KeyManager;
class MouseManager;

class Script : public Component
{
public:

	Script();
	~Script();

	// =====�Ʒ� ��������� �����ڸ� ���� �ʱ�ȭ ���ݴϴ�!!=====

	GameObject* gameobject;
	ResourceManager* resource; // ResourceManager�� �ν��Ͻ�
	KeyManager* key;
	MouseManager* mouse;

	// =====================================================

	virtual void Start() {} // ������Ʈ�� �߰��� ���� �ٷ� ȣ��˴ϴ�.

	virtual void Initialize() override { 
		gameobject = GetOwner();
		Start(); 
	}
	virtual void Update() {}
	virtual void FixedUpdate() {}
	virtual void LateUpadte() {}

	void DontDestroyOnLoad(GameObject* _target);
	bool Destroy(GameObject* _target);

	virtual void OnCollision(GameObject* _toHit) {}

private:
	
};