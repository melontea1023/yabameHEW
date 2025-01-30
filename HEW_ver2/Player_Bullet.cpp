#include"Player_Bullet.h"


void PlayerBullet::Move_Update(Player _obj)
{
	if (p_starting)
	{
		if (++Life_Time >= 420)
		{
			PBulletpos = _obj.GetPos();
			player_bulletType = 0;
			p_starting = false;
		}
		switch (player_bulletType)
		{
		case 1: //�����
			if (boss_pos_right) //BOSS�̌��ݒn���E�Ȃ��
			{
				PBulletpos.x++;
				PBulletpos.y++;
			}
			else
			{
				PBulletpos.x--;
				PBulletpos.y++;
			}
			break;

		case 2: //��������
			if (boss_pos_right) //BOSS�̌��ݒn���E�Ȃ��
			{
				PBulletpos.x++;
			}
			else
			{
				PBulletpos.x--;
			}
			break;

		case 3: //������
			if (boss_pos_right) //BOSS�̌��ݒn���E�Ȃ��
			{
				PBulletpos.x++;
				PBulletpos.y--;
			}
			else
			{
				PBulletpos.x--;
				PBulletpos.y--;
			}
			break;

		
		}
		PlayerBullet::SetPos(PBulletpos.x,PBulletpos.y,PBulletpos.z);
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

void PlayerBullet::Setboss_pos_right(bool _e_check)
{
	boss_pos_right = _e_check;
}