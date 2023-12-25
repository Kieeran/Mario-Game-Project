#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"
#include "AssetIDs.h"

#define BLACK_BLOCK_SIZE 16

class CBlackObject : public CGameObject
{
protected:
	int lengthWidth;
	int lengthHeight;

public:
	CBlackObject(float x, float y, int lengthWidth, int lengthHeight) : CGameObject(x, y)
	{
		this->x = x;
		this->y = y;
		this->lengthWidth = lengthWidth;
		this->lengthHeight = lengthHeight;
	}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};