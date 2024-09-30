#pragma once

class GameObject;
class GameScene;
class Script;

// 스프라이트 이미지에 필요한 데이터
struct SpriteData
{
	POINT fullSize; // 스프라이트 이미지 전체 크기
	POINT count; // 몇 X 몇인지
	POINT cutPos; // 스프라이트 이미지의 시작 지점
	POINT offset; // 자른 후 남길 여백
};

struct EventData
{
	Event_Theme theme = Event_Theme::Default;
	Event_Type type = Event_Type::Default;
	Event_List event = Event_List::None;
	GameScene* sceneParam = nullptr;
	GameObject* objectParam = nullptr;
};

