#pragma once
#include"Object.h"

class Test_Bullet :public Object
{
protected:

	DirectX::XMFLOAT3 eb_pos = { 0.0f,0.0f,0.0f };

	DirectX::XMFLOAT3 target_pos = { 0.0f,0.0f,0.0f };

	DirectX::XMFLOAT3 e_now_pos = { 0.0f,0.0f,0.0f };

	DirectX::XMFLOAT3 eb_now_pos = { 0.0f,0.0f,0.0f };

	DirectX::XMFLOAT3 divisionpos = { 0.0f,0.0f,0.0f };

	DirectX::XMFLOAT3 intermediate_target = { 0.0f,0.0f,0.0f };

	DirectX::XMFLOAT3 final_target = { 0.0f,0.0f,0.0f };

	DirectX::XMFLOAT3 current_target = { 0.0f,0.0f,0.0f };



	float send_r = 0;
	float off_screen_pos = 0;

	float dif_x, dif_y;
	float hypotenuse;

	float Check_r1 = 0, Check_r2 = 0, Check_r3 = 0;

	int life_time = 0;//íeÇÃê∂ë∂éûä‘(íeÇ™ì¡íËç¿ïWÇí¥Ç¶ÇƒÇ‡ë∂ç›ÇµÇƒÇ¢ÇÈç€Ç…égóp)

	bool up_flg = false, down_flg = false, left_flg = false, rigt_flg = false;



public:
	bool loop_flg = false;

	float SetTarget(DirectX::XMFLOAT3, DirectX::XMFLOAT3);

	void Set_Bullet_Target(DirectX::XMFLOAT3, DirectX::XMFLOAT3, DirectX::XMFLOAT3);

	DirectX::XMFLOAT3 MoveBulllet(DirectX::XMFLOAT3, DirectX::XMFLOAT3);

};