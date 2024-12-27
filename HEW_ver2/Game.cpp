#include"Game.h"
#include"Scene.h"


std::vector<Object> obj = {};
Scene scene;
void Game::Init(HWND hWnd)
{
	//�S�ẴI�u�W�F�N�g��Init
	
}

void Game::Update(void)
{
	scene.MainUpdate();
	
}

void Game::Draw(void)
{

	D3D_StartRender();

	scene.MainDraw();


	D3D_FinishRender(); //�`��I��
}

void Game::Uninit(void)
{
	int number = obj.size();

	for (int i = 0; i >= number; number--)
	{
		obj[i].Uninit();
	}
	D3D_Release();   //DirectX���I��
}


