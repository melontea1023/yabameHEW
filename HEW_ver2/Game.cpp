#include "Game.h"
#include "Player.h"


std::vector<Object> objs = {};
//std::vector<Bullet> bullets; // 弾丸のリスト

void Game::Init(HWND hWnd) {

    D3D_Create(hWnd);

    sound.Init();
    sound.Play(SOUND_LABEL_TITLE);
    // 前の状態の初期化
    int prevState = -1;
    isMusicPlaying = false;


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

    enemy.CharacterInit();
}


void Game::Update(void) {

    input.Update();

    switch (State) {
    case TITLE:

        if (Input::GetKeyTrigger(VK_SPACE)) {
            State = GAME;
            sound.Stop(SOUND_LABEL_TITLE);
            sound.Play(SOUND_LABEL_BATTLE);
        }
        break;
    case GAME:

        // プレイヤーの更新処理
        player.Update();
        enemy.Enemy_Action_Move(player.GetPos());
        //// 弾丸の更新処理と反射チェック
        //player.Reflect(bullet);
        //bullet.Update(1.0f / 60.0f); // フレームレートを仮定して更新
                // 反射判定
        player.Reflect(bullet);
        if (player.Reflect(bullet)) {
            // Reflectされたら、MoveReflectedBulletを有効にする
            bullet.SetReflected(true);
        }

        // 反射されていれば、新しい移動処理を適用
        //if (bullet.IsReflected()) {
            bullet.MoveReflectedBullet();
        //}
        //else {
        //    // 通常の弾の移動（敵から発射される時）
        //    bullet.SetPos(bullet.MoveBulllet(player.GetPos(), bullet.GetPos()));
        //}
        if (Input::GetKeyTrigger(VK_SPACE)) {
            State = LAST;
            sound.Stop(SOUND_LABEL_BATTLE);
            sound.Play(SOUND_LABEL_RESULT);
        }
        break;
    case LAST:
        if (Input::GetKeyTrigger(VK_SPACE)) {
            State = TITLE;
            sound.Stop(SOUND_LABEL_RESULT);
            sound.Play(SOUND_LABEL_TITLE);
        }
        break;
    }
    prevState = State;
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
        enemy.CharacterDraw();
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
    sound.Uninit();
    //int number = objs.size();

    //for (int i = 0; i < number; i++) {
    //    objs[i].Uninit();
    //}
    D3D_Release(); // DirectXを終了
}
