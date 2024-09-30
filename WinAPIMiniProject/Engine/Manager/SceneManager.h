#pragma once

class SceneManager : public Singleton<SceneManager>
{

private:
	friend class Singleton;
	SceneManager() = default;
	~SceneManager() = default;

public:
	// Scene�� �߰��� �� GameScene* Ÿ���� ��ȯ�մϴ�.
	template <typename T>
	GameScene* CreateScene(SceneTag _tag, std::wstring _key)
	{
		T* _scene = new T();
		_scene->SetInfo(_tag, _key);
		_scene->SceneEnter();
		Scene_list[(int)_tag].push_back(_scene);
		return _scene;
	}

	template <typename T>
	GameScene* FindScene()
	{
		for (int i = 0; i < (int)SceneTag::Size; i++)
		{
			for (int j = 0; j < Scene_list[i].size(); j++)
			{
				T* _temp = dynamic_cast<T*>(Scene_list[i][j]);
				if (_temp) 
				{
					return _temp;
				}
			}
		}
		return nullptr;
	}
	template <typename T>
	GameScene* DestroyScene()
	{
		for (int i = 0; i < (int)SceneTag::Size; i++)
		{
			for (int j = 0; j < Scene_list[i].size(); j++)
			{
				T* _temp = dynamic_cast<T*>(Scene_list[i][j]);
				if (_temp) 
				{
					_temp->SceneExit();
					delete Scene_list[i][j];
					Scene_list->erase(j);
				}
			}
		}
		return nullptr;
	}

	GameScene* GetActiveScene();
	std::list<GameObject*>* GetGlobalObjectList() { return globalObjectList; }

	bool LoadScene(const SceneTag _type, std::wstring _key);
	bool LoadScene(GameScene* _scene);
	GameObject* FindGlobalObject(std::string _key, Layer _layer = Layer::Default);

	void Initialize();
	void Update();
	void FixedUpdate();
	void LateUpdate();
	void Render();
	void UIRender();

private:
	// ���� �±׺��� ����
	std::vector<GameScene*> Scene_list[(int)SceneTag::Size];
	GameScene* Active_Scene = nullptr;
	// �������� �� ������Ʈ�� ���⼭ �����մϴ�. (ex/ ĳ���ʹ� ���� �Ѿ�� ������ �Ǿ� �� ��)
	std::list<GameObject*> globalObjectList[(int)Layer::Size];
};