#pragma once
#include "Object.h"

class Enemy : public Object {
protected:
    bool isActive;
public:
    float stamina = 100;
    float atk;
    float health = 5;

    Enemy() : isActive(true) {} // ���������ɃA�N�e�B�u��
    bool IsActive() const { return isActive; }
    void SetActive(bool active) { isActive = active; }

};