#include "Player.h"

Input input;

void Player::Init(const wchar_t* imgname, int sx, int sy) {
    Object::Init(imgname, sx, sy);
}

void Player::Update() {
    //// 入力処理（例: キーボード）
    //if (Input::GetKeyPress(VK_A) || Input::GetButtonPress(XINPUT_LEFT)) {

    //}
    //if (Input::GetKeyPress(VK_D) || Input::GetButtonPress(XINPUT_RIGHT)) {

    //}
    //if (Input::GetKeyPress(VK_W) || Input::GetButtonPress(XINPUT_UP)) {

    //}
    //if (Input::GetKeyPress(VK_S) || Input::GetButtonPress(XINPUT_DOWN)) {

    //}
    float moveSpeed = 5.0f; // 移動速度

    if (Input::GetButtonPress(XINPUT_RIGHT_SHOULDER)) {
        if (stamina > 0.0f) { // スタミナが残っている場合のみ消費
            stamina -= 0.5f; // スタミナ消費
            moveSpeed += 2.0f; // 移動速度を上昇
        }
        else {
            stamina = 0.0f; // スタミナが0以下にならないよう制限
        }
    }
    else {
        stamina += 0.5f; // スタミナの自然回復
        if (stamina > 100.0f) stamina = 100.0f; // スタミナの上限を100に
    }
        // 左アナログスティックの入力を取得
    DirectX::SimpleMath::Vector2 leftStick = Input::GetLeftAnalogStick();

    // アナログスティックの値でプレイヤーの座標を移動


    pos.x += leftStick.x * moveSpeed;
    pos.y += leftStick.y * moveSpeed;

}

void Player::flutter() {
    const float flutterCost = 20.0f; // flutterのスタミナ消費量

    if (stamina >= flutterCost) {
        stamina -= flutterCost; // スタミナを消費

    }
    else {
       
    }
}