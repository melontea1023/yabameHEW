#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include"Object.h"
#include"input.h"
#include "Advertisement raining.h"

#define GAME_TITLE (101)
#define GAME_GAME (102)
#define GAME_CLEAR (103)
#define GAME_END (104)

class Game {

private:
	Input input;
	
	Object  title;
	Object bg1;	//background
	Player player;
	Advertisement adObject; // 広告オブジェクト
public:
	void Init(HWND hWnd);   //初期化
	void Update(void);
	void Draw(void);            //描画
	void Uninit(void);          //終了

	bool Box_Hit_judgment(Object, Object);
};