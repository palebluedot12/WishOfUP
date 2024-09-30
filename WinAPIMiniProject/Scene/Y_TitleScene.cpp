#include "Framework.h"
#include "Y_TitleScene.h"

void Y_TitleScene::SceneEnter()
{
	SOUND->SoundcutPlay(SoundList::MainBGM, SoundChannel::BackGround);
	GameObject* Titleimg = CreateObject(Layer::BackGround, ObjectTag::Default, "TitleBackground"
		, ResourceManager::Get()->Find<Sprite>(L"TitleBackground"));
	{
		//게임 시작
		{
			GameObject* Startbt = CreateObject(Layer::Object, ObjectTag::Object, "GameStart"
				, ResourceManager::Get()->Find<Sprite>(L"GameStart_" + std::to_wstring(0)));

			Y_BtScript* bts = Startbt->AddComponent<Y_BtScript>();
			bts->bt_trans->position = { 40, 430 };
			bts->_clickEvent.theme = Event_Theme::Fade; // 페이드인-아웃을 호출하고 페이드 인이 끝날 때 이벤트를 수행한다. Default는 그냥 바로 수행한다.
			bts->_clickEvent.type = Event_Type::Default; // 씬체인지를 할거야.. 근데 씬말고 다른 이벤트를 수행하고 싶으면 Default를 고른다!
			bts->_clickEvent.event = Event_List::GameStart; // 이건 type이 Default일때만 호출 할 수 있는데, Default를 골랐으면 해당 이벤트를 호출한다!
		}
		//게임 종료
		{
			GameObject* Endbt = CreateObject(Layer::Object, ObjectTag::Object, "GameEnd"
				, ResourceManager::Get()->Find<Sprite>(L"GameEnd_" + std::to_wstring(0)));

			Y_BtScript* bts = Endbt->AddComponent<Y_BtScript>();
			bts->bt_trans->position = { 40, 550 };
			bts->_clickEvent.theme = Event_Theme::Fade;
			bts->_clickEvent.type = Event_Type::Default;
			bts->_clickEvent.event = Event_List::GameEnd;

		}
		//로고
		{
			GameObject* logo = CreateObject(Layer::Object, ObjectTag::Object, "Logo_1"
				, ResourceManager::Get()->Find<Sprite>(L"Logo_1"));
			Transform* tr = logo->GetComponent<Transform>();
			tr->position = { 40,200 };
		}
		//유피 일러스트
		{
			GameObject* ill = CreateObject(Layer::Object, ObjectTag::Object, "TitleIllustrator"
				, ResourceManager::Get()->Find<Sprite>(L"TitleIllustrator"));
			Transform* tr = ill->GetComponent<Transform>();
			tr->position = { 410,50 };
			tr->scale = { 680,1000 };
		}
	}
}

void Y_TitleScene::SceneExit()
{
}