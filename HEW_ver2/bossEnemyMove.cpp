#include"testenemy.h"


void TestEnemy::bossEnemyMoveLeft()
{
    // 左に移動する動き
    if (!isWaiting) {
        epos.x -= 10.0f;  // ボスが左に移動

        // ボスが画面の左端に到達したかチェック
        if (epos.x <= -SCREEN_WIDTH / 2 / 2) {//bossPos.x 値-10
            epos.x = -SCREEN_WIDTH / 2 / 2;  // ボスが左端に到達した場合、そこで止める //デバッグしたら抜けている//bossPos.x値-737
            isWaiting = true;      // 1秒待機状態に切り替え                //デバッグしたら抜けている//isWaiting値1
         
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

    // ボスの位置を設定
 
    
}



void TestEnemy::bossEnemyMoveRight()
{
    // 右に移動する動き
    if (!isWaiting) {
        epos.x += 10.0f;  // ボスが右に移動

        // ボスが画面の右端に到達したかチェック
        if (epos.x >= SCREEN_WIDTH / 2 / 2) {
            epos.x = SCREEN_WIDTH / 2 / 2;  // ボスが右端に到達した場合、そこで止める //デバッグしたら抜けている//bossPos.x値730
            isWaiting = true;     // 1秒待機状態に切り替え                //デバッグしたら抜けている//isWaiting値0
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
        // ボスの位置を設定

    }

  
}

bool TestEnemy::GetEndflg()
{

    return move_end;
}