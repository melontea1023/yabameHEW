#include"t_bullet.h"




float check = 0;

bool pos_check = true;

//double send_r = 0;

float Test_Bullet::SetTarget(DirectX::XMFLOAT3 _ebpos, DirectX::XMFLOAT3 _nowebpos)
{
	target_pos = _ebpos;//目標座標
	e_now_pos = _nowebpos; //ボスの現在の座標

	dif_x = e_now_pos.x - target_pos.x;//プレイヤーの座標とエネミーの座標の差分(横)

	dif_y = e_now_pos.y - target_pos.y;//プレイヤーの座標とエネミーの座標の差分(縦)

	float angle = atan2(dif_y, dif_x);

	send_r = angle * (180 / DirectX::XM_PI);;

	return send_r;
}


void Test_Bullet::Set_Bullet_Target(DirectX::XMFLOAT3 _ebpos, DirectX::XMFLOAT3 _nowebpos, DirectX::XMFLOAT3 _bullet_pos)
{
	DirectX::XMFLOAT3 player_pos = _ebpos;//プレイヤー座標
	eb_now_pos = _nowebpos; //ボスの現在の座標
	// プレイヤー座標を中間目標に設定
	intermediate_target = _ebpos;

	// 弾の現在位置
	eb_now_pos = _nowebpos;

	// 画面外に向かう最終目標を計算
	DirectX::XMFLOAT3 direction;
	direction.x = _ebpos.x - _bullet_pos.x; // X方向
	direction.y = _ebpos.y - _bullet_pos.y; // Y方向

	// 正規化
	float length = sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length != 0) {
		direction.x /= length;
		direction.y /= length;
	}

	// 画面外の目標を設定（プレイヤー位置からさらに延長線上に進む）
	float extension = 1500.0f; // プレイヤーを通り越して画面外まで進む距離
	final_target.x = _ebpos.x + direction.x * extension;
	final_target.y = _ebpos.y + direction.y * extension;

}



DirectX::XMFLOAT3 Test_Bullet::MoveBulllet(DirectX::XMFLOAT3 _ebpos, DirectX::XMFLOAT3 _nowebpos) //左から順にプレイヤーの位置、ボスの位置
{

	// 現在の弾の位置
	divisionpos = _nowebpos;

	// 寿命管理
	life_time++;
	if (life_time >= 480) { // 寿命が尽きたら画面外に移動
		divisionpos = { 1000.0f, 1000.0f, 0.0f };
		life_time = 0;
		loop_flg = true;
		pos_check = true;
		return divisionpos;
	}

	// 現在の目標を設定（中間目標 or 最終目標）
	if (pos_check)
	{
		current_target = intermediate_target;
	}
	// 中間目標（プレイヤー）に到達したら最終目標に切り替える
	float distance_to_intermediate = sqrt(pow(intermediate_target.x - divisionpos.x, 2) + pow(intermediate_target.y - divisionpos.y, 2));

	if (distance_to_intermediate < 10.0f) // 中間目標に近づいたら
	{
		current_target = final_target; // 最終目標に切り替え
		pos_check = false;
	}



	// 現在の目標に向かう方向ベクトルを計算
	DirectX::XMFLOAT3 direction;
	direction.x = current_target.x - divisionpos.x;
	direction.y = current_target.y - divisionpos.y;

	// 正規化
	float length = sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length != 0) {
		direction.x /= length;
		direction.y /= length;
	}

	// 弾を移動
	float speed = 10.0f;
	divisionpos.x += direction.x * speed;
	divisionpos.y += direction.y * speed;


	return divisionpos;

}
