#include"Game.h"

bool Game::Any_Button()
{
    if (Input::GetButtonTrigger(XINPUT_A))
    {
        Scene_Change_flg = true;
    }
    if (Input::GetButtonTrigger(XINPUT_B))
    {
        Scene_Change_flg = true;
    }
    if (Input::GetButtonTrigger(XINPUT_X))
    {
        Scene_Change_flg = true;
    }
    if (Input::GetButtonTrigger(XINPUT_Y))
    {
        Scene_Change_flg = true;
    }
    if (Input::GetButtonTrigger(XINPUT_UP))
    {
        Scene_Change_flg = true;
    }
    if (Input::GetButtonTrigger(XINPUT_DOWN))
    {
        Scene_Change_flg = true;
    }
    if (Input::GetButtonTrigger(XINPUT_LEFT))
    {
        Scene_Change_flg = true;
    }
    if (Input::GetButtonTrigger(XINPUT_RIGHT))
    {
        Scene_Change_flg = true;

    }
    if (Input::GetButtonTrigger(XINPUT_START))
    {
        Scene_Change_flg = true;

    }
    if (Input::GetButtonTrigger(XINPUT_BACK))
    {
        Scene_Change_flg = true;

    }
    if (Input::GetButtonTrigger(XINPUT_LEFT_THUMB))
    {
        Scene_Change_flg = true;

    }
    if (Input::GetButtonTrigger(XINPUT_RIGHT_THUMB))
    {
        Scene_Change_flg = true;

    }
    if (Input::GetButtonTrigger(XINPUT_LEFT_SHOULDER))
    {
        Scene_Change_flg = true;

    }
    if (Input::GetButtonTrigger(XINPUT_RIGHT_SHOULDER))
    {
        Scene_Change_flg = true;
    }


    return Scene_Change_flg;

}

