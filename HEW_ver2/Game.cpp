#include"Game.h"
#include<vector>

std::vector<Object> obj = {};

void Game::Init(HWND hWnd)
{
	D3D_Create(hWnd); //DirectX������

	//�I�u�W�F�N�g��Init
	bg1.Init(L"asset/background01_test.png");   //�w�i��������
	bg1.SetPos(0.0f, 0.0f, 0.0f);      //�ʒu��ݒ�
	bg1.SetSize(768.0f, 576.0f, 0.0f); //�傫����ݒ�
	bg1.SetAngle(0.0f);   //�p�x��ݒ�
	obj.push_back(bg1);
}

void Game::Update(void)
{

	
}

void Game::Draw(void)
{

	D3D_StartRender();

	bg1.Draw();


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


