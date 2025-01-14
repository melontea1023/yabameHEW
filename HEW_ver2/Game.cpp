#include"Game.h"



std::vector<Object> obj = {};
void Game::Init(HWND hWnd)
{
	//オブジェクトのInit
	bg1.Init(L"asset/bg1.png");   //背景を初期化
	bg1.SetPos(0.0f, 0.0f, 0.0f);      //位置を設定
	bg1.SetSize(768.0f, 576.0f, 0.0f); //大きさを設定
	bg1.SetAngle(0.0f);   //角度を設定
	
	//オブジェクトのInit
	Player.Init(L"asset/Player.png");   //背景を初期化
	Player.SetPos(0.0f, 0.0f, 0.0f);      //位置を設定
	Player.SetSize(70.0f, 100.0f, 0.0f); //大きさを設定
	Player.SetAngle(0.0f);   //角度を設定
}

void Game::Update(void)
{

	
}

void Game::Draw(void)
{

	D3D_StartRender();

	D3D_FinishRender(); //描画終了
}

void Game::Uninit(void)
{
	int number = obj.size();

	for (int i = 0; i >= number; number--)
	{
		obj[i].Uninit();
	}
	D3D_Release();   //DirectXを終了
}


