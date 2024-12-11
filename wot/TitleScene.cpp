#include "TitleScene.h"
#include "Game.h"
#include"Texture2D.h"

// �R���X�g���N�^
TitleScene::TitleScene()
{
	Init();
}

// �f�X�g���N�^
TitleScene::~TitleScene()
{
	Uninit();
}

// ������
void TitleScene::Init()
{
	Texture2D* pt = Game::GetInstance()->AddObject<Texture2D>();
	pt->SetTexture("assets/texture/background1.png");
	pt->SetPosition(0.0f,0.0f,0.0f);
	pt->SetRotation(0.0f, 0.0f, 0.0f);
	pt->SetScale(1280.0f, 720.0f, 0.0f);
	m_MySceneObjects.emplace_back(pt);

}

// �X�V
void TitleScene::Update()
{
	// �G���^�[�L�[�������ăX�e�[�W1��
	if (Input::GetKeyTrigger(VK_RETURN))
	{
		Game::GetInstance()->ChangeScene(STAGE1);
	}
}

// �I������
void TitleScene::Uninit()
{
	// ���̃V�[���̃I�u�W�F�N�g���폜����
	for (auto& o : m_MySceneObjects) {
		Game::GetInstance()->DeleteObject(o);
	}
}
