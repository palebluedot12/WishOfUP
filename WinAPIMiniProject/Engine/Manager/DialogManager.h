#pragma once

class DialogManager : public Singleton<DialogManager>
{
private:
    friend class Singleton<DialogManager>;
    DialogManager() = default;
    ~DialogManager() = default;

public:
    void Initialize(Gdiplus::Graphics* graphics);
    void StartDialogue(const std::wstring& text, const Gdiplus::Point& position);
    void Update();
    void Render();

private:
    void DrawSpeechBubble(const Gdiplus::Rect& rect);
    void DrawDialogueText(const std::wstring& text, const Gdiplus::Rect& rect);

    Gdiplus::Graphics* graphics;
    std::wstring fullText;
    std::wstring currentText;
    size_t currentIndex;
    std::chrono::time_point<std::chrono::high_resolution_clock> lastTime;
    bool isDisplaying;
    Gdiplus::Point position;
    const float charDisplayInterval = 0.1f;
};
