#define _CRT_SECURE_NO_WARNINGS

#include "DxLib.h"



#define GAME_WIDTH	800		
#define GAME_HEIGHT	600		
#define GAME_COLOR	32		

	

#define GAME_MAP_YOKO_SIZE		32	
#define GAME_MAP_TATE_SIZE		32	

#define GAME_MAP_BUN_YOKO_CNT	32	
#define GAME_MAP_BUN_TATE_CNT	41	

#define GAME_MAP_YOKO			40	
#define GAME_MAP_TATE			40	
#define GAME_MAP_OK_KIND		100	
#define GAME_MAP_NG_KIND		100	
#define GAME_MAP_BT_KIND		5	

#define GAME_MAP_1_PATH			"MAPIMAGE\\mapchip1.png"	

#define GAME_MAP_CSV_1_SITA		"MAPIMAGE\\mapchip1_map_sita.csv"	
#define GAME_MAP_CSV_1_NAKA		"MAPIMAGE\\mapchip1_map_naka.csv"	
#define GAME_MAP_CSV_1_UE		"MAPIMAGE\\mapchip1_map_ue.csv"		

#define GAME_MAP_NAME_1_UE		"MAPDATA_1_UE"		
#define GAME_MAP_NAME_1_NAKA	"MAPDATA_1_NAKA"	
#define GAME_MAP_NAME_1_SITA	"MAPDATA_1_SITA"	

#define GAME_CHARA				"CHARAIMAGE\\chara.png"	

	
#define GAME_CHARA_BUN_YOKO_CNT	12		
#define GAME_CHARA_BUN_TATE_CNT	8		
#define GAME_CHARA_YOKO_SIZE	24		
#define GAME_CHARA_TATE_SIZE	32		
#define GAME_CHARA_MOTION_NUM	12		
#define GAME_CHARA_KIND_YOKO	3		
#define GAME_CHARA_KIND_TATE	4		

#define GAME_CHARA_STARTX		10		
#define GAME_CHARA_STARTY		10	
#define GAME_CHARA_SPEED		2		

#define GAME_PLAYER_LV_FIRST	1		
#define GAME_PLAYER_HP_FIRST	15		
#define GAME_PLAYER_ATK_FIRST	5		
#define GAME_PLAYER_DEF_FIRST	5		
#define GAME_PLAYER_EXP_FIRST	5		

#define GAME_PLAYER_HP_LVUP		5		
#define GAME_PLAYER_ATK_LVUP	4		
#define GAME_PLAYER_DEF_LVUP	3		






#define GAME_TITLE_IMAGE				"TITLEIMAGE\\titleimage.png"	
#define GAME_CLEAR_IMAGE				"CLEARIMAGE\\clearimage.png"	


enum GAME_SCENE {
	GAME_SCENE_TITLE,		
	GAME_SCENE_PLAY,	

   GAME_SCENE_END			
};

enum CHARA_IMAGE {
	CHARA_KIND_1 = 0,
	CHARA_KIND_2 = 3,
	CHARA_KIND_3 = 6,
	CHARA_KIND_4 = 9,
	CHARA_KIND_5 = 48,
	CHARA_KIND_6 = 51,
	CHARA_KIND_7 = 54,
	CHARA_KIND_8 = 57,
	CHARA_KIND_END = 95
};	



enum GAME_END_KIND {
	GAME_END_KIND_NONE,		
	GAME_END_KIND_OVER,		
	GAME_END_KIND_CLEAR,	
};


struct STRUCT_IMAGE
{
	char FilePath[128];												
	int Handle[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];		
	int X     [GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];		
	int Y     [GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];		
	int Width [GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];		
	int Height[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];		
	int C_Width[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];		
	int C_Height[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];	

};	

struct STRUCT_MAPDATA
{
	char name[64];											
	int data[GAME_MAP_TATE][GAME_MAP_YOKO];					
	int mapdata_Init[GAME_MAP_TATE][GAME_MAP_YOKO];			

	int Handle[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];	
	int X[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];		
	int Y[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];		
	int Width[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];	
	int Height[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];	
	int C_Width[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];	
	int C_Height[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];

	int mapNGKind[GAME_MAP_NG_KIND];					
	int mapOKKind[GAME_MAP_OK_KIND];					
	int mapBTKind[GAME_MAP_BT_KIND];					

	RECT rect_NG[GAME_MAP_TATE][GAME_MAP_YOKO];			
	RECT rect_NG_First[GAME_MAP_TATE][GAME_MAP_YOKO];	

	RECT rect_OK[GAME_MAP_TATE][GAME_MAP_YOKO];			
	RECT rect_OK_First[GAME_MAP_TATE][GAME_MAP_YOKO];	

	RECT rect_BT[GAME_MAP_TATE][GAME_MAP_YOKO];	
	RECT rect_BT_First[GAME_MAP_TATE][GAME_MAP_YOKO];		

};	

struct STRUCT_CHARAIMAGE
{
	char FilePath[128];													
	int Handle[GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT];		
	int X[GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT];			
	int Y[GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT];			
	int Width[GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT];		
	int Height[GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT];		
	int C_Width[GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT];		
	int C_Height[GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT];	
};	

struct STRUCT_CHARADATA
{
	STRUCT_CHARAIMAGE charaimage;		
	int Handle[GAME_CHARA_MOTION_NUM];	
	int X;								
	int Y;								
	int Width;							
	int Height;							
	int C_Width;						
	int C_Height;						
	int NowHandleNum;					
	int NowHandleCnt;					
	int NowHandleCntMAX;				

	int Speed;							
	int MoveDistX;						
	int MoveDistY;						

	BOOL CanMoveUp;						
	BOOL CanMoveDown;					
	BOOL CanMoveLeft;					
	BOOL CanMoveRight;					

	BOOL ScrollOK_X;					
	BOOL ScrollOK_Y;					

	int atariX;							
	int atariY;							
	int atariWidth;						
	int atariHeight;					
						

				

	char name[255];						
	int HP;
	int ATK;
	int DEF;
	int EXP;			

	int LV;
	int HP_MAX;
	int ATK_MAX;
	int DEF_MAX;
	

	RECT rect_st;	
	RECT atariRect;
	

	

	BOOL IsAlive;		//生きているか

	int gameEndKind;	//ゲーム終了の状態

	int EndLV;			//終了時点でのLV
	int EndHP;			//終了時点でのHP
	int EndATK;			//終了時点でのATK
	int EndDEF;			//終了時点でのDEF

};	//STRUCT_CHARADATA構造体






typedef STRUCT_IMAGE IMAGE;
typedef STRUCT_MAPDATA MAPDATA;
typedef STRUCT_CHARAIMAGE CHARAIMAGE;
typedef STRUCT_CHARADATA CHARADATA;


WNDPROC WndProc;						


char AllKeyState[256];			

int GameSceneNow = (int)GAME_SCENE_TITLE;


IMAGE Image_map;
MAPDATA mapData_sita;	//下のマップ
MAPDATA mapData_naka;	//中のマップ
MAPDATA mapData_ue;		//上のマップ



IMAGE image_title;		//タイトル画面
IMAGE image_clear;		//クリア画面


int ScrollCntYoko = 0;	//スクロールカウンタ(横)
int ScrollCntTate = 0;	//スクロールカウンタ(縦)

CHARAIMAGE CharaImage;	//キャラの画像
CHARADATA	Myplayer;	//キャラのデータ


int PlayerImageNum[GAME_CHARA_MOTION_NUM];


RECT rectEndCon{ 100,100,300,500 };
RECT rectEndEnd{ 500,100,700,500 };


int EndConCnt = 0;
int EndConCntMAX = 120;

int EndEndCnt = 0;
int EndEndCntMAX = 120;

