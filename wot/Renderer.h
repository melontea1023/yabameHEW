#pragma once

#include	<d3d11.h>
#include	<DirectXMath.h>
#include	<SimpleMath.h>
#include	<io.h>
#include	<string>
#include	<vector>

//�O�����C�u����
#pragma comment(lib,"directxtk.lib")
#pragma comment(lib,"d3d11.lib")

// �R�c���_�f�[�^
struct VERTEX_3D
{
	DirectX::SimpleMath::Vector3 position;
	DirectX::SimpleMath::Vector3 normal;
	DirectX::SimpleMath::Color color;
	DirectX::SimpleMath::Vector2 uv;
};

// �u�����h�X�e�[�g
enum EBlendState {
	BS_NONE = 0,							// ��������������
	BS_ALPHABLEND,							// ����������
	BS_ADDITIVE,							// ���Z����
	BS_SUBTRACTION,							// ���Z����
	MAX_BLENDSTATE
};

//���s����
struct LIGHT {
	BOOL Enable;//�����g����
	BOOL Dummy[3];
	DirectX::SimpleMath::Vector4 Direction;//���s�����̕���
	DirectX::SimpleMath::Color Diffuse;//���s�����̋����ƐF
	DirectX::SimpleMath::Color Ambient;//�����̋����ƐF
};

//���b�V��
struct SUBSET {
	std::string MtrlName;			//�}�e���A����
	unsigned int IndexNum = 0;		//�C���f�b�N�X��
	unsigned int VertexNum = 0;		//���_��
	unsigned int IndexBase = 0;		//�J�n�C���f�b�N�X
	unsigned int VertexBase = 0;	//���_�x�[�X
	unsigned int MaterialIdx = 0;	//�}�e���A���̔ԍ�
};

//�}�e���A��
struct MATERIAL {
	DirectX::SimpleMath::Color Ambient;//������
	DirectX::SimpleMath::Color Diffuse;//�g�U����
	DirectX::SimpleMath::Color Specular;//���ʔ���
	DirectX::SimpleMath::Color Emission;//����
	float Shiness;//����̊��炩��
	BOOL TextureEnable;//�e�N�X�`�����g�����g��Ȃ����̃t���O
	BOOL Dummy[2];
};
//-----------------------------------------------------------------------------
//Renderer�N���X
//-----------------------------------------------------------------------------
class Renderer
{
private:

	static D3D_FEATURE_LEVEL       m_FeatureLevel;

	static ID3D11Device*           m_Device;
	static ID3D11DeviceContext*    m_DeviceContext;
	static IDXGISwapChain*         m_SwapChain;
	static ID3D11RenderTargetView* m_RenderTargetView;
	static ID3D11DepthStencilView* m_DepthStencilView;

	static ID3D11Buffer*			m_WorldBuffer;
	static ID3D11Buffer*			m_ViewBuffer;
	static ID3D11Buffer*			m_ProjectionBuffer;

	static ID3D11Buffer* m_LightBuffer;
	static ID3D11Buffer* m_MaterialBuffer;
	static ID3D11Buffer* m_TextureBuffer;//UV

	static ID3D11DepthStencilState* m_DepthStateEnable;
	static ID3D11DepthStencilState* m_DepthStateDisable;

	static ID3D11BlendState*		m_BlendState[MAX_BLENDSTATE]; // �u�����h �X�e�[�g;
	static ID3D11BlendState*		m_BlendStateATC;

public:

	static void Init();
	static void Uninit();
	static void Begin();
	static void End();

	static void SetDepthEnable(bool Enable);

	static void SetATCEnable(bool Enable);

	static void SetWorldViewProjection2D();
	static void SetWorldMatrix(DirectX::SimpleMath::Matrix* WorldMatrix);
	static void SetViewMatrix(DirectX::SimpleMath::Matrix* ViewMatrix);
	static void SetProjectionMatrix(DirectX::SimpleMath::Matrix* ProjectionMatrix);

	static ID3D11Device* GetDevice( void ){ return m_Device; }
	static ID3D11DeviceContext* GetDeviceContext( void ){ return m_DeviceContext; }

	static void CreateVertexShader(ID3D11VertexShader** VertexShader, ID3D11InputLayout** VertexLayout, const char* FileName);
	static void CreatePixelShader(ID3D11PixelShader** PixelShader, const char* FileName);

	static void SetLight(LIGHT Light);
	static void SetMaterial(MATERIAL Material);
	static void SetUV(float u, float v, float uw, float vh);

	//=============================================================================
	// �u�����h �X�e�[�g�ݒ�
	//=============================================================================
	static void SetBlendState(int nBlendState)
	{
		if (nBlendState >= 0 && nBlendState < MAX_BLENDSTATE) {
			float blendFactor[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
			m_DeviceContext->OMSetBlendState(m_BlendState[nBlendState], blendFactor, 0xffffffff);
		}
	}
};