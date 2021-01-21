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
	

	

	BOOL IsAlive;		//�����Ă��邩

	int gameEndKind;	//�Q�[���I���̏��

	int EndLV;			//�I�����_�ł�LV
	int EndHP;			//�I�����_�ł�HP
	int EndATK;			//�I�����_�ł�ATK
	int EndDEF;			//�I�����_�ł�DEF

};	//STRUCT_CHARADATA�\����






typedef STRUCT_IMAGE IMAGE;
typedef STRUCT_MAPDATA MAPDATA;
typedef STRUCT_CHARAIMAGE CHARAIMAGE;
typedef STRUCT_CHARADATA CHARADATA;


WNDPROC WndProc;						


char AllKeyState[256];			

int GameSceneNow = (int)GAME_SCENE_TITLE;


IMAGE Image_map;
MAPDATA mapData_sita;	//���̃}�b�v
MAPDATA mapData_naka;	//���̃}�b�v
MAPDATA mapData_ue;		//��̃}�b�v



IMAGE image_title;		//�^�C�g�����
IMAGE image_clear;		//�N���A���


int ScrollCntYoko = 0;	//�X�N���[���J�E���^(��)
int ScrollCntTate = 0;	//�X�N���[���J�E���^(�c)

CHARAIMAGE CharaImage;	//�L�����̉摜
CHARADATA	Myplayer;	//�L�����̃f�[�^


int PlayerImageNum[GAME_CHARA_MOTION_NUM];


RECT rectEndCon{ 100,100,300,500 };
RECT rectEndEnd{ 500,100,700,500 };


int EndConCnt = 0;
int EndConCntMAX = 120;

int EndEndCnt = 0;
int EndEndCntMAX = 120;

int MY_RANGE_RAND(int, int);	

int SceneBefore;	//�ȑO�̃V�[��
int SceneNext;		//���̃V�[��



				

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
	int IsLoad = FALSE;		//���y��摜�Ȃǂ�ǂݍ��߂����m�F����ϐ�

	ChangeWindowMode(TRUE);					//�E�B���h�E���[�h�ɐݒ�
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);			//�w��̐��l�ŉ�ʂ�\������

	

	

	if (DxLib_Init() == -1) { return -1; }						//�c�w���C�u��������������

	SetDrawScreen(DX_SCREEN_BACK);								//Draw�n�֐��͗���ʂɕ`��

	MY_MAP_READ_CSV_UE_KIND_SET(&mapData_ue);		//�}�b�v�̏�̎�ނ�ݒ�
	MY_MAP_READ_CSV_NAKA_KIND_SET(&mapData_naka);	//�}�b�v�̒��̎�ނ�ݒ�
	MY_MAP_READ_CSV_SITA_KIND_SET(&mapData_sita);	//�}�b�v�̉��̎�ނ�ݒ�

	MY_MAP_READ_CSV_NUM(&mapData_ue, GAME_MAP_CSV_1_UE, GAME_MAP_NAME_1_UE);		//�}�b�v�P�̏��ǂݍ��݁A�����蔻��̗̈�����
	MY_MAP_READ_CSV_NUM(&mapData_naka, GAME_MAP_CSV_1_NAKA, GAME_MAP_NAME_1_NAKA);	//�}�b�v�P�̒���ǂݍ��݁A�����蔻��̗̈�����
	MY_MAP_READ_CSV_NUM(&mapData_sita, GAME_MAP_CSV_1_SITA, GAME_MAP_NAME_1_SITA);	//�}�b�v�P�̉���ǂݍ��݁A�����蔻��̗̈�����

	if (MY_MAP_LOAD_BUNKATSU(&mapData_ue, GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT, GAME_MAP_BUN_YOKO_CNT, GAME_MAP_BUN_TATE_CNT, 32, 32, GAME_MAP_1_PATH) == FALSE) { MessageBox(NULL, GAME_MAP_1_PATH, "NotFound", MB_OK); return -1; }		//MAP��ǂݍ���
	if (MY_MAP_LOAD_BUNKATSU(&mapData_naka, GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT, GAME_MAP_BUN_YOKO_CNT, GAME_MAP_BUN_TATE_CNT, 32, 32, GAME_MAP_1_PATH) == FALSE) { MessageBox(NULL, GAME_MAP_1_PATH, "NotFound", MB_OK); return -1; }	//MAP��ǂݍ���
	if (MY_MAP_LOAD_BUNKATSU(&mapData_sita, GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT, GAME_MAP_BUN_YOKO_CNT, GAME_MAP_BUN_TATE_CNT, 32, 32, GAME_MAP_1_PATH) == FALSE) { MessageBox(NULL, GAME_MAP_1_PATH, "NotFound", MB_OK); return -1; }	//MAP��ǂݍ���

	if (MY_CHARA_LOAD_BUNKATSU(&CharaImage, GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT, GAME_CHARA_BUN_YOKO_CNT, GAME_CHARA_BUN_TATE_CNT, GAME_CHARA_YOKO_SIZE, GAME_CHARA_TATE_SIZE, GAME_CHARA) == FALSE) { MessageBox(NULL, GAME_CHARA, "NotFound", MB_OK); return -1; }	//GAME_CHARA_1��ǂݍ���

	
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


