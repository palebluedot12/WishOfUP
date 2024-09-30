#include "Framework.h"
#include "TextRenderer.h"

TextRenderer::TextRenderer()
{
	SetType(ComponentType::TextRenderer);
	offset = { 0,0 };
	m_color = RGB(0, 0, 0);
	width = 0;
	height = 30;
	m_fontPath = L"";
    m_txt = {};
    isActive = true;
    onebyone = false;
    wid_index = 1;
    hei_index = 1;
    count = 0;
    isStop = false;
}

TextRenderer::~TextRenderer()
{
    if (m_fontPath != L"")
    {
        RemoveFontResource(m_fontPath);
    }
}

void TextRenderer::Render()
{
	if (m_fontPath == L"") return;
	if (m_fontName == L"") return;
	if (m_txt.empty()) return;
	if (!isActive) return;

    Transform* _tr = GetOwner()->GetComponent<Transform>();

    if (_tr == nullptr) return;

    // 폰트 생성
    HFONT hFont = CreateFont(
        height,                           // 폰트 크기
        0,                                // 폰트 너비 (기본값 0)
        0,                                // 문자 각도 (기본값 0)
        0,                                // 문자 방향 (기본값 0)
        FW_NORMAL,                        // 폰트 스타일
        FALSE,                            // 기울임 여부
        FALSE,                            // 밑줄 여부
        FALSE,                            // 취소선 여부
        DEFAULT_CHARSET,                  // 문자 집합
        OUT_DEFAULT_PRECIS,               // 출력 정밀도
        CLIP_DEFAULT_PRECIS,              // 클리핑 정밀도
        DEFAULT_QUALITY,                  // 출력 품질
        DEFAULT_PITCH | FF_DONTCARE,      // 글꼴 피치와 패밀리
        m_fontName                        // 글꼴 이름
    );

    HDC _backDC = RenderManager::Get()->Get_BackDC();

    // 생성된 폰트를 DC에 선택
    HFONT hOldFont = (HFONT)(SelectObject(_backDC, hFont));

    // 텍스트 출력
    SetBkMode(_backDC, TRANSPARENT); // 배경을 투명으로 설정
    SetTextColor(_backDC, m_color); // 텍스트 색상 설정

    int i = 0;

    if (!onebyone)
    {
        for (; i < m_txt.size(); i++)
        {
            TextOutW(_backDC, _tr->worldPosition.x, _tr->worldPosition.y + (i * height), m_txt[i].c_str(), m_txt[i].length()); // ANSI 문자열 출력 (UTF-8을 사용하려면 TextOutW 함수를 사용하세요.)
        }
    }
    else
    {
        count += DELTA;
        if (count >= 0.05f && wid_index < m_txt[hei_index - 1].length())
        {
            wid_index++;
            count = 0.f;
        }
        if (wid_index >= m_txt[hei_index - 1].length())
        {
            if (hei_index < m_txt.size())
            {
                wid_index = 0;
                hei_index++;
            }
        }
        
        for (; i < hei_index; i++)
        {
            if (i == hei_index - 1)
            {
                TextOutW(_backDC, _tr->worldPosition.x + offset.x, _tr->worldPosition.y + (i * height) + offset.y, m_txt[i].c_str(), wid_index); // ANSI 문자열 출력 (UTF-8을 사용하려면 TextOutW 함수를 사용하세요.)
            } 
            else
            {
                TextOutW(_backDC, _tr->worldPosition.x + offset.x, _tr->worldPosition.y + (i * height) + offset.y, m_txt[i].c_str(), m_txt[i].length()); // ANSI 문자열 출력 (UTF-8을 사용하려면 TextOutW 함수를 사용하세요.)
            }
        }
    }

    // 선택된 폰트 해제
    SelectObject(_backDC, hOldFont);
    // 생성된 폰트 해제
    DeleteObject(hFont);

}

void TextRenderer::SetFont(const wchar_t* _name, const wchar_t* _path)
{
    if (AddFontResource(_path) == 0)
    {
        assert(false);
    }
    m_fontPath = _path;
    m_fontName = _name;
}
void TextRenderer::DrawAll()
{
    if (onebyone)
    {
        onebyone = false;
    }
}
