//#include"Enemy.h"
#include<stdlib.h>
#include"Game.h"
#include"time.h"

bool bullet_set_flg = true;
bool bullet_move_flg = false;
DirectX::XMFLOAT3 Get_ebpos = { 0.0f,0.0f,0.0f };

void TestEnemy::CharacterInit(void)
{

	eb.Init(L"asset/link.png");   //�����N��������
	eb.SetPos(SCREEN_WIDTH / 2 / 2, SCREEN_HEIGHT / 2 / 2, 0.0f);//�ʒu��ݒ�
	eb.SetSize(750.0f, 375.0f, 0.0f); //�傫����ݒ�
	eb.SetAngle(0.0f);   //�p�x��ݒ�

	ad.Advertisement_raining_Init();

}


void TestEnemy::test_Update(DirectX::XMFLOAT3 _pos, DirectX::XMFLOAT3 _nowepos)//������Player,Enemy�̍��W
{

	if (eb.loop_flg)
	{
		bullet_set_flg = true;
		bullet_move_flg = false;
	}

	if (bullet_move_flg)
	{
		Get_ebpos = eb.MoveBulllet(_pos, eb.GetPos());
		eb.SetPos(Get_ebpos.x, Get_ebpos.y, Get_ebpos.z);
	}

	if (bullet_set_flg)
	{
		int r = eb.SetTarget(_pos, _nowepos);
		eb.SetAngle(r);
		eb.SetPos(_nowepos.x, _nowepos.y, _nowepos.z);

		eb.Set_Bullet_Target(_pos, _nowepos, eb.GetPos());

		bullet_set_flg = false;
		bullet_move_flg = true;
		eb.loop_flg = false;
	}







}

void TestEnemy::Enemy_Action_Move(int _eMove_Type, DirectX::XMFLOAT3 _playerPosition)
{
	int e_Type = _eMove_Type;

	switch (e_Type)
	{
	case 1://�����N�����Ɋ֌W���鏈��������

		if (Ed_Animation_end_flg) //�����N�����A�j���[�V�������I����Ă��邩�̊m�F
		{
			test_Update(_playerPosition, TestEnemy::GetPos());
		}
		else
		{
			link_e=link_throwing_Animation();
			TestEnemy::SetUV(link_e.x, link_e.y);

		}
		break;
	case 2://�ړ��Ɋ֌W���鏈��������

		break;
	case 3://�L���~�炵�Ɋ֌W���鏈��������



		if (Ad_Animation_end_flg) //�L���~�炵�A�j���[�V�������I����Ă��邩�̊m�F
		{
			ad.Advertisement_raining_Update(_playerPosition);
		}
		else
		{
			ad_e=Advertisement_raining_Animation();
			TestEnemy::SetUV(ad_e.x, ad_e.y);
		}

		break;
	}

}


void TestEnemy::CharacterDraw(void)
{
	/*enemy.Draw();*/
	eb.Draw();
	ad.Advertisement_raining_Darw();
}


//�{�X�̍s���p�^�[������---------------------------
//���ځF�����N����50���A�L���~�炵30���A�ړ�20��
//���ځF�����N����50���A�L���~�炵20���A�ړ�30��
//�O��ځF�����N����40���A�L���~�炵30���A�ړ�30��
//�l��ځF�����N����30���A�L���~�炵10���A�ړ�60��
//�܉�ځF�����N����20���A�L���~�炵00���A�ړ�80��
//�Z��ځF�����N����00���A�L���~�炵00���A�ړ�100��
//
//--------------------------------------------

int TestEnemy::probability(void)
{
	int return_num = 0;
	srand(time(NULL));
	int r = (rand() % 10 + 1);

	switch (probability_Count)
	{
	case 1:
		if (r <= 5)
		{
			return_num = 1;//�����N����
		}
		else if (r >= 6 && r <= 8)
		{
			return_num = 3;
		}
		else
		{
			return_num = 2;
		}
		probability_Count++;
		break;
	case 2:
		if (r <= 5)
		{
			return_num = 1;//�����N����
		}
		else if (r >= 6 && r <= 7)
		{
			return_num = 3;
		}
		else
		{
			return_num = 2;
		}
		probability_Count++;
		break;
	case 3:
		if (r <= 4)
		{
			return_num = 1;//�����N����
		}
		else if (r >= 5 && r <= 7)
		{
			return_num = 3;
		}
		else
		{
			return_num = 2;
		}
		probability_Count++;
		break;
	case 4:
		if (r <= 3)
		{
			return_num = 1;//�����N����
		}
		else if (r == 4)
		{
			return_num = 3;
		}
		else
		{
			return_num = 2;
		}
		probability_Count++;
		break;
	case 5:
		if (r <= 2)
		{
			return_num = 1; //�����N����
		}

		else
		{
			return_num = 2;
		}
		probability_Count++;
		break;
	case 6:
		return_num = 2;
		probability_Count++;
		break;
	}




	if (probability_Count >= 7)
	{
		probability_Count = 1;
	}
	return return_num;
}