//########## �Q�[���Ŏg�p����A���y��摜�Ȃǂ�ǂݍ��ފ֐� ##########
BOOL MY_GAME_NOWLOADING(VOID)
{
	
	if (MY_LOAD_BACKGROUND(&image_title, GAME_TITLE_IMAGE) == FALSE) { MessageBox(NULL, GAME_TITLE_IMAGE, "NotFound", MB_OK); return FALSE; }				//IMAGE��ǂݍ���
	if (MY_LOAD_BACKGROUND(&image_clear, GAME_CLEAR_IMAGE) == FALSE) { MessageBox(NULL, GAME_CLEAR_IMAGE, "NotFound", MB_OK); return FALSE; }				//IMAGE��ǂݍ���
	

	return TRUE;
}

//########## �Q�[�����œǂݍ��񂾉摜�≹�y���폜����֐� ##########
VOID MY_GAME_DELETE(VOID)
{
	//�}�b�v�̃n���h�����폜
	for (int mapCnt = 0; mapCnt < GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT; mapCnt++)
	{
		DeleteGraph(mapData_ue.Handle[mapCnt]);
		DeleteGraph(mapData_sita.Handle[mapCnt]);
	}

	
	


	return;
}

//########## �Q�[���ł̖������[�v���̊֐� ##########
BOOL MY_GAME_IN_MUGENLOOP(VOID)
{
	if (ProcessMessage() != 0) { return FALSE; }	//���b�Z�[�W�����̌��ʂ��G���[�̂Ƃ��A�����I��

	if (ClearDrawScreen() != 0) { return FALSE; }	//��ʂ������ł��Ȃ������Ƃ��A�����I��

	MY_ALL_KEYDOWN_UPDATE();				//�L�[�̏�Ԃ��擾

	

	//�V�[���I��
	switch (GameSceneNow)
	{
	case (int)GAME_SCENE_TITLE:	//�^�C�g����ʂ̏�����������

		MY_GAME_TITLE();	//�^�C�g����ʂ̏���

		break;	//�^�C�g����ʂ̏��������܂�

	case (int)GAME_SCENE_PLAY:	//�v���C��ʂ̏�����������

		MY_GAME_PLAY();		//�v���C��ʂ̏���

		break;	//�v���C��ʂ̏��������܂�

	

	

	case (int)GAME_SCENE_END:	//�G���h��ʂ̏�����������

		MY_GAME_END();		//�G���h��ʂ̏���

		break;	//�G���h��ʂ̏��������܂�

	default:

		break;

	}

	

	

	ScreenFlip();		//���j�^�̃��t���b�V�����[�g�̑����ŗ���ʂ��ĕ`��

	

	return TRUE;
}

//########## FPS�l���v���A�X�V����֐� ##########

