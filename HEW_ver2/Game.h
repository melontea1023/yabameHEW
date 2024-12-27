#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include"Object.h"
#include"input.h"







class Game {

private:
	Input input;
	


public:
	void Init(HWND hWnd);   //‰Šú‰»
	void Update(void);
	void Draw(void);            //•`‰æ
	void Uninit(void);          //I—¹

	bool Box_Hit_judgment(Object, Object);
	bool Circle_Hit_judgment(Object, Object);
	

};