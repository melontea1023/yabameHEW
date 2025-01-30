#include"t_bullet.h"




float check = 0;

bool pos_check = true;

//double send_r = 0;

float Test_Bullet::SetTarget(DirectX::XMFLOAT3 _ebpos, DirectX::XMFLOAT3 _nowebpos)
{
	target_pos = _ebpos; // �ڕW���W
	e_now_pos = _nowebpos; // �{�X�̌��݂̍��W

	// �����v�Z�i���ʂ��L���b�V���j
	float dif_x = e_now_pos.x - target_pos.x;
	float dif_y = e_now_pos.y - target_pos.y;

	// atan2 �v�Z
	float angle = atan2(dif_y, dif_x);

	// ���W�A������x�ɕϊ�
	return angle * (180.0f / DirectX::XM_PI);
}


void Test_Bullet::Set_Bullet_Target(DirectX::XMFLOAT3 _ebpos, DirectX::XMFLOAT3 _nowebpos, DirectX::XMFLOAT3 _bullet_pos)
{

	// ���ԖڕW�ƒe�̌��݈ʒu��ݒ�
	intermediate_target = _ebpos;

	// �����x�N�g�����v�Z�i���ʂ��L���b�V���j
	float dif_x = _ebpos.x - _bullet_pos.x;
	float dif_y = _ebpos.y - _bullet_pos.y;

	// �������v�Z
	float length = sqrt(dif_x * dif_x + dif_y * dif_y);

	// �������[���łȂ��ꍇ�ɐ��K��
	if (length > 0.0f) {
		dif_x /= length;
		dif_y /= length;
	}

	// ��ʊO�̖ڕW��ݒ�
	float extension = 1500.0f;
	final_target.x = _ebpos.x + dif_x * extension;
	final_target.y = _ebpos.y + dif_y * extension;

}



DirectX::XMFLOAT3 Test_Bullet::MoveBulllet(DirectX::XMFLOAT3 _ebpos, DirectX::XMFLOAT3 _nowebpos) //�����珇�Ƀv���C���[�̈ʒu�A�{�X�̈ʒu
{
	//eb_end = false;
	divisionpos = _nowebpos;

	// �����Ǘ�
	if (++life_time >= 420) {
		divisionpos = { 1000.0f, 1000.0f, 0.0f };
		life_time = 0;
		pos_check = true;
		eb_end = true;
		eb_finish = true;
		return divisionpos;
	}

	// ���݂̖ڕW��ݒ�
	if (pos_check) {
		current_target = intermediate_target;
	}

	// ���ԖڕW�ւ̋����̕����i���������v�Z�������ڔ�r�j
	float dif_x = intermediate_target.x - divisionpos.x;
	float dif_y = intermediate_target.y - divisionpos.y;
	float distance_squared_to_intermediate = dif_x * dif_x + dif_y * dif_y;

	if (distance_squared_to_intermediate < 100.0f) { // 10.0f �̓��
		current_target = final_target;
		pos_check = false;
	}

	// ���݂̖ڕW�ւ̕������v�Z
	dif_x = current_target.x - divisionpos.x;
	dif_y = current_target.y - divisionpos.y;

	// �����x�N�g���̐��K��
	float length_squared = dif_x * dif_x + dif_y * dif_y;

	// ���������ȏ�łȂ��ꍇ�͐��K�����X�L�b�v
	if (length_squared > 1e-6f) {
		float inv_length = 1.0f / sqrt(length_squared);
		dif_x *= inv_length;
		dif_y *= inv_length;

	}

	// �e�̈ړ�
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

void Test_Bullet::MoveReflectedBullet() {	// ���ˌ�̒e�̈ړ�
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