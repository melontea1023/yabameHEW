#include"testenemy.h"


DirectX::XMFLOAT2 TestEnemy::Advertisement_raining_Animation()
{
	if (ad_e.x == 3)
	{
		finish_Count++;
		if (finish_Count >= 130)
		{
			ad_e.x = 0;
			aniCount = 0;
			finish_Count = 0;
			//ここの下に広告降らしを起動するフラグを起動する----------------------
			Ad_Animation_end_flg = true;
			//--------------------------------------------------------------------
		}
		
	}
	else
	{
		aniCount++;
		if (aniCount % 12 == 1)
		{
			ad_e.x += 1;
		}
	}
	return ad_e;
}



DirectX::XMFLOAT2 TestEnemy::link_throwing_Animation()
{
	if (link_e.x == 3)
	{
		finish_Count++;
		if (finish_Count >= 80)
		{
			link_e.x = 0;
			aniCount = 0;
			finish_Count = 0;
			//ここの下にリンク投げを起動するフラグを起動する----------------------
			Ed_Animation_end_flg = true;
			bullet_set_flg = true;
			//--------------------------------------------------------------------
		}

	}
	else
	{
		aniCount++;
		if (aniCount % 15 == 1)
		{
			link_e.x += 1;
		}
	}
	return link_e;
}



//void Advertisement_raining_Animation(void)
//{
//	DirectX::XMFLOAT2 ad_e = anienemy.GetUV();
//
//
//}
//
//
//
//void link_throwing_Animation(void)
//{
//	DirectX::XMFLOAT2 link_e = anienemy.GetUV();
//
//
//}
//
