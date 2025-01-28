#include"Advertisement raining.h"
#include"Game.h"
#include"direct3d.h"
#include"input.h"
#include<stdlib.h>



Advertisement ad;
Advertisement ad2;
//Input input;

//�L���ڕW���W---------------------------
// - SCREEN_WIDTH / 2 / 2, SCREEN_HEIGHT / 2 / 2(����)

// SCREEN_WIDTH / 2 / 2, SCREEN_HEIGHT / 2 / 2(�E��)

// - SCREEN_WIDTH / 2 / 2, - SCREEN_HEIGHT / 2 / 2(����)

// SCREEN_WIDTH / 2 / 2, - SCREEN_HEIGHT / 2 / 2(�E��)

//�ォ��L�����~��������ꍇ�̍��W��"810"

//-------------------------------------

void Advertisement::Advertisement_raining_Init()
{
	//
	//ad.Init(L"asset/neofx.png");   //�L���������� 
	ad.Init(L"asset/weby.png");   //�L����������
	//ad.SetPos( -SCREEN_WIDTH / 2 / 2, SCREEN_HEIGHT / 2 / 2, 0.0f);      //�ʒu��ݒ�
	ad.SetPos(1000, 1000, 0.0f);      //�ʒu��ݒ�
	ad.SetSize(SCREEN_WIDTH/2, SCREEN_HEIGHT / 2, 0.0f); //�傫����ݒ�
	ad.SetAngle(0.0f);   //�p�x��ݒ�

	ad2.Init(L"asset/ad.png");   //�L����������
	ad2.SetPos(-1000, 1000, 0.0f);      //�ʒu��ݒ�
	ad2.SetSize(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f); //�傫����ݒ�
	ad2.SetAngle(0.0f);   //�p�x��ݒ�

	
	random = 0;
	time_count = 0;

	Set_flg = false;
	random_flg = true;
	move_flg=false;
	m_flg = false;
}
void Advertisement::Advertisement_raining_Update(DirectX::XMFLOAT3 _nowpos)
{
	//input.Update();

	if (random_flg)
	{
		random = GetRandom();//�����擾
	}

	now_p_pos = _nowpos;
	int Advertisement_Type = AdvertisingLocation(now_p_pos);
	
		if (!Set_flg)
		{
			Advertisement_Attack_Set(Advertisement_Type, now_p_pos);
			
		}
		Advertisement_move(Advertisement_Type);
	
}
void Advertisement::Advertisement_raining_Darw()
{

	switch (random)//�����ɉ����čL����ς���
	{
	case 1:
		ad.Draw();
		break;

	case 2:
		ad2.Draw();
		break;
	}
	

}
void Advertisement::Advertisement_raining_Uninit()
{
	//
	ad.Uninit();

	ad2.Uninit();

	

}


int Advertisement::GetRandom()
{
	int r = rand();
	r = (r % 3) + 1;
	random_flg = false;
	return r;
}



