#pragma once

class CDataGame
{
private:
	bool isAllowGoLeft;
	bool isAllowGoRight;
	bool isAllowGoUp;
	bool isAllowGoDown;

	bool isInHiddenPlace;

	int card1;
	int card2;
	int card3;

	int level;
	int score;
	int lives;
public:
	CDataGame();

	bool GetAllowGoLeft() { return isAllowGoLeft; }
	bool GetAllowGoRight() { return isAllowGoRight; }
	bool GetAllowGoUp() { return isAllowGoUp; }
	bool GetAllowGoDown() { return isAllowGoDown; }

	void SetAllowGoLeft(bool l) { isAllowGoLeft = l; }
	void SetAllowGoRight(bool r) { isAllowGoRight = r; }
	void SetAllowGoUp(bool u) { isAllowGoUp = u; }
	void SetAllowGoDown(bool d) { isAllowGoDown = d; }

	int GetLevel() { return level; }
	int GetScore() { return score; }
	int GetLives() { return lives; }

	int GetCard1() { return card1; }
	int GetCard2() { return card2; }
	int GetCard3() { return card3; }

	bool GetIsInHiddenPlace() { return isInHiddenPlace; }
	void SetIsInHiddenPlace(bool b) { isInHiddenPlace = b; }
};