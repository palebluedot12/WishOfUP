#pragma once

class Y_DashEffectScript;
class Y_BtScript;

class Y_PlayerScript : public Script
{
private:

    // 캐릭터의 상태를 저장하기 위한 enum class입니다.
    // 점프 상태를 나타냅니다.
    enum class JumpType
    {
        None         = 0,                   // 땅에 닿은 상태
        JumpingUp    = 1,                   // 올라가는 점프
        JumpingDown  = 2,                   // 내려가는 점프
        Landing      = 3,                   // 착지 중
    };
    

    // 캐릭터의 컴포넌트를 저장하기 위한 변수입니당
    Transform*       tr;                    // 트랜스폼 컴포넌트
    Animator*        an;                    // 애니메이터 컴포넌트
    RectCollider*    co;                    // 렉트콜라이더 컴포넌트
    Camera*          ca;                    // 카메라 컴포넌트

    float Timer = 0.f;

    // 캐릭터의 기본적인 스탯들 등등입니다
    float godTime = 2.f;                    // 무적 시간
    float godTimer = 0.f;                   // 무적 타이머
    float moveSpeed = 300.f;                // 이동속도
    float gravity = 0.f;                    // 현재 적용되고 있는 중력
    float gravityScale = 800.f;             // 중력 크기
    float gravityMax = 400.f;               // 최대 중력
    float jumpForce = 400.0f;               // 점프력
    int   maxJump = 2;                      // 최대 점프 횟수
    int   jumpCount = 1;                    // 점프카운트
    int   life = 3;                         // 캐릭터 기본 목숨 (씬당 3개)


    float hitNuckBack = 400.f;              // 피격 시 넉백 거리
    float hitMove = 0.f;                    // 넉백으로 이동중인 거리
    float hitBrake = 800.f;                 // 넉백 정지력(?)
    float hitFlashTick = 0.2f;              // 피격 시 깜빡이는 간격
    float hitFlashTimer = 0.f;              // 피격 시 깜빡이는 간격 타이머 
    bool  hitalpha = false;                 // 피격 시 깜빡이는 효과를 주기 위한 변수

    float fallCount = 0.f;                  // 낙뎀 계산용 변수

    float umbrellaCoolTime = 2.f;           // 우산 쿨타임
    float umbrellaTimer = umbrellaCoolTime; // 우산 타이머

    float wallJumpDuration = 2.f;           // 벽타기 지속시간
    float wallJumpTimer = 0.f;              // 벽타기 타이머

    float dashSpeed = 900.f;                // 대쉬 스피드
    float dashBrake = 2000.f;               // 대쉬 정지력(?)
    float dashMove = 0.f;                   // 대쉬로 이동중인 거리

    float climbSpeed = 200.f;               // 밧줄 올라가는 속도

    float DeadZoom = 10.f;                  // 죽었을 때 확대할 줌 배율
    float DeadZoomTemp_1 = 1.f; 
    float DeadZoomTemp_2 = 1.f; 
    float DeadZoomTemp_3 = 1.f; 

    // 상태 처리용 변수들입니다
    int   moveDir = 0;                      // x축 이동 방향 (1이 오른쪽)
    std::wstring viewDir = L"Right";        // 보고있는 방향
    int   isWall = 0;                       // 벽에 부딪힌 방향 
    int   isWallJump = 0;                   // 0 = 벽점프 아님, 1 = 벽잡고 있음, 2 = 벽점프 했음, 3 = 벽잡다 시간 지나서 떨어짐
    int   isHit = 0;                        // 0 = 피격 안함, 1 = 피격 공중에 뜸, 2 = 피격 후 바닥에 착지
    int   isDead = 0;                       // 0 = 안죽음, 1 = 죽고 튕기는중, 2 = 죽고 땅에 내려앉음..
    bool  isDash = false;                   // 대쉬중인가
    bool  isUmbrella = false;               // 우산을 쓰고 있는가
    bool  isClimb = false;                  // 밧줄을 타고 있는가
    bool  isWind = false;
    JumpType JumpState = JumpType::None;    // 점프 상태를 나타냄

    // UI 관련 (자식 오브젝트)
    GameObject* UI_Inter_Npc = nullptr;
    GameObject* UI_Inter_Rope = nullptr;
    GameObject* UI_Inter_Dialog = nullptr;
    GameObject* UI_Inter_Dialog2 = nullptr;
    GameObject* UI_Inter_Dialog3 = nullptr;
    GameObject* UI_Inter_Jump = nullptr;
    GameObject* UI_Inter_Umbrella = nullptr;
    GameObject* UI_Inter_WallJump_Left = nullptr;
    GameObject* UI_Inter_WallJump_Right = nullptr;
    GameObject* UI_Inter_Dash = nullptr;
    Spriterenderer* Dial_sp;

    // 상호작용 대상 오브젝트
    GameObject*    InterTarget = nullptr;
    Transform*     InterTransform = nullptr;
    RectCollider*  InterCollider = nullptr;

    // 이펙트 관련
    vector<GameObject*> _effectlist;
    float dashEffectTimer = 0.f;
    float dashEffectdelete = 0.f;

    // 치트모드 ㄷㄷ.....
    bool FakerMode = false;

    // 컷씬 엔딩용
    float elapsedTime = 0.f;
    bool ismon1made = false;
    bool ismon2made = false;
    bool ismon3made = false;
    bool ismon4made = false;
    bool ismon5made = false;
    bool ismon6made = false;
    bool ismainmonmade = false;
    bool ismainmonfirstmade = false;
    bool isbtnmade = false;
    int  cutSceneIndex = 0;

    // 하층구역 -> 거주지역 대화창
    bool isDialogWindow1 = false;
    bool isDialogWindow2 = false;
    bool isDialogWindow3 = false;

public:

    bool  isPlayerMovementEnabled = true;

    struct SaveData
    {
        GameScene* saveScene = nullptr;
        Vector2 spawnPos = { 0,0 };
    };
    
    InterType InterState = InterType::None; // 상호작용 상태입니다.
    int   maxHp = 10;                       // 최대 체력
    int   hp = maxHp;                       // 현재 체력
    float dashCoolTime = 2.f;               // 대쉬 쿨타임
    float dashTimer = dashCoolTime;         // 대쉬 타이머

    SaveData saveList[5];

