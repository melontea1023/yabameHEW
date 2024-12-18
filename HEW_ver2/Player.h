#pragma once
#include "Object.h"
#include "Weapon.h"
#include <vector>

class Player : public Object {
private:
    std::vector<Weapon*> weapons; // ����̃��X�g
    int currentWeaponIndex;       // ���ݑI�𒆂̕���
public:
    Player();
    void Init(const wchar_t* imgname, int sx = 1, int sy = 1);
    void Update(float deltaTime); // �v���C���[�̍X�V����
    void Fire();                  // ���݂̕���Ŕ���
    void SwitchWeapon(int index); // �����؂�ւ���
};
