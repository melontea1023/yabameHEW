#include"Player_Bullet.h"
#include"Player.h"

void PlayerBullet::Move_Update()
{
	if (p_starting)
	{
		//�G�����E�ǂ���ɋ��邩�̂̏���


		switch (player_bulletType)
		{
		case 1: //�����

			break;

		case 2: //��������

			break;

		case 3: //������

			break;

		
		}
		//PlayerBullet::SetPos()
	}





}

void PlayerBullet::p_BulletMove()
{

}

void PlayerBullet::P_BDraw()
{
	if (p_starting)
	{
		PlayerBullet::Draw();
	}
}

void PlayerBullet::SetBulletType(int _b_Type) //�e�̔��˂���A�����A���̂����ꂩ��player_bulletType�Ɋi�[
{
	player_bulletType = _b_Type;
}

void PlayerBullet::Set_p_starting(bool _s_check)//�v���C���[�̒e���N�����邩�ǂ����̃t���O�Ɋi�[
{
	p_starting = _s_check;
}