int MY_RANGE_RAND(int, int);	

int SceneBefore;	//以前のシーン
int SceneNext;		//次のシーン



				

VOID MY_ALL_KEYDOWN_UPDATE(VOID);	

VOID MY_GAME_TITLE(VOID);			
VOID MY_GAME_TITLE_DRAW(VOID);		
VOID MY_GAME_PLAY(VOID);			
VOID MY_GAME_PLAY_DRAW(VOID);		
	
VOID MY_GAME_END(VOID);				
VOID MY_GAME_END_DRAW(VOID);		

BOOL MY_PLAY_INIT(VOID);			



BOOL MY_MAP_READ_CSV_UE_KIND_SET(MAPDATA *);	
BOOL MY_MAP_READ_CSV_NAKA_KIND_SET(MAPDATA *);	
BOOL MY_MAP_READ_CSV_SITA_KIND_SET(MAPDATA *);	
BOOL MY_MAP_READ_CSV_NUM(MAPDATA *, const char *, const char *);				


int MY_LOAD_BACKGROUND(IMAGE *, const char *);										

								

BOOL MY_MAP_LOAD_BUNKATSU(MAPDATA *, int, int, int, int, int, const char *);	

VOID MY_PLAY_MAP_DRAW(MAPDATA);			
VOID MY_PLAY_MAP_DRAW_ATARI(MAPDATA *, MAPDATA *, MAPDATA *);	

BOOL MY_CHARA_LOAD_BUNKATSU(CHARAIMAGE*, int, int, int, int, int, const char *);	

BOOL MY_PLAYER_INIT(CHARADATA *, CHARAIMAGE, int *, int, int, int);	
VOID MY_PLAY_PLAYER_DRAW(CHARADATA);								

VOID MY_PLAY_PLAYER_OPERATION(VOID);								
BOOL MY_PLAY_PLAYER_OPERATION_KEY(int *, int *);					
VOID MY_PLAY_PLAYER_OPERATION_ENCOUNTER(int *, int *);				

VOID MY_SET_PLAYER_ATARI(CHARADATA *);	

BOOL MY_CHECK_RECT_ATARI(RECT, RECT);	
BOOL MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(RECT, RECT map[GAME_MAP_TATE][GAME_MAP_YOKO], int *, int *);



BOOL MY_GAME_NOWLOADING(VOID);				
BOOL MY_GAME_IN_MUGENLOOP(VOID);			
VOID MY_GAME_DELETE(VOID);					


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int IsLoad = FALSE;		//音楽や画像などを読み込めたか確認する変数

	ChangeWindowMode(TRUE);					//ウィンドウモードに設定
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);			//指定の数値で画面を表示する

	

	

	if (DxLib_Init() == -1) { return -1; }						//ＤＸライブラリ初期化処理

	SetDrawScreen(DX_SCREEN_BACK);								//Draw系関数は裏画面に描画

	MY_MAP_READ_CSV_UE_KIND_SET(&mapData_ue);		//マップの上の種類を設定
	MY_MAP_READ_CSV_NAKA_KIND_SET(&mapData_naka);	//マップの中の種類を設定
	MY_MAP_READ_CSV_SITA_KIND_SET(&mapData_sita);	//マップの下の種類を設定

	MY_MAP_READ_CSV_NUM(&mapData_ue, GAME_MAP_CSV_1_UE, GAME_MAP_NAME_1_UE);		//マップ１の上を読み込み、当たり判定の領域を作る
	MY_MAP_READ_CSV_NUM(&mapData_naka, GAME_MAP_CSV_1_NAKA, GAME_MAP_NAME_1_NAKA);	//マップ１の中を読み込み、当たり判定の領域を作る
	MY_MAP_READ_CSV_NUM(&mapData_sita, GAME_MAP_CSV_1_SITA, GAME_MAP_NAME_1_SITA);	//マップ１の下を読み込み、当たり判定の領域を作る

	if (MY_MAP_LOAD_BUNKATSU(&mapData_ue, GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT, GAME_MAP_BUN_YOKO_CNT, GAME_MAP_BUN_TATE_CNT, 32, 32, GAME_MAP_1_PATH) == FALSE) { MessageBox(NULL, GAME_MAP_1_PATH, "NotFound", MB_OK); return -1; }		//MAPを読み込む
	if (MY_MAP_LOAD_BUNKATSU(&mapData_naka, GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT, GAME_MAP_BUN_YOKO_CNT, GAME_MAP_BUN_TATE_CNT, 32, 32, GAME_MAP_1_PATH) == FALSE) { MessageBox(NULL, GAME_MAP_1_PATH, "NotFound", MB_OK); return -1; }	//MAPを読み込む
	if (MY_MAP_LOAD_BUNKATSU(&mapData_sita, GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT, GAME_MAP_BUN_YOKO_CNT, GAME_MAP_BUN_TATE_CNT, 32, 32, GAME_MAP_1_PATH) == FALSE) { MessageBox(NULL, GAME_MAP_1_PATH, "NotFound", MB_OK); return -1; }	//MAPを読み込む

	if (MY_CHARA_LOAD_BUNKATSU(&CharaImage, GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT, GAME_CHARA_BUN_YOKO_CNT, GAME_CHARA_BUN_TATE_CNT, GAME_CHARA_YOKO_SIZE, GAME_CHARA_TATE_SIZE, GAME_CHARA) == FALSE) { MessageBox(NULL, GAME_CHARA, "NotFound", MB_OK); return -1; }	//GAME_CHARA_1を読み込む

	
	IsLoad = MY_GAME_NOWLOADING();

	if (IsLoad == FALSE) { return -1; }

	int IsInLoop = FALSE;		

	while (TRUE)	
	{
		
		IsInLoop = MY_GAME_IN_MUGENLOOP();

		if (IsInLoop == FALSE) { break; }			
	}

	MY_GAME_DELETE();

	DxLib_End();		

	return 0;
}


//########## ゲームで使用する、音楽や画像などを読み込む関数 ##########
BOOL MY_GAME_NOWLOADING(VOID)
{
	
	if (MY_LOAD_BACKGROUND(&image_title, GAME_TITLE_IMAGE) == FALSE) { MessageBox(NULL, GAME_TITLE_IMAGE, "NotFound", MB_OK); return FALSE; }				//IMAGEを読み込む
	if (MY_LOAD_BACKGROUND(&image_clear, GAME_CLEAR_IMAGE) == FALSE) { MessageBox(NULL, GAME_CLEAR_IMAGE, "NotFound", MB_OK); return FALSE; }				//IMAGEを読み込む
	

	return TRUE;
}

//########## ゲーム内で読み込んだ画像や音楽を削除する関数 ##########
VOID MY_GAME_DELETE(VOID)
{
	//マップのハンドルを削除
	for (int mapCnt = 0; mapCnt < GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT; mapCnt++)
	{
		DeleteGraph(mapData_ue.Handle[mapCnt]);
		DeleteGraph(mapData_sita.Handle[mapCnt]);
	}

	
	


	return;
}

//########## ゲームでの無限ループ内の関数 ##########
BOOL MY_GAME_IN_MUGENLOOP(VOID)
{
	if (ProcessMessage() != 0) { return FALSE; }	//メッセージ処理の結果がエラーのとき、強制終了

	if (ClearDrawScreen() != 0) { return FALSE; }	//画面を消去できなかったとき、強制終了

	MY_ALL_KEYDOWN_UPDATE();				//キーの状態を取得

	

	//シーン選択
	switch (GameSceneNow)
	{
	case (int)GAME_SCENE_TITLE:	//タイトル画面の処理ここから

		MY_GAME_TITLE();	//タイトル画面の処理

		break;	//タイトル画面の処理ここまで

	case (int)GAME_SCENE_PLAY:	//プレイ画面の処理ここから

		MY_GAME_PLAY();		//プレイ画面の処理

		break;	//プレイ画面の処理ここまで

	

	

	case (int)GAME_SCENE_END:	//エンド画面の処理ここから

		MY_GAME_END();		//エンド画面の処理

		break;	//エンド画面の処理ここまで

	default:

		break;

	}

	

	

	ScreenFlip();		//モニタのリフレッシュレートの速さで裏画面を再描画

	

	return TRUE;
}

