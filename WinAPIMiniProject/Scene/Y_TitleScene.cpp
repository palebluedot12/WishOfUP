#include "Framework.h"
#include "Y_TitleScene.h"

void Y_TitleScene::SceneEnter()
{
	SOUND->SoundcutPlay(SoundList::MainBGM, SoundChannel::BackGround);
	GameObject* Titleimg = CreateObject(Layer::BackGround, ObjectTag::Default, "TitleBackground"
		, ResourceManager::Get()->Find<Sprite>(L"TitleBackground"));
	{
		//���� ����
		{
			GameObject* Startbt = CreateObject(Layer::Object, ObjectTag::Object, "GameStart"
				, ResourceManager::Get()->Find<Sprite>(L"GameStart_" + std::to_wstring(0)));

			Y_BtScript* bts = Startbt->AddComponent<Y_BtScript>();
			bts->bt_trans->position = { 40, 430 };
			bts->_clickEvent.theme = Event_Theme::Fade; // ���̵���-�ƿ��� ȣ���ϰ� ���̵� ���� ���� �� �̺�Ʈ�� �����Ѵ�. Default�� �׳� �ٷ� �����Ѵ�.
			bts->_clickEvent.type = Event_Type::Default; // ��ü������ �Ұž�.. �ٵ� ������ �ٸ� �̺�Ʈ�� �����ϰ� ������ Default�� ����!
			bts->_clickEvent.event = Event_List::GameStart; // �̰� type�� Default�϶��� ȣ�� �� �� �ִµ�, Default�� ������� �ش� �̺�Ʈ�� ȣ���Ѵ�!
		}
		//���� ����
		{
			GameObject* Endbt = CreateObject(Layer::Object, ObjectTag::Object, "GameEnd"
				, ResourceManager::Get()->Find<Sprite>(L"GameEnd_" + std::to_wstring(0)));

			Y_BtScript* bts = Endbt->AddComponent<Y_BtScript>();
			bts->bt_trans->position = { 40, 550 };
			bts->_clickEvent.theme = Event_Theme::Fade;
			bts->_clickEvent.type = Event_Type::Default;
			bts->_clickEvent.event = Event_List::GameEnd;

		}
		//�ΰ�
		{
			GameObject* logo = CreateObject(Layer::Object, ObjectTag::Object, "Logo_1"
				, ResourceManager::Get()->Find<Sprite>(L"Logo_1"));
			Transform* tr = logo->GetComponent<Transform>();
			tr->position = { 40,200 };
		}
		//���� �Ϸ���Ʈ
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