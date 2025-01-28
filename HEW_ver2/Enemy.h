#pragma once
#include "Object.h"

class Enemy : public Object {
protected:
    bool isActive;

public:
    float health = 5;
    float stamina = 100;
    float atk;

    Enemy() : isActive(true) {} // 初期化時にアクティブ化

    bool IsActive() const { return isActive; }
    void SetActive(bool active) { isActive = active; }

    void TakeDamage(float damage) {
        health -= damage;
        if (health <= 0) {
            Destroy();
        }
    }

    void Destroy() {
        // 敵を削除する処理
        isActive = false; // 例えば、敵を非アクティブ化する
    }
};