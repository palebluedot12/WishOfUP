#include "Framework.h"

void TileManager::Initialize()
{
}

void TileManager::LoadMapData(GameScene* curscene, std::string file)
{
	std::ifstream loadFile(file);
	std::string temp;

	_tileData.clear();
	_height = 0;
	_width = 0;

	while (std::getline(loadFile, temp))
	{
		if (!temp.empty())
		{
			std::vector<int> datas = Utility::SplitStringtoInt(temp, ",");
			if (_width == 0) {
				_width = datas.size();
			}
			// x축이 다른 줄이 있으면 에러
			else if (datas.size() != _width) {
				assert(false);
			}
			_tileData.push_back(datas);
			_height++;
		}
	}

	// 맵 데이터가 비어있는 경우
	if (_height == 0 || _width == 0) {
		assert(false);
	}

	_mapSize = { (float)_width * 64, (float)_height * 64};

	curscene->MapSize = _mapSize;

	CreateTile(curscene);
}

void TileManager::LoadColliderData(GameScene* curscene , std::string file)
{
	std::ifstream loadFile(file);
	std::string temp;
	_colliderData.clear();

	_height = 0;
	_width = 0;

	while (std::getline(loadFile, temp))
	{
		if (!temp.empty())
		{
			std::vector<std::string> datas = Utility::SplitStringtoString(temp, ",");
			if (_width == 0) {
				_width = datas.size();
			}
			// x축이 다른 줄이 있으면 에러
			else if (datas.size() != _width) {
				assert(false);
			}
			_colliderData.push_back(datas);
			_height++;
		}
	}

	// 맵 데이터가 비어있는 경우
	if (_height == 0 || _width == 0) {
		assert(false);
	}

	CreateCollider(curscene);
}

void TileManager::CreateCollider(GameScene* curscene)
{
	float _size = 64;

	for (int y = 0; y < _height; y++)
	{
		for (int x = 0; x < _width; x++)
		{
			// ^없으면 패스
			if (_colliderData[y][x].find("^") != string::npos)
			{
				std::pair<int, int> WidHei = Utility::SplitStringtoPairInt(_colliderData[y][x], "^");
				// 0이 존재하면 예외처리
				if (WidHei.first <= 0 || WidHei.second <= 0)
					assert(false);

				GameObject* tile = curscene->CreateObject(Layer::Tile, ObjectTag::Ground, "Collider");
				Transform* tr = tile->GetComponent<Transform>();
				tr->position = { x * _size,  y * _size };
				RectCollider* col = tile->AddComponent<RectCollider>();
				
				col->size = { (float)WidHei.first * _size,(float)WidHei.second * _size };
			}
		}
	}
}


