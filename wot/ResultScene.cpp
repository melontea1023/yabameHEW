#include "ResultScene.h"
#include "Game.h"
#include "Texture2D.h"

// �R���X�g���N�^
ResultScene::ResultScene()
{
	Init();
}

// �f�X�g���N�^
ResultScene::~ResultScene()
{
	Uninit();
}

// ������
void ResultScene::Init()
{
	Texture2D* pt = Game::GetInstance()->AddObject<Texture2D>();
	pt->SetTexture("assets/texture/background2.png");
	pt->SetScale(1280.0f, 720.0f, 0.0f);
	m_MySceneObjects.emplace_back(pt);

	Texture2D* pt2 = Game::GetInstance()->AddObject<Texture2D>();
	pt2->SetTexture("assets/texture/resultString.png");
	pt2->SetScale(700.0f, 100.0f, 0.0f);
	pt2->SetUV(1, 5, 1, 13);
	m_MySceneObjects.emplace_back(pt2);
}

// �X�V
void ResultScene::Update()
{
	// �G���^�[�L�[�������ă^�C�g����
	if (Input::GetKeyTrigger(VK_RETURN))
	{
		Game::GetInstance()->ChangeScene(TITLE);
	}
}

// �I������
void ResultScene::Uninit()
{
	// ���̃V�[���̃I�u�W�F�N�g���폜����
	for (auto& o : m_MySceneObjects) {
		Game::GetInstance()->DeleteObject(o);
	}
}
