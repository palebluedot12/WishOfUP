#include "Framework.h"
#include "Y_EndingScene_Choice2.h"

void Y_EndingScene_Choice2::SceneEnter()
{
	{
		GameObject* Ending2img = CreateObject(Layer::BackGround, ObjectTag::Default
			, "Ending2", ResourceManager::Get()->Find<Sprite>(L"E2_1"));
		Ending2img->AddComponent<Y_EndingScript_2>();
		Ending2img->GetComponent<Transform>()->position = { -5, -25 };
	}

}

void Y_EndingScene_Choice2::SceneExit()
{
}
