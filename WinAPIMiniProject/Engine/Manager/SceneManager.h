#pragma once

class SceneManager : public Singleton<SceneManager>
{

private:
	friend class Singleton;
	SceneManager() = default;
	~SceneManager() = default;

public:
	// Scene을 추가한 후 GameScene* 타입을 반환합니다.
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
	// 씬을 태그별로 관리
	std::vector<GameScene*> Scene_list[(int)SceneTag::Size];
	GameScene* Active_Scene = nullptr;
	// 전역으로 쓸 오브젝트는 여기서 관리합니다. (ex/ 캐릭터는 씬이 넘어가도 유지가 되야 할 때)
	std::list<GameObject*> globalObjectList[(int)Layer::Size];
};