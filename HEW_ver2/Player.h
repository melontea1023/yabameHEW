#pragma once
#include "Object.h"
#include "Weapon.h"
#include <vector>

class Player : public Object {
private:
    std::vector<Weapon*> weapons; // 武器のリスト
    int currentWeaponIndex;       // 現在選択中の武器
public:
    Player();
    void Init(const wchar_t* imgname, int sx = 1, int sy = 1);
    void Update(float deltaTime); // プレイヤーの更新処理
    void Fire();                  // 現在の武器で発射
    void SwitchWeapon(int index); // 武器を切り替える
};
