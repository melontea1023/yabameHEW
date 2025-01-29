#pragma once
#include<iostream>
#include<vector>
#include<algorithm>
#include"Object.h"
#include"testEnemy.h"
#include"input.h"
#include"Player.h"
#include"sound.h"

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

	bool GAME_CLEAR_flg = false;
	bool GAME_END_flg = false;
	bool Loop_flg = false;
	bool Scene_Change_flg = false;
	
public:

	Game() : State(TITLE) {}

	void Init(HWND hWnd);   //������
	void Update(void);
	void Draw(void);            //�`��
	void Uninit(void);          //�I��

	bool Box_Hit_judgment(Object, Object);
	bool Box_Hit_Judgment(Object, Object);
	bool Circle_Hit_judgment(Object, Object);

	void Damage(Player, TestEnemy);

	void Damage(Player, Test_Bullet);

	void Damage(TestEnemy, Test_Bullet);

	bool Any_Button();
};