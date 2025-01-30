#include"testenemy.h"
#include"time.h"
#include <cstdlib> // rand, srand
#include <ctime>   // time
int eb_count = 0;

//
void TestEnemy::CharacterInit(void)
{

	eb.Init(L"asset/link.png");   //�����N��������
	eb.SetPos(epos);//�ʒu��ݒ�
	eb.SetSize(750.0f, 375.0f, 0.0f); //�傫����ݒ�
	eb.SetAngle(0.0f);   //�p�x��ݒ�
	ad.Advertisement_raining_Init();

}


void TestEnemy::test_Update(DirectX::XMFLOAT3 _pos, DirectX::XMFLOAT3 _nowepos)//������Player,Enemy�̍��W
{
	if (bullet_move_flg)
	{
		Get_ebpos = eb.MoveBulllet(_pos, eb.GetPos());
		eb.SetPos(Get_ebpos);
		eb_count++;
		e_Running_flg = eb.GetEndflg();
	}

	if (bullet_set_flg)
	{
		int r = eb.SetTarget(_pos, _nowepos);
		eb.SetAngle(r);
		eb.SetPos(_nowepos);

		eb.Set_Bullet_Target(_pos, _nowepos, eb.GetPos());

		bullet_set_flg = false;
		bullet_move_flg = true;
		eb.loop_flg = false;
	}

}

void TestEnemy::Enemy_Action_Move(DirectX::XMFLOAT3 _playerPosition)
{
	if (!e_Running_flg)
	{
		e_Type = probability();
	}

	//DirectX::XMFLOAT3 nowpos = TestEnemy::GetPos();
	

	switch (e_Type)
	{
	case 1://�����N�����Ɋ֌W���鏈��������
		if (Ed_Animation_end_flg) //�����N�����A�j���[�V�������I����Ă��邩�̊m�F
		{
			if (bullet_set_flg)
			{
		//esound.Play(SOUND_LABEL_LINK);
				epos = TestEnemy::GetPos();
				int r = eb.SetTarget(_playerPosition, epos);
				eb.SetAngle(r);
				eb.SetPos(epos);

				eb.Set_Bullet_Target(_playerPosition, epos, eb.GetPos());

				bullet_set_flg = false;
				bullet_move_flg = true;
				eb.SetShotfinish(false);

			}
			if (bullet_move_flg)
			{
				Get_ebpos = eb.MoveBulllet(_playerPosition, eb.GetPos());
				eb.SetPos(Get_ebpos);
				if (eb.GetEndflg())
				{
					Ed_Animation_end_flg = false; // �A�j���[�V�����I���t���O�����Z�b�g
					e_Running_flg = false;       // ���̍s��������
					eb.SetEndflg(false);
				}
			}
			break;
		}
		else
		{
			link_e = link_throwing_Animation();
			SetUV(link_e.x, link_e.y);
		}
		e_Running_flg = true;
		break;
	case 2://�ړ��Ɋ֌W���鏈��������
		if (moving_flg)
		{
			epos = TestEnemy::GetPos();  // �{�X�̌��݈ʒu���擾
			if (FbossRight)
			{
				bossEnemyMoveRight();
			}
			else
			{
				bossEnemyMoveLeft();
			}
			SetPos(epos.x, epos.y, epos.z);
		}
		e_Running_flg = true;
		if (TestEnemy::GetEndflg())
		{
			e_Running_flg = false;       // ���̍s��������
		}

		break;
	case 3://�L���~�炵�Ɋ֌W���鏈��������
		if (Ad_Animation_end_flg) //�L���~�炵�A�j���[�V�������I����Ă��邩�̊m�F
		{
			//esound.Play(SOUND_LABEL_ADVAGO);
			ad.Advertisement_raining_Update(_playerPosition);
			if (ad.GetEndflg())
			{
				Ad_Animation_end_flg = false; // �A�j���[�V�����I���t���O�����Z�b�g
				e_Running_flg = false;       // ���̍s��������
				ad.SetEndflg(false);
				break;
			}
		}
		else
		{
			ad_e = Advertisement_raining_Animation();
			SetUV(ad_e.x, ad_e.y);
		}
		e_Running_flg = true;
		break;
	}

}

void TestEnemy::CharacterDraw(void)
{
	/*enemy.Draw();*/
	if (bullet_move_flg)
	{
		eb.Draw();
	}
	
	ad.Advertisement_raining_Draw();
}
////�{�X�̍s���p�^�[������---------------------------
////���ځF�����N����50���A�L���~�炵30���A�ړ�20��
////���ځF�����N����50���A�L���~�炵20���A�ړ�30��
////�O��ځF�����N����40���A�L���~�炵30���A�ړ�30��
////�l��ځF�����N����30���A�L���~�炵10���A�ړ�60��
////�܉�ځF�����N����20���A�L���~�炵00���A�ړ�80��
////�Z��ځF�����N����00���A�L���~�炵00���A�ړ�100��
////--------------------------------------------
//
int TestEnemy::probability(void)
{
	srand(static_cast<unsigned int>(time(0)));

	// �e�s���̊m��
	int linkThrow = 0;
	int adRain = 0;
	int move = 0;
	// �^�[�����Ƃ̊m���ݒ�
	if (turn == 1) {
		linkThrow = 50; adRain = 30; move = 20;
	}
	else if (turn == 2) {
		linkThrow = 50; adRain = 20; move = 30;
	}
	else if (turn == 3) {
		linkThrow = 40; adRain = 30; move = 30;
	}
	else if (turn == 4) {
		linkThrow = 30; adRain = 10; move = 60;
	}
	else if (turn == 5) {
		linkThrow = 20; adRain = 0;  move = 80;
	}
	else {
		linkThrow = 0;  adRain = 0;  move = 100;
	}
	if (turn == 7)
	{
		turn = 1;
	}
	else
	{
		turn++;
	}


	// �����_���ōs��������
	int randomValue = rand() % 100 + 1; // 1�`100�̃����_���l
	if (randomValue < linkThrow) {
		return 1; // �����N����
	}
	else if (randomValue < linkThrow + adRain) {
		return 3; // �L���~�炵
	}
	else {
		return 2; // �ړ�
	}
}