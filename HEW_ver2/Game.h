#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include"Object.h"
#include"testEnemy.h"
#include"input.h"
#include"sound.h"


#define GAME_TITLE (101)
#define GAME_GAME (102)
#define GAME_CLEAR (103)
#define GAME_END (104)
//�񋓌^�ŃV�[���J��
enum GameState
{
	TITLE,
	GAME,
	LAST,
	END
};

class Game {

private:
	Input input;

	Sound sound;
	

	Object  title;
	Object bg1;	//background
	Object clear_screen;
	Object game_over_screen;
	Player player; // Player�N���X�̃C���X�^���X

	TestEnemy testenemy;

	GameState State = TITLE;
	
public:

	Game() : State(TITLE) {}

	void Init(HWND hWnd);   //������
	void Update(void);
	void Draw(void);            //�`��
	void Uninit(void);          //�I��

	bool Box_Hit_judgment(Object, Object);
	bool Circle_Hit_judgment(Object, Object);


};