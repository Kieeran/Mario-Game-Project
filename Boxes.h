#pragma once

#include "GameObject.h"
#define ID_ANI_PINK_BOX		600001
#define ID_ANI_BLUE_BOX		600002
#define ID_ANI_GREEN_BOX	600003
#define ID_ANI_WHITE_BOX	600004
class CBoxes : public CGameObject
{
protected:
	float lengthSide;
	int lengthWidth;
	int lengthHeight;
	int spriteIdTopLeft, spriteIdTopMiddle, spriteIdTopRight,
		spriteIdMiddleLeft, spriteIdCenter, spriteIdMiddleRight,
		spriteIdBottomLeft, spriteIdBottomMiddle, spriteIdBottomRight,
		spriteIdShadowTop, spriteIdShadowRest;

public:
	CBoxes(float x, float y,
		float lengthSide, int lengthWidth, int lengthHeight,
		int spriteIdTopLeft, int spriteIdTopMiddle, int spriteIdTopRight,
		int spriteIdMiddleLeft, int spriteIdCenter, int spriteIdMiddleRight,
		int spriteIdBottomLeft, int spriteIdBottomMiddle, int spriteIdBottomRight,
		int spriteIdShadowTop, int spriteIdShadowRest) :CGameObject(x, y)
	{
		this->lengthSide = lengthSide;
		this->lengthWidth = lengthWidth;
		this->lengthHeight = lengthHeight;
		this->spriteIdTopLeft = spriteIdTopLeft;
		this->spriteIdTopMiddle = spriteIdTopMiddle;
		this->spriteIdTopRight = spriteIdTopRight;
		this->spriteIdMiddleLeft = spriteIdMiddleLeft;
		this->spriteIdCenter = spriteIdCenter;
		this->spriteIdMiddleRight = spriteIdMiddleRight;
		this->spriteIdBottomLeft = spriteIdBottomLeft;
		this->spriteIdBottomMiddle = spriteIdBottomMiddle;
		this->spriteIdBottomRight = spriteIdBottomRight;
		this->spriteIdShadowTop = spriteIdShadowTop;
		this->spriteIdShadowRest = spriteIdShadowRest;
	}

	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};