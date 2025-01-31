#pragma once
#include "Object.h"
//#include "Enemy.h"
#include <vector>

class Player : public Object {
public:
    int hp = 4;
    float stamina = 100;
    int attack = 1;

    float atk;
    float health = 5;
    int AttackType = 0;
    bool Player_Type = false;
    bool attack_flg = false;
    bool Up_a_flg = false;
    bool Center_a_flg = false;
    bool Down_a_flg = false;

    Player();
    void Player_Init();
    void Update(); // プレイヤーの更新処理
    //void flutter();
    //void Attack(Enemy& target); // 攻撃メソッド
    //bool IsTargetInRange(const Enemy& target) const; // 距離計算メソッド

    void Sethp(int);
    int Gethp();
    bool GetAttack();
    int GetAttackType();
    bool GetPlayerType();

    //Reflection関係の処理-----------------------------------------------
    int GetReflectionAtk(void);
    //void SetAttack(bool);


    //-----------------------------------------------

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
