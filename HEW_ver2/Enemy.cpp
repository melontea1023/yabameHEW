#include "Enemy.h"

void Enemy::Init(const wchar_t* imgname, int sx, int sy, float speed) {
    Object::Init(imgname, sx, sy);
    this->speed = speed;
    this->isActive = true;
}

void Enemy::Update(float deltaTime) {
    pos.x += speed * deltaTime;

    // ‰æ–ÊŠO‚Éo‚½‚ç–³Œø‰»
    if (pos.x < 0 || pos.x > SCREEN_WIDTH || pos.y < 0 || pos.y > SCREEN_HEIGHT) {
        isActive = false;
    }
}