VOID MY_ALL_KEYDOWN_UPDATE(VOID)
{
	char TempKey[256];			//�ꎞ�I�ɁA���݂̃L�[�̓��͏�Ԃ��i�[����

	GetHitKeyStateAll(TempKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�

	for (int i = 0; i < 256; i++)
	{
		if (TempKey[i] != 0)	//������Ă���L�[�̃L�[�R�[�h�������Ă���Ƃ�
		{
			AllKeyState[i]++;	//������Ă���
		}
		else
		{
			AllKeyState[i] = 0;	//������Ă��Ȃ�
		}
	}
	return;
}

//########## �^�C�g����ʂ̊֐� ##########
VOID MY_GAME_TITLE(VOID)
{

	

	if (AllKeyState[KEY_INPUT_RETURN] != 0)	//�G���^�[�L�[��������Ă�����
	{
		if (MY_PLAY_INIT() == TRUE)		//�v���C��ʏ�����
		{
			GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		}
	}

	MY_GAME_TITLE_DRAW();	//�^�C�g����ʕ`��̊֐�

	return;
}

//########## �^�C�g����ʕ`��̊֐� ##########
VOID MY_GAME_TITLE_DRAW(VOID)
{
	DrawGraph(0, 0, image_title.Handle[0], TRUE);

	
	DrawString(0, 0, "�X�^�[�g���(�G���^�[�L�[�������ĉ�����)", GetColor(255, 255, 255));

	return;
}

//########## �������֐� ##########
BOOL MY_PLAY_INIT(VOID)
{
	ScrollCntYoko = 0;
	ScrollCntTate = 0;

	//�v���C���[�̉摜�̔ԍ���ݒ�
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

	//�v���C���[��������
	if (MY_PLAYER_INIT(&Myplayer, CharaImage, &PlayerImageNum[0], GAME_MAP_YOKO_SIZE * GAME_CHARA_STARTX, GAME_MAP_TATE_SIZE * GAME_CHARA_STARTY, GAME_CHARA_SPEED) == FALSE) { MessageBox(NULL, "CHARA_INIT", "NotFound", MB_OK); return FALSE; }

	

	

	return TRUE;
}

//########## �v���C��ʂ̊֐� ##########
VOID MY_GAME_PLAY(VOID)
{

	MY_PLAY_PLAYER_OPERATION();		//�v���C���[�𑀍삷��



	MY_GAME_PLAY_DRAW();	//�v���C��ʕ`��
	if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�G���^�[�L�[��������Ă�����
	{
		
			GameSceneNow = (int)GAME_SCENE_END;	//�V�[�����v���C��ʂɂ���
		
	}

	return;
}

// ########## �v���C��ʕ`��̊֐� ##########
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
	//*(num + 0)�͔z��̐擪�A�h���X

	for (int mot = 0; mot < GAME_CHARA_MOTION_NUM; mot++)
	{
		charadata->Handle[mot] = charaimage.Handle[*(num + mot)];	//�摜�̃n���h��������
	}

	charadata->X = x;
	charadata->Y = y;
	charadata->Width = charaimage.Width[*(num + 0)];		//�ŏ��̉摜�̉�����ݒ肷��
	charadata->Height = charaimage.Height[*(num + 0)];		//�ŏ��̉摜�̍�����ݒ肷��
	charadata->C_Width = charaimage.C_Width[*(num + 0)];	//�ŏ��̉摜�̉����̒��S��ݒ肷��
	charadata->C_Height = charaimage.C_Height[*(num + 0)];	//�ŏ��̉摜�̍����̒��S��ݒ肷��

	//�}�b�v�ЂƂ�����Ɠ����傫���ɂ���
	charadata->Width = GAME_MAP_YOKO_SIZE;
	charadata->Height = GAME_MAP_TATE_SIZE;
	charadata->C_Width = GAME_MAP_YOKO_SIZE / 2;
	charadata->C_Height = GAME_MAP_TATE_SIZE / 2;

	charadata->NowHandleNum = 6;	//�O�����̍ŏ��̉摜
	charadata->NowHandleCnt = 0;	//�摜�J�E���^��������

	charadata->NowHandleCntMAX = 6;	//�摜�J�E���^MAX��������

	
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

	//�G�̎�ނ͂Ȃ�

	wsprintf(charadata->name, "AAA");	//���O��ݒ�

	charadata->LV = charadata->HP_MAX = GAME_PLAYER_LV_FIRST;			//�v���C���[�̍ŏ���LV
	charadata->HP = charadata->HP_MAX = GAME_PLAYER_HP_FIRST;			//�v���C���[�̍ŏ���HP
	charadata->ATK = charadata->ATK_MAX = GAME_PLAYER_ATK_FIRST;		//�v���C���[�̍ŏ���ATK
	charadata->DEF = charadata->DEF_MAX = GAME_PLAYER_DEF_FIRST;		//�v���C���[�̍ŏ���DEF
	charadata->EXP = GAME_PLAYER_EXP_FIRST;								//�v���C���[�̍ŏ���EXP

	
	charadata->IsAlive = TRUE;			//�����Ă���

	

	charadata->gameEndKind = (int)GAME_END_KIND_NONE;

	

	MY_SET_PLAYER_ATARI(charadata);	//�v���C���[�̓����蔻��̗̈��ݒ肷��

	return TRUE;
}

//########## �v���C���[�𑀍삷��֐� ##########

VOID MY_PLAY_PLAYER_OPERATION(VOID)
{
	int retAtariX = 0; int retAtariY = 0;	//�������Ă���}�b�v�̏ꏊ

	BOOL IsKeyDown = MY_PLAY_PLAYER_OPERATION_KEY(&retAtariX, &retAtariY);	//�L�[�������đ��삵�Ă��邩���f

	


	return;
}
//########## �v���C���[�𑀍삷��(�L�[����)�֐� ##########
BOOL MY_PLAY_PLAYER_OPERATION_KEY(int *x, int *y)
{
	BOOL IsKeyDown = FALSE;		//�L�[�������ꂽ��

	if (AllKeyState[KEY_INPUT_LEFT] != 0)	//�����L�[��������Ă�����
	{
		IsKeyDown = TRUE;	//�L�[�������ꂽ

		Myplayer.CanMoveLeft = TRUE;	//�������ɁA�܂�������

		MY_SET_PLAYER_ATARI(&Myplayer);	//�v���C���[�̓����蔻��̗̈��ݒ�
		Myplayer.atariRect.left -= 4;	//�����A�����蔻��̗̈�����ɂ��炷
		Myplayer.atariRect.right -= 4;	//�����A�����蔻��̗̈�����ɂ��炷

		if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_naka.rect_NG, x, y) == TRUE)	//���ɍs���Ȃ����m�Ɠ��������Ƃ�
		{
			Myplayer.CanMoveLeft = FALSE;	//���ɍs���Ȃ�
		}

		if (Myplayer.CanMoveLeft == TRUE)	//���Ɉړ��ł���Ƃ�
		{
			if (Myplayer.ScrollOK_X == FALSE)	//�X�N���[���ł��Ȃ��Ƃ�
			{
				if (Myplayer.X > 0)
				{
					Myplayer.X -= Myplayer.Speed;	//�v���C���[�����Ɉړ�
				}
			}
			else	//�X�N���[���ł���Ƃ�
			{
				if (ScrollCntYoko > 0)	//�}�b�v�O�փX�N���[�����Ȃ�
				{
					ScrollCntYoko -= Myplayer.Speed;	//��ʂ����ɃX�N���[��
				}
			}

			if (Myplayer.MoveDistX > 0)
			{
				Myplayer.MoveDistX -= Myplayer.Speed;	//�������������v�Z
			}
		}

	}

	if (AllKeyState[KEY_INPUT_RIGHT] != 0)	//�E���L�[��������Ă�����
	{
		IsKeyDown = TRUE;	//�L�[�������ꂽ

		Myplayer.CanMoveRight = TRUE;	//�E�����ɁA�܂�������

		MY_SET_PLAYER_ATARI(&Myplayer);	//�v���C���[�̓����蔻��̗̈��ݒ�
		Myplayer.atariRect.left += 4;	//�����A�v���C���[�̓����蔻��̗̈���E�ɂ��炷
		Myplayer.atariRect.right += 4;	//�����A�v���C���[�̓����蔻��̗̈���E�ɂ��炷

		if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_naka.rect_NG, x, y) == TRUE)	//�E�ɍs���Ȃ����m�Ɠ��������Ƃ�
		{
			Myplayer.CanMoveRight = FALSE;	//�E�ɍs���Ȃ�
		}

		if (Myplayer.CanMoveRight == TRUE)	//�E�Ɉړ��ł���Ƃ�
		{
			if (Myplayer.ScrollOK_X == FALSE)	//�v���C���[��������Ƃ�
			{
				if (Myplayer.X + Myplayer.Width < GAME_WIDTH)
				{
					Myplayer.X += Myplayer.Speed;			//�v���C���[���E�Ɉړ�
				}
			}
			else	//�v���C���[�������Ȃ��Ƃ�
			{
				if (ScrollCntYoko < GAME_MAP_YOKO_SIZE * GAME_MAP_YOKO)	//��ʊO�փX�N���[�����Ȃ�
				{
					ScrollCntYoko += Myplayer.Speed;	//��ʂ��E�ɃX�N���[��
				}
			}

			if (Myplayer.MoveDistX < GAME_MAP_YOKO_SIZE * GAME_MAP_YOKO)
			{
				Myplayer.MoveDistX += Myplayer.Speed;	//�������������v�Z
			}
		}
	}

	if (AllKeyState[KEY_INPUT_UP] != 0)	//����L�[��������Ă�����
	{
		IsKeyDown = TRUE;	//�L�[�������ꂽ

		Myplayer.CanMoveUp = TRUE;	//������ɁA�܂�������

		MY_SET_PLAYER_ATARI(&Myplayer);	//�v���C���[�̓����蔻��̗̈��ݒ�
		Myplayer.atariRect.top -= 4;	//�����A�����蔻��̗̈����ɂ��炷
		Myplayer.atariRect.bottom -= 4;	//�����A�����蔻��̗̈����ɂ��炷

		if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_naka.rect_NG, x, y) == TRUE)	//��ɍs���Ȃ����m�Ɠ��������Ƃ�
		{
			Myplayer.CanMoveUp = FALSE;	//��ɍs���Ȃ�
		}

		if (Myplayer.CanMoveUp == TRUE)	//��Ɉړ��ł���Ƃ�
		{
			if (Myplayer.ScrollOK_Y == FALSE)	//�v���C���[��������Ƃ�
			{
				if (Myplayer.Y > 0)
				{
					Myplayer.Y -= Myplayer.Speed;	//�v���C���[����Ɉړ�
				}
			}
			else	//�X�N���[���ł���Ƃ�
			{
				if (ScrollCntTate > 0)	//�}�b�v�O�փX�N���[�����Ȃ�
				{
					ScrollCntTate -= Myplayer.Speed;	//��ʂ���ɃX�N���[��
				}
			}

			if (Myplayer.MoveDistY > 0)
			{
				Myplayer.MoveDistY -= Myplayer.Speed;	//�������������v�Z
			}
		}
	}

	if (AllKeyState[KEY_INPUT_DOWN] != 0)	//�����L�[��������Ă�����
	{
		IsKeyDown = TRUE;	//�L�[�������ꂽ

		Myplayer.CanMoveDown = TRUE;	//�������ɁA�܂�������

		MY_SET_PLAYER_ATARI(&Myplayer);	//�v���C���[�̓����蔻��̗̈��ݒ�
		Myplayer.atariRect.top += 4;	//�����A�v���C���[�̓����蔻��̗̈�����ɂ��炷
		Myplayer.atariRect.bottom += 4;	//�����A�v���C���[�̓����蔻��̗̈�����ɂ��炷

		if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_naka.rect_NG, x, y) == TRUE)	//���ɍs���Ȃ����m�Ɠ��������Ƃ�
		{
			Myplayer.CanMoveDown = FALSE;	//���ɍs���Ȃ�
		}

		if (Myplayer.CanMoveDown == TRUE)	//���Ɉړ��ł���Ƃ�
		{
			if (Myplayer.ScrollOK_Y == FALSE)	//�v���C���[��������Ƃ�
			{
				if (Myplayer.Y + Myplayer.Width < GAME_HEIGHT)
				{
					Myplayer.Y += Myplayer.Speed;			//�v���C���[�����Ɉړ�
				}
			}
			else	//�v���C���[�������Ȃ��Ƃ�
			{
				if (ScrollCntTate < GAME_MAP_TATE_SIZE * GAME_MAP_TATE)	//��ʊO�փX�N���[�����Ȃ�
				{
					ScrollCntTate += Myplayer.Speed;	//��ʉ��ɃX�N���[��
				}
			}

			if (Myplayer.MoveDistY < GAME_MAP_TATE_SIZE * (GAME_MAP_TATE - 1))
			{
				Myplayer.MoveDistY += Myplayer.Speed;	//�������������v�Z
			}
		}
	}

	//�}�b�v�̍����ɂ���Ƃ��́A�v���C���[�𓮂���
	if (Myplayer.MoveDistX > 0 &&
		Myplayer.MoveDistX <= GAME_MAP_YOKO_SIZE * 10)	//�v���C���[�̓��������������ȏ゠���(�J�n�n�_)
	{
		Myplayer.ScrollOK_X = FALSE;					//�}�b�v���~�߂āA�v���C���[�𓮂���
	}

	//�}�b�v�^�񒆂�ւ�ɂ���Ƃ��́A�}�b�v�𓮂���
	if (Myplayer.MoveDistX > GAME_MAP_YOKO_SIZE * 10 &&
		Myplayer.MoveDistX <= GAME_MAP_YOKO_SIZE * (GAME_MAP_YOKO - 15))	//�v���C���[�̓��������������ȏ゠���(�J�n�n�_)
	{
		Myplayer.ScrollOK_X = TRUE;					//�}�b�v�𓮂���
	}

	//�}�b�v�̉E���ɂ���Ƃ��́A�v���C���[�𓮂���
	if (Myplayer.MoveDistX > GAME_MAP_YOKO_SIZE * (GAME_MAP_YOKO - 15) &&
		Myplayer.MoveDistX <= GAME_MAP_YOKO_SIZE * GAME_MAP_YOKO)	//�v���C���[�̓��������������ȏ゠���(�I���n�_)
	{
		Myplayer.ScrollOK_X = FALSE;					//�}�b�v���~�߂āA�v���C���[�𓮂���
	}

	//�}�b�v�̏㑤�ɂ���Ƃ��́A�v���C���[�𓮂���
	if (Myplayer.MoveDistY > 0 &&
		Myplayer.MoveDistY <= GAME_MAP_TATE_SIZE * 10)	//�v���C���[�̓��������������ȏ゠���(�J�n�n�_)
	{
		Myplayer.ScrollOK_Y = FALSE;					//�}�b�v���~�߂āA�v���C���[�𓮂���
	}

	//�}�b�v�^�񒆂�ւ�ɂ���Ƃ��́A�}�b�v�𓮂���
	if (Myplayer.MoveDistY > GAME_MAP_TATE_SIZE * 10 &&
		Myplayer.MoveDistY <= GAME_MAP_TATE_SIZE * (GAME_MAP_TATE - 9))	//�v���C���[�̓��������������ȏ゠���(�J�n�n�_)
	{
		Myplayer.ScrollOK_Y = TRUE;					//�}�b�v�𓮂���
	}

	//�}�b�v�̉����ɂ���Ƃ��́A�v���C���[�𓮂���
	if (Myplayer.MoveDistY > GAME_MAP_TATE_SIZE * (GAME_MAP_TATE - 9) &&
		Myplayer.MoveDistY <= GAME_MAP_TATE_SIZE * GAME_MAP_TATE)	//�v���C���[�̓��������������ȏ゠���(�I���n�_)
	{
		Myplayer.ScrollOK_Y = FALSE;	//�}�b�v���~�߂āA�v���C���[�𓮂���
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
				*atariY = tate;	//atariY�̃A�h���X���w��������̏ꏊ�ɁA�����������m�̏c�̈ʒu������
				*atariX = yoko;	//atariX�̃A�h���X���w��������̏ꏊ�ɁA�����������m�̉��̈ʒu������

				return TRUE;
			}
		}
	}

	return FALSE;		//�������Ă��Ȃ�
}

