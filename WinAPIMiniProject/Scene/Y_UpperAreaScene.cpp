#include "Framework.h"

void Y_UpperAreaScene::SceneEnter()
{
	SpawnPoint_1 = { 200, 4380 };
	SpawnPoint_2 = { 290, 1640 };
	BGSound = SoundList::BackGround_2;

	// 백그라운드 설정
	SetBackGround(ResourceManager::Get()->Find<Sprite>(L"BG4"));
	TileManager::Get()->LoadMapData(this, "Asset/TileText/UpperAreaFixed.csv");
	TileManager::Get()->LoadColliderData(this, "Asset/ColliderText/UpperAreaCollider.csv");

	{
		Y_InteractScript* obj_Info;
		GameObject* savepoint_1 = CreateObject(Layer::Object, ObjectTag::SavePoint, "Save_3");
		obj_Info = savepoint_1->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 200, 4250 };
		obj_Info->col->size = { 200, 300 };
	}
	{
		Y_InteractScript* obj_Info;
		GameObject* savepoint_1 = CreateObject(Layer::Object, ObjectTag::SavePoint, "Save_4");
		obj_Info = savepoint_1->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 200, 1300 };
		obj_Info->col->size = { 200, 500 };
	}

	{
		Y_InteractScript* obj_Info;
		GameObject* nextScene = CreateObject(Layer::Object, ObjectTag::ToScene4, "nextScene");
		obj_Info = nextScene->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 930, 0 };
		obj_Info->col->size = { 100, 100 };
	}
	{
		Y_InteractScript* obj_Info;
		GameObject* nextScene = CreateObject(Layer::Object, ObjectTag::ToScene2_Reverse, "nextScene");
		obj_Info = nextScene->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 50, 4550 };
		obj_Info->col->size = { 150, 50 };
	}
}

void Y_UpperAreaScene::SceneExit()
{
}
