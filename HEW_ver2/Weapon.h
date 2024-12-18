#pragma once
#include <vector>
#include "Bullet.h"

class Weapon {
private:
    std::vector<Bullet*> bullets; // 弾丸たち
    float fireRate;               // 発射間隔
    float timeSinceLastShot;      // 最後に弾丸を発射してからの経過時間

public:
    void Init(float fireRate);
    void Fire(const DirectX::XMFLOAT3& position, float angle);
    void Update(float deltaTime);
};

