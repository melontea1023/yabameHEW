#include"Game.h"
#include"Scene.h"


std::vector<Object> obj = {};
Scene scene;
void Game::Init(HWND hWnd)
{
	//全てのオブジェクトのInit
	
}

void Game::Update(void)
{
	scene.MainUpdate();
	
}

void Game::Draw(void)
{

	D3D_StartRender();

	scene.MainDraw();


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


