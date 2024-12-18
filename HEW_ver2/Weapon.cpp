#include "Weapon.h"

void Weapon::Init(float initFireRate) {
    this->fireRate = fireRate;
    this->timeSinceLastShot = 0.0f;
}

void Weapon::Fire(const DirectX::XMFLOAT3& position, float angle) {
    if (timeSinceLastShot >= fireRate) {
        Bullet* newBullet = new Bullet();
        newBullet->Init(L"bullet.png", 1, 1, 300.0f, angle);  // 速度と角度を設定
        newBullet->SetPos(position.x, position.y, 0.0f);

        bullets.push_back(newBullet);
        timeSinceLastShot = 0.0f;
    }
}


void Weapon::Update(float deltaTime) {
    // 弾丸を更新
    for (auto it = bullets.begin(); it != bullets.end(); ) {
        (*it)->Update(deltaTime);

        // 弾丸が非アクティブなら削除
        if (!(*it)->IsActive()) {
            delete* it;  // メモリ解放
            it = bullets.erase(it);  // 弾丸をリストから削除
        }
        else {
            ++it;
        }
    }

    timeSinceLastShot += deltaTime;
}

