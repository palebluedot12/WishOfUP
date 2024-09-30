#pragma once

class Y_RainSpawner : public Script
{
private:

	GameObject* dropPoint[3];

	float DropTimer = 0.f;
	float DropTick = 0.3f;

	std::queue<GameObject*> rainlist;

	Transform* dropTr[3];
	int Max = 0;

public:


	void Start()
	{
		dropPoint[0] = gameobject->CreateChild("SpawnPoint1");
		dropPoint[1] = gameobject->CreateChild("SpawnPoint2");
		dropPoint[2] = gameobject->CreateChild("SpawnPoint3");

		dropTr[0] = dropPoint[0]->GetComponent<Transform>();
		dropTr[1] = dropPoint[1]->GetComponent<Transform>();
		dropTr[2] = dropPoint[2]->GetComponent<Transform>();

		dropTr[0]->position = { -20, 0 };
		dropTr[1]->position = { -0, 0 };
		dropTr[2]->position = { 20, 0 };
	}

	void Update()
	{

		DropTimer += DELTA;

		if (DropTimer >= DropTick)
		{
			DropTimer = 0;

			if (Max > 0)
			{
				int rainType = rand() % 3 + 1;
				std::wstring spriteName = L"Rain" + std::to_wstring(rainType);
				GameObject* rain = SceneManager::Get()->GetActiveScene()->CreateObject(
					Layer::Object, ObjectTag::Rain, "",
					ResourceManager::Get()->Find<Sprite>(spriteName));

				if (rain == nullptr) {
					assert(false && "Failed to create rain object.");
					return;
				}

				Transform* _tr = rain->GetComponent<Transform>();
				if (_tr == nullptr) {
					assert(false && "Failed to get Transform component from rain object.");
					return;
				}

				_tr->position = dropTr[rand() % 3]->worldPosition;
				rain->AddComponent<Y_RainScript>();
				rainlist.push(rain);
				Max--;
			}
			else
			{
				if (!rainlist.empty())
				{
					Transform* tr = rainlist.front()->GetComponent<Transform>();
					if (tr != nullptr) {
						tr->position.y = dropTr[0]->worldPosition.y;
					}
					GameObject* _temp = rainlist.front();
					rainlist.pop();
					rainlist.push(_temp);
				}
			}
		}
	}

	void SetMax(int sec) { Max = sec; }
};