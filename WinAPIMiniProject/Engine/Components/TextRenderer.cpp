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

    // ��Ʈ ����
    HFONT hFont = CreateFont(
        height,                           // ��Ʈ ũ��
        0,                                // ��Ʈ �ʺ� (�⺻�� 0)
        0,                                // ���� ���� (�⺻�� 0)
        0,                                // ���� ���� (�⺻�� 0)
        FW_NORMAL,                        // ��Ʈ ��Ÿ��
        FALSE,                            // ����� ����
        FALSE,                            // ���� ����
        FALSE,                            // ��Ҽ� ����
        DEFAULT_CHARSET,                  // ���� ����
        OUT_DEFAULT_PRECIS,               // ��� ���е�
        CLIP_DEFAULT_PRECIS,              // Ŭ���� ���е�
        DEFAULT_QUALITY,                  // ��� ǰ��
        DEFAULT_PITCH | FF_DONTCARE,      // �۲� ��ġ�� �йи�
        m_fontName                        // �۲� �̸�
    );

    HDC _backDC = RenderManager::Get()->Get_BackDC();

    // ������ ��Ʈ�� DC�� ����
    HFONT hOldFont = (HFONT)(SelectObject(_backDC, hFont));

    // �ؽ�Ʈ ���
    SetBkMode(_backDC, TRANSPARENT); // ����� �������� ����
    SetTextColor(_backDC, m_color); // �ؽ�Ʈ ���� ����

    int i = 0;

    if (!onebyone)
    {
        for (; i < m_txt.size(); i++)
        {
            TextOutW(_backDC, _tr->worldPosition.x, _tr->worldPosition.y + (i * height), m_txt[i].c_str(), m_txt[i].length()); // ANSI ���ڿ� ��� (UTF-8�� ����Ϸ��� TextOutW �Լ��� ����ϼ���.)
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
                TextOutW(_backDC, _tr->worldPosition.x + offset.x, _tr->worldPosition.y + (i * height) + offset.y, m_txt[i].c_str(), wid_index); // ANSI ���ڿ� ��� (UTF-8�� ����Ϸ��� TextOutW �Լ��� ����ϼ���.)
            } 
            else
            {
                TextOutW(_backDC, _tr->worldPosition.x + offset.x, _tr->worldPosition.y + (i * height) + offset.y, m_txt[i].c_str(), m_txt[i].length()); // ANSI ���ڿ� ��� (UTF-8�� ����Ϸ��� TextOutW �Լ��� ����ϼ���.)
            }
        }
    }

    // ���õ� ��Ʈ ����
    SelectObject(_backDC, hOldFont);
    // ������ ��Ʈ ����
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
