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

	// ���ҽ��� ã���ϴ�
	template <typename T>
	T* Find(const std::wstring& _key)
	{
		//auto == std::map<std::wstring, GameResource*>::itator
		auto it = resourceList.find(_key);

		if (it == resourceList.end())
			return nullptr;

		return dynamic_cast<T*>(it->second);
	}
	// �ش� ����� ��������Ʈ�� �ҷ��� �����մϴ�.
	Sprite* AddSprite(const std::wstring& _key, const std::wstring _path);
	// ��������Ʈ �̹����� �ִϸ��̼� ������ �޾Ƽ� �ִϸ��̼��� �����մϴ�.
	Animation* AddAnimation(const std::wstring& _key, Sprite* _sprite, std::vector<std::pair<int, float>>& _arr);

	TileMap* AddTileMap(const std::wstring& _key, std::wstring _path, Sprite* _sprite);

private:

	std::map<std::wstring, GameResource*> resourceList;

};
