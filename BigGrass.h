#pragma once

#include "GameObject.h"
#include "Animation.h"
#include "Animations.h"

#define ID_ANI_BIGGRASS 300000

class CBigGrass : public CGameObject
{
protected:
	int spriteId;
public:
	CBigGrass(float x, float y, int spriteId) : CGameObject(x, y) 
	{
		this->spriteId = spriteId;
	}
	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
};