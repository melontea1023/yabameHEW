#pragma once
#include <SimpleMath.h>
#include "Shader.h"
#include "Camera.h"

class Object {
protected:
	// SRT���i�p�����j
	DirectX::SimpleMath::Vector3 m_Position = DirectX::SimpleMath::Vector3(0.0f, 0.0f, 0.0f);
	DirectX::SimpleMath::Vector3 m_Rotation = DirectX::SimpleMath::Vector3(0.0f, 0.0f, 0.0f);
	DirectX::SimpleMath::Vector3 m_Scale = DirectX::SimpleMath::Vector3(1.0f, 1.0f, 1.0f);


	// �`��ׂ̈̏��i�����ڂɊւ�镔���j
	Shader m_Shader; // �V�F�[�_�[

	Camera* m_Camera;

public:

	Object(Camera* cam);//�R���X�g���N�^
	virtual ~Object();//�f�X�g���N�^

	virtual void Init()=0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Uninit() = 0;

	void SetPosition(const DirectX::SimpleMath::Vector3& pos);
	DirectX::SimpleMath::Vector3 GetPosition() const;
	void SetRotation(const DirectX::SimpleMath::Vector3& rot);
	DirectX::SimpleMath::Vector3 GetRotation() const;
};