    void Start()
    {
        // 우리 유피 모션들
        {
            // Animator 컴포넌트를 얻어옵니다.
            an = gameobject->AddComponent<Animator>();
            // 우산 x
            an->AddAnimation(L"LeftIdle_0", resource->Find<Animation>(L"Y_Idle_Left"));
            an->AddAnimation(L"RightIdle_0", resource->Find<Animation>(L"Y_Idle_Right"));
            an->AddAnimation(L"LeftRun_0", resource->Find<Animation>(L"Y_Run_Left"));
            an->AddAnimation(L"RightRun_0", resource->Find<Animation>(L"Y_Run_Right"));
            an->AddAnimation(L"LeftJump1_0", resource->Find<Animation>(L"Y_Jump1_Left"));
            an->AddAnimation(L"RightJump1_0", resource->Find<Animation>(L"Y_Jump1_Right"));
            an->AddAnimation(L"LeftJump2_0", resource->Find<Animation>(L"Y_2Jump_Left"));
            an->AddAnimation(L"RightJump2_0", resource->Find<Animation>(L"Y_2Jump_Right"));
            an->AddAnimation(L"LeftHit_0", resource->Find<Animation>(L"Y_Hit_Left"));
            an->AddAnimation(L"RightHit_0", resource->Find<Animation>(L"Y_Hit_Right"));
            // 우산 o
            an->AddAnimation(L"LeftIdle_1", resource->Find<Animation>(L"Y_UmIdle_Left"));
            an->AddAnimation(L"RightIdle_1", resource->Find<Animation>(L"Y_UmIdle_Right"));
            an->AddAnimation(L"LeftRun_1", resource->Find<Animation>(L"Y_UmRun_Left"));
            an->AddAnimation(L"RightRun_1", resource->Find<Animation>(L"Y_UmRun_Right"));
            an->AddAnimation(L"LeftJump1_1", resource->Find<Animation>(L"Y_UmJump_Left"));
            an->AddAnimation(L"RightJump1_1", resource->Find<Animation>(L"Y_UmJump_Right"));
            an->AddAnimation(L"LeftJump2_1", resource->Find<Animation>(L"Y_UmJumpR_Left"));
            an->AddAnimation(L"RightJump2_1", resource->Find<Animation>(L"Y_UmJumpR_Right"));
            an->AddAnimation(L"LeftHit_1", resource->Find<Animation>(L"Y_UmHit_Left"));
            an->AddAnimation(L"RightHit_1", resource->Find<Animation>(L"Y_UmHit_Right"));
            // 우산 피고 접기
            an->AddAnimation(L"LeftOpen", resource->Find<Animation>(L"Y_Open_Left"));
            an->AddAnimation(L"RightOpen", resource->Find<Animation>(L"Y_Open_Right"));
            an->AddAnimation(L"LeftClose", resource->Find<Animation>(L"Y_Close_Left"));
            an->AddAnimation(L"RightClose", resource->Find<Animation>(L"Y_Close_Right"));
            // 기타
            an->AddAnimation(L"Climb", resource->Find<Animation>(L"Y_Climb"));
            an->AddAnimation(L"WallJump", resource->Find<Animation>(L"Y_WallJump"));
            an->AddAnimation(L"LeftGameOver", resource->Find<Animation>(L"Y_GameOver_Left"));
            an->AddAnimation(L"RightGameOver", resource->Find<Animation>(L"Y_GameOver_Right"));
            an->AddAnimation(L"Back", resource->Find<Animation>(L"Y_Back"));
        }

        // Transform 컴포넌트를 얻어옵니다.
        tr = gameobject->GetComponent<Transform>();
        tr->position = Vector2(400, 1800);
        tr->scale = Vector2(128, 128);

        // RectCollider 컴포넌트를 얻어옵니다.
        co = gameobject->AddComponent<RectCollider>();
        co->size = { 60, 80 };
        co->offset = { 34, 47 };

        // Camera 컴포넌트를 등록하고 메인카메라로 설정해줍니다.
        ca = gameobject->AddComponent<Camera>();
        RenderManager::Get()->SetCamera(ca);

        // 씬이 넘어가도 삭제 안되게 해줍니다.
        DontDestroyOnLoad(gameobject);

        // UI관련 자식 오브젝트 생성
        {
            Transform* c_tr;
            
            UI_Inter_Npc = gameobject->CreateChild("UI_Inter_Npc", ResourceManager::Get()->Find<Sprite>(L"UI_X"));
            UI_Inter_Npc->SetActive(false);
            c_tr = UI_Inter_Npc->GetComponent<Transform>();
            c_tr->scale = { 55,55 };
            c_tr->position = { tr->scale.x / 2 - c_tr->scale.x / 2, -30 };

            UI_Inter_Rope = gameobject->CreateChild("UI_Inter_Rope", ResourceManager::Get()->Find<Sprite>(L"UI_Up"));
            UI_Inter_Rope->SetActive(false);
            c_tr = UI_Inter_Rope->GetComponent<Transform>();
            c_tr->scale = { 55,55 };
            c_tr->position = { tr->scale.x / 2 - c_tr->scale.x  / 2, -30 };

            UI_Inter_WallJump_Left = gameobject->CreateChild("UI_Wall_Jump_Left", ResourceManager::Get()->Find<Sprite>(L"UI_Left"));
            UI_Inter_WallJump_Left->SetActive(false);
            c_tr = UI_Inter_WallJump_Left->GetComponent<Transform>();
            c_tr->scale = { 55,55 };
            c_tr->position = { tr->scale.x / 2 - c_tr->scale.x / 2, -30 };

            UI_Inter_WallJump_Right = gameobject->CreateChild("UI_Wall_Jump_Right", ResourceManager::Get()->Find<Sprite>(L"UI_Right"));
            UI_Inter_WallJump_Right->SetActive(false);
            c_tr = UI_Inter_WallJump_Right->GetComponent<Transform>();
            c_tr->scale = { 55,55 };
            c_tr->position = { tr->scale.x / 2 - c_tr->scale.x / 2, -30 };

            UI_Inter_Umbrella = gameobject->CreateChild("UI_Jump", ResourceManager::Get()->Find<Sprite>(L"UI_Z"));
            UI_Inter_Umbrella->SetActive(false);
            Dial_sp = UI_Inter_Umbrella->GetComponent<Spriterenderer>();
            c_tr = UI_Inter_Umbrella->GetComponent<Transform>();
            c_tr->scale = { 55, 55 };
            c_tr->position = { tr->scale.x / 2 - c_tr->scale.x / 2, -30 };

            UI_Inter_Dialog = gameobject->CreateChild("UI_Dial", ResourceManager::Get()->Find<Sprite>(L"Dialog1"));
            UI_Inter_Dialog->SetActive(false);
            Dial_sp = UI_Inter_Dialog->GetComponent<Spriterenderer>();
            c_tr = UI_Inter_Dialog->GetComponent<Transform>();
            c_tr->position = { 75, -75 };
            
            UI_Inter_Dialog2 = gameobject->CreateChild("UI_Dial", ResourceManager::Get()->Find<Sprite>(L"Dialog2"));
            UI_Inter_Dialog2->SetActive(false);
            Dial_sp = UI_Inter_Dialog2->GetComponent<Spriterenderer>();
            c_tr = UI_Inter_Dialog2->GetComponent<Transform>();
            c_tr->position = { 75, -75 };

            UI_Inter_Dialog3 = gameobject->CreateChild("UI_Dial", ResourceManager::Get()->Find<Sprite>(L"Dialog3"));
            UI_Inter_Dialog3->SetActive(false);
            Dial_sp = UI_Inter_Dialog3->GetComponent<Spriterenderer>();
            c_tr = UI_Inter_Dialog3->GetComponent<Transform>();
            c_tr->position = { 75, -75 };

            UI_Inter_Jump = gameobject->CreateChild("UI_Jump", ResourceManager::Get()->Find<Sprite>(L"UI_Space"));
            UI_Inter_Jump->SetActive(false);
            Dial_sp = UI_Inter_Jump->GetComponent<Spriterenderer>();
            c_tr = UI_Inter_Jump->GetComponent<Transform>();
            c_tr->position = { 0, -30 };
            c_tr->scale = { 140, 55 };


        }
    }

