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
	// 마지막부터 거꾸로 읽어서 .에서 멈춘 후 확장자만 따옵니당
	std::wstring _ext = _path.substr(_path.find_last_of(L".") + 1);

	// 경로를 설정해줍니다
	SetPath(_path);

	// 확장자 설정 및 이미지 정보 로드 후 저장
	if (_ext == L"bmp")
	{
		SetExt(ExtType::Bmp);

		m_bitmap = Gdiplus::Bitmap::FromFile(_path.c_str());

		if (m_bitmap == nullptr)
			return false;

		data.fullSize = { (long)m_bitmap->GetWidth(), (long)m_bitmap->GetHeight()};
		data.count = { 1, 1 }; // 기본 설정은 1 X 1
		data.cutPos = { 0, 0 }; // 시작 위치도 기본 0,0
		data.offset = { 0, 0 }; // 기본 옵셋도 시본 0,0
	}
	else if (_ext == L"png")
	{
		SetExt(ExtType::Png);
		m_image = Gdiplus::Image::FromFile(_path.c_str());

		if (m_image == nullptr)
			return false;

		data.fullSize = { (long)m_image->GetWidth(), (long)m_image->GetHeight() };
		data.count = { 1, 1 }; // 기본 설정은 1 X 1
		data.cutPos = { 0, 0 }; // 시작 위치도 기본 0,0
		data.offset = { 0, 0 }; // 기본 옵셋도 시본 0,0
	}
		
	m_hdc = CreateCompatibleDC(RenderManager::Get()->Get_FrontDC());

	return true;
}