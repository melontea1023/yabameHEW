#include"Game.h"



std::vector<Object> obj = {};
void Game::Init(HWND hWnd)
{
	//�I�u�W�F�N�g��Init

	
}

void Game::Update(void)
{

	
}

void Game::Draw(void)
{

	D3D_StartRender();

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


