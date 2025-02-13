#pragma once

#include "Object.h"

class Bullet : public Object {
private:
    float speed; // 弾の速度
    bool isActive=true; // 弾が有効か
    bool angle;
public:
    void Init(const wchar_t* imgname, int sx, int sy,float speed,float angle);
    void Update(float deltaTime); // 弾丸の移動
    bool IsActive() const { return isActive; }; // 弾が有効かどうか
    void SetVelocity(float velocityX, float velocityY);
};
