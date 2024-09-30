#include "Framework.h"

void Y_UndergroundScene::SceneEnter()
{
	SpawnPoint_1 = { 100, 2150 };
	SpawnPoint_2 = { 100, 2150 };
	BGSound = SoundList::BackGround_1;

	// 백그라운드 설정
	SetBackGround(ResourceManager::Get()->Find<Sprite>(L"BG2"));

	TileManager::Get()->LoadMapData(this, "Asset/TileText/DownAreaRealRealEzrealTest.csv");
	TileManager::Get()->LoadColliderData(this, "Asset/ColliderText/DownAreaRealRealEzrealTestCollider.csv");

	{
		GameObject* CutObj = CreateObject(Layer::Object, ObjectTag::Default, "zoozack"
			, ResourceManager::Get()->Find<Sprite>(L"zoozack"));
		Y_InteractScript* _info = CutObj->AddComponent<Y_InteractScript>();
		_info->tr->position = { 300, 1800 };
	}
	
	{
		Y_InteractScript* obj_Info;
		GameObject* nextScene = CreateObject(Layer::Object, ObjectTag::ToScene2, "nextScene");
		obj_Info = nextScene->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 2000, 240 };
		obj_Info->col->size = { 30, 500 };
	}
	// 세이브 포인트
	{
		Y_InteractScript* obj_Info;
		GameObject* savepoint_1 = CreateObject(Layer::Object, ObjectTag::SavePoint, "Save_0");
		obj_Info = savepoint_1->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 100, 2000 };
		obj_Info->col->size = { 200, 300 };
	}

	//상호작용npc
	{
		Y_InteractScript* obj_Info;
		GameObject* savepoint_1 = CreateObject(Layer::Object, ObjectTag::SavePoint, "Save_0");
		obj_Info = savepoint_1->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 100, 2000 };
		obj_Info->col->size = { 200, 300 };
	}

	{
		GameObject* DialogWindow = CreateObject(Layer::Object, ObjectTag::UnderDialog1, "underDialog");
		Y_InteractScript* dia_info;
		dia_info = DialogWindow->AddComponent<Y_InteractScript>();

		dia_info->tr->position = { 500, 641 };
		dia_info->col->size = { 400, 170 };
	}
	{
		GameObject* DialogWindow = CreateObject(Layer::Object, ObjectTag::UnderDialog2, "underDialog");
		Y_InteractScript* dia_info;
		dia_info = DialogWindow->AddComponent<Y_InteractScript>();

		dia_info->tr->position = { 1000, 641 };
		dia_info->col->size = { 400, 170 };
	}
	{
		GameObject* DialogWindow = CreateObject(Layer::Object, ObjectTag::UnderDialog3, "underDialog");
		Y_InteractScript* dia_info;
		dia_info = DialogWindow->AddComponent<Y_InteractScript>();

		dia_info->tr->position = { 1500, 641 };
		dia_info->col->size = { 400, 170 };
	}

	//맨 아래 
	{
		GameObject* DialogWindow = CreateObject(Layer::Object, ObjectTag::Jump_Tutorial, "Jump_Tutorial");
		Y_InteractScript* dia_info;
		dia_info = DialogWindow->AddComponent<Y_InteractScript>();

		dia_info->tr->position = { 930, 2000 };
		dia_info->col->size = { 220, 170 };
	}
	
	
	{
		GameObject* DialogWindow = CreateObject(Layer::Object, ObjectTag::Jump_Tutorial, "Jump_Tutorial");
		Y_InteractScript* dia_info;
		dia_info = DialogWindow->AddComponent<Y_InteractScript>();

		dia_info->tr->position = { 512, 1520 };
		dia_info->col->size = { 130, 50 };
	}

	//벽점구간
	{
		GameObject* DialogWindow = CreateObject(Layer::Object, ObjectTag::WallJump_Tutorial_Right, "Jump_Tutorial");
		Y_InteractScript* dia_info;
		dia_info = DialogWindow->AddComponent<Y_InteractScript>();

		dia_info->tr->position = { 455, 1030 };
		dia_info->col->size = { 66, 370 };
	}

	
	{
		GameObject* DialogWindow = CreateObject(Layer::Object, ObjectTag::WallJump_Tutorial_Left, "Jump_Tutorial");
		Y_InteractScript* dia_info;
		dia_info = DialogWindow->AddComponent<Y_InteractScript>();

		dia_info->tr->position = { 630, 820 };
		dia_info->col->size = { 66, 580 };
	}

	{
		GameObject* DialogWindow = CreateObject(Layer::Object, ObjectTag::Umbrella_Tutorial, "Umbrella_Tutorial");
		Y_InteractScript* dia_info;
		dia_info = DialogWindow->AddComponent<Y_InteractScript>();

		dia_info->tr->position = { 230, 940 };
		dia_info->col->size = { 200, 480 };
	}

	//대쉬구간
	{
		GameObject* tile = CreateObject(Layer::Object, ObjectTag::Dash_Tutorial, "Dash_Tutorial", ResourceManager::Get()->Find<Sprite>(L"UI_Shift"));

		Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

		Transform* tr = tile->GetComponent<Transform>();
		tr->scale = { (float)sp->GetSprite()->GetWidth()-30, (float)sp->GetSprite()->GetHeight()-30 };
		tr->position = { 990,1300 };

	}
}

void Y_UndergroundScene::SceneExit()
{
}
