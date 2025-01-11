#include "Player.h"

Input input;

void Player::Init(const wchar_t* imgname, int sx, int sy) {
    Object::Init(imgname, sx, sy);
}

void Player::Update() {
    //// ���͏����i��: �L�[�{�[�h�j
    //if (Input::GetKeyPress(VK_A) || Input::GetButtonPress(XINPUT_LEFT)) {

    //}
    //if (Input::GetKeyPress(VK_D) || Input::GetButtonPress(XINPUT_RIGHT)) {

    //}
    //if (Input::GetKeyPress(VK_W) || Input::GetButtonPress(XINPUT_UP)) {

    //}
    //if (Input::GetKeyPress(VK_S) || Input::GetButtonPress(XINPUT_DOWN)) {

    //}
    float moveSpeed = 5.0f; // �ړ����x

    if (Input::GetButtonPress(XINPUT_RIGHT_SHOULDER)) {
        if (stamina > 0.0f) { // �X�^�~�i���c���Ă���ꍇ�̂ݏ���
            stamina -= 0.5f; // �X�^�~�i����
            moveSpeed += 2.0f; // �ړ����x���㏸
        }
        else {
            stamina = 0.0f; // �X�^�~�i��0�ȉ��ɂȂ�Ȃ��悤����
        }
    }
    else {
        stamina += 0.5f; // �X�^�~�i�̎��R��
        if (stamina > 100.0f) stamina = 100.0f; // �X�^�~�i�̏����100��
    }
        // ���A�i���O�X�e�B�b�N�̓��͂��擾
    DirectX::SimpleMath::Vector2 leftStick = Input::GetLeftAnalogStick();

    // �A�i���O�X�e�B�b�N�̒l�Ńv���C���[�̍��W���ړ�


    pos.x += leftStick.x * moveSpeed;
    pos.y += leftStick.y * moveSpeed;

}

void Player::flutter() {
    const float flutterCost = 20.0f; // flutter�̃X�^�~�i�����

    if (stamina >= flutterCost) {
        stamina -= flutterCost; // �X�^�~�i������

    }
    else {
       
    }
}