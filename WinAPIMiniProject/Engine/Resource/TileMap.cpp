#include "Framework.h"
#include "TileMap.h"

TileMap::TileMap()
	: GameResource(ResourceType::TileMap)
{
}

TileMap::~TileMap()
{
}

bool TileMap::Load(const std::wstring& _path, Sprite* _sprite)
{
	// 경로를 설정해줍니다
	SetPath(_path);
	SetExt(ExtType::Csv);

	std::wifstream loadfile(_path);
	if (!loadfile.is_open())
		assert(false);

	m_sprite = _sprite;
	if (_sprite == nullptr)
		assert(false);
	

	std::wstring temp;
	std::vector<std::vector<int>> tileData;  // 타일 데이터를 임시로 저장할 컨테이너

	int rowIndex = 0;
	while (loadfile >> temp)
	{
		std::vector<int> datas = SplitString(temp, L",");

		if (rowIndex == 0) {
			mapSize.x = datas.size();  // 첫 번째 행을 기준으로 맵의 가로 크기 설정
		}

		tileData.push_back(datas);
		rowIndex++;
	}

	mapSize.y = rowIndex;  // 읽은 행 수를 기준으로 맵의 세로 크기 설정

	// 임시 타일 데이터를 멤버 변수로 이동
	_tileData = std::move(tileData);

	mapScale = { static_cast<float>(mapSize.x) * _sprite->GetWidth(),
				 static_cast<float>(mapSize.y) * _sprite->GetHeight() };

	return true;
}

std::vector<int> TileMap::SplitString(const std::wstring& origin, const std::wstring& tok)
{
	std::vector<int> result;
	std::wstring temp = origin;

	size_t cutAt = 0;

	while ((cutAt = temp.find_first_of(tok)) != std::wstring::npos)
	{
		if (cutAt > 0) {
			std::wstring token = temp.substr(0, cutAt);
			result.push_back(std::stoi(token));
		}
		temp = temp.substr(cutAt + 1);
	}

	if (!temp.empty()) {
		result.push_back(std::stoi(temp));
	}

	return result;
}