void TileManager::CreateTile(GameScene* curscene)
{
	for (int y = _height - 1; y >= 0; y--)
	{
		for (int x = 0; x < _width; x++)
		{
			TileType type = (TileType)_tileData[y][x];
			switch (type)
			{
			case TileType::Underfloor:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Ground, "Tile_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Tile_0"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };
			}
			break;

			case TileType::Tile1:
			{
				GameObject* tile = curscene->CreateObject(Layer::Tile, ObjectTag::Ground, "Tile_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Tile_1"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };

				RectCollider* tile_rc = tile->AddComponent<RectCollider>();
				tile_rc->size = { tr->scale.x,tr->scale.y - 20 };
				tile_rc->offset = { 0,10 };

			}
			break;

			case TileType::Tile2:
			{
				GameObject* tile = curscene->CreateObject(Layer::Tile, ObjectTag::Ground, "Tile_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Tile_2"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };

				RectCollider* tile_rc = tile->AddComponent<RectCollider>();
				tile_rc->size = { tr->scale.x,tr->scale.y - 20 };
				tile_rc->offset = { 0,10 };
			}
			break;

			case TileType::Tile3:
			{
				GameObject* tile = curscene->CreateObject(Layer::Tile, ObjectTag::Ground, "Tile_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Tile_3"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };

				RectCollider* tile_rc = tile->AddComponent<RectCollider>();
				tile_rc->size = { tr->scale.x,tr->scale.y - 20 };
				tile_rc->offset = { 0,10 };
			}
			break;

			case TileType::Tile4:
			{
				GameObject* tile = curscene->CreateObject(Layer::Tile, ObjectTag::Ground, "Tile_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Tile_4"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };

				RectCollider* tile_rc = tile->AddComponent<RectCollider>();
				tile_rc->size = { tr->scale.x,tr->scale.y - 20 };
				tile_rc->offset = { 0,10 };
			}
			break;

			case TileType::Tile5:
			{
				GameObject* tile = curscene->CreateObject(Layer::Tile, ObjectTag::Ground, "Tile_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Tile_5"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };

				RectCollider* tile_rc = tile->AddComponent<RectCollider>();
				tile_rc->size = { tr->scale.x,tr->scale.y - 20 };
				tile_rc->offset = { 0,10 };
			}
			break;

			case TileType::Tile6:
			{
				GameObject* tile = curscene->CreateObject(Layer::Tile, ObjectTag::Ground, "Tile_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Tile_6"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };

				RectCollider* tile_rc = tile->AddComponent<RectCollider>();
				tile_rc->size = { tr->scale.x,tr->scale.y - 20 };
				tile_rc->offset = { 0,10 };
			}
			break;

			case TileType::Tile7:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Ground, "Tile_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Tile_7"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };
			}
			break;

			case TileType::Tile8:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Ground, "Tile_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Tile_8"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };
			}
			break;

			case TileType::Tile9:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Ground, "Tile_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Tile_9"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };
			}
			break;

			case TileType::Tile10:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Ground, "Tile_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Tile_10"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };
			}
			break;

			case TileType::Tile11:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Ground, "Tile_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Tile_11"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };
			}
			break;

			case TileType::Tile12:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Ground, "Tile_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Tile_12"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };
			}
			break;

			case TileType::Tile13:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Ground, "Tile_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Tile_13"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };
			}
			break;

			case TileType::Tile14:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Ground, "Tile_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Tile_14"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };
			}
			break;

			case TileType::Tile15:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Ground, "Tile_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Tile_15"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };
			}
			break;

			case TileType::Tile16:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Ground, "Tile_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Tile_16"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };
			}
			break;

			case TileType::Tile17:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Ground, "Tile_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Tile_17"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };
			}
			break;

			case TileType::WindAnim:
			{
				GameObject* Wind = curscene->CreateObject(Layer::Object, ObjectTag::Wind, "Wind");
				Animator* Wind_an = Wind->AddComponent<Animator>();
				Transform* Wind_tr = Wind->AddComponent<Transform>();
				RectCollider* Wind_rc = Wind->AddComponent<RectCollider>();

				Wind_an->AddAnimation(L"wind_animation", ResourceManager::Get()->Find<Animation>(L"Wind_Ani"));
				Wind_an->ActiveAnimation(L"wind_animation", true);
				
				int height = Wind_an->GetActiveAnimation()->GetImage()->GetHeight();
				int width = Wind_an->GetActiveAnimation()->GetImage()->GetWidth();

				Wind_tr->scale = { (float)width, (float)height };
				Wind_tr->position = { (float)x * Wind_tr->scale.x/2.0f, (float)(y * Wind_tr->scale.y) /3.0f };

				Wind_rc->size = { Wind_tr->scale.x,Wind_tr->scale.y };

			}

			break;

			case TileType::Wind:
			{
				GameObject* Wind = curscene->CreateObject(Layer::Object, ObjectTag::Wind, "Wind");
				Wind->AddComponent<Y_FanObjectScript>()->SetPos(Vector2(x * 64, y * 64 + 25));
			}
			break;

			case TileType::Rope1:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Rope, "Rope_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Rope1"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };
				RectCollider* rc = tile->AddComponent<RectCollider>();
				rc->size.x = tr->scale.x / 6;
				rc->offset.x = tr->scale.x - tr->scale.x / 1.7f;

			}
			break;
			
			case TileType::Rope2:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Rope, "Rope_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Rope2"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };
				RectCollider* rc = tile->AddComponent<RectCollider>();
				rc->size.x = tr->scale.x / 6;
				rc->offset.x = tr->scale.x - tr->scale.x / 1.7f;
			}
			break;

			case TileType::Rope3:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Rope, "Rope_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Rope3"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };
				RectCollider* rc = tile->AddComponent<RectCollider>();
				rc->size.x = tr->scale.x / 6;
				rc->offset.x = tr->scale.x - tr->scale.x / 1.7f;
			}
			break;

			case TileType::Rope4:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Rope, "Rope_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Rope4"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };
				RectCollider* rc = tile->AddComponent<RectCollider>();
				rc->size.x = tr->scale.x / 6;
				rc->offset.x = tr->scale.x - tr->scale.x / 1.7f;
			}
			break;

			case TileType::Rope5:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Rope, "Rope_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Rope5"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };
				RectCollider* rc = tile->AddComponent<RectCollider>();
				rc->size.x = tr->scale.x / 6;
				rc->offset.x = tr->scale.x - tr->scale.x / 1.7f;

			}
			break;

			case TileType::Laserup:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Trap, "Laser_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"LaserUp"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };
				RectCollider* rc = tile->AddComponent<RectCollider>();
			}
			break;

			case TileType::Laserdown:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Trap, "Laser_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"LaserDown"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };
				RectCollider* rc = tile->AddComponent<RectCollider>();
			}
			break;

			case TileType::Laserbeam:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Trap, "Laser_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"LaserBeam"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };
				RectCollider* rc = tile->AddComponent<RectCollider>();
				rc->size.x = tr->scale.x / 6;
				rc->offset.x = tr->scale.x-tr->scale.x/1.8f;
			}
			break;

			case TileType::LaserbeamUp:
			{
				GameObject* Laser = curscene->CreateObject(Layer::Object, ObjectTag::Trap, "Laser", ResourceManager::Get()->Find<Sprite>(L"LaserBeam"));
				Laser->AddComponent<Y_LaserBeamUp>()->SetPos(Vector2(x * 64, y * 64));
			}
			break;

			case TileType::LaserbeamDown:
			{
				GameObject* Laser = curscene->CreateObject(Layer::Object, ObjectTag::Trap, "Laser", ResourceManager::Get()->Find<Sprite>(L"LaserBeam"));
				Laser->AddComponent<Y_LaserBeamDown>()->SetPos(Vector2(x * 64, y * 64));
			}
			break;

			case TileType::Water1:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Trap, "Water_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Water1"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };
				RectCollider* rc = tile->AddComponent<RectCollider>();
				rc->size.y = tr->scale.y / 2;
				rc->offset.y = tr->scale.y - tr->scale.y / 2.f;
			}
			break;

			case TileType::Water2:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Trap, "Water_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Water2"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };
				RectCollider* rc = tile->AddComponent<RectCollider>();
				rc->size.y = tr->scale.y / 2;
				rc->offset.y = tr->scale.y - tr->scale.y / 2.f;

			}
			break;

			case TileType::Water3:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Trap, "Water_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Water3"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };
				RectCollider* rc = tile->AddComponent<RectCollider>();
				rc->size.y = tr->scale.y / 2;
				rc->offset.y = tr->scale.y - tr->scale.y / 2.f;

			}
			break;

			case TileType::Water4:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Trap, "Water_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Water4"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };
				RectCollider* rc = tile->AddComponent<RectCollider>();
				rc->size.y = tr->scale.y / 2;
				rc->offset.y = tr->scale.y - tr->scale.y / 2.f;

			}
			break;

			case TileType::Water5:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Trap, "Water_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Water5"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y  };
				RectCollider* rc = tile->AddComponent<RectCollider>();
			}
			break;

			case TileType::Water6:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Trap, "Water_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Water6"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };
				RectCollider* rc = tile->AddComponent<RectCollider>();

			}
			break;

			case TileType::Water7:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Trap, "Water_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Water7"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };
				RectCollider* rc = tile->AddComponent<RectCollider>();

			}
			break;

			case TileType::Water8:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Trap, "Water_" + std::to_string(x), ResourceManager::Get()->Find<Sprite>(L"Water8"));

				Spriterenderer* sp = tile->GetComponent<Spriterenderer>();

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { (float)sp->GetSprite()->GetWidth(), (float)sp->GetSprite()->GetHeight() };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };
				RectCollider* rc = tile->AddComponent<RectCollider>();
			}
			break;
			case TileType::Rain:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Rain, "Rain");

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { 64, 64 };
				tr->position = { x * tr->scale.x,  y * tr->scale.y };
				RectCollider* rc = tile->AddComponent<RectCollider>();
			}
			break;
			case TileType::Robot:
			{
				GameObject* tile = curscene->CreateObject(Layer::Object, ObjectTag::Robot, "Rain"
					, ResourceManager::Get()->Find<Sprite>(L"NPC5"));

				Transform* tr = tile->GetComponent<Transform>();
				tr->scale = { 128, 128 };
				tr->position = { (float)x * 64,  (float)y * 64 - 40 };
				RectCollider* rc = tile->AddComponent<RectCollider>();
			}
			break;
			}
		}
	}
}


