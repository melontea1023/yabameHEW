#include "Game.h"
#include "Player.h"

std::vector<Object> objs = {};

//サウンド追加
//sound.hの列挙とクラス内にそれぞれ追加

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

    sound.Init();
    sound.Play(SOUND_LABEL_BGM000);
}


void Game::Update(void) {

    input.Update();
    //一旦スペースで全部シーン遷移
    switch (State) {
    case TITLE:
        if (Input::GetKeyTrigger(VK_SPACE)) {
            State = GAME;
            player.Update();
        }
        break;
    case GAME:
        // プレイヤーの更新処理
        player.Update();
        //for (Bullet& bullet : bullets) { // 複数のBulletに対応
        //    player.Reflect(bullet);
        //    bullet.Update(deltaTime); // Bullet の移動更新
        //}
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
