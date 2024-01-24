#include "DataGame.h"
#include "Mario.h"
CDataGame::CDataGame()
{
	isAllowGoLeft = false;
	isAllowGoRight = true;
	isAllowGoUp = false;
	isAllowGoDown = false;
	level = MARIO_LEVEL_SMALL;
	score = 0;
	lives = 4;
}