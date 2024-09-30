#pragma once
class Collider;
class Script;

class GameObject
{
public:

	GameObject(Layer _layer = Layer::Default, ObjectTag _type = ObjectTag::Default
		, std::string _key = "");
	~GameObject();

	void Update();
	void FixedUpdate();
	void LateUpdate();
	void Render();

	std::string GetName() const { return name; }
	ObjectTag GetTag() const { return tag; }
	Layer GetLayer() const { return layer; }
	bool GetActive() const { return isActive; }

	void SetActive(bool _val) { isActive = _val; }

	// 특정 컴포넌트를 추가한 후 반환
	template<class T>
	T* AddComponent()
	{
		T* _temp = new T();
		_temp->SetOwner(this);
		// 클래스 타입을 받아온다.
		ComponentType _type = _temp->GetType();

		if (_type != ComponentType::Script) {
			if (componentList[(int)_type] == nullptr) {
				componentList[(int)_type] = _temp;
				_temp->Initialize();
			}
			else return dynamic_cast<T*>(componentList[(int)_type]);
		}
		else if (_type == ComponentType::Script)
		{
			scryptList.push_back(_temp);
			_temp->Initialize();
		}
		return _temp;
	}
	// 특정 컴포넌트 반환
	template<class T>
	T* GetComponent()
	{
		T* _temp;

		for (Component* comp : componentList)
		{
			if (_temp = dynamic_cast<T*>(comp))
				return _temp;
		}

		for (Component* scr : scryptList)
		{
			if (_temp = dynamic_cast<T*>(scr))
				return _temp;
		}
		return nullptr;
	}
	// 컴포넌트 삭제
	template<class T>
	bool RemoveComponent()
	{
		T* _temp;

		for (int i = 0; i < (int)ComponentType::Size; i++)
		{
			if (_temp = dynamic_cast<T*>(componentList[i]))
			{
				delete componentList[i];
				componentList[i] = nullptr;
				return true;
			}
				
		}
		for (int i = 0; i < scryptList.size(); i++)
		{
			if (_temp = dynamic_cast<T*>(scryptList[i]))
			{
				delete scryptList[i];
				scryptList.erase(i);
				return true;
			}
		}
		return false; // 실패 시 false 반환
	}

	GameObject* CreateChild(std::string _key, Sprite* _sprite = nullptr);

	GameScene* GetOwner() { return owner; }
	GameObject* GetParent() { return parent; }
	std::vector<GameObject*> GetChild() { return childList; }
	std::vector<Component*>& GetScripts() { return scryptList; }

	void SetOwner(GameScene* _owner) { owner = _owner; }
	void Delete() { isDelete = true; }
	bool IsDelete() { return isDelete; }

private:

	bool isActive;
	bool isDelete = false; // 삭제할 때 업데이트중에 삭제하면 에러나서 업데이트가 종료된 후 삭제하기 위한 용도의 변수

	GameScene* owner;

	ObjectTag tag;
	Layer layer;
	std::string name;

	// 컴포넌트를 저장하는 배열
	Component* componentList[(int)ComponentType::Size]{ nullptr, };
	// 스크립트를 저장하는 배열
	std::vector<Component*> scryptList;

	std::vector<GameObject*> childList;
	GameObject* parent;

};