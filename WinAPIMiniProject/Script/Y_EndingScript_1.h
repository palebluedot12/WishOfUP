#pragma once

class Y_EndingScript_1 : public Script
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
		if (key->IsDown(32) && index <= 10)
		{
			EventData _eData;
			_eData.type = Event_Type::Default;
			_eData.event = Event_List::EndingSceneNext1;
			_eData.objectParam = gameobject;
			if (RenderManager::Get()->FadeInOutStart())
			{
				EventManager::Get()->FadeEventPush(_eData);
			}
		}
		if (index >= 11) // 크레딧따라 추가
		{
			// Ending 1, 크레딧까지 끝나면 타이틀 출력하기
			SceneManager::Get()->FindGlobalObject("Player", Layer::Player)->GetComponent<Y_PlayerScript>()->Reset();
			LOAD_SCENE(FIND_SCENE(Y_TitleScene));
			
		}
	}

	void FixedUpdate()
	{
		if (index <= 10)
		{
			sp->SetSprite(resource->Find<Sprite>(L"E1_" + std::to_wstring(index)));
		}
	}
};