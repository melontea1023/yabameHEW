#include"Player_Bullet.h"


void PlayerBullet::Move_Update(Player _obj)
{
	if (p_starting)
	{
		if (!p_b_Setflg)
		{
			PBulletpos = _obj.GetPos();
			p_b_Setflg = true;
		}

		if (++Life_Time >= 300)
		{
			PBulletpos = _obj.GetPos();
			player_bulletType = 0;
			p_starting = false;
			p_b_Setflg = false;
		}
		switch (player_bulletType)
		{
		case 1: //上方向
			if (boss_pos_right) //BOSSの現在地が右ならば
			{

				PBulletpos.x++;
				PBulletpos.y++;
			}
			else
			{
				PBulletpos.x-=10;
				PBulletpos.y+=10;
			}
			break;

		case 2: //中央方向
			if (boss_pos_right) //BOSSの現在地が右ならば
			{
				PBulletpos.x+=10;
			}
			else
			{
				PBulletpos.x-=10;
			}
			break;

		case 3: //下方向
			if (boss_pos_right) //BOSSの現在地が右ならば
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

void PlayerBullet::SetBulletType(int _b_Type) //弾の発射が上、中央、下のいずれかをplayer_bulletTypeに格納
{
	player_bulletType = _b_Type;
}

void PlayerBullet::Set_p_starting(bool _s_check)//プレイヤーの弾を起動するかどうかのフラグに格納
{
	p_starting = _s_check;
}

void PlayerBullet::Setboss_pos_right(bool _e_check)
{
	boss_pos_right = _e_check;
}