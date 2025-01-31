#pragma once
#include"Object.h"
#include"Player.h"

class PlayerBullet : public Object
{
protected:
	DirectX::XMFLOAT3 PBulletpos = { 0.0f,0.0f,0.0f };

	bool p_b_Setflg = false;
	bool p_starting = false;
	bool boss_pos_right = false;
	bool AngleSet = false;
	int player_bulletType = 0;
	int Life_Time = 0;
public:
	void Move_Update(Player);
	void p_BulletMove();

	void P_BDraw();

	void SetBulletType(int); //�e�̔��˂���A�����A���̂����ꂩ��player_bulletType�Ɋi�[
	void Set_p_starting(bool); //�v���C���[�̒e���N�����邩�ǂ����̃t���O�Ɋi�[
	void Setp_b(bool);
	bool Get_p_starting();
	void Setboss_pos_right(bool); //BOSS�̍��W���E���ǂ����̃t���O���i�[




};