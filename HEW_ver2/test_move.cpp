//#include"Enemy.h"
#include<stdlib.h>
#include"Game.h"
#include"time.h"

bool bullet_set_flg = true;
bool bullet_move_flg = false;
DirectX::XMFLOAT3 Get_ebpos = { 0.0f,0.0f,0.0f };

void TestEnemy::CharacterInit(void)
{

	eb.Init(L"asset/link.png");   //リンクを初期化
	eb.SetPos(SCREEN_WIDTH / 2 / 2, SCREEN_HEIGHT / 2 / 2, 0.0f);//位置を設定
	eb.SetSize(750.0f, 375.0f, 0.0f); //大きさを設定
	eb.SetAngle(0.0f);   //角度を設定

	ad.Advertisement_raining_Init();

}


void TestEnemy::test_Update(DirectX::XMFLOAT3 _pos, DirectX::XMFLOAT3 _nowepos)//左からPlayer,Enemyの座標
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
	case 1://リンク投げに関係する処理を入れる

		if (Ed_Animation_end_flg) //リンク投げアニメーションが終わっているかの確認
		{
			test_Update(_playerPosition, TestEnemy::GetPos());
		}
		else
		{
			link_e=link_throwing_Animation();
			TestEnemy::SetUV(link_e.x, link_e.y);

		}
		break;
	case 2://移動に関係する処理を入れる

		break;
	case 3://広告降らしに関係する処理を入れる



		if (Ad_Animation_end_flg) //広告降らしアニメーションが終わっているかの確認
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


//ボスの行動パターンメモ---------------------------
//一回目：リンク投げ50％、広告降らし30％、移動20％
//二回目：リンク投げ50％、広告降らし20％、移動30％
//三回目：リンク投げ40％、広告降らし30％、移動30％
//四回目：リンク投げ30％、広告降らし10％、移動60％
//五回目：リンク投げ20％、広告降らし00％、移動80％
//六回目：リンク投げ00％、広告降らし00％、移動100％
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
			return_num = 1;//リンク投げ
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
			return_num = 1;//リンク投げ
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
			return_num = 1;//リンク投げ
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
			return_num = 1;//リンク投げ
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
			return_num = 1; //リンク投げ
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