//########## FPS値を計測、更新する関数 ##########

VOID MY_ALL_KEYDOWN_UPDATE(VOID)
{
	char TempKey[256];			//一時的に、現在のキーの入力状態を格納する

	GetHitKeyStateAll(TempKey); // 全てのキーの入力状態を得る

	for (int i = 0; i < 256; i++)
	{
		if (TempKey[i] != 0)	//押されているキーのキーコードを押しているとき
		{
			AllKeyState[i]++;	//押されている
		}
		else
		{
			AllKeyState[i] = 0;	//押されていない
		}
	}
	return;
}

//########## タイトル画面の関数 ##########
VOID MY_GAME_TITLE(VOID)
{

	

	if (AllKeyState[KEY_INPUT_RETURN] != 0)	//エンターキーが押されていた時
	{
		if (MY_PLAY_INIT() == TRUE)		//プレイ画面初期化
		{
			GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
		}
	}

	MY_GAME_TITLE_DRAW();	//タイトル画面描画の関数

	return;
}

//########## タイトル画面描画の関数 ##########
VOID MY_GAME_TITLE_DRAW(VOID)
{
	DrawGraph(0, 0, image_title.Handle[0], TRUE);

	
	DrawString(0, 0, "スタート画面(エンターキーを押して下さい)", GetColor(255, 255, 255));

	return;
}

//########## 初期化関数 ##########
BOOL MY_PLAY_INIT(VOID)
{
	ScrollCntYoko = 0;
	ScrollCntTate = 0;

	//プレイヤーの画像の番号を設定
	int StartNum = (int)CHARA_KIND_7;
	int soeji = 0;
	PlayerImageNum[soeji++] = StartNum + 0;
	PlayerImageNum[soeji++] = StartNum + 1;
	PlayerImageNum[soeji++] = StartNum + 2;
	PlayerImageNum[soeji++] = StartNum + 12;
	PlayerImageNum[soeji++] = StartNum + 13;
	PlayerImageNum[soeji++] = StartNum + 14;
	PlayerImageNum[soeji++] = StartNum + 24;
	PlayerImageNum[soeji++] = StartNum + 25;
	PlayerImageNum[soeji++] = StartNum + 26;
	PlayerImageNum[soeji++] = StartNum + 36;
	PlayerImageNum[soeji++] = StartNum + 37;
	PlayerImageNum[soeji++] = StartNum + 38;

	//プレイヤーを初期化
	if (MY_PLAYER_INIT(&Myplayer, CharaImage, &PlayerImageNum[0], GAME_MAP_YOKO_SIZE * GAME_CHARA_STARTX, GAME_MAP_TATE_SIZE * GAME_CHARA_STARTY, GAME_CHARA_SPEED) == FALSE) { MessageBox(NULL, "CHARA_INIT", "NotFound", MB_OK); return FALSE; }

	

	

	return TRUE;
}

//########## プレイ画面の関数 ##########
VOID MY_GAME_PLAY(VOID)
{

	MY_PLAY_PLAYER_OPERATION();		//プレイヤーを操作する



	MY_GAME_PLAY_DRAW();	//プレイ画面描画
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//エンターキーが押されていた時
	{
		
			GameSceneNow = (int)GAME_SCENE_END;	//シーンをプレイ画面にする
		
	}

	return;
}

// ########## プレイ画面描画の関数 ##########
VOID MY_GAME_PLAY_DRAW(VOID)
{

	MY_PLAY_MAP_DRAW(mapData_sita);


	MY_PLAY_MAP_DRAW(mapData_naka);

	MY_PLAY_PLAYER_DRAW(Myplayer);


	MY_PLAY_MAP_DRAW(mapData_ue);

	MY_PLAY_MAP_DRAW_ATARI(&mapData_ue, &mapData_naka, &mapData_sita);


	return;
}


BOOL MY_PLAYER_INIT(CHARADATA *charadata, CHARAIMAGE charaimage, int *num, int x, int y, int speed)
{
	//*(num + 0)は配列の先頭アドレス

	for (int mot = 0; mot < GAME_CHARA_MOTION_NUM; mot++)
	{
		charadata->Handle[mot] = charaimage.Handle[*(num + mot)];	//画像のハンドルを入れる
	}

	charadata->X = x;
	charadata->Y = y;
	charadata->Width = charaimage.Width[*(num + 0)];		//最初の画像の横幅を設定する
	charadata->Height = charaimage.Height[*(num + 0)];		//最初の画像の高さを設定する
	charadata->C_Width = charaimage.C_Width[*(num + 0)];	//最初の画像の横幅の中心を設定する
	charadata->C_Height = charaimage.C_Height[*(num + 0)];	//最初の画像の高さの中心を設定する

	//マップひとつあたりと同じ大きさにする
	charadata->Width = GAME_MAP_YOKO_SIZE;
	charadata->Height = GAME_MAP_TATE_SIZE;
	charadata->C_Width = GAME_MAP_YOKO_SIZE / 2;
	charadata->C_Height = GAME_MAP_TATE_SIZE / 2;

	charadata->NowHandleNum = 6;	//前向きの最初の画像
	charadata->NowHandleCnt = 0;	//画像カウンタを初期化

	charadata->NowHandleCntMAX = 6;	//画像カウンタMAXを初期化

	
	charadata->Speed = speed;		

	charadata->MoveDistX = x;		
	charadata->MoveDistY = y;		

	charadata->CanMoveUp = TRUE;	
	charadata->CanMoveDown = TRUE;	
	charadata->CanMoveLeft = TRUE;	
	charadata->CanMoveRight = TRUE;	

	charadata->ScrollOK_X = FALSE;	
	charadata->ScrollOK_Y = FALSE;	

	charadata->atariX = 4;			
	charadata->atariY = 10;			
	charadata->atariWidth = 18;		
	charadata->atariHeight = 24;	

	//敵の種類はなし

	wsprintf(charadata->name, "AAA");	//名前を設定

	charadata->LV = charadata->HP_MAX = GAME_PLAYER_LV_FIRST;			//プレイヤーの最初のLV
	charadata->HP = charadata->HP_MAX = GAME_PLAYER_HP_FIRST;			//プレイヤーの最初のHP
	charadata->ATK = charadata->ATK_MAX = GAME_PLAYER_ATK_FIRST;		//プレイヤーの最初のATK
	charadata->DEF = charadata->DEF_MAX = GAME_PLAYER_DEF_FIRST;		//プレイヤーの最初のDEF
	charadata->EXP = GAME_PLAYER_EXP_FIRST;								//プレイヤーの最初のEXP

	
	charadata->IsAlive = TRUE;			//生きている

	

	charadata->gameEndKind = (int)GAME_END_KIND_NONE;

	

	MY_SET_PLAYER_ATARI(charadata);	//プレイヤーの当たり判定の領域を設定する

	return TRUE;
}

//########## プレイヤーを操作する関数 ##########

