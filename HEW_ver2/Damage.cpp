#include"Game.h"



int playerhp = 0;
int enemyhp = 0;
int hit_time_count = 0;
bool Setting_flg = false;

void Game::Damage(Player obj1, TestEnemy obj2) //������Player Enemy;
{
	if (!Setting_flg)
	{
		playerhp = obj1.Gethp();
		enemyhp = obj2.Gethp();
	}
	

	if (Box_Hit_Judgment(obj1, obj2)) //�v���C���[�ƃG�l�~�[���ڐG���Ă��邩�ǂ����̊m�F
	{
		if (obj1.GetAttack())//player���U�������ǂ������m�F
		{
			//player���U�����Ȃ��
			hit_time_count++;
			if (hit_time_count % 60 == 1)
			{
				enemyhp -= obj2.Getatk();
				//hit_time_count =0;
				Setting_flg = true;
			}
				
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


void Game::Damage(Player obj1, Test_Bullet obj2)//������Player Bullet
{
	//if (!Setting_flg)
	//{
	//	playerhp = obj1.Gethp();
	//}

	//if (Box_Hit_Judgment(obj1, obj2)) //�v���C���[�ƒe���ڐG���Ă��邩�ǂ����̊m�F
	//{
	//	if (obj1.GetAttack())//player���U�������ǂ������m�F
	//	{
	//		hit_time_count++;
	//		if (hit_time_count % 60 == 1)
	//		{
	//			//enemyhp -= obj2.Getatk();
	//			hit_time_count = 0;
	//			Setting_flg = true;
	//		}
	//	}
	//		


	//}

	//if (playerhp <= 0)
	//{
	//	GAME_END_flg = true;
	//}

}


void Game::Damage(TestEnemy obj1, PlayerBullet obj2)//������Enemy Bullet
{
	if (!Setting_flg)
	{
		enemyhp = obj1.Gethp();
	}

	
	if (Box_Hit_Judgment(obj1, obj2)) //�G�l�~�[�ƒe���ڐG���Ă��邩�ǂ����̊m�F
	{
		hit_time_count++;
		if (hit_time_count % 60 == 1)
		{
			//enemyhp -= player.GetReflectionAtk();
			enemyhp = 0;
			hit_time_count = 0;
			Setting_flg = true;
		}

			
	}
	if (enemyhp <= 0)
	{
		GAME_CLEAR_flg = true;
		Setting_flg = false;
	}
	





}