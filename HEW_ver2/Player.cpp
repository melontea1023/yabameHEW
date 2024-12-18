#include "Player.h"

Player::Player() : currentWeaponIndex(0) {}

void Player::Init(const wchar_t* imgname, int sx, int sy) {
    Object::Init(imgname, sx, sy);

    // 初期武器の追加
    weapons.push_back(new Weapon(0.5f, -1)); // 無限弾薬の武器
    weapons.push_back(new Weapon(1.0f, 30)); // 30発の弾薬を持つ武器
}

void Player::Update(float deltaTime) {
    // 入力処理（例: キーボード）
    if (/*発射ボタン*/) {
        Fire();
    }
    if (/*武器切り替えボタン*/) {
        SwitchWeapon((currentWeaponIndex + 1) % weapons.size());
    }

    // 現在の武器を更新
    weapons[currentWeaponIndex]->Update(deltaTime);
}

void Player::Fire() {
    float x = GetPos().x;
    float y = GetPos().y;
    float z = GetPos().z;

    // 現在の武器で発射
    weapons[currentWeaponIndex]->Fire(x, y, z, GetAngle());
}

void Player::SwitchWeapon(int index) {
    if (index >= 0 && index < weapons.size()) {
        currentWeaponIndex = index;
    }
}
