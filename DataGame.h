#pragma once

class CDataGame
{
private:
	bool isAllowGoLeft;
	bool isAllowGoRight;
	bool isAllowGoUp;
	bool isAllowGoDown;

	bool isInHiddenPlace;

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

	bool GetIsInHiddenPlace() { return isInHiddenPlace; }
	void SetIsInHiddenPlace(bool b) { isInHiddenPlace = b; }
};