VOID MY_PLAY_PLAYER_OPERATION(VOID)
{
	int retAtariX = 0; int retAtariY = 0;	//当たっているマップの場所

	BOOL IsKeyDown = MY_PLAY_PLAYER_OPERATION_KEY(&retAtariX, &retAtariY);	//キーを押して操作しているか判断

	


	return;
}
//########## プレイヤーを操作する(キー操作)関数 ##########
BOOL MY_PLAY_PLAYER_OPERATION_KEY(int *x, int *y)
{
	BOOL IsKeyDown = FALSE;		//キーを押されたか

	if (AllKeyState[KEY_INPUT_LEFT] != 0)	//左矢印キーが押されていた時
	{
		IsKeyDown = TRUE;	//キーを押された

		Myplayer.CanMoveLeft = TRUE;	//左方向に、まだ動ける

		MY_SET_PLAYER_ATARI(&Myplayer);	//プレイヤーの当たり判定の領域を設定
		Myplayer.atariRect.left -= 4;	//少し、当たり判定の領域を左にずらす
		Myplayer.atariRect.right -= 4;	//少し、当たり判定の領域を左にずらす

		if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_naka.rect_NG, x, y) == TRUE)	//左に行けないモノと当たったとき
		{
			Myplayer.CanMoveLeft = FALSE;	//左に行けない
		}

		if (Myplayer.CanMoveLeft == TRUE)	//左に移動できるとき
		{
			if (Myplayer.ScrollOK_X == FALSE)	//スクロールできないとき
			{
				if (Myplayer.X > 0)
				{
					Myplayer.X -= Myplayer.Speed;	//プレイヤーを左に移動
				}
			}
			else	//スクロールできるとき
			{
				if (ScrollCntYoko > 0)	//マップ外へスクロールしない
				{
					ScrollCntYoko -= Myplayer.Speed;	//画面を左にスクロール
				}
			}

			if (Myplayer.MoveDistX > 0)
			{
				Myplayer.MoveDistX -= Myplayer.Speed;	//動いた距離を計算
			}
		}

	}

	if (AllKeyState[KEY_INPUT_RIGHT] != 0)	//右矢印キーが押されていた時
	{
		IsKeyDown = TRUE;	//キーを押された

		Myplayer.CanMoveRight = TRUE;	//右方向に、まだ動ける

		MY_SET_PLAYER_ATARI(&Myplayer);	//プレイヤーの当たり判定の領域を設定
		Myplayer.atariRect.left += 4;	//少し、プレイヤーの当たり判定の領域を右にずらす
		Myplayer.atariRect.right += 4;	//少し、プレイヤーの当たり判定の領域を右にずらす

		if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_naka.rect_NG, x, y) == TRUE)	//右に行けないモノと当たったとき
		{
			Myplayer.CanMoveRight = FALSE;	//右に行けない
		}

		if (Myplayer.CanMoveRight == TRUE)	//右に移動できるとき
		{
			if (Myplayer.ScrollOK_X == FALSE)	//プレイヤーが動けるとき
			{
				if (Myplayer.X + Myplayer.Width < GAME_WIDTH)
				{
					Myplayer.X += Myplayer.Speed;			//プレイヤーを右に移動
				}
			}
			else	//プレイヤーが動けないとき
			{
				if (ScrollCntYoko < GAME_MAP_YOKO_SIZE * GAME_MAP_YOKO)	//画面外へスクロールしない
				{
					ScrollCntYoko += Myplayer.Speed;	//画面を右にスクロール
				}
			}

			if (Myplayer.MoveDistX < GAME_MAP_YOKO_SIZE * GAME_MAP_YOKO)
			{
				Myplayer.MoveDistX += Myplayer.Speed;	//動いた距離を計算
			}
		}
	}

	if (AllKeyState[KEY_INPUT_UP] != 0)	//上矢印キーが押されていた時
	{
		IsKeyDown = TRUE;	//キーを押された

		Myplayer.CanMoveUp = TRUE;	//上方向に、まだ動ける

		MY_SET_PLAYER_ATARI(&Myplayer);	//プレイヤーの当たり判定の領域を設定
		Myplayer.atariRect.top -= 4;	//少し、当たり判定の領域を上にずらす
		Myplayer.atariRect.bottom -= 4;	//少し、当たり判定の領域を上にずらす

		if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_naka.rect_NG, x, y) == TRUE)	//上に行けないモノと当たったとき
		{
			Myplayer.CanMoveUp = FALSE;	//上に行けない
		}

		if (Myplayer.CanMoveUp == TRUE)	//上に移動できるとき
		{
			if (Myplayer.ScrollOK_Y == FALSE)	//プレイヤーが動けるとき
			{
				if (Myplayer.Y > 0)
				{
					Myplayer.Y -= Myplayer.Speed;	//プレイヤーを上に移動
				}
			}
			else	//スクロールできるとき
			{
				if (ScrollCntTate > 0)	//マップ外へスクロールしない
				{
					ScrollCntTate -= Myplayer.Speed;	//画面を上にスクロール
				}
			}

			if (Myplayer.MoveDistY > 0)
			{
				Myplayer.MoveDistY -= Myplayer.Speed;	//動いた距離を計算
			}
		}
	}

	if (AllKeyState[KEY_INPUT_DOWN] != 0)	//下矢印キーが押されていた時
	{
		IsKeyDown = TRUE;	//キーを押された

		Myplayer.CanMoveDown = TRUE;	//下方向に、まだ動ける

		MY_SET_PLAYER_ATARI(&Myplayer);	//プレイヤーの当たり判定の領域を設定
		Myplayer.atariRect.top += 4;	//少し、プレイヤーの当たり判定の領域を下にずらす
		Myplayer.atariRect.bottom += 4;	//少し、プレイヤーの当たり判定の領域を下にずらす

		if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_naka.rect_NG, x, y) == TRUE)	//下に行けないモノと当たったとき
		{
			Myplayer.CanMoveDown = FALSE;	//下に行けない
		}

		if (Myplayer.CanMoveDown == TRUE)	//下に移動できるとき
		{
			if (Myplayer.ScrollOK_Y == FALSE)	//プレイヤーが動けるとき
			{
				if (Myplayer.Y + Myplayer.Width < GAME_HEIGHT)
				{
					Myplayer.Y += Myplayer.Speed;			//プレイヤーを下に移動
				}
			}
			else	//プレイヤーが動けないとき
			{
				if (ScrollCntTate < GAME_MAP_TATE_SIZE * GAME_MAP_TATE)	//画面外へスクロールしない
				{
					ScrollCntTate += Myplayer.Speed;	//画面下にスクロール
				}
			}

			if (Myplayer.MoveDistY < GAME_MAP_TATE_SIZE * (GAME_MAP_TATE - 1))
			{
				Myplayer.MoveDistY += Myplayer.Speed;	//動いた距離を計算
			}
		}
	}

	//マップの左側にいるときは、プレイヤーを動かす
	if (Myplayer.MoveDistX > 0 &&
		Myplayer.MoveDistX <= GAME_MAP_YOKO_SIZE * 10)	//プレイヤーの動いた距離が一定以上あれば(開始地点)
	{
		Myplayer.ScrollOK_X = FALSE;					//マップを止めて、プレイヤーを動かす
	}

	//マップ真ん中らへんにいるときは、マップを動かす
	if (Myplayer.MoveDistX > GAME_MAP_YOKO_SIZE * 10 &&
		Myplayer.MoveDistX <= GAME_MAP_YOKO_SIZE * (GAME_MAP_YOKO - 15))	//プレイヤーの動いた距離が一定以上あれば(開始地点)
	{
		Myplayer.ScrollOK_X = TRUE;					//マップを動かす
	}

	//マップの右側にいるときは、プレイヤーを動かす
	if (Myplayer.MoveDistX > GAME_MAP_YOKO_SIZE * (GAME_MAP_YOKO - 15) &&
		Myplayer.MoveDistX <= GAME_MAP_YOKO_SIZE * GAME_MAP_YOKO)	//プレイヤーの動いた距離が一定以上あれば(終了地点)
	{
		Myplayer.ScrollOK_X = FALSE;					//マップを止めて、プレイヤーを動かす
	}

	//マップの上側にいるときは、プレイヤーを動かす
	if (Myplayer.MoveDistY > 0 &&
		Myplayer.MoveDistY <= GAME_MAP_TATE_SIZE * 10)	//プレイヤーの動いた距離が一定以上あれば(開始地点)
	{
		Myplayer.ScrollOK_Y = FALSE;					//マップを止めて、プレイヤーを動かす
	}

	//マップ真ん中らへんにいるときは、マップを動かす
	if (Myplayer.MoveDistY > GAME_MAP_TATE_SIZE * 10 &&
		Myplayer.MoveDistY <= GAME_MAP_TATE_SIZE * (GAME_MAP_TATE - 9))	//プレイヤーの動いた距離が一定以上あれば(開始地点)
	{
		Myplayer.ScrollOK_Y = TRUE;					//マップを動かす
	}

	//マップの下側にいるときは、プレイヤーを動かす
	if (Myplayer.MoveDistY > GAME_MAP_TATE_SIZE * (GAME_MAP_TATE - 9) &&
		Myplayer.MoveDistY <= GAME_MAP_TATE_SIZE * GAME_MAP_TATE)	//プレイヤーの動いた距離が一定以上あれば(終了地点)
	{
		Myplayer.ScrollOK_Y = FALSE;	//マップを止めて、プレイヤーを動かす
	}

	return IsKeyDown;
}






