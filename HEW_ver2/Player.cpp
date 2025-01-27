#include "Player.h"
#include <cmath>

Player::Player()//値調整
    : stamina(100.0f), health(100.0f), reflectSpeed(10.0f), attackRange(100.0f), attackDamage(10.0f) {
    velocity = { 0.0f, 0.0f };//imakannkeinasi
}

void Player::Init(const wchar_t* textureFile, int sx, int sy) {
    Object::Init(textureFile, sx, sy);
    SetPos(0.0f, 0.0f, 0.0f);
    SetSize(70.0f, 100.0f, 0.0f);
    SetAngle(0.0f);
}

void Player::Update() {
    float moveSpeed = 5.0f;

    // スタミナに応じた移動速度調整
    if (Input::GetButtonPress(XINPUT_RIGHT_SHOULDER)) {
        if (stamina > 0.0f) {
            stamina -= 0.5f; // スタミナ消費
            moveSpeed += 2.0f;
        }
    }
    else {
        stamina += 0.5f; // スタミナ回復
        if (stamina > 100.0f) stamina = 100.0f;
    }

    // 左アナログスティックによる移動
    DirectX::SimpleMath::Vector2 leftStick = Input::GetLeftAnalogStick();
    pos.x += leftStick.x * moveSpeed;
    pos.y += leftStick.y * moveSpeed;

}

void Player::Reflect(Bullet& bullet) {//反射角度調整
    if (Input::GetButtonPress(XINPUT_A)) {
        velocity = { 1.0f, 1.0f }; // 右上
    }
    else if (Input::GetButtonPress(XINPUT_B)) {
        velocity = { 1.0f, 0.0f }; // 右
    }
    else if (Input::GetButtonPress(XINPUT_X)) {
        velocity = { 1.0f, -1.0f }; // 右下
    }
    if (IsTargetInRange(bullet)) {
        bullet.SetVelocity(velocity.x * reflectSpeed, velocity.y * reflectSpeed); // Bulletの速度を設定
    }
}

void Player::Attack(Object& target) {
    if (IsTargetInRange(target)) {
        // ダメージ系の処理
        target.SetColor(1.0f, 0.0f, 0.0f, 1.0f); // 敵赤くするやつ
    }
}

bool Player::IsTargetInRange(const Object& target) const {
    float dx = target.GetPos().x - position.x;
    float dy = target.GetPos().y - position.y;
    float distanceSquared = dx * dx + dy * dy;
    return distanceSquared <= (attackRange * attackRange);
}