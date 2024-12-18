#pragma once
#include <vector>
#include "Bullet.h"

class Weapon {
private:
    std::vector<Bullet*> bullets; // ’eŠÛ‚½‚¿
    float fireRate;               // ”­ËŠÔŠu
    float timeSinceLastShot;      // ÅŒã‚É’eŠÛ‚ğ”­Ë‚µ‚Ä‚©‚ç‚ÌŒo‰ßŠÔ

public:
    void Init(float fireRate);
    void Fire(const DirectX::XMFLOAT3& position, float angle);
    void Update(float deltaTime);
};

