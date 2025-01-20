#pragma once
#include "Object.h"
#include "Input.h"
#include <vector>

class Player : public Object {
private:
    DirectX::XMFLOAT2 velocity;    // 反射オブジェクトの方向
    float reflectSpeed;           // 反射オブジェクトの速度
    float attackRange;            // 範囲
    float attackDamage;           // ダメージ

public:
    float stamina;                // プレイヤーのスタミナ
    float health;                 // プレイヤーの体力

    Player();
    void Init(const wchar_t* textureFile, int sx = 1, int sy = 1); // 初期化
    void Update();                 // 更新処理
    void Reflect();                // 反射処理
    void Attack(Object& target); // 攻撃処理
    bool IsTargetInRange(const Object& target) const; // 対象が攻撃範囲内か判定
};