BOOL MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(RECT chara, RECT map[GAME_MAP_TATE][GAME_MAP_YOKO], int *atariX, int *atariY)
{
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			
			if (MY_CHECK_RECT_ATARI(chara, map[tate][yoko]) == TRUE)
			{
				*atariY = tate;	//atariYのアドレスが指し示す先の場所に、当たったモノの縦の位置を入れる
				*atariX = yoko;	//atariXのアドレスが指し示す先の場所に、当たったモノの横の位置を入れる

				return TRUE;
			}
		}
	}

	return FALSE;		//当たっていない
}

//########## 領域の当たり判定をする関数 ##########
BOOL MY_CHECK_RECT_ATARI(RECT a, RECT b)
{
	if (a.left < b.right &&
		a.top < b.bottom &&
		a.right > b.left &&
		a.bottom > b.top
		)
	{
		return TRUE;	//当たっている
	}

	return FALSE;		//当たっていない
}

//########## プレイヤーの当たり判定の領域を設定する関数 ##########
VOID MY_SET_PLAYER_ATARI(CHARADATA *charadata)
{
	//当たり判定の領域の設定
	charadata->atariRect.left = charadata->X + charadata->atariX + 2;						//現在のX位置 ＋ 当たり判定のX位置
	charadata->atariRect.top = charadata->Y + charadata->atariY + 2;						//現在のY位置 ＋ 当たり判定のY位置
	charadata->atariRect.right = charadata->X + charadata->atariX + charadata->atariWidth - 2;		//現在のX位置 ＋ 当たり判定のX位置 ＋ 当たり判定の幅
	charadata->atariRect.bottom = charadata->Y + charadata->atariY + charadata->atariHeight - 2;	//現在のY位置 ＋ 当たり判定のY位置 ＋ 当たり判定の高さ

	return;
}

//########## プレイヤーを表示する関数 ##########
VOID MY_PLAY_PLAYER_DRAW(CHARADATA player)
{
	//プレイヤーを描画
	DrawGraph(
		player.X,
		player.Y,
		player.Handle[player.NowHandleNum], TRUE);


	if (AllKeyState[KEY_INPUT_LEFT] != 0)	//左矢印キーが押されていた時
	{
		if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
		{
			Myplayer.NowHandleCnt++;
		}
		else
		{
			Myplayer.NowHandleCnt = 0;

			if (Myplayer.NowHandleNum >= 9 && Myplayer.NowHandleNum < 11)
			{
				Myplayer.NowHandleNum++;	//次の左向きの画像
			}
			else
			{
				Myplayer.NowHandleNum = 9;	
			}
		}
	}
	else if (AllKeyState[KEY_INPUT_RIGHT] != 0)	
	{
		if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
		{
			Myplayer.NowHandleCnt++;
		}
		else
		{
			Myplayer.NowHandleCnt = 0;

			if (Myplayer.NowHandleNum >= 3 && Myplayer.NowHandleNum < 5)
			{
				Myplayer.NowHandleNum++;	
			}
			else
			{
				Myplayer.NowHandleNum = 3;	
			}
		}
	}
	else if (AllKeyState[KEY_INPUT_UP] != 0)	
	{
		if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
		{
			Myplayer.NowHandleCnt++;
		}
		else
		{
			Myplayer.NowHandleCnt = 0;

			if (Myplayer.NowHandleNum >= 0 && Myplayer.NowHandleNum < 2)
			{
				Myplayer.NowHandleNum++;	
			}
			else
			{
				Myplayer.NowHandleNum = 0;	
			}
		}
	}
	else if (AllKeyState[KEY_INPUT_DOWN] != 0)	
	{
		if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
		{
			Myplayer.NowHandleCnt++;
		}
		else
		{
			Myplayer.NowHandleCnt = 0;

			if (Myplayer.NowHandleNum >= 6 && Myplayer.NowHandleNum < 8)
			{
				Myplayer.NowHandleNum++;	
			}
			else
			{
				Myplayer.NowHandleNum = 6;	
			}
		}
	}

	
	return;
}

VOID MY_PLAY_MAP_DRAW(MAPDATA mapdata)
{
	//スクロールするマップを描画
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			if ((yoko + 1) * GAME_MAP_YOKO_SIZE - ScrollCntYoko >= 0 &&
				(yoko + 0) * GAME_MAP_YOKO_SIZE - ScrollCntYoko <= GAME_WIDTH &&
				(tate + 1) * GAME_MAP_TATE_SIZE - ScrollCntTate >= 0 &&
				(tate + 0) * GAME_MAP_TATE_SIZE - ScrollCntTate <= GAME_HEIGHT
				)	//画面に写っているならばならば
			{
				DrawGraph(
					yoko * GAME_MAP_YOKO_SIZE - ScrollCntYoko,				
					tate * GAME_MAP_TATE_SIZE - ScrollCntTate,				
					mapdata.Handle[mapdata.data[tate][yoko]], TRUE);		
			}

		}
	}

}


VOID MY_PLAY_MAP_DRAW_ATARI(MAPDATA *map_ue, MAPDATA *map_naka, MAPDATA *map_sita)
{
	//スクロールするマップを描画
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			
		

			map_naka->rect_OK[tate][yoko].left = map_naka->rect_OK_First[tate][yoko].left - ScrollCntYoko;
			map_naka->rect_OK[tate][yoko].right = map_naka->rect_OK_First[tate][yoko].right - ScrollCntYoko;
			map_naka->rect_OK[tate][yoko].top = map_naka->rect_OK_First[tate][yoko].top - ScrollCntTate;
			map_naka->rect_OK[tate][yoko].bottom = map_naka->rect_OK_First[tate][yoko].bottom - ScrollCntTate;

			map_naka->rect_NG[tate][yoko].left = map_naka->rect_NG_First[tate][yoko].left - ScrollCntYoko;
			map_naka->rect_NG[tate][yoko].right = map_naka->rect_NG_First[tate][yoko].right - ScrollCntYoko;
			map_naka->rect_NG[tate][yoko].top = map_naka->rect_NG_First[tate][yoko].top - ScrollCntTate;
			map_naka->rect_NG[tate][yoko].bottom = map_naka->rect_NG_First[tate][yoko].bottom - ScrollCntTate;

			map_sita->rect_BT[tate][yoko].left = map_sita->rect_BT_First[tate][yoko].left - ScrollCntYoko;
			map_sita->rect_BT[tate][yoko].right = map_sita->rect_BT_First[tate][yoko].right - ScrollCntYoko;
			map_sita->rect_BT[tate][yoko].top = map_sita->rect_BT_First[tate][yoko].top - ScrollCntTate;
			map_sita->rect_BT[tate][yoko].bottom = map_sita->rect_BT_First[tate][yoko].bottom - ScrollCntTate;


		}
	}
}


