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
    void Update(); // プレイヤーの更新処理
    //void flutter();
    //void Attack(Enemy& target); // 攻撃メソッド
    //bool IsTargetInRange(const Enemy& target) const; // 距離計算メソッド
};
