#pragma once

class Y_EndingScript_2 : public Script
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
		if (key->IsDown(32) && index <= 4)
		{
			EventData _eData;
			_eData.type = Event_Type::Default;
			_eData.event = Event_List::EndingSceneNext2;
			_eData.objectParam = gameobject;
			if (RenderManager::Get()->FadeInOutStart())
			{
				EventManager::Get()->FadeEventPush(_eData);
			}
		}
		if (key->IsDown(32) && index == 5)
		{
			// intro scene ������ �������� ����ϱ�
			EventData _eData;
			_eData.type = Event_Type::Default;
			_eData.event = Event_List::GoStage_1;
			_eData.objectParam = SceneManager::Get()->FindGlobalObject("Player", Layer::Player);
			_eData.objectParam->GetComponent<Y_PlayerScript>()->Reset();
			_eData.sceneParam = SceneManager::Get()->GetActiveScene();
			if (RenderManager::Get()->FadeInOutStart())
			{
				EventManager::Get()->FadeEventPush(_eData);
			}
		}
	}

	void FixedUpdate()
	{
		if (index <= 5)
		{
			sp->SetSprite(resource->Find<Sprite>(L"E2_" + std::to_wstring(index)));
		}
	}
};