    void Update()
    {
        if (key->IsDown('T'))
        {
            HitAction(10);
        }
        
        float deltaTime;
        deltaTime = DELTA;

        // 대쉬 이펙트 제거
        for (int i = 0; i < _effectlist.size();)
        {
            Y_DashEffectScript* effect = _effectlist[i]->GetComponent<Y_DashEffectScript>();
            if (effect->tick_Count == 0)
            {
                Destroy(_effectlist[i]);
                _effectlist.erase(_effectlist.begin() + i);
            }
            else ++i;
        }
        {
            // 치트모드
            if (key->IsDown(192))
            {
                FakerMode = (FakerMode == true ? false : true);
            }
            if (FakerMode)
            {
                an->ActiveAnimation(L"WallJump");
                an->Stop();
                if (key->IsHold(37))
                {
                    tr->position.x -= moveSpeed * deltaTime;
                    an->GotoAndStop(1);
                }
                if (key->IsHold(39))
                {
                    tr->position.x += moveSpeed * deltaTime;
                    an->GotoAndStop(3);
                }
                if (key->IsHold(38))
                {
                    tr->position.y -= moveSpeed * deltaTime;
                }
                if (key->IsHold(40))
                {
                    tr->position.y += moveSpeed * deltaTime;
                }
            }
            if (key->IsDown(50))
            {
                RenderManager* Rm = RenderManager::Get();
                Rm->ColliderRender(Rm->GetColliderRender() == true ? false : true);
            }
        }

        if (!FakerMode && isPlayerMovementEnabled)
        {
            // 땅 및 벽 충돌. 함수 위치(맨 위)를 바꾸지 말아주세요 ㅠ 바꾸면 작동이 이상해진답니다 ㅠㅠ.
            GroundCollision();

            if (isDead)
            {
                Time::Get()->SetTimeScale(0.5f);
                if (hitMove > 0.f)
                {
                    tr->position.x += hitMove * (viewDir == L"Right" ? -1 : 1) * deltaTime;
                    hitMove -= hitBrake * deltaTime;
                }
                else if (hitMove <= 0.f)
                {
                    hitMove = 0.f;
                }
                if (gravity == 0.f)
                {
                    an->Play();

                    if (DeadZoomTemp_1 < 3.f && isDead == 1)
                    {
                        DeadZoomTemp_3 += 1;
                        DeadZoomTemp_2 += (DELTA / (int)DeadZoomTemp_3) / 10;
                        DeadZoomTemp_1 += DeadZoomTemp_2;
                        ca->SetZoom(DeadZoomTemp_1);
                    }
                    else if (DeadZoomTemp_1 >= 3.f && isDead == 1)
                    {
                        RenderManager::Get()->FadeInStart();
                        isDead = 2;
                        DeadZoomTemp_1 = 1.f;
                        DeadZoomTemp_2 = 0.1f;
                        DeadZoomTemp_3 = 0.1f;
                    }
                }
            }
            else if (hp > 0)
            {
                // 방향키 이동
                if (JumpState != JumpType::Landing && (isWallJump == 0 || isWallJump == 3) && !isDash && isHit != 1 && !isClimb)
                {
                    if (an->FindAnimation(viewDir + L"Open") != an->GetActiveAnimation() &&
                        an->FindAnimation(viewDir + L"Close") != an->GetActiveAnimation())
                    {
                        // 왼쪽 키
                        if (key->IsHold(37))
                        {
                            moveDir = -1;
                            viewDir = L"Left";
                            if (isWall == 1) tr->position.x += moveDir * moveSpeed * deltaTime;
                            if (JumpState == JumpType::None)
                            {
                                an->ActiveAnimation(L"LeftRun_" + std::to_wstring(isUmbrella), true);
                                SOUND->SoundPlay(SoundList::Move, SoundChannel::PlayerEffect);
                            }
                        }
                        // 오른쪽 키
                        else if (key->IsHold(39))
                        {
                            moveDir = 1;
                            viewDir = L"Right";
                            if (isWall == -1) tr->position.x += moveDir * moveSpeed * deltaTime;
                            if (JumpState == JumpType::None)
                            {
                                an->ActiveAnimation(L"RightRun_" + std::to_wstring(isUmbrella), true);
                                SOUND->SoundPlay(SoundList::Move, SoundChannel::PlayerEffect);
                            }
                        }
                        else
                        {
                            moveDir = 0; // 정면을 바라봄
                            if (JumpState == JumpType::None) an->ActiveAnimation(viewDir + L"Idle_" + std::to_wstring(isUmbrella), true);
                        }
                    }
                    else if (an->FindAnimation(viewDir + L"Open") == an->GetActiveAnimation() ||
                        an->FindAnimation(viewDir + L"Close") == an->GetActiveAnimation())
                    {
                        if (an->IsEnd())
                        {
                            an->ActiveAnimation(viewDir + L"Idle_" + std::to_wstring(isUmbrella), true);
                        }
                    }
                }
                // 최상층에서는 걷기 외에 다른 액션은 불가
                if (SceneManager::Get()->GetActiveScene() != FIND_SCENE(Y_CutScene_UpperArea))
                {
                    // 벽잡기
                    if (isWallJump == 1)
                    {
                        gravity = 0.f;
                        wallJumpTimer += deltaTime;
                        if (wallJumpTimer >= wallJumpDuration)
                        {
                            isWallJump = 3;
                            wallJumpTimer = 0.f;
                        }
                    }
                    // 우산 사용
                    if (key->IsDown(90) && !isClimb)
                    {
                        // 지상에서의 우산 작동
                        if (JumpState == JumpType::None)
                        {
                            if (isUmbrella)
                            {
                                isUmbrella = false;
                                if (!moveDir)
                                {
                                    an->ActiveAnimation(viewDir + L"Close", false);
                                    SOUND->SoundPlay(SoundList::CloseUmbrella, SoundChannel::PlayerEffect);
                                }
                                umbrellaTimer = 0.f;
                            }
                            else if (umbrellaTimer >= umbrellaCoolTime)
                            {
                                isUmbrella = true;
                                if (!moveDir)
                                {
                                    an->ActiveAnimation(viewDir + L"Open", false);
                                    SOUND->SoundPlay(SoundList::OpenUmbrella, SoundChannel::PlayerEffect);
                                }
                            }
                        }
                        // 공중에서의 우산 작동
                        else if (gravity != 0.f)
                        {
                            if (isUmbrella)
                            {
                                isUmbrella = false;
                                an->ActiveAnimation(viewDir + L"Jump1_0", false);
                                SOUND->SoundPlay(SoundList::CloseUmbrella, SoundChannel::PlayerEffect);
                                umbrellaTimer = 0.f;
                            }
                            else if (umbrellaTimer >= umbrellaCoolTime)
                            {
                                isUmbrella = true;
                                isWallJump = false;
                                fallCount = 0.f;
                                an->ActiveAnimation(viewDir + L"Jump1_1", false);
                                SOUND->SoundPlay(SoundList::OpenUmbrella, SoundChannel::PlayerEffect);
                            }
                        }
                    }
                    if (umbrellaTimer < umbrellaCoolTime) umbrellaTimer += deltaTime;

                    if (key->IsDown(32) && !isUmbrella)
                    {
                        // 벽타기 검사부터 시작
                        if (isWallJump == 1)
                        {
                            isWallJump = 2;
                            gravity = -jumpForce * 0.7f;
                            moveDir = (isWall == -1 ? 1 : -1);
                            tr->position.x += moveDir * moveSpeed * deltaTime;
                            an->ActiveAnimation(L"WallJump");
                            an->GotoAndStop((isWall == 1 ? 1 : 3));
                        }
                        // 밧줄 점프
                        else if (!isWallJump && !isDash)
                        {
                            if (isClimb)
                            {
                                an->ActiveAnimation(L"WallJump");
                                SOUND->SoundcutPlay(SoundList::WallJump, SoundChannel::PlayerVoice3);
                                gravity = -jumpForce * 0.5f;
                                jumpCount++;
                                isClimb = false;
                            }
                            // 아니면 그냥 점프
                            else if (jumpCount <= maxJump - 1)
                            {
                                gravity = -jumpForce * (1 - (jumpCount * 0.2f));
                                tr->position.y += gravity * deltaTime;
                                jumpCount++;
                                if (jumpCount == 1)
                                {
                                    an->ActiveAnimation(viewDir + L"Jump1_" + std::to_wstring(isUmbrella), false);
                                    SOUND->SoundcutPlay(SoundList::Jump, SoundChannel::PlayerVoice1);
                                }
                                else if (jumpCount >= maxJump)
                                {
                                    if (isUmbrella)
                                    {
                                        an->ActiveAnimation(viewDir + L"Jump1_1", false);
                                        an->GotoAndPlay(0);
                                    }
                                    else if (!isUmbrella)
                                    {
                                        an->ActiveAnimation(viewDir + L"Jump2_0", false);
                                        SOUND->SoundcutPlay(SoundList::DoubleJump, SoundChannel::PlayerVoice2);
                                        an->GotoAndPlay(2);
                                    }
                                }
                            }
                        }
                    }
                    if (isWallJump == 2)
                    {
                        dashEffectTimer += deltaTime;
                        if (dashEffectTimer >= 0.1f)
                        {
                            dashEffectTimer = 0.f;
                            GameObject* clone = SceneManager::Get()->GetActiveScene()->CreateObject(Layer::Default
                                , ObjectTag::Default
                                , "WallJumpEf"
                                , ResourceManager::Get()->Find<Sprite>(L"WallJump"));
                            clone->GetComponent<Transform>()->position = tr->worldPosition;
                            clone->GetComponent<Transform>()->worldPosition = tr->worldPosition;
                            clone->GetComponent<Spriterenderer>()->index = (moveDir == -1 ? 1 : 3);
                            Y_DashEffectScript* scr = clone->AddComponent<Y_DashEffectScript>();
                            scr->sp->SetColor(1, 1, 1, 1, false);
                            _effectlist.push_back(clone);
                        }
                    }
                    // 대쉬 관련
                    if (dashTimer >= dashCoolTime)
                    {
                        if (key->IsDown(16) && !isUmbrella && !isClimb) // 우산을 썼을 땐 대쉬 불가
                        {
                            if (key->IsHold(37) || key->IsHold(39))
                            {
                                if (key->IsHold(37))
                                {
                                    moveDir = -1;
                                    viewDir = L"Left";
                                    an->ActiveAnimation(L"LeftRun_0");
                                    an->GotoAndStop(3);
                                }
                                if (key->IsHold(39))
                                {
                                    moveDir = 1;
                                    viewDir = L"Right";
                                    an->ActiveAnimation(L"RightRun_0");
                                    an->GotoAndStop(3);
                                }
                                SOUND->SoundPlay(SoundList::Dash, SoundChannel::PlayerDash);
                                godTimer = 0.1f;
                                isDash = true;
                                gravity = 0.f;
                                dashMove = dashSpeed;
                                dashTimer = 0.f;
                                jumpCount = 1;
                                isWallJump = false;
                            }
                        }
                    }
                    else dashTimer += deltaTime;
                    if (isDash)
                    {
                        // 대쉬 이펙트
                        dashEffectTimer += deltaTime;
                        if (dashEffectTimer >= 0.05f)
                        {
                            dashEffectTimer = 0.f;
                            GameObject* clone = SceneManager::Get()->GetActiveScene()->CreateObject(Layer::Default, ObjectTag::Default
                                , "dashEf", ResourceManager::Get()->Find<Sprite>(L"dash" + viewDir));
                            clone->GetComponent<Transform>()->position = tr->worldPosition;
                            clone->GetComponent<Transform>()->worldPosition = tr->worldPosition;
                            Y_DashEffectScript* scr = clone->AddComponent<Y_DashEffectScript>();
                            scr->sp->SetColor(1, 1, 1, 1, false);
                            _effectlist.push_back(clone);
                        }
                        dashMove -= dashBrake * deltaTime;
                        if (dashMove <= 0.f)
                        {
                            isDash = false;
                            godTimer = 0.f;
                            dashEffectTimer = 0.f;
                            an->Play();
                        }
                        tr->position.x += dashMove * moveDir * deltaTime;
                    }
                    // 밧줄 타기
                    if (InterState == InterType::Rope && JumpState != JumpType::Landing)
                    {
                        if (!isUmbrella)
                        {
                            if (key->IsDown(38))
                            {
                                jumpCount = 0;
                                isClimb = true;
                                isWallJump = 0;
                                moveDir = 0;
                                hitMove = 0.f;
                                tr->position.y -= climbSpeed * deltaTime;
                                tr->position.x = InterTransform->worldPosition.x + (InterCollider->size.x / 2) + (InterCollider->offset.x) - (tr->scale.x / 2);
                            }
                            if (isClimb)
                            {
                                gravity = 0.f;
                                if (key->IsHold(38))
                                {
                                    an->ActiveAnimation(L"Climb", false);
                                    an->GotoAndStop((int)(tr->position.y / 30) % 2);
                                    tr->position.y -= climbSpeed * deltaTime;
                                }
                                if (key->IsHold(40))
                                {
                                    an->ActiveAnimation(L"Climb", false);
                                    an->GotoAndStop((int)(tr->position.y / 30) % 2);
                                    tr->position.y += climbSpeed * deltaTime;
                                }
                            }
                        }
                    }
                    else
                    {
                        isClimb = false;
                    }
                    // 피격
                    if (isHit)
                    {
                        godTimer += deltaTime;
                        hitFlashTimer += deltaTime;
                        if (hitFlashTimer >= hitFlashTick)
                        {
                            hitFlashTimer -= hitFlashTick;
                            hitalpha = hitalpha == false ? true : false;
                            an->SetAlpha(0.4f + (hitalpha * 0.3f));
                        }
                        if (godTimer >= godTime)
                        {
                            isHit = 0;
                            an->SetAlpha(1.f);
                            godTimer = 0.f;
                        }
                        if (godTimer <= 0.5f)
                        {
                            tr->position.x += hitMove * (viewDir == L"Right" ? -1 : 1) * deltaTime;
                            hitMove -= hitBrake * deltaTime;
                        }
                        else
                        {
                            isHit = 2;
                            hitMove = 0.f;
                        }
                    }

                    if (!isDash && !isClimb && (isWallJump == 0 || isWallJump == 3))
                    {
                        if (gravity != 0.f)
                        {
                            if (gravity < 0.01f && JumpState != JumpType::JumpingUp)
                                JumpState = JumpType::JumpingUp;
                            else if (gravity > 0.01f && JumpState != JumpType::JumpingDown)
                                JumpState = JumpType::JumpingDown;
                        }
                        else if (gravity == 0.f && JumpState != JumpType::Landing)
                        {
                            JumpState = JumpType::None;
                        }
                    }
                }

                StateToAnimation();

                // 중력 작용
                if (!isDash && isWallJump != 1 && isDead != 2)
                {
                    if (!isClimb)
                    {
                        // 우산 쓸 시에는 중력 덜 받게
                        if (gravity > 0.f)
                        {
                            gravity += gravityScale * deltaTime * (1 - (isUmbrella * 0.7f * (isHit != 1)));
                            if (!isUmbrella)
                                fallCount += gravity * deltaTime;
                        }
                        else
                        {
                            gravity += gravityScale * deltaTime;
                            fallCount = 0.f;
                        }
                        // 최대 중력 넘지 않게
                        if (gravity >= gravityMax * (1 - (isUmbrella * 0.7f * (isHit != 1))))
                            gravity = gravityMax * (1 - (isUmbrella * 0.7f * (isHit != 1)));
                    }
                    if (isWall == 0 && isHit != 1)
                    {
                        tr->position.x += (int)(!isWall) * moveDir * moveSpeed * deltaTime;
                    }

                }
            }
        }
        

        // 씬 넘어가기
        if (InterState == InterType::ToScene2)
        {
            GotoScene2();
        }

        if (InterState == InterType::ToScene3)
        {
            GotoScene3();
        }

        if (InterState == InterType::ToScene4)
        {
            GotoScene4();
        }
    }

