#pragma once
#include <memory>

//Scene �N���X
class Scene
{
public:

	Scene(); // �R���X�g���N�^
	virtual ~Scene(); // �f�X�g���N�^(virtual���K�v)

	virtual void Update() = 0; // �X�V�i�������z�֐��j
};