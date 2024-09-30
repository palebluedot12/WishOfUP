#pragma once

class Y_BtScript : public Script
{
private:

    Spriterenderer* bt_sprite;

public:

    Transform* bt_trans;
    int _index = 0;
    int _state = 0;

    EventData _onEvent = { Event_Theme::Default ,Event_Type::Default, Event_List::None }; // 올리기만 해도
    EventData _clickEvent = { Event_Theme::Default ,Event_Type::Default, Event_List::None }; // 
    EventData _upEvent = { Event_Theme::Default ,Event_Type::Default, Event_List::None };

    void Start()
    {
        bt_sprite = gameobject->GetComponent<Spriterenderer>();
        bt_trans = gameobject->GetComponent<Transform>();
    }

    void Update()
    {
        if (bt_sprite != nullptr &&
            (bt_sprite->GetSprite()->data.count.x * bt_sprite->GetSprite()->data.count.y) >= _index + _state + 1)
            bt_sprite->index = _index + _state;

        if (bt_trans->worldPosition.x < mouse->position.x &&
            bt_trans->worldPosition.y <  mouse->position.y &&
            bt_trans->worldPosition.x + bt_trans->scale.x > mouse->position.x &&
            bt_trans->worldPosition.y + bt_trans->scale.y > mouse->position.y)
        {
            if (mouse->IsHold(MouseType::LEFT))
            {
                _state = 1;
                if (mouse->IsDown(MouseType::LEFT) && _clickEvent.event != Event_List::None)
                    ClickEvent();
            }
            else if (mouse->IsUp(MouseType::LEFT))
            {
                _state = 0;
                if (_upEvent.event != Event_List::None)
                    UpEvent();
            }
            else
            {
                _state = 0;
                if (_onEvent.event != Event_List::None)
                    OnEvent();
            }
        }
    }

    void OnEvent()
    {
        if (_onEvent.theme == Event_Theme::Default)
            EventManager::Get()->CallEvent(_onEvent);
        else if (_onEvent.theme == Event_Theme::Fade)
        {
            if (RenderManager::Get()->FadeInOutStart())
            {
                EventManager::Get()->FadeEventPush(_onEvent);
            }   
        }
    }
    void ClickEvent()
    {
        if (_clickEvent.theme == Event_Theme::Default)
            EventManager::Get()->CallEvent(_clickEvent);
        else if (_clickEvent.theme == Event_Theme::Fade)
        {
            if (RenderManager::Get()->FadeInOutStart())
            {
                EventManager::Get()->FadeEventPush(_clickEvent);
            }
        }
    }
    void UpEvent()
    {
        if (_upEvent.theme == Event_Theme::Default)
            EventManager::Get()->CallEvent(_upEvent);
        else if (_upEvent.theme == Event_Theme::Fade)
        {
            if (RenderManager::Get()->FadeInOutStart())
            {
                EventManager::Get()->FadeEventPush(_upEvent);
            }
        }
    }
};