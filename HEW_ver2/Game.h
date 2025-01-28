#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include"Object.h"
#include"testEnemy.h"
#include"input.h"
#include"sound.h"
#include "Player.h"


#define GAME_TITLE (101)
#define GAME_GAME (102)
#define GAME_CLEAR (103)
#define GAME_END (104)
//列挙型でシーン遷移
enum GameState
{
	TITLE,
	GAME,
	LAST,
	END
};

class Game {

private:
	Input input;

	Sound sound;
	

	Object  title;
	Object bg1;	//background

	Object clear_screen;
	Object game_over_screen;
	Object Player;

	Player player;

	TestEnemy testenemy;

	GameState State = TITLE;

public:

	Game() : State(TITLE) {}

	void Init(HWND hWnd);   //初期化
	void Update(void);
	void Draw(void);            //描画
	void Uninit(void);          //終了

	bool Box_Hit_judgment(Object, Object);
};