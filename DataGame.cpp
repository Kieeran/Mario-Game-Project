#include "DataGame.h"
#include "Mario.h"
CDataGame::CDataGame()
{
	level = MARIO_LEVEL_SMALL;
	score = 0;
	lives = 4;

	isAllowGoLeft = false;
	isAllowGoRight = true;
	isAllowGoUp = false;
	isAllowGoDown = false;

	isInHiddenPlace = false;
}