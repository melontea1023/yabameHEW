#include"Game.h"

bool P_E_Touchflg = false;

int playerhp = 0;
int enemyhp = 0;

void Game::Damage(Player obj1, TestEnemy obj2) //������Player Enemy;
{
	playerhp = obj1.Gethp();
	enemyhp = obj2.Gethp();

	if (Box_Hit_Judgment(obj1, obj2)) //�v���C���[�ƃG�l�~�[���ڐG���Ă��邩�ǂ����̊m�F
	{
		if (obj1.GetAttack())//player���U�������ǂ������m�F
		{
			//player���U�����Ȃ��
			
				enemyhp=0;
		}
		else
		{
			//player���U�����Ŗ����Ȃ�
			//playerhp=0;
			//enemyhp = 0;

		}

	}

	if (playerhp<=0)
	{
		GAME_END_flg = true;
	}

	if (enemyhp <= 0)
	{
		GAME_CLEAR_flg = true;
	}
	obj1.Sethp(playerhp);
	obj2.Sethp(enemyhp);
}


void Game::Damage(Player obj1, Test_Bullet obj2)//������Player Bullet
{

	if (Box_Hit_Judgment(obj1, obj2)) //�v���C���[�ƒe���ڐG���Ă��邩�ǂ����̊m�F
	{
		playerhp = 0;


	}

	if (playerhp <= 0)
	{
		GAME_END_flg = true;
	}

}


void Game::Damage(TestEnemy obj1, Test_Bullet obj2)//������Enemy Bullet
{
	if (Box_Hit_Judgment(obj1, obj2)) //�G�l�~�[�ƒe���ڐG���Ă��邩�ǂ����̊m�F
	{

	}





}