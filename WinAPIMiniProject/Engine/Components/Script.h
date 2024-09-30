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

	// =====아래 멤버변수는 생성자를 통해 초기화 해줍니다!!=====

	GameObject* gameobject;
	ResourceManager* resource; // ResourceManager의 인스턴스
	KeyManager* key;
	MouseManager* mouse;

	// =====================================================

	virtual void Start() {} // 컴포넌트를 추가한 직후 바로 호출됩니다.

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