#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"

class CPipe : public CGameObject
{
protected:
	int lenthCellSide;
	int lengthHeight;
	int spriteIdTopLeft, spriteIdTopRight,
		spriteIdBotLeft, spriteIdBotRight;
public:
	CPipe(float x, float y,
		int lenthCellSide, int lengthHeight,
		int spriteIdTopLeft, int spriteIdTopRight,
		int spriteIdBotLeft, int spriteIdBotRight
	) : CGameObject(x, y)
	{
		this->lenthCellSide = lenthCellSide;
		this->lengthHeight = lengthHeight;
		this->spriteIdTopLeft = spriteIdTopLeft;
		this->spriteIdTopRight = spriteIdTopRight;
		this->spriteIdBotLeft = spriteIdBotLeft;
		this->spriteIdBotRight = spriteIdBotRight;
	}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	virtual int IsColliable() { return 1; }
	virtual int IsBlocking() { return 1; }
};