BOOL MY_GAME_SCENE_MOVE(int beforeScene)
{

		switch (beforeScene)
		{
		case (int)GAME_SCENE_TITLE:	//タイトル画面

			MY_GAME_TITLE_DRAW();	//タイトル画面描画

			break;

		case (int)GAME_SCENE_PLAY:	//プレイ画面

			MY_GAME_PLAY_DRAW();	//プレイ画面描画

			break;


		case (int)GAME_SCENE_END:	//エンド画面

			MY_GAME_END_DRAW();		//エンド画面

			break;

		default:

			break;

		}

		
	return FALSE;
}








VOID MY_GAME_END(VOID)
{


		if (AllKeyState[KEY_INPUT_ESCAPE] != 0)	//スペースキーが押されていた時
		{
			GameSceneNow = (int)GAME_SCENE_TITLE;	//シーンをタイトル画面にする
		}

	

	MY_GAME_END_DRAW();	

	return;
}

VOID MY_GAME_END_DRAW(VOID)
{
	char clear[64] = { "GAME CLEAR" };
	
	

	DrawStringToHandle(0, 0, "エンド画面", GetColor(255, 255, 255), 30);

	return;
}


BOOL MY_MAP_READ_CSV_NUM(MAPDATA *mapdata, const char *path, const char *mapname)
{
	FILE *fp;

	if ((fp = fopen(path, "r")) == NULL)	
	{
		return FALSE;
	}

	int result = 0;			
	int LoopCnt = 0;		
	while (result != EOF)	
	{
		
		result = fscanf(fp, "%d,", &mapdata->data[LoopCnt / GAME_MAP_YOKO][LoopCnt % GAME_MAP_YOKO]);
		mapdata->mapdata_Init[LoopCnt / GAME_MAP_YOKO][LoopCnt % GAME_MAP_YOKO]
			= mapdata->data[LoopCnt / GAME_MAP_YOKO][LoopCnt % GAME_MAP_YOKO];	

		LoopCnt++;
	}
	fclose(fp);	

	
	wsprintf(mapdata->name, mapname);	


	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			mapdata->rect_NG[tate][yoko].left = 0;
			mapdata->rect_NG[tate][yoko].top = 0;
			mapdata->rect_NG[tate][yoko].right = 0;
			mapdata->rect_NG[tate][yoko].bottom = 0;

			mapdata->rect_NG_First[tate][yoko] = mapdata->rect_NG[tate][yoko];	

			mapdata->rect_OK[tate][yoko].left = 0;
			mapdata->rect_OK[tate][yoko].top = 0;
			mapdata->rect_OK[tate][yoko].right = 0;
			mapdata->rect_OK[tate][yoko].bottom = 0;

			mapdata->rect_OK_First[tate][yoko] = mapdata->rect_OK[tate][yoko];	

			mapdata->rect_BT[tate][yoko].left = 0;
			mapdata->rect_BT[tate][yoko].top = 0;
			mapdata->rect_BT[tate][yoko].right = 0;
			mapdata->rect_BT[tate][yoko].bottom = 0;

			mapdata->rect_BT_First[tate][yoko] = mapdata->rect_BT[tate][yoko];	

		}
	}


	int cnt;
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			for (cnt = 0; cnt < GAME_MAP_NG_KIND; cnt++)	
			{
				if (mapdata->data[tate][yoko] == mapdata->mapNGKind[cnt])
				{
					mapdata->rect_NG[tate][yoko].left = yoko * GAME_MAP_YOKO_SIZE + 1;
					mapdata->rect_NG[tate][yoko].top = tate * GAME_MAP_TATE_SIZE + 1;
					mapdata->rect_NG[tate][yoko].right = (yoko + 1) * GAME_MAP_YOKO_SIZE - 1;
					mapdata->rect_NG[tate][yoko].bottom = (tate + 1) * GAME_MAP_TATE_SIZE - 1;

					mapdata->rect_NG_First[tate][yoko] = mapdata->rect_NG[tate][yoko];	
				}
			}

			for (cnt = 0; cnt < GAME_MAP_OK_KIND; cnt++)	
			{
				if (mapdata->data[tate][yoko] == mapdata->mapOKKind[cnt])
				{
					mapdata->rect_OK[tate][yoko].left = yoko * GAME_MAP_YOKO_SIZE + 1;
					mapdata->rect_OK[tate][yoko].top = tate * GAME_MAP_TATE_SIZE + 1;
					mapdata->rect_OK[tate][yoko].right = (yoko + 1) * GAME_MAP_YOKO_SIZE - 1;
					mapdata->rect_OK[tate][yoko].bottom = (tate + 1) * GAME_MAP_TATE_SIZE - 1;

					mapdata->rect_OK_First[tate][yoko] = mapdata->rect_OK[tate][yoko];	
				}
			}

			for (cnt = 0; cnt < GAME_MAP_BT_KIND; cnt++)	
			{
				if (mapdata->data[tate][yoko] == mapdata->mapBTKind[cnt])
				{
					mapdata->rect_BT[tate][yoko].left = yoko * GAME_MAP_YOKO_SIZE + 1;
					mapdata->rect_BT[tate][yoko].top = tate * GAME_MAP_TATE_SIZE + 1;
					mapdata->rect_BT[tate][yoko].right = (yoko + 1) * GAME_MAP_YOKO_SIZE - 1;
					mapdata->rect_BT[tate][yoko].bottom = (tate + 1) * GAME_MAP_TATE_SIZE - 1;

					mapdata->rect_BT_First[tate][yoko] = mapdata->rect_BT[tate][yoko];	
				}
			}
		}
	}

	return TRUE;
}


int MY_LOAD_BACKGROUND(IMAGE *image, const char *path)
{
	image->Handle[0] = LoadGraph(path);	

	
	GetGraphSize(
		image->Handle[0],			
		&image->Width[0],			
		&image->Height[0]);					

	image->C_Width[0] = image->Width[0] / 2;	
	image->C_Height[0] = image->Height[0] / 2;	

	return image->Handle[0];
}



BOOL MY_MAP_LOAD_BUNKATSU(MAPDATA *mapdata, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char *path)
{
	int ret = 0;

	ret = LoadDivGraph(path, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, mapdata->Handle);	

	if (ret == -1) { return FALSE; }	

	for (int cnt = 0; cnt < GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT; cnt++)
	{
		
		GetGraphSize(
			mapdata->Handle[cnt],		
			&mapdata->Width[cnt],		
			&mapdata->Height[cnt]);				

		mapdata->C_Width[cnt] = mapdata->Width[cnt] / 2;	
		mapdata->C_Height[cnt] = mapdata->Height[cnt] / 2;	
	}

	return TRUE;
}

