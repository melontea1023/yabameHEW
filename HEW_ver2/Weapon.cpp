#include "Weapon.h"

void Weapon::Init(float initFireRate) {
    this->fireRate = fireRate;
    this->timeSinceLastShot = 0.0f;
}

void Weapon::Fire(const DirectX::XMFLOAT3& position, float angle) {
    if (timeSinceLastShot >= fireRate) {
        Bullet* newBullet = new Bullet();
        newBullet->Init(L"bullet.png", 1, 1, 300.0f, angle);  // ���x�Ɗp�x��ݒ�
        newBullet->SetPos(position.x, position.y, 0.0f);

        bullets.push_back(newBullet);
        timeSinceLastShot = 0.0f;
    }
}


void Weapon::Update(float deltaTime) {
    // �e�ۂ��X�V
    for (auto it = bullets.begin(); it != bullets.end(); ) {
        (*it)->Update(deltaTime);

        // �e�ۂ���A�N�e�B�u�Ȃ�폜
        if (!(*it)->IsActive()) {
            delete* it;  // ���������
            it = bullets.erase(it);  // �e�ۂ����X�g����폜
        }
        else {
            ++it;
        }
    }

    timeSinceLastShot += deltaTime;
}

