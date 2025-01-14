#pragma once

#include"Object.h"


class Advertisement :public Object
{
protected:


	DirectX::XMFLOAT3 now_p_pos = { 0.0f,0.0f,0.0f };

	int random;

	int time_count;

	bool Set_flg;
	bool random_flg;
	bool move_flg;
	bool m_flg;
public:

	void Advertisement_raining_Init();
	void Advertisement_raining_Update(DirectX::XMFLOAT3);
	void Advertisement_raining_Darw();  //Draw‚Ì’†‚Ìˆ—‚Ìˆê”Ô‰º
	void Advertisement_raining_Uninit();

	int GetRandom();

	int AdvertisingLocation(DirectX::XMFLOAT3);
	void Advertisement_Attack_Set(int);
	void Advertisement_move(int);
};
