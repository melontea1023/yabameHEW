#pragma once
#include"Object.h"
#include"Advertisement raining.h"
#include"t_bullet.h"


class TestEnemy :public Object
{
protected:

	Advertisement ad;
	Test_Bullet eb;

	DirectX::XMFLOAT3 epos = { 0.0f,0.0f,0.0f };

	DirectX::XMFLOAT3 ebpos = { 0.0f,0.0f,0.0f };

	DirectX::XMFLOAT2 Set_E = { 0.0f,0.0f };

	int aniCount = 0;
	int finish_Count = 0;
	DirectX::XMFLOAT2 ad_e = { 0,0 };
	DirectX::XMFLOAT2 link_e = { 0,0 };

	int probability_Count = 0;

	bool Ad_Animation_end_flg = false;; //�L���~�炵�A�j���[�V�������I��������ǂ����̊m�F
	bool Ed_Animation_end_flg = false;; //�����N�����A�j���[�V�������I��������ǂ����̊m�F
public:

	void CharacterInit(void);
	void test_Update(DirectX::XMFLOAT3, DirectX::XMFLOAT3);
	void CharacterDraw(void);
	void Enemy_Action_Move(int, DirectX::XMFLOAT3);
	int probability(void);

	//�G�l�~�[�̍L���~�炵�̃A�j���[�V����---------------------------------
	DirectX::XMFLOAT2 Advertisement_raining_Animation();
	//---------------------------------------------------------------------
	//�G�l�~�[�̃����N�����̃A�j���[�V����---------------------------------
	DirectX::XMFLOAT2 link_throwing_Animation();
	//--------------------------------------------------------------------------
};