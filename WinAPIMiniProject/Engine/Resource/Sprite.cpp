#include "Framework.h"

Sprite::Sprite() 
	: GameResource(ResourceType::Sprite)
{
	m_image = nullptr;
	m_bitmap = nullptr;
	data = { {0,0}, {0,0}, {0,0}, {0,0} };
	m_hdc = nullptr;
}

Sprite::~Sprite()
{
}

bool Sprite::Load(const std::wstring& _path)
{
	// ���������� �Ųٷ� �о .���� ���� �� Ȯ���ڸ� ���ɴϴ�
	std::wstring _ext = _path.substr(_path.find_last_of(L".") + 1);

	// ��θ� �������ݴϴ�
	SetPath(_path);

	// Ȯ���� ���� �� �̹��� ���� �ε� �� ����
	if (_ext == L"bmp")
	{
		SetExt(ExtType::Bmp);

		m_bitmap = Gdiplus::Bitmap::FromFile(_path.c_str());

		if (m_bitmap == nullptr)
			return false;

		data.fullSize = { (long)m_bitmap->GetWidth(), (long)m_bitmap->GetHeight()};
		data.count = { 1, 1 }; // �⺻ ������ 1 X 1
		data.cutPos = { 0, 0 }; // ���� ��ġ�� �⺻ 0,0
		data.offset = { 0, 0 }; // �⺻ �ɼµ� �ú� 0,0
	}
	else if (_ext == L"png")
	{
		SetExt(ExtType::Png);
		m_image = Gdiplus::Image::FromFile(_path.c_str());

		if (m_image == nullptr)
			return false;

		data.fullSize = { (long)m_image->GetWidth(), (long)m_image->GetHeight() };
		data.count = { 1, 1 }; // �⺻ ������ 1 X 1
		data.cutPos = { 0, 0 }; // ���� ��ġ�� �⺻ 0,0
		data.offset = { 0, 0 }; // �⺻ �ɼµ� �ú� 0,0
	}
		
	m_hdc = CreateCompatibleDC(RenderManager::Get()->Get_FrontDC());

	return true;
}