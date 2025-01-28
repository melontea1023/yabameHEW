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
	//�X�e�[�^�X�֘A------------------------
	int Boss_hp = 15;
	int 


	//-----------------------------------
	int aniCount = 0;
	int finish_Count = 0;
	DirectX::XMFLOAT2 ad_e = { 0,0 };
	DirectX::XMFLOAT2 link_e = { 0,0 };
	bool bullet_set_flg = true;
	bool bullet_move_flg = false;
	DirectX::XMFLOAT3 Get_ebpos = { 0.0f,0.0f,0.0f };

	int e_Type = 1;
	int probability_Count = 1;
	int SaveProbability_Count;

	bool Ad_Animation_end_flg = false;; //�L���~�炵�A�j���[�V�������I��������ǂ����̊m�F
	bool Ed_Animation_end_flg = false;; //�����N�����A�j���[�V�������I��������ǂ����̊m�F
	float delta_time = 0.1f;

	int turn = 1;

	int return_num = 0;

	//�ړ��n�̕ϐ��Q--------------------------
	bool FbossRight = false;
	bool isWaiting = false; //�ړ�
	bool moving_flg = true; //�ړ������m�F�p
	bool move_end = false;
	int time_c = 0;

	//----------------------
public:
	bool e_Running_flg = false;;
	void CharacterInit(void);
	void test_Update(DirectX::XMFLOAT3, DirectX::XMFLOAT3);
	void CharacterDraw(void);
	void Enemy_Action_Move(DirectX::XMFLOAT3);
	int probability(void);

	//void Initialize();

	void bossEnemyMoveLeft();
	void bossEnemyMoveRight();
	bool GetEndflg();

	//�G�l�~�[�̍L���~�炵�̃A�j���[�V����---------------------------------
	DirectX::XMFLOAT2 Advertisement_raining_Animation();
	//---------------------------------------------------------------------
	//�G�l�~�[�̃����N�����̃A�j���[�V����---------------------------------
	DirectX::XMFLOAT2 link_throwing_Animation();
	//-------------------------------------------------------------------------------
};