#pragma once

class CDataGame
{
private:
	bool isAllowGoLeft;
	bool isAllowGoRight;
	bool isAllowGoUp;
	bool isAllowGoDown;

	int level;
public:
	CDataGame();

	bool GetAllowGoLeft() { return isAllowGoLeft; }
	bool GetAllowGoRight() { return isAllowGoRight; }
	bool GetAllowGoUp() { return isAllowGoUp; }
	bool GetAllowGoDown() { return isAllowGoDown; }

	int GetLevel() { return level; }
};