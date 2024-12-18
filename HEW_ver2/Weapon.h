#pragma once
#include <vector>
#include "Bullet.h"

class Weapon {
private:
    std::vector<Bullet*> bullets; // �e�ۂ���
    float fireRate;               // ���ˊԊu
    float timeSinceLastShot;      // �Ō�ɒe�ۂ𔭎˂��Ă���̌o�ߎ���

public:
    void Init(float fireRate);
    void Fire(const DirectX::XMFLOAT3& position, float angle);
    void Update(float deltaTime);
};