BOOL MY_MAP_READ_CSV_NAKA_KIND_SET(MAPDATA *mapdata)
{
	int Soeji;

	
	Soeji = 0;
	mapdata->mapOKKind[Soeji++] = 30;	//空白
	mapdata->mapOKKind[Soeji++] = 1081;	//｜の道
	mapdata->mapOKKind[Soeji++] = 1145;	//＋の道
	mapdata->mapOKKind[Soeji++] = 1113;	//－の道
	mapdata->mapOKKind[Soeji++] = 18;	//草

	mapdata->mapOKKind[Soeji++] = 160;	//春大木
	mapdata->mapOKKind[Soeji++] = 161;	//春大木
	mapdata->mapOKKind[Soeji++] = 162;	//春大木
	mapdata->mapOKKind[Soeji++] = 163;	//春大木
	mapdata->mapOKKind[Soeji++] = 192;	//春大木
	mapdata->mapOKKind[Soeji++] = 193;	//春大木
	mapdata->mapOKKind[Soeji++] = 194;	//春大木
	mapdata->mapOKKind[Soeji++] = 195;	//春大木
	mapdata->mapOKKind[Soeji++] = 224;	//春大木
	mapdata->mapOKKind[Soeji++] = 225;	//春大木
	mapdata->mapOKKind[Soeji++] = 226;	//春大木
	mapdata->mapOKKind[Soeji++] = 227;	//春大木
	mapdata->mapOKKind[Soeji++] = 256;	//春大木
	mapdata->mapOKKind[Soeji++] = 259;	//春大木

	mapdata->mapOKKind[Soeji++] = 164;	//夏大木
	mapdata->mapOKKind[Soeji++] = 165;	//夏大木
	mapdata->mapOKKind[Soeji++] = 166;	//夏大木
	mapdata->mapOKKind[Soeji++] = 167;	//夏大木
	mapdata->mapOKKind[Soeji++] = 196;	//夏大木
	mapdata->mapOKKind[Soeji++] = 197;	//夏大木
	mapdata->mapOKKind[Soeji++] = 198;	//夏大木
	mapdata->mapOKKind[Soeji++] = 199;	//夏大木
	mapdata->mapOKKind[Soeji++] = 228;	//夏大木
	mapdata->mapOKKind[Soeji++] = 229;	//夏大木
	mapdata->mapOKKind[Soeji++] = 230;	//夏大木
	mapdata->mapOKKind[Soeji++] = 231;	//夏大木
	mapdata->mapOKKind[Soeji++] = 260;	//夏大木
	mapdata->mapOKKind[Soeji++] = 263;	//夏大木

	mapdata->mapOKKind[Soeji++] = 288;	//秋大木
	mapdata->mapOKKind[Soeji++] = 289;	//秋大木
	mapdata->mapOKKind[Soeji++] = 290;	//秋大木
	mapdata->mapOKKind[Soeji++] = 291;	//秋大木
	mapdata->mapOKKind[Soeji++] = 320;	//秋大木
	mapdata->mapOKKind[Soeji++] = 321;	//秋大木
	mapdata->mapOKKind[Soeji++] = 322;	//秋大木
	mapdata->mapOKKind[Soeji++] = 323;	//秋大木
	mapdata->mapOKKind[Soeji++] = 352;	//秋大木
	mapdata->mapOKKind[Soeji++] = 353;	//秋大木
	mapdata->mapOKKind[Soeji++] = 354;	//秋大木
	mapdata->mapOKKind[Soeji++] = 355;	//秋大木
	mapdata->mapOKKind[Soeji++] = 384;	//秋大木
	mapdata->mapOKKind[Soeji++] = 387;	//秋大木

	mapdata->mapOKKind[Soeji++] = 292;	//冬大木
	mapdata->mapOKKind[Soeji++] = 293;	//冬大木
	mapdata->mapOKKind[Soeji++] = 294;	//冬大木
	mapdata->mapOKKind[Soeji++] = 295;	//冬大木
	mapdata->mapOKKind[Soeji++] = 324;	//冬大木
	mapdata->mapOKKind[Soeji++] = 325;	//冬大木
	mapdata->mapOKKind[Soeji++] = 326;	//冬大木
	mapdata->mapOKKind[Soeji++] = 327;	//冬大木
	mapdata->mapOKKind[Soeji++] = 356;	//冬大木
	mapdata->mapOKKind[Soeji++] = 357;	//冬大木
	mapdata->mapOKKind[Soeji++] = 358;	//冬大木
	mapdata->mapOKKind[Soeji++] = 359;	//冬大木
	mapdata->mapOKKind[Soeji++] = 388;	//冬大木
	mapdata->mapOKKind[Soeji++] = 391;	//冬大木
	mapdata->mapOKKind[Soeji++] = 12;	//花
	mapdata->mapOKKind[Soeji++] = 801;	//縁下
	mapdata->mapOKKind[Soeji++] = 768;	//縁左

	mapdata->mapOKKind[Soeji++] = 1219;	//蓮の花
	mapdata->mapOKKind[Soeji++] = 1173;	//ピサの斜塔上

	mapdata->mapOKKind[Soeji++] = 466;	//立て看板左上
	mapdata->mapOKKind[Soeji++] = 467;	//立て看板右上

	mapdata->mapOKKind[Soeji++] = 82;	//草長め

	mapdata->mapOKKind[Soeji++] = 1188;	//花
	mapdata->mapOKKind[Soeji++] = 1188;	//花
	mapdata->mapOKKind[Soeji++] = 1188;	//花
	mapdata->mapOKKind[Soeji++] = 1186;	//花
	mapdata->mapOKKind[Soeji++] = 1190;	//花
	mapdata->mapOKKind[Soeji++] = 1191;	//花

	mapdata->mapOKKind[Soeji++] = 17;	

	
	for (int cnt = Soeji; cnt < GAME_MAP_OK_KIND; cnt++) { mapdata->mapOKKind[cnt] = -1; }

	
	Soeji = 0;
	mapdata->mapNGKind[Soeji++] = 1136;	//家
	mapdata->mapNGKind[Soeji++] = 1105;	//家
	mapdata->mapNGKind[Soeji++] = 1106;	//家左
	mapdata->mapNGKind[Soeji++] = 1200;	//家右
	mapdata->mapNGKind[Soeji++] = 1169;	//豪邸左
	mapdata->mapNGKind[Soeji++] = 1170;	//豪邸右

	mapdata->mapNGKind[Soeji++] = 34;	//中木夏
	mapdata->mapNGKind[Soeji++] = 35;	//中木夏
	mapdata->mapNGKind[Soeji++] = 98;	//中木夏
	mapdata->mapNGKind[Soeji++] = 99;	//中木夏
	mapdata->mapNGKind[Soeji++] = 66;	//中木夏
	mapdata->mapNGKind[Soeji++] = 67;	//中木夏

	mapdata->mapNGKind[Soeji++] = 945;	//小木
	mapdata->mapNGKind[Soeji++] = 946;	//小木

	mapdata->mapNGKind[Soeji++] = 257;	//春大木
	mapdata->mapNGKind[Soeji++] = 258;	//春大木
	mapdata->mapNGKind[Soeji++] = 261;	//夏大木
	mapdata->mapNGKind[Soeji++] = 262;	//夏大木
	mapdata->mapNGKind[Soeji++] = 385;	//秋大木
	mapdata->mapNGKind[Soeji++] = 386;	//秋大木
	mapdata->mapNGKind[Soeji++] = 389;	//冬大木
	mapdata->mapNGKind[Soeji++] = 390;	//冬大木
	mapdata->mapNGKind[Soeji++] = 1088;	//春大木
	mapdata->mapNGKind[Soeji++] = 1089;	//夏大木
	mapdata->mapNGKind[Soeji++] = 1090;	//秋大木
	mapdata->mapNGKind[Soeji++] = 1091;	//冬大木

	mapdata->mapNGKind[Soeji++] = 432;	//木看板

	mapdata->mapNGKind[Soeji++] = 448;	//池
	mapdata->mapNGKind[Soeji++] = 480;	//池
	mapdata->mapNGKind[Soeji++] = 512;	//池
	mapdata->mapNGKind[Soeji++] = 544;	//池
	mapdata->mapNGKind[Soeji++] = 450;	//池
	mapdata->mapNGKind[Soeji++] = 482;	//池
	mapdata->mapNGKind[Soeji++] = 513;	//池
	mapdata->mapNGKind[Soeji++] = 546;	//池
	mapdata->mapNGKind[Soeji++] = 481;	//池
	mapdata->mapNGKind[Soeji++] = 513;	//池
	mapdata->mapNGKind[Soeji++] = 545;	//池
	mapdata->mapNGKind[Soeji++] = 616;

	mapdata->mapNGKind[Soeji++] = 1040;	//山
	mapdata->mapNGKind[Soeji++] = 1041;	//山
	mapdata->mapNGKind[Soeji++] = 1042;	//山
	mapdata->mapNGKind[Soeji++] = 1043;	//山
	mapdata->mapNGKind[Soeji++] = 1072;	//山
	mapdata->mapNGKind[Soeji++] = 1073;	//山
	mapdata->mapNGKind[Soeji++] = 1074;	//山
	mapdata->mapNGKind[Soeji++] = 1075;	//山

	mapdata->mapNGKind[Soeji++] = 1128;

	mapdata->mapNGKind[Soeji++] = 1137;	//豪邸噴水左
	mapdata->mapNGKind[Soeji++] = 1138;	//豪邸噴水右

	mapdata->mapNGKind[Soeji++] = 1168;	//学校
	mapdata->mapNGKind[Soeji++] = 1200;	//ピラミッド
	mapdata->mapNGKind[Soeji++] = 1233;	//ピラミッド
	mapdata->mapNGKind[Soeji++] = 1202;	//家旗
	mapdata->mapNGKind[Soeji++] = 1232;	//家遺跡
	mapdata->mapNGKind[Soeji++] = 1234;	//家遺跡
	mapdata->mapNGKind[Soeji++] = 1205;	//ピサの斜塔下

	mapdata->mapNGKind[Soeji++] = 498;	//立て看板左下
	mapdata->mapNGKind[Soeji++] = 499;	//立て看板右下

	mapdata->mapNGKind[Soeji++] = 1260;	//塀
	mapdata->mapNGKind[Soeji++] = 1288;	//塀
	mapdata->mapNGKind[Soeji++] = 1289;	//塀
	mapdata->mapNGKind[Soeji++] = 1290;	//塀
	mapdata->mapNGKind[Soeji++] = 1291;	//塀
	mapdata->mapNGKind[Soeji++] = 1292;	//塀
	mapdata->mapNGKind[Soeji++] = 1256;	//塀
	mapdata->mapNGKind[Soeji++] = 1258;	//塀
	mapdata->mapNGKind[Soeji++] = 1259;	//塀
	mapdata->mapNGKind[Soeji++] = 1294;	//塀
	mapdata->mapNGKind[Soeji++] =839;

	mapdata->mapNGKind[Soeji++] = 542;	//箱
	mapdata->mapNGKind[Soeji++] = 543;	//箱
	mapdata->mapNGKind[Soeji++] = 574;	//箱
	mapdata->mapNGKind[Soeji++] = 575;	//箱
	mapdata->mapNGKind[Soeji++] = 606;	//箱
	mapdata->mapNGKind[Soeji++] = 607;	//箱

	mapdata->mapNGKind[Soeji++] = 1284;	//落とし穴小
	mapdata->mapNGKind[Soeji++] = 1285;	//落とし穴中

	mapdata->mapNGKind[Soeji++] = 1107;	//元魔王城
	mapdata->mapNGKind[Soeji++] = 1108;	//元魔王城
	mapdata->mapNGKind[Soeji++] = 1139;	//元魔王城
	mapdata->mapNGKind[Soeji++] = 1140;	//元魔王城

	mapdata->mapNGKind[Soeji++] = 1194;	//魔王城門
	mapdata->mapNGKind[Soeji++] = 1195;	//魔王城門

	mapdata->mapNGKind[Soeji++] = 1171;	//魔王城
	mapdata->mapNGKind[Soeji++] = 1172;	//魔王城
	mapdata->mapNGKind[Soeji++] = 1203;	//魔王城
	mapdata->mapNGKind[Soeji++] = 1204;	//魔王城

	mapdata->mapNGKind[Soeji++] = 1124;	//川

	mapdata->mapNGKind[Soeji++] = 350;	//宝箱
	mapdata->mapNGKind[Soeji++] = 382;	//宝箱空き

	mapdata->mapNGKind[Soeji++] = 351;	//金の宝箱
	mapdata->mapNGKind[Soeji++] = 383;	//金の宝箱空き

	//通行できない種類の残りを-1で埋める
	for (int cnt = Soeji; cnt < GAME_MAP_NG_KIND; cnt++) { mapdata->mapNGKind[cnt] = -1; }

	//戦闘するマップの残りを-1で埋める
	Soeji = 0;
	for (int cnt = Soeji; cnt < GAME_MAP_BT_KIND; cnt++) { mapdata->mapBTKind[cnt] = -1; }

	return TRUE;
}

