#include "Game.h"
#include "Player.h"


std::vector<Object> objs = {};
//std::vector<Bullet> bullets; // �e�ۂ̃��X�g

void Game::Init(HWND hWnd) {

    D3D_Create(hWnd);

    sound.Init();
    sound.Play(SOUND_LABEL_TITLE);
    // �O�̏�Ԃ̏�����
    int prevState = -1;
    isMusicPlaying = false;


    // �w�i�̏�����
    bg1.Init(L"asset/bg1.png");
    bg1.SetPos(0.0f, 0.0f, 0.0f);
    bg1.SetSize(1980.0f, 1080.0f, 0.0f);
    bg1.SetAngle(0.0f);
    objs.push_back(bg1);

    // Player�̏�����
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

        // �v���C���[�̍X�V����
        player.Update();
        enemy.Enemy_Action_Move(player.GetPos());
        //// �e�ۂ̍X�V�����Ɣ��˃`�F�b�N
        //player.Reflect(bullet);
        //bullet.Update(1.0f / 60.0f); // �t���[�����[�g�����肵�čX�V
                // ���˔���
        player.Reflect(bullet);
        if (player.Reflect(bullet)) {
            // Reflect���ꂽ��AMoveReflectedBullet��L���ɂ���
            bullet.SetReflected(true);
        }

        // ���˂���Ă���΁A�V�����ړ�������K�p
        //if (bullet.IsReflected()) {
            bullet.MoveReflectedBullet();
        //}
        //else {
        //    // �ʏ�̒e�̈ړ��i�G���甭�˂���鎞�j
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
    D3D_Release(); // DirectX���I��
}
