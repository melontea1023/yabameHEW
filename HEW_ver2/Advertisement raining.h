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

	bool Set_flg;//�L���~�炵�̍��W�ݒ��A�����čs���̂�h���t���O
	bool random_flg;//�����̊l����A�����čs���̂�h���t���O
	bool move_flg;
	bool m_flg;
	bool Check_flg = false;//�L���~�낵���쓮�������ǂ����̃t���O(�֐����N������ۂɎg�p)

	bool ad_end = false;
public:


	bool Running_flg = false;
	void AdReset();
	void Advertisement_raining_Init();
	void Advertisement_raining_Update(DirectX::XMFLOAT3);
	void Advertisement_raining_Draw();  //Draw�̒��̏����̈�ԉ�
	void Advertisement_raining_Uninit();

	int GetRandom();

	int AdvertisingLocation(DirectX::XMFLOAT3);
	void Advertisement_Attack_Set(int, DirectX::XMFLOAT3);
	void Advertisement_move(int);
	bool GetEndflg(void);
	void SetEndflg(bool);
};
