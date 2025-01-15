#include "Game.h"
#include "Player.h"

std::vector<Object> obj = {};
Player player; // Playerクラスのインスタンス

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
    obj.push_back(bg1);

    // Playerの初期化
    player.Init(L"asset/playertest.png",1,1);
    player.SetPos(0.0f, 0.0f, 0.0f);
    player.SetSize(70.0f, 100.0f, 0.0f);
    player.SetAngle(0.0f);
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
    int number = obj.size();

    for (int i = 0; i < number; i++) {
        obj[i].Uninit();
    }
    D3D_Release(); // DirectXを終了
}
