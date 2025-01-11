#pragma once
#include "Object.h"
#include "Enemy.h"
#include <vector>

class Player : public Object {
public:
    float stamina = 100;
    float atk;
    float health = 5;

    Player();
    void Init(const wchar_t* imgname, int sx = 1, int sy = 1);
    void Update(); // �v���C���[�̍X�V����
    void flutter();
    void Attack(Enemy& target); // �U�����\�b�h
    bool IsTargetInRange(const Enemy& target) const; // �����v�Z���\�b�h
};
