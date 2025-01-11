#pragma once
#include "Object.h"
#include <vector>

class Player : public Object {
public:
    float stamina=100;
    float atk;
    float health=5;

    Player();
    void Init(const wchar_t* imgname, int sx = 1, int sy = 1);
    void Update(); // プレイヤーの更新処理
    void flutter();
};
