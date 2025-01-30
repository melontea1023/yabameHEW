#include "Player.h"
#include <cmath>

Player::Player()//値調整
    : stamina(100.0f), health(100.0f), reflectSpeed(100.0f), attackRange(100.0f), attackDamage(10.0f) {
    velocity = { 0.0f, 0.0f };//imakannkeinasi
}

void Player::Init(const wchar_t* textureFile, int sx, int sy) {
    Object::Init(textureFile, sx, sy);
    SetPos(0.0f, 0.0f, 0.0f);
    SetSize(70.0f, 100.0f, 0.0f);
    SetAngle(0.0f);
}

void Player::Update() {
    float moveSpeed = 20.0f;
    // スタミナに応じた移動速度調整
    if (Input::GetButtonPress(XINPUT_RIGHT_SHOULDER)) {
        if (stamina > 0.0f) {
            stamina -= 0.5f; // スタミナ消費
            moveSpeed += 10.0f;
        }
    }
    else {
        stamina += 0.5f; // スタミナ回復
        if (stamina > 100.0f) stamina = 100.0f;
    }
    if (Input::GetKeyTrigger(VK_A)) {
        //pos.x += 50;
    }
    // 左アナログスティックによる移動
    DirectX::SimpleMath::Vector2 leftStick = Input::GetLeftAnalogStick();
    pos.x += leftStick.x * moveSpeed;
    pos.y += leftStick.y * moveSpeed;
}

bool Player::Reflect(Test_Bullet& bullet) {
    //esound.Play(SOUND_LABEL_FRAP);
    if (Input::GetButtonTrigger(XINPUT_Y)|| Input::GetKeyPress(VK_A) ){
        velocity = { 100.0f, 100.0f }; // 右上 
    }
    else if (Input::GetButtonTrigger(XINPUT_B)) {
        velocity = { -10.0f, 0.0f }; // 左
    }
    else if (Input::GetButtonTrigger(XINPUT_A)) {
        velocity = { 10.0f, -10.0f }; // 右下
        bullet.SetVelocity(100, 100);
        pos.x++;
        MessageBoxA(NULL, "A", "デバッグ", MB_OK);
    }
    else {
        return false; // どのボタンも押されていないなら反射しない
    }

    bullet.SetVelocity(velocity.x * reflectSpeed, velocity.y * reflectSpeed);
    bullet.SetReflected(true);
    return true; // 反射成功
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
