#include "Framework.h"

GameManager* GameManager::instance = nullptr;

GameManager::GameManager()
{
	Time::Get();
	SceneManager::Get();
	KeyManager::Get();
	MouseManager::Get();
}

GameManager::~GameManager()
{
	Time::Delete();
	KeyManager::Delete();
	MouseManager::Delete();
	SceneManager::Delete();
	Finalize();
}

void GameManager::Render()
{
	RenderManager::Get()->Render();
}

void GameManager::Finalize()
{
	SoundManager::Get()->Finalize();
}


void GameManager::Initialize(HWND hwnd)
{
	RenderManager::Get()->Initialize(hwnd, MAX_WIDTH, MAX_HEIGHT);
	SoundManager::Get()->Initialize();
	SceneManager::Get()->Initialize();
	EffectManager::Get()->Initialize();
}

void GameManager::Update()
{
	KeyManager::Get()->UpdateInput();
	MouseManager::Get()->UpdateMouse();
	SceneManager::Get()->Update();
	SoundManager::Get()->Update();
}

void GameManager::FixedUpdate()
{
	static float FixedTimer = 0.f;
	FixedTimer += DELTA;
	if (FixedTimer >= 0.02f)
	{
		SceneManager::Get()->FixedUpdate();
		FixedTimer -= 0.02f;
	}
}

void GameManager::LateUpdate()
{
	SceneManager::Get()->LateUpdate();
	KeyManager::Get()->ResetInput();
}
