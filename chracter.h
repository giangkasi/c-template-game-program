#pragma once
#include<iostream>
#include<list>
#include"map.h"
//#include"scene.h"


class character
{
public:
	character();
	
	void toMove();
	void toView(int ,int);
	void view();

	void Compos();
	RECT PlayerRect;

	RECT goal;
	
	bool OnCollision(RECT,RECT);
private:

	
	int Handle[12];
	
	int Width;
	int Height;

	int X;
	int Y;

	int direction;
	bool moving;
	int Speed;
	int MoveDistX;
	int MoveDistY;

	int countAni;

	
};


