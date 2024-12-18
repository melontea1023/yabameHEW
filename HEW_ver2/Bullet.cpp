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

    // âÊñ äOÇ…èoÇΩÇÁñ≥å¯âª
    if (pos.x < 0 || pos.x > SCREEN_WIDTH || pos.y < 0 || pos.y > SCREEN_HEIGHT) {
        isActive = false;
    }
}
