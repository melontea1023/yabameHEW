#pragma once
#include"Object.h"


class PlayerBullet : public Object
{
protected:

	bool p_starting = false;
	int player_bulletType = 0;

public:
	void Move_Update();
	void p_BulletMove();

	void P_BDraw();

	void SetBulletType(int); //�e�̔��˂���A�����A���̂����ꂩ��player_bulletType�Ɋi�[
	void Set_p_starting(bool); //�v���C���[�̒e���N�����邩�ǂ����̃t���O�Ɋi�[





};