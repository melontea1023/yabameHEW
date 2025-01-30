#pragma once
#include"Object.h"


class PlayerBullet : public Object
{
protected:

	bool p_starting = false;
	int player_bulletType = 0;

public:
	void Move_Update();
	void p_BulletMove();

	void P_BDraw();

	void SetBulletType(int); //弾の発射が上、中央、下のいずれかをplayer_bulletTypeに格納
	void Set_p_starting(bool); //プレイヤーの弾を起動するかどうかのフラグに格納





};