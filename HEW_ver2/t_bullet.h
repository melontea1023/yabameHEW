#pragma once
#include"Object.h"

class Test_Bullet :public Object
{
protected:


	DirectX::XMFLOAT3 eb_pos = { 0.0f,0.0f,0.0f };

	DirectX::XMFLOAT3 target_pos = { 0.0f,0.0f,0.0f };

	
	DirectX::XMFLOAT3 eb_now_pos = { 0.0f,0.0f,0.0f };

	DirectX::XMFLOAT3 divisionpos = { 0.0f,0.0f,0.0f };

	DirectX::XMFLOAT3 intermediate_target = { 0.0f,0.0f,0.0f };

	DirectX::XMFLOAT3 final_target = { 0.0f,0.0f,0.0f };

	DirectX::XMFLOAT3 current_target = { 0.0f,0.0f,0.0f };

	DirectX::XMFLOAT2 velocity = { 0.0f, 0.0f };
	//DirectX::XMFLOAT3 e_now_pos = { 0.0f, 0.0f, 0.0f };

	float send_r = 0;
	float off_screen_pos = 0;

	float dif_x, dif_y;
	float hypotenuse;

	float Check_r1 = 0, Check_r2 = 0, Check_r3 = 0;

	int life_time = 0;//弾の生存時間(弾が特定座標を超えても存在している際に使用)

	bool up_flg = false, down_flg = false, left_flg = false, rigt_flg = false;

	bool eb_end = false;
	bool eb_finish = false;

	bool reflected = false;

public:
	DirectX::XMFLOAT3 e_now_pos = { SCREEN_WIDTH / 2 / 2, SCREEN_HEIGHT / 2 / 2, 0.0f };

	bool loop_flg = false;

	float SetTarget(DirectX::XMFLOAT3, DirectX::XMFLOAT3);

	void Set_Bullet_Target(DirectX::XMFLOAT3, DirectX::XMFLOAT3, DirectX::XMFLOAT3);

	DirectX::XMFLOAT3 MoveBulllet(DirectX::XMFLOAT3, DirectX::XMFLOAT3);

	bool GetEndflg(void);
	void SetEndflg(bool);

	void SetShotfinish(bool);
	bool GetShotfinish(void);

	void MoveReflectedBullet();
	void SetVelocity(float vx,float vy);

	void SetPos(DirectX::XMFLOAT3 pos);
	void SetReflected(bool value) { reflected = value; }
	bool IsReflected() const { return reflected; }
};