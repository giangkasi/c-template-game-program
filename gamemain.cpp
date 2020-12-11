#include "Map.h"
#include "chracter.h"
#include"scene.h"



int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nCmdShow) {
    ChangeWindowMode(TRUE);
    if (DxLib_Init() == -1)return -1;
    SetDrawScreen(DX_SCREEN_BACK);
    


    
    Map* map = new Map();
    SceneManager* scene = new SceneManager();

    while (true) {
        if (ProcessMessage() != 0) { break; }
        if (ClearDrawScreen() != 0) { break; }


        scene->ChangeScene();
        map->All();
        

    }
    DxLib_End();
    return 0;
}


