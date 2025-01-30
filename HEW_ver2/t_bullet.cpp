#include"t_bullet.h"




float check = 0;

bool pos_check = true;

//double send_r = 0;

float Test_Bullet::SetTarget(DirectX::XMFLOAT3 _ebpos, DirectX::XMFLOAT3 _nowebpos)
{
	target_pos = _ebpos; // 目標座標
	e_now_pos = _nowebpos; // ボスの現在の座標

	// 差分計算（結果をキャッシュ）
	float dif_x = e_now_pos.x - target_pos.x;
	float dif_y = e_now_pos.y - target_pos.y;

	// atan2 計算
	float angle = atan2(dif_y, dif_x);

	// ラジアンから度に変換
	return angle * (180.0f / DirectX::XM_PI);
}


void Test_Bullet::Set_Bullet_Target(DirectX::XMFLOAT3 _ebpos, DirectX::XMFLOAT3 _nowebpos, DirectX::XMFLOAT3 _bullet_pos)
{

	// 中間目標と弾の現在位置を設定
	intermediate_target = _ebpos;

	// 方向ベクトルを計算（結果をキャッシュ）
	float dif_x = _ebpos.x - _bullet_pos.x;
	float dif_y = _ebpos.y - _bullet_pos.y;

	// 長さを計算
	float length = sqrt(dif_x * dif_x + dif_y * dif_y);

	// 長さがゼロでない場合に正規化
	if (length > 0.0f) {
		dif_x /= length;
		dif_y /= length;
	}

	// 画面外の目標を設定
	float extension = 1500.0f;
	final_target.x = _ebpos.x + dif_x * extension;
	final_target.y = _ebpos.y + dif_y * extension;

}



DirectX::XMFLOAT3 Test_Bullet::MoveBulllet(DirectX::XMFLOAT3 _ebpos, DirectX::XMFLOAT3 _nowebpos) //左から順にプレイヤーの位置、ボスの位置
{
	//eb_end = false;
	divisionpos = _nowebpos;

	// 寿命管理
	if (++life_time >= 420) {
		divisionpos = { 1000.0f, 1000.0f, 0.0f };
		life_time = 0;
		pos_check = true;
		eb_end = true;
		eb_finish = true;
		return divisionpos;
	}

	// 現在の目標を設定
	if (pos_check) {
		current_target = intermediate_target;
	}

	// 中間目標への距離の平方（平方根を計算せず直接比較）
	float dif_x = intermediate_target.x - divisionpos.x;
	float dif_y = intermediate_target.y - divisionpos.y;
	float distance_squared_to_intermediate = dif_x * dif_x + dif_y * dif_y;

	if (distance_squared_to_intermediate < 100.0f) { // 10.0f の二乗
		current_target = final_target;
		pos_check = false;
	}

	// 現在の目標への方向を計算
	dif_x = current_target.x - divisionpos.x;
	dif_y = current_target.y - divisionpos.y;

	// 方向ベクトルの正規化
	float length_squared = dif_x * dif_x + dif_y * dif_y;

	// 距離が一定以上でない場合は正規化をスキップ
	if (length_squared > 1e-6f) {
		float inv_length = 1.0f / sqrt(length_squared);
		dif_x *= inv_length;
		dif_y *= inv_length;

	}

	// 弾の移動
	float speed = 10.0f;
	divisionpos.x += dif_x * speed;
	divisionpos.y += dif_y * speed;

	return divisionpos;

}

bool Test_Bullet::GetEndflg(void)
{
	return eb_end;
}

void Test_Bullet::SetEndflg(bool _reset)
{
	eb_end = _reset;
}

bool Test_Bullet::GetShotfinish(void)
{
	return eb_finish;
}


void Test_Bullet::SetShotfinish(bool _check)
{
	eb_finish = _check;
}

void Test_Bullet::MoveReflectedBullet() {	// 反射後の弾の移動
	e_now_pos.x += velocity.x;
	e_now_pos.y += velocity.y;
	SetPos(e_now_pos);
}
void Test_Bullet::SetVelocity(float vx, float vy) {
	velocity.x = vx;
	velocity.y = vy;

}

void Test_Bullet::SetPos(DirectX::XMFLOAT3 pos) {
	e_now_pos = pos;
}