    void FixedUpdate()
    {
        // 카메라 줌인/줌아웃 키 입력 처리
        if (key->IsHold(33)) { // F2 키
            ca->ZoomIn(1.01f);
        }

        if (key->IsHold(34)) { // F3 키
            ca->ZoomOut(1.01f);
        }

        InterCheck();

        if (InterState == InterType::NPC && JumpState == JumpType::None)
        {
            UI_Inter_Npc->SetActive(true);
        }
        else if (InterState == InterType::Rope)
        {
            UI_Inter_Rope->SetActive(true);
        }
        else if (InterState == InterType::WallJump_Tutorial_Right)
        {
            UI_Inter_WallJump_Right->SetActive(true);
        }
        else if (InterState == InterType::WallJump_Tutorial_Left)
        {
            UI_Inter_WallJump_Left->SetActive(true);
        }
        else if (InterState == InterType::Jump_Tutorial)
        {
            UI_Inter_Jump->SetActive(true);
        }
        else if (InterState == InterType::Dialog)
        {
            UI_Inter_Dialog->SetActive(true);
        }
        else if (InterState == InterType::Dialog2)
        {
            UI_Inter_Dialog2->SetActive(true);
        }
        else if (InterState == InterType::Dialog3)
        {
            UI_Inter_Dialog3->SetActive(true);
        }
        else if (InterState == InterType::Umbrella_Tutorial)
        {
            UI_Inter_Umbrella->SetActive(true);
        }
        // 바람과 상호작용
        else if (InterState == InterType::Wind)
        {
            isWind = true;
            if (isUmbrella)
            {
                FlyupByWind();
            }
        }
        else if (InterState == InterType::SavePoint)
        {
            
        }
        else
        {
            isWind = false;
            UI_Inter_Npc->SetActive(false);
            UI_Inter_Rope->SetActive(false);
            UI_Inter_Jump->SetActive(false);
            UI_Inter_WallJump_Left->SetActive(false);
            UI_Inter_WallJump_Right->SetActive(false);
            UI_Inter_Umbrella->SetActive(false);
            UI_Inter_Dialog2->SetActive(false);
            UI_Inter_Dialog3->SetActive(false);

        }
        
        if (SceneManager::Get()->GetActiveScene() == FIND_SCENE(Y_CutScene_UpperArea))
        {
            MonitorCheck();
        }

    }

