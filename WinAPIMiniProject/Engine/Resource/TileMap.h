#pragma once

class TileMap : public GameResource
{
public:

	TileMap();
	~TileMap();

	bool Load(const std::wstring& _path, Sprite* _sprite);

	Sprite* GetSprite() { return m_sprite; }
	HDC GetHDC() { return m_hdc; }
	POINT GetMapSize() { return mapSize; }
	Vector2 GetMapScale() { return mapScale; }
	std::vector<std::vector<int>>& GetTileData() { return _tileData; }

private:

	Sprite* m_sprite;
	std::vector<std::vector<int>> _tileData;

	POINT mapSize; // 몇 X 몇인지
	Vector2 mapScale;

	HDC m_hdc;

	std::vector<int> SplitString(const std::wstring& origin, const std::wstring& tok);
};

