#include "Bullet.h"

void Bullet::Init(const wchar_t* imgname, int sx, int sy, float speed, float angle) {
    Object::Init(imgname, sx, sy);
    this->speed = speed;
    this->angle = angle;
    this->isActive = true;
}

void Bullet::Update(float deltaTime) {
    pos.x += speed * cos(angle) * deltaTime;
    pos.y += speed * sin(angle) * deltaTime;

    // 画面外に出たら無効化
    if (pos.x < 0 || pos.x > SCREEN_WIDTH || pos.y < 0 || pos.y > SCREEN_HEIGHT) {
        isActive = false;
    }
}

void Bullet::SetVelocity(float velocityX, float velocityY) {
    // 新しい速度と角度を計算
    speed = sqrt(velocityX * velocityX + velocityY * velocityY);
    if (velocityX < 0 && velocityY < 0) {
        speed = -speed; // 第三象限の場合、負にする
    }
    angle = atan2(velocityY, velocityX);
}