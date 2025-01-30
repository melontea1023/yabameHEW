#include"testenemy.h"
#include"time.h"
#include <cstdlib> // rand, srand
#include <ctime>   // time
int eb_count = 0;

//
void TestEnemy::CharacterInit(void)
{

	eb.Init(L"asset/link.png");   //リンクを初期化
	eb.SetPos(epos);//位置を設定
	eb.SetSize(750.0f, 375.0f, 0.0f); //大きさを設定
	eb.SetAngle(0.0f);   //角度を設定
	ad.Advertisement_raining_Init();

}


void TestEnemy::test_Update(DirectX::XMFLOAT3 _pos, DirectX::XMFLOAT3 _nowepos)//左からPlayer,Enemyの座標
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
	case 1://リンク投げに関係する処理を入れる
		if (Ed_Animation_end_flg) //リンク投げアニメーションが終わっているかの確認
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
					Ed_Animation_end_flg = false; // アニメーション終了フラグをリセット
					e_Running_flg = false;       // 次の行動を許可
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
	case 2://移動に関係する処理を入れる
		if (moving_flg)
		{
			epos = TestEnemy::GetPos();  // ボスの現在位置を取得
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
			e_Running_flg = false;       // 次の行動を許可
		}

		break;
	case 3://広告降らしに関係する処理を入れる
		if (Ad_Animation_end_flg) //広告降らしアニメーションが終わっているかの確認
		{
			//esound.Play(SOUND_LABEL_ADVAGO);
			ad.Advertisement_raining_Update(_playerPosition);
			if (ad.GetEndflg())
			{
				Ad_Animation_end_flg = false; // アニメーション終了フラグをリセット
				e_Running_flg = false;       // 次の行動を許可
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
////ボスの行動パターンメモ---------------------------
////一回目：リンク投げ50％、広告降らし30％、移動20％
////二回目：リンク投げ50％、広告降らし20％、移動30％
////三回目：リンク投げ40％、広告降らし30％、移動30％
////四回目：リンク投げ30％、広告降らし10％、移動60％
////五回目：リンク投げ20％、広告降らし00％、移動80％
////六回目：リンク投げ00％、広告降らし00％、移動100％
////--------------------------------------------
//
int TestEnemy::probability(void)
{
	srand(static_cast<unsigned int>(time(0)));

	// 各行動の確率
	int linkThrow = 0;
	int adRain = 0;
	int move = 0;
	// ターンごとの確率設定
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


	// ランダムで行動を決定
	int randomValue = rand() % 100 + 1; // 1～100のランダム値
	if (randomValue < linkThrow) {
		return 1; // リンク投げ
	}
	else if (randomValue < linkThrow + adRain) {
		return 3; // 広告降らし
	}
	else {
		return 2; // 移動
	}
}