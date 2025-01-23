#include"t_bullet.h"




float check = 0;

bool pos_check = true;

//double send_r = 0;

float Test_Bullet::SetTarget(DirectX::XMFLOAT3 _ebpos, DirectX::XMFLOAT3 _nowebpos)
{
	target_pos = _ebpos;//�ڕW���W
	e_now_pos = _nowebpos; //�{�X�̌��݂̍��W

	dif_x = e_now_pos.x - target_pos.x;//�v���C���[�̍��W�ƃG�l�~�[�̍��W�̍���(��)

	dif_y = e_now_pos.y - target_pos.y;//�v���C���[�̍��W�ƃG�l�~�[�̍��W�̍���(�c)

	float angle = atan2(dif_y, dif_x);

	send_r = angle * (180 / DirectX::XM_PI);;

	return send_r;
}


void Test_Bullet::Set_Bullet_Target(DirectX::XMFLOAT3 _ebpos, DirectX::XMFLOAT3 _nowebpos, DirectX::XMFLOAT3 _bullet_pos)
{
	DirectX::XMFLOAT3 player_pos = _ebpos;//�v���C���[���W
	eb_now_pos = _nowebpos; //�{�X�̌��݂̍��W
	// �v���C���[���W�𒆊ԖڕW�ɐݒ�
	intermediate_target = _ebpos;

	// �e�̌��݈ʒu
	eb_now_pos = _nowebpos;

	// ��ʊO�Ɍ������ŏI�ڕW���v�Z
	DirectX::XMFLOAT3 direction;
	direction.x = _ebpos.x - _bullet_pos.x; // X����
	direction.y = _ebpos.y - _bullet_pos.y; // Y����

	// ���K��
	float length = sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length != 0) {
		direction.x /= length;
		direction.y /= length;
	}

	// ��ʊO�̖ڕW��ݒ�i�v���C���[�ʒu���炳��ɉ�������ɐi�ށj
	float extension = 1500.0f; // �v���C���[��ʂ�z���ĉ�ʊO�܂Ői�ދ���
	final_target.x = _ebpos.x + direction.x * extension;
	final_target.y = _ebpos.y + direction.y * extension;

}



DirectX::XMFLOAT3 Test_Bullet::MoveBulllet(DirectX::XMFLOAT3 _ebpos, DirectX::XMFLOAT3 _nowebpos) //�����珇�Ƀv���C���[�̈ʒu�A�{�X�̈ʒu
{

	// ���݂̒e�̈ʒu
	divisionpos = _nowebpos;

	// �����Ǘ�
	life_time++;
	if (life_time >= 480) { // �������s�������ʊO�Ɉړ�
		divisionpos = { 1000.0f, 1000.0f, 0.0f };
		life_time = 0;
		loop_flg = true;
		pos_check = true;
		return divisionpos;
	}

	// ���݂̖ڕW��ݒ�i���ԖڕW or �ŏI�ڕW�j
	if (pos_check)
	{
		current_target = intermediate_target;
	}
	// ���ԖڕW�i�v���C���[�j�ɓ��B������ŏI�ڕW�ɐ؂�ւ���
	float distance_to_intermediate = sqrt(pow(intermediate_target.x - divisionpos.x, 2) + pow(intermediate_target.y - divisionpos.y, 2));

	if (distance_to_intermediate < 10.0f) // ���ԖڕW�ɋ߂Â�����
	{
		current_target = final_target; // �ŏI�ڕW�ɐ؂�ւ�
		pos_check = false;
	}



	// ���݂̖ڕW�Ɍ����������x�N�g�����v�Z
	DirectX::XMFLOAT3 direction;
	direction.x = current_target.x - divisionpos.x;
	direction.y = current_target.y - divisionpos.y;

	// ���K��
	float length = sqrt(direction.x * direction.x + direction.y * direction.y);
	if (length != 0) {
		direction.x /= length;
		direction.y /= length;
	}

	// �e���ړ�
	float speed = 10.0f;
	divisionpos.x += direction.x * speed;
	divisionpos.y += direction.y * speed;


	return divisionpos;

}
