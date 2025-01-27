#pragma once

#include "Object.h"

class Bullet : public Object {
private:
    float speed; // �e�̑��x
    bool isActive=true; // �e���L����
    bool angle;
    DirectX::XMFLOAT2 velocity; // �e�̕����x�N�g��
public:
    void Init(const wchar_t* imgname, int sx, int sy,float speed,float angle);
    void Update(float deltaTime); // �e�ۂ̈ړ�
    void SetVelocity(float x, float y);
    bool IsActive() const { return isActive; }; // �e���L�����ǂ���
};
