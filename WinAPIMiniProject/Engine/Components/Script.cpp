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

// ��������Ʈ�� ����������Ʈ�� ��ȯ�մϴ�.
void Script::DontDestroyOnLoad(GameObject* _target)
{
	_target->GetOwner()->DontDestroyOnLoad(_target);
}

bool Script::Destroy(GameObject* _target)
{
	return _target->GetOwner()->DestroyObject(_target->GetName(), _target->GetLayer());
}
