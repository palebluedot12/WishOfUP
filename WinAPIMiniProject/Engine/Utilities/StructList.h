#pragma once

class GameObject;
class GameScene;
class Script;

// ��������Ʈ �̹����� �ʿ��� ������
struct SpriteData
{
	POINT fullSize; // ��������Ʈ �̹��� ��ü ũ��
	POINT count; // �� X ������
	POINT cutPos; // ��������Ʈ �̹����� ���� ����
	POINT offset; // �ڸ� �� ���� ����
};

struct EventData
{
	Event_Theme theme = Event_Theme::Default;
	Event_Type type = Event_Type::Default;
	Event_List event = Event_List::None;
	GameScene* sceneParam = nullptr;
	GameObject* objectParam = nullptr;
};

