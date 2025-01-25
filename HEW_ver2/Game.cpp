#include "Game.h"
#include "Player.h"

std::vector<Object> objs = {};

//列挙型でシーン遷移
enum GameState
{ TITLE, 
  GAME, 
  LAST
};
GameState State = TITLE;

void Game::Init(HWND hWnd) {

    D3D_Create(hWnd);
    // 背景の初期化
    bg1.Init(L"asset/title2.png");
    bg1.SetPos(0.0f, 0.0f, 0.0f);
    bg1.SetSize(768.0f, 576.0f, 0.0f);
    bg1.SetAngle(0.0f);
    objs.push_back(bg1);

    // Playerの初期化
    player.Init(L"asset/playertest.png",1,1);
    player.SetPos(0.0f, 0.0f, 0.0f);
    player.SetSize(70.0f, 100.0f, 0.0f);
    player.SetAngle(0.0f);
    objs.push_back(player);
}


void Game::Update(void) {

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
        player.Update();
        for (Bullet& bullet : bullets) { // 複数のBulletに対応
            player.Reflect(bullet);
            bullet.Update(deltaTime); // Bullet の移動更新
        }
        adObject.UpdatePosition(); // Advertisement の位置更新
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
        break;
    case GAME:
        // プレイ画面の描画 
        player.Draw();
        break;
    case LAST:

        break;
    }
    D3D_FinishRender();
}

void Game::Uninit(void) {

    for (auto& i : objs) {
        i.Uninit();
    }
    //int number = objs.size();

    //for (int i = 0; i < number; i++) {
    //    objs[i].Uninit();
    //}
    D3D_Release(); // DirectXを終了
}
