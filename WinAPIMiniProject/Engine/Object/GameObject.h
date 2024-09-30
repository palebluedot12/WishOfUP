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

	// Ư�� ������Ʈ�� �߰��� �� ��ȯ
	template<class T>
	T* AddComponent()
	{
		T* _temp = new T();
		_temp->SetOwner(this);
		// Ŭ���� Ÿ���� �޾ƿ´�.
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
	// Ư�� ������Ʈ ��ȯ
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
	// ������Ʈ ����
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
		return false; // ���� �� false ��ȯ
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
	bool isDelete = false; // ������ �� ������Ʈ�߿� �����ϸ� �������� ������Ʈ�� ����� �� �����ϱ� ���� �뵵�� ����

	GameScene* owner;

	ObjectTag tag;
	Layer layer;
	std::string name;

	// ������Ʈ�� �����ϴ� �迭
	Component* componentList[(int)ComponentType::Size]{ nullptr, };
	// ��ũ��Ʈ�� �����ϴ� �迭
	std::vector<Component*> scryptList;

	std::vector<GameObject*> childList;
	GameObject* parent;

};