BOOL MY_MAP_READ_CSV_SITA_KIND_SET(MAPDATA *mapdata)
{
	int Soeji;


	Soeji = 0;
	mapdata->mapOKKind[Soeji++] = 0;	//緑のマップ
	mapdata->mapOKKind[Soeji++] = 1;	//草1
	mapdata->mapOKKind[Soeji++] = 152;	//岩
	mapdata->mapOKKind[Soeji++] = 314;	//魔王城
	mapdata->mapOKKind[Soeji++] = 616;	//池
	mapdata->mapOKKind[Soeji++] = 936;	//海


	
	for (int cnt = Soeji; cnt < GAME_MAP_OK_KIND; cnt++) { mapdata->mapOKKind[cnt] = -1; }

	
	Soeji = 0;
	for (int cnt = Soeji; cnt < GAME_MAP_NG_KIND; cnt++) { mapdata->mapNGKind[cnt] = -1; }

	
	

	
	for (int cnt = Soeji; cnt < GAME_MAP_BT_KIND; cnt++) { mapdata->mapBTKind[cnt] = -1; }

	return TRUE;
}


BOOL MY_MAP_READ_CSV_UE_KIND_SET(MAPDATA *mapdata)
{
	int Soeji;

	
	Soeji = 0;
	for (int cnt = Soeji; cnt < GAME_MAP_OK_KIND; cnt++) { mapdata->mapOKKind[cnt] = -1; }

	
	Soeji = 0;
	for (int cnt = Soeji; cnt < GAME_MAP_NG_KIND; cnt++) { mapdata->mapNGKind[cnt] = -1; }

	
	Soeji = 0;
	for (int cnt = Soeji; cnt < GAME_MAP_BT_KIND; cnt++) { mapdata->mapBTKind[cnt] = -1; }

	return TRUE;
}


BOOL MY_CHARA_LOAD_BUNKATSU(CHARAIMAGE *c, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char *path)
{
	int retLoad;

	//ファイルパスをコピー
	wsprintf(c->FilePath, path);

	//画像をメモリに分割して読み込み、ハンドルを取得
	retLoad = LoadDivGraph(c->FilePath, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, c->Handle);

	if (retLoad == -1) { return FALSE; }	

	for (int cnt = 0; cnt < GAME_MAP_BUN_YOKO_CNT*GAME_MAP_BUN_TATE_CNT; cnt++)
	{
		
		GetGraphSize(
			c->Handle[cnt],		
			&c->Width[cnt],		
			&c->Height[cnt]);				

		c->C_Width[cnt] = c->Width[cnt] / 2;			
		c->C_Height[cnt] = c->Height[cnt] / 2;			
	}

	return TRUE;
}


