#include"Player.h"

void Player::Player_ani()
{
	p_hit = Player_Hit_Animation();

	Player::SetUV(p_hit.x, p_hit.y);
}


//�ړ����Ă��鎞�ɂ��̊֐����Ăяo��
DirectX::XMFLOAT2 Player::Player_Move_Animation(void)
{
	static float elapsed_time = 0.0f;
	static int ad_finish_count = 0;
	float frame_time = 0.6f; // �t���[���؂�ւ��Ԋu�i�b�P�ʁj

	elapsed_time += p_delta_time;

	if (p_move.x == 3)
	{
		ad_finish_count++;
		if (ad_finish_count >= 60)
		{
			p_move.x = 0;
			ad_finish_count = 0;
			elapsed_time = 0.0f;
		}
	}
	else
	{
		if (elapsed_time >= frame_time)
		{
			elapsed_time = 0.0f;
			p_move.x += 1;
		}
	}
	return p_move;
}


DirectX::XMFLOAT2 Player::Player_Hit_Animation(void) //�͂����A�j���[�V����
{
	static float elapsed_time = 0.0f;
	static int ad_finish_count = 0;
	float frame_time = 0.6f; // �t���[���؂�ւ��Ԋu�i�b�P�ʁj

	elapsed_time += p_delta_time;

	if (p_hit.x == 3)
	{
		ad_finish_count++;
		if (ad_finish_count >= 60)
		{
			p_hit.x = 0;
			ad_finish_count = 0;
			elapsed_time = 0.0f;
		}
	}
	else
	{
		if (elapsed_time >= frame_time)
		{
			elapsed_time = 0.0f;
			p_hit.x += 1;
		}
	}
	return p_hit;
}