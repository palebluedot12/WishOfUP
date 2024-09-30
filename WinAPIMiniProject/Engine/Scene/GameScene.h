#pragma once

class SceneManager;
class GameObject;

class GameScene
{
public:

	GameScene() = default;
	~GameScene();

	// 씬 생성시 호출됩니다. 상속시켜줄 것이라 가상함수로 뺐습니다
	virtual void SceneEnter() {}
	// 씬 소멸 직전에 호출됩니다. 위와 동일하게 가상함수로 뺐습니다
	virtual void SceneExit() {}

	// 오브젝트의 이름을 반환합니다.
	std::wstring Get_Name() const { return this->sceneName; }
	// 오브젝트의 태그를 반환합니다.
	SceneTag Get_Tag() const { return this->sceneTag; }

	// 현재 씬의 오브젝트리스트를 반환합니다.
	std::list<GameObject*>* GetObjectList() { return objectList; }

	// 오브젝트를 만든 후 해당 오브젝트를 반환합니다.
	GameObject* CreateObject(Layer _layer = Layer::Default, ObjectTag _tag = ObjectTag::Object
		, std::string _key = "", Sprite*_sprite = nullptr);
	// 오브젝트를 찾은 후 해당 오브젝트를 반환합니다.
	GameObject* FindObject(std::string _key, Layer _layer = Layer::Default);
	// 오브젝트를 삭제한 후 삭제가 성공하면 true, 실패하면 false를 반환합니다.
	bool DestroyObject(std::string _key, Layer _layer = Layer::Default);
	// 씬오브젝트를 전역오브젝트로 보냅니다.
	void DontDestroyOnLoad(GameObject* _target);

	// 씬을 만들 때 호출하는 함수입니다. 외부에서 접근 x
	void SetInfo(SceneTag _tag, std::wstring _key);

	void SetBackGround(Sprite* _sprite) { backGround = _sprite; }
	Sprite* GetBackGround() { return backGround; }

	Vector2 MapSize;
	Vector2 SpawnPoint_1;
	Vector2 SpawnPoint_2;
	SoundList BGSound = SoundList::None;

private:

	Sprite* backGround;
	std::wstring sceneName;
	SceneTag sceneTag;

	

	// 레이어별로 오브젝트를 관리합니당
	std::list<GameObject*> objectList[(int)Layer::Size];

};