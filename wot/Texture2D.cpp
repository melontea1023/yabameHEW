#include "Texture2D.h"

using namespace std;
using namespace DirectX::SimpleMath;

// �R���X�g���N�^
Texture2D::Texture2D(Camera* cam) :Object(cam)
{

}

// �f�X�g���N�^
Texture2D::~Texture2D()
{

}

//=======================================
// ����������
//=======================================
void Texture2D::Init()
{
	// ���_�f�[�^
	std::vector<VERTEX_3D> vertices;

	vertices.resize(4);

	vertices[0].position = Vector3(-0.5f, 0.5f, 0);
	vertices[1].position = Vector3(0.5f, 0.5f, 0);
	vertices[2].position = Vector3(-0.5f, -0.5f, 0);
	vertices[3].position = Vector3(0.5f, -0.5f, 0);

	vertices[0].color = Color(1, 1, 1, 1);
	vertices[1].color = Color(1, 1, 1, 1);
	vertices[2].color = Color(1, 1, 1, 1);
	vertices[3].color = Color(1, 1, 1, 1);

	vertices[0].uv = Vector2(0, 0);
	vertices[1].uv = Vector2(1, 0);
	vertices[2].uv = Vector2(0, 1);
	vertices[3].uv = Vector2(1, 1);

	// ���_�o�b�t�@����
	m_VertexBuffer.Create(vertices);

	// �C���f�b�N�X�o�b�t�@����
	std::vector<unsigned int> indices;
	indices.resize(4);

	indices[0] = 0;
	indices[1] = 1;
	indices[2] = 2;
	indices[3] = 3;

	// �C���f�b�N�X�o�b�t�@����
	m_IndexBuffer.Create(indices);

	// �V�F�[�_�I�u�W�F�N�g����
	m_Shader.Create("shader/unlitTextureVS.hlsl", "shader/unlitTexturePS.hlsl");

	// �}�e���A�����擾
	m_Materiale = std::make_unique<Material>();
	MATERIAL mtrl;
	mtrl.Diffuse = Color(1, 1, 1, 1);
	mtrl.Shiness = 1;
	mtrl.TextureEnable = true; // �e�N�X�`�����g�����ۂ��̃t���O
	m_Materiale->Create(mtrl);
}

//=======================================
// �X�V����
//=======================================
void Texture2D::Update()
{

}

//=======================================
// �`�揈��
//=======================================
void Texture2D::Draw()
{
	// SRT���쐬
	Matrix r = Matrix::CreateFromYawPitchRoll(m_Rotation.x, m_Rotation.y, m_Rotation.z);
	Matrix t = Matrix::CreateTranslation(m_Position.x, m_Position.y, m_Position.z);
	Matrix s = Matrix::CreateScale(m_Scale.x, m_Scale.y, m_Scale.z);

	Matrix worldmtx;
	worldmtx = s * r * t;
	Renderer::SetWorldMatrix(&worldmtx); // GPU�ɃZ�b�g

	// �`��̏���
	ID3D11DeviceContext* devicecontext;
	devicecontext = Renderer::GetDeviceContext();

	// �g�|���W�[���Z�b�g�i�v���~�e�B�u�^�C�v�j
	devicecontext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

	m_Shader.SetGPU();
	m_VertexBuffer.SetGPU();
	m_IndexBuffer.SetGPU();

	m_Texture.SetGPU();
	m_Materiale->SetGPU();

	// UV�̐ݒ���w��
	float u = m_NumU - 1;
	float v = m_NumV - 1;
	float uw = 1 / m_SplitX;
	float vh = 1 / m_SplitY;

	Renderer::SetUV(u, v, uw, vh);

	// �J�����̐ݒ���w��
	m_Camera->SetCamera(1);

	devicecontext->DrawIndexed(
		4, // �`�悷��C���f�b�N�X���i�l�p�`�Ȃ�łS�j
		0, // �ŏ��̃C���f�b�N�X�o�b�t�@�̈ʒu
		0);
}

//=======================================
// �I������
//=======================================
void Texture2D::Uninit()
{

}

// �e�N�X�`�����w��
void Texture2D::SetTexture(const char* imgname)
{
	// �e�N�X�`�����[�h
	bool sts = m_Texture.Load(imgname);
	assert(sts == true);
}

// �ʒu���w��
void Texture2D::SetPosition(const float& x, const float& y, const float& z)
{
	Vector3 p = { x, y, z };
	SetPosition(p);
}
void Texture2D::SetPosition(const Vector3& pos)
{
	m_Position = pos;
}

// �p�x���w��
void Texture2D::SetRotation(const float& x, const float& y, const float& z)
{
	Vector3 r = { x, y, z };
	SetRotation(r);
}
void Texture2D::SetRotation(const Vector3& rot)
{
	m_Rotation = rot * 3.14f/180; // deg��rad�ɕϊ�
}

// �傫�����w��
void Texture2D::SetScale(const float& x, const float& y, const float& z)
{
	Vector3 s = { x, y, z };
	SetScale(s);
}
void Texture2D::SetScale(const Vector3& scl)
{
	m_Scale = scl;
}

// UV���W���w��
void Texture2D::SetUV(const float& nu, const float& nv, const float& sx, const float& sy)
{
	m_NumU = nu;
	m_NumV = nv;
	m_SplitX = sx;
	m_SplitY = sy;
}
