#pragma once

#include"Object.h"

#define Ad_falling_pos_y (810)

#define testpos_y (360)


class Advertisement :public Object
{
protected:


	DirectX::XMFLOAT3 now_p_pos = { 0.0f,0.0f,0.0f };

	int random;
	int Advertisement_Type;
	int time_count;

	bool Set_flg;//広告降らしの座標設定を連続して行うのを防ぐフラグ
	bool random_flg;//乱数の獲得を連続して行うのを防ぐフラグ
	bool move_flg;
	bool m_flg;
	bool Check_flg = false;//広告降ろしが作動したかどうかのフラグ(関数が起動する際に使用)

	bool ad_end = false;
public:


	bool Running_flg = false;
	void AdReset();
	void Advertisement_raining_Init();
	void Advertisement_raining_Update(DirectX::XMFLOAT3);
	void Advertisement_raining_Draw();  //Drawの中の処理の一番下
	void Advertisement_raining_Uninit();

	int GetRandom();

	int AdvertisingLocation(DirectX::XMFLOAT3);
	void Advertisement_Attack_Set(int, DirectX::XMFLOAT3);
	void Advertisement_move(int);
	bool GetEndflg(void);
	void SetEndflg(bool);
};
