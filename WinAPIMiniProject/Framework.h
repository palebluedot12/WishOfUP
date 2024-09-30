#pragma once

#include <SDKDDKVer.h>

#define MAX_WIDTH 1024 //화면크기
#define MAX_HEIGHT 768
#define HALF_WIDTH MAX_WIDTH/2.0f //화면크기의 절반
#define HALF_HEIGHT MAX_HEIGHT/2.0f

#define LOAD_SCENE(n) SceneManager::Get()->LoadScene(n)
#define FIND_SCENE(n) SceneManager::Get()->FindScene<n>()

#define KEY_DOWN(n) KeyManager::Get()->IsDown(n)
#define KEY_HOLD(n) KeyManager::Get()->IsHold(n)
#define KEY_UP(n) KeyManager::Get()->IsUp(n)

#define SOUND SoundManager::Get()
#define DELTA Time::Get()->GetDeltaTime()
#define SCREEN_START_LEFT 10;
#define SCREEN_START_TOP 10;

#define PI 3.14

// Windows 헤더 파일
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <cmath>
#include <assert.h>
#include<unordered_map> 
#include <bitset>
#include <chrono>
#include <fstream>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>

// Gdi+
#include <gdiplus.h>
#pragma comment(lib, "gdiplus.lib")


//Utilities
#include "Engine/Utilities/Singleton.h"
#include "Engine/Utilities/Time.h"
#include "Engine/Utilities/EnumList.h"
#include "Engine/Utilities/StructList.h"
#include "Engine/Utilities/Utility.h"

//Math
#include "Engine/Math/Vector2.h"

//Component
#include "Engine/Components/Component.h"
#include "Engine/Components/Transform.h"
#include "Engine/Components/Collider.h"
#include "Engine/Components/SpriteRenderer.h"
#include "Engine/Components/Animator.h"
#include "Engine/Components/Script.h"
#include "Engine/Components/Camera.h"
#include "Engine/Components/TextRenderer.h"

//Game
#include "Engine/Object/GameObject.h"
#include "Engine/Scene/GameScene.h"

//Resource
#include "Engine/Resource/DataSheet/SpriteData.h"
#include "Engine/Resource/GameResource.h"
#include "Engine/Resource/Animation.h"
#include "Engine/Resource/Sprite.h"
#include "Engine/Resource/TileMap.h"

//Manager
#include "Engine/Manager/SceneManager.h"
#include "Engine/Manager/RenderManager.h"
#include "Engine/Manager/ResourceManager.h"
#include "Engine/Manager/GameManager.h"
#include "Engine/CollisionSystem.h"
#include "Engine/Manager/EventManager.h"
#include "Engine/Manager/InputManager.h"
#include "Engine/Manager/SoundManager.h"
#include "Engine/Manager/DialogManager.h"
#include "Engine/Manager/TileManager.h"
#include "Engine/Manager/EffectManager.h"

// 커스텀 씬과 스크립트
#include "Scene/Y_LoadScene.h"
#include "Scene/Y_UndergroundScene.h"
#include "Scene/Y_ResidentialAreaScene.h"
#include "Scene/Y_UpperAreaScene.h"
#include "Scene/Y_CutScene_UpperArea.h"
#include "Scene/Y_EndingScene_Choice1.h"
#include "Scene/Y_EndingScene_Choice2.h"

#include "Scene/Y_TitleScene.h"
#include "Scene/Y_IntroScene.h"
#include "Scene/Y_EndingScene_Choice1.h"
#include "Scene/Y_EndingScene_Choice2.h"

#include "Script/Y_BtScript.h"
#include "Script/Y_DashEffectScript.h"
#include "Script/Y_PlayerScript.h"
#include "Script/Y_LoadScript.h"
#include "Script/Y_InteractScript.h"
#include "Script/Y_PauseScript.h"
#include "Script/Y_LifeBarScript.h"
#include "Script/Y_ManagerScript.h"
#include "Script/Y_DashBarScript.h"
#include "Script/Y_FanObjectScript.h"
#include "Script/Y_LaserBeamUp.h"
#include "Script/Y_LaserBeamDown.h"
#include "Script/Y_IntroScript.h"
#include "Script/Y_RainScript.h"
#include "Script/Y_RainSpawner.h"
#include "Script/Y_EndingScript_1.h"
#include "Script/Y_EndingScript_2.h"
