#include"Game.h"
#include"testEnemy.h"


int playerhp = 0;
int enemyhp = 0;
bool Setting_flg = false;

void Game::Damage(Player obj1, TestEnemy obj2) //左からPlayer Enemy;
{
	if (!Setting_flg)
	{
		playerhp = obj1.Gethp();
		enemyhp = obj2.Gethp();
	}
	

	if (Box_Hit_Judgment(obj1, obj2)) //プレイヤーとエネミーが接触しているかどうかの確認
	{
		if (obj1.GetAttack())//playerが攻撃中かどうかを確認
		{
			//playerが攻撃中ならば
			
				enemyhp-=obj2.Getatk();
				Setting_flg = true;
		}
		else
		{
			//playerが攻撃中で無いなら
			//playerhp=0;
			//enemyhp = 0;

		}

	}

	if (playerhp<=0)
	{
		GAME_END_flg = true;
		Setting_flg = false;
	}

	if (enemyhp <= 0)
	{
		GAME_CLEAR_flg = true;
		Setting_flg = false;
	}
	obj1.Sethp(playerhp);
	obj2.Sethp(enemyhp);
}


void Game::Damage(Player obj1, Test_Bullet obj2)//左からPlayer Bullet
{

	if (Box_Hit_Judgment(obj1, obj2)) //プレイヤーと弾が接触しているかどうかの確認
	{
		playerhp = 0;


	}

	if (playerhp <= 0)
	{
		GAME_END_flg = true;
	}

}


void Game::Damage(TestEnemy obj1, Test_Bullet obj2)//左からEnemy Bullet
{
	if (Box_Hit_Judgment(obj1, obj2)) //エネミーと弾が接触しているかどうかの確認
	{

	}





}