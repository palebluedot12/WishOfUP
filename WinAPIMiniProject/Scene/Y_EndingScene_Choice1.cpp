#include "Framework.h"
#include "Y_EndingScene_Choice1.h"

void Y_EndingScene_Choice1::SceneEnter()
{
	{
		GameObject* Ending1img = CreateObject(Layer::BackGround, ObjectTag::Default
			, "Ending1", ResourceManager::Get()->Find<Sprite>(L"E1_1"));
		Ending1img->AddComponent<Y_EndingScript_1>();
		Ending1img->GetComponent<Transform>()->position = { -5, -25 };
	}

}

void Y_EndingScene_Choice1::SceneExit()
{
}
