#include "Game.h"
#include "Player.h"


std::vector<Object> objs = {};
//std::vector<Bullet> bullets; // �e�ۂ̃��X�g

void Game::Init(HWND hWnd) {

    D3D_Create(hWnd);
    sound.Init();
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
    if (Input::GetButtonPress(XINPUT_LEFT_THUMB)) {
        MessageBoxA(NULL, "A", "a", MB_OK);
    }
    input.Update();
    //��U�X�y�[�X�őS���V�[���J��
    switch (State) {
    case TITLE:
        player.Update();
        sound.Stop(SOUND_LABEL_RESULT);
        sound.Play(SOUND_LABEL_TITLE);
 
        if (Input::GetKeyTrigger(VK_SPACE)) {
            State = GAME;
        }
        break;
    case GAME:
        // �v���C���[�̍X�V����
        player.Update();
        sound.Stop(SOUND_LABEL_TITLE);
        sound.Play(SOUND_LABEL_BATTLE);
        enemy.Enemy_Action_Move(player.GetPos());
        // �e�ۂ̍X�V�����Ɣ��˃`�F�b�N
        player.Reflect();
        eb.Update(1.0f / 60.0f); // �t���[�����[�g�����肵�čX�V
        if (Input::GetKeyTrigger(VK_SPACE)) {
            State = LAST;
        }
        break;
    case LAST:
        sound.Stop(SOUND_LABEL_BATTLE);
        sound.Play(SOUND_LABEL_RESULT);
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

    //int number = objs.size();

    //for (int i = 0; i < number; i++) {
    //    objs[i].Uninit();
    //}
    D3D_Release(); // DirectX���I��
}
