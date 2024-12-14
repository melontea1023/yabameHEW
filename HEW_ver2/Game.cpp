#include"Game.h"



std::vector<Object> obj = {};
void Game::Init(HWND hWnd)
{
	//オブジェクトのInit

	
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