    void StateToAnimation()
    {
        if (hp > 0)
        {
            if (!isDash && !isClimb && isHit != 1)
            {
                if (an->GetActiveAnimation() != an->FindAnimation(L"WallJump"))
                {
                    if (JumpState == JumpType::JumpingUp) // 올라가는 중
                    {
                        if (isUmbrella)
                        {

                        }
                        else if (!isUmbrella)
                        {
                            if (jumpCount <= 1 && an->GetFrame() >= 2)
                                an->Stop();
                            if (jumpCount >= 2 && an->IsEnd())
                                an->GotoAndPlay(1);
                        }
                    }
                    else if (JumpState == JumpType::JumpingDown) // 내려가는 중
                    {
                        if (isUmbrella)
                        {
                            an->ActiveAnimation(viewDir + L"Jump2_1", false);
                            if (an->GetFrame() >= 2)
                                an->Stop();
                        }
                        else if (!isUmbrella)
                        {
                            if (jumpCount <= 1)
                            {
                                an->ActiveAnimation(viewDir + L"Jump1_0", false);
                                an->GotoAndStop(3);
                            }
                            if (jumpCount >= 2)
                            {
                                an->ActiveAnimation(viewDir + L"Jump2_0", false);
                                if (an->GetFrame() == 0) an->GotoAndPlay(1);
                                // 애니메이션 재생이 끝나면
                                if (an->IsEnd())
                                    an->GotoAndPlay(1);
                            }
                        }
                    }
                }
                else if (an->GetActiveAnimation() == an->FindAnimation(L"WallJump"))
                {
                    if (isWallJump == 0)
                    {
                        an->GotoAndStop((moveDir == 1 ? 3 : 1));
                    }
                }
                if (JumpState == JumpType::Landing) // 착지!!
                {
                    if (!isUmbrella)
                    {
                        an->ActiveAnimation(viewDir + L"Jump1_0", false);
                        if (an->GetFrame() <= 3)
                        {
                            an->GotoAndPlay(4);
                            moveDir = 0;
                        }
                        else if (an->IsEnd())
                        {
                            //an->GotoAndPlay(5);
                            JumpState = JumpType::None;
                        }
                    }
                    else
                    {
                        an->ActiveAnimation(viewDir + L"Jump2_1", false);
                        if (an->GetFrame() <= 2)
                        {
                            an->GotoAndPlay(3);
                            moveDir = 0;
                            tr->position += Vector2(moveDir * moveSpeed * DELTA, 0);
                        }
                        else if (an->IsEnd())
                        {
                            JumpState = JumpType::None;
                        }
                    }
                }
            }
        }
        else if (hp <= 0)
        {

        }
    }
    void GroundCollision()
    {
        isWall = 0;
        if (co->isActive)
        {
            std::list<GameObject*> arr = SceneManager::Get()->GetActiveScene()->GetObjectList()[(int)Layer::Tile];
            for (GameObject* obj : SceneManager::Get()->GetActiveScene()->GetObjectList()[(int)Layer::Tile])
            {
                RectCollider* tile_col = obj->GetComponent<RectCollider>();

                if (tile_col == nullptr) continue;

                if (CollisionSystem::Get()->AABB(co, tile_col) && isDead != 2)
                {
                    POINT hitDir = CollisionSystem::Get()->AABB_Dir(co, tile_col);
                    // 캐릭터의 밑이 닿았을 때
                    if (hitDir.y == -1 && (gravity > 0.01f || isClimb)) {
                        if ((JumpState == JumpType::JumpingDown || JumpState == JumpType::JumpingUp))
                        {
                            JumpState = JumpType::Landing;
                            EffectManager::Get()->Landing(tr->scale, tr->position);
                            SOUND->SoundPlay(SoundList::Land, SoundChannel::PlayerEffect);
                        }
                        jumpCount = 0;
                        gravity = 0.f;
                        moveDir = 0;
                        isWallJump = 0;
                        isClimb = false;
                        if (fallCount >= 64 * 4 && !isUmbrella)
                        {
                            HitAction((int)(fallCount / 64) - 3);
                        }
                        tr->position.y = obj->GetComponent<Transform>()->worldPosition.y - co->size.y - co->offset.y + tile_col->offset.y;
                    }
                    if (hitDir.y == 1 && gravity < 0.01f) {
                        gravity *= -1.f;
                        tr->position.y = obj->GetComponent<Transform>()->worldPosition.y
                            + tile_col->size.y - tile_col->offset.y - co->offset.y;
                    }
                    if (hitDir.x != 0 && !isClimb)
                    {
                        isWall = hitDir.x;
                        moveDir = 0.f;
                        /*if (obj->GetTag() == ObjectTag::Walljump){}*/
                        if ((isWallJump == 0 || isWallJump == 2) && !isUmbrella && (gravity != 0.f || isDash) && !isDead)
                        {
                            if ((hitDir.x == 1 && key->IsDown(37)) || (hitDir.x == -1 && key->IsDown(39)))
                            {
                                isWallJump = 1;
                                moveDir = 0;
                                isDash = false;
                                an->ActiveAnimation(L"WallJump");
                                SOUND->SoundcutPlay(SoundList::WallJump, SoundChannel::PlayerVoice3);
                                an->GotoAndStop((isWall == 1 ? 0 : 2));
                                wallJumpTimer = 0.f;
                            }
                        }
                        if (hitDir.x == 1)
                        {
                             tr->position.x = obj->GetComponent<Transform>()->worldPosition.x
                                - co->size.x - co->offset.x;

                        }
                        if (hitDir.x == -1)
                        {
                            tr->position.x = obj->GetComponent<Transform>()->worldPosition.x
                                + obj->GetComponent<RectCollider>()->size.x - co->offset.x;
                        }
                        // 벽점프중 닿으면 이동 중지
                        if (isWallJump == 2)
                        {
                            moveDir = 0;
                        }
                    }
                }
            }
        }
        tr->position.y += gravity * DELTA;
    }
    void InterCheck()
    {
        UI_Inter_Dialog->SetActive(false);
        InterState = InterType::None;
        for (GameObject* obj : SceneManager::Get()->GetActiveScene()->GetObjectList()[(int)Layer::Object])
        {
            RectCollider* obj_col = obj->GetComponent<RectCollider>();
            if (obj_col == nullptr) continue;
            if (CollisionSystem::Get()->AABB(co, obj_col))
            {
                if (InterTarget != obj)
                {
                    InterTarget = obj;
                    InterTransform = obj->GetComponent<Transform>();
                    InterCollider = obj->GetComponent<RectCollider>();
                }
                if (obj->GetTag() == ObjectTag::NPC)
                {
                    InterState = InterType::NPC;
                }
                else if (obj->GetTag() == ObjectTag::Rope)
                {
                    InterState = InterType::Rope;
                }
                else if (obj->GetTag() == ObjectTag::Wind && isHit != 1)
                {
                    InterState = InterType::Wind;
                }
                else if (obj->GetTag() == ObjectTag::ToScene2)
                {
                    InterState = InterType::ToScene2;
                }
                else if (obj->GetTag() == ObjectTag::ToScene3)
                {
                    InterState = InterType::ToScene3;
                }
                else if (obj->GetTag() == ObjectTag::ToScene4)
                {
                    InterState = InterType::ToScene4;
                }
                else if (obj->GetTag() == ObjectTag::ToScene2_Reverse)
                {
                    InterState = InterType::ToScene2_Reverse;
                    GotoScene2_Reverse();
                }
                else if (obj->GetTag() == ObjectTag::SavePoint)
                {
                    InterState = InterType::SavePoint;
                    AddSpawmPoint(obj->GetName());
                }
                else if (obj->GetTag() == ObjectTag::Dialog)
                {
                    InterState = InterType::Dialog;
                }
                else if (obj->GetTag() == ObjectTag::UnderDialog1)
                {
                    InterState = InterType::Dialog;
                    Dial_sp->SetSprite(ResourceManager::Get()->Find<Sprite>(L"Dialog1"));
                }
                else if (obj->GetTag() == ObjectTag::UnderDialog2)
                {
                    InterState = InterType::Dialog2;
                    Dial_sp->SetSprite(ResourceManager::Get()->Find<Sprite>(L"Dialog2"));
                }
                else if (obj->GetTag() == ObjectTag::UnderDialog3)
                {
                    InterState = InterType::Dialog3;
                    Dial_sp->SetSprite(ResourceManager::Get()->Find<Sprite>(L"Dialog3"));
                }
                else if (obj->GetTag() == ObjectTag::Jump_Tutorial)
                {
                    InterState = InterType::Jump_Tutorial;
                    Dial_sp->SetSprite(ResourceManager::Get()->Find<Sprite>(L"UI_Space"));
                }
                else if (obj->GetTag() == ObjectTag::Dash_Tutorial)
                {
                    InterState = InterType::Dash_Tutorial;
                }
                else if (obj->GetTag() == ObjectTag::WallJump_Tutorial_Left)
                {
                    InterState = InterType::WallJump_Tutorial_Left;
                    Dial_sp->SetSprite(ResourceManager::Get()->Find<Sprite>(L"UI_Left"));
                }
                else if (obj->GetTag() == ObjectTag::WallJump_Tutorial_Right)
                {
                    InterState = InterType::WallJump_Tutorial_Right;
                    Dial_sp->SetSprite(ResourceManager::Get()->Find<Sprite>(L"UI_Right"));
                }
                else if (obj->GetTag() == ObjectTag::Umbrella_Tutorial)
                {
                    InterState = InterType::Umbrella_Tutorial;
                    Dial_sp->SetSprite(ResourceManager::Get()->Find<Sprite>(L"UI_Z"));
                }
                else if (obj->GetTag() == ObjectTag::MONITOR_SMALL1)
                {
                    InterState = InterType::MONITOR_SMALL1;

                    if (!ismon1made)
                    {
                        GameScene* _tempScene = SceneManager::Get()->GetActiveScene();
                        GameObject* clone = _tempScene->CreateObject(Layer::Object, ObjectTag::MONITOR_SMALL1, "Monitor1",
                            ResourceManager::Get()->Find<Sprite>(L"Monitor_1"));
                        Transform* temptr = clone->GetComponent<Transform>();
                        Transform* objtr = obj->GetComponent<Transform>();
                        temptr->position = { objtr->position.x - 37.0f, objtr->position.y + 62.0f };
                        ismon1made = true;
                    }
                }
                else if (obj->GetTag() == ObjectTag::MONITOR_SMALL2)
                {
                    InterState = InterType::MONITOR_SMALL2;
                    
                    if (!ismon2made) 
                    {
                        GameScene* _tempScene = SceneManager::Get()->GetActiveScene();
                        GameObject* clone = _tempScene->CreateObject(Layer::Object, ObjectTag::MONITOR_SMALL2, "Monitor2",
                            ResourceManager::Get()->Find<Sprite>(L"Monitor_2"));
                        Transform* temptr = clone->GetComponent<Transform>();
                        Transform* objtr = obj->GetComponent<Transform>();
                        temptr->position = { objtr->position.x - 46.0f, objtr->position.y + 34.0f };
                        ismon2made = true;

                    }

                }
                else if (obj->GetTag() == ObjectTag::MONITOR_SMALL3)
                {
                    InterState = InterType::MONITOR_SMALL3;
                    
                    if (!ismon3made)
                    {
                        GameScene* _tempScene = SceneManager::Get()->GetActiveScene();
                        GameObject* clone = _tempScene->CreateObject(Layer::Object, ObjectTag::MONITOR_SMALL3, "Monitor3",
                            ResourceManager::Get()->Find<Sprite>(L"Monitor_3"));
                        Transform* temptr = clone->GetComponent<Transform>();
                        Transform* objtr = obj->GetComponent<Transform>();
                        temptr->position = { objtr->position.x - 51.0f, objtr->position.y + 43.0f };
                        ismon3made = true;

                    }

                }
                else if (obj->GetTag() == ObjectTag::MONITOR_SMALL4)
                {
                    InterState = InterType::MONITOR_SMALL4;

                    if (!ismon4made) 
                    {
                        GameScene* _tempScene = SceneManager::Get()->GetActiveScene();
                        GameObject* clone = _tempScene->CreateObject(Layer::Object, ObjectTag::MONITOR_SMALL4, "Monitor4",
                            ResourceManager::Get()->Find<Sprite>(L"Monitor_4"));
                        Transform* temptr = clone->GetComponent<Transform>();
                        Transform* objtr = obj->GetComponent<Transform>();
                        temptr->position = { objtr->position.x - 20.0f, objtr->position.y + 43.0f };
                        ismon4made = true;

                    }
                }
                else if (obj->GetTag() == ObjectTag::MONITOR_SMALL5)
                {
                    InterState = InterType::MONITOR_SMALL5;

                    if (!ismon5made)
                    {
                        GameScene* _tempScene = SceneManager::Get()->GetActiveScene();
                        GameObject* clone = _tempScene->CreateObject(Layer::Object, ObjectTag::MONITOR_SMALL5, "Monitor5",
                            ResourceManager::Get()->Find<Sprite>(L"Monitor_5"));
                        Transform* temptr = clone->GetComponent<Transform>();
                        Transform* objtr = obj->GetComponent<Transform>();
                        temptr->position = { objtr->position.x - 45.0f, objtr->position.y - 3.0f };
                        ismon5made = true;
                    }
                }
                else if (obj->GetTag() == ObjectTag::MONITOR_SMALL6)
                {
                    InterState = InterType::MONITOR_SMALL6;

                    if (!ismon6made)
                    {
                        GameScene* _tempScene = SceneManager::Get()->GetActiveScene();
                        GameObject* clone = _tempScene->CreateObject(Layer::Object, ObjectTag::MONITOR_SMALL6, "Monitor6",
                            ResourceManager::Get()->Find<Sprite>(L"Monitor_6"));
                        Transform* temptr = clone->GetComponent<Transform>();
                        Transform* objtr = obj->GetComponent<Transform>();
                        temptr->position = { objtr->position.x - 75.0f, objtr->position.y - 7.0f };
                        ismon6made = true;
                    }
                }
                else if (obj->GetTag() == ObjectTag::MONITOR_CutScene)
                {
                    InterState = InterType::MONITOR_CutScene;
                }
                else if (obj->GetTag() == ObjectTag::MONITOR_BIG)
                {
                    InterState = InterType::MONITOR_BIG;

                    an->ActiveAnimation(L"Back", false);

                    float zoomlev = ca->GetZoomLevel();
                    if (zoomlev <= 1.15f)
                    {
                        ca->ZoomIn(1.003f); // 일정 크기 되면 멈추게
                    }
                    else // 줌 끝나고서 이미지 띄우게
                    {
                        // 메인모니터 텍스트
                        if (!ismainmonmade)
                        {
                            GameScene* _tempScene = SceneManager::Get()->GetActiveScene();

                            if (!ismainmonfirstmade && !isPlayerMovementEnabled)
                            {
                                GameObject* clone = _tempScene->CreateObject(Layer::Object, ObjectTag::MONITOR_BIG, "Main_Monitor_1",
                                    ResourceManager::Get()->Find<Sprite>(L"Main_Monitor_1"));
                                Transform* temptr = clone->GetComponent<Transform>();
                                Transform* objtr = obj->GetComponent<Transform>();
                                temptr->position = { objtr->position.x - 350.0f, objtr->position.y - 40.0f };
                                cutSceneIndex++;
                                ismainmonfirstmade = true;
                            }

                            if (KEY_DOWN('X') && cutSceneIndex == 1)
                            {
                                _tempScene->DestroyObject("Main_Monitor_1");
                                GameObject* clone = _tempScene->CreateObject(Layer::Object, ObjectTag::MONITOR_BIG, "Main_Monitor_2",
                                    ResourceManager::Get()->Find<Sprite>(L"Main_Monitor_2"));
                                Transform* temptr = clone->GetComponent<Transform>();
                                Transform* objtr = obj->GetComponent<Transform>();
                                temptr->position = { objtr->position.x - 350.0f, objtr->position.y - 40.0f };
                                if (KEY_DOWN('X')) cutSceneIndex++;
                              
                            }
                            else if (KEY_DOWN('X') && cutSceneIndex == 2)
                            {
                                _tempScene->DestroyObject("Main_Monitor_2");
                                GameObject* clone = _tempScene->CreateObject(Layer::Object, ObjectTag::MONITOR_BIG, "Main_Monitor_3",
                                    ResourceManager::Get()->Find<Sprite>(L"Main_Monitor_3"));
                                Transform* temptr = clone->GetComponent<Transform>();
                                Transform* objtr = obj->GetComponent<Transform>();
                                temptr->position = { objtr->position.x - 350.0f, objtr->position.y - 40.0f };
                                if (KEY_DOWN('X')) cutSceneIndex++;
                                

                            }
                            else if (KEY_DOWN('X') && cutSceneIndex == 3)
                            {
                                _tempScene->DestroyObject("Main_Monitor_3");
                                GameObject* clone = _tempScene->CreateObject(Layer::Object, ObjectTag::MONITOR_BIG, "Main_Monitor_4",
                                    ResourceManager::Get()->Find<Sprite>(L"Main_Monitor_4"));
                                Transform* temptr = clone->GetComponent<Transform>();
                                Transform* objtr = obj->GetComponent<Transform>();
                                temptr->position = { objtr->position.x - 350.0f, objtr->position.y - 40.0f };
                                if (KEY_DOWN('X')) cutSceneIndex++;
                                

                            }
                            else if (KEY_DOWN('X') && cutSceneIndex == 4)
                            {
                                _tempScene->DestroyObject("Main_Monitor_4");
                                GameObject* clone = _tempScene->CreateObject(Layer::Object, ObjectTag::MONITOR_BIG, "Main_Monitor_5",
                                    ResourceManager::Get()->Find<Sprite>(L"Main_Monitor_5"));
                                Transform* temptr = clone->GetComponent<Transform>();
                                Transform* objtr = obj->GetComponent<Transform>();
                                temptr->position = { objtr->position.x - 350.0f, objtr->position.y - 40.0f };
                                if (KEY_DOWN('X')) cutSceneIndex++;


                                // 왜 씬 안넘어감?
                                if (!isbtnmade)
                                {
                                    GameScene* _tempScene = SceneManager::Get()->GetActiveScene();
                                    GameObject* ChoiceBt1 = _tempScene->CreateObject(Layer::UI, ObjectTag::UI, "ChoiceBt_1"
                                        , ResourceManager::Get()->Find<Sprite>(L"ChoiceBt_1"));
                                    Y_BtScript* bts1 = ChoiceBt1->AddComponent<Y_BtScript>();
                                    bts1->bt_trans->position = { 300, 250 };
                                    //bts->_clickEvent = Event_List::GameStart;
                                    bts1->_clickEvent.theme = Event_Theme::Fade; // 페이드인-아웃을 호출하고 페이드 인이 끝날 때 이벤트를 수행한다. Default는 그냥 바로 수행한다.
                                    bts1->_clickEvent.type = Event_Type::Default; // 씬체인지를 할거야.. 근데 씬말고 다른 이벤트를 수행하고 싶으면 Default를 고른다!
                                    bts1->_clickEvent.event = Event_List::GoEnding_1; // 이건 type이 Default일때만 호출 할 수 있는데, Default를 골랐으면 해당 이벤트를 호출한다!

                                    GameObject* ChoiceBt2 = _tempScene->CreateObject(Layer::UI, ObjectTag::UI, "ChoiceBt_2"
                                        , ResourceManager::Get()->Find<Sprite>(L"ChoiceBt_2"));
                                    Y_BtScript* bts2 = ChoiceBt2->AddComponent<Y_BtScript>();
                                    bts2->bt_trans->position = { 300, 350 };
                                    //bts->_clickEvent = Event_List::GameStart;
                                    bts2->_clickEvent.theme = Event_Theme::Fade;
                                    bts2->_clickEvent.type = Event_Type::Default;
                                    bts2->_clickEvent.event = Event_List::GoEnding_2_Before;

                                    bts2->_clickEvent.objectParam = gameobject;
                                    isbtnmade = true;
                                }  
                            }  
                        }
                    }
                }
                if (obj->GetTag() == ObjectTag::GoEnding)
                {
                    LOAD_SCENE(FIND_SCENE(Y_EndingScene_Choice2));
                }
                if (obj->GetTag() == ObjectTag::Trap && isHit == 0 && !isDash)
                {
                    HitAction(1);
                }
                if (obj->GetTag() == ObjectTag::Rain && isHit == 0 && !isDash && !isUmbrella)
                {
                    HitAction(1);
                }
            }
        }
    }
    void FlyupByWind()
    {
        gravity = -jumpForce * 0.6f;
        JumpState = JumpType::JumpingUp;
        an->ActiveAnimation(viewDir + L"Jump1_1", false);
        SOUND->SoundPlay(SoundList::Wind, SoundChannel::Trap);
    }
    void HitAction(int _dmg)
    {
        if (!isDead)
        {
            if (godTimer == 0.f)
            {
                SOUND->SoundcutPlay(SoundList::Hit, SoundChannel::PlayerEffect);
                hp -= _dmg;
                if (hp <= 0)
                {
                    hp = 0;
                    an->ActiveAnimation(viewDir + L"GameOver", false);
                    an->Stop();
                    gravity = -250.f;
                    hitMove = hitNuckBack * 1.5f;
                    DeadZoomTemp_1 = 1.f;
                    DeadZoomTemp_2 = 0.1f;
                    DeadZoomTemp_3 = 0.1f;
                    isDead = 1;
                }
                else
                {
                    an->ActiveAnimation(viewDir + L"Hit_" + std::to_wstring(isUmbrella));
                    gravity = -150.f;
                    hitMove = hitNuckBack;
                    isHit = 1;
                }
                moveDir = 0.f;
                isDash = false;
                fallCount = 0.f;
            }
        }
    }


