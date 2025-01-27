#pragma once

#include "Object.h"

class Bullet : public Object {
private:
    float speed; // ’e‚Ì‘¬“x
    bool isActive=true; // ’e‚ª—LŒø‚©
    bool angle;
    DirectX::XMFLOAT2 velocity; // ’e‚Ì•ûŒüƒxƒNƒgƒ‹
public:
    void Init(const wchar_t* imgname, int sx, int sy,float speed,float angle);
    void Update(float deltaTime); // ’eŠÛ‚ÌˆÚ“®
    void SetVelocity(float x, float y);
    bool IsActive() const { return isActive; }; // ’e‚ª—LŒø‚©‚Ç‚¤‚©
};
