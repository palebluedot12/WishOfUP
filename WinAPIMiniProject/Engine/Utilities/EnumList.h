// 씬 레이어
enum class Layer
{
    Default,
    BackGround,
    Tile,
    Object,
    Monster,
    Player,
    Particle,
    UI,
    Size,
};

// 오브젝트 태그
enum class ObjectTag
{
    Default,
    Player,
    Object,
    NPC,
    Rope,
    Walljump,
    Wind,
    Trap,
    Dialog,
    Ground,
    SavePoint,
    ToScene2,
    ToScene3,
    ToScene4,
    ToScene2_Reverse,
    MONITOR_SMALL1,
    MONITOR_SMALL2,
    MONITOR_SMALL3,
    MONITOR_SMALL4,
    MONITOR_SMALL5,
    MONITOR_SMALL6,
    MONITOR_CutScene,
    MONITOR_BIG,
    GoEnding,
    Rain,
    UI,
    UnderDialog1,
    UnderDialog2,
    UnderDialog3,
    Robot,
    Jump_Tutorial,
    WallJump_Tutorial_Left,
    WallJump_Tutorial_Right,
    Dash_Tutorial,
    Umbrella_Tutorial,
    Size,
};

// 씬 태그
enum class SceneTag
{
    Load,
    Title,
    CutScene,
    Play,
    //등등
    Size,
};

// 리소스 타입
enum class ResourceType
{
    Sprite,
    Animation,
    Font,
    TileMap,
    Prefab,
    Sound,
    Size,
};

// 리소스 확장자
enum class ExtType
{
    Bmp,
    Png,
    Ttf,
    Wav,
    Mp3,
    Csv,
    None,
};

// 스크립트는 따로 다른 배열에 관리할 것이라 일부러 Size아래에 놓았습니다.
enum class ComponentType
{
    Spriterenderer,
    TextRenderer,
    Transform,
    Animator,
    RigidBody,
    RectCollider,
    CircleCollider,
    Camera,
    Size,
    Script,
};

enum class Event_Theme
{
    Default,
    Fade,
};
enum class Event_List
{
    None,
    GameStart,
    GameEnd,
    VolumeUp,
    VolumeDown,
    Respawn,
    CutSceneNext,
    EndingSceneNext1,
    EndingSceneNext2,
    GoMain,
    GoStage_1,
    GoStage_2,
    GoStage_3,
    GoStage_4,
    GoEnding_1,
    GoEnding_2_Before,
    GoEnding_2,
    InGame
};
enum class Event_Type
{
    Default,
    SceneChange,
};


enum class KeyType // 키보드
{
    UP = VK_UP,
    DOWN = VK_DOWN,
    LEFT = VK_LEFT,
    RIGHT = VK_RIGHT,
    SPACEBAR = VK_SPACE,
};

enum class MouseType // 마우스
{
    LEFT = VK_LBUTTON,
    ROLL = VK_MBUTTON,
    RIGHT = VK_RBUTTON,
};

enum class SoundChannel
{
    BackGround,
    PlayerEffect,
    PlayerDash,
    PlayerVoice1,
    PlayerVoice2,
    PlayerVoice3,
    Trap,
    Effect,
    Size,
};

enum class SoundList
{
    None,
    IntroBGM,
    MainBGM,
    Ending1BGM,
    Ending2BGM,
    BackGround_1,
    BackGround_2,
    BackGround_3,
    BackGround_4,
    GameOver,
    GameOverBtn,
    CloseUmbrella,
    OpenUmbrella,
    Dash,
    Land,
    Jump,
    DoubleJump,
    WallJump,
    Hit,
    Move,
    Wind,
    Size,
};

enum class TileType
{
    Default = -1,
    Underfloor,
    Tile1,
    Tile2,
    Tile3,
    Tile4,
    Tile5,
    Tile6,
    Tile7,
    Tile8,
    Tile9,
    Tile10,
    Tile11,
    Tile12,
    Tile13,
    Tile14,
    Tile15,
    Tile16,
    Tile17,
    WindAnim = 29,
    Wind = 30,
    Rope1 = 31,
    Rope2,
    Rope3,
    Rope4,
    Rope5,
    Laserup = 36,
    Laserdown = 37,
    Laserbeam = 38,
    LaserbeamUp = 39,
    LaserbeamDown = 40,
    Water1 =41,
    Water2,
    Water3,
    Water4,
    Water5,
    Water6,
    Water7,
    Water8,
    Rain,
    Robot = 60,
    Size
};
// 현재 상호작용이 가능한 상태 유형을 나타냅니다.
enum class InterType
{
    None = 0,                   // 상호작용 가능한 개체가 없음
    NPC = 1,                   // NPC(대화)와 상호작용 가능
    Rope = 2,                   // 밧줄과 상호작용 가능 
    Wind = 3,
    ToScene2 = 4,
    ToScene3 = 5,
    ToScene4 = 6,
    Dialog = 7,
    SavePoint = 8,
    MONITOR_SMALL1 = 9,
    MONITOR_SMALL2 = 10,
    MONITOR_SMALL3 = 11,
    MONITOR_SMALL4 = 12,
    MONITOR_SMALL5 = 13,
    MONITOR_SMALL6 = 14,
    MONITOR_CutScene = 15,
    MONITOR_BIG = 16,
    ToScene2_Reverse = 17,
    Jump_Tutorial,
    WallJump_Tutorial_Left,
    WallJump_Tutorial_Right,
    Dash_Tutorial,
    Dialog2 = 22,
    Dialog3 = 23,
    Umbrella_Tutorial
};