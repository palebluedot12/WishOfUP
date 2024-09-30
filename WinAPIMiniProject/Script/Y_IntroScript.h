#pragma once

class Y_IntroScript : public Script
{
private:

	Spriterenderer* sp;
	Transform* tr;

public:

	int index = 1;

	void Start()
	{
		sp = gameobject->GetComponent<Spriterenderer>();

	}

	void Update()
	{
		if (key->IsDown(32) && index <= 2)
		{
			EventData _eData;
			_eData.type = Event_Type::Default;
			_eData.event = Event_List::CutSceneNext;
			_eData.objectParam = gameobject;
			if (RenderManager::Get()->FadeInOutStart())
			{
				EventManager::Get()->FadeEventPush(_eData);
			}  
		}
		if (index == 3)
		{
			// intro scene 끝나면 하층구역 출력하기
			EventData _eData;
			_eData.type = Event_Type::Default;
			_eData.event = Event_List::GoStage_1;
			_eData.objectParam = SceneManager::Get()->FindGlobalObject("Player", Layer::Player);
			_eData.objectParam->GetComponent<Y_PlayerScript>()->SpawnReset();
			_eData.sceneParam = SceneManager::Get()->GetActiveScene();
			if (RenderManager::Get()->FadeInOutStart())
			{
				EventManager::Get()->FadeEventPush(_eData);
			}
		}
	}

	void FixedUpdate()
	{
		if (index <= 3)
		{
			sp->SetSprite(resource->Find<Sprite>(L"Intro" + std::to_wstring(index)));
		}
	}
};