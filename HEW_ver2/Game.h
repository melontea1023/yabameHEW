#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include"Object.h"
#include"input.h"
#include "Player.h"
#include "Advertisement raining.h"
#include "testEnemy.h"
#include "sound.h"

#define GAME_TITLE (101)
#define GAME_GAME (102)
#define GAME_CLEAR (103)
#define GAME_END (104)
//列挙型でシーン遷移
enum GameState
{
	TITLE,
	GAME,
	LAST
};

class Game {

private:
	Input input;

	Sound sound;
	
	Object  title;
	Object bg1;	//background

	TestEnemy enemy;
	Player player;

	GameState State = TITLE;

public:

	Game() : State(TITLE) {}

	void Init(HWND hWnd);   //初期化
	void Update(void);
	void Draw(void);            //描画
	void Uninit(void);          //終了

	bool Box_Hit_judgment(Object, Object);
};