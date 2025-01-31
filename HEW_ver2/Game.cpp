#include "Game.h"
//#include "Player.h"


std::vector<Object> obj = {};




void Game::Init(HWND hWnd) {

    D3D_Create(hWnd);

    sound.Init();
    sound.Play(SOUND_LABEL_TITLE);
    // 背景の初期化
    bg1.Init(L"asset/bg1.png");
    bg1.SetPos(0.0f, 0.0f, 0.0f);
    bg1.SetSize(1980.0f, 1080.0f, 0.0f);
    bg1.SetAngle(0.0f);
    obj.push_back(bg1);

    title.Init(L"asset/title2.png");
    title.SetPos(0.0f, 0.0f, 0.0f);
    title.SetSize(1980.0f, 1080.0f, 0.0f);
    title.SetAngle(0.0f);
    obj.push_back(title);

    clear_screen.Init(L"asset/Game Clear.png");
    clear_screen.SetPos(0.0f, 0.0f, 0.0f);
    clear_screen.SetSize(1980.0f, 1080.0f, 0.0f);
    clear_screen.SetAngle(0.0f);
    obj.push_back(clear_screen);

    game_over_screen.Init(L"asset/Game Over3.png");
    game_over_screen.SetPos(0.0f, 0.0f, 0.0f);
    game_over_screen.SetSize(1980.0f, 1080.0f, 0.0f);
    game_over_screen.SetAngle(0.0f);
    obj.push_back(game_over_screen);

    // Playerの初期化
    player.Init(L"asset/PMove_Attack.png",4,1);
    player.SetPos(-600.0f, -100.0f, 0.0f);
    player.SetSize(200.0f, 250.0f, 0.0f);
    player.SetAngle(0.0f);

    pbullet.Init(L"asset/link.png");
    pbullet.SetPos(-1000.0f, -1000.0f, 0.0f);
    pbullet.SetSize(750.0f, 375.0f, 0.0f);
    pbullet.SetAngle(0.0f);

    //// Playerの初期化
    //Action_player.Init(L"asset/Pmove.png", 3, 1);
    //Action_player.SetPos(-600.0f, -100.0f, 0.0f);
    //Action_player.SetSize(200.0f, 250.0f, 0.0f);
    //Action_player.SetAngle(0.0f);

    testenemy.Init(L"asset/linkmove.png", 4, 1);
    testenemy.SetPos(SCREEN_WIDTH / 2 / 2, 270, 0.0f);
    testenemy.SetSize(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.0f);
    testenemy.SetAngle(0.0f);

    //testenemy_link.Init(L"asset/adneofx.png", 4, 1);
    

    //testenemy_ad1.Init(L"asset/adweby.png", 4, 1); 
    

    //testenemy_ad2.Init(L"asset/adneofx.png", 4, 1);
   

    //testenemy_ad3.Init(L"asset/adwarning.png", 4, 1);
    


    testenemy.CharacterInit();
    sound.Init(); //サウンドの初期化


}

void Game::Update(void) {

    input.Update();
    //一旦スペースで全部シーン遷移
    switch (State) 
    {
    case TITLE:
        if (Loop_flg)
        {
            //初期化
            testenemy.Sethp(15);
            player.SetPos(-600.0f, -100.0f, 0.0f);
            pbullet.SetPos(-1000.0f, -1000.0f, 0.0f);
            pbullet.Set_p_starting(false);
            pbullet.Setp_b(false);
            testenemy.SetReflection(false);
            testenemy.SetPos(SCREEN_WIDTH / 2 / 2, 270, 0.0f);
            testenemy.ReSet();
            GAME_CLEAR_flg = false;
            GAME_END_flg = false;
            Loop_flg = false;
            Scene_Change_flg = false;

        }




        if (Any_Button()) 
        {
            State = GAME;
            sound.Stop(SOUND_LABEL_TITLE);
            sound.Play(SOUND_LABEL_BATTLE);
            Scene_Change_flg = false;
            //player.Update();

        }

        //Action_player;

        break;
    case GAME:

        
      
        //Damage(player, eb);

        // プレイヤーの更新処理
        player.Update();

        testenemy.Enemy_Action_Move(player.GetPos());
        DirectX::XMFLOAT3 CheckEpos = testenemy.GetPos();

        if (CheckEpos.x < 0)
        {
            pbullet.Setboss_pos_right(false);
        }
        else
        {
            pbullet.Setboss_pos_right(true);
        }


        pbullet.Set_p_starting(testenemy.GetReflection());
        pbullet.SetBulletType(player.GetAttackType());
        pbullet.Move_Update(player);
        testenemy.SetReflection(pbullet.Get_p_starting());

        ////PlayerとEnemy(BOSS)の当たり判定&HP管理
        Damage(player, testenemy);
        Damage(testenemy, pbullet);
        testenemy.p_eb_check(player);

        
        if (testenemy.GetHit())
        {
            State = END;
            sound.Stop(SOUND_LABEL_BATTLE);
            sound.Play(SOUND_LABEL_LOSE);
        }

        if (GAME_END_flg)
        {
            State = END;
            sound.Stop(SOUND_LABEL_BATTLE);
            sound.Play(SOUND_LABEL_LOSE);
        }

        if (GAME_CLEAR_flg)
        {
            State = LAST;
            sound.Stop(SOUND_LABEL_BATTLE);
            sound.Play(SOUND_LABEL_LOSE);
        }

      
        break;
    case LAST:
        if (Any_Button()) {
            State = TITLE;
            sound.Stop(SOUND_LABEL_RESULT);
            sound.Play(SOUND_LABEL_TITLE);
            Scene_Change_flg = false;
            Loop_flg = true;
        }
        //GAME_CLEAR_flg = false; 
        break;

    case END:
        if (Any_Button()) {
            State = TITLE;
            sound.Stop(SOUND_LABEL_LOSE);
            sound.Play(SOUND_LABEL_TITLE);
            Scene_Change_flg = false;
            Loop_flg = true;
        }
        //GAME_END_flg = false;

        break;
    }

}

void Game::Draw(void) {
    D3D_StartRender();
    switch (State) {
    case TITLE:
        bg1.Draw();
        title.Draw();

        break;
    case GAME:
        // プレイ画面の描画 
        bg1.Draw();
        player.Draw();

        pbullet.P_BDraw();
     
           
        testenemy.Draw();
        testenemy.CharacterDraw();
        break;
    case LAST:
        clear_screen.Draw();
        break;
    case END:
        game_over_screen.Draw();
        break;
    }
    D3D_FinishRender();
}

void Game::Uninit(void) {
    int number = obj.size();

    for (int i = 0; i < number; i++) {
        obj[i].Uninit();
    }

    sound.Uninit(); //サウンドを終了
    D3D_Release(); // DirectXを終了
}


void Game::Now_Enemy_Pos()
{
    testenemy.GetPos();


}
