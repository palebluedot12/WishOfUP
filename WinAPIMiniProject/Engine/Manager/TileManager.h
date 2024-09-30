#pragma once
class Sprite;

class TileManager : public GameScene, public Singleton<TileManager>
{
private:

	friend class Singleton;
	TileManager() = default;
	~TileManager() {}

public:
	void Initialize();
	void LoadMapData(GameScene* curscene, std::string file);
	void CreateTile(GameScene* curscene);
	void LoadColliderData(GameScene* curscene, std::string file);
	void CreateCollider(GameScene* curscene);

private:
	UINT _width, _height;
	TileType _tileType;
	Vector2 _mapSize;

	Animator* _an = nullptr;
	std::vector<std::vector<int>> _tileData;
	std::vector<std::vector<std::string>> _colliderData;

	bool _isLoad = true;

};

