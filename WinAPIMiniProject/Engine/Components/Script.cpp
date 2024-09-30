#include "Framework.h"

Script::Script()
{
	this->SetType(ComponentType::Script);
	this->resource = ResourceManager::Get();
	this->key = KeyManager::Get();
	this->mouse = MouseManager::Get();
}

Script::~Script()
{
}

// 씬오브젝트를 전역오브젝트로 전환합니다.
void Script::DontDestroyOnLoad(GameObject* _target)
{
	_target->GetOwner()->DontDestroyOnLoad(_target);
}

bool Script::Destroy(GameObject* _target)
{
	return _target->GetOwner()->DestroyObject(_target->GetName(), _target->GetLayer());
}
