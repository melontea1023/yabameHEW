#include"Player_Bullet.h"
#include"Player.h"

void PlayerBullet::Move_Update()
{
	if (p_starting)
	{
		//敵が左右どちらに居るかのの処理


		switch (player_bulletType)
		{
		case 1: //上方向

			break;

		case 2: //中央方向

			break;

		case 3: //下方向

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

void PlayerBullet::SetBulletType(int _b_Type) //弾の発射が上、中央、下のいずれかをplayer_bulletTypeに格納
{
	player_bulletType = _b_Type;
}

void PlayerBullet::Set_p_starting(bool _s_check)//プレイヤーの弾を起動するかどうかのフラグに格納
{
	p_starting = _s_check;
}