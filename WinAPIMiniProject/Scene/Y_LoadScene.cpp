#include "Framework.h"
#include "Y_LoadScene.h"

void Y_LoadScene::SceneEnter()
{
	GameObject* SampleObject = CreateObject(Layer::Default, ObjectTag::Default, "Sample_Object_1");
	SampleObject->AddComponent<Y_LoadScript>();

	{
		GameObject* Player = CreateObject(Layer::Player, ObjectTag::Object, "Player");
		Player->AddComponent<Y_PlayerScript>();
	}
	{
		GameObject* LifeBar = CreateObject(Layer::UI, ObjectTag::UI, "LifeBar"
			, ResourceManager::Get()->Find<Sprite>(L"LifeBar_10"));
		LifeBar->AddComponent<Y_LifeBarScript>();
	}
	{
		GameObject* DashBar = CreateObject(Layer::UI, ObjectTag::UI, "DashBar"
			, ResourceManager::Get()->Find<Sprite>(L"UI_Dash"));
		DashBar->AddComponent<Y_DashBarScript>();
	}
	{
		GameObject* PauseBar = CreateObject(Layer::UI, ObjectTag::UI, "PauseBar");
		PauseBar->AddComponent<Y_PauseScript>();
	}
	GameObject* GM = CreateObject(Layer::UI, ObjectTag::UI, "GameManager");
	Y_ManagerScript* GMS = GM->AddComponent<Y_ManagerScript>();

}

void Y_LoadScene::SceneExit()
{
}
