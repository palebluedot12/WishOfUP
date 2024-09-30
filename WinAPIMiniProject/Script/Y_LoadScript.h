#pragma once

class Y_LoadScript : public Script
{
private:
	Animation* an;
	Sprite* sp;

public:
	void Start()
	{
		// ============리소스 등록하는 과정입니닷============

		// 사운드
		SoundManager::Get()->AddSound(SoundList::CloseUmbrella, "Asset/Sound/CloseUmbrella.mp3", false);
		SoundManager::Get()->AddSound(SoundList::OpenUmbrella, "Asset/Sound/OpenUmbrella.mp3", false);
		SoundManager::Get()->AddSound(SoundList::Dash, "Asset/Sound/Dash.mp3", false);
		SoundManager::Get()->AddSound(SoundList::BackGround_1, "Asset/Sound/DownAreaBGM.mp3", true);
		SoundManager::Get()->AddSound(SoundList::BackGround_2, "Asset/Sound/ResidentialAreaBGM.mp3", true);
		SoundManager::Get()->AddSound(SoundList::BackGround_3, "Asset/Sound/UpperLevelAreaBGM.mp3", true);
		SoundManager::Get()->AddSound(SoundList::BackGround_4, "Asset/Sound/LastAreaBGM.mp3", true);
		SoundManager::Get()->AddSound(SoundList::Ending1BGM, "Asset/Sound/Ending1BGM.mp3", true);
		SoundManager::Get()->AddSound(SoundList::Ending2BGM, "Asset/Sound/Ending2BGM.mp3", true);
		SoundManager::Get()->AddSound(SoundList::IntroBGM, "Asset/Sound/IntroBGM.mp3", true);
		SoundManager::Get()->AddSound(SoundList::MainBGM, "Asset/Sound/MainBGM.mp3", true);
		SoundManager::Get()->AddSound(SoundList::GameOver, "Asset/Sound/GameOver.mp3", false);
		SoundManager::Get()->AddSound(SoundList::GameOverBtn, "Asset/Sound/GameOverBtn.mp3", false);
		SoundManager::Get()->AddSound(SoundList::DoubleJump, "Asset/Sound/PlayerDoubleJump.mp3", false);
		SoundManager::Get()->AddSound(SoundList::Hit, "Asset/Sound/PlayerHit.mp3", false);
		SoundManager::Get()->AddSound(SoundList::Jump, "Asset/Sound/PlayerJump.mp3", false);
		SoundManager::Get()->AddSound(SoundList::Land, "Asset/Sound/PlayerLand.mp3", false);
		SoundManager::Get()->AddSound(SoundList::Move, "Asset/Sound/PlayerWalk.mp3", false);
		SoundManager::Get()->AddSound(SoundList::WallJump, "Asset/Sound/PlayerWallJump.mp3", false);
		SoundManager::Get()->AddSound(SoundList::Wind, "Asset/Sound/Wind.mp3", false);

		// 배경 관련
		resource->AddSprite(L"Title", L"Asset/Sprite/BG/Title.bmp");
		resource->AddSprite(L"BG1", L"Asset/Sprite/BG/residential_area.bmp");
		resource->AddSprite(L"BG2", L"Asset/Sprite/BG/substratum.bmp");
		resource->AddSprite(L"BG3", L"Asset/Sprite/BG/top_floor.bmp");
		resource->AddSprite(L"BG4", L"Asset/Sprite/BG/upper_floor.bmp");

		// 컷신 관련
		resource->AddSprite(L"Intro1", L"Asset/Sprite/CS/Intro1.png");
		resource->AddSprite(L"Intro2", L"Asset/Sprite/CS/Intro2.png");
		resource->AddSprite(L"Intro3", L"Asset/Sprite/CS/Intro3.png");
		
		sp = resource->AddSprite(L"Moni", L"Asset/Sprite/NPC/monitor.bmp");
		sp = resource->AddSprite(L"Monitor_1", L"Asset/Sprite/NPC/monitor_text_1.png");
		sp = resource->AddSprite(L"Monitor_2", L"Asset/Sprite/NPC/monitor_text_2.png");
		sp = resource->AddSprite(L"Monitor_3", L"Asset/Sprite/NPC/monitor_text_3.png");
		sp = resource->AddSprite(L"Monitor_4", L"Asset/Sprite/NPC/monitor_text_4.png");
		sp = resource->AddSprite(L"Monitor_5", L"Asset/Sprite/NPC/monitor_text_5.png");
		sp = resource->AddSprite(L"Monitor_6", L"Asset/Sprite/NPC/monitor_text_6.png");
		sp = resource->AddSprite(L"Blackbox", L"Asset/Sprite/NPC/blackbox.png");
		sp = resource->AddSprite(L"Question_Mark", L"Asset/Sprite/NPC/question_mark.png");

		{
			// 타이틀 씬
			resource->AddSprite(L"TitleBackground", L"Asset/Sprite/CS/TitleBackground.png");

			// 인트로 씬
			resource->AddSprite(L"Intro1", L"Asset/Sprite/CS/Intro1.png");
			resource->AddSprite(L"Intro2", L"Asset/Sprite/CS/Intro2.png");
			resource->AddSprite(L"Intro3", L"Asset/Sprite/CS/Intro3.png");
		}
		{
			// 엔딩 1
			resource->AddSprite(L"E1_1", L"Asset/Sprite/CS/E1_1.png");
			resource->AddSprite(L"E1_2", L"Asset/Sprite/CS/E1_2.png");
			resource->AddSprite(L"E1_3", L"Asset/Sprite/CS/E1_3.png");
			resource->AddSprite(L"E1_4", L"Asset/Sprite/CS/E1_4.png");
			resource->AddSprite(L"E1_5", L"Asset/Sprite/CS/E1_5.png");
			resource->AddSprite(L"E1_6", L"Asset/Sprite/CS/E1_6.png");
			resource->AddSprite(L"E1_7", L"Asset/Sprite/CS/E1_7.png");
			resource->AddSprite(L"E1_8", L"Asset/Sprite/CS/E1_8.png");
			resource->AddSprite(L"E1_9", L"Asset/Sprite/CS/E1_9.png");
			resource->AddSprite(L"E1_10", L"Asset/Sprite/CS/E1_10.png");
			
			// 엔딩 2
			resource->AddSprite(L"E2_1", L"Asset/Sprite/CS/E2_1.png");
			resource->AddSprite(L"E2_2", L"Asset/Sprite/CS/E2_2.png");
			resource->AddSprite(L"E2_3", L"Asset/Sprite/CS/E2_3.png");
			resource->AddSprite(L"E2_4", L"Asset/Sprite/CS/E2_4.png");
			resource->AddSprite(L"E2_5", L"Asset/Sprite/CS/E2_5.png");
	}
	{
			// 상호작용 오브젝트
			sp = resource->AddSprite(L"Monitor_S", L"Asset/Sprite/NPC/monitor_test.png");
			sp = resource->AddSprite(L"Moni", L"Asset/Sprite/NPC/monitor.bmp");
			sp = resource->AddSprite(L"Monitor_1", L"Asset/Sprite/NPC/monitor_text_1.png");
			sp = resource->AddSprite(L"Monitor_2", L"Asset/Sprite/NPC/monitor_text_2.png");
			sp = resource->AddSprite(L"Monitor_3", L"Asset/Sprite/NPC/monitor_text_3.png");
			sp = resource->AddSprite(L"Monitor_4", L"Asset/Sprite/NPC/monitor_text_4.png");
			sp = resource->AddSprite(L"Monitor_5", L"Asset/Sprite/NPC/monitor_text_5.png");
			sp = resource->AddSprite(L"Monitor_6", L"Asset/Sprite/NPC/monitor_text_6.png");

			sp = resource->AddSprite(L"Main_Monitor_1", L"Asset/Sprite/NPC/mainMonitor_text_1.png");
			sp = resource->AddSprite(L"Main_Monitor_2", L"Asset/Sprite/NPC/mainMonitor_text_2.png");
			sp = resource->AddSprite(L"Main_Monitor_3", L"Asset/Sprite/NPC/mainMonitor_text_3.png");
			sp = resource->AddSprite(L"Main_Monitor_4", L"Asset/Sprite/NPC/mainMonitor_text_4.png");
			sp = resource->AddSprite(L"Main_Monitor_5", L"Asset/Sprite/NPC/mainMonitor_text_5.png");

			sp = resource->AddSprite(L"NPC1", L"Asset/Sprite/NPC/boy-L.bmp");
			sp = resource->AddSprite(L"NPC2", L"Asset/Sprite/NPC/boy-R.bmp");
			sp = resource->AddSprite(L"NPC3", L"Asset/Sprite/NPC/moniter.bmp");
			sp = resource->AddSprite(L"NPC4", L"Asset/Sprite/NPC/paper.bmp");
			sp = resource->AddSprite(L"NPC5", L"Asset/Sprite/NPC/robot.bmp");
		}
		{
			// UI 관련
			sp = resource->AddSprite(L"LifeBar_0", L"Asset/Sprite/UI/Life_00.bmp");
			sp = resource->AddSprite(L"LifeBar_1", L"Asset/Sprite/UI/Life_01.bmp");
			sp = resource->AddSprite(L"LifeBar_2", L"Asset/Sprite/UI/Life_02.bmp");
			sp = resource->AddSprite(L"LifeBar_3", L"Asset/Sprite/UI/Life_03.bmp");
			sp = resource->AddSprite(L"LifeBar_4", L"Asset/Sprite/UI/Life_04.bmp");
			sp = resource->AddSprite(L"LifeBar_5", L"Asset/Sprite/UI/Life_05.bmp");
			sp = resource->AddSprite(L"LifeBar_6", L"Asset/Sprite/UI/Life_06.bmp");
			sp = resource->AddSprite(L"LifeBar_7", L"Asset/Sprite/UI/Life_07.bmp");
			sp = resource->AddSprite(L"LifeBar_8", L"Asset/Sprite/UI/Life_08.bmp");
			sp = resource->AddSprite(L"LifeBar_9", L"Asset/Sprite/UI/Life_09.bmp");
			sp = resource->AddSprite(L"LifeBar_10", L"Asset/Sprite/UI/Life_10.bmp");

			sp = resource->AddSprite(L"Volume_1", L"Asset/Sprite/UI/1.bmp");
			sp = resource->AddSprite(L"Volume_2", L"Asset/Sprite/UI/2.bmp");
			sp = resource->AddSprite(L"Volume_3", L"Asset/Sprite/UI/3.bmp");
			sp = resource->AddSprite(L"Volume_4", L"Asset/Sprite/UI/4.bmp");
			sp = resource->AddSprite(L"Volume_5", L"Asset/Sprite/UI/5.bmp");
			sp = resource->AddSprite(L"Volume_6", L"Asset/Sprite/UI/6.bmp");
			sp = resource->AddSprite(L"Volume_7", L"Asset/Sprite/UI/7.bmp");
			sp = resource->AddSprite(L"Volume_8", L"Asset/Sprite/UI/8.bmp");
			sp = resource->AddSprite(L"Volume_9", L"Asset/Sprite/UI/9.bmp");
			sp = resource->AddSprite(L"Volume_10", L"Asset/Sprite/UI/10.bmp");
			sp = resource->AddSprite(L"PauseBar", L"Asset/Sprite/UI/onlysetting.png");
			sp = resource->AddSprite(L"ChoiceBt_1", L"Asset/Sprite/UI/select_ending_1.png");
			sp = resource->AddSprite(L"ChoiceBt_2", L"Asset/Sprite/UI/select_ending_2.png");

			sp = resource->AddSprite(L"Dialog1", L"Asset/Sprite/UI/residental_0-1.png");
			sp = resource->AddSprite(L"Dialog2", L"Asset/Sprite/UI/residental_0-2.png");
			sp = resource->AddSprite(L"Dialog3", L"Asset/Sprite/UI/residental_0-3.png");
			sp = resource->AddSprite(L"Dialog4", L"Asset/Sprite/UI/residental_1-1.png");
			sp = resource->AddSprite(L"Dialog5", L"Asset/Sprite/UI/residental_1-2.png");
			sp = resource->AddSprite(L"Dialog6", L"Asset/Sprite/UI/residental_3-1.png");
			sp = resource->AddSprite(L"Dialog7", L"Asset/Sprite/UI/residental_3-2.png");
			sp = resource->AddSprite(L"Dialog8", L"Asset/Sprite/UI/residental_3-3.png");
			sp = resource->AddSprite(L"Dialog9", L"Asset/Sprite/UI/residental_4-1.png");
			sp = resource->AddSprite(L"Dialog10", L"Asset/Sprite/UI/residental_5-1.png");
			


			sp = resource->AddSprite(L"zoozack", L"Asset/Sprite/UI/asd.bmp");

		}
		{
			sp = resource->AddSprite(L"GameStart_0", L"Asset/Sprite/UI/gamestart.bmp");
			sp->data.count = { 2,1 };
			std::vector<std::pair<int, float>> arr =
			{
				{0, 0.1f},
				{1, 0.1f},
			};
			//sp = resource->AddSprite(L"GameStart_1", L"Asset/Sprite/UI/gamestart_push.bmp");
		}
		{
			sp = resource->AddSprite(L"GameEnd_0", L"Asset/Sprite/UI/gameend.bmp");
			sp->data.count = { 2,1 };
			std::vector<std::pair<int, float>> arr =
			{
				{0, 0.1f},
				{1, 0.1f},
			};
		}
		//sp = resource->AddSprite(L"GameEnd_1", L"Asset/Sprite/UI/gameend_push.bmp");
		sp = resource->AddSprite(L"Logo_1", L"Asset/Sprite/UI/logo_1.bmp");
		sp = resource->AddSprite(L"Logo_2", L"Asset/Sprite/UI/logo_2.bmp");
		sp = resource->AddSprite(L"TitleIllustrator", L"Asset/Sprite/UI/TitleIllustrator.png");

		sp = resource->AddSprite(L"GrayRect", L"Asset/Sprite/UI/GrayRect.bmp");
		{
			sp = resource->AddSprite(L"main_0", L"Asset/Sprite/UI/main.bmp");
			sp->data.count = { 2,1 };
			std::vector<std::pair<int, float>> arr =
			{
				{0, 0.1f},
				{1, 0.1f},
			};
		}
		//sp = resource->AddSprite(L"main_1", L"Asset/Sprite/UI/main_push.bmp");

		sp = resource->AddSprite(L"UI_Dash", L"Asset/Sprite/UI/Dash.bmp");
		sp->data.count = { 2,1 };
		sp = resource->AddSprite(L"UI_Left", L"Asset/Sprite/UI/left.bmp");
		sp->data.count = { 2,1 };
		sp = resource->AddSprite(L"UI_Right", L"Asset/Sprite/UI/right.bmp");
		sp->data.count = { 2,1 };
		sp = resource->AddSprite(L"UI_Down", L"Asset/Sprite/UI/down.bmp");
		sp->data.count = { 2,1 };
		sp = resource->AddSprite(L"UI_Up", L"Asset/Sprite/UI/up.bmp");
		sp->data.count = { 2,1 };
		sp = resource->AddSprite(L"UI_Z", L"Asset/Sprite/UI/Z.bmp");
		sp->data.count = { 2,1 };
		sp = resource->AddSprite(L"UI_X", L"Asset/Sprite/UI/X.bmp");
		sp->data.count = { 2,1 };
		sp = resource->AddSprite(L"UI_Shift", L"Asset/Sprite/UI/Shift.bmp");
		sp->data.count = { 2,1 };
		sp = resource->AddSprite(L"UI_Space", L"Asset/Sprite/UI/Space.bmp");
		sp->data.count = { 1,2 };
		sp = resource->AddSprite(L"UI_Skip", L"Asset/Sprite/UI/skip.bmp");

		{
			// 맵 관련

			//Tile
			sp = resource->AddSprite(L"Tile_0", L"Asset/Sprite/Map/0.bmp");
			sp = resource->AddSprite(L"Tile_1", L"Asset/Sprite/Map/1.bmp");
			sp = resource->AddSprite(L"Tile_2", L"Asset/Sprite/Map/2.bmp");
			sp = resource->AddSprite(L"Tile_3", L"Asset/Sprite/Map/3.bmp");
			sp = resource->AddSprite(L"Tile_4", L"Asset/Sprite/Map/4.bmp");
			sp = resource->AddSprite(L"Tile_5", L"Asset/Sprite/Map/5.bmp");
			sp = resource->AddSprite(L"Tile_6", L"Asset/Sprite/Map/6.bmp");
			sp = resource->AddSprite(L"Tile_7", L"Asset/Sprite/Map/7.bmp");
			sp = resource->AddSprite(L"Tile_8", L"Asset/Sprite/Map/8.bmp");
			sp = resource->AddSprite(L"Tile_9", L"Asset/Sprite/Map/9.bmp");
			sp = resource->AddSprite(L"Tile_10", L"Asset/Sprite/Map/10.bmp");
			sp = resource->AddSprite(L"Tile_11", L"Asset/Sprite/Map/11.bmp");
			sp = resource->AddSprite(L"Tile_12", L"Asset/Sprite/Map/12.bmp");
			sp = resource->AddSprite(L"Tile_13", L"Asset/Sprite/Map/13.bmp");
			sp = resource->AddSprite(L"Tile_14", L"Asset/Sprite/Map/14.bmp");
			sp = resource->AddSprite(L"Tile_15", L"Asset/Sprite/Map/15.bmp");
			sp = resource->AddSprite(L"Tile_16", L"Asset/Sprite/Map/16.bmp");
			sp = resource->AddSprite(L"Tile_17", L"Asset/Sprite/Map/17.bmp");
			sp = resource->AddSprite(L"Fan", L"Asset/Sprite/Map/fan_ani.bmp"); sp->data.count = { 3,1 };
			std::vector<std::pair<int, float>> arr = { {0, 0.1f}, {1, 0.1f}, {2, 0.1f} };
			resource->AddAnimation(L"Fan_Ani", sp, arr);

			sp = resource->AddSprite(L"Wind", L"Asset/Sprite/Map/wind_ani.bmp"); sp->data.count = { 6,1 };
			arr = { {0, 0.1f}, {1, 0.1f}, {2, 0.1f}, {3, 0.1f}, {4, 0.1f}, {5, 0.1f} };
			resource->AddAnimation(L"Wind_Ani", sp, arr);
			//Rope
			sp = resource->AddSprite(L"Rope1", L"Asset/Sprite/Map/Light1.bmp");
			sp = resource->AddSprite(L"Rope2", L"Asset/Sprite/Map/Light2.bmp");
			sp = resource->AddSprite(L"Rope3", L"Asset/Sprite/Map/Light3.bmp");
			sp = resource->AddSprite(L"Rope4", L"Asset/Sprite/Map/Light4.bmp");
			sp = resource->AddSprite(L"Rope5", L"Asset/Sprite/Map/Light5.bmp");
			//Water
			sp = resource->AddSprite(L"Water1", L"Asset/Sprite/Map/W_1.bmp");
			sp = resource->AddSprite(L"Water2", L"Asset/Sprite/Map/W_2.bmp");
			sp = resource->AddSprite(L"Water3", L"Asset/Sprite/Map/W_3.bmp");
			sp = resource->AddSprite(L"Water4", L"Asset/Sprite/Map/W_4.bmp");
			sp = resource->AddSprite(L"Water5", L"Asset/Sprite/Map/WF_1.bmp");
			sp = resource->AddSprite(L"Water6", L"Asset/Sprite/Map/WF_2.bmp");
			sp = resource->AddSprite(L"Water7", L"Asset/Sprite/Map/WF_3.bmp");
			sp = resource->AddSprite(L"Water8", L"Asset/Sprite/Map/WF_4.bmp");
			//Rain
			sp = resource->AddSprite(L"Rain1", L"Asset/Sprite/Map/rain_1.bmp");
			sp = resource->AddSprite(L"Rain2", L"Asset/Sprite/Map/rain_2.bmp");
			sp = resource->AddSprite(L"Rain3", L"Asset/Sprite/Map/rain_3.bmp");
		}

		//Laser
		{
			sp = resource->AddSprite(L"LaserUp", L"Asset/Sprite/Map/laser3.bmp");
			sp = resource->AddSprite(L"LaserUp1", L"Asset/Sprite/Map/beam_ani2.bmp");
			sp->data.count = { 3,1 };
			std::vector<std::pair<int, float>> arr =
			{
				{0, 0.1f},
				{1, 0.1f},
				{2, 0.1f}
			};
			resource->AddAnimation(L"LaserUpAni", sp, arr);
		}


		{
			sp = resource->AddSprite(L"LaserDown", L"Asset/Sprite/Map/laser4.bmp");
			sp = resource->AddSprite(L"LaserDown1", L"Asset/Sprite/Map/beam_ani.bmp");
			sp->data.count = { 3,1 };
			std::vector<std::pair<int, float>> arr =
			{
				{0, 0.1f},
				{1, 0.1f},
				{2, 0.1f}
			};
			resource->AddAnimation(L"LaserDownAni", sp, arr);
		}

		{
			sp = resource->AddSprite(L"LaserBeam", L"Asset/Sprite/Map/laser1.bmp");
		}

		//=================================================

	   // 우리 유피짱이 움직일 거예요
		{
			// 유휴 상태
			sp = resource->AddSprite(L"Idle_Left", L"Asset/Sprite/Player/idle-left.bmp");
			sp->data.count = { 7,1 };
			std::vector<std::pair<int, float>> arr = {
				  {0, 0.1f}
				, {1, 0.1f}
				, {2, 0.1f}
				, {3, 0.1f}
				, {4, 0.1f}
				, {5, 0.1f}
				, {6, 0.1f}
			};
			resource->AddAnimation(L"Y_Idle_Left", sp, arr);
			sp = resource->AddSprite(L"Idle_Right", L"Asset/Sprite/Player/idle-right.bmp");
			sp->data.count = { 7,1 };
			resource->AddAnimation(L"Y_Idle_Right", sp, arr);
		}
		{
			// 점프 상태
			sp = resource->AddSprite(L"Jump1_Left", L"Asset/Sprite/Player/jump-left.bmp");
			sp->data.count = { 6,1 };
			std::vector<std::pair<int, float>> arr = {
				  {0, 0.15f}
				, {1, 0.15f}
				, {2, 0.15f}
				, {3, 0.15f}
				, {4, 0.1f}
				, {5, 0.1f}
			};
			resource->AddAnimation(L"Y_Jump1_Left", sp, arr);
			sp = resource->AddSprite(L"Jump1_Right", L"Asset/Sprite/Player/jump-right.bmp");
			sp->data.count = { 6,1 };
			resource->AddAnimation(L"Y_Jump1_Right", sp, arr);
		}
		{
			// 달리기
			sp = resource->AddSprite(L"Run_Left", L"Asset/Sprite/Player/run-left.bmp");
			sp->data.count = { 7,1 };
			std::vector<std::pair<int, float>> arr = {
				  {0, 0.1f}
				, {1, 0.1f}
				, {2, 0.1f}
				, {3, 0.1f}
				, {4, 0.1f}
				, {5, 0.1f}
				, {6, 0.1f}
			};
			resource->AddAnimation(L"Y_Run_Left", sp, arr);
			sp = resource->AddSprite(L"Run_Right", L"Asset/Sprite/Player/run-right.bmp");
			sp->data.count = { 7,1 };
			resource->AddAnimation(L"Y_Run_Right", sp, arr);
		}
		{
			// 이단 점프
			sp = resource->AddSprite(L"2Jump_Left", L"Asset/Sprite/Player/2jump-left.bmp");
			sp->data.count = { 4,1 };
			std::vector<std::pair<int, float>> arr = {
				  {0, 0.1f}
				, {1, 0.1f}
				, {2, 0.1f}
				, {3, 0.1f}
			};
			resource->AddAnimation(L"Y_2Jump_Left", sp, arr);
			sp = resource->AddSprite(L"2Jump_Right", L"Asset/Sprite/Player/2jump-right.bmp");
			sp->data.count = { 4,1 };
			resource->AddAnimation(L"Y_2Jump_Right", sp, arr);
		}
		{
			// 우산 펼치기
			sp = resource->AddSprite(L"Open_Left", L"Asset/Sprite/Player/open-left.bmp");
			sp->data.count = { 3,1 };
			std::vector<std::pair<int, float>> arr = {
				  {0, 0.1f}
				, {1, 0.1f}
				, {2, 0.1f}
			};
			resource->AddAnimation(L"Y_Open_Left", sp, arr);
			sp = resource->AddSprite(L"Open_Right", L"Asset/Sprite/Player/open-right.bmp");
			sp->data.count = { 3,1 };
			resource->AddAnimation(L"Y_Open_Right", sp, arr);
		}
		{
			// 우산 접기
			sp = resource->AddSprite(L"Close_Left", L"Asset/Sprite/Player/close-left.bmp");
			sp->data.count = { 3,1 };
			std::vector<std::pair<int, float>> arr = {
				  {0, 0.1f}
				, {1, 0.1f}
				, {2, 0.1f}
			};
			resource->AddAnimation(L"Y_Close_Left", sp, arr);
			sp = resource->AddSprite(L"Close_Right", L"Asset/Sprite/Player/close-right.bmp");
			sp->data.count = { 3,1 };
			resource->AddAnimation(L"Y_Close_Right", sp, arr);
		}
		{
			// 우산 유휴
			sp = resource->AddSprite(L"UmIdle_Left", L"Asset/Sprite/Player/umbrella-idle-left.bmp");
			sp->data.count = { 7,1 };
			std::vector<std::pair<int, float>> arr = {
				  {0, 0.1f}
				, {1, 0.1f}
				, {2, 0.1f}
				, {3, 0.1f}
				, {4, 0.1f}
				, {5, 0.1f}
				, {6, 0.1f}
			};
			resource->AddAnimation(L"Y_UmIdle_Left", sp, arr);
			sp = resource->AddSprite(L"UmIdle_Right", L"Asset/Sprite/Player/umbrella-idle-right.bmp");
			sp->data.count = { 7,1 };
			resource->AddAnimation(L"Y_UmIdle_Right", sp, arr);
		}
		{
			// 우산 달리기 
			sp = resource->AddSprite(L"UmRun_Left", L"Asset/Sprite/Player/run-umblella-left.bmp");
			sp->data.count = { 7,1 };
			std::vector<std::pair<int, float>> arr = {
				  {0, 0.1f}
				, {1, 0.1f}
				, {2, 0.1f}
				, {3, 0.1f}
				, {4, 0.1f}
				, {5, 0.1f}
				, {6, 0.1f}
			};
			resource->AddAnimation(L"Y_UmRun_Left", sp, arr);
			sp = resource->AddSprite(L"UmRun_Right", L"Asset/Sprite/Player/run-umblella-right.bmp");
			sp->data.count = { 7,1 };
			resource->AddAnimation(L"Y_UmRun_Right", sp, arr);
		}
		{
			// 우산 점프
			sp = resource->AddSprite(L"UmJump_Left", L"Asset/Sprite/Player/fly-Sheet-left.bmp");
			sp->data.count = { 4,1 };
			std::vector<std::pair<int, float>> arr = {
				  {0, 0.11f}
				, {1, 0.11f}
				, {2, 0.11f}
				, {3, 0.11f}
			};
			resource->AddAnimation(L"Y_UmJump_Left", sp, arr);
			sp = resource->AddSprite(L"UmJump_Right", L"Asset/Sprite/Player/fly-Sheet-right.bmp");
			sp->data.count = { 4,1 };
			resource->AddAnimation(L"Y_UmJump_Right", sp, arr);
		}
		{
			// 우산 점프 역재생
			sp = resource->AddSprite(L"UmJumpR_Left", L"Asset/Sprite/Player/fly-Sheet-revers-left.bmp");
			sp->data.count = { 4,1 };
			std::vector<std::pair<int, float>> arr = {
				  {0, 0.11f}
				, {1, 0.11f}
				, {2, 0.11f}
				, {3, 0.11f}
			};
			resource->AddAnimation(L"Y_UmJumpR_Left", sp, arr);
			sp = resource->AddSprite(L"UmJumpR_Right", L"Asset/Sprite/Player/fly-Sheet-revers-right.bmp");
			sp->data.count = { 4,1 };
			resource->AddAnimation(L"Y_UmJumpR_Right", sp, arr);
		}
		{
			// 게임 오버
			sp = resource->AddSprite(L"GameOver_Left", L"Asset/Sprite/Player/game-over-left.bmp");
			sp->data.count = { 4,1 };
			std::vector<std::pair<int, float>> arr = {
				  {0, 0.1f}
				, {1, 0.1f}
				, {2, 0.1f}
				, {3, 0.1f}
			};
			resource->AddAnimation(L"Y_GameOver_Left", sp, arr);
			sp = resource->AddSprite(L"GameOver_Right", L"Asset/Sprite/Player/game-over-right.bmp");
			sp->data.count = { 4,1 };
			resource->AddAnimation(L"Y_GameOver_Right", sp, arr);
		}
		{
			// 벽 점프
			sp = resource->AddSprite(L"WallJump", L"Asset/Sprite/Player/wall-jump.bmp");
			sp->data.count = { 4,1 };
			std::vector<std::pair<int, float>> arr = {
				  {0, 0.1f}
				, {1, 0.1f}
				, {2, 0.1f}
				, {3, 0.1f}
			};
			resource->AddAnimation(L"Y_WallJump", sp, arr);
		}
		{
			// 밧줄 올라가기
			sp = resource->AddSprite(L"Climb", L"Asset/Sprite/Player/climb.bmp");
			sp->data.count = { 2,1 };
			std::vector<std::pair<int, float>> arr = {
				  {0, 0.2f}
				, {1, 0.2f}
			};
			resource->AddAnimation(L"Y_Climb", sp, arr);
		}
		{
			sp = resource->AddSprite(L"Hit_Left", L"Asset/Sprite/Player/hit-left.bmp");
			std::vector<std::pair<int, float>> arr = {
				  {0, 1.f}
			};
			resource->AddAnimation(L"Y_Hit_Left", sp, arr);
			sp = resource->AddSprite(L"Hit_Right", L"Asset/Sprite/Player/hit-right.bmp");
			resource->AddAnimation(L"Y_Hit_Right", sp, arr);
		}
		{
			sp = resource->AddSprite(L"UmHit_Left", L"Asset/Sprite/Player/hit-umblella-left.bmp");
			std::vector<std::pair<int, float>> arr = {
				  {0, 1.f}
			};
			resource->AddAnimation(L"Y_UmHit_Left", sp, arr);
			sp = resource->AddSprite(L"UmHit_Right", L"Asset/Sprite/Player/hit-umblella-right.bmp");
			resource->AddAnimation(L"Y_UmHit_Right", sp, arr);
		}
		{
			sp = resource->AddSprite(L"Back", L"Asset/Sprite/Player/back.bmp");
			std::vector<std::pair<int, float>> arr = {
				  {0, 1.f}
			};
			resource->AddAnimation(L"Y_Back", sp, arr);
		}

		// 이펙트 관련
		{
			{
				sp = resource->AddSprite(L"landEffect", L"Asset/Sprite/Effect/land.bmp");
				sp->data.count = { 5,1 };
				std::vector<std::pair<int, float>> arr = {
					  {0, 0.1f}
					, {1, 0.1f}
					, {2, 0.1f}
					, {3, 0.1f}
					, {4, 0.1f}
					, {5, 0.1f}
				};
				resource->AddAnimation(L"Ef_land", sp, arr);
			}

			//점프
			{
				sp = resource->AddSprite(L"jumpEffect", L"Asset/Sprite/Effect/jump.bmp");
				sp->data.count = { 1,1 };
				std::vector<std::pair<int, float>> arr = {
					  {0, 0.1f},
					  {1, 0.1f}
				};
				resource->AddAnimation(L"Ef_jump", sp, arr);
			}

			//대쉬
			{
				sp = resource->AddSprite(L"dashRight", L"Asset/Sprite/Effect/R_R.png");
				sp = resource->AddSprite(L"dashLeft", L"Asset/Sprite/Effect/R_L.png");

			}
		}
	}
	
};