#pragma once
#include<iostream>

#include<algorithm>
#include"Object.h"
#include"input.h"

#define GAME_TITLE (101)
#define GAME_GAME (102)
#define GAME_CLEAR (103)
#define GAME_END (104)

class Game {

private:
	Input input;
	
	Object  title;
	Object bg1;	//background
	Object Player;



	

public:
	void Init(HWND hWnd);   //èâä˙âª
	void Update(void);
	void Draw(void);            //ï`âÊ
	void Uninit(void);          //èIóπ

	bool Box_Hit_judgment(Object, Object);
	bool Circle_Hit_judgment(Object, Object);
	

};