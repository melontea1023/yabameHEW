#pragma once
#include "Object.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Texture.h"
#include "Material.h"

//-----------------------------------------------------------------------------
// Texture2D�N���X
//-----------------------------------------------------------------------------
class Texture2D : public Object
{
private:
	// �`��ׂ̈̏��i���b�V���Ɋւ����j
	IndexBuffer m_IndexBuffer; // �C���f�b�N�X�o�b�t�@
	VertexBuffer<VERTEX_3D> m_VertexBuffer; // ���_�o�b�t�@

	// �`��ׂ̈̏��i�����ڂɊւ�镔���j
	Texture m_Texture; // �e�N�X�`��
	std::unique_ptr<Material> m_Materiale; //�}�e���A��

	// UV���W�̏��
	float m_NumU = 1;
	float m_NumV = 1;
	float m_SplitX = 1;
	float m_SplitY = 1;

public:

	Texture2D(Camera* cam); // �R���X�g���N�^
	~Texture2D(); // �f�X�g���N�^

	void Init();
	void Update();
	void Draw();
	void Uninit();

	// �e�N�X�`�����w��
	void SetTexture(const char* imgname);

	// �ʒu���w��
	void SetPosition(const float& x, const float& y, const float& z);
	void SetPosition(const DirectX::SimpleMath::Vector3& pos);

	// �p�x���w��
	void SetRotation(const float& x, const float& y, const float& z);
	void SetRotation(const DirectX::SimpleMath::Vector3& rot);

	// �傫�����w��
	void SetScale(const float& x, const float& y, const float& z);
	void SetScale(const DirectX::SimpleMath::Vector3& scl);

	// UV���W���w��
	void SetUV(const float& nu, const float& nv, const float& sx, const float& sy);
};

