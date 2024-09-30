#include "Framework.h"

GameObject::GameObject(Layer _layer, ObjectTag _tag, std::string _key)
{
	this->layer = _layer;
	this->tag = _tag;
	this->name = _key;
	this->isActive = true;
	this->parent = nullptr;
}
// 소멸자 호출 시 모든 힙 할당을 삭제
GameObject::~GameObject()
{
	for (int i = 0; i < (int)ComponentType::Size; i++)
	{
		delete componentList[i];
		// 세간에는 delete를 해도 nullptr로 변하지 않는다는 소문이 있습니다 조심 ㄷㄷ
		componentList[i] = nullptr;
	}
	for (int i = 0; i < scryptList.size(); i++)
	{
		delete scryptList[i];
	}
	scryptList.clear();
}

void GameObject::Update() 
{
	if (isActive)
	{
		if (!isDelete)
		{
			for (Component* scr : scryptList)
			{
				scr->Update();
				if (isDelete) break;
			}
		}
		if (!isDelete)
		{
			for (Component* comp : componentList)
			{
				if (comp)
					comp->Update();
				if (isDelete) break;
			}
		}
	}
}

void GameObject::FixedUpdate()
{
	if (isActive)
	{
		if (!isDelete)
		{
			for (Component* scr : scryptList)
			{
				scr->FixedUpdate();
				if (isDelete) break;
			}
		}
		if (!isDelete)
		{
			for (Component* comp : componentList)
			{
				if (comp)
					comp->FixedUpdate();
				if (isDelete) break;
			}
		}
	}
}

void GameObject::LateUpdate()
{
	if (isActive)
	{
		if (!isDelete)
		{
			for (Component* scr : scryptList)
			{
				scr->LateUpdate();
				if (isDelete) break;
			}
		}
		if (!isDelete)
		{
			for (Component* comp : componentList)
			{
				if (comp)
					comp->LateUpdate();
				if (isDelete) break;
			}
		}
	}
}

void GameObject::Render()
{
	if (isActive)
	{
		for (Component* comp : componentList)
		{
			if (comp)
				comp->Render();
		}
	}
}

GameObject* GameObject::CreateChild(std::string _key, Sprite* _sprite)
{
	GameObject* _ui = new GameObject(this->GetLayer(), this->GetTag(), _key);
	Transform* _tr = _ui->AddComponent<Transform>();
	if (_sprite != nullptr)
	{
		Spriterenderer* _sp = _ui->AddComponent<Spriterenderer>();
		_sp->SetSprite(_sprite);
		_tr->scale = { (float)_sp->GetSprite()->GetWidth(), (float)_sp->GetSprite()->GetHeight() };
	}
	_ui->SetOwner(this->GetOwner());
	_ui->parent = this;

	this->childList.push_back(_ui);

	return _ui;
}