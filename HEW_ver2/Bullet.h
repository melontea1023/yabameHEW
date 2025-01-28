#pragma once

#include "Object.h"

class Bullet : public Object {
private:
    float speed; // �e�̑��x
    bool isActive=true; // �e���L����
    bool angle;
public:
    void Init(const wchar_t* imgname, int sx, int sy,float speed,float angle);
    void Update(float deltaTime); // �e�ۂ̈ړ�
    bool IsActive() const { return isActive; }; // �e���L�����ǂ���
    void SetVelocity(float velocityX, float velocityY);
};
