#include"Game.h"

bool P_E_Touchflg = false;

void Game::Damage(Player obj1, TestEnemy obj2) //������Player Enemy;
{
	int playerhp = obj1.Gethp();
	int enemyhp = obj2.Gethp();

	if (Box_Hit_judgment(obj1, obj2)) //�v���C���[�ƃG�l�~�[���ڐG���Ă��邩�ǂ����̊m�F
	{
		if (obj1.GetAttack())//player���U�������ǂ������m�F
		{
			//player���U�����Ȃ��



		}
		else
		{
			//player���U�����Ŗ����Ȃ�
			playerhp-=1;

		}






	}





	obj1.Sethp(playerhp);
	obj2.Sethp(enemyhp);


	if (playerhp<=0)
	{
		GAME_END_flg = true;
	}

	if (enemyhp <= 0)
	{
		GAME_CLEAR_flg = true;
	}
}