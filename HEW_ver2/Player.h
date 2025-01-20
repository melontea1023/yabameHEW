#pragma once
#include "Object.h"
#include "Input.h"
#include <vector>

class Player : public Object {
private:
    DirectX::XMFLOAT2 velocity;    // ���˃I�u�W�F�N�g�̕���
    float reflectSpeed;           // ���˃I�u�W�F�N�g�̑��x
    float attackRange;            // �͈�
    float attackDamage;           // �_���[�W

public:
    float stamina;                // �v���C���[�̃X�^�~�i
    float health;                 // �v���C���[�̗̑�

    Player();
    void Init(const wchar_t* textureFile, int sx = 1, int sy = 1); // ������
    void Update();                 // �X�V����
    void Reflect();                // ���ˏ���
    void Attack(Object& target); // �U������
    bool IsTargetInRange(const Object& target) const; // �Ώۂ��U���͈͓�������
};

