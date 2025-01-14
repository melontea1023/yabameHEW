#include"Game.h"
#include<vector>

std::vector<Object> obj = {};

void Game::Init(HWND hWnd)
{
	D3D_Create(hWnd); //DirectX初期化

	//オブジェクトのInit
	bg1.Init(L"asset/background01_test.png");   //背景を初期化
	bg1.SetPos(0.0f, 0.0f, 0.0f);      //位置を設定
	bg1.SetSize(768.0f, 576.0f, 0.0f); //大きさを設定
	bg1.SetAngle(0.0f);   //角度を設定
	obj.push_back(bg1);
}

void Game::Update(void)
{

	
}

void Game::Draw(void)
{

	D3D_StartRender();

	bg1.Draw();


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


