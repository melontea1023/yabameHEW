#pragma once
#include "Object.h"

class Enemy : public Object {
private:
    float speed;              // 敵の速度
    bool isActive = true;     // アクティブ状態

public:
    void Init(const wchar_t* imgname, int sx, int sy, float speed);  // 初期化
    void Update(float deltaTime);  // 更新
    bool IsActive() const { return isActive; }  // アクティブ状態を取得
};
