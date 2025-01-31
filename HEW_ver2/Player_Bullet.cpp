#include"Player_Bullet.h"


void PlayerBullet::Move_Update(Player _obj)
{
	if (p_starting)
	{
		if (!p_b_Setflg)
		{
			PBulletpos =  _obj.GetPos();;
			p_b_Setflg = true;
		}

		if (++Life_Time >= 400)
		{
			PBulletpos = { -1000.0f, -1000.0f, 0.0f };
			Life_Time = 0;
			player_bulletType = 0;
			p_starting = false;
			p_b_Setflg = false;
			AngleSet = false;
		}
		switch (player_bulletType)
		{
		case 1: //�����
			if (boss_pos_right) //BOSS�̌��ݒn���E�Ȃ��
			{
				if (!AngleSet)
				{
					PlayerBullet::SetAngle(25.0f);
					AngleSet = true;
				}
				PBulletpos.x+=10;
				PBulletpos.y+=5;
			}
			else
			{
				if (!AngleSet)
				{
					PlayerBullet::SetAngle(-25.0f);
					AngleSet = true;
				}
				PBulletpos.x-=10;
				PBulletpos.y+=5;
			}
			break;

		case 2: //��������
			if (boss_pos_right) //BOSS�̌��ݒn���E�Ȃ��
			{
				if (!AngleSet)
				{
					PlayerBullet::SetAngle(0.0f);
					AngleSet = true;
				}
				PBulletpos.x+=10;
			}
			else
			{
				if (!AngleSet)
				{
					PlayerBullet::SetAngle(0.0f);
					AngleSet = true;
				}
				PBulletpos.x-=10;
			}
			break;

		case 3: //������
			if (boss_pos_right) //BOSS�̌��ݒn���E�Ȃ��
			{
				if (!AngleSet)
				{
					PlayerBullet::SetAngle(-25.0f);
					AngleSet = true;
				}
				PBulletpos.x+=10;
				PBulletpos.y-=5;
			}
			else
			{
				if (!AngleSet)
				{
					PlayerBullet::SetAngle(25.0f);
					AngleSet = true;
				}
				PBulletpos.x-=10;
				PBulletpos.y-=5;
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

void PlayerBullet::Setp_b(bool _p_b_check)
{
	p_b_Setflg = _p_b_check;
}

bool PlayerBullet::Get_p_starting()
{
	return p_starting;
}