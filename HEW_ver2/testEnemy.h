#pragma once
#include"Object.h"

#include"t_bullet.h"


class TestEnemy :public Object
{
protected:

	//Advertisement ad;
	Test_Bullet eb;

	DirectX::XMFLOAT3 epos = { 0.0f,0.0f,0.0f };

	DirectX::XMFLOAT3 ebpos = { 0.0f,0.0f,0.0f };

	int aniCount = 0;
	int finish_Count = 0;
	DirectX::XMFLOAT2 ad_e = { 0,0 };
	DirectX::XMFLOAT2 link_e = { 0,0 };

	int probability_Count = 0;
public:

	void CharacterInit(void);
	void test_Update(DirectX::XMFLOAT3, DirectX::XMFLOAT3);
	void CharacterDraw(void);
	void Enemy_Action_Move(int);
	int probability(void);

	//エネミーの広告降らしのアニメーション---------------------------------
	DirectX::XMFLOAT2 Advertisement_raining_Animation();
	//---------------------------------------------------------------------
	//エネミーのリンク投げのアニメーション---------------------------------
	DirectX::XMFLOAT2 link_throwing_Animation();
	//---------------------------------------------------------------------
};