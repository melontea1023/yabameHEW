#include "Player.h"
#include <cmath>
Input input;

Player::Player()
{

}
void Player::Player_Init()
{

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
    float moveSpeed = 3.5f; // 移動速度

    if (Input::GetButtonPress(XINPUT_RIGHT_SHOULDER)) //Rボタン 
    {
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
  /*  p_move = Player_Move_Animation();
    Player::SetUV(p_move.x, p_move.y);*/


    // アナログスティックの値でプレイヤーの座標を移動
    pos.x += leftStick.x * moveSpeed;
    pos.y += leftStick.y * moveSpeed;

    if (Input::GetButtonTrigger(XINPUT_A)) //下にはたく
    {
        attack_flg = true;
        Player_Type = true;
        AttackType = 3;
    }
   

    if (Input::GetButtonTrigger(XINPUT_B)) //真ん中にはたく
    {
        attack_flg = true;
        Player_Type = true;
        AttackType = 2;
    }
    
    if (Input::GetButtonTrigger(XINPUT_Y)) //上にはたく
    {
        attack_flg = true;
        Player_Type = true;
        AttackType = 1;
    }
   

    if (attack_flg)
    {
        p_hit=Player_Hit_Animation();
        Player::SetUV(p_hit.x, p_hit.y);
    }



    //if (Input::GetButtonPress(XINPUT_A)) {
    //    Enemy target; // 仮のターゲット
    //    Attack(target); 
    //}
}

//void Player::flutter() {
//    const float flutterCost = 20.0f; // flutterのスタミナ消費量
//
//    if (stamina >= flutterCost) {
//        stamina -= flutterCost; // スタミナを消費
//        Enemy target; //Enemyクラス
//        target.TakeDamage(10);
//    }
//    else {
//       
//    }
//}

//void Player::flutter() {

//    if (stamina >= flutterCost) {
//        stamina -= flutterCost; // スタミナを消費
//    }
//}
//
//void Player::Attack(Enemy& target) {
//    // 攻撃ロジック
//    if (IsTargetInRange(target)) {
//        target.TakeDamage(10); // 例として10ダメージを与える
//    }
//}
//
//bool Player::IsTargetInRange(const Enemy& target) const {
//    float distance = std::sqrt(std::pow(target.GetPosition().x - pos.x, 2) + std::pow(target.GetPosition().y - pos.y, 2));
//    float attackRange = 50.0f; // 攻撃範囲（例として50.0f）
//
//    return distance <= attackRange;
//}



//enemy.h
//class Enemy {
//public:
//    void TakeDamage(int damage);
//    int GetHealth() const;
//    DirectX::SimpleMath::Vector2 GetPosition() const;
//
//private:
//    int health = 100; // 初期体力
//    DirectX::SimpleMath::Vector2 pos; // 位置情報
//};
//
//
//enemy.cpp
//
//void TargetComponent::TakeDamage(int damage) {
//    health -= damage;
//    if (health < 0) {
//        health = 0;
//    }
//}
//
//int TargetComponent::GetHealth() const {
//    return health;
//}
//
//DirectX::SimpleMath::Vector2 TargetComponent::GetPosition() const {
//    return pos; 
// }


void Player::Sethp(int _hp)
{
    hp = _hp;
}
int Player::Gethp()
{
    return hp;
}


bool Player::GetAttack()
{
    return attack_flg;
}

int Player::GetAttackType()
{

    return AttackType;
}
bool Player::GetPlayerType()
{
    return Player_Type;
}


int Player::GetReflectionAtk(void)
{
    return attack;
}
