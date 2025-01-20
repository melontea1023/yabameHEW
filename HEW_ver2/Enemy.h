#pragma once
#include "Object.h"

class Enemy : public Object {
public:
    float health;
    void TakeDamage(float damage) {
        health -= damage;
        if (health <= 0) {
            Destroy();
        }
    }
    void Destroy() {
        // “G‚ðíœ‚·‚éˆ—
    }
};
