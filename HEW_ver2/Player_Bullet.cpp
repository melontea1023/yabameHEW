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
		case 1: //上方向
			if (boss_pos_right) //BOSSの現在地が右ならば
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

		case 2: //中央方向
			if (boss_pos_right) //BOSSの現在地が右ならば
			{
				PBulletpos.x++;
			}
			else
			{
				PBulletpos.x--;
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