int Advertisement::AdvertisingLocation(DirectX::XMFLOAT3 _now_p_pos)
{
	int AdType = 0;

	bool LU_flg = false, LD_flg = false, RU_flg = false, RD_flg = false;

	DirectX::XMFLOAT2 Reference_point_LU, Reference_point_CU, Reference_point_RU, Reference_point_L, Reference_point_C, Reference_point_R, Reference_point_LD, Reference_point_CD, Reference_point_RD;
	float px = _now_p_pos.x;
	float py = _now_p_pos.y;
	float pz = _now_p_pos.z;

	Reference_point_LU.x = -SCREEN_WIDTH/2; Reference_point_LU.y = SCREEN_HEIGHT/2;
	Reference_point_CU.x = 0; Reference_point_CU.y = SCREEN_HEIGHT/2;
	Reference_point_RU.x = SCREEN_WIDTH/2; Reference_point_RU.y = SCREEN_HEIGHT/2;
	Reference_point_L.x = -SCREEN_WIDTH/2; Reference_point_L.y = 0;
	Reference_point_C.x = 0; Reference_point_C.y = 0;
	Reference_point_R.x = SCREEN_WIDTH/2; Reference_point_R.y = 0;
	Reference_point_LD.x = -SCREEN_WIDTH/2; Reference_point_LD.y = -SCREEN_HEIGHT/2;
	Reference_point_CD.x = 0; Reference_point_CD.y = -SCREEN_HEIGHT/2;
	Reference_point_RD.x = SCREEN_WIDTH/2; Reference_point_RD.y = -SCREEN_HEIGHT/2;

	//����Ƀv���C���[�����邩�̊m�F
	if (px >= Reference_point_LU.x && py <= Reference_point_LU.y&& px <= Reference_point_CU.x && py <= Reference_point_CU.y && px>=Reference_point_L.x&& py>=Reference_point_L.y&&px<= Reference_point_C.x&& py >= Reference_point_C.y) //��ʂ��S���������ۂ̍���Ƀv���C���[�����邩�̊m�F
	{
		LU_flg = true;
	}
	else
	{
		LU_flg = false;
	}

	//�����Ƀv���C���[�����邩�̊m�F
	if (px >= Reference_point_L.x && py <= Reference_point_L.y && px <= Reference_point_C.x && py <= Reference_point_C.y && px >= Reference_point_LD.x && py >= Reference_point_LD.y && px <= Reference_point_CD.x && py >= Reference_point_CD.y)//��ʂ��S���������ۂ̍����Ƀv���C���[�����邩�̊m�F
	{
		LD_flg = true;
	}
	else
	{
		LD_flg = false;
	}

	//�E��Ƀv���C���[�����邩�̊m�F
	if (px <= Reference_point_RU.x && py <= Reference_point_RU.y && px >= Reference_point_CU.x && py <= Reference_point_CU.y && px <= Reference_point_R.x && py >= Reference_point_R.y && px >= Reference_point_C.x && py >= Reference_point_C.y) //��ʂ��S���������ۂ̉E��Ƀv���C���[�����邩�̊m�F
	{
		RU_flg = true;
	}
	else
	{
		RU_flg = false;
	}

	//�E���Ƀv���C���[�����邩�̊m�F
	if (px <= Reference_point_R.x && py <= Reference_point_R.y && px >= Reference_point_C.x && py <= Reference_point_C.y && px <= Reference_point_RD.x && py >= Reference_point_RD.y && px >= Reference_point_CD.x && py >= Reference_point_CD.y)//��ʂ��S���������ۂ̉E���Ƀv���C���[�����邩�̊m�F
	{
		RD_flg = true;
	}
	else
	{
		RD_flg = false;
	}


	if (LU_flg)
	{
		AdType = 1;
	}

	if (LD_flg)
	{
		AdType = 3;
	}

	if (RU_flg)
	{
		AdType = 2;
	}
	if (RD_flg)
	{
		AdType = 4;
	}

	return AdType;

}

void  Advertisement::Advertisement_Attack_Set(int _Type, DirectX::XMFLOAT3 _p_pos)
{
	int Type = _Type;
	DirectX::XMFLOAT3 Adpos = ad.GetPos();//����m�F�p(����m�F�ȊO�ł̓R�����g�A�E�g)

	//DirectX::XMFLOAT3 Adpos = _p_pos;

	switch (Type)//
	{
	case 1://����̎�

		Adpos.x = -SCREEN_WIDTH / 2 / 2;
		Adpos.y = testpos_y;
		Set_flg = true;

		ad.SetPos(Adpos.x, Adpos.y, Adpos.z);

		ad2.SetPos(Adpos.x, Adpos.y, Adpos.z);
		break;
	case 2://�E��̎�
		Adpos.x = SCREEN_WIDTH / 2 / 2;
		Adpos.y = testpos_y;
		Set_flg = true;

		ad.SetPos(Adpos.x, Adpos.y, Adpos.z);

		ad2.SetPos(Adpos.x, Adpos.y, Adpos.z);

		

		break;
	case 3://�����̎�
		Adpos.x = -SCREEN_WIDTH / 2 / 2;
		Adpos.y = testpos_y;
		Set_flg = true;

		ad.SetPos(Adpos.x, Adpos.y, Adpos.z);

		ad2.SetPos(Adpos.x, Adpos.y, Adpos.z);

		break;
	case 4://�E���̎�
		Adpos.x = SCREEN_WIDTH / 2 / 2;
		Adpos.y = testpos_y;
		Set_flg = true;

		ad.SetPos(Adpos.x, Adpos.y, Adpos.z);

		ad2.SetPos(Adpos.x, Adpos.y, Adpos.z);
		break;
	}




}



