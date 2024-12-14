#pragma once
#include"direct3d.h"
#include"WICTextureLoader.h" //�e�N�X�`���ǂݍ��݃��C�u����
class Object {
private:
	// ���_�f�[�^�����߂�
	Vertex vertexList[4] =
	{                       //R,   G,   B,   A
		{ -0.5f,  0.5f, 0.5f,1.0f,1.0f,1.0f,1.0f, 0.0f,0.0f },  // �O�Ԗڂ̒��_���W�@{ x, y, z }
		{  0.5f,  0.5f, 0.5f,1.0f,1.0f,1.0f,1.0f, 1.0f,0.0f },  // �P�Ԗڂ̒��_���W
		{ -0.5f, -0.5f, 0.5f,1.0f,1.0f,1.0f,1.0f, 0.0f,1.0f },  // �Q�Ԗڂ̒��_���W
		{  0.5f, -0.5f, 0.5f,1.0f,1.0f,1.0f,1.0f, 1.0f,1.0f },  // �R�Ԗڂ̒��_���W
	};
	
	// ���_�o�b�t�@
	ID3D11Buffer* m_pVertexBuffer;
	//�e�N�X�`���p�ϐ��@�@�@�@�@�@�@�@�@
	ID3D11ShaderResourceView* m_pTextureView;            //������𑝂₹�΃e�N�X�`����������@�@�@�@�@�@�@�@�@

	//���W
	 DirectX::XMFLOAT3 pos = {0.0f,0.0f,0.0f};
	 //�傫��
	 DirectX::XMFLOAT3 size = { 100.0f,100.0f,0.0f };

	 //�p�x
	 float angle =0.0f;

	 //�F
	 DirectX::XMFLOAT4 color = { 1.0f,1.0f,1.0f,1.0f };

	//
	 DirectX::XMFLOAT2 UV = { 0.0f,1.0f};


	 //�e�N�X�`�����c���ɂɉ���������Ă��邩
	 int splitX = 1;
	 int splitY = 1;
	 
	 //���a�p
	 float r;

public:
	//�����牽�i�ڂ�؂蔲���ĕ\�����邩
	int numU = 0;
	int numV = 0;
	
	void Init(const wchar_t* imgname,int sx=1,int sy=1);  //������
	void Draw(void);                       //�`��
	void Uninit(void);                    //�I��
	void SetPos(float x, float y, float z);//���W���Z�b�g
	void SetSize(float x, float y, float z);//�傫�����Z�b�g
	void SetAngle(float a);//�p�x���Z�b�g
	void SetColor(float r, float g, float b, float a); //�F���Z�b�g
	void SetUV(float u, float v);
	void CutUV(float U, float V);
	DirectX::XMFLOAT3 GetPos(void); //���W���Q�b�g
	DirectX::XMFLOAT3 GetSize(void); //�傫�����Q�b�g
	float GetAngle(void);            //�p�x���Q�b�g
	DirectX::XMFLOAT4 GetColor(void); //�F���Q�b�g
	DirectX::XMFLOAT2 GetUV(void); //�؂���̒l�Q�b�g


};