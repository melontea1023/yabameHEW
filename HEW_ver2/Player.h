#pragma once
#include "Object.h"
#include "Input.h"
#include <vector>
#include "Bullet.h"

class Player : public Object {
private:
    DirectX::XMFLOAT2 velocity;    // 反射オブジェクトの方向
    float reflectSpeed;           // 反射オブジェクトの速度
    float attackRange;            // 範囲
    float attackDamage;           // ダメージ

    float detectionRange = 100.0f; // 範囲の設定
public:
    float stamina;                // プレイヤーのスタミナ
    float health;                 // プレイヤーの体力

    

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
    void Init(const wchar_t* textureFile, int sx = 1, int sy = 1); // 初期化
    void Update();                 // 更新処理
    void Reflect(Bullet& bullet);;                // 反射処理
    void Attack(Object& target); // 攻撃処理
    bool IsTargetInRange(const Object& target) const; // 対象が攻撃範囲内か判定
};

