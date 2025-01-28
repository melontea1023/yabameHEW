#include"Advertisement raining.h"
#include"Game.h"
#include"direct3d.h"
#include"input.h"
#include<stdlib.h>



Advertisement ad;
Advertisement ad2;
Advertisement ad3;

//Input input;

//広告目標座標---------------------------
// - SCREEN_WIDTH / 2 / 2, SCREEN_HEIGHT / 2 / 2(左上)

// SCREEN_WIDTH / 2 / 2, SCREEN_HEIGHT / 2 / 2(右上)

// - SCREEN_WIDTH / 2 / 2, - SCREEN_HEIGHT / 2 / 2(左下)

// SCREEN_WIDTH / 2 / 2, - SCREEN_HEIGHT / 2 / 2(右下)

//上から広告を降下させる場合の座標は"810"

//-------------------------------------



//敵の大きさは横がプレイヤーの2倍縦は１．２倍

void Advertisement::Advertisement_raining_Init()
{
	//
	ad.Init(L"asset/weby.png");   //広告を初期化
	//ad.SetPos( -SCREEN_WIDTH / 2 / 2, SCREEN_HEIGHT / 2 / 2, 0.0f);      //位置を設定
	ad.SetPos(1000, 1000, 0.0f);      //位置を設定
	ad.SetSize(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f); //大きさを設定
	ad.SetAngle(0.0f);   //角度を設定

	ad2.Init(L"asset/ad.png");   //広告を初期化
	ad2.SetPos(-1000, 1000, 0.0f);      //位置を設定
	ad2.SetSize(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f); //大きさを設定
	ad2.SetAngle(0.0f);   //角度を設定

	ad3.Init(L"asset/warning.png");   //広告を初期化
	ad3.SetPos(-1000, 1000, 0.0f);      //位置を設定
	ad3.SetSize(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f); //大きさを設定
	ad3.SetAngle(0.0f);   //角度を設定


	random = 0;
	time_count = 0;

	Set_flg = false;
	random_flg = true;
	move_flg = false;
	m_flg = false;
}
void Advertisement::Advertisement_raining_Update(DirectX::XMFLOAT3 _nowpos)// 引数はPlayerの座標
{
	//input.Update();

	if (random_flg)
	{
		random = GetRandom();//乱数取得
	}

	now_p_pos = _nowpos;
	int Advertisement_Type = AdvertisingLocation(now_p_pos);

	if (!Set_flg)
	{
		Advertisement_Attack_Set(Advertisement_Type, now_p_pos);

	}
	Advertisement_move(Advertisement_Type);

}
void Advertisement::Advertisement_raining_Draw()
{

	switch (random)//乱数に応じて広告を変える
	{
	case 1:
		ad.Draw();
		break;

	case 2:
		ad2.Draw();
		break;
	case 3:
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
	srand(time(NULL));
	int r = rand();
	r = (r % 2) + 1;
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

	Reference_point_LU.x = -SCREEN_WIDTH / 2; Reference_point_LU.y = SCREEN_HEIGHT / 2;
	Reference_point_CU.x = 0; Reference_point_CU.y = SCREEN_HEIGHT / 2;
	Reference_point_RU.x = SCREEN_WIDTH / 2; Reference_point_RU.y = SCREEN_HEIGHT / 2;
	Reference_point_L.x = -SCREEN_WIDTH / 2; Reference_point_L.y = 0;
	Reference_point_C.x = 0; Reference_point_C.y = 0;
	Reference_point_R.x = SCREEN_WIDTH / 2; Reference_point_R.y = 0;
	Reference_point_LD.x = -SCREEN_WIDTH / 2; Reference_point_LD.y = -SCREEN_HEIGHT / 2;
	Reference_point_CD.x = 0; Reference_point_CD.y = -SCREEN_HEIGHT / 2;
	Reference_point_RD.x = SCREEN_WIDTH / 2; Reference_point_RD.y = -SCREEN_HEIGHT / 2;

	//左上にプレイヤーが居るかの確認
	if (px >= Reference_point_LU.x && py <= Reference_point_LU.y && px <= Reference_point_CU.x && py <= Reference_point_CU.y && px >= Reference_point_L.x && py >= Reference_point_L.y && px <= Reference_point_C.x && py >= Reference_point_C.y) //画面を４分割した際の左上にプレイヤーがいるかの確認
	{
		LU_flg = true;
	}
	else
	{
		LU_flg = false;
	}

	//左下にプレイヤーが居るかの確認
	if (px >= Reference_point_L.x && py <= Reference_point_L.y && px <= Reference_point_C.x && py <= Reference_point_C.y && px >= Reference_point_LD.x && py >= Reference_point_LD.y && px <= Reference_point_CD.x && py >= Reference_point_CD.y)//画面を４分割した際の左下にプレイヤーがいるかの確認
	{
		LD_flg = true;
	}
	else
	{
		LD_flg = false;
	}

	//右上にプレイヤーが居るかの確認
	if (px <= Reference_point_RU.x && py <= Reference_point_RU.y && px >= Reference_point_CU.x && py <= Reference_point_CU.y && px <= Reference_point_R.x && py >= Reference_point_R.y && px >= Reference_point_C.x && py >= Reference_point_C.y) //画面を４分割した際の右上にプレイヤーがいるかの確認
	{
		RU_flg = true;
	}
	else
	{
		RU_flg = false;
	}

	//右下にプレイヤーが居るかの確認
	if (px <= Reference_point_R.x && py <= Reference_point_R.y && px >= Reference_point_C.x && py <= Reference_point_C.y && px <= Reference_point_RD.x && py >= Reference_point_RD.y && px >= Reference_point_CD.x && py >= Reference_point_CD.y)//画面を４分割した際の右下にプレイヤーがいるかの確認
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
	DirectX::XMFLOAT3 Adpos = ad.GetPos();

	switch (Type)//
	{
	case 1://左上の時

		Adpos.x = -SCREEN_WIDTH / 2 / 2;
		Adpos.y = Ad_falling_pos_y;
		Set_flg = true;

		ad.SetPos(Adpos.x, Adpos.y, Adpos.z);

		ad2.SetPos(Adpos.x, Adpos.y, Adpos.z);
		break;
	case 2://右上の時
		Adpos.x = SCREEN_WIDTH / 2 / 2;
		Adpos.y = Ad_falling_pos_y;
		Set_flg = true;

		ad.SetPos(Adpos.x, Adpos.y, Adpos.z);

		ad2.SetPos(Adpos.x, Adpos.y, Adpos.z);



		break;
	case 3://左下の時
		Adpos.x = -SCREEN_WIDTH / 2 / 2;
		Adpos.y = Ad_falling_pos_y;
		Set_flg = true;

		ad.SetPos(Adpos.x, Adpos.y, Adpos.z);

		ad2.SetPos(Adpos.x, Adpos.y, Adpos.z);

		break;
	case 4://右下の時
		Adpos.x = SCREEN_WIDTH / 2 / 2;
		Adpos.y = Ad_falling_pos_y;
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
	case 1://左上の時

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
				adpos.y = Ad_falling_pos_y;
				time_count = 0;
				targetposType = 0;
				Set_flg = false;
				random_flg = true;
				move_flg = false;
				m_flg = false;
				ad_end = false;
				//Set_flg = false;
			}
		}

		ad.SetPos(adpos.x, adpos.y, adpos.z);

		ad2.SetPos(adpos.x, adpos.y, adpos.z);

		break;
	case 2://右上の時

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
				adpos.y = Ad_falling_pos_y;
				time_count = 0;
				targetposType = 0;
				Set_flg = false;
				random_flg = true;
				move_flg = false;
				m_flg = false;
				ad_end = false;
				//Set_flg = false;
			}
		}
		ad.SetPos(adpos.x, adpos.y, adpos.z);

		ad2.SetPos(adpos.x, adpos.y, adpos.z);


		break;
	case 3://左下の時
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
				adpos.y = Ad_falling_pos_y;
				time_count = 0;
				targetposType = 0;
				Set_flg = false;
				random_flg = true;
				move_flg = false;
				m_flg = false;
				ad_end = true;
				ad_end = false;
				//Set_flg = false;
			}
		}

		ad.SetPos(adpos.x, adpos.y, adpos.z);

		ad2.SetPos(adpos.x, adpos.y, adpos.z);
		break;
	case 4://右下の時
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
				adpos.y = Ad_falling_pos_y;
				time_count = 0;
				targetposType = 0;
				Set_flg = false;
				random_flg = true;
				move_flg = false;
				m_flg = false;
				ad_end = false;
				//Set_flg = false;
			}
		}
		ad.SetPos(adpos.x, adpos.y, adpos.z);

		ad2.SetPos(adpos.x, adpos.y, adpos.z);
		break;
	}


}

--------------------------------------------------------------------
bool Advertisement::GetEndflg(void)
{
	return ad_end;
}
void Advertisement::SetVelocity(const DirectX::XMFLOAT2& velocity) {
	this->velocity = velocity;
}

void Advertisement::UpdatePosition() {
	position.x += velocity.x;
	position.y += velocity.y;
}