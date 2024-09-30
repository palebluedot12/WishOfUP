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
	// ��θ� �������ݴϴ�
	SetPath(_path);
	SetExt(ExtType::Csv);

	std::wifstream loadfile(_path);
	if (!loadfile.is_open())
		assert(false);

	m_sprite = _sprite;
	if (_sprite == nullptr)
		assert(false);
	

	std::wstring temp;
	std::vector<std::vector<int>> tileData;  // Ÿ�� �����͸� �ӽ÷� ������ �����̳�

	int rowIndex = 0;
	while (loadfile >> temp)
	{
		std::vector<int> datas = SplitString(temp, L",");

		if (rowIndex == 0) {
			mapSize.x = datas.size();  // ù ��° ���� �������� ���� ���� ũ�� ����
		}

		tileData.push_back(datas);
		rowIndex++;
	}

	mapSize.y = rowIndex;  // ���� �� ���� �������� ���� ���� ũ�� ����

	// �ӽ� Ÿ�� �����͸� ��� ������ �̵�
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
