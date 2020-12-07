#include "chracter.h"

#define GAME_CHARA ".\\image\\chara.png"
#define MOVETIME 10
#define CELL_WIDTH 40
#define CELL_HEIGHT 40

character::character() {

	LoadDivGraph(GAME_CHARA, 12, 3, 4, 20, 28, Handle);
	GetGraphSize(Handle[0], &Width, &Height);
	X = 0;
	Y = 0;
    

	countAni = 0;

	direction = 2;
	moving = false;

	Speed = 1;
	MoveDistX = 0;
	MoveDistY = 0;

    
    PlayerRect.left = 0;
    PlayerRect.top =0;
    PlayerRect.right = 0;
    PlayerRect.bottom =0;

    goal.left=440;
    goal.top=440;
    goal.right=470;
    goal.bottom=470;
};
void character::toMove() {
    moving = false;

    if (MoveDistX == X && MoveDistY == Y) { //移動中でなければ
        if (CheckHitKey(KEY_INPUT_DOWN)) {
            moving = true;
            direction = 2;
            MoveDistY += CELL_HEIGHT;   
        }
        else if (CheckHitKey(KEY_INPUT_LEFT)) {
            moving = true;
            direction = 4;
            MoveDistX -= CELL_WIDTH;
        }
        else if (CheckHitKey(KEY_INPUT_RIGHT)) {
           moving = true;
            direction = 6;
            MoveDistX += CELL_WIDTH;
        }
        else if (CheckHitKey(KEY_INPUT_UP)) {
            moving = true;
            direction = 8;
            MoveDistY -= CELL_HEIGHT;
        }
        else {
            countAni = 0;//キーが押されておらず、移動が完了していればanimCountをリセット
        }
    }
    else {
        moving = true;
    }

    if (Y < MoveDistY) { Y += Speed;    
    PlayerRect.left = X + 40;
    PlayerRect.top = Y + 40;
    PlayerRect.right = X - 40;
    PlayerRect.bottom = Y - 40;
   // DrawBox(PlayerRect.left, PlayerRect.top, PlayerRect.right, PlayerRect.bottom, GetColor(255, 255, 0), TRUE);
    }
    if (X > MoveDistX) { X -= Speed;    
    PlayerRect.left = X + 40;
    PlayerRect.top = Y + 40;
    PlayerRect.right = X - 40;
    PlayerRect.bottom = Y - 40;
   // DrawBox(PlayerRect.left, PlayerRect.top, PlayerRect.right, PlayerRect.bottom, GetColor(255, 255, 0), TRUE);
    }
    if (X < MoveDistX) { X += Speed;   
    PlayerRect.left = X + 40;
    PlayerRect.top = Y + 40;
    PlayerRect.right = X - 40;
    PlayerRect.bottom = Y - 40;
   // DrawBox(PlayerRect.left, PlayerRect.top, PlayerRect.right, PlayerRect.bottom, GetColor(255, 255, 0), TRUE);
    }
    if (Y > MoveDistY ){Y -= Speed;  
    PlayerRect.left = X + 40;
    PlayerRect.top = Y + 40;
    PlayerRect.right = X - 40;
    PlayerRect.bottom = Y - 40; 
   // DrawBox(PlayerRect.left, PlayerRect.top, PlayerRect.right, PlayerRect.bottom, GetColor(255, 255, 0), TRUE);
    }
}


void character::toView(int DivnumNow,int first) {
	if (DivnumNow == 0)DrawExtendGraph(X, Y + Height / 2, X + Width * 2, Y + Height * 2 + Height / 2, Handle[first], TRUE);
	if (DivnumNow == 1)DrawExtendGraph(X, Y + Height / 2, X + Width * 2, Y + Height * 2 + Height / 2, Handle[first + 1], TRUE);
	if (DivnumNow == 2)DrawExtendGraph(X, Y + Height / 2, X + Width * 2, Y + Height * 2 + Height / 2, Handle[first + 2], TRUE);
	if (DivnumNow == 3)DrawExtendGraph(X, Y + Height / 2, X + Width * 2, Y + Height * 2 + Height / 2, Handle[first + 1], TRUE);
}


void character::view() {
    int DivnumNow = countAni / MOVETIME;//animCountがWALKTIMEの公倍数になるたびにanimStateが1増える

    if (DivnumNow == 4) {//animStateが4になったらリセット
        countAni = 0;
        DivnumNow = 0;
    }

    if (moving) {
        if (direction == 2)toView(DivnumNow, 0);
        if (direction == 4)toView(DivnumNow, 3);
        if (direction == 6)toView(DivnumNow, 6);
        if (direction == 8)toView(DivnumNow, 9);
        countAni++;
    }
    else {
        if (direction == 2)DrawExtendGraph(X, Y + Height / 2, X + Width * 2, Y + Height * 2 + Height / 2, Handle[1], TRUE);
        if (direction == 4)DrawExtendGraph(X, Y + Height / 2, X + Width * 2, Y + Height * 2 + Height / 2, Handle[4], TRUE);
        if (direction == 6)DrawExtendGraph(X, Y + Height / 2, X + Width * 2, Y + Height * 2 + Height / 2, Handle[7], TRUE);
        if (direction == 8)DrawExtendGraph(X, Y + Height / 2, X + Width * 2, Y + Height * 2 + Height / 2, Handle[10], TRUE);
    }
}

void character::Compos(){
    toMove();
    view();
}

bool character::OnCollision(RECT a,RECT b )
{
    if (a.left < b.right &&
        a.top < b.bottom &&
        a.right > b.left &&
        a.bottom > b.top)
    {
        return true;
    }
    return false;
}

