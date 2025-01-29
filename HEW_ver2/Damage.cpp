#include"Game.h"

bool P_E_Touchflg = false;

void Game::Damage(Player obj1, TestEnemy obj2) //左からPlayer Enemy;
{
	int playerhp = obj1.Gethp();
	int enemyhp = obj2.Gethp();
	if (Box_Hit_judgment(obj1, obj2)) //プレイヤーとエネミーが接触しているかどうかの確認
	{
		if (1)//playerが攻撃中かどうかを確認
		{
			//playerが攻撃中ならば



		}
		else
		{
			//playerが攻撃中で無いなら


		}






	}





	obj1.Sethp(playerhp);
	obj2.Sethp(enemyhp);
}