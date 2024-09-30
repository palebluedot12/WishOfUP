#pragma once

class Y_PlayerScript;

class Y_DashBarScript : public Script
{
private:

	Spriterenderer* sp;
	Transform* tr;

	// 플레이어 정보 가져오기
	GameObject* _player;
	Y_PlayerScript* _playerScript;

public:

	void Start()
	{
		sp = gameobject->GetComponent<Spriterenderer>();
		tr = gameobject->GetComponent<Transform>();

		tr->position = { 350, 40 };

		gameobject->SetActive(false);

		_player = SceneManager::Get()->FindGlobalObject("Player", Layer::Player);

		DontDestroyOnLoad(gameobject);
	}

	void Update()
	{
		if (_player != nullptr)
		{
			if (_playerScript == nullptr)
			{
				_playerScript = _player->GetComponent<Y_PlayerScript>();
			}
			else if (_playerScript != nullptr)
			{
				float dashTimer = _playerScript->dashTimer;
				float dashCoolTime = _playerScript->dashCoolTime;
				if (dashTimer >= dashCoolTime)
				{
					sp->index = 0;
				}
				else sp->index = 1;
			}
		}
	}

};