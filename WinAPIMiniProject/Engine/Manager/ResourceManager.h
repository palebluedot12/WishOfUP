#pragma once


class Texture;
class GameResource;

class ResourceManager : public Singleton<ResourceManager>
{

private:
	friend class Singleton;
	ResourceManager() = default;
	~ResourceManager() = default;

public:

	// 리소스를 찾습니닷
	template <typename T>
	T* Find(const std::wstring& _key)
	{
		//auto == std::map<std::wstring, GameResource*>::itator
		auto it = resourceList.find(_key);

		if (it == resourceList.end())
			return nullptr;

		return dynamic_cast<T*>(it->second);
	}
	// 해당 경로의 스프라이트를 불러와 저장합니다.
	Sprite* AddSprite(const std::wstring& _key, const std::wstring _path);
	// 스프라이트 이미지와 애니메이션 정보를 받아서 애니메이션을 저장합니다.
	Animation* AddAnimation(const std::wstring& _key, Sprite* _sprite, std::vector<std::pair<int, float>>& _arr);

	TileMap* AddTileMap(const std::wstring& _key, std::wstring _path, Sprite* _sprite);

private:

	std::map<std::wstring, GameResource*> resourceList;

};
