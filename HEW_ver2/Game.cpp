#include "Game.h"
#include "Player.h"

std::vector<Object> objs = {};
std::vector<Bullet> bullets; // 弾丸のリスト

void Game::Init(HWND hWnd) {

    D3D_Create(hWnd);
    // 背景の初期化
    bg1.Init(L"asset/bg1.png");
    bg1.SetPos(0.0f, 0.0f, 0.0f);
    bg1.SetSize(1980.0f, 1080.0f, 0.0f);
    bg1.SetAngle(0.0f);
    objs.push_back(bg1);

    // Playerの初期化
    player.Init(L"asset/movesprite.png",3,1);
    player.SetPos(0.0f, 0.0f, 0.0f);
    player.SetSize(100.0f, 150.0f, 0.0f);
    player.SetAngle(0.0f);
    objs.push_back(player);

    // 弾丸
    for (int i = 0; i < 5; ++i) {
        Bullet bullet;
        bullet.Init(L"asset/bullet.png", 1, 1, 300.0f, i * DirectX::XM_PI / 4);
        bullet.SetPos(100.0f * i, 100.0f, 0.0f);
        bullets.push_back(bullet);
    }
}


void Game::Update(void) {

    input.Update();
    //一旦スペースで全部シーン遷移
    switch (State) {
    case TITLE:
        if (Input::GetKeyTrigger(VK_SPACE)) {
            State = GAME;
        }
        break;
    case GAME:
        // プレイヤーの更新処理
        player.Update();
        // 弾丸の更新処理と反射チェック
        for (Bullet& bullet : bullets) {
            if (bullet.IsActive()) {
                player.Reflect(bullet);
                bullet.Update(1.0f / 60.0f); // フレームレートを仮定して更新
            }
        }
        if (Input::GetKeyTrigger(VK_SPACE)) {
            State = LAST;
        }
        break;
    case LAST:
        if (Input::GetKeyTrigger(VK_SPACE)) {
            State = TITLE;
        }
        break;
    }

}

void Game::Draw(void) {
    D3D_StartRender();
    switch (State) {
    case TITLE:
        bg1.Draw();
        player.Draw();
        break;
    case GAME:
        bg1.Draw();
        player.Draw();
        for (const Bullet& bullet : bullets) {
            if (bullet.IsActive()) {
                bullet.Draw();
            }
        }
        break;
    case LAST:
        break;
    }
    D3D_FinishRender();
}

void Game::Uninit(void) {

    for (auto& obj : objs) {
        obj.Uninit();
    }
    for (Bullet& bullet : bullets) {
        bullet.Uninit();
    }
    //int number = objs.size();

    //for (int i = 0; i < number; i++) {
    //    objs[i].Uninit();
    //}
    D3D_Release(); // DirectXを終了
}
