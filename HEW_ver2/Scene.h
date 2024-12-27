#pragma once


#define GAME_TITLE (101)
#define GAME_GAME (102)
#define GAME_CLEAR (103)
#define GAME_END (104)

class Scene
{
protected:
	int SCENE;
public:
	//void TitleInit(void);
//void TitleUpdate(void);
//void TitleDraw(void);
//void TitleUninit(void);
	void MainInit(void);
	void MainUpdate(void);
	void MainDraw(void);
	void MainUninit(void);
};

