#pragma once

class SceneManager;
class GameObject;

class GameScene
{
public:

	GameScene() = default;
	~GameScene();

	// �� ������ ȣ��˴ϴ�. ��ӽ����� ���̶� �����Լ��� �����ϴ�
	virtual void SceneEnter() {}
	// �� �Ҹ� ������ ȣ��˴ϴ�. ���� �����ϰ� �����Լ��� �����ϴ�
	virtual void SceneExit() {}

	// ������Ʈ�� �̸��� ��ȯ�մϴ�.
	std::wstring Get_Name() const { return this->sceneName; }
	// ������Ʈ�� �±׸� ��ȯ�մϴ�.
	SceneTag Get_Tag() const { return this->sceneTag; }

	// ���� ���� ������Ʈ����Ʈ�� ��ȯ�մϴ�.
	std::list<GameObject*>* GetObjectList() { return objectList; }

	// ������Ʈ�� ���� �� �ش� ������Ʈ�� ��ȯ�մϴ�.
	GameObject* CreateObject(Layer _layer = Layer::Default, ObjectTag _tag = ObjectTag::Object
		, std::string _key = "", Sprite*_sprite = nullptr);
	// ������Ʈ�� ã�� �� �ش� ������Ʈ�� ��ȯ�մϴ�.
	GameObject* FindObject(std::string _key, Layer _layer = Layer::Default);
	// ������Ʈ�� ������ �� ������ �����ϸ� true, �����ϸ� false�� ��ȯ�մϴ�.
	bool DestroyObject(std::string _key, Layer _layer = Layer::Default);
	// ��������Ʈ�� ����������Ʈ�� �����ϴ�.
	void DontDestroyOnLoad(GameObject* _target);

	// ���� ���� �� ȣ���ϴ� �Լ��Դϴ�. �ܺο��� ���� x
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

	

	// ���̾�� ������Ʈ�� �����մϴ�
	std::list<GameObject*> objectList[(int)Layer::Size];

};