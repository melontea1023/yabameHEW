#include    "main.h"
#include    "Application.h"
#include <iostream>

//=======================================
//�G���g���[�|�C���g
//=======================================
int main(void)
{
#if defined(DEBUG) || defined(_DEBUG)
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif//defined(DEBUG) || defined(_DEBUG)

    std::cout << "����";

    // �A�v���P�[�V�������s
    Application app(SCREEN_WIDTH,SCREEN_HEIGHT);//SCREEN_WIDTH,SCREEN_HEIGHT�𑗂��Ă���
    app.Run();

    return 0;
}