    void MonitorCheck()
    {
        if (InterState == InterType::MONITOR_SMALL1)
        {
            
        }
        else if (InterState == InterType::MONITOR_SMALL2)
        {

        }
        else if (InterState == InterType::MONITOR_SMALL3)
        {

        }
        else if (InterState == InterType::MONITOR_SMALL4)
        {

        }
        else if (InterState == InterType::MONITOR_SMALL5)
        {

        }
        else if (InterState == InterType::MONITOR_SMALL6)
        {
        }

        else if (InterState == InterType::MONITOR_CutScene)
        {

            // 이동 불가, 자동 연출
            // 플레이어가 키다운으로 이동 불가
            isPlayerMovementEnabled = false;

            moveDir = 0;

            // 특정 거리만큼 오른쪽으로 자동으로 이동
            float distanceToMove = 5000.0f;
            float moveSpeed = 150.0f;

            float totalMoveTime = distanceToMove / moveSpeed;

            if (elapsedTime < totalMoveTime)
            {
                float deltaTime = DELTA;
                tr->position.x += moveSpeed * deltaTime;
                elapsedTime += deltaTime;
            }
        }

        else if (InterState == InterType::MONITOR_BIG)
        {
            //an->ActiveAnimation(L"Back", false);

            //float zoomlev = ca->GetZoomLevel();
            //if (zoomlev <= 1.15f)
            //{
            //    ca->ZoomIn(1.003f); // 일정 크기 되면 멈추게
            //}
            //else // 줌레벨 1.15 이상 되고나서 이미지 띄우게
            //{

            //}
        }
    }
   
    void Respawn()
    {
        for (int i = 4; i >= 0; i--)
        {
            if (saveList[i].saveScene != nullptr)
            {
                if (saveList[i].saveScene != SceneManager::Get()->GetActiveScene())
                    SceneManager::Get()->LoadScene(saveList[i].saveScene);
                tr->position.x = saveList[i].spawnPos.x;
                tr->position.y = saveList[i].spawnPos.y;
                break;
            }
        }
        isDead = false;
        hp = 10;
    }

    void SpawnReset()
    {
        for (int i = 0; i < 5; i++)
        {
            saveList[i].saveScene = nullptr;
            saveList[i].spawnPos = { 0,0 };
        }
    }

    void AddSpawmPoint(std::string _name)
    {
        if (_name == "Save_0")
        {
            saveList[0].saveScene = FIND_SCENE(Y_UndergroundScene);
            saveList[0].spawnPos = saveList[0].saveScene->SpawnPoint_1;
        }
        else if (_name == "Save_1")
        {
            saveList[1].saveScene = FIND_SCENE(Y_ResidentialAreaScene);
            saveList[1].spawnPos = saveList[1].saveScene->SpawnPoint_1;
        }
        else if (_name == "Save_2")
        {
            saveList[2].saveScene = FIND_SCENE(Y_ResidentialAreaScene);
            saveList[2].spawnPos = saveList[2].saveScene->SpawnPoint_2;
        }
        else if (_name == "Save_3")
        {
            saveList[3].saveScene = FIND_SCENE(Y_UpperAreaScene);
            saveList[3].spawnPos = saveList[3].saveScene->SpawnPoint_1;
        }
        else if (_name == "Save_4")
        {
            saveList[4].saveScene = FIND_SCENE(Y_UpperAreaScene);
            saveList[4].spawnPos = saveList[4].saveScene->SpawnPoint_2;
        }
    }

    void GotoScene2()
    {
        EventData _temp;
        _temp.event = Event_List::GoStage_2;
        _temp.objectParam = gameobject;
        EventManager::Get()->CallEvent(_temp);
    }

    void GotoScene3()
    {
        EventData _temp;
        _temp.event = Event_List::GoStage_3;
        _temp.objectParam = gameobject;
        EventManager::Get()->CallEvent(_temp);
    }

    void GotoScene4()
    {
        EventData _temp;
        _temp.event = Event_List::GoStage_4;
        _temp.objectParam = gameobject;
        EventManager::Get()->CallEvent(_temp);
    }
    void GotoScene2_Reverse()
    {
        LOAD_SCENE(FIND_SCENE(Y_ResidentialAreaScene));
        tr->position = Vector2(20, 100);
    }
    void Reset()
    {
        SpawnReset();
        elapsedTime = 0.f;
        ismon1made = false;
        ismon2made = false;
        ismon3made = false;
        ismon4made = false;
        ismon5made = false;
        ismon6made = false;
        ismainmonmade = false;
        ismainmonfirstmade = false;
        isbtnmade = false;
        cutSceneIndex = 0;
        isPlayerMovementEnabled = true;
        co->isActive = true;
        fallCount = 0.f;
    }
};
