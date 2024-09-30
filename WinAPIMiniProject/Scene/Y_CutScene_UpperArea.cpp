#include "Framework.h"
#include "Y_CutScene_UpperArea.h"

void Y_CutScene_UpperArea::SceneEnter()
{
	SpawnPoint_1 = {70, 2070};
	SpawnPoint_2 = {70, 2070};
	BGSound = SoundList::BackGround_4;

	this->MapSize = { 2500,2300 };
	SetBackGround(ResourceManager::Get()->Find<Sprite>(L"BG3"));
	{
		GameObject* Tile;
		Tile = CreateObject(Layer::Tile, ObjectTag::Ground
			, "Tile1"
			, ResourceManager::Get()->Find<Sprite>(L"Tile_1"));
		Spriterenderer* sp = Tile->GetComponent<Spriterenderer>();
		Transform* tr = Tile->GetComponent<Transform>();
		tr->scale = { 2500, 100 };
		tr->position = { 0, 2200, };
		Tile->AddComponent<RectCollider>();
	}
	{
		Y_InteractScript* obj_Info;

		// 모니터 전체 오브젝트
		GameObject* monitor = CreateObject(Layer::Object, ObjectTag::MONITOR_SMALL1, "monitor"
			, ResourceManager::Get()->Find<Sprite>(L"Moni"));
		Transform* objtr = monitor->GetComponent<Transform>();
		objtr->position = { 500,1530 };

		// 모니터에 이미지 띄울때 콜라이더들
		GameObject* mon1 = CreateObject(Layer::Object, ObjectTag::MONITOR_SMALL1, "sample_npc1");
		obj_Info = mon1->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 570,1650 };
		obj_Info->col->size = { 30, 500 };
		GameObject* mon2 = CreateObject(Layer::Object, ObjectTag::MONITOR_SMALL2, "sample_npc1");
		obj_Info = mon2->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 710,1850 };
		obj_Info->col->size = { 30, 500 };
		GameObject* mon3 = CreateObject(Layer::Object, ObjectTag::MONITOR_SMALL3, "sample_npc1");
		obj_Info = mon3->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 950,1750 };
		obj_Info->col->size = { 30, 500 };
		GameObject* mon4 = CreateObject(Layer::Object, ObjectTag::MONITOR_SMALL4, "sample_npc1");
		obj_Info = mon4->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 1120,1750 };
		obj_Info->col->size = { 30, 700 };
		GameObject* mon5 = CreateObject(Layer::Object, ObjectTag::MONITOR_SMALL5, "sample_npc1");
		obj_Info = mon5->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 1270,1600 };
		obj_Info->col->size = { 30, 700 };
		GameObject* mon6 = CreateObject(Layer::Object, ObjectTag::MONITOR_SMALL6, "sample_npc1");
		obj_Info = mon6->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 1400,1950 };
		obj_Info->col->size = { 30, 500 };

		// 뭔버근지 모르겠는데 col size 30보다 크게 하면 시작할때부터 닿는걸로 판정돼서 걍 여러개 만들어놓음 ;
		GameObject* cutScene_col = CreateObject(Layer::Object, ObjectTag::MONITOR_CutScene, "cutScene_col");
		obj_Info = cutScene_col->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 1550,1700 };
		obj_Info->col->size = { 30, 1000 };
		GameObject* cutScene_col2 = CreateObject(Layer::Object, ObjectTag::MONITOR_CutScene, "cutScene_col");
		obj_Info = cutScene_col2->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 1580,1700 };
		obj_Info->col->size = { 30, 1000 };
		GameObject* cutScene_col3 = CreateObject(Layer::Object, ObjectTag::MONITOR_CutScene, "cutScene_col");
		obj_Info = cutScene_col3->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 1610,1700 };
		obj_Info->col->size = { 30, 1000 };
		GameObject* cutScene_col4 = CreateObject(Layer::Object, ObjectTag::MONITOR_CutScene, "cutScene_col");
		obj_Info = cutScene_col4->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 1640,1700 };
		obj_Info->col->size = { 30, 1000 };
		GameObject* cutScene_col5 = CreateObject(Layer::Object, ObjectTag::MONITOR_CutScene, "cutScene_col");
		obj_Info = cutScene_col5->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 1670,1700 };
		obj_Info->col->size = { 30, 1000 };
		GameObject* cutScene_col6 = CreateObject(Layer::Object, ObjectTag::MONITOR_CutScene, "cutScene_col");
		obj_Info = cutScene_col6->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 1700,1700 };
		obj_Info->col->size = { 30, 1000 };
		GameObject* cutScene_col7 = CreateObject(Layer::Object, ObjectTag::MONITOR_CutScene, "cutScene_col");
		obj_Info = cutScene_col7->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 1730,1700 };
		obj_Info->col->size = { 30, 1000 };
		GameObject* cutScene_col8 = CreateObject(Layer::Object, ObjectTag::MONITOR_CutScene, "cutScene_col");
		obj_Info = cutScene_col8->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 1760,1700 };
		obj_Info->col->size = { 30, 1000 };
		GameObject* cutScene_col9 = CreateObject(Layer::Object, ObjectTag::MONITOR_CutScene, "cutScene_col");
		obj_Info = cutScene_col9->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 1790,1700 };
		obj_Info->col->size = { 30, 1000 };
		GameObject* cutScene_col10 = CreateObject(Layer::Object, ObjectTag::MONITOR_CutScene, "cutScene_col");
		obj_Info = cutScene_col10->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 1820,1700 };
		obj_Info->col->size = { 30, 1000 };
		GameObject* cutScene_col11 = CreateObject(Layer::Object, ObjectTag::MONITOR_CutScene, "cutScene_col");
		obj_Info = cutScene_col11->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 1850,1700 };
		obj_Info->col->size = { 30, 1000 };
		GameObject* cutScene_col12 = CreateObject(Layer::Object, ObjectTag::MONITOR_CutScene, "cutScene_col");
		obj_Info = cutScene_col12->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 1880,1700 };
		obj_Info->col->size = { 30, 1000 };
		GameObject* cutScene_col13 = CreateObject(Layer::Object, ObjectTag::MONITOR_CutScene, "cutScene_col");
		obj_Info = cutScene_col13->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 1910,1700 };
		obj_Info->col->size = { 30, 1000 };
		GameObject* cutScene_col14 = CreateObject(Layer::Object, ObjectTag::MONITOR_CutScene, "cutScene_col");
		obj_Info = cutScene_col14->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 1940,1700 };
		obj_Info->col->size = { 30, 1000 };
		GameObject* cutScene_col15 = CreateObject(Layer::Object, ObjectTag::MONITOR_CutScene, "cutScene_col");
		obj_Info = cutScene_col15->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 1970,1700 };
		obj_Info->col->size = { 30, 1000 };
		GameObject* cutScene_col16 = CreateObject(Layer::Object, ObjectTag::MONITOR_CutScene, "cutScene_col");
		obj_Info = cutScene_col16->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 2000,1700 };
		obj_Info->col->size = { 30, 1000 };
		// 큰모니터
		GameObject* cutScene_col18 = CreateObject(Layer::Object, ObjectTag::MONITOR_BIG, "cutScene_col");
		obj_Info = cutScene_col18->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 2080,1700 };
		obj_Info->col->size = { 30, 1000 };

		GameObject* cutScene_col19 = CreateObject(Layer::Object, ObjectTag::GoEnding, "cutScene_col");
		obj_Info = cutScene_col19->AddComponent<Y_InteractScript>();
		obj_Info->tr->position = { 2080,3000 };
		obj_Info->col->size = { 30, 100 };

	}

}

void Y_CutScene_UpperArea::SceneExit()
{
}
