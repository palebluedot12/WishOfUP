#include "Framework.h"

void EffectManager::Initialize()
{
	_curScene = SceneManager::Get()->GetActiveScene();
	_obj = _curScene->CreateObject(Layer::Object, ObjectTag::Object, "Effect");

	_an = _obj->AddComponent<Animator>();
	_tr = _obj->GetComponent<Transform>();

	_an->AddAnimation(L"Ef_land", ResourceManager::Get()->Find<Animation>(L"Ef_land"));
	_an->AddAnimation(L"Ef_jump", ResourceManager::Get()->Find<Animation>(L"Ef_jump"));

	_curScene->DontDestroyOnLoad(_obj);
}

void EffectManager::FadeIn()
{
}

void EffectManager::FadeOut()
{
}

void EffectManager::Jumping(Vector2 scale, Vector2 pos)
{
	if (!_curScene)return;
	if (!_obj)return;
	if (!_an)return;

	_tr->scale = scale;
	_tr->position = pos;
	_an->ActiveAnimation(L"Ef_jump", false);
	_an->GotoAndPlay(0);
}


void EffectManager::Landing(Vector2 scale,Vector2 pos)
{
	if (!_curScene)return;
	if (!_obj)return;
	if (!_an)return;

	_tr->scale = scale;
	_tr->position = pos;
	_an->ActiveAnimation(L"Ef_land",false);
	_an->GotoAndPlay(0);
}
