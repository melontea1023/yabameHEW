#include"Game.h"



std::vector<Object> obj = {};
void Game::Init(HWND hWnd)
{
	//�I�u�W�F�N�g��Init
	bg1.Init(L"asset/bg1.png");   //�w�i��������
	bg1.SetPos(0.0f, 0.0f, 0.0f);      //�ʒu��ݒ�
	bg1.SetSize(768.0f, 576.0f, 0.0f); //�傫����ݒ�
	bg1.SetAngle(0.0f);   //�p�x��ݒ�
	
	//�I�u�W�F�N�g��Init
	Player.Init(L"asset/Player.png");   //�w�i��������
	Player.SetPos(0.0f, 0.0f, 0.0f);      //�ʒu��ݒ�
	Player.SetSize(70.0f, 100.0f, 0.0f); //�傫����ݒ�
	Player.SetAngle(0.0f);   //�p�x��ݒ�
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


