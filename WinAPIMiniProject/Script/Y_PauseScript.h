#pragma once

class Y_PauseScript : public Script
{
private:

	GameObject* Pause_Window;
	GameObject* Pause_Base;
	GameObject* Volume_Bar;
	GameObject* X_Button;
	GameObject* Volume_Up;
	GameObject* Volume_Down;
	GameObject* Home_Button;
	float Temp_scale;

	Spriterenderer* Volume_Img;
	Spriterenderer* Home_Img;

	Y_BtScript* bts;

public:

	void Start()
	{

		Temp_scale = Time::Get()->GetTimeScale();

		DontDestroyOnLoad(gameobject);
		// 생성 순서에 유의 (마지막에 생성된게 마지막에 랜더링됩니다.)
		{
			Pause_Window = gameobject->CreateChild("Window", ResourceManager::Get()->Find<Sprite>(L"GrayRect"));
			Pause_Window->GetComponent<Spriterenderer>()->SetColor(0, 0, 0, 0.5f, true);
		}
		{
			Pause_Base = gameobject->CreateChild("Base", ResourceManager::Get()->Find<Sprite>(L"PauseBar"));
			Pause_Base->GetComponent<Spriterenderer>()->SetColor(0, 0, 0, 0.8f, true);
		}
		{
			Volume_Bar = gameobject->CreateChild("Volume"
				, resource->Find<Sprite>(L"Volume_5"));
			Volume_Img = Volume_Bar->GetComponent<Spriterenderer>();
		}
		{
			Home_Button = gameobject->CreateChild("Home"
				, resource->Find<Sprite>(L"main_0"));
			bts = Home_Button->AddComponent<Y_BtScript>();
			bts->_upEvent.theme = Event_Theme::Default;
			bts->_upEvent.type = Event_Type::Default;
			bts->_upEvent.event = Event_List::GoMain;
			Transform* tr = Home_Button->GetComponent<Transform>();
			tr->position = { 40,200 };
		}
		{
			X_Button = gameobject->CreateChild("X_Button");
			bts = X_Button->AddComponent<Y_BtScript>();
			bts->bt_trans->position = { 956, 32 };
			bts->bt_trans->scale = { 30, 30 };
			bts->_clickEvent.theme = Event_Theme::Default;
			bts->_clickEvent.type = Event_Type::Default;
			bts->_clickEvent.event = Event_List::InGame;
			//RectCollider* col = X_Button->AddComponent<RectCollider>();
			//col->size = { 30,30 };
		}
		{
			Volume_Down = gameobject->CreateChild("Volume_Down");
			bts = Volume_Down->AddComponent<Y_BtScript>();
			bts->bt_trans->position = { 370, 137 };
			bts->bt_trans->scale = { 30, 30 };
			bts->_clickEvent.event = Event_List::VolumeDown;
			//Transform* tr = Volume_Down->GetComponent<Transform>();
			//tr->position = { 370, 137 };
			//RectCollider* col = X_Button->AddComponent<RectCollider>();
			//col->size = { 30,30 };
		}
		{
			Volume_Up = gameobject->CreateChild("Volume_Up");
			bts = Volume_Up->AddComponent<Y_BtScript>();
			bts->bt_trans->position = { 900, 137 };
			bts->bt_trans->scale = { 30, 30 };
			bts->_clickEvent.event = Event_List::VolumeUp;
			//Transform* tr = Volume_Up->GetComponent<Transform>();
			//tr->position = { 900, 137 };
			//RectCollider* col = X_Button->AddComponent<RectCollider>();
			//col->size = { 30,30 };
		}
		Pause_Window->SetActive(GameManager::Get()->IsStop());
		Pause_Base->SetActive(GameManager::Get()->IsStop());
		Volume_Bar->SetActive(GameManager::Get()->IsStop());
		Home_Button->SetActive(GameManager::Get()->IsStop());
		X_Button->SetActive(GameManager::Get()->IsStop());
	}

	void Update()
	{
		bts = X_Button->GetComponent<Y_BtScript>();

		if (key->IsDown(27))
		{
			if (GameManager::Get()->IsStop())
				GameManager::Get()->SetStop(false);
			else GameManager::Get()->SetStop(true);
		}
		if (GameManager::Get()->IsStop())
		{
			Pause_Window->SetActive(true);
			Pause_Base->SetActive(true);
			Volume_Bar->SetActive(true);
			Home_Button->SetActive(true);
			X_Button->SetActive(true);
			Time::Get()->SetTimeStop(true);
		}
		else
		{
			Pause_Window->SetActive(false);
			Pause_Base->SetActive(false);
			Volume_Bar->SetActive(false);
			Home_Button->SetActive(false);
			X_Button->SetActive(false);
			Time::Get()->SetTimeStop(false);
		}
		int _vol = SoundManager::Get()->GetVolume();
		if (_vol >= 10)
		{
			Volume_Img->SetActive(true);
			Volume_Img->SetSprite(resource->Find<Sprite>(L"Volume_" + std::to_wstring(_vol / 10)));
		}
		else if (_vol <= 0)
		{
			Volume_Img->SetActive(false);
		}
	}
};