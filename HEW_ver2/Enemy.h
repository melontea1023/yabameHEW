#pragma once
#include "Object.h"

class Enemy : public Object {
private:
    float speed;              // �G�̑��x
    bool isActive = true;     // �A�N�e�B�u���

public:
    void Init(const wchar_t* imgname, int sx, int sy, float speed);  // ������
    void Update(float deltaTime);  // �X�V
    bool IsActive() const { return isActive; }  // �A�N�e�B�u��Ԃ��擾
};
