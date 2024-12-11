#pragma once
#include "Scene.h"
#include "Object.h"

// TitleScene�N���X
class TitleScene : public Scene
{
private:
	std::vector<Object*> m_MySceneObjects; // ���̃V�[���̃I�u�W�F�N�g

	void Init(); // ������
	void Uninit(); // �I������

public:
	TitleScene(); // �R���X�g���N�^
	~TitleScene(); // �f�X�g���N�^

	void Update(); // �X�V
};

