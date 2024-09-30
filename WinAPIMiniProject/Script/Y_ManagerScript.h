#pragma once

class Y_PlayerScript;
class Y_LifeBarScript;
class Y_DashBarScript;
class Y_PauseScript;

class Y_ManagerScript : public Script
{
private:

	Y_PlayerScript* playerScr;
	Y_LifeBarScript* lifebarScr;
	Y_DashBarScript* DashbarScr;
	Y_PauseScript* PausebarScr;

	// 디버깅용
	TextRenderer* trd;
	Transform* p_tr;

	// 게임오버 씬
	GameObject* deadUP;
	GameObject* gameOverScene;
	Transform* gameOverTr;
	TextRenderer* gameOverText;
	Spriterenderer* gameOversprite;
	float RespawnCount = 0.f;

public:

	GameObject* Player;
	GameObject* LifeUI;
	GameObject* DashUI;
	GameObject* PauseUI;

	void Start()
	{
		DontDestroyOnLoad(gameobject);
		{
			trd = gameobject->AddComponent<TextRenderer>();
			trd->SetFont(L"가평한석봉 큰붓 B", L"Asset/Font/GapyeongHanseokbongB.ttf");
			trd->SetColor(RGB(255, 255, 255));
			trd->width = 2;
			trd->height = 20;
			trd->offset = { 5, 3 };
			//trd->OneByOne(true);
			trd->SetActive(false);
		}
		{
			deadUP = gameobject->CreateChild("DeadSprite", ResourceManager::Get()->Find<Sprite>(L"GameOver_Right"));
			gameOversprite = deadUP->GetComponent<Spriterenderer>();
			gameOverTr = deadUP->GetComponent<Transform>();
			gameOverTr->position = { 350, 100 };
			gameOverTr->scale = { 384, 384 };
			gameOversprite->index = 3;

			gameOverScene = gameobject->CreateChild("DeadScene");
			gameOverText = gameOverScene->AddComponent<TextRenderer>();
			gameOverText->SetFont(L"Galmuri11 Regular", L"Asset/Font/Galmuri11.ttf");
			gameOverText->height = 70;
			gameOverText->offset.x = 100;
			gameOverText->offset.y = 150;
			gameOverText->SetColor(RGB(255, 192, 0));
			gameOverText->OneByOne(true);

			deadUP->SetActive(false);
			gameOverScene->SetActive(false);
		}
	}

	void Update()
	{
		// 디버그 단축키
		if (key->IsDown(49))
		{
			if (trd->IsActive())
				trd->SetActive(false);
			else trd->SetActive(true);
		}

		if (trd->IsActive())
		{
			trd->SetText(DebugingText());
		}

		if (Player == nullptr)
		{
			Player = SceneManager::Get()->FindGlobalObject("Player", Layer::Player);
		}
		if (LifeUI == nullptr)
		{
			LifeUI = SceneManager::Get()->FindGlobalObject("LifeBar", Layer::UI);
		}
		if (DashUI == nullptr)
		{
			DashUI = SceneManager::Get()->FindGlobalObject("DashBar", Layer::UI);
		}
		if (PauseUI == nullptr)
		{
			PauseUI = SceneManager::Get()->FindGlobalObject("PauseBar", Layer::UI);
		}
		if (Player != nullptr && LifeUI != nullptr && DashUI != nullptr)
		{
			if (playerScr == nullptr)
			{
				playerScr = Player->GetComponent<Y_PlayerScript>();
				p_tr = Player->GetComponent<Transform>();
			}
			if (lifebarScr == nullptr)
				lifebarScr = LifeUI->GetComponent<Y_LifeBarScript>();
			if (DashbarScr == nullptr)
				DashbarScr = DashUI->GetComponent<Y_DashBarScript>();
			if (PausebarScr == nullptr)
				PausebarScr = PauseUI->GetComponent<Y_PauseScript>();

			if (playerScr != nullptr && lifebarScr != nullptr && 
				DashbarScr != nullptr && PausebarScr != nullptr)
			{
				if (SceneManager::Get()->GetActiveScene()->Get_Tag() == SceneTag::Play)  
				{
					Player->SetActive(true);
					LifeUI->SetActive(true);
					DashUI->SetActive(true);
					PauseUI->SetActive(true);
					if (RenderManager::Get()->GetCamera() != nullptr)
					{
						RenderManager::Get()->GetCamera()->SetActive(true);
					}
				}
				else if (SceneManager::Get()->GetActiveScene()->Get_Tag() != SceneTag::Play)
				{
					Player->SetActive(false);
					LifeUI->SetActive(false);
					DashUI->SetActive(false);
					PauseUI->SetActive(false);
					if (RenderManager::Get()->GetCamera() != nullptr)
					{
						RenderManager::Get()->GetCamera()->SetActive(false);
					}
				}
				if (playerScr->hp == 0)
				{
					LifeUI->SetActive(false);
					DashUI->SetActive(false);
					if (RenderManager::Get()->GetAlpha() >= 1.f)
					{
						RespawnCount += DELTA;
						if (RespawnCount < 1.5)
						{
							gameOverScene->SetActive(true);
							deadUP->SetActive(true);
							std::vector<std::wstring> _temp;
							_temp.push_back(L"꼭 만나야 할 사람이 있는데 . . .");
							gameOverText->SetText(_temp);
						}
						else
						{
							RespawnCount = 0.f;
							RenderManager::Get()->FadeOutStart();
							EventData _event;
							_event.event = Event_List::Respawn;
							_event.objectParam = Player;
							EventManager::Get()->CallEvent(_event);
							Time::Get()->SetTimeScale(1.f);
							RenderManager::Get()->GetCamera()->SetZoom(1.f);
							gameOverScene->SetActive(false);
							deadUP->SetActive(false);
						}
					}
				}
				else
				{
					gameOverScene->SetActive(false);
					deadUP->SetActive(false);
				}
				if (playerScr->InterState == InterType::MONITOR_BIG)
				{
					LifeUI->SetActive(false);
					DashUI->SetActive(false);
				}
			}
		}
		if (KEY_DOWN(112))
		{
			EventData _temp;
			_temp.event = Event_List::GoStage_1;
			_temp.objectParam = Player;
			EventManager::Get()->CallEvent(_temp);
		}
		if (KEY_DOWN(113))
		{
			EventData _temp;
			_temp.event = Event_List::GoStage_2;
			_temp.objectParam = Player;
			EventManager::Get()->CallEvent(_temp);
		}
		if (KEY_DOWN(114))
		{
			EventData _temp;
			_temp.event = Event_List::GoStage_3;
			_temp.objectParam = Player;
			EventManager::Get()->CallEvent(_temp);
		}
		if (KEY_DOWN(115))
		{
			EventData _temp;
			_temp.event = Event_List::GoStage_4;
			_temp.objectParam = Player;
			EventManager::Get()->CallEvent(_temp);
		}
	}
	std::vector<std::wstring> DebugingText()
	{
		std::vector<std::wstring> _temp;
		if (p_tr != nullptr)
		{
			_temp.push_back(L"Fps : " + std::to_wstring(Time::Get()->GetFPS()));
			_temp.push_back(L"현재 씬 : " + SceneManager::Get()->GetActiveScene()->Get_Name());
			_temp.push_back(L"캐릭터 X좌표 : " + std::to_wstring((int)p_tr->worldPosition.x));
			_temp.push_back(L"캐릭터 Y좌표 : " + std::to_wstring((int)p_tr->worldPosition.y));
			_temp.push_back(L"캐릭터 Hp : " + std::to_wstring(playerScr->hp));
		}
		return _temp;
	}
};