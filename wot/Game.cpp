#include "Game.h"
#include "Renderer.h"

Game* Game::m_Instance;

// �R���X�g���N�^
Game::Game()
{
	
	m_Input = std::make_unique<Input>(); //���͏������쐬
	m_Camera = std::make_unique<Camera>(); //�J�������쐬
}

// �f�X�g���N�^
Game::~Game()
{
	delete m_Scene;
}

// ������
void Game::Init()
{
	// �I�u�W�F�N�g�쐬
	m_Instance = new Game;

	// �`�揉����
	Renderer::Init();

	// �I�u�W�F�N�g�z��쐬
	//m_Instance->m_Objects.emplace_back(new GolfBall);
	//m_Instance->m_Objects.emplace_back(new Ground);

	// �J����������
	m_Instance->m_Camera->Init();
	m_Instance->m_Scene=new TitleScene; //���������m��


	// �I�u�W�F�N�g������
	// (��AddObject�֐��Ŏ��s����悤�ɕύX�j
	//for (auto& o : m_Instance->m_Objects)
	//{
	//	o->Init();
	//}
}

// �X�V
void Game::Update()
{
	// �V�[���X�V
	m_Instance->m_Scene->Update();

	// �J�����X�V
	m_Instance->m_Camera->Update();

	// ���͏����X�V
	m_Instance->m_Input->Update();

	// �I�u�W�F�N�g�X�V
	for (auto& o : m_Instance->m_Objects)
	{
		o->Update();
	}
}

// �`��
void Game::Draw()
{
	// �`��O����
	Renderer::Begin();

	// �J�����`��
	m_Instance->m_Camera->Draw();

	// �I�u�W�F�N�g�`��
	for (auto& o : m_Instance->m_Objects)
	{
		o->Draw();
	}

	// �`��㏈��
	Renderer::End();
}

// �I������
void Game::Uninit()
{
	//�I�u�W�F�N�g��S�č폜
	m_Instance->DeleteAllObject();

	// �I�u�W�F�N�g�I������
 	// (��DeleteObject�֐��Ŏ��s����悤�ɕύX�j
	//for (auto& o : m_Instance->m_Objects)
	//{
	//	o->Uninit();
	//}

	// �J�����I������
	m_Instance->m_Camera->Uninit();

	// �`��I������
	Renderer::Uninit();
}

// �C���X�^���X���擾
Game* Game::GetInstance()
{
	return m_Instance;
}

// �J�������擾����
Camera& Game::GetCamera()
{
	return *(m_Instance->m_Camera);
}

// �V�[����؂�ւ���
void Game::ChangeScene(SceneName sName)
{
	// �ǂݍ��ݍς݂̃V�[��������΍폜
	if (m_Instance->m_Scene != nullptr) {
		delete m_Instance->m_Scene;
		m_Instance->m_Scene = nullptr;
	}

	switch (sName)
	{
	case TITLE:
		m_Instance->m_Scene = new TitleScene; // ���������m��
		break;
	case STAGE1:
		m_Instance->m_Scene = new Stage1Scene; // ���������m��
		break;
	case RESULT:
		m_Instance->m_Scene = new ResultScene; // ���������m��
		break;
	}
}

// �I�u�W�F�N�g���폜����
void Game::DeleteObject(Object* pt)
{
	if (pt == NULL) return;

	pt->Uninit(); // �I������

	// �v�f���폜
	m_Instance->m_Objects.erase(
		std::remove_if(
			m_Instance->m_Objects.begin(),
			m_Instance->m_Objects.end(),
			[pt](const std::unique_ptr<Object>& element) {return element.get() == pt; }),
		m_Instance->m_Objects.end());
	m_Instance->m_Objects.shrink_to_fit();
}

// �I�u�W�F�N�g�����ׂč폜����
void Game::DeleteAllObject()
{
	// �I�u�W�F�N�g�I������
	for (auto& o : m_Instance->m_Objects)
	{
		o->Uninit();
	}

	m_Instance->m_Objects.clear(); //�S�č폜
	m_Instance->m_Objects.shrink_to_fit();
}

