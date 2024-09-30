#include "Framework.h"
#include "Y_IntroScene.h"

void Y_IntroScene::SceneEnter()
{
	{
		//intro cuts
		GameObject* Introimg = CreateObject(Layer::BackGround, ObjectTag::Default
			, "Intro", ResourceManager::Get()->Find<Sprite>(L"Intro1"));
		Introimg->AddComponent<Y_IntroScript>();
		Introimg->GetComponent<Transform>()->position = { -5, -25 };

		//skip button
		GameObject* skbt = CreateObject(Layer::Object, ObjectTag::Object, "Skip"
			, ResourceManager::Get()->Find<Sprite>(L"UI_Skip"));

		Y_BtScript* bt = skbt->AddComponent<Y_BtScript>();
		bt->bt_trans->position = { 800,-20 };
		bt->_clickEvent.theme = Event_Theme::Fade;
		bt->_clickEvent.type = Event_Type::Default;
		bt->_clickEvent.event = Event_List::GoStage_1; // 하층구역으로 바로 넘어가게 하는 거 필요
		bt->_clickEvent.objectParam = SceneManager::Get()->FindGlobalObject("Player", Layer::Player);
		bt->_clickEvent.objectParam->GetComponent<Y_PlayerScript>()->SpawnReset();
	}
}

void Y_IntroScene::SceneExit()
{
}