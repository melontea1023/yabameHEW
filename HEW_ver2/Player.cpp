#include "Player.h"
#include <cmath>
Input input;

Player::Player()
{

}
void Player::Player_Init()
{

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

    //if (Input::GetButtonPress(XINPUT_A)) {
    //    Enemy target; // ���̃^�[�Q�b�g
    //    Attack(target); 
    //}
}

//void Player::flutter() {
//    const float flutterCost = 20.0f; // flutter�̃X�^�~�i�����
//
//    if (stamina >= flutterCost) {
//        stamina -= flutterCost; // �X�^�~�i������
//        Enemy target; //Enemy�N���X
//        target.TakeDamage(10);
//    }
//    else {
//       
//    }
//}

//void Player::flutter() {
//    const float flutterCost = 20.0f; // flutter�̃X�^�~�i�����
//
//    if (stamina >= flutterCost) {
//        stamina -= flutterCost; // �X�^�~�i������
//    }
//}
//
//void Player::Attack(Enemy& target) {
//    // �U�����W�b�N
//    if (IsTargetInRange(target)) {
//        target.TakeDamage(10); // ��Ƃ���10�_���[�W��^����
//    }
//}
//
//bool Player::IsTargetInRange(const Enemy& target) const {
//    float distance = std::sqrt(std::pow(target.GetPosition().x - pos.x, 2) + std::pow(target.GetPosition().y - pos.y, 2));
//    float attackRange = 50.0f; // �U���͈́i��Ƃ���50.0f�j
//
//    return distance <= attackRange;
//}



//enemy.h
//class Enemy {
//public:
//    void TakeDamage(int damage);
//    int GetHealth() const;
//    DirectX::SimpleMath::Vector2 GetPosition() const;
//
//private:
//    int health = 100; // �����̗�
//    DirectX::SimpleMath::Vector2 pos; // �ʒu���
//};
//
//
//enemy.cpp
//
//void TargetComponent::TakeDamage(int damage) {
//    health -= damage;
//    if (health < 0) {
//        health = 0;
//    }
//}
//
//int TargetComponent::GetHealth() const {
//    return health;
//}
//
//DirectX::SimpleMath::Vector2 TargetComponent::GetPosition() const {
//    return pos; 
// }


//Player�̏����� Game.cpp�ۑ��p
//player.Init(L"asset/playertest.png", 1, 1);
//player.SetPos(0.0f, 0.0f, 0.0f);
//player.SetSize(70.0f, 100.0f, 0.0f);
//player.SetAngle(0.0f);