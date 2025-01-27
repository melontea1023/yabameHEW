#include "Game.h"
#include "Player.h"

std::vector<Object> objs = {};

//�T�E���h�ǉ�
//sound.h�̗񋓂ƃN���X���ɂ��ꂼ��ǉ�

void Game::Init(HWND hWnd) {

    D3D_Create(hWnd);
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

    sound.Init();
    sound.Play(SOUND_LABEL_BGM000);
}


void Game::Update(void) {

    input.Update();
    //��U�X�y�[�X�őS���V�[���J��
    switch (State) {
    case TITLE:
        if (Input::GetKeyTrigger(VK_SPACE)) {
            State = GAME;
            player.Update();
        }
        break;
    case GAME:
        // �v���C���[�̍X�V����
        player.Update();
        //for (Bullet& bullet : bullets) { // ������Bullet�ɑΉ�
        //    player.Reflect(bullet);
        //    bullet.Update(deltaTime); // Bullet �̈ړ��X�V
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
        // �v���C��ʂ̕`�� 
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
    D3D_Release(); // DirectX���I��
}
