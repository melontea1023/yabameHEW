#include "Renderer.h"
#include "Camera.h"
#include "Application.h"
#include "input.h"
#include "Game.h"
#include "GolfBall.h"

using namespace std;
using namespace DirectX::SimpleMath;

//=======================================
//����������
//=======================================
void Camera::Init()
{
	m_Position = Vector3(0.0f, 20.0f, -100.0f);
	m_Target = Vector3(0.0f, 0.0f, 0.0f);//�����Ă������
	m_CameraDirection = 3.14f;
}


//=======================================
//�X�V����
//=======================================
void Camera::Update()
{
	//���E�L�[�œ���
	if (Input::GetKeyPress(VK_LEFT)) {
		m_CameraDirection += 0.02f;
	}
	if (Input::GetKeyPress(VK_RIGHT)) {
		m_CameraDirection -= 0.02f;
	}
	//�S���t�{�[���̈ʒu�擾
	vector<GolfBall*>ballpt = Game::GetInstance()->GetObjects<GolfBall>();
	if (ballpt.size() > 0) {
		Vector3 ballPos = ballpt[0]->GetPosition();
		//ballPos = ballpt[1]->GetRotation();

		//�J�����̈ʒu���X�V
		m_Position.x = ballPos.x + sin(m_CameraDirection) * 50;
		m_Position.y = ballPos.y + 20;
		m_Position.z = ballPos.z + cos(m_CameraDirection) * 50;
		//�J�����̒����_���X�V
		m_Target = ballPos;

		// �{�[����ł���
		//if (Input::GetKeyPress(VK_G)) {
		//	Vector3 forward(sin(m_CameraDirection), 0.0f, cos(m_CameraDirection)); // �J�����̌���
		//	m_GolfBall.ShootInDirection(forward, -1.0f); // �{�[���𑬓x10.0�őł��o��
	}
}


//=======================================
//�`�揈��
//=======================================
void Camera::Draw()
{

}


//=======================================
//�I������
//=======================================
void Camera::Uninit()
{

}

void Camera::SetCamera(int mode) {
	if (mode == 0) {//3D
		// �r���[�ϊ����쐬
		Vector3 up = Vector3(0.0f, 1.0f, 0.0f);
		m_ViewMatrix = DirectX::XMMatrixLookAtLH(m_Position, m_Target, up); // ����n�ɂ����@20230511 by suzuki.tomoki
		// DIRECTXTK�̃��\�b�h�͉E��n�@20230511 by suzuki.tomoki
		// �E��n�ɂ���ƂR�p�`���_�������v���ɂȂ�̂ŕ`�悳��Ȃ��Ȃ�̂Œ���
		// ���̃R�[�h�͊m�F�e�X�g�̂��߂Ɏc��
		// m_ViewMatrix = m_ViewMatrix.CreateLookAt(m_Position, m_Target, up);					

		Renderer::SetViewMatrix(&m_ViewMatrix);

		//�v���W�F�N�V�����s��̐���
		constexpr float fieldOfView = DirectX::XMConvertToRadians(45.0f);    // ����p
		float aspectRatio = static_cast<float>(Application::GetWidth()) / static_cast<float>(Application::GetHeight());	// �A�X�y�N�g��	
		
		float nearPlane = 1.0f;       // �j�A�N���b�v�@   ��ԋ߂�    n~
		float farPlane = 1000.0f;      // �t�@�[�N���b�v�@��ԉ����@  ~n

		//�v���W�F�N�V�����s��̐���
		Matrix projectionMatrix;
		projectionMatrix = DirectX::XMMatrixPerspectiveFovLH(fieldOfView, aspectRatio, nearPlane, farPlane);	// ����n�ɂ����@20230511 by suzuki.tomoki
		// DIRECTXTK�̃��\�b�h�͉E��n�@20230511 by suzuki.tomoki
		// �E��n�ɂ���ƂR�p�`���_�������v���ɂȂ�̂ŕ`�悳��Ȃ��Ȃ�̂Œ���
		// ���̃R�[�h�͊m�F�e�X�g�̂��߂Ɏc��
		// projectionMatrix = DirectX::SimpleMath::Matrix::CreatePerspectiveFieldOfView(fieldOfView, aspectRatio, nearPlane, farPlane);

		Renderer::SetProjectionMatrix(&projectionMatrix);
	}
	else if (mode == 1) {//2D
		Vector3 pos = { 0.0f,0.0f, -10.0f };
		Vector3 tgt = { 0.0f,0.0f, 1.0f };
		Vector3 up = Vector3{ 0.0f,1.0f, 0.0f };
		m_ViewMatrix = DirectX::XMMatrixLookAtLH(pos, tgt, up);
		Renderer::SetViewMatrix(&m_ViewMatrix);

		//�v���W�F�N�V�����s��̐���
		float nearPlane = 1.0f;
		float farPlane = 1000.0f;
		Matrix projectionMatrix = DirectX::XMMatrixOrthographicLH(
			static_cast<float>(Application::GetWidth()),
			static_cast<float>(Application::GetHeight()),
			nearPlane,farPlane);
		
		projectionMatrix = DirectX::XMMatrixTranspose(projectionMatrix);
		Renderer::SetProjectionMatrix(&projectionMatrix);

	}
}

