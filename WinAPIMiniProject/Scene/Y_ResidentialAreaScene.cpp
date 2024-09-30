#include "Framework.h"

void Y_ResidentialAreaScene::SceneEnter()
{
	SpawnPoint_1 = { 40, 2850 };
	SpawnPoint_2 = { 1000, 1020 };
	BGSound = SoundList::BackGround_3;

	// 백그라운드 설정
	SetBackGround(ResourceManager::Get()->Find<Sprite>(L"BG1"));
	TileManager::Get()->LoadMapData(this, "Asset/TileText/2nd.csv");
	TileManager::Get()->LoadColliderData(this, "Asset/ColliderText/2ndAreaCollider.csv");

	// 세이브 포인트
	{
		Y_InteractScript* obj_Info;
		GameObject* savepoint_1 = CreateObject(Layer::Object, ObjectTag::SavePoint, "Save_1");
		obj_Info = savepoint_1->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 40, 2800 };
		obj_Info->col->size = { 200, 300 };
	}
	{
		Y_InteractScript* obj_Info;
		GameObject* savepoint_1 = CreateObject(Layer::Object, ObjectTag::SavePoint, "Save_2");
		obj_Info = savepoint_1->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 1000, 900 };
		obj_Info->col->size = { 200, 300 };
	}


	Y_InteractScript* _info;
	//Rain
	{
		GameObject* RainSpawner1 = CreateObject(Layer::Object, ObjectTag::Default, "RainSpawner");
		RainSpawner1->AddComponent<Y_RainSpawner>();
		RainSpawner1->GetComponent<Y_RainSpawner>()->SetMax(3);
		_info = RainSpawner1->AddComponent<Y_InteractScript>();
		_info->tr->position = { 384, 1320 };
		_info->tr->scale = { 100, 100 };
		_info->col->size = { 64, 64 };

		GameObject* RainSpawner2 = CreateObject(Layer::Object, ObjectTag::Default, "RainSpawner");
		RainSpawner2->AddComponent<Y_RainSpawner>();
		RainSpawner2->GetComponent<Y_RainSpawner>()->SetMax(3);
		_info = RainSpawner2->AddComponent<Y_InteractScript>();
		_info->tr->position = { 384, 1320 };
		_info->tr->scale = { 100, 100 };
		_info->col->size = { 64, 64 };
	}
	
	//맨 아래 비
	{
		for (int i = 0; i < 2; i++)
		{
			GameObject* RainSpawner = CreateObject(Layer::Object, ObjectTag::Default, "RainSpawner");
			RainSpawner->AddComponent<Y_RainSpawner>();
			RainSpawner->GetComponent<Y_RainSpawner>()->SetMax(3);
			_info = RainSpawner->AddComponent<Y_InteractScript>();
			_info->tr->position = { 512+(float)64*i, 2750 };
			_info->tr->scale = { 100, 100 };
			_info->col->size = { 64, 64 };
		}
	}

	//맨 오른쪽 맨 위 비
	{
		GameObject* RainSpawner = CreateObject(Layer::Object, ObjectTag::Default, "RainSpawner");
		RainSpawner->AddComponent<Y_RainSpawner>();
		RainSpawner->GetComponent<Y_RainSpawner>()->SetMax(3);
		_info = RainSpawner->AddComponent<Y_InteractScript>();
		_info->tr->position = { 1344, 620 };
		_info->tr->scale = { 100, 100 };
		_info->col->size = { 64, 64 };
	}
	{
		Y_InteractScript* obj_Info;
		GameObject* nextScene = CreateObject(Layer::Object, ObjectTag::ToScene3, "nextScene");
		obj_Info = nextScene->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 80, 50 };
		obj_Info->col->size = { 100, 50 };
	}
}

void Y_ResidentialAreaScene::SceneExit()
{

}
