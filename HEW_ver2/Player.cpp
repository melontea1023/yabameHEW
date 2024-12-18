#include "Player.h"

Player::Player() : currentWeaponIndex(0) {}

void Player::Init(const wchar_t* imgname, int sx, int sy) {
    Object::Init(imgname, sx, sy);

    // ��������̒ǉ�
    weapons.push_back(new Weapon(0.5f, -1)); // �����e��̕���
    weapons.push_back(new Weapon(1.0f, 30)); // 30���̒e���������
}

void Player::Update(float deltaTime) {
    // ���͏����i��: �L�[�{�[�h�j
    if (/*���˃{�^��*/) {
        Fire();
    }
    if (/*����؂�ւ��{�^��*/) {
        SwitchWeapon((currentWeaponIndex + 1) % weapons.size());
    }

    // ���݂̕�����X�V
    weapons[currentWeaponIndex]->Update(deltaTime);
}

void Player::Fire() {
    float x = GetPos().x;
    float y = GetPos().y;
    float z = GetPos().z;

    // ���݂̕���Ŕ���
    weapons[currentWeaponIndex]->Fire(x, y, z, GetAngle());
}

void Player::SwitchWeapon(int index) {
    if (index >= 0 && index < weapons.size()) {
        currentWeaponIndex = index;
    }
}
