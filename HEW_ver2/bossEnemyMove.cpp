#include"testenemy.h"


void TestEnemy::bossEnemyMoveLeft()
{
    // ���Ɉړ����铮��
    if (!isWaiting) {
        epos.x -= 10.0f;  // �{�X�����Ɉړ�

        // �{�X����ʂ̍��[�ɓ��B�������`�F�b�N
        if (epos.x <= -SCREEN_WIDTH / 2 / 2) {//bossPos.x �l-10
            epos.x = -SCREEN_WIDTH / 2 / 2;  // �{�X�����[�ɓ��B�����ꍇ�A�����Ŏ~�߂� //�f�o�b�O�����甲���Ă���//bossPos.x�l-737
            isWaiting = true;      // 1�b�ҋ@��Ԃɐ؂�ւ�                //�f�o�b�O�����甲���Ă���//isWaiting�l1
         
            time_c++;
            if (time_c == 60)
            {
                FbossRight = true;
                moving_flg = true;
                move_end = true;
                time_c = 0;
            }

        }
    }
    else {
       
        isWaiting = false;

    }

    // �{�X�̈ʒu��ݒ�
 
    
}



void TestEnemy::bossEnemyMoveRight()
{
    // �E�Ɉړ����铮��
    if (!isWaiting) {
        epos.x += 10.0f;  // �{�X���E�Ɉړ�

        // �{�X����ʂ̉E�[�ɓ��B�������`�F�b�N
        if (epos.x >= SCREEN_WIDTH / 2 / 2) {
            epos.x = SCREEN_WIDTH / 2 / 2;  // �{�X���E�[�ɓ��B�����ꍇ�A�����Ŏ~�߂� //�f�o�b�O�����甲���Ă���//bossPos.x�l730
            isWaiting = true;     // 1�b�ҋ@��Ԃɐ؂�ւ�                //�f�o�b�O�����甲���Ă���//isWaiting�l0
            time_c++;

            if (time_c == 60)
            {
                FbossRight = false;
                moving_flg = true;
                move_end = true;
                time_c = 0;
            }

            
        }
    }
    else {
       
        isWaiting = false;
        // �{�X�̈ʒu��ݒ�

    }

  
}

bool TestEnemy::GetEndflg()
{

    return move_end;
}