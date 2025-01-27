#pragma once

#include "Object.h"

class Bullet : public Object {
private:
    float speed; // ’e‚Ì‘¬“x
    bool isActive=true; // ’e‚ª—LŒø‚©
    bool angle;
public:
    void Init(const wchar_t* imgname, int sx, int sy,float speed,float angle);
    void Update(float deltaTime); // ’eŠÛ‚ÌˆÚ“®
    bool IsActive() const { return isActive; }; // ’e‚ª—LŒø‚©‚Ç‚¤‚©
    void SetVelocity(float velocityX, float velocityY);
};
