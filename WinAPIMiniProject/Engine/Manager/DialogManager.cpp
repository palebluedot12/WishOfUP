#include "Framework.h"

void DialogManager::Initialize(Gdiplus::Graphics* graphics)
{
    this->graphics = graphics;
    isDisplaying = false;
    currentIndex = 0;
}

void DialogManager::StartDialogue(const std::wstring& text, const Gdiplus::Point& position)
{
    fullText = text;
    currentText.clear();
    currentIndex = 0;
    lastTime = std::chrono::high_resolution_clock::now();
    isDisplaying = true;
    this->position = position;
}

void DialogManager::Update()
{
    if (!isDisplaying)
        return;

    auto now = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> elapsed = now - lastTime;

    if (elapsed.count() >= charDisplayInterval)
    {
        if (currentIndex < fullText.size())
        {
            currentText += fullText[currentIndex++];
            lastTime = now;
        }
        else
        {
            isDisplaying = false;
        }
    }
}

void DialogManager::Render()
{
    if (!isDisplaying)
        return;

    Gdiplus::Rect rect(position.X, position.Y, 300, 100);
    DrawSpeechBubble(rect);
    DrawDialogueText(currentText, rect);
}

void DialogManager::DrawSpeechBubble(const Gdiplus::Rect& rect)
{
    Gdiplus::Pen pen(Gdiplus::Color(255, 0, 0, 0), 2);
    Gdiplus::SolidBrush brush(Gdiplus::Color(255, 255, 255));

    graphics->FillRectangle(&brush, rect);
    graphics->DrawRectangle(&pen, rect);

    Gdiplus::Point points[] = {
        Gdiplus::Point(rect.X + rect.Width / 2 - 10, rect.Y + rect.Height),
        Gdiplus::Point(rect.X + rect.Width / 2 + 10, rect.Y + rect.Height),
        Gdiplus::Point(rect.X + rect.Width / 2, rect.Y + rect.Height + 20)
    };
    graphics->FillPolygon(&brush, points, 3);
    graphics->DrawPolygon(&pen, points, 3);
}

void DialogManager::DrawDialogueText(const std::wstring& text, const Gdiplus::Rect& rect)
{
    Gdiplus::FontFamily fontFamily(L"Arial");
    Gdiplus::Font font(&fontFamily, 16, Gdiplus::FontStyleRegular, Gdiplus::UnitPixel);
    Gdiplus::SolidBrush brush(Gdiplus::Color(255, 0, 0, 0));

    Gdiplus::RectF layoutRect(rect.X + 10, rect.Y + 10, rect.Width - 20, rect.Height - 20);
    Gdiplus::StringFormat format;
    format.SetAlignment(Gdiplus::StringAlignmentNear);
    format.SetLineAlignment(Gdiplus::StringAlignmentNear);

    graphics->DrawString(text.c_str(), -1, &font, layoutRect, &format, &brush);
}
