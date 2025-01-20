#include "Player.h"
#include <cmath>

Player::Player()//�l����
    : stamina(100.0f), health(100.0f), reflectSpeed(10.0f), attackRange(100.0f), attackDamage(10.0f) {
    velocity = { 0.0f, 0.0f };//imakannkeinasi
}

void Player::Init(const wchar_t* textureFile, int sx, int sy) {
    Object::Init(textureFile, sx, sy);
    SetPos(0.0f, 0.0f, 0.0f);
    SetSize(70.0f, 100.0f, 0.0f);
    SetAngle(0.0f);
}

void Player::Update() {
    float moveSpeed = 5.0f;

    // �X�^�~�i�ɉ������ړ����x����
    if (Input::GetButtonPress(XINPUT_RIGHT_SHOULDER)) {
        if (stamina > 0.0f) {
            stamina -= 0.5f; // �X�^�~�i����
            moveSpeed += 2.0f;
        }
    }
    else {
        stamina += 0.5f; // �X�^�~�i��
        if (stamina > 100.0f) stamina = 100.0f;
    }

    // ���A�i���O�X�e�B�b�N�ɂ��ړ�
    DirectX::SimpleMath::Vector2 leftStick = Input::GetLeftAnalogStick();
    pos.x += leftStick.x * moveSpeed;
    pos.y += leftStick.y * moveSpeed;

    // �{�^�����͂ɉ����čU���┽�˂����s
    if (Input::GetButtonPress(XINPUT_A) || Input::GetButtonPress(XINPUT_B) || Input::GetButtonPress(XINPUT_X)) {
        Reflect();
    }
}

void Player::Reflect() {//���ˊp�x����
    if (Input::GetButtonPress(XINPUT_A)) {
        velocity = { 1.0f, 1.0f }; // �E��
    }
    else if (Input::GetButtonPress(XINPUT_B)) {
        velocity = { 1.0f, 0.0f }; // �E
    }
    else if (Input::GetButtonPress(XINPUT_X)) {
        velocity = { 1.0f, -1.0f }; // �E��
    }

    // ���K�����đ��x��ݒ�
    float length = std::sqrt(velocity.x * velocity.x + velocity.y * velocity.y);
    if (length != 0.0f) {
        velocity.x = (velocity.x / length) * reflectSpeed;
        velocity.y = (velocity.y / length) * reflectSpeed;
    }

    pos.x += velocity.x;
    pos.y += velocity.y;
}

void Player::Attack(Object& target) {
    if (IsTargetInRange(target)) {
        // �_���[�W�n�̏���
        target.SetColor(1.0f, 0.0f, 0.0f, 1.0f); // �G�Ԃ�������
    }
}

bool Player::IsTargetInRange(const Object& target) const {
    // �������v�Z
    DirectX::XMFLOAT3 targetPos = target.GetPos();
    float dx = targetPos.x - pos.x;
    float dy = targetPos.y - pos.y;
    float distance = std::sqrt(dx * dx + dy * dy);

    // �U���͈͓��Ȃ� true ��Ԃ�
    return distance <= attackRange;
}
