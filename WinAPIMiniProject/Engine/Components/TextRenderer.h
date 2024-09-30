#pragma once
class TextRenderer : public Component
{
public:
	TextRenderer();
	~TextRenderer();

	virtual void Render() override;
	
	void SetFont(const wchar_t* _name, const wchar_t* _path);
	void SetText(std::vector<std::wstring> _str) { m_txt = _str; }
	void SetColor(COLORREF _color) { m_color = _color; }
	void SetActive(bool _val) { isActive = _val; }

	void OneByOne(bool _val) { onebyone = _val; }
	void Reset() { wid_index = 1; hei_index = 1; count = 0; }
	void Stop() { isStop = true; }
	void Play() { isStop = false; }
	void DrawAll();

	std::vector<std::wstring> GetText() { return m_txt; }
	COLORREF GetColor() { return m_color; }

	bool IsActive() { return isActive; }

	int height; // 텍스트 크기
	int width; // 텍스트 너비
	Vector2 offset; // 오프셋


private:

	bool isActive;
	const wchar_t* m_fontPath;
	const wchar_t* m_fontName;
	COLORREF m_color;
	std::vector<std::wstring> m_txt;

	bool onebyone;
	int wid_index;
	int hei_index;
	float count;
	bool isStop;

};

