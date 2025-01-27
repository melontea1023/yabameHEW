#include "Game.h"
#include "Player.h"


std::vector<Object> obj = {};
Player player; // Player�N���X�̃C���X�^���X



void Game::Init(HWND hWnd) {

    D3D_Create(hWnd);
    // �w�i�̏�����
    bg1.Init(L"asset/bg1.png");
    bg1.SetPos(0.0f, 0.0f, 0.0f);
    bg1.SetSize(1980.0f, 1080.0f, 0.0f);
    bg1.SetAngle(0.0f);
    obj.push_back(bg1);

    // Player�̏�����
    player.Init(L"asset/movesprite.png",3,1);
    player.SetPos(0.0f, 0.0f, 0.0f);
    player.SetSize(100.0f, 150.0f, 0.0f);
    player.SetAngle(0.0f);

    testenemy.Init(L"asset/movesprite.png", 1, 1);
    testenemy.SetPos(0.0f, 0.0f, 0.0f);
    testenemy.SetSize(SCREEN_WIDTH / 2/2, SCREEN_HEIGHT / 2/2, 0.0f);
    testenemy.SetAngle(0.0f);

    //testenemy_link.Init(L"asset/adneofx.png", 4, 1);
    

    //testenemy_ad1.Init(L"asset/adweby.png", 4, 1); 
    

    //testenemy_ad2.Init(L"asset/adneofx.png", 4, 1);
   

    //testenemy_ad3.Init(L"asset/adwarning.png", 4, 1);
    


    testenemy.CharacterInit();
    sound.Init(); //�T�E���h�̏�����


}

void Game::Update(void) {

    input.Update();
    //��U�X�y�[�X�őS���V�[���J��
    switch (State) {
    case TITLE:
        if (Input::GetKeyTrigger(VK_SPACE)) {
            State = GAME;
            player.Update();
            testenemy.test_Update(player.GetPos(), testenemy.GetPos());

        }
        break;
    case GAME:
        // �v���C���[�̍X�V����
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
    int number = obj.size();

    for (int i = 0; i < number; i++) {
        obj[i].Uninit();
    }

    sound.Uninit(); //�T�E���h���I��
    D3D_Release(); // DirectX���I��
}
