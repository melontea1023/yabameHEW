#pragma once
#include "Object.h"
//#include "Enemy.h"
#include <vector>

class Player : public Object {
public:
    float stamina = 100;
    float atk;
    float health = 5;

    

    Player();
    void Player_Init();
    void Update(); // �v���C���[�̍X�V����
    //void flutter();
    //void Attack(Enemy& target); // �U�����\�b�h
    //bool IsTargetInRange(const Enemy& target) const; // �����v�Z���\�b�h

    //�v���C���[�A�j���[�V����-------------------
    int p_aniCount = 0;
    int p_finish_Count = 0;
    float p_delta_time = 0.1f;
    DirectX::XMFLOAT2 p_move = { 0,0 };
    DirectX::XMFLOAT2 p_hit = { 0,0 };
    void Player_ani();
    DirectX::XMFLOAT2 Player_Move_Animation(void);
    DirectX::XMFLOAT2 Player_Hit_Animation(void);
    //-----------------------------------------------
};
