#pragma once


class EffectManager : public Singleton<EffectManager>
{
private:

	friend class Singleton;
public:
	void Initialize();

	void FadeIn();
	void FadeOut();
	void Jumping(Vector2 scale, Vector2 pos);
	void Landing(Vector2 scale,Vector2 pos);
	void SetActive(bool isActive) { _obj->SetActive(isActive); }

public:
	Animator* _an;
	Transform* _tr;
	GameObject* _obj;
	GameScene* _curScene;
	Sprite* _sp;
};

