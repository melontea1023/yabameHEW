#pragma once
#include "Scene.h"
#include "Object.h"

// ResultScene�N���X
class ResultScene : public Scene
{
private:
	std::vector<Object*> m_MySceneObjects; // ���̃V�[���̃I�u�W�F�N�g

	void Init(); // ������
	void Uninit(); // �I������

public:
	ResultScene(); // �R���X�g���N�^
	~ResultScene(); // �f�X�g���N�^

	void Update(); // �X�V
};

