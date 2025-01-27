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

    //プレイヤーアニメーション-------------------
    int p_aniCount = 0;
    int p_finish_Count = 0;
    float p_delta_time = 0.1f;
    DirectX::XMFLOAT2 p_move = { 0,0 };
    DirectX::XMFLOAT2 p_hit = { 0,0 };
    void Player_ani();
    DirectX::XMFLOAT2 Player_Move_Animation(void);
    DirectX::XMFLOAT2 Player_Hit_Animation(void);
    //-----------------------------------------------
};
