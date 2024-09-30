#include "Framework.h"

void EventManager::CallEvent(EventData _data)
{
	if (_data.type == Event_Type::Default)
	{
		if (_data.event == Event_List::GameStart)
		{
			LOAD_SCENE(FIND_SCENE(Y_IntroScene));
			SOUND->SoundcutPlay(SoundList::IntroBGM, SoundChannel::BackGround);
		}

		if (_data.event == Event_List::GoEnding_1)
		{
			GameScene* _tempScene = SceneManager::Get()->GetActiveScene();
			_tempScene->DestroyObject("Monitor1");
			_tempScene->DestroyObject("Monitor2");
			_tempScene->DestroyObject("Monitor3");
			_tempScene->DestroyObject("Monitor4");
			_tempScene->DestroyObject("Monitor5");
			_tempScene->DestroyObject("Monitor6");
			_tempScene->DestroyObject("Main_Monitor_5");
			_tempScene->DestroyObject("ChoiceBt_1");
			_tempScene->DestroyObject("ChoiceBt_2");
			LOAD_SCENE(FIND_SCENE(Y_EndingScene_Choice1));
		}
		if (_data.event == Event_List::GoEnding_2)
		{
			LOAD_SCENE(FIND_SCENE(Y_EndingScene_Choice2));
		}
		
		if (_data.event == Event_List::GameEnd)
		{
			PostMessage(RenderManager::Get()->Get_HWND(), WM_CLOSE, 0, 0);
		}
		else if (_data.event == Event_List::VolumeUp)
		{
			if(SoundManager::Get()->GetVolume() < 100)
				SoundManager::Get()->SetVolume(SoundManager::Get()->GetVolume() + 10);
		}
		else if (_data.event == Event_List::VolumeDown)
		{
			if (SoundManager::Get()->GetVolume() > 0)
				SoundManager::Get()->SetVolume(SoundManager::Get()->GetVolume() - 10);
		}
		else if (_data.event == Event_List::GoMain)
		{
			LOAD_SCENE(FIND_SCENE(Y_TitleScene));
			Y_PlayerScript* playerscr = SceneManager::Get()->FindGlobalObject("Player", Layer::Player)->GetComponent<Y_PlayerScript>();
			playerscr->hp = 10;
			Time::Get()->SetTimeScale(1.f);
			GameManager::Get()->SetStop(false);
			Time::Get()->SetTimeStop(false);

		}
		else if (_data.event == Event_List::InGame)
		{
			GameManager::Get()->SetStop(false);
		}
		else if (_data.event == Event_List::Respawn)
		{
			Y_PlayerScript* _temps = _data.objectParam->GetComponent<Y_PlayerScript>();
			_temps->Respawn();
		}
		else if (_data.event == Event_List::CutSceneNext)
		{
			Y_IntroScript* scr = _data.objectParam->GetComponent<Y_IntroScript>();
			scr->index++;
		}
		else if (_data.event == Event_List::EndingSceneNext1)
		{
			Y_EndingScript_1* scr = _data.objectParam->GetComponent<Y_EndingScript_1>();
			scr->index++;
		}
		else if (_data.event == Event_List::EndingSceneNext2)
		{
			Y_EndingScript_2* scr = _data.objectParam->GetComponent<Y_EndingScript_2>();
			scr->index++;
		}
		else if (_data.event == Event_List::GoStage_1)
		{
			GameScene* _targetScene = FIND_SCENE(Y_UndergroundScene);
			if (_targetScene != nullptr)
			{
				LOAD_SCENE(_targetScene);
				_data.objectParam->GetComponent<Transform>()->position = _targetScene->SpawnPoint_1;
				SOUND->SoundcutPlay(SoundList::BackGround_1, SoundChannel::BackGround);
			}
		}
		else if (_data.event == Event_List::GoStage_2)
		{
			GameScene* _targetScene = FIND_SCENE(Y_ResidentialAreaScene);
			if (_targetScene != nullptr)
			{
				LOAD_SCENE(_targetScene);
				_data.objectParam->GetComponent<Transform>()->position = _targetScene->SpawnPoint_1;
				SOUND->SoundcutPlay(SoundList::BackGround_2, SoundChannel::BackGround);
			} 
		}
		else if (_data.event == Event_List::GoStage_3)
		{
			GameScene* _targetScene = FIND_SCENE(Y_UpperAreaScene);
			if (_targetScene != nullptr)
			{
				LOAD_SCENE(_targetScene);
				_data.objectParam->GetComponent<Transform>()->position = _targetScene->SpawnPoint_1;
				SOUND->SoundcutPlay(SoundList::BackGround_3, SoundChannel::BackGround);
			}
		}
		else if (_data.event == Event_List::GoStage_4)
		{
			GameScene* _targetScene = FIND_SCENE(Y_CutScene_UpperArea);
			if (_targetScene != nullptr)
			{
				LOAD_SCENE(_targetScene);
				_data.objectParam->GetComponent<Transform>()->position = _targetScene->SpawnPoint_1;
				SOUND->SoundcutPlay(SoundList::BackGround_4, SoundChannel::BackGround);
			}
		}
		else if (_data.event == Event_List::GoEnding_2_Before)
		{
			GameScene* _tempScene = SceneManager::Get()->GetActiveScene();
			_tempScene->DestroyObject("Monitor1");
			_tempScene->DestroyObject("Monitor2");
			_tempScene->DestroyObject("Monitor3");
			_tempScene->DestroyObject("Monitor4");
			_tempScene->DestroyObject("Monitor5");
			_tempScene->DestroyObject("Monitor6");
			_tempScene->DestroyObject("Main_Monitor_5");
			_tempScene->DestroyObject("ChoiceBt_1");
			_tempScene->DestroyObject("ChoiceBt_2");

			{
				GameObject* clone = _tempScene->CreateObject(Layer::Object, ObjectTag::MONITOR_BIG, "Blackbox",
					ResourceManager::Get()->Find<Sprite>(L"Blackbox"));
				Transform* temptr = clone->GetComponent<Transform>();
				temptr->position = { 1986.0f, 2200.0f };
				temptr->scale = { 130.0f, 100.0f };

			}
			Y_PlayerScript* asd = _data.objectParam->GetComponent<Y_PlayerScript>();
			asd->isPlayerMovementEnabled = true;
			RectCollider* co = _data.objectParam->GetComponent<RectCollider>();
			co->isActive = false;
		}
	}
	else if (_data.type == Event_Type::SceneChange)
	{
		SceneManager::Get()->LoadScene(_data.sceneParam);
	}
}

void EventManager::FadeEventPush(EventData _data)
{
	_eventlist.push(_data);
}

void EventManager::ProcessEventlist()
{
	while (!_eventlist.empty())
	{
		CallEvent(_eventlist.front());
		_eventlist.pop();
	}
}
