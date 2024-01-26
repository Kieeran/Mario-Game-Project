#include "DataGame.h"
#include "Mario.h"
CDataGame::CDataGame()
{
	level = MARIO_LEVEL_SMALL;
	score = 0;
	lives = 4;

	card1 = 0;
	card2 = 0;
	card3 = 0;

	isAllowGoLeft = false;
	isAllowGoRight = true;
	isAllowGoUp = false;
	isAllowGoDown = false;

	isInHiddenPlace = false;
}