//########## �̈�̓����蔻�������֐� ##########
BOOL MY_CHECK_RECT_ATARI(RECT a, RECT b)
{
	if (a.left < b.right &&
		a.top < b.bottom &&
		a.right > b.left &&
		a.bottom > b.top
		)
	{
		return TRUE;	//�������Ă���
	}

	return FALSE;		//�������Ă��Ȃ�
}

//########## �v���C���[�̓����蔻��̗̈��ݒ肷��֐� ##########
VOID MY_SET_PLAYER_ATARI(CHARADATA *charadata)
{
	//�����蔻��̗̈�̐ݒ�
	charadata->atariRect.left = charadata->X + charadata->atariX + 2;						//���݂�X�ʒu �{ �����蔻���X�ʒu
	charadata->atariRect.top = charadata->Y + charadata->atariY + 2;						//���݂�Y�ʒu �{ �����蔻���Y�ʒu
	charadata->atariRect.right = charadata->X + charadata->atariX + charadata->atariWidth - 2;		//���݂�X�ʒu �{ �����蔻���X�ʒu �{ �����蔻��̕�
	charadata->atariRect.bottom = charadata->Y + charadata->atariY + charadata->atariHeight - 2;	//���݂�Y�ʒu �{ �����蔻���Y�ʒu �{ �����蔻��̍���

	return;
}

//########## �v���C���[��\������֐� ##########
VOID MY_PLAY_PLAYER_DRAW(CHARADATA player)
{
	//�v���C���[��`��
	DrawGraph(
		player.X,
		player.Y,
		player.Handle[player.NowHandleNum], TRUE);


	if (AllKeyState[KEY_INPUT_LEFT] != 0)	//�����L�[��������Ă�����
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
				Myplayer.NowHandleNum++;	//���̍������̉摜
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
	//�X�N���[������}�b�v��`��
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			if ((yoko + 1) * GAME_MAP_YOKO_SIZE - ScrollCntYoko >= 0 &&
				(yoko + 0) * GAME_MAP_YOKO_SIZE - ScrollCntYoko <= GAME_WIDTH &&
				(tate + 1) * GAME_MAP_TATE_SIZE - ScrollCntTate >= 0 &&
				(tate + 0) * GAME_MAP_TATE_SIZE - ScrollCntTate <= GAME_HEIGHT
				)	//��ʂɎʂ��Ă���Ȃ�΂Ȃ��
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
	//�X�N���[������}�b�v��`��
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
		case (int)GAME_SCENE_TITLE:	//�^�C�g�����

			MY_GAME_TITLE_DRAW();	//�^�C�g����ʕ`��

			break;

		case (int)GAME_SCENE_PLAY:	//�v���C���

			MY_GAME_PLAY_DRAW();	//�v���C��ʕ`��

			break;


		case (int)GAME_SCENE_END:	//�G���h���

			MY_GAME_END_DRAW();		//�G���h���

			break;

		default:

			break;

		}

		
	return FALSE;
}








VOID MY_GAME_END(VOID)
{


		if (AllKeyState[KEY_INPUT_ESCAPE] != 0)	//�X�y�[�X�L�[��������Ă�����
		{
			GameSceneNow = (int)GAME_SCENE_TITLE;	//�V�[�����^�C�g����ʂɂ���
		}

	

	MY_GAME_END_DRAW();	

	return;
}

VOID MY_GAME_END_DRAW(VOID)
{
	char clear[64] = { "GAME CLEAR" };
	
	

	DrawStringToHandle(0, 0, "�G���h���", GetColor(255, 255, 255), 30);

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
	mapdata->mapOKKind[Soeji++] = 30;	//��
	mapdata->mapOKKind[Soeji++] = 1081;	//�b�̓�
	mapdata->mapOKKind[Soeji++] = 1145;	//�{�̓�
	mapdata->mapOKKind[Soeji++] = 1113;	//�|�̓�
	mapdata->mapOKKind[Soeji++] = 18;	//��

	mapdata->mapOKKind[Soeji++] = 160;	//�t���
	mapdata->mapOKKind[Soeji++] = 161;	//�t���
	mapdata->mapOKKind[Soeji++] = 162;	//�t���
	mapdata->mapOKKind[Soeji++] = 163;	//�t���
	mapdata->mapOKKind[Soeji++] = 192;	//�t���
	mapdata->mapOKKind[Soeji++] = 193;	//�t���
	mapdata->mapOKKind[Soeji++] = 194;	//�t���
	mapdata->mapOKKind[Soeji++] = 195;	//�t���
	mapdata->mapOKKind[Soeji++] = 224;	//�t���
	mapdata->mapOKKind[Soeji++] = 225;	//�t���
	mapdata->mapOKKind[Soeji++] = 226;	//�t���
	mapdata->mapOKKind[Soeji++] = 227;	//�t���
	mapdata->mapOKKind[Soeji++] = 256;	//�t���
	mapdata->mapOKKind[Soeji++] = 259;	//�t���

	mapdata->mapOKKind[Soeji++] = 164;	//�đ��
	mapdata->mapOKKind[Soeji++] = 165;	//�đ��
	mapdata->mapOKKind[Soeji++] = 166;	//�đ��
	mapdata->mapOKKind[Soeji++] = 167;	//�đ��
	mapdata->mapOKKind[Soeji++] = 196;	//�đ��
	mapdata->mapOKKind[Soeji++] = 197;	//�đ��
	mapdata->mapOKKind[Soeji++] = 198;	//�đ��
	mapdata->mapOKKind[Soeji++] = 199;	//�đ��
	mapdata->mapOKKind[Soeji++] = 228;	//�đ��
	mapdata->mapOKKind[Soeji++] = 229;	//�đ��
	mapdata->mapOKKind[Soeji++] = 230;	//�đ��
	mapdata->mapOKKind[Soeji++] = 231;	//�đ��
	mapdata->mapOKKind[Soeji++] = 260;	//�đ��
	mapdata->mapOKKind[Soeji++] = 263;	//�đ��

	mapdata->mapOKKind[Soeji++] = 288;	//�H���
	mapdata->mapOKKind[Soeji++] = 289;	//�H���
	mapdata->mapOKKind[Soeji++] = 290;	//�H���
	mapdata->mapOKKind[Soeji++] = 291;	//�H���
	mapdata->mapOKKind[Soeji++] = 320;	//�H���
	mapdata->mapOKKind[Soeji++] = 321;	//�H���
	mapdata->mapOKKind[Soeji++] = 322;	//�H���
	mapdata->mapOKKind[Soeji++] = 323;	//�H���
	mapdata->mapOKKind[Soeji++] = 352;	//�H���
	mapdata->mapOKKind[Soeji++] = 353;	//�H���
	mapdata->mapOKKind[Soeji++] = 354;	//�H���
	mapdata->mapOKKind[Soeji++] = 355;	//�H���
	mapdata->mapOKKind[Soeji++] = 384;	//�H���
	mapdata->mapOKKind[Soeji++] = 387;	//�H���

	mapdata->mapOKKind[Soeji++] = 292;	//�~���
	mapdata->mapOKKind[Soeji++] = 293;	//�~���
	mapdata->mapOKKind[Soeji++] = 294;	//�~���
	mapdata->mapOKKind[Soeji++] = 295;	//�~���
	mapdata->mapOKKind[Soeji++] = 324;	//�~���
	mapdata->mapOKKind[Soeji++] = 325;	//�~���
	mapdata->mapOKKind[Soeji++] = 326;	//�~���
	mapdata->mapOKKind[Soeji++] = 327;	//�~���
	mapdata->mapOKKind[Soeji++] = 356;	//�~���
	mapdata->mapOKKind[Soeji++] = 357;	//�~���
	mapdata->mapOKKind[Soeji++] = 358;	//�~���
	mapdata->mapOKKind[Soeji++] = 359;	//�~���
	mapdata->mapOKKind[Soeji++] = 388;	//�~���
	mapdata->mapOKKind[Soeji++] = 391;	//�~���
	mapdata->mapOKKind[Soeji++] = 12;	//��
	mapdata->mapOKKind[Soeji++] = 801;	//����
	mapdata->mapOKKind[Soeji++] = 768;	//����

	mapdata->mapOKKind[Soeji++] = 1219;	//�@�̉�
	mapdata->mapOKKind[Soeji++] = 1173;	//�s�T�̎Γ���

	mapdata->mapOKKind[Soeji++] = 466;	//���ĊŔ���
	mapdata->mapOKKind[Soeji++] = 467;	//���ĊŔE��

	mapdata->mapOKKind[Soeji++] = 82;	//������

	mapdata->mapOKKind[Soeji++] = 1188;	//��
	mapdata->mapOKKind[Soeji++] = 1188;	//��
	mapdata->mapOKKind[Soeji++] = 1188;	//��
	mapdata->mapOKKind[Soeji++] = 1186;	//��
	mapdata->mapOKKind[Soeji++] = 1190;	//��
	mapdata->mapOKKind[Soeji++] = 1191;	//��

	mapdata->mapOKKind[Soeji++] = 17;	

	
	for (int cnt = Soeji; cnt < GAME_MAP_OK_KIND; cnt++) { mapdata->mapOKKind[cnt] = -1; }

	
	Soeji = 0;
	mapdata->mapNGKind[Soeji++] = 1136;	//��
	mapdata->mapNGKind[Soeji++] = 1105;	//��
	mapdata->mapNGKind[Soeji++] = 1106;	//�ƍ�
	mapdata->mapNGKind[Soeji++] = 1200;	//�ƉE
	mapdata->mapNGKind[Soeji++] = 1169;	//���@��
	mapdata->mapNGKind[Soeji++] = 1170;	//���@�E

	mapdata->mapNGKind[Soeji++] = 34;	//���؉�
	mapdata->mapNGKind[Soeji++] = 35;	//���؉�
	mapdata->mapNGKind[Soeji++] = 98;	//���؉�
	mapdata->mapNGKind[Soeji++] = 99;	//���؉�
	mapdata->mapNGKind[Soeji++] = 66;	//���؉�
	mapdata->mapNGKind[Soeji++] = 67;	//���؉�

	mapdata->mapNGKind[Soeji++] = 945;	//����
	mapdata->mapNGKind[Soeji++] = 946;	//����

	mapdata->mapNGKind[Soeji++] = 257;	//�t���
	mapdata->mapNGKind[Soeji++] = 258;	//�t���
	mapdata->mapNGKind[Soeji++] = 261;	//�đ��
	mapdata->mapNGKind[Soeji++] = 262;	//�đ��
	mapdata->mapNGKind[Soeji++] = 385;	//�H���
	mapdata->mapNGKind[Soeji++] = 386;	//�H���
	mapdata->mapNGKind[Soeji++] = 389;	//�~���
	mapdata->mapNGKind[Soeji++] = 390;	//�~���
	mapdata->mapNGKind[Soeji++] = 1088;	//�t���
	mapdata->mapNGKind[Soeji++] = 1089;	//�đ��
	mapdata->mapNGKind[Soeji++] = 1090;	//�H���
	mapdata->mapNGKind[Soeji++] = 1091;	//�~���

	mapdata->mapNGKind[Soeji++] = 432;	//�؊Ŕ�

	mapdata->mapNGKind[Soeji++] = 448;	//�r
	mapdata->mapNGKind[Soeji++] = 480;	//�r
	mapdata->mapNGKind[Soeji++] = 512;	//�r
	mapdata->mapNGKind[Soeji++] = 544;	//�r
	mapdata->mapNGKind[Soeji++] = 450;	//�r
	mapdata->mapNGKind[Soeji++] = 482;	//�r
	mapdata->mapNGKind[Soeji++] = 513;	//�r
	mapdata->mapNGKind[Soeji++] = 546;	//�r
	mapdata->mapNGKind[Soeji++] = 481;	//�r
	mapdata->mapNGKind[Soeji++] = 513;	//�r
	mapdata->mapNGKind[Soeji++] = 545;	//�r
	mapdata->mapNGKind[Soeji++] = 616;

	mapdata->mapNGKind[Soeji++] = 1040;	//�R
	mapdata->mapNGKind[Soeji++] = 1041;	//�R
	mapdata->mapNGKind[Soeji++] = 1042;	//�R
	mapdata->mapNGKind[Soeji++] = 1043;	//�R
	mapdata->mapNGKind[Soeji++] = 1072;	//�R
	mapdata->mapNGKind[Soeji++] = 1073;	//�R
	mapdata->mapNGKind[Soeji++] = 1074;	//�R
	mapdata->mapNGKind[Soeji++] = 1075;	//�R

	mapdata->mapNGKind[Soeji++] = 1128;

	mapdata->mapNGKind[Soeji++] = 1137;	//���@������
	mapdata->mapNGKind[Soeji++] = 1138;	//���@�����E

	mapdata->mapNGKind[Soeji++] = 1168;	//�w�Z
	mapdata->mapNGKind[Soeji++] = 1200;	//�s���~�b�h
	mapdata->mapNGKind[Soeji++] = 1233;	//�s���~�b�h
	mapdata->mapNGKind[Soeji++] = 1202;	//�Ɗ�
	mapdata->mapNGKind[Soeji++] = 1232;	//�ƈ��
	mapdata->mapNGKind[Soeji++] = 1234;	//�ƈ��
	mapdata->mapNGKind[Soeji++] = 1205;	//�s�T�̎Γ���

	mapdata->mapNGKind[Soeji++] = 498;	//���ĊŔ���
	mapdata->mapNGKind[Soeji++] = 499;	//���ĊŔE��

	mapdata->mapNGKind[Soeji++] = 1260;	//��
	mapdata->mapNGKind[Soeji++] = 1288;	//��
	mapdata->mapNGKind[Soeji++] = 1289;	//��
	mapdata->mapNGKind[Soeji++] = 1290;	//��
	mapdata->mapNGKind[Soeji++] = 1291;	//��
	mapdata->mapNGKind[Soeji++] = 1292;	//��
	mapdata->mapNGKind[Soeji++] = 1256;	//��
	mapdata->mapNGKind[Soeji++] = 1258;	//��
	mapdata->mapNGKind[Soeji++] = 1259;	//��
	mapdata->mapNGKind[Soeji++] = 1294;	//��
	mapdata->mapNGKind[Soeji++] =839;

	mapdata->mapNGKind[Soeji++] = 542;	//��
	mapdata->mapNGKind[Soeji++] = 543;	//��
	mapdata->mapNGKind[Soeji++] = 574;	//��
	mapdata->mapNGKind[Soeji++] = 575;	//��
	mapdata->mapNGKind[Soeji++] = 606;	//��
	mapdata->mapNGKind[Soeji++] = 607;	//��

	mapdata->mapNGKind[Soeji++] = 1284;	//���Ƃ�����
	mapdata->mapNGKind[Soeji++] = 1285;	//���Ƃ�����

	mapdata->mapNGKind[Soeji++] = 1107;	//��������
	mapdata->mapNGKind[Soeji++] = 1108;	//��������
	mapdata->mapNGKind[Soeji++] = 1139;	//��������
	mapdata->mapNGKind[Soeji++] = 1140;	//��������

	mapdata->mapNGKind[Soeji++] = 1194;	//�������
	mapdata->mapNGKind[Soeji++] = 1195;	//�������

	mapdata->mapNGKind[Soeji++] = 1171;	//������
	mapdata->mapNGKind[Soeji++] = 1172;	//������
	mapdata->mapNGKind[Soeji++] = 1203;	//������
	mapdata->mapNGKind[Soeji++] = 1204;	//������

	mapdata->mapNGKind[Soeji++] = 1124;	//��

	mapdata->mapNGKind[Soeji++] = 350;	//��
	mapdata->mapNGKind[Soeji++] = 382;	//�󔠋�

	mapdata->mapNGKind[Soeji++] = 351;	//���̕�
	mapdata->mapNGKind[Soeji++] = 383;	//���̕󔠋�

	//�ʍs�ł��Ȃ���ނ̎c���-1�Ŗ��߂�
	for (int cnt = Soeji; cnt < GAME_MAP_NG_KIND; cnt++) { mapdata->mapNGKind[cnt] = -1; }

	//�퓬����}�b�v�̎c���-1�Ŗ��߂�
	Soeji = 0;
	for (int cnt = Soeji; cnt < GAME_MAP_BT_KIND; cnt++) { mapdata->mapBTKind[cnt] = -1; }

	return TRUE;
}

BOOL MY_MAP_READ_CSV_SITA_KIND_SET(MAPDATA *mapdata)
{
	int Soeji;


	Soeji = 0;
	mapdata->mapOKKind[Soeji++] = 0;	//�΂̃}�b�v
	mapdata->mapOKKind[Soeji++] = 1;	//��1
	mapdata->mapOKKind[Soeji++] = 152;	//��
	mapdata->mapOKKind[Soeji++] = 314;	//������
	mapdata->mapOKKind[Soeji++] = 616;	//�r
	mapdata->mapOKKind[Soeji++] = 936;	//�C


	
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

	//�t�@�C���p�X���R�s�[
	wsprintf(c->FilePath, path);

	//�摜���������ɕ������ēǂݍ��݁A�n���h�����擾
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


