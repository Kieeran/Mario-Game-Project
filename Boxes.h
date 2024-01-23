#pragma once

#include "GameObject.h"
#include "AssetIDs.h"

class CBoxes : public CGameObject
{
protected:
	float lengthCellSide;
	int lengthWidth;
	int lengthHeight;
	int spriteIdTopLeft, spriteIdTopMiddle, spriteIdTopRight,
		spriteIdMiddleLeft, spriteIdCenter, spriteIdMiddleRight,
		spriteIdBottomLeft, spriteIdBottomMiddle, spriteIdBottomRight,
		spriteIdShadowTop, spriteIdShadowRest;

public:
	CBoxes(float x, float y,
		float lengthCellSide, int lengthWidth, int lengthHeight,
		int spriteIdTopLeft, int spriteIdTopMiddle, int spriteIdTopRight,
		int spriteIdMiddleLeft, int spriteIdCenter, int spriteIdMiddleRight,
		int spriteIdBottomLeft, int spriteIdBottomMiddle, int spriteIdBottomRight,
		int spriteIdShadowTop, int spriteIdShadowRest) :CGameObject(x, y)
	{
		this->lengthCellSide = lengthCellSide;
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
	int IsDirectionColliable(float nx, float ny)
	{
		return nx == 0 && ny == -1;
	}
};