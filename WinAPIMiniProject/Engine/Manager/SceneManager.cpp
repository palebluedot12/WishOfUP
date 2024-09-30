#include "Framework.h"

// 초기 씬 세팅은 여기서
void SceneManager::Initialize()
{
	CreateScene<Y_LoadScene>(SceneTag::Load, L"Load");

	CreateScene<Y_UndergroundScene>(SceneTag::Play, L"Underground_Area");
	CreateScene<Y_ResidentialAreaScene>(SceneTag::Play, L"Residential_Area");
	CreateScene<Y_UpperAreaScene>(SceneTag::Play, L"Upper_Area");
	CreateScene<Y_CutScene_UpperArea>(SceneTag::Play, L"CS_Upper_Area");
	//IntroScene
	CreateScene<Y_IntroScene>(SceneTag::CutScene, L"Intro");
	//EndingScene
	CreateScene<Y_EndingScene_Choice1>(SceneTag::CutScene, L"Ending1");
	CreateScene<Y_EndingScene_Choice2>(SceneTag::CutScene, L"Ending2");

	CreateScene<Y_TitleScene>(SceneTag::Title, L"Title");
	LoadScene(FindScene<Y_TitleScene>());

}

GameScene* SceneManager::GetActiveScene()
{
	if (Active_Scene != nullptr)
		return Active_Scene;
	else return nullptr;
}

bool SceneManager::LoadScene(const SceneTag _type, std::wstring _key)
{
	for (int i = 0; i < Scene_list[(int)_type].size(); i++)
	{
		if (Scene_list[(int)_type][i]->Get_Name() == _key)
		{
			if (Active_Scene != nullptr)
				Active_Scene->SceneExit();
			Active_Scene = Scene_list[(int)_type][i];
		}
	}
	return false;
}

bool SceneManager::LoadScene(GameScene* _scene)
{
	if (_scene == nullptr) return false;
	else
	{
		if (Active_Scene != nullptr)
			Active_Scene->SceneExit();
		Active_Scene = _scene;
		// 브금 자동 변경
		if (Active_Scene->BGSound != SoundList::None)
		{
			SOUND->SoundcutPlay(Active_Scene->BGSound, SoundChannel::BackGround);
		}
		return true;
	}
}

GameObject* SceneManager::FindGlobalObject(std::string _key, Layer _layer)
{
	for (int i = (int)_layer; i < (int)Layer::Size; i++)
	{
		for (auto it = globalObjectList[i].begin(); it != globalObjectList[i].end(); ++it)
		{
			if ((*it)->GetName() == _key)
			{
				return *it;
			}
		}
	}
	return nullptr;
}

void SceneManager::Update()
{
	std::vector<GameScene*>* arr = Scene_list;

	if (Active_Scene != nullptr)
	{
		for (int i = 0; i < (int)Layer::Size; i++)
		{
			for (GameObject* obj : Active_Scene->GetObjectList()[i])
			{
				if (obj->GetActive())
				{
					obj->Update();
					for (GameObject* c_obj : obj->GetChild())
					{
						if (c_obj->GetActive())
							c_obj->Update();
					}
				}

			}
			for (GameObject* obj : globalObjectList[i])
			{
				if (obj->GetActive())
				{
					obj->Update();
					for (GameObject* c_obj : obj->GetChild())
					{
						if (c_obj->GetActive())
							c_obj->Update();
					}
				}
			}
		}
	}
}

void SceneManager::FixedUpdate()
{
	if (Active_Scene != nullptr)
	{
		for (int i = 0; i < (int)Layer::Size; i++)
		{
			for (GameObject* obj : Active_Scene->GetObjectList()[i])
			{
				if (obj->GetActive())
				{
					obj->FixedUpdate();
					for (GameObject* c_obj : obj->GetChild())
					{
						if (c_obj->GetActive())
							c_obj->FixedUpdate();
					}
				}
			}
			for (GameObject* obj : globalObjectList[i])
			{
				if (obj->GetActive())
				{
					obj->FixedUpdate();
					for (GameObject* c_obj : obj->GetChild())
					{
						if (c_obj->GetActive())
							c_obj->FixedUpdate();
					}
				}
			}
		}
	}
}

void SceneManager::LateUpdate()
{
	if (Active_Scene != nullptr)
	{
		for (int i = 0; i < (int)Layer::Size; i++)
		{
			for (GameObject* obj : Active_Scene->GetObjectList()[i])
			{
				if (obj->GetActive())
				{
					obj->LateUpdate();
					for (GameObject* c_obj : obj->GetChild())
					{
						if (c_obj->GetActive())
							c_obj->LateUpdate();
					}
				}
			}
			for (GameObject* obj : globalObjectList[i])
			{
				if (obj->GetActive())
				{
					obj->LateUpdate();
					for (GameObject* c_obj : obj->GetChild())
					{
						if (c_obj->GetActive())
							c_obj->LateUpdate();
					}
				}
			}
		}
	}
}

void SceneManager::Render()
{
	if (Active_Scene != nullptr)
	{
		for (int i = 0; i < (int)Layer::UI; i++)
		{
			for (GameObject* obj : Active_Scene->GetObjectList()[i])
			{
				if (obj->GetActive())
				{
					obj->Render();
					for (GameObject* c_obj : obj->GetChild())
					{
						if (c_obj->GetActive())
							c_obj->Render();
					}
				}
			}
			for (GameObject* obj : globalObjectList[i])
			{
				if (obj->GetActive())
				{
					obj->Render();
					for (GameObject* c_obj : obj->GetChild())
					{
						if (c_obj->GetActive())
							c_obj->Render();
					}
				}
			}
		}
	}
}

void SceneManager::UIRender()
{
	if (Active_Scene != nullptr)
	{

		for (GameObject* obj : Active_Scene->GetObjectList()[(int)Layer::UI])
		{
			if (obj->GetActive())
			{
				obj->Render();
				for (GameObject* c_obj : obj->GetChild())
				{
					if (c_obj->GetActive())
						c_obj->Render();
				}
			}
		}
		for (GameObject* obj : globalObjectList[(int)Layer::UI])
		{
			if (obj->GetActive())
			{
				obj->Render();
				for (GameObject* c_obj : obj->GetChild())
				{
					if (c_obj->GetActive())
						c_obj->Render();
				}
			}
		}
	}
}
