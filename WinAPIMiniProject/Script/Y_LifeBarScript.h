#pragma once

class Y_PlayerScript;

class Y_LifeBarScript : public Script
{
private:

	GameObject* _player;
	Y_PlayerScript* _playerScript;

	Spriterenderer* sp;
	Transform* tr;

public:

	void Start()
	{
		sp = gameobject->AddComponent<Spriterenderer>();

		tr = gameobject->GetComponent<Transform>();
		tr->position = { 40, 20 };
		tr->scale.x = (float)sp->GetSprite()->GetWidth();
		tr->scale.y = (float)sp->GetSprite()->GetHeight();

		gameobject->SetActive(false);

		_player = SceneManager::Get()->FindGlobalObject("Player", Layer::Player);
		DontDestroyOnLoad(gameobject);
	}

	void FixedUpdate()
	{
		if (_player != nullptr)
		{
			if (_playerScript == nullptr)
			{
				_playerScript = _player->GetComponent<Y_PlayerScript>();
			}
			else if (_playerScript != nullptr)
			{
				int hp = _playerScript->hp;
				sp->SetSprite(resource->Find<Sprite>(L"LifeBar_" + std::to_wstring(hp)));
			}
		}
	}
};