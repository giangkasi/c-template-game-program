#include "Map.h"
#include "chracter.h"
#include"scene.h"
enum SCENE {
           TITLE,
            GAME,
            END
        };
struct STRUCT_MUSIC
{
    int Handle;					
    char FilePath[128];			
    int Playtype;				
};	
typedef STRUCT_MUSIC MUSIC;
BOOL MY_KEY_DOWN(int);
VOID MY_START(VOID);
VOID MY_START_PROC(VOID);
VOID MY_START_DRAW(VOID);

VOID MY_PLAY(VOID);
VOID MY_PLAY_PROC(VOID);
VOID MY_PLAY_DRAW(VOID);

VOID MY_END(VOID);
VOID MY_END_PROC(VOID);
VOID MY_END_DRAW(VOID);

VOID MY_ALL_KEYDOWN_UPDATE(VOID);
BOOL MY_CHECK_RECT_COLL(RECT, RECT);
BOOL MY_MUSIC_LOAD(MUSIC*, const char*);

#define GAME_MUSIC_TITLE				"MUSIC\\title.mp3"
#define GAME_MUSIC_PLAY					"MUSIC\\play.mp3"
#define GAME_MUSIC_END					"MUSIC\\end.mp3"

int GameScene;
int AllKeyState[256] = { '\0' };
char OldAllKeyState[256] = { '\0' };



MUSIC MUSIC_MY_BGM_PLAY;
MUSIC MUSIC_MY_BGM_TITLE;
MUSIC MUSIC_MY_BGM_END;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow) {
    ChangeWindowMode(TRUE);
    if (DxLib_Init() == -1)return -1;
    SetDrawScreen(DX_SCREEN_BACK);
    
    MY_MUSIC_LOAD(&MUSIC_MY_BGM_PLAY, GAME_MUSIC_PLAY);
    MY_MUSIC_LOAD(&MUSIC_MY_BGM_TITLE, GAME_MUSIC_TITLE);
    MY_MUSIC_LOAD(&MUSIC_MY_BGM_END, GAME_MUSIC_END);

    character* pl = new character();
    Map* map = new Map();
    SceneManager* scene = new SceneManager();

    while (true) {
        if (ProcessMessage() != 0) { break; }
        if (ClearDrawScreen() != 0) { break; }



        map->All();
        pl->Compos();

    }
    DxLib_End();
    return 0;
}


