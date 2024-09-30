#include "Framework.h"

void GameScene::SetInfo(SceneTag _tag, std::wstring _key)
{
    this->sceneTag = _tag;
    this->sceneName = _key;
}

GameScene::~GameScene()
{
    for (int i = 0; i < (int)Layer::Size; i++) {
        for (auto obj : objectList[i]) {
            delete obj;
        }
        objectList[i].clear(); // 리스트를 비워줍니다.
    }
}

GameObject* GameScene::CreateObject(Layer _layer, ObjectTag _tag, std::string _key, Sprite* _sprite)
{
	GameObject* _obj = new GameObject(_layer, _tag, _key);
    Transform* _tr = _obj->AddComponent<Transform>();
    if (_sprite != nullptr)
    {
        Spriterenderer* _sp =_obj->AddComponent<Spriterenderer>();
        _sp->SetSprite(_sprite);
        _tr->scale = { (float)_sp->GetSprite()->GetWidth(), (float)_sp->GetSprite()->GetHeight() };
    }
        
    _obj->SetOwner(this);
	this->objectList[(int)_layer].push_back(_obj);
	return _obj;
}

GameObject* GameScene::FindObject(std::string _key, Layer _layer)
{
    for (int i = (int)_layer; i < (int)Layer::Size; i++)
    {
        for (auto it = objectList[i].begin(); it != objectList[i].end(); ++it)
        {
            if ((*it)->GetName() == _key)
            {
                return *it;
            }
        }
    }
    return nullptr;
}

bool GameScene::DestroyObject(std::string _key, Layer _layer)
{
    for (int i = (int)_layer; i < (int)Layer::Size; i++)
    {
        for (auto it = objectList[i].begin(); it != objectList[i].end(); ++it)
        {
            if ((*it)->GetName() == _key)
            {
                delete* it;
                *it = nullptr;
                objectList[i].erase(it);
                return true;
            }
        }
    }
    return false;
}

void GameScene::DontDestroyOnLoad(GameObject* _target)
{   
    SceneManager::Get()->GetGlobalObjectList()[(int)_target->GetLayer()].push_back(_target);
    std::list<GameObject*> arr = SceneManager::Get()->GetGlobalObjectList()[(int)Layer::Player];

    for (auto it = objectList[(int)_target->GetLayer()].begin(); it != objectList[(int)_target->GetLayer()].end(); ++it)
    {
        if ((*it)->GetName() == _target->GetName())
        {
            objectList[(int)_target->GetLayer()].erase(it);
            break;
        }
    }
}