#include "Framework.h"

Sprite* ResourceManager::AddSprite(const std::wstring& _key, const std::wstring _path)
{
	// 매니저가 이미 가지고 있는지 확인해봅니다.
	Sprite* _sprite = Find<Sprite>(_key);

	// 이미 있는지 확인해서 없으면 만들어줍니다.
	if (_sprite != nullptr) 
		return _sprite;

	else _sprite = new Sprite();

	// 생성에 실패했을 때 예외처리도 잊지말기
	if (_sprite->Load(_path) == false)
		assert(false);

	// 매니저의 배열에 넣어줍니다
	resourceList.insert(std::make_pair(_key, _sprite));

	return _sprite;
}

Animation* ResourceManager::AddAnimation(const std::wstring& _key, Sprite* _sprite, std::vector<std::pair<int, float>>& _arr)
{

	Animation* _animation = Find<Animation>(_key);

	if (_animation != nullptr)
		return _animation;

	else _animation = new Animation();

	if (_animation->Load(_sprite, _arr) == false)
		assert(false);

	resourceList.insert(std::make_pair(_key, _animation));

	return _animation;
}

TileMap* ResourceManager::AddTileMap(const std::wstring& _key, std::wstring _path, Sprite* _sprite)
{

	TileMap* _tilemap = Find<TileMap>(_key);

	if (_tilemap != nullptr)
		return _tilemap;

	else _tilemap = new TileMap();

	if (_tilemap->Load(_path, _sprite) == false)
		assert(false);

	resourceList.insert(std::make_pair(_key, _tilemap));

	return _tilemap;
}