void Advertisement::Advertisement_move(int _target_pos)
{
	int targetposType = _target_pos;

	DirectX::XMFLOAT3 adpos = ad.GetPos();

	switch (targetposType)//
	{
	case 1://����̎�

		if (adpos.y >= SCREEN_HEIGHT / 2 / 2)
		{
			adpos.y--;
		}
		else
		{
			time_count++;
			if (time_count >= 300)
			{
				adpos.x = -SCREEN_WIDTH / 2 / 2;
				adpos.y = testpos_y;
				time_count = 0;
				targetposType = 0;
				Set_flg = false;
				random_flg = true;
				move_flg = false;
				m_flg = false;
				ad_end = true;
				//Set_flg = false;
			}
		}
		
			ad.SetPos(adpos.x, adpos.y, adpos.z);
		
			ad2.SetPos(adpos.x, adpos.y, adpos.z);

		break;
	case 2://�E��̎�

		if (adpos.y >= SCREEN_HEIGHT / 2 / 2)
		{
			adpos.y--;
		}
		else
		{
			time_count++;
			if (time_count >= 300)
			{
				adpos.x = SCREEN_WIDTH / 2 / 2;
				adpos.y = testpos_y;
				time_count = 0;
				targetposType = 0;

				Set_flg = false;
				random_flg = true;
				move_flg = false;
				m_flg = false;
				ad_end = true;

				//Set_flg = false;
			}
		}
		ad.SetPos(adpos.x, adpos.y, adpos.z);

		ad2.SetPos(adpos.x, adpos.y, adpos.z);


		break;
	case 3://�����̎�
		if (adpos.y >= -SCREEN_HEIGHT / 2 / 2)
		{
			adpos.y--;
		}
		else
		{
			time_count++;
			if (time_count >= 300)
			{
				adpos.x = -SCREEN_WIDTH / 2 / 2;
				adpos.y = testpos_y;
				time_count = 0;
				targetposType = 0;

				Set_flg = false;
				random_flg = true;
				move_flg = false;
				m_flg = false;
				ad_end = true;
				ad_end = true;

				//Set_flg = false;
			}
		}

		ad.SetPos(adpos.x, adpos.y, adpos.z);

		ad2.SetPos(adpos.x, adpos.y, adpos.z);
		break;
	case 4://�E���̎�
		if (adpos.y >= -SCREEN_HEIGHT / 2 / 2)
		{
			adpos.y--;
		}
		else
		{
			time_count++;
			if (time_count >= 300)
			{
				adpos.x = SCREEN_WIDTH / 2 / 2;
				adpos.y = testpos_y;
				time_count = 0;
				targetposType = 0;

				Set_flg = false;
				random_flg = true;
				move_flg = false;
				m_flg = false;
				ad_end = true;

				//Set_flg = false;
			}
		}
		ad.SetPos(adpos.x, adpos.y, adpos.z);

		ad2.SetPos(adpos.x, adpos.y, adpos.z);
		break;
	}


}

void Advertisement::SetVelocity(const DirectX::XMFLOAT2& velocity) {
	this->velocity = velocity;
}

void Advertisement::UpdatePosition() {
	position.x += velocity.x;
	position.y += velocity.y;
}