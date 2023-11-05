#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_CLOUD 100000

class CCloud : public CGameObject
{
protected:
	int spriteId;
public:
	CCloud(float x, float y, int spriteId) : CGameObject(x, y)
	{
		this->x = x;
		this->y = y;
		this->spriteId